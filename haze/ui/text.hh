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

#ifndef HAZE_UI_TEXT
#define HAZE_UI_TEXT

#include <string>
#include <vector>

#include "haze/gfx/math.hh"
#include "haze/gfx/gl.hh"
#include "haze/ui/font.hh"

namespace haze {

        class text :
                public non_copyable,
                public gl::figure {
        public:
                text(const gl::color & color = gl::color());

                text(const std::string & message,
                     const font &        font,
                     const gl::color &   color = gl::color());
                ~text();

                void         set(const gl::color & color);
                void         set(const font &        font,
                                 const std::string & message);

                // XXX FIXME: Use size_type
                bounding_box<size_t> size() const;

                virtual void draw() const;
                virtual void move(const math::point<GLfloat> & where);

        private:
                std::vector<gl::texture *> chars_;
                gl::color                  color_;
        };

}

#endif
