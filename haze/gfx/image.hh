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

#ifndef HAZE_GFX_IMAGE
#define HAZE_GFX_IMAGE

#include <string>
#include <SDL/SDL.h>

#include "haze/core/exception.hh"
#include "haze/core/filesystem.hh"
#include "haze/core/pattern.hh"
#include "haze/gfx/geometry.hh"

namespace HAZE {

        class image : public bounding_box<size_t>, public non_copyable {
        public:
                class cannot_load : public exception {
                public:
                        cannot_load(const path &        path,
                                   const std::string & cause) :
                                exception(std::string("Cannot load ") +
                                          path.str()                  +
                                          (!cause.empty() ? ", " + cause : ""))
                        { }
                };

                class cannot_create : public exception {
                };

#if 0
                image(void * data,
                      int    width, int height,
                      int    depth, int pitch,
                      Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask);
#endif
                image(SDL_Surface * surface);
                image(const path & file);
                virtual ~image();

                size_t       bpp() const;
                bool         hasAlpha() const;
                const void * data() const;
                image *      clip(const rectangle<size_t,
                                                  size_t> & rect) const;

        private:
                SDL_Surface * surface_;
                static int    count_;
        };

}

#endif
