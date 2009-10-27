// -*- c++ -*-

//
// Copyright (C) 2009 Francesco Salvestrini
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

#include "config.h"

#ifdef HAVE_SDL

#include "SDL.h"

#include "haze/gfx/backends/sdl.h++"

#define VIDEO_WIDTH  640
#define VIDEO_HEIGHT 320
#define VIDEO_BPP    16

namespace HAZE {

        SDL::SDL() throw(CannotInitialize) :
                width_(VIDEO_WIDTH),
                height_(VIDEO_HEIGHT),
                bpp_(VIDEO_BPP)
        {
                if (!SDL_WasInit(SDL_INIT_VIDEO)) {
                        if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
                                throw CannotInitialize(SDL_GetError());
                        }
                }

                Uint32 flags = SDL_ANYFORMAT | SDL_OPENGL;

                int closest = SDL_VideoModeOK(width_,
                                              height_,
                                              bpp_,
                                              flags);
                if (closest == 0) {
                        throw CannotInitialize("video mode "
                                               "unsupported");
                }
                if (closest != bpp_) {
                        bpp_ = closest;
                }

                if (!SDL_SetVideoMode(width_, height_, bpp_, flags)) {
                        throw CannotInitialize("wrong video mode");
                }
        }

        SDL::~SDL()
        { SDL_QuitSubSystem(SDL_INIT_VIDEO); }

        unsigned int SDL::width()
        { return width_; }

        unsigned int SDL::height()
        { return height_; }

        unsigned int SDL::bpp()
        { return bpp_; }

}

#endif
