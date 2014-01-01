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

#include <utility>

#include "haze/gfx/text.hh"

namespace haze {

        text::text(const std::string & message,
                   const font &        fnt,
                   const gl::color &   color) :
                color_(color)
        { set(fnt, message); }

        text::text(const gl::color & color) :
                color_(color)
        { }

        text::~text()
        {
                for (std::vector<gl::texture *>::iterator i = chars_.begin();
                     i != chars_.end();
                     i++) {
                        delete *i;
                }
        }

        void text::move(const math::point<GLfloat> & where)
        {
                center_ = where;

                math::point<GLfloat> p(center_);

                for (std::vector<gl::texture *>::const_iterator i =
                             chars_.begin();
                     i != chars_.end();
                     i++) {
                        (*i)->move(p);
                        p.x(p.x() + (*i)->width());
                }
        }

        void text::draw() const
        {
                for (std::vector<gl::texture *>::const_iterator i =
                             chars_.begin();
                     i != chars_.end();
                     i++) {
                        (*i)->draw();
                }
        }

        void text::set(const font &        fnt,
                       const std::string & message)
        {
                chars_.clear();

                std::vector<image *> tmp = fnt.map(message);
                for (std::vector<image *>::const_iterator i = tmp.begin();
                     i != tmp.end();
                     i++) {
                        chars_.push_back(new gl::texture(*(*i), color_));
                }
        }

        void text::set(const gl::color & color)
        {
                color_ = color;

                for (std::vector<gl::texture *>::iterator i = chars_.begin();
                     i != chars_.end();
                     i++) {
                        (*i)->set(color_);
                }
        }

        bounding_box<size_t> text::size() const
        {
                bounding_box<size_t> t;

                for (std::vector<gl::texture *>::const_iterator i =
                             chars_.begin();
                     i != chars_.end();
                     i++) {
                        t.width(t.width() + (*i)->width());
                        t.height(std::max(t.height(),
                                          static_cast<size_t>((*i)->height())));
                }

                return t;
        }

}
