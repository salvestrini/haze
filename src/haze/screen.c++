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

#include "haze/size.h++"
#include "haze/screen.h++"
#include "haze/object.h++"
#include "haze/image.h++"

namespace HAZE {

        Screen::Screen(const std::string & name,
                       unsigned int        width,
                       unsigned int        height,
                       bytesPerPixel       bpp) :
                Object(name),
                size_(width, height),
                bpp_(bpp)
        {
                log << "Screen " << name << " "
                    << "(" << size_.width()
                    << "x" << size_.height()
                    << "@" << bpp_
                    << ")"
                    << " created"
                    << Log::endl;
        }

        void Screen::add(Object & o)
        {
                objects_.push_front(&o);
        }

        void Screen::remove(Object & o)
        {
                objects_.remove(&o);
        }

        void Screen::draw()
        { draw(Rectangle(Point(0, 0), size_)); }

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
        }

        void Screen::resize(const Size & size)
        {
                size_ = size;
        }

}
