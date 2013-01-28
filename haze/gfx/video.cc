//
// Copyright (C) 2012, 2013 Francesco Salvestrini
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//

#include <string>

#include "haze/core/debug.hh"
#include "haze/core/utils.hh"
#include "haze/core/log.hh"
#include "haze/gfx/video.hh"
#include "haze/gfx/camera.hh"
#include "haze/gfx/view.hh"
#include "haze/gfx/backends/backend.hh"

namespace HAZE {

        bool video::is_mode_ok(size_t width,
                               size_t height,
                               size_t bpp,
                               Uint32 flags)
        {
                if (SDL_VideoModeOK(width, height, bpp, flags) <= 0)
                        return false;
                return true;
        }

        video::video(size_t w,
                     size_t h,
                     size_t bpp) :
                MATH::rectangle<size_t>(w, h),
                surface_(0),
                flags_(0),
                bpp_(0)
        {
                if (!SDL_WasInit(SDL_INIT_VIDEO)) {
                        if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
                                throw cannot_initialize(SDL_GetError());
                        }
                }

                DBG("Initializing video to " <<
                    width() << " x " << height() << " @ "<< bpp);

                const SDL_VideoInfo * info = SDL_GetVideoInfo();
                if (!info) {
                        throw cannot_initialize(SDL_GetError());
                }

                DBG("Video infos:");
                DBG("  hw_available = " << info->hw_available);
                DBG("  wm_available = " << info->wm_available);
                DBG("  blit_hw      = " << info->blit_hw     );
                DBG("  blit_hw_CC   = " << info->blit_hw_CC  );
                DBG("  blit_hw_A    = " << info->blit_hw_A   );
                DBG("  blit_sw      = " << info->blit_sw     );
                DBG("  blit_sw_CC   = " << info->blit_sw_CC  );
                DBG("  blit_sw_A    = " << info->blit_sw_A   );
                DBG("  blit_fill    = " << info->blit_fill   );
                DBG("  video_mem    = " << info->video_mem   );
                DBG("  current_w    = " << info->current_w   );
                DBG("  current_h    = " << info->current_h   );
                DBG("  bpp          = " << tostring(info->vfmt->BitsPerPixel));

                Uint32 flags =
                        SDL_OPENGL    |
                        SDL_RESIZABLE |
                        SDL_DOUBLEBUF |
                        SDL_HWSURFACE |
                        0;

                {
                        size_t wt = static_cast<size_t>(info->current_w);
                        size_t ht = static_cast<size_t>(info->current_h);

                        if (width() > wt)
                                width(wt);
                        if (height() > ht)
                                height(ht);
                        if (bpp > info->vfmt->BitsPerPixel)
                                bpp = info->vfmt->BitsPerPixel;
                }

                if (!is_mode_ok(width(), height(), bpp, flags))
                        throw cannot_initialize("Video mode unsupported");

                // Set the GL attributes
                SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

                // Create the GL drawing context
                surface_ = SDL_SetVideoMode(width(), height(), bpp, flags);
                if (!surface_) {
                        throw cannot_initialize(SDL_GetError());
                }

                flags_ = flags;
                bpp_   = bpp;

                DBG("Video set to " <<
                    width() << " x " << height() << " @ " << bpp_);

                HAZE::GL::init();

                resize(width(), height());
        }

        video::~video()
        { SDL_QuitSubSystem(SDL_INIT_VIDEO); }

        void video::resize(size_t w,
                           size_t h)
        {
                if ((w == 0) || (h == 0)) {
                        throw cannot_resize("Wrong dimensions");
                }

                if (!is_mode_ok(w, h, bpp_, flags_))
                        throw cannot_initialize("Video mode unsupported");

                MATH::rectangle<size_t>::resize(w, h);

                surface_ = SDL_SetVideoMode(width(),
                                            height(),
                                            bpp_,
                                            flags_);
                if (!surface_) {
                        throw cannot_resize(SDL_GetError());
                }

                glViewport(0, 0,
                           static_cast<GLsizei>(width()),
                           static_cast<GLsizei>(height()));

                //glMatrixMode(GL_PROJECTION);
                //glLoadIdentity();

                // This sets up the OpenGL window so that (0,0) corresponds
                // to the top left corner, and (width, height) corresponds to
                // the bottom right hand corner
                //glOrtho(0,
                //        static_cast<GLfloat>(width()),
                //        static_cast<GLfloat>(height()),
                //        0, -1, 1);

                //glMatrixMode(GL_MODELVIEW);
                //glLoadIdentity();

                //camera->position(0.0f, 0.0f, 0.0f);
                //camera->direction(0.0f, 0.0f);
        }

        size_t video::bpp()
        { return surface_->format->BitsPerPixel; }

        void video::clear()
        {
                // DBG("Clearing video");
                glClear(GL_COLOR_BUFFER_BIT); // | GL_DEPTH_BUFFER_BIT
        }

        void video::update()
        {
                // DBG("Updating video");
                glFlush();
                SDL_GL_SwapBuffers();
        }

}
