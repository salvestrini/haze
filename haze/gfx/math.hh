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

#ifndef HAZE_GFX_MATH
#define HAZE_GFX_MATH

#include <cmath>

namespace HAZE {
        namespace MATH {

                template<typename TYPE> TYPE radians2angle(TYPE radians)
                { return radians * 180 / M_PI; }

                template<typename TYPE = float> class point {
                public:
                        point(const point & p) :
                                x_(p.x()),
                                y_(p.y()),
                                z_(p.z())
                        { }

                        point(TYPE x = 0,
                              TYPE y = 0,
                              TYPE z = 0) :
                                x_(x),
                                y_(y),
                                z_(z)
                        { }

                        virtual ~point()
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

                template<typename TYPE = int> class rectangle {
                public:
                        rectangle(TYPE width,
                                  TYPE height) :
                                from_(0, 0),
                                to_(width, height)
                        { }

                        rectangle(const point<TYPE> & from,
                                  const point<TYPE> & to) :
                                from_(from),
                                to_(to)
                        { }

                        virtual ~rectangle()
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

                        virtual void resize(const TYPE & w,
                                            const TYPE & h) {
                                width(w);
                                height(h);
                        }

                private:
                        point<TYPE> from_;
                        point<TYPE> to_;
                };

                template<typename TYPE = float> class Vector {
                public:
                        Vector(TYPE xv = 0, TYPE yv = 0, TYPE zv = 0) :
                                x(xv), y(yv), z(zv)
                        { }

                        Vector(const Vector & other) :
                                x(other.x), y(other.y), z(other.z)
                        { }

                        virtual ~Vector()
                        { }

                        typedef TYPE size_type;

                        inline Vector operator + (const Vector & v)
                        { return Vector(v.x + x, v.y + y, v.z + z); }

                        inline Vector operator - (const Vector &v)
                        { return Vector(x - v.x, y - v.y, z - v.z); }

                        inline Vector operator * (TYPE value)
                        { return Vector(x * value, y * value, z * value); }

                        inline Vector operator / (TYPE value)
                        { return Vector(x / value, y / value, z / value); }

                        TYPE x;
                        TYPE y;
                        TYPE z;
                };

                template<typename TYPE = float> class Vertex {
                public:
                        Vertex(const Vertex & other) :
                                x(other.x), y(other.y), z(other.z)
                        { }

                        Vertex(TYPE xv = 0, TYPE yv = 0, TYPE zv = 0) :
                                x(xv), y(yv), z(zv)
                        { }

                        virtual ~Vertex()
                        { }

                        typedef TYPE size_type;

                        TYPE x;
                        TYPE y;
                        TYPE z;
                };

        }
}

#endif
