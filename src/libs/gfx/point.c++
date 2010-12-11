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

#include <utility>

#include "haze/gfx/point.h++"

namespace HAZE {

        Point::Point(int x, int y) :
                p_(x, y)
        { }

        Point::~Point()
        { }

        int Point::x() const
        { return p_.first; }

        int Point::y() const
        { return p_.second; }

        void Point::x(int v)
        { p_.first = v; }

        void Point::y(int v)
        { p_.second = v; }

}
