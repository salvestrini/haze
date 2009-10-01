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

#ifndef SCREEN_H
#define SCREEN_H

#include <list>

#include "object.h"
#include "rectangle.h"

namespace HAZE {

        class Screen : public Rectangle {
        public:
                void add(const Object & o);
                void remove(const Object & o);
                void draw();

        protected:

        private:
                std::list<Object *> objects_;
        };

}

#endif // SCREEN_H
