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

#ifndef POINT_H
#define POINT_H

#include "object.h"

namespace HAZE {

        class Point : public Object {
        public:
                Point(const Point & p) :
                        x_(p.x_),
                        y_(p.y_) {
                };

                Point(unsigned int x = 0,
                      unsigned int y = 0) :
                        x_(x),
                        y_(y) {
                };

                unsigned int x() {
                        return x_;
                }
                unsigned int y() {
                        return y_;
                }

                unsigned int x(unsigned int v) {
                        x_ = v;
                }
                unsigned int y(unsigned int v) {
                        y_ = v;
                }

                virtual void draw() {
                }

        protected:

        private:
                unsigned int x_;
                unsigned int y_;
        };

}

#endif // POINT_H
