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

#include "haze/ui/font.hh"

namespace haze {

        glyphs::glyphs()
        { }

        glyphs::~glyphs()
        { }

        bounding_box<image::size_type> glyphs::max_glyph_size() const
        { return max_; }

        void glyphs::add(char c, image * i)
        {
                glyphs_[c] = i;

                max_ = haze::max<image::size_type>(max_, *i);
        }

        void glyphs::remove(char c)
        {
                glyphs_.erase(c);

                for (std::map<char, image *>::iterator i = glyphs_.begin();
                     i != glyphs_.end();
                     i++) {
                        max_ = haze::max<image::size_type>(max_,
                                                           (*i).second->
                                                           size());
                }
        }

        void glyphs::clear()
        {
                glyphs_.clear();
                max_.clear();
        }

        image * glyphs::map(char c) const
        {
                std::map<char, image *>::const_iterator i = glyphs_.find(c);
                if (i == glyphs_.end()) {
                        throw cannot_map(c);
                }

                return (*i).second;
        }

        font::font()
        { }

        font::~font()
        { }

        std::vector<image *> font::map(const std::string & s) const
        {
                std::vector<image *>                    tmp;
                std::map<char, image *>::const_iterator j;

                for (std::string::const_iterator i = s.begin();
                     i != s.end();
                     i++) {
                        tmp.push_back(glyphs::map(*i));
                }

                return tmp;
        }

}
