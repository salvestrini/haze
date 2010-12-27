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

#ifndef HAZE_GFX_GEOMETRY
#define HAZE_GFX_GEOMETRY

#include <cmath>
#include <utility>

namespace HAZE {

        template<typename TYPE = size_t> class Size {
        public:
                Size(TYPE width  = 0,
                     TYPE height = 0) :
                        width_(width),
                        height_(height)
                { }

                virtual ~Size()
                { }

                TYPE width() const
                { return width_; }

                TYPE height() const
                { return height_; }

                void width(TYPE value)
                { width_ = value; }

                void height(TYPE value)
                { height_ = value; }

                void resize(TYPE width,
                            TYPE height) {
                        width_  = width;
                        height_ = height;
                }

                void resize(const Size & size) {
                        width_  = size.width_;
                        height_ = size.height_;
                }

                void resize(float factor) {
                        width_  = static_cast<TYPE>(std::abs(float(width_)  *
                                                             factor));
                        height_ = static_cast<TYPE>(std::abs(float(height_) *
                                                             factor));
                }

        private:
                TYPE width_;
                TYPE height_;
        };

        template<typename TYPE = int> class Point {
        public:
                Point(TYPE x = 0, TYPE y = 0) :
                        x_(x),
                        y_(y)
                { }

                virtual ~Point()
                { }

                TYPE  x() const { return x_; }
                TYPE  y() const { return y_; }

                void  x(TYPE v) { x_ = v; }
                void  y(TYPE v) { y_ = v; }

                void  move(TYPE x, TYPE y) {
                        x_ = x;
                        y_ = y;
                }

        private:
                TYPE x_;
                TYPE y_;
        };

        template<typename TYPE = int> class Vector {
        public:
                Vector(TYPE x = 0, TYPE y = 0, TYPE z = 0) :
                        x_(x),
                        y_(y),
                        z_(z)
                { }

                virtual ~Vector()
                { }

                TYPE  x() const { return x_; }
                TYPE  y() const { return y_; }
                TYPE  z() const { return z_; }

                void  x(TYPE v) { x_ = v; }
                void  y(TYPE v) { y_ = v; }
                void  z(TYPE v) { z_ = v; }

                void  move(TYPE x, TYPE y, TYPE z) {
                        x_ = x;
                        y_ = y;
                        z_ = z;
                }

        private:
                TYPE x_;
                TYPE y_;
                TYPE z_;
        };

        template<typename PTYPE = int,
                 typename STYPE = size_t> class Rectangle :
                public Point<PTYPE>,
                public Size<STYPE> {
        public:
                Rectangle() { }

                Rectangle(PTYPE x, PTYPE y, STYPE w, STYPE h) :
                        Point<PTYPE>(x, y),
                        Size<STYPE>(w, h)
                { }

                Rectangle(const Point<PTYPE> & origin,
                          const Size<STYPE> &  size) :
                        Point<PTYPE>(origin),
                        Size<STYPE>(size)
                { }

                virtual ~Rectangle()
                { }
        };

}

#endif
