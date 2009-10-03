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

#ifndef HAZE_WIDGET_H
#define HAZE_WIDGET_H

#include "rectangle.h"
#include "object.h"

namespace HAZE {

        class Widget : public Object {
        public:
                Widget(const Rectangle & r) : borders_(r) { }

                virtual void draw(const Rectangle & clipping) = 0;
                virtual void move(const Point & p)            = 0;
                virtual void resize(const Rectangle & box)    = 0;

                virtual const Rectangle & borders()  { return borders_; }

        protected:

        private:
                Rectangle borders_;
        };

}

#endif // HAZE_WIDGET_H
