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

#define SCREEN_DEFAULT_WIDTH  640
#define SCREEN_DEFAULT_HEIGHT 320

namespace HAZE {

        class Screen : public Object {
        public:
                Screen(unsigned int width  = SCREEN_DEFAULT_WIDTH,
                       unsigned int height = SCREEN_DEFAULT_HEIGHT) :
                        borders_(0, 0, width, height) {
                }

                void add(Object & o);
                void remove(Object & o);

                void draw() { draw(borders_); }

                virtual void draw(const Rectangle & clipping);
                virtual void move(const Point & where) { }
                virtual void resize(const Rectangle & box);

        protected:

        private:
                std::list<Object *> objects_;
                Rectangle           borders_;
        };

}

#endif // SCREEN_H
