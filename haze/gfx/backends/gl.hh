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

#ifndef HAZE_GFX_BACKENDS_GL
#define HAZE_GFX_BACKENDS_GL

#include "haze/core/filesystem.hh"

#include "haze/gfx/config.hh"

#if HAVE_OPENGL
#include <GL/gl.h>
#else
#error I have no GL header to use ...
#endif

#include "haze/gfx/image.hh"
#include "haze/gfx/geometry.hh"

namespace haze {

        namespace GL {

                void init();

                class draw_guard {
                public:
                        draw_guard(GLenum mode) {
                                glBegin(mode);
                        }

                        ~draw_guard() {
                                glEnd();
                        }
                };

                class color {
                public:
                        color(GLfloat red   = 1.0f,
                              GLfloat green = 1.0f,
                              GLfloat blue  = 1.0f,
                              GLfloat alpha = 1.0f);
                        ~color();

                        GLfloat red()   const;
                        GLfloat green() const;
                        GLfloat blue()  const;
                        GLfloat alpha() const;

                        void    red(GLfloat   value);
                        void    green(GLfloat value);
                        void    blue(GLfloat  value);
                        void    alpha(GLfloat value);

                        void    program() const;

                private:
                        GLfloat red_;
                        GLfloat green_;
                        GLfloat blue_;
                        GLfloat alpha_;
                };

                class pen {
                public:
                        pen(const color & c    = GL::color(),
                            GLfloat       size = 1.0f);
                        ~pen();

                        void      color(const GL::color & c);
                        GL::color color() const;

                        void      size(GLfloat value);
                        GLfloat   size() const;

                        void      program() const;

                private:
                        GL::color color_;
                        GLfloat   size_;
                };

                class point {
                public:
                        point(const pen &                  pen,
                              const math::point<GLfloat> & where =
                              math::point<GLfloat>(0.0f, 0.0f));
                        ~point();

                        void move(const math::point<GLfloat> & where);

                        void draw() const;

                private:
                        pen                  pen_;
                        math::point<GLfloat> where_;
                };

                class segment {
                public:
                        segment(const pen &                  pen,
                                const math::point<GLfloat> & from =
                                math::point<GLfloat>(0.0f, 0.0f),
                                const math::point<GLfloat> & to =
                                math::point<GLfloat>(0.0f, 0.0f));
                        ~segment();

                        void move(const math::point<GLfloat> & where);
                        void rotate(GLfloat radians);
                        //void scale(GLfloat factor)

                        void draw() const;

                private:
                        pen                  pen_;
                        math::point<GLfloat> from_;
                        math::point<GLfloat> to_;
                };

                class figure {
                public:
                        figure();
                        virtual ~figure();

                        virtual void move(const math::point<GLfloat> & where);
                        virtual void rotate(GLfloat radians);
                        virtual void scale(GLfloat factor);

                        virtual void draw() const = 0;

                protected:
                        math::point<GLfloat> center_;
                        GLfloat              rotation_; // degrees
                        GLfloat              scale_;
                };

                class triangle : public figure {
                public:
                        triangle(const pen &                  pen,
                                 const math::point<GLfloat> & a,
                                 const math::point<GLfloat> & b,
                                 const math::point<GLfloat> & c,
                                 bool                         filled = false);
                        ~triangle();

                        virtual void draw() const;

                private:
                        pen                  pen_;
                        math::point<GLfloat> a_;
                        math::point<GLfloat> b_;
                        math::point<GLfloat> c_;
                        bool                 filled_;
                };

                class rectangle : public figure {
                public:
                        rectangle(const pen &                  pen,
                                  const math::point<GLfloat> & from,
                                  const math::point<GLfloat> & to,
                                  bool                         filled = false);
                        ~rectangle();

                        virtual void draw() const;

                private:
                        pen                  pen_;
                        math::point<GLfloat> from_;
                        math::point<GLfloat> to_;
                        bool                 filled_;
                };

                class circle : public figure {
                public:
                        circle(const pen &                  pen,
                               const math::point<GLfloat> & center,
                               GLfloat                      radius,
                               size_t                       segments = 8,
                               bool                         filled   = false);
                        ~circle();

                        virtual void draw() const;

                private:
                        pen                  pen_;
                        math::point<GLfloat> center_;
                        GLfloat              radius_;
                        size_t               segments_;
                        bool                 filled_;
                };

                class polygon : public figure {
                public:
                        polygon(const pen &                        pen,
                                std::list<math::point<GLfloat> >   points =
                                std::list<math::point<GLfloat> >(),
                                bool                               filled =
                                false);

                        void set(bool filled);
                        void set(std::list<math::point<GLfloat> > points);

                        virtual void draw() const;

                private:
                        pen                              pen_;
                        std::list<math::point<GLfloat> > points_;
                        bool                             filled_;
                };

                class texture :
                        public bounding_box<GLuint>,
                        public non_copyable,
                        public figure {
                public:
                        class cannot_create : public exception { };

                        texture(const image & image,
                                const color & c = color());
                        ~texture();

                        void set(const color & c);

                        virtual void draw() const;

                        // XXX FIXME: Add size_type and size()

                private:
                        color  color_;
                        GLuint id_;

                        void init(const image & image);
                };
        }

}

#endif
