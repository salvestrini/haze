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

#include "haze/core/exception.hxx"

namespace HAZE {

#define VIDEO_DEFAULT_WIDTH     640
#define VIDEO_DEFAULT_HEIGHT    480
#define VIDEO_DEFAULT_BPP        32

        class Video {
        public:
                class CannotInitialize : public Exception {
                public:
                        CannotInitialize(const std::string what) :
                                Exception(what) { }
                };

                class CannotResize : public Exception {
                public:
                        CannotResize(const std::string what) :
                                Exception(what) { }
                };

                Video(size_t width     = VIDEO_DEFAULT_WIDTH,
                      size_t height    = VIDEO_DEFAULT_HEIGHT,
                      size_t bpp       = VIDEO_DEFAULT_BPP)
                        throw(CannotInitialize);
                virtual ~Video();

                typedef size_t size_type;

                // Width and Height ... we should derive from a Rectangle ...
                void resize(size_t width,
                            size_t height);

                size_t width();
                size_t height();
                size_t bpp();

                void         clear();
                void         update();

        private:
                void initGL();

                // SDL specific
                SDL_Surface * surface_;
                Uint32        flags_;

                int           bpp_;
        };

}

#endif
