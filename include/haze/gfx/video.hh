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

#ifndef HAZE_GFX_VIDEO
#define HAZE_GFX_VIDEO

#include <string>

#include "SDL.h"

#include "haze/core/pattern.hh"
#include "haze/core/exception.hh"
#include "haze/gfx/math.hh"

namespace haze {
        namespace gfx {

                class video :
                        public math::rectangle<size_t>,
                        public non_copyable {
                public:
                        class cannot_resize : public exception {
                        public:
                                cannot_resize(const std::string what) :
                                        exception(what) { }
                        };

                        video(size_t width,
                              size_t height,
                              size_t bpp);
                        virtual ~video();

                        typedef size_t size_type;

                        // Width and height ... we should derive from a
                        // rectangle ...
                        void   resize(size_t width,
                                      size_t height);

                        void   clear();
                        void   update();
#if 0
                        void   current();
#endif

                private:
                        SDL_Window *  window_;
                        SDL_GLContext context_;
                        SDL_Surface * surface_;
                };

        }
}

#endif
