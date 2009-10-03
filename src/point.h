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

#ifndef HAZE_POINT_H
#define HAZE_POINT_H

#include <utility>

namespace HAZE {

        class Point {
        public:
                Point(const Point & p) : p_(p.p_) { }
                Point(int x = 0,
                      int y = 0) : p_(x, y) { }

                ~Point() { }

                int  x() const { return p_.first;  }
                int  y() const { return p_.second; }
                void x(int v)  { p_.first = v;     }
                void y(int v)  { p_.second = v;    }

        protected:

        private:
                std::pair<int, int> p_;
        };

}

#endif // HAZE_POINT_H
