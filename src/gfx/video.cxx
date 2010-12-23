//
// Copyright (C) 2010 Francesco Salvestrini
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
#include <cassert>

#include <GL/gl.h>

#include "core/log.hxx"
#include "gfx/video.hxx"

namespace HAZE {

        Video::Video(size_t width,
                     size_t height,
                     size_t bpp)
                throw(CannotInitialize) :
                surface_(0)
        {
                if (!SDL_WasInit(SDL_INIT_VIDEO)) {
                        if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
                                throw CannotInitialize(SDL_GetError());
                        }
                }

                DBG("Initializing video %d x %d @ %d", width, height, bpp);

                const SDL_VideoInfo * info = SDL_GetVideoInfo();
                if (!info) {
                        throw CannotInitialize(SDL_GetError());
                }
                DBG("Video infos:");
                DBG("  hw_available = %d", info->hw_available);
                DBG("  wm_available = %d", info->wm_available);
                DBG("  blit_hw      = %d", info->blit_hw     );
                DBG("  blit_hw_CC   = %d", info->blit_hw_CC  );
                DBG("  blit_hw_A    = %d", info->blit_hw_A   );
                DBG("  blit_sw      = %d", info->blit_sw     );
                DBG("  blit_sw_CC   = %d", info->blit_sw_CC  );
                DBG("  blit_sw_A    = %d", info->blit_sw_A   );
                DBG("  blit_fill    = %d", info->blit_fill   );
                DBG("  video_mem    = %d", info->video_mem   );
                DBG("  current_w    = %d", info->current_w   );
                DBG("  current_h    = %d", info->current_h   );

                Uint32 flags =
                        SDL_OPENGL    |
                        SDL_RESIZABLE |
                        SDL_DOUBLEBUF |
                        SDL_HWSURFACE |
                        0;

                int closest = SDL_VideoModeOK(width, height, bpp, flags);
                if (closest <= 0) {
                        throw CannotInitialize("Video mode unsupported");
                }

                // XXX FIXME: Ugly ...
                if (static_cast<size_t>(closest) != bpp) {
                        bpp = closest;
                        DBG("Closest video mode is %d bpp", bpp);
                }

                // Set the GL attributes
                SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

#if 0
                assert(bpp != 0);
                int tmp = bpp / 4;

                if (SDL_GL_SetAttribute(SDL_GL_RED_SIZE,   tmp) != 0) {
                        throw CannotInitialize("Cannot set "
                                               "SDL_GL_RED_SIZE attribute");
                }
                if (SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, tmp) != 0) {
                        throw CannotInitialize("Cannot set "
                                               "SDL_GL_RED_SIZE attribute");
                }
                if (SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, tmp) != 0) {
                        throw CannotInitialize("Cannot set "
                                               "SDL_GL_RED_SIZE attribute");
                }
                if (SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, tmp) != 0) {
                        throw CannotInitialize("Cannot set "
                                               "SDL_GL_RED_SIZE attribute");
                }
#endif

                // Create the GL drawing context
                surface_ = SDL_SetVideoMode(width, height, bpp, flags);
                if (!surface_) {
                        throw CannotInitialize(SDL_GetError());
                }

                DBG("Video set to %d x %d @ %d", width, height, bpp);

                initGL();
                resizeWindow(width, height);
        }

        Video::~Video()
        { SDL_QuitSubSystem(SDL_INIT_VIDEO); }

        void Video::initGL()
        {
                DBG("GL initializing");

                glEnable(GL_LINE_SMOOTH);
                glEnable(GL_POINT_SMOOTH);
                glEnable(GL_POLYGON_SMOOTH);
                glEnable(GL_TEXTURE_2D);
                glDisable(GL_DEPTH_TEST);
                glEnable(GL_BLEND);

                // glShadeModel(GL_FLAT);
                // glShadeModel(GL_SMOOTH);

                glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
                // glClearDepth(1.0f);

                // glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
                DBG("GL initialized");
        }

        void Video::resizeWindow(size_t width,
                                 size_t height)
        {
                if ((height == 0) || (height == 0)) {
                        throw CannotResize();
                }

                glViewport(0, 0,
                           static_cast<GLsizei>(width),
                           static_cast<GLsizei>(height));

                glMatrixMode(GL_PROJECTION);
                glLoadIdentity();

                // This sets up the OpenGL window so that (0,0) corresponds
                // to the top left corner, and (width, height) corresponds to
                // the bottom right hand corner
                glOrtho(0,
                        static_cast<GLfloat>(width),
                        static_cast<GLfloat>(height),
                        0,
                        0,
                        1);

                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
        }

        unsigned int Video::width()
        { return surface_->w; }

        unsigned int Video::height()
        { return surface_->h; }

        unsigned int Video::bpp()
        { return surface_->format->BitsPerPixel; }

        void Video::clear()
        {
                // DBG("Clearing video");
                glClear(GL_COLOR_BUFFER_BIT); // | GL_DEPTH_BUFFER_BIT
        }

        void Video::update()
        {
                // DBG("Updating video");
                SDL_GL_SwapBuffers();
        }

}
