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

#ifndef HAZE_GFX_TEXT
#define HAZE_GFX_TEXT

#include <GL/gl.h>

#include <string>
#include <vector>

#include "haze/gfx/font.hxx"
#include "haze/gfx/geometry.hxx"
#include "haze/gfx/primitive.hxx"

namespace HAZE {

        class Text {
        public:
                Text(const GL::Color & color = GL::Color());

                Text(const std::string & message,
                     const Font &        font,
                     const GL::Color &   color = GL::Color());
                ~Text();

                void         draw(GLfloat x, GLfloat y) const;
                void         draw(const Point<GLfloat> & origin) const;

                void         set(const GL::Color & color);
                void         set(const Font &        font,
                                 const std::string & message);
                Size<size_t> size() const;

        private:
                std::vector<GL::Texture *> chars_;
                GL::Color                  color_;
        };

}

#endif
