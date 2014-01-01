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

#ifndef HAZE_GFX_FONT
#define HAZE_GFX_FONT

#include <string>
#include <map>
#include <vector>

#include "haze/core/exception.hh"
#include "haze/gfx/image.hh"

namespace haze {

        class glyphs {
        public:
                class cannot_map : public exception {
                public:
                        cannot_map(char c) :
                                exception(std::string("Cannot map "
                                                      "character ") +
                                          std::string("'")          +
                                          std::string(1, c)         +
                                          std::string("'"))
                        { }
                };

                glyphs();
                ~glyphs();

                void                           clear();
                void                           add(char c, image * i);
                void                           remove(char c);

                image *                        map(char c) const;

                bounding_box<image::size_type> max_glyph_size() const;

        private:
                std::map<char, image *>        glyphs_;
                bounding_box<image::size_type> max_;
        };

        class font :
                public glyphs {
        public:
                font();
                ~font();

                std::vector<image *> map(const std::string & s) const;
        };

}

#endif
