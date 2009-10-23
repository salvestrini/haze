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

#include "haze/core/log.h++"
#include "haze/gfx/size.h++"
#include "haze/gfx/image.h++"
#include "haze/ui/window.h++"
#include "haze/ui/screen.h++"

namespace HAZE {

        Screen::Screen(const std::string & n,
                       unsigned int        w,
                       unsigned int        h,
                       bytesPerPixel       b) :
                RectangularWidget(n, Size(w, h)),
                bpp_(b)
        {
                log << "Screen " << name() << " "
                    << "(" << std::string(size())
                    << "@" << bpp_
                    << ")"
                    << " created"
                    << Log::endl;
        }

        void Screen::add(Window * w)
        {
                windows_.push_front(w);
                log << "Window " << *w << " added to "
                    << "screen " << *this
                    << Log::endl;
        }

        void Screen::remove(Window * w)
        {
                windows_.remove(w);
                log << "Window " << *w << " removed from "
                    << "screen " << *this
                    << Log::endl;
        }

        void Screen::draw()
        { draw(Rectangle(Point(0, 0), size())); }

        void Screen::draw(const Rectangle & clipping)
        {
                // XXX FIXME:
                //     clipping must be contained inside
                //     borders_

                std::list<Window *>::iterator iter;

                background_.draw(Point(0,0), clipping);

                for (iter  = windows_.begin();
                     iter != windows_.end();
                     iter++) {
                        (* iter)->draw(clipping);
                }
        }

        void Screen::move(const Point & where)
        { }

        void Screen::resize(const Size & box)
        { }

}
