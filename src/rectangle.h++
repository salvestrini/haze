// -*- c++ -*-

//
// Copyright (C) 2009 Francesco Salvestrini
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

#ifndef HAZE_RECTANGLE_H
#define HAZE_RECTANGLE_H

#include "point.h++"
#include "size.h++"

namespace HAZE {

        class Rectangle {
        public:
#if 0
                Rectangle(int  x = 0,
                          int  y = 0,
                          int  w = 0,
                          int  h = 0) :
                        p1_(x, y),
                        p2_(x + w, y + h)
                {
                        // XXX FIXME: Add checks here
                }

                Rectangle(const Point & p,
                          unsigned int  w = 0,
                          unsigned int  h = 0) :
                        p1_(p)
                {
                        // XXX FIXME: Add checks here

                        p2_.x(p.x() + w);
                        p2_.y(p.y() + h);
                }
#endif

                Rectangle() :
                        origin_(0, 0),
                        size_(0, 0) { }

                Rectangle(const Point & origin,
                          const Size &  size) :
                        origin_(origin),
                        size_(size) { }

                Rectangle(const Point & p1,
                          const Point & p2)
                {
                        Point p1_, p2_;

                        if (p1.x() > p2.x()) {
                                p1_.x(p2.x());
                                p2_.x(p1.x());
                        } else {
                                p1_.x(p1.x());
                                p2_.x(p2.x());
                        }
                        if (p1.y() > p2.y()) {
                                p1_.y(p2.y());
                                p2_.y(p1.y());
                        } else {
                                p1_.y(p1.y());
                                p2_.y(p2.y());
                        }

                        origin_ = p1;
                        size_   = Size(p2_.x() - p1_.x(),
                                       p2_.y() - p1_.x());
                }

                virtual ~Rectangle() { }

                void         move(const Point & where) { origin_ = where; }

                int          x() const { return origin_.x(); }
                int          y() const { return origin_.y(); }
                void         x(int v)  { origin_.x(v); }
                void         y(int v)  { origin_.y(v); }

                unsigned int width()  const         { return size_.width();  }
                unsigned int height() const         { return size_.height(); }
                void         width(unsigned int v)  { size_.width(v);  }
                void         height(unsigned int v) { size_.height(v); }

                const Size & size()                 { return size_; }
                void         resize(const Size & s) { size_ = s; }

        protected:

        private:
                Point origin_;
                Size  size_;
        };

}

#endif // HAZE_RECTANGLE_H
