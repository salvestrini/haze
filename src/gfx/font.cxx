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

#include "gfx/font.hxx"

namespace HAZE {

        Font::Font()
        { }

        Font::~Font()
        { }

        void Font::add(char c, Image * i)
        { glyphs_[c] = i; }

        void Font::remove(char c)
        { glyphs_.erase(c); }

        void Font::clear()
        { glyphs_.clear(); }

        Image * Font::map(char c) const
        {
                std::map<char, Image *>::const_iterator i = glyphs_.find(c);
                if (i == glyphs_.end()) {
                        throw CannotMap(std::string("Missing "
                                                    "mapping "
                                                    "for character ") +
                                        std::string(1, c));
                }

                return (*i).second;
        }

        std::vector<Image *> Font::map(const std::string & s) const
        {
                std::vector<Image *>                    tmp;
                std::map<char, Image *>::const_iterator j;

                for (std::string::const_iterator i = s.begin();
                     i != s.end();
                     i++) {
                        j = glyphs_.find(*i);
                        if (j == glyphs_.end()) {
                                throw CannotMap(std::string("Missing "
                                                            "mapping "
                                                            "for character ") +
                                                std::string(1, *i));
                        }

                        tmp.push_back((*j).second);
                }

                return tmp;
        }

}
