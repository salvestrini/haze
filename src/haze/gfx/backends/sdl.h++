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

#include "haze/gfx/backends/video.h++"

namespace HAZE {
        class SDL : public Video {
        public:
                SDL();
                virtual ~SDL();

                virtual unsigned int width();
                virtual unsigned int height();
                virtual unsigned int bpp();

                virtual void         refresh();

        private:
                int           width_;
                int           height_;
                int           bpp_;
                SDL_Surface * context_;
        };

}

#endif