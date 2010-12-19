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

#include <SDL/SDL.h>

#include "globals.hxx"

#include "gfx/image.hxx"
#include "gfx/texture.hxx"

namespace HAZE {

        void Texture::init(const Image & image)
        {
                glGenTextures(1, &id_);
                glBindTexture(GL_TEXTURE_2D, id_);

                glTexParameteri(GL_TEXTURE_2D,
                                GL_TEXTURE_MIN_FILTER,
                                GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D,
                                GL_TEXTURE_MAG_FILTER,
                                GL_LINEAR);

                GLuint internal_format;
                GLenum format;
                if (image.hasAlpha()) {
                        internal_format = 4;
                        format          = GL_BGRA;
                } else {
                        internal_format = 3;
                        format          = GL_BGR;
                }

                glTexImage2D(GL_TEXTURE_2D,
                             0, internal_format,
                             image.width(), image.height(),
                             0, format,
                             GL_UNSIGNED_BYTE,
                             image.data());
                    
                width(image.width());
                height(image.height());
        }

        Texture::Texture(const Image & image)
        { init(image); }

        Texture::Texture(const Path & file)
        { init(Image(file)); }

        Texture::~Texture()
        { }

        // GLuint Texture::id()
        // { return id_; }

        void Texture::draw(const Point<GLfloat> & origin,
                           GLfloat scale, GLfloat rotation,
                           GLfloat red, GLfloat green, GLfloat blue,
                           GLfloat alpha)
        {
                glBindTexture(GL_TEXTURE_2D, id_);
                glLoadIdentity();

                glTranslatef(origin.x(), origin.y(), 0.0);
                glScaled(scale, scale, 1.0f);
                glRotatef(rotation, 1.0f, 1.0f, 1.0f);

                // Scale the points if needed
                GLfloat w  = width() * scale;
                GLfloat h  = height() * scale;

                glColor4f(red, green, blue, alpha);

                glBegin(GL_QUADS);

                glTexCoord2f(0, 1); glVertex2f(0, h);
                glTexCoord2f(0, 0); glVertex2f(0, 0);
                glTexCoord2f(1, 0); glVertex2f(w, 0);
                glTexCoord2f(1, 1); glVertex2f(w, h);

                glEnd();
        }

}
