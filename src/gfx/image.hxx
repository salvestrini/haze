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

#ifndef HAZE_GFX_IMAGE
#define HAZE_GFX_IMAGE

#include <string>
#include <SDL/SDL.h>

#include "core/exception.hxx"
#include "core/filesystem.hxx"
#include "core/pattern.hxx"
#include "gfx/geometry.hxx"

namespace HAZE {

        class Image : public Size<size_t>, public NonCopyable {
        public:
                class CannotLoad : public Exception {
                public:
                        CannotLoad(const Path &        path,
                                   const std::string & cause) :
                                Exception(std::string("Cannot load ") +
                                          std::string(path.c_str())   +
                                          (!cause.empty() ? ", " + cause : ""))
                        { }
                };

                Image(const Path & file);
                virtual ~Image();

                size_t       bpp() const;
                bool         hasAlpha() const;
                const void * data() const;


        private:
                SDL_Surface * surface_;
                static int    count_;
        };

}

#endif
