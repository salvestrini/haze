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

#ifndef HAZE_PEN_H
#define HAZE_PEN_H

#include "haze/color.h++"

namespace HAZE {

        class Pen {
        public:
                Pen(const Color & color,
                    unsigned int  size) :
                        color_(color),
                        size_(size) {
                }

        protected:

        private:
                Color        color_;
                unsigned int size_;
        };

}

#endif // HAZE_PEN_H