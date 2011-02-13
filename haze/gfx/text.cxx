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

#include <utility>

#include "haze/gfx/text.hxx"

namespace HAZE {

        Text::Text(const std::string & message,
                   const Font &        font,
                   const GL::Color &   color) :
                color_(color)
        { set(font, message); }

        Text::Text(const GL::Color & color)
        { }

        Text::~Text()
        {
                for (std::vector<GL::Texture *>::iterator i = chars_.begin();
                     i != chars_.end();
                     i++) {
                        delete *i;
                }
        }

        void Text::move(const MATH::Point<GLfloat> & where)
        {
                center_ = where;

                MATH::Point<GLfloat> p(center_);

                for (std::vector<GL::Texture *>::const_iterator i =
                             chars_.begin();
                     i != chars_.end();
                     i++) {
                        (*i)->move(p);
                        p.x(p.x() + (*i)->width());
                }
        }

        void Text::draw() const
        {
                for (std::vector<GL::Texture *>::const_iterator i =
                             chars_.begin();
                     i != chars_.end();
                     i++) {
                        (*i)->draw();
                }
        }

        void Text::set(const Font &        font,
                       const std::string & message)
        {
                chars_.clear();

                std::vector<Image *> tmp = font.map(message);
                for (std::vector<Image *>::const_iterator i = tmp.begin();
                     i != tmp.end();
                     i++) {
                        chars_.push_back(new GL::Texture(*(*i), color_));
                }
        }

        void Text::set(const GL::Color & color)
        {
                color_ = color;

                for (std::vector<GL::Texture *>::iterator i = chars_.begin();
                     i != chars_.end();
                     i++) {
                        (*i)->set(color_);
                }
        }

        Size<size_t> Text::size() const
        {
                Size<size_t> t;

                for (std::vector<GL::Texture *>::const_iterator i =
                             chars_.begin();
                     i != chars_.end();
                     i++) {
                        t.width(t.width() + (*i)->width());
                        t.height(std::max(t.height(), (*i)->height()));
                }

                return t;
        }

}
