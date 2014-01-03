//
// Copyright (C) 2012, 2013, 2014 Francesco Salvestrini
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
#include "haze/gfx/gl.hh"

namespace haze {

        video::video(size_t w,
                     size_t h,
                     size_t bpp) :
                math::rectangle<size_t>(w, h),
                surface_(0)
        {
                if (!SDL_WasInit(SDL_INIT_VIDEO)) {
                        if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
                                throw cannot_initialize(SDL_GetError());
                        }
                }

                DBG("Initializing video to " <<
                    width() << " x " << height() << " @ "<< bpp);

                window_ = SDL_CreateWindow("Haze demo",
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           w, h,
                                           SDL_WINDOW_OPENGL |
                                           SDL_WINDOW_RESIZABLE);
                if (!window_)
                        throw cannot_initialize(SDL_GetError());

                context_ = SDL_GL_CreateContext(window_);
                if (!context_)
                        throw cannot_initialize(SDL_GetError());

                // Set the GL attributes
                // if (!
                SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1)// )
                        // throw cannot_initialize(SDL_GetError())
                        ;

                // Create the GL drawing context
                surface_ = SDL_GetWindowSurface(window_);
                if (!surface_)
                        throw cannot_initialize(SDL_GetError());

                haze::gl::init();

                DBG("Video initialized");

                resize(width(), height());
        }

#if 0
        void video::current()
        {
                if (SDL_GL_MakeCurrent(window_, context_))
                    throw(cannot_initialize(SDL_GetError()));
        }
#endif

        video::~video()
        {
                SDL_GL_DeleteContext(context_);

                SDL_QuitSubSystem(SDL_INIT_VIDEO);
        }

        void video::resize(size_t w,
                           size_t h)
        {
                if ((w == 0) || (h == 0)) {
                        throw cannot_resize("Wrong dimensions");
                }

                math::rectangle<size_t>::resize(w, h);

                SDL_SetWindowSize(window_, w, h);
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

                DBG("Video resized to " << width() << "x" << height());
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
                SDL_GL_SwapWindow(window_);
        }

}
