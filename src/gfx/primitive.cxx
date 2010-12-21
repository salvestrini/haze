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
                { glColor4f(red_, green_, blue_, alpha_); }

                Point::Point(const Color & color) :
                        Color(color)
                { }

                Point::~Point()
                { }

                void Point::draw(const HAZE::Point<GLfloat> & where)
                {
                        set();

                        //glPointSize(1.0f);
                        glBegin(GL_POINTS);
                        glVertex2f(where.x(), where.y());
                        glEnd();
                }

                Line::Line(const Color & color) :
                        Color(color)
                { }

                Line::~Line()
                { }

                void Line::draw(const HAZE::Point<GLfloat> & from,
                                const HAZE::Point<GLfloat> & to)
                {
                        set();

                        glBegin(GL_LINES);
                        glVertex2f(from.x(), from.y());
                        glVertex2f(to.x(),   to.y());
                        glEnd();
                }

                Triangle::Triangle(const Color & color,
                                   bool          filled) :
                        Color(color),
                        filled_(filled)
                { }

                Triangle::~Triangle()
                { }

                void Triangle::draw(const HAZE::Point<GLfloat> & a,
                                    const HAZE::Point<GLfloat> & b,
                                    const HAZE::Point<GLfloat> & c)
                {
                        if (!filled_) {
                                set();
                        }

                        glBegin(GL_TRIANGLES);
                        if (filled_) {
                                set();
                        }
                        glVertex3f(a.x(), a.y(), 0.0f);
                        glVertex3f(b.x(), b.y(), 0.0f);
                        glVertex3f(c.x(), c.y(), 0.0f);
                        glEnd();

                }

                Rectangle::Rectangle(const Color & color,
                                     bool          filled) :
                        Color(color),
                        filled_(filled)
                { }

                Rectangle::~Rectangle()
                { }

                void Rectangle::draw(const HAZE::Point<GLfloat> & from,
                                     const HAZE::Point<GLfloat> & to)
                {
                        set();

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

                Circle::Circle(const Color & color,
                               GLfloat       radius,
                               size_t        slices,
                               bool          filled) :
                        Color(color),
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
                        set();

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

        }
}
