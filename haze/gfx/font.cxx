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

#include "haze/gfx/font.hxx"

namespace HAZE {

        Glyphs::Glyphs()
        { }

        Glyphs::~Glyphs()
        { }

        void Glyphs::add(char c, Image * i)
        { glyphs_[c] = i; }

        void Glyphs::remove(char c)
        { glyphs_.erase(c); }

        void Glyphs::clear()
        { glyphs_.clear(); }

        Image * Glyphs::map(char c) const
        {
                std::map<char, Image *>::const_iterator i = glyphs_.find(c);
                if (i == glyphs_.end()) {
                        throw CannotMap(c);
                }

                return (*i).second;
        }

        Font::Font()
        { }

        Font::~Font()
        { }

        std::vector<Image *> Font::map(const std::string & s) const
        {
                std::vector<Image *>                    tmp;
                std::map<char, Image *>::const_iterator j;

                for (std::string::const_iterator i = s.begin();
                     i != s.end();
                     i++) {
                        tmp.push_back(Glyphs::map(*i));
                }

                return tmp;
        }

}
