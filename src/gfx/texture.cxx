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
#include <GL/glu.h>

#include "globals.hxx"

#include "gfx/image.hxx"
#include "gfx/texture.hxx"

namespace HAZE {

        void Texture::init(const Image & image)
        {
                GLuint id_;

                glPixelStorei(GL_UNPACK_ALIGNMENT,4);

                glGenTextures(1, &id_);
                glBindTexture(GL_TEXTURE_2D, id_);

                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

                glTexParameteri(GL_TEXTURE_2D,
                                GL_TEXTURE_MIN_FILTER,
                                GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D,
                                GL_TEXTURE_MAG_FILTER,
                                GL_NEAREST);

                GLuint internal_format;
                GLenum format;
                if (image.hasAlpha()) {
                        internal_format = 4;
                        format          = GL_BGRA;
                } else {
                        internal_format = 3;
                        format          = GL_BGR;
                }

                if (gluBuild2DMipmaps(GL_TEXTURE_2D, internal_format,
                                      image.width(), image.height(),
                                      format, GL_UNSIGNED_BYTE,
                                      image.data())) {
                        throw CannotCreate();
                }
                    
                width(image.width());
                height(image.height());
        }


        Texture::Texture(const Image & image)
        { init(image); }

        Texture::Texture(const Path & file)
        { init(Image(file)); }

        Texture::~Texture()
        { }

        GLuint Texture::id()
        { return id_; }

        void Texture::draw(const Point<GLfloat> & origin,
                           GLfloat scale, GLfloat rotation,
                           GLfloat red, GLfloat green, GLfloat blue,
                           GLfloat alpha)
        {
#if 0
                //check if the right texture is bound
                if( g_Graphics->CurrentTexture != TextureId ) {
                        //bind texture
                        glBindTexture(GL_TEXTURE_2D, m_Textures[TextureId].Texture );
                        
                        //set graphics varible
                        g_Graphics->CurrentTexture = TextureId;
                }
#endif

                        // Scale the points if needed
                GLfloat w  = width() * scale;
                GLfloat h  = height() * scale;

                glLoadIdentity();
                glTranslatef(camera.x() + origin.x(),
                             camera.x() + origin.y(),
                             0.0);
                glScaled(scale, scale, 0);
                glRotatef(rotation, 0.0f, 0.0f, 1.0f);
                        
                glBegin(GL_QUADS);
                        
                // Top-left vertex (corner)
                glColor4f(red, green, blue, alpha);
                glTexCoord2f(0, 1);
                glVertex2f(0, 0);
                
                // Bottom-left vertex (corner)
                glTexCoord2f(0, 0);
                glVertex2f(0, h);
                        
                // Bottom-right vertex (corner)
                glTexCoord2f(1, 0);
                glVertex2f(w, h);
                
                // Top-right vertex (corner)
                glTexCoord2f(1, 1);
                glVertex2f(w, origin.y());
                
                glEnd();
        }

}
