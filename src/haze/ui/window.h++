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

#ifndef HAZE_UI_WINDOW
#define HAZE_UI_WINDOW

#include <string>

#include "haze/gfx/rectangle.h++"
#include "haze/ui/widget.h++"

#define WINDOW_DEFAULT_WIDTH  100
#define WINDOW_DEFAULT_HEIGHT 100

namespace HAZE {

        class Window : public RectangularWidget {
        public:
                Window(const std::string & name,
                       const Size &        size = Size(WINDOW_DEFAULT_WIDTH,
                                                       WINDOW_DEFAULT_HEIGHT));

                virtual void resize(const Size & box);
                virtual void draw(const Rectangle & clipping);

        protected:

        private:
        };

}

#endif
