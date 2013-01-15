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

#ifndef HAZE_GFX_TEXT
#define HAZE_GFX_TEXT

#include <string>
#include <vector>

#include "haze/gfx/math.hh"
#include "haze/gfx/font.hh"
#include "haze/gfx/backends/backend.hh"

namespace HAZE {

        class Text :
                public NonCopyable,
                public GL::Figure {
        public:
                Text(const GL::Color & color = GL::Color());

                Text(const std::string & message,
                     const Font &        font,
                     const GL::Color &   color = GL::Color());
                ~Text();

                void         set(const GL::Color & color);
                void         set(const Font &        font,
                                 const std::string & message);

                // XXX FIXME: Use size_type
                Size<size_t> size() const;

                virtual void draw() const;
                virtual void move(const MATH::Point<GLfloat> & where);

        private:
                std::vector<GL::Texture *> chars_;
                GL::Color                  color_;
        };

}

#endif
