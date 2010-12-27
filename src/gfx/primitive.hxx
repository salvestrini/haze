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

#ifndef HAZE_GFX_PRIMITIVE
#define HAZE_GFX_PRIMITIVE

#include <GL/gl.h>

#include "core/filesystem.hxx"
#include "gfx/image.hxx"
#include "gfx/geometry.hxx"

namespace HAZE {

        namespace GL {

                class Color {
                public:
                        Color(GLfloat red   = 1.0f,
                              GLfloat green = 1.0f,
                              GLfloat blue  = 1.0f,
                              GLfloat alpha = 1.0f);
                        ~Color();

                        GLfloat red();
                        GLfloat green();
                        GLfloat blue();
                        GLfloat alpha();

                        void    red(GLfloat   value);
                        void    green(GLfloat value);
                        void    blue(GLfloat  value);
                        void    alpha(GLfloat value);

                        void    set();

                private:
                        GLfloat red_;
                        GLfloat green_;
                        GLfloat blue_;
                        GLfloat alpha_;
                };

                class Pen {
                public:
                        Pen(const Color & color = Color(),
                            GLfloat       size  = 1.0f);
                        ~Pen();

                        void    color(const Color & color);
                        Color   color();

                        void    size(GLfloat value);
                        GLfloat size();

                        void    set();

                private:
                        Color   color_;
                        GLfloat size_;
                };

                class Point {
                public:
                        Point(const Pen & pen);
                        ~Point();

                        void draw(const HAZE::Point<GLfloat> & where);

                private:
                        Pen pen_;
                };

                class Line {
                public:
                        Line(const Pen & pen);
                        ~Line();

                        void draw(const HAZE::Point<GLfloat> & from,
                                  const HAZE::Point<GLfloat> & to);

                private:
                        Pen pen_;
                };

                class Triangle {
                public:
                        Triangle(const Pen & pen,
                                 bool        filled = false);
                        ~Triangle();

                        void draw(const HAZE::Point<GLfloat> & a,
                                  const HAZE::Point<GLfloat> & b,
                                  const HAZE::Point<GLfloat> & c);

                private:
                        Pen  pen_;
                        bool filled_;
                };

                class Rectangle {
                public:
                        Rectangle(const Pen & pen,
                                  bool        filled = false);
                        ~Rectangle();

                        void draw(const HAZE::Point<GLfloat> & from,
                                  const HAZE::Point<GLfloat> & to);

                private:
                        Pen  pen_;
                        bool filled_;
                };

                class Circle {
                public:
                        Circle(const Pen & pen,
                               GLfloat     radius,
                               size_t      segments = 8,
                               bool        filled   = false);
                        ~Circle();

                        void draw(const HAZE::Point<GLfloat> & center);

                private:
                        Pen     pen_;
                        GLfloat radius_;
                        size_t  segments_;
                        bool    filled_;
                };

                class Polygon {
                public:
                        Polygon(const Pen &                    pen,
                                std::list<std::pair<GLfloat,
                                                    GLfloat> > points,
                                bool                           filled = false);

                        void draw(const HAZE::Point<GLfloat> & where,
                                  GLfloat                     scale    = 1.0f,
                                  GLfloat                     rotation = 0.0f);

                private:
                        Pen                                     pen_;
                        std::list<std::pair<GLfloat, GLfloat> > points_;
                        bool                                    filled_;
                };

                class Texture :
                        public Size<GLuint>,
                        public NonCopyable  {
                public:
                        class CannotCreate : public Exception { };

                        Texture(const Path & file,
                                const Color & color = Color());
                        Texture(const Image & image,
                                const Color & color = Color());
                        ~Texture();

                        void draw(const HAZE::Point<GLfloat> & origin,
                                  GLfloat                     scale    = 1.0f,
                                  GLfloat                     rotation = 0.0f);

                private:
                        Color  color_;
                        GLuint id_;

                        void init(const Image & image);
                };
        }

}

#endif
