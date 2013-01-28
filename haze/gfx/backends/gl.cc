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

#include <cmath>
#include <cstring>
#include <vector>
#include <sstream>

#include "haze/core/log.hh"
#include "haze/core/debug.hh"
#include "haze/gfx/math.hh"
#include "haze/gfx/backends/gl.hh"

namespace HAZE {

        namespace GL {

#define DEBUG_GL 1

#if DEBUG_GL
#define ASSERT_GL_NO_ERROR() {                                            \
                        GLenum err = glGetError();                        \
                        if (err != GL_NO_ERROR) {                         \
                                const char * e = 0;                       \
                                switch (err) {                            \
                                        case GL_INVALID_ENUM:             \
                                                e = "Invalid enum";       \
                                                break;                    \
                                        case GL_INVALID_VALUE:            \
                                                e = "Invalid value";      \
                                                break;                    \
                                        case GL_INVALID_OPERATION:        \
                                                e = "Invalid operation";  \
                                                break;                    \
                                        case GL_STACK_OVERFLOW:           \
                                                e = "Stack overflow";     \
                                                break;                    \
                                        case GL_OUT_OF_MEMORY:            \
                                                e = "Out of memory";      \
                                                break;                    \
                                        case GL_TABLE_TOO_LARGE:          \
                                                e = "Table too large";    \
                                                break;                    \
                                        default:                          \
                                                e = "Unkwnon"; break;     \
                                }                                         \
                                ERR("Got GL error " << int(err) << " " << \
                                    "(" << e << ")");                     \
                                BUG();                                    \
                        }                                                 \
                }
#else
#define ASSERT_GL_NO_ERROR()
#endif

                static void dump_extensions()
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
                                DBG("  " << *i);
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

                        dump_extensions();
                }

                color::color(GLfloat red,
                             GLfloat green,
                             GLfloat blue,
                             GLfloat alpha) :
                        red_(red),
                        green_(green),
                        blue_(blue),
                        alpha_(alpha)
                { }

                color::~color()
                { }

                GLfloat color::red() const
                { return red_; }

                GLfloat color::green() const
                { return green_; }

                GLfloat color::blue() const
                { return blue_; }

                GLfloat color::alpha() const
                { return alpha_; }

                void color::red(GLfloat value)
                { red_ = value; }

                void color::green(GLfloat value)
                { green_ = value; }

                void color::blue(GLfloat value)
                { blue_ = value; }

                void color::alpha(GLfloat value)
                { alpha_ = value; }

                void color::program() const
                {
                        if (alpha_ == 1.0f) {
                                glColor3f(red_, green_, blue_);
                        } else {
                                glColor4f(red_, green_, blue_, alpha_);
                        }
                }

                pen::pen(const GL::color & c,
                         GLfloat           size) :
                        color_(c),
                        size_(size)
                { }

                pen::~pen()
                { }

                void pen::program() const
                {
                        color_.program();
                        glPointSize(size_);
                }

                void pen::color(const GL::color & c)
                { color_ = c; }

                color pen::color() const
                { return color_; }

                void pen::size(GLfloat value)
                { size_ = value; }

                GLfloat pen::size() const
                { return size_; }

                point::point(const pen &                  pen,
                             const MATH::point<GLfloat> & where) :
                        pen_(pen),
                        where_(where)
                { }

                point::~point()
                { }

                void point::move(const MATH::point<GLfloat> & where)
                { where_ = where; }

                void point::draw() const
                {
                        pen_.program();

                        {
                                draw_guard d(GL_POINTS);
                                glVertex2f(where_.x(), where_.y());
                        }

                        ASSERT_GL_NO_ERROR();
                }

                segment::segment(const pen &                  pen,
                                 const MATH::point<GLfloat> & from,
                                 const MATH::point<GLfloat> & to) :
                        pen_(pen),
                        from_(from),
                        to_(to)
                { }

                segment::~segment()
                { }

                void segment::move(const MATH::point<GLfloat> & where)
                {
                        // XXX FIXME: Add code here
                        (void) where;
                        //where_ = where;
                }

                void segment::rotate(GLfloat radians)
                {
                        // XXX FIXME: Add code here
                        (void) radians;

                        //angle_ = MATH::radians2angle<GLfloat>(radians);
                }

                void segment::draw() const
                {
                        pen_.program();

                        {
                                draw_guard d(GL_LINES);
                                glVertex2f(from_.x(), from_.y());
                                glVertex2f(to_.x(),   to_.y());
                        }

                        ASSERT_GL_NO_ERROR();
                }

                figure::figure() :
                        center_(MATH::point<GLfloat>(0.0f, 0.0f)),
                        rotation_(0.0f),
                        scale_(1.0f)
                { }

                figure::~figure()
                { }

                void figure::move(const MATH::point<GLfloat> & where)
                { center_ = where; }

                void figure::rotate(GLfloat radians)
                { rotation_ = MATH::radians2angle<GLfloat>(radians); }

                void figure::scale(GLfloat factor)
                { scale_ = factor; }

                triangle::triangle(const pen &                  pen,
                                   const MATH::point<GLfloat> & a,
                                   const MATH::point<GLfloat> & b,
                                   const MATH::point<GLfloat> & c,
                                   bool                         filled) :
                        pen_(pen),
                        a_(a),
                        b_(b),
                        c_(c),
                        filled_(filled)
                { }

                triangle::~triangle()
                { }

                void triangle::draw() const
                {
                        pen_.program();

                        {
                                draw_guard d(filled_      ?
                                             GL_TRIANGLES :
                                             GL_TRIANGLES);
                                glVertex3f(a_.x(), a_.y(), 0.0f);
                                glVertex3f(b_.x(), b_.y(), 0.0f);
                                glVertex3f(c_.x(), c_.y(), 0.0f);
                        }

                        ASSERT_GL_NO_ERROR();
                }

                rectangle::rectangle(const pen &                  pen,
                                     const MATH::point<GLfloat> & from,
                                     const MATH::point<GLfloat> & to,
                                     bool                         filled) :
                        pen_(pen),
                        from_(from),
                        to_(to),
                        filled_(filled)
                { }

                rectangle::~rectangle()
                { }

                void rectangle::draw() const
                {
                        pen_.program();

                        {
                                draw_guard d(filled_ ?
                                             GL_QUADS : GL_LINE_LOOP);

                                glVertex2f(from_.x(), from_.y());
                                glVertex2f(to_.x(),   from_.y());
                                glVertex2f(to_.x(),   to_.y());
                                glVertex2f(from_.x(), to_.y());
                        }

                        ASSERT_GL_NO_ERROR();
                }

                circle::circle(const pen &                  pen,
                               const MATH::point<GLfloat> & center,
                               GLfloat                      radius,
                               size_t                       segments,
                               bool                         filled) :
                        pen_(pen),
                        center_(center),
                        radius_(radius),
                        segments_(segments),
                        filled_(filled)
                { }

                circle::~circle()
                {
                        if (segments_ <= 0) {
                                segments_ = 1;
                        }
                }

                void circle::draw() const
                {
                        pen_.program();

                        {
                                const float increment =
                                        2.0f * M_PI / segments_;
                                float       theta     = 0.0f;

                                draw_guard d(filled_         ?
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

                polygon::polygon(const pen &                      pen,
                                 std::list<MATH::point<GLfloat> > points,
                                 bool                             filled) :
                        pen_(pen),
                        points_(points),
                        filled_(filled)
                { }

                void polygon::set(bool filled)
                { filled_ = filled; }

                void polygon::set(std::list<MATH::point<GLfloat> > points)
                { points_ = points; }

                void polygon::draw() const
                {
                        // glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

                        pen_.program();

                        glPushMatrix();

                        glTranslatef(center_.x(), center_.y(), 0.0f);
                        //glScalef(scale, scale, 0.0f);
                        glRotatef(rotation_, 0.0f, 0.0f, 1.0f);

                        {
                                draw_guard d(filled_         ?
                                             GL_TRIANGLE_FAN :
                                             GL_LINE_LOOP);

                                for (std::list<MATH::point<GLfloat> >::
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

                void texture::init(const image & image)
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
                        DBG("texture %d is %d x %d pixels (%s)",
                            id_,
                            width(), height(),
                            format == GL_BGRA ? "has-alpha" : "no-alpha");
#endif
                        glDisable(GL_TEXTURE_2D);

                        ASSERT_GL_NO_ERROR();
                }

                texture::texture(const image & image,
                                 const color & c) :
                        color_(c)
                { init(image); }

                texture::~texture()
                { glDeleteTextures(1, &id_); }

                void texture::set(const color & c)
                { color_ = c; }

                void texture::draw() const
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
                                draw_guard d(GL_QUADS);

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
