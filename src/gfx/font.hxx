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

#ifndef HAZE_GFX_FONT
#define HAZE_GFX_FONT

#include <string>
#include <map>
#include <vector>

#include "core/exception.hxx"
#include "gfx/image.hxx"

namespace HAZE {

        class Font {
        public:
                class CannotMap : public Exception {
                public:
                        CannotMap(char c) :
                                Exception(std::string("Cannot map "
                                                      "character '") +
                                          std::string(1, c)          +
                                          std::string("'"))
                        { }
                };

                Font();
                ~Font();

                void                 clear();
                void                 add(char c, Image * i);
                void                 remove(char c);

                Image *              map(char c) const;
                std::vector<Image *> map(const std::string & s) const;

        private:
                std::map<char, Image *> glyphs_;
        };

}

#endif