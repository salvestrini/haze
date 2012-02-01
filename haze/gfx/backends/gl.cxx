//
// Copyright (C) 2012 Francesco Salvestrini
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
#include <cstring>
#include <vector>
#include <sstream>

#include "haze/core/log.hxx"
#include "haze/core/debug.hxx"
#include "haze/gfx/math.hxx"
#include "haze/gfx/backends/gl.hxx"

namespace HAZE {

        namespace GL {

#define DEBUG_GL 1

#if DEBUG_GL
#define ASSERT_GL_NO_ERROR() {                                  \
        GLenum err = glGetError();                              \
        if (err != GL_NO_ERROR) {                               \
                const char * e = 0;                             \
                switch (err) {                                  \
                        case GL_INVALID_ENUM:                   \
                                e = "Invalid enum";             \
                                break;                          \
                        case GL_INVALID_VALUE:                  \
                                e = "Invalid value";            \
                                break;                          \
                        case GL_INVALID_OPERATION:              \
                                e = "Invalid operation";        \
                                break;                          \
                        case GL_STACK_OVERFLOW:                 \
                                e = "Stack overflow";           \
                                break;                          \
                        case GL_OUT_OF_MEMORY:                  \
                                e = "Out of memory";            \
                                break;                          \
                        case GL_TABLE_TOO_LARGE:                \
                                e = "Table too large";          \
                                break;                          \
                        default:                                \
                                e = "Unkwnon"; break;           \
                }                                               \
                ERR("Got GL error 0x%x (%s)", err, e);          \
                BUG();                                          \
        }                                                       \
}
#else
#define ASSERT_GL_NO_ERROR()
#endif

                static void dumpExtensions()
                {
                        const GLubyte * strings =
                                glGetString(GL_EXTENSIONS);
                        ASSERT_GL_NO_ERROR();
                        ASSERT(strings);

                        std::string extensions(reinterpret_cast<const char *>(strings));
                        std::stringstream        ss(extensions);
                        std::vector<std::string> tokens;
                        std::string              buffer;

                        while (ss >> buffer) {
                                tokens.push_back(buffer);
                        }

                        DBG("GL Extensions:");
                        for (std::vector<std::string>::const_iterator i =
                                     tokens.begin();
                             i != tokens.end();
                             i++) {
                                DBG("  %s", (*i).c_str());
                        }
                }

                void init()
                {
                        DBG("GL initializing");

                        glEnable(GL_LINE_SMOOTH);
                        glEnable(GL_POINT_SMOOTH);
                        glEnable(GL_POLYGON_SMOOTH);
                        glEnable(GL_TEXTURE_2D);
                        glDisable(GL_DEPTH_TEST);
                        glEnable(GL_BLEND);

                        // glShadeModel(GL_FLAT);
                        // glShadeModel(GL_SMOOTH);

                        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
                        // glClearDepth(1.0f);

                        // glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
                        DBG("GL initialized");

                        dumpExtensions();
                }

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
                             const MATH::Point<GLfloat> & where) :
                        pen_(pen),
                        where_(where)
                { }

                Point::~Point()
                { }

                void Point::move(const MATH::Point<GLfloat> & where)
                { where_ = where; }

                void Point::draw() const
                {
                        pen_.program();

                        {
                                DrawGuard d(GL_POINTS);
                                glVertex2f(where_.x(), where_.y());
                        }

                        ASSERT_GL_NO_ERROR();
                }

                Segment::Segment(const Pen &                  pen,
                                 const MATH::Point<GLfloat> & from,
                                 const MATH::Point<GLfloat> & to) :
                        pen_(pen),
                        from_(from),
                        to_(to)
                { }

                Segment::~Segment()
                { }

                void Segment::move(const MATH::Point<GLfloat> & where)
                {
                        // XXX FIXME: Add code here
                        (void) where;
                        //where_ = where;
                }

                void Segment::rotate(GLfloat radians)
                {
                        // XXX FIXME: Add code here
                        (void) radians;

                        //angle_ = MATH::radians2angle<GLfloat>(radians);
                }

                void Segment::draw() const
                {
                        pen_.program();

                        {
                                DrawGuard d(GL_LINES);
                                glVertex2f(from_.x(), from_.y());
                                glVertex2f(to_.x(),   to_.y());
                        }

                        ASSERT_GL_NO_ERROR();
                }

                Figure::Figure() :
                        center_(MATH::Point<GLfloat>(0.0f, 0.0f)),
                        rotation_(0.0f),
                        scale_(1.0f)
                { }

                Figure::~Figure()
                { }

                void Figure::move(const MATH::Point<GLfloat> & where)
                { center_ = where; }

                void Figure::rotate(GLfloat radians)
                { rotation_ = MATH::radians2angle<GLfloat>(radians); }

                void Figure::scale(GLfloat factor)
                { scale_ = factor; }

                Triangle::Triangle(const Pen &                  pen,
                                   const MATH::Point<GLfloat> & a,
                                   const MATH::Point<GLfloat> & b,
                                   const MATH::Point<GLfloat> & c,
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

                        {
                                DrawGuard d(filled_      ?
                                            GL_TRIANGLES :
                                            GL_TRIANGLES);
                                glVertex3f(a_.x(), a_.y(), 0.0f);
                                glVertex3f(b_.x(), b_.y(), 0.0f);
                                glVertex3f(c_.x(), c_.y(), 0.0f);
                        }

                        ASSERT_GL_NO_ERROR();
                }

                Rectangle::Rectangle(const Pen &                  pen,
                                     const MATH::Point<GLfloat> & from,
                                     const MATH::Point<GLfloat> & to,
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

                        {
                                DrawGuard d(filled_ ? GL_QUADS : GL_LINE_LOOP);
                                glVertex2f(from_.x(), from_.y());
                                glVertex2f(to_.x(),   from_.y());
                                glVertex2f(to_.x(),   to_.y());
                                glVertex2f(from_.x(), to_.y());
                        }

                        ASSERT_GL_NO_ERROR();
                }

                Circle::Circle(const Pen &                  pen,
                               const MATH::Point<GLfloat> & center,
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

                        {
                                const float increment =
                                        2.0f * M_PI / segments_;
                                float       theta     = 0.0f;

                                DrawGuard d(filled_         ?
                                            GL_TRIANGLE_FAN :
                                            GL_LINE_LOOP);

                                for (size_t i = 0; i < segments_; ++i) {
                                        glVertex2f(center_.x() +
                                                   radius_ * cosf(theta),
                                                   center_.y() +
                                                   radius_ * sinf(theta));

                                        theta += increment;
                                }
                        }

                        ASSERT_GL_NO_ERROR();
                }

                Polygon::Polygon(const Pen &                      pen,
                                 std::list<MATH::Point<GLfloat> > points,
                                 bool                             filled) :
                        pen_(pen),
                        points_(points),
                        filled_(filled)
                { }

                void Polygon::set(bool filled)
                { filled_ = filled; }

                void Polygon::set(std::list<MATH::Point<GLfloat> > points)
                { points_ = points; }

                void Polygon::draw() const
                {
                        // glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

                        pen_.program();

                        glPushMatrix();

                        glTranslatef(center_.x(), center_.y(), 0.0f);
                        //glScalef(scale, scale, 0.0f);
                        glRotatef(rotation_, 0.0f, 0.0f, 1.0f);

                        {
                                DrawGuard d(filled_         ?
                                            GL_TRIANGLE_FAN :
                                            GL_LINE_LOOP);

                                for (std::list<MATH::Point<GLfloat> >::
                                             const_iterator i =
                                             points_.begin();
                                     i != points_.end();
                                     i++) {
                                        glVertex2f((*i).x(), (*i).y());
                                }
                        }

                        glPopMatrix();

                        ASSERT_GL_NO_ERROR();
                }

                void Texture::init(const Image & image)
                {
                        glEnable(GL_TEXTURE_2D);

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

                Texture::~Texture()
                { glDeleteTextures(1, &id_); }

                void Texture::set(const Color & color)
                { color_ = color; }

                void Texture::draw() const
                {
                        glEnable(GL_TEXTURE_2D);

                        //glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_DST_ALPHA);
                        //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA);
                        //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                        glBlendFunc(GL_ONE, GL_ONE);

                        glBindTexture(GL_TEXTURE_2D, id_);

                        glPushMatrix();

                        glTranslatef(center_.x(), center_.y(), 0.0f);
                        glScalef(scale_, scale_, 0.0f);
                        glRotatef(rotation_, 0.0f, 0.0f, 1.0f);

                        GLfloat w2  = width()  / 2;
                        GLfloat h2  = height() / 2;

                        color_.program();

                        {
                                DrawGuard d(GL_QUADS);

                                glTexCoord2f(0.0f, 0.0f); glVertex2f(-w2, -h2);
                                glTexCoord2f(1.0f, 0.0f); glVertex2f( w2, -h2);
                                glTexCoord2f(1.0f, 1.0f); glVertex2f( w2,  h2);
                                glTexCoord2f(0.0f, 1.0f); glVertex2f(-w2,  h2);
                        }

                        glPopMatrix();

                        glDisable(GL_TEXTURE_2D);

                        ASSERT_GL_NO_ERROR();
                }

        }
}