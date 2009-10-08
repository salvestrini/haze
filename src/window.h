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

#ifndef HAZE_WINDOW_H
#define HAZE_WINDOW_H

#include "widget.h"
#include "rectangle.h"
#include "point.h"

namespace HAZE {

        class Window : public RectangularWidget {
        public:
                Window() { }
                Window(const Rectangle & r) :
                        RectangularWidget(r) { }

                virtual void draw(const Rectangle & clipping);
                virtual void move(const Point & p);
                virtual void resize(const Rectangle & box);

        protected:

        private:
        };

}

#endif // HAZE_WINDOW_H
