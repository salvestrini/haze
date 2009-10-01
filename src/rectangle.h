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

namespace HAZE {

        class Rectangle : public Object {
        public:
                Rectangle() {
                }

                Rectangle(const Point & p,
                          unsigned int  w = 0,
                          unsigned int  h = 0) :
                        p1_(p)
                        p2_(p.x() + w,
                            p.y() + h) {
                };

                Rectangle(const Point & p1,
                          const Point & p2) :
                        p1_(p1),
                        p2_(p2) {
                };

                void draw() {
                }

        protectd:
        private:
                Point p1_;
                Point p2_;
        };

}

#endif // RECTANGLE_H
