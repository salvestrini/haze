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

#include "haze/gfx/point.h++"
#include "haze/gfx/size.h++"

namespace HAZE {

        class Rectangle {
        public:
                Rectangle();
                Rectangle(const Point & origin,
                          const Size &  size);
                Rectangle(const Point & p1,
                          const Point & p2);

                virtual ~Rectangle();

                void         move(const Point & where);

                int          x() const;
                int          y() const;
                void         x(int v);
                void         y(int v);

                unsigned int width()  const;
                unsigned int height() const;
                void         width(unsigned int v);
                void         height(unsigned int v);

                const Size & size() const;
                void         resize(const Size & s);

        protected:
                Size  size_;

        private:
                Point origin_;
        };

}

#endif // HAZE_RECTANGLE_H
