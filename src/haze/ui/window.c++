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

#include <string>

#include "haze/log.h++"
#include "haze/size.h++"
#include "haze/rectangle.h++"
#include "haze/ui/widget.h++"
#include "haze/ui/window.h++"

namespace HAZE {

        Window::Window(const std::string & n,
                       const Size &        s) :
                        RectangularWidget(n, s)
        {
                log << "Window " << name() << " "
                    << "(" << size() << ")"
                    << " created"
                    << Log::endl;
        }

        void Window::resize(const Size & box)
        {
        }

        void Window::draw(const Rectangle & clipping)
        {
        }

}
