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

#include <cmath>

#include "core/log.hxx"
#include "core/debug.hxx"
#include "gfx/primitive.hxx"

namespace HAZE {

        namespace GL {

                Color::Color(GLfloat red,
                             GLfloat green,
                             GLfloat blue,
                             GLfloat alpha) :
                        red_(red),
                        green_(green),
                        blue_(blue),
                        alpha_(alpha)
                { }

                Color::~Color()
                { }

                GLfloat Color::red()
                { return red_; }

                GLfloat Color::green()
                { return green_; }

                GLfloat Color::blue()
                { return blue_; }

                GLfloat Color::alpha()
                { return alpha_; }

                void Color::red(GLfloat value)
                { red_ = value; }

                void Color::green(GLfloat value)
                { green_ = value; }

                void Color::blue(GLfloat value)
                { blue_ = value; }

                void Color::alpha(GLfloat value)
                { alpha_ = value; }

                void Color::set()
                {
                        if (alpha_ == 1.0f) {
                                glColor3f(red_, green_, blue_);
                        } else {
                                glColor4f(red_, green_, blue_, alpha_);
                        }
                }

                Pen::Pen(const Color & color,
                         GLfloat       size) :
                        color_(color),
                        size_(size)
                { }

                Pen::~Pen()
                { }

                void Pen::set()
                {
                        color_.set();
                        glPointSize(size_);
                }

                Point::Point(const Pen & pen) :
                        pen_(pen)
                { }

                Point::~Point()
                { }

                void Point::draw(const HAZE::Point<GLfloat> & where)
                {
                        pen_.set();

                        glBegin(GL_POINTS);
                        glVertex2f(where.x(), where.y());
                        glEnd();
                }

                Line::Line(const Pen & pen) :
                        pen_(pen)
                { }

                Line::~Line()
                { }

                void Line::draw(const HAZE::Point<GLfloat> & from,
                                const HAZE::Point<GLfloat> & to)
                {
                        pen_.set();

                        glBegin(GL_LINES);
                        glVertex2f(from.x(), from.y());
                        glVertex2f(to.x(),   to.y());
                        glEnd();
                }

                Triangle::Triangle(const Pen & pen,
                                   bool        filled) :
                        pen_(pen),
                        filled_(filled)
                { }

                Triangle::~Triangle()
                { }

                void Triangle::draw(const HAZE::Point<GLfloat> & a,
                                    const HAZE::Point<GLfloat> & b,
                                    const HAZE::Point<GLfloat> & c)
                {
                        pen_.set();

                        if (filled_) {
                                glBegin(GL_TRIANGLES);
                        } else {
                                glBegin(GL_TRIANGLES);
                        }
                        glVertex3f(a.x(), a.y(), 0.0f);
                        glVertex3f(b.x(), b.y(), 0.0f);
                        glVertex3f(c.x(), c.y(), 0.0f);
                        glEnd();

                }

                Rectangle::Rectangle(const Pen & pen,
                                     bool        filled) :
                        pen_(pen),
                        filled_(filled)
                { }

                Rectangle::~Rectangle()
                { }

                void Rectangle::draw(const HAZE::Point<GLfloat> & from,
                                     const HAZE::Point<GLfloat> & to)
                {
                        pen_.set();

                        if (filled_) {
                                glBegin(GL_QUADS);
                        } else {
                                glBegin(GL_LINE_LOOP);
                        }

                        glVertex2f(from.x(), from.y());
                        glVertex2f(to.x(),   from.y());
                        glVertex2f(to.x(),   to.y());
                        glVertex2f(from.x(), to.y());
                        glEnd();
                }

                Circle::Circle(const Pen & pen,
                               GLfloat     radius,
                               size_t      slices,
                               bool        filled) :
                        pen_(pen),
                        radius_(radius),
                        slices_(slices),
                        filled_(filled)
                { }

                Circle::~Circle()
                {
                        if (slices_ <= 0) {
                                slices_ = 1;
                        }
                }

                void Circle::draw(const HAZE::Point<GLfloat> & center)
                {
                        pen_.set();

                        if (filled_) {
                                glBegin(GL_TRIANGLES);
                        } else {
                                glBegin(GL_LINE_LOOP);
                        }

                        glVertex2f(center.x(), center.y());

                        for (float angle = 0;
                             angle <= 2 * M_PI;
                             angle += 2 * M_PI / slices_) {
                                glVertex2f(center.x() + cosf(angle) * radius_,
                                           center.y() + sinf(angle) * radius_);
                        }

                        glEnd();
                }

                Polygon::Polygon(const Pen &                    pen,
                                 std::list<std::pair<GLfloat,
                                                     GLfloat> > points,
                                 bool                           filled) :
                        pen_(pen),
                        points_(points),
                        filled_(filled)
                { }

                void Polygon::draw(const HAZE::Point<GLfloat> & where,
                                   GLfloat                      scale,
                                   GLfloat                      rotation)
                {
                        // glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

                        pen_.set();

                        glPushMatrix();

                        glTranslatef(where.x(), where.y(), 0.0f);

                        glBegin(GL_TRIANGLE_FAN);
                        for (std::list<std::pair<GLfloat,
                                                 GLfloat> >::iterator i =
                                     points_.begin();
                             i != points_.end();
                             i++) {
                                glVertex2f((*i).first, (*i).second);
                        }
                        glEnd();

                        glPopMatrix();
                }

#define WANT_TEXTURE_MANAGER 0

#ifdef WANT_TEXTURE_MANAGER

#define MAX_TEXTURES 1024

                class TextureManager {
                public:
                        TextureManager(size_t count = MAX_TEXTURES) :
                                current_(0),
                                size_(count) {
                                indexes_ = new GLuint[count];
                                glGenTextures(count, indexes_);

                        }

                        ~TextureManager() {
                                delete [] indexes_;
                        }

                        GLuint next() {
                                if (current_ >= size_) {
                                        BUG();
                                }
                                return indexes_[current_++];
                        }

                private:
                        GLuint * indexes_;
                        size_t   current_;
                        size_t   size_;
                };

                TextureManager * textureManager = 0;
#endif

                void Texture::init(const Image & image)
                {
#if WANT_TEXTURE_MANAGER
                        if (!textureManager) {
                                textureManager = new TextureManager;
                        }

                        id_ = textureManager->next();
#else
                        glGenTextures(1, &id_);
#endif
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

                        DBG("Image is %d x %d pixels (%s)",
                            width(), height(),
                            format == GL_BGRA ? "alpha" : "no-alpha");
                }

                Texture::Texture(const Image & image,
                                 const Color & color) :
                        color_(color)
                { init(image); }

                Texture::Texture(const Path &  file,
                                 const Color & color) :
                        color_(color)
                { init(Image(file)); }

                Texture::~Texture()
                { glDeleteTextures(1, &id_); }

                void Texture::draw(const HAZE::Point<GLfloat> & origin,
                                   GLfloat                      scale,
                                   GLfloat                      rotation)
                {
                        //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

                        glBindTexture(GL_TEXTURE_2D, id_);

                        glPushMatrix();

                        glTranslatef(origin.x(), origin.y(), 0.0f);
                        glScalef(scale, scale, 0.0f);
                        glRotatef(rotation, 0.0f, 0.0f, 1.0f);

                        GLfloat w2  = width()  / 2;
                        GLfloat h2  = height() / 2;

                        color_.set();

                        glBegin(GL_QUADS);

                        glTexCoord2f(0.0f, 0.0f); glVertex2f(-w2, -h2);
                        glTexCoord2f(1.0f, 0.0f); glVertex2f( w2, -h2);
                        glTexCoord2f(1.0f, 1.0f); glVertex2f( w2,  h2);
                        glTexCoord2f(0.0f, 1.0f); glVertex2f(-w2,  h2);

                        glEnd();

                        glPopMatrix();
                }

        }
}
