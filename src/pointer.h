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

#ifndef HAZE_POINTER_H
#define HAZE_POINTER_H

#include "object.h"
#include "image.h"
#include "point.h"

namespace HAZE {

        class Pointer : public Object, public Image {
        public:
                Pointer() { }

                Pointer(const std::string & filename) :
                        Image(filename),
                        hotspot_(0, 0),
                        position_(0, 0) { }

                virtual void draw(const Rectangle & clipping) {
                        Image::draw(position_);
                }

                virtual void move(const Point & where) {
                        position_ = where;
                }

                virtual void resize(const Rectangle & box) { }

        protected:

        private:
                Point hotspot_;
                Point position_;
        };

}

#endif // HAZE_POINTER_H
