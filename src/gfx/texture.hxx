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

#ifndef HAZE_GFX_TEXTURE
#define HAZE_GFX_TEXTURE

#include <GL/gl.h>

#include "core/exception.hxx"
#include "core/pattern.hxx"
#include "core/filesystem.hxx"
#include "gfx/geometry.hxx"

namespace HAZE {

        class Texture : public Size<GLuint>, public NonCopyable  {
        public:
                class CannotCreate : public Exception { };

                Texture(const Path & file);
                Texture(const Image & image);
                ~Texture();

                GLuint id();

                void   draw(const Point<GLfloat> & origin,
                            GLfloat scale, GLfloat rotation,
                            GLfloat red, GLfloat green, GLfloat blue,
                            GLfloat alpha);

        private:
                GLuint id_;

                void init(const Image & image);
        };

}

#endif
