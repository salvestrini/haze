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

#ifndef HAZE_FRAME_H
#define HAZE_FRAME_H

#include "rectangle.h"
#include "image.h"

namespace HAZE {

        class Frame : public Rectangle {
        public:
                struct defs {
                        Image * tl_;
                        Image * t_;
                        Image * tr_;
                        Image * l_;
                        Image * r_;
                        Image * bl_;
                        Image * b_;
                        Image * br_;
                };

                Frame(const struct defs & d);
                virtual ~Frame() { }

                virtual void draw(const Rectangle & clipping);

        protected:
                struct defs defs_;

        private:
        };

}

#endif // HAZE_FRAME_H
