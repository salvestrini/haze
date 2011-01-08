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

#include "haze/core/log.hxx"
#include "haze/core/debug.hxx"
#include "haze/gfx/primitive.hxx"

namespace HAZE {

        namespace GL {

#define DEBUG_GL 1

#if DEBUG_GL
#define ASSERT_GL_NO_ERROR() { assert(glGetError() == GL_NO_ERROR); }
#else
#define ASSERT_GL_NO_ERROR()
#endif

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

                GLfloat Color::red() const
                { return red_; }

                GLfloat Color::green() const
                { return green_; }

                GLfloat Color::blue() const
                { return blue_; }

                GLfloat Color::alpha() const
                { return alpha_; }

                void Color::red(GLfloat value)
                { red_ = value; }

                void Color::green(GLfloat value)
                { green_ = value; }

                void Color::blue(GLfloat value)
                { blue_ = value; }

                void Color::alpha(GLfloat value)
                { alpha_ = value; }

                void Color::program() const
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

                void Pen::program() const
                {
                        color_.program();
                        glPointSize(size_);
                }

                void Pen::color(const Color & color)
                { color_ = color; }

                Color Pen::color() const
                { return color_; }

                void Pen::size(GLfloat value)
                { size_ = value; }

                GLfloat Pen::size() const
                { return size_; }

                Point::Point(const Pen &                  pen,
                             const HAZE::Point<GLfloat> & where) :
                        pen_(pen),
                        where_(where)
                { }

                Point::~Point()
                { }

                void Point::move(const HAZE::Point<GLfloat> & where)
                { where_ = where; }

                void Point::draw() const
                {
                        pen_.program();

                        glBegin(GL_POINTS);
                        glVertex2f(where_.x(), where_.y());
                        glEnd();
                }

                Line::Line(const Pen &                  pen,
                           const HAZE::Point<GLfloat> & from,
                           const HAZE::Point<GLfloat> & to) :
                        pen_(pen),
                        from_(from),
                        to_(to)
                { }

                Line::~Line()
                { }

                void Line::draw() const
                {
                        pen_.program();

                        glBegin(GL_LINES);
                        glVertex2f(from_.x(), from_.y());
                        glVertex2f(to_.x(),   to_.y());
                        glEnd();
                }

                Triangle::Triangle(const Pen &                  pen,
                                   const HAZE::Point<GLfloat> & a,
                                   const HAZE::Point<GLfloat> & b,
                                   const HAZE::Point<GLfloat> & c,
                                   bool                         filled) :
                        pen_(pen),
                        a_(a),
                        b_(b),
                        c_(c),
                        filled_(filled)
                { }

                Triangle::~Triangle()
                { }

                void Triangle::draw() const
                {
                        pen_.program();

                        if (filled_) {
                                glBegin(GL_TRIANGLES);
                        } else {
                                glBegin(GL_TRIANGLES);
                        }
                        glVertex3f(a_.x(), a_.y(), 0.0f);
                        glVertex3f(b_.x(), b_.y(), 0.0f);
                        glVertex3f(c_.x(), c_.y(), 0.0f);
                        glEnd();

                }

                Rectangle::Rectangle(const Pen &                  pen,
                                     const HAZE::Point<GLfloat> & from,
                                     const HAZE::Point<GLfloat> & to,
                                     bool                         filled) :
                        pen_(pen),
                        from_(from),
                        to_(to),
                        filled_(filled)
                { }

                Rectangle::~Rectangle()
                { }

                void Rectangle::draw() const
                {
                        pen_.program();

                        if (filled_) {
                                glBegin(GL_QUADS);
                        } else {
                                glBegin(GL_LINE_LOOP);
                        }

                        glVertex2f(from_.x(), from_.y());
                        glVertex2f(to_.x(),   from_.y());
                        glVertex2f(to_.x(),   to_.y());
                        glVertex2f(from_.x(), to_.y());
                        glEnd();
                }

                Circle::Circle(const Pen &                  pen,
                               const HAZE::Point<GLfloat> & center,
                               GLfloat                      radius,
                               size_t                       segments,
                               bool                         filled) :
                        pen_(pen),
                        center_(center),
                        radius_(radius),
                        segments_(segments),
                        filled_(filled)
                { }

                Circle::~Circle()
                {
                        if (segments_ <= 0) {
                                segments_ = 1;
                        }
                }

                void Circle::draw() const
                {
                        pen_.program();

                        if (filled_) {
                                glBegin(GL_TRIANGLE_FAN);
                        } else {
                                glBegin(GL_LINE_LOOP);
                        }

                        const float increment = 2.0f * M_PI / segments_;
                        float       theta     = 0.0f;

                        for (size_t i = 0; i < segments_; ++i) {
                                glVertex2f(center_.x() +
                                           radius_ * cosf(theta),
                                           center_.y() +
                                           radius_ * sinf(theta));

                                theta += increment;
                        }

                        glEnd();
                }

                Polygon::Polygon(const Pen &                      pen,
                                 std::list<HAZE::Point<GLfloat> > points,
                                 const HAZE::Point<GLfloat> &     where,
                                 bool                             filled) :
                        pen_(pen),
                        points_(points),
                        where_(where),
                        filled_(filled)
                { }

                void Polygon::set(bool filled)
                { filled_ = filled; }

                void Polygon::set(std::list<HAZE::Point<GLfloat> > points)
                { points_ = points; }

                void Polygon::move(const HAZE::Point<GLfloat> & where)
                { where_ = where; }

                void Polygon::draw()
                        const
                {
                        // glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

                        pen_.program();

                        glPushMatrix();

                        glTranslatef(where_.x(), where_.y(), 0.0f);

                        if (filled_) {
                                glBegin(GL_TRIANGLE_FAN);
                        } else {
                                glBegin(GL_LINE_LOOP);
                        }
                        for (std::list<HAZE::Point<GLfloat> >::
                                     const_iterator i = points_.begin();
                             i != points_.end();
                             i++) {
                                glVertex2f((*i).x(), (*i).y());
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
                        glEnable(GL_TEXTURE_2D);

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

#if 0
                        DBG("Texture %d is %d x %d pixels (%s)",
                            id_,
                            width(), height(),
                            format == GL_BGRA ? "has-alpha" : "no-alpha");
#endif
                        glDisable(GL_TEXTURE_2D);

                        ASSERT_GL_NO_ERROR();
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

                void Texture::set(const Color & color)
                { color_ = color; }

                void Texture::draw(const HAZE::Point<GLfloat> & origin,
                                   GLfloat                      scale,
                                   GLfloat                      rotation)
                        const
                {
                        glEnable(GL_TEXTURE_2D);

                        //glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_DST_ALPHA);
                        //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA);
                        //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                        glBlendFunc(GL_ONE, GL_ONE);

                        glBindTexture(GL_TEXTURE_2D, id_);

                        glPushMatrix();

                        glTranslatef(origin.x(), origin.y(), 0.0f);
                        glScalef(scale, scale, 0.0f);
                        glRotatef(rotation, 0.0f, 0.0f, 1.0f);

                        GLfloat w2  = width()  / 2;
                        GLfloat h2  = height() / 2;

                        color_.program();

                        glBegin(GL_QUADS);

                        glTexCoord2f(0.0f, 0.0f); glVertex2f(-w2, -h2);
                        glTexCoord2f(1.0f, 0.0f); glVertex2f( w2, -h2);
                        glTexCoord2f(1.0f, 1.0f); glVertex2f( w2,  h2);
                        glTexCoord2f(0.0f, 1.0f); glVertex2f(-w2,  h2);

                        glEnd();

                        glPopMatrix();

                        glDisable(GL_TEXTURE_2D);

                        ASSERT_GL_NO_ERROR();
                }

        }
}
