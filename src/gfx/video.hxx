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

#ifndef HAZE_GFX_VIDEO
#define HAZE_GFX_VIDEO

#include <string>

#include <SDL/SDL.h>

#include "core/exception.hxx"

namespace HAZE {

#define VIDEO_DEFAULT_WIDTH     640
#define VIDEO_DEFAULT_HEIGHT    480
#define VIDEO_DEFAULT_BPP         8
#define VIDEO_DEFAULT_FREQUENCY  60

        class Video {
        public:
                class CannotInitialize : public Exception {
                public:
                        CannotInitialize(const std::string what) :
                                Exception(what) { }
                };

                Video(unsigned int width     = VIDEO_DEFAULT_WIDTH,
                      unsigned int height    = VIDEO_DEFAULT_HEIGHT,
                      unsigned int bpp       = VIDEO_DEFAULT_BPP,
                      unsigned int frequency = VIDEO_DEFAULT_FREQUENCY)
                        throw(CannotInitialize);
                virtual ~Video();

                unsigned int width();
                unsigned int height();
                unsigned int bpp();
                unsigned int hz();

                void         clear();

        private:
                SDL_Surface * surface_;
        };

}

#endif
