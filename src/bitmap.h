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

#ifndef HAZE_BITMAP_H
#define HAZE_BITMAP_H

namespace HAZE {

        class Bitmap {
        public:
                Bitmap(unsigned int width,
                       unsigned int height) :
                        width_(width),
                        height_(height) { }

                unsigned int width()  const { return width_;  }
                unsigned int height() const { return height_; }

        protected:
                unsigned int width_;
                unsigned int height_;

        private:
        };

}

#endif // HAZE_BITMAP_H
