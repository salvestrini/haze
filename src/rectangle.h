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

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"

namespace HAZE {

        class Rectangle {
        public:
                Rectangle(unsigned int  x = 0,
                          unsigned int  y = 0,
                          unsigned int  w = 0,
                          unsigned int  h = 0) :
                        p1_(x, y),
                        p2_(x + w, y + h) {
                }

                Rectangle(const Point & p,
                          unsigned int  w = 0,
                          unsigned int  h = 0) :
                        p1_(p) {
                        p2_.x(p.x() + w);
                        p2_.y(p.y() + h);
                }

                Rectangle(const Point & p1,
                          const Point & p2) {
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
                }

                ~Rectangle() { }

                void move(const Point & p) {
                        unsigned int w = p2_.x() - p1_.x();
                        unsigned int h = p2_.y() - p1_.y();

                        p2_.x(p.x() + w);
                        p2_.y(p.y() + h);
                        p1_ = p;
                }

                unsigned int width() {
                        return p2_.x() - p1_.x();
                }
                unsigned int height() {
                        return p2_.y() - p1_.y();
                }

                virtual void draw() {
                }

                Rectangle operator &&(const Rectangle & rhs) {
                        Rectangle r;

                        // XXX FIXME

                        return r;
                }

        protected:

        private:
                Point p1_;
                Point p2_;
        };

}

#endif // RECTANGLE_H
