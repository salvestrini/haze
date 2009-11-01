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

#ifndef HAZE_GFX_BACKENDS_SDL
#define HAZE_GFX_BACKENDS_SDL

#include <string>
#include "SDL/SDL.h"

#include "haze/gfx/backends/video.h++"

namespace HAZE {

        class SDLVideo : public Video {
        public:
                SDLVideo(const std::string & name) throw(CannotInitialize);
                virtual ~SDLVideo();

                virtual unsigned int width();
                virtual unsigned int height();
                virtual unsigned int bpp();
                virtual unsigned int hz();

                virtual void         refresh();

        private:
                unsigned int  width_;
                unsigned int  height_;
                unsigned int  bpp_;
                unsigned int  hz_;
                SDL_Surface * context_;
        };

}

#endif
