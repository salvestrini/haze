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

#ifndef HAZE_GFX_VIDEO
#define HAZE_GFX_VIDEO

#include <string>

#include <SDL/SDL.h>

#include "haze/core/pattern.hh"
#include "haze/core/exception.hh"
#include "haze/gfx/config.hh"
#include "haze/gfx/math.hh"

namespace HAZE {

        class video :
                public MATH::rectangle<size_t>,
                public non_copyable {
        public:
                class cannot_initialize : public exception {
                public:
                        cannot_initialize(const std::string what) :
                                exception(what) { }
                };

                class cannot_resize : public exception {
                public:
                        cannot_resize(const std::string what) :
                                exception(what) { }
                };

                video(size_t width  = HAZE_VIEWPORT_WIDTH,
                      size_t height = HAZE_VIEWPORT_HEIGHT,
                      size_t bpp    = HAZE_VIEWPORT_BPP);
                virtual ~video();

                typedef size_t size_type;

                // Width and height ... we should derive from a rectangle ...
                void   resize(size_t width,
                              size_t height);

                size_t bpp();
                void   clear();
                void   update();

        private:
                bool   is_mode_ok(size_t width,
                                  size_t height,
                                  size_t bpp,
                                  Uint32 flags);

                SDL_Surface * surface_;
                Uint32        flags_;
                size_t        bpp_;
        };

}

#endif
