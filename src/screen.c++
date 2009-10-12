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

#include <list>

#include "size.h++"
#include "screen.h++"
#include "object.h++"

namespace HAZE {

        void Screen::add(Object & o)
        {
                objects_.push_front(&o);
        }

        void Screen::remove(Object & o)
        {
                objects_.remove(&o);
        }

        void Screen::draw(const Rectangle & clipping)
        {
                // XXX FIXME:
                //     clipping must be contained inside
                //     borders_

                std::list<Object *>::iterator iter;

                background_.draw(Point(0,0), clipping);

                for (iter  = objects_.begin();
                     iter != objects_.end();
                     iter++) {
                        (* iter)->draw(clipping);
                }

                pointer_.draw(clipping);
        }

        void Screen::resize(const Size & size)
        {
                size_ = size;
        }

}
