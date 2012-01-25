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

#ifndef HAZE_GFX_MATH
#define HAZE_GFX_MATH

#include <cmath>

namespace HAZE {
        namespace MATH {

                template<typename TYPE> TYPE radians2angle(TYPE radians)
                { return radians * 180 / M_PI; }

                template<typename TYPE = int> class Point {
                public:
                        Point(const Point & p) :
                                x_(p.x()),
                                y_(p.y())
                        { }

                        Point(TYPE x = 0,
                              TYPE y = 0) :
                                x_(x),
                                y_(y)
                        { }

                        virtual ~Point()
                        { }

                        typedef TYPE size_type;

                        TYPE  x() const { return x_; }
                        TYPE  y() const { return y_; }

                        void  x(TYPE v) { x_ = v; }
                        void  y(TYPE v) { y_ = v; }

                        void  move(TYPE x,
                                   TYPE y) {
                                x_ = x;
                                y_ = y;
                        }

                private:
                        TYPE x_;
                        TYPE y_;
                };

                template<typename TYPE = int> class Rectangle {
                public:
                        Rectangle(TYPE width,
                                  TYPE height) :
                                from_(0, 0),
                                to_(width, height)
                        { }

                        Rectangle(const Point<TYPE> & from,
                                  const Point<TYPE> & to) :
                                from_(from),
                                to_(to)
                        { }

                        virtual ~Rectangle()
                        { }

                        typedef TYPE size_type;

                        virtual TYPE width() const
                        { return std::abs(to_.x() - from_.x()); }

                        virtual void width(const TYPE & v)
                        {
                                TYPE c(from_.x() + (to_.x() - from_.x()) / 2);

                                from_.x(c - v / 2);
                                to_.x(c + v / 2);
                        }

                        virtual TYPE height() const
                        { return std::abs(to_.y() - from_.y()); }

                        // XXX FIXME: Do resizing around the center
                        virtual void height(const TYPE & v)
                        {
                                TYPE c(from_.y() + (to_.y() - from_.y()) / 2);

                                from_.y(c - v / 2);
                                to_.y(c + v / 2);
                        }

                private:
                        Point<TYPE> from_;
                        Point<TYPE> to_;
                };

                template<typename TYPE = int> class Vector {
                public:
                        Vector(TYPE x = 0,
                               TYPE y = 0,
                               TYPE z = 0) :
                                x_(x),
                                y_(y),
                                z_(z)
                        { }

                        virtual ~Vector()
                        { }

                        typedef TYPE size_type;

                        TYPE  x() const { return x_; }
                        TYPE  y() const { return y_; }
                        TYPE  z() const { return z_; }

                        void  x(TYPE v) { x_ = v; }
                        void  y(TYPE v) { y_ = v; }
                        void  z(TYPE v) { z_ = v; }

                        void  move(TYPE x,
                                   TYPE y,
                                   TYPE z) {
                                x_ = x;
                                y_ = y;
                                z_ = z;
                        }

                private:
                        TYPE x_;
                        TYPE y_;
                        TYPE z_;
                };

        }
}

#endif