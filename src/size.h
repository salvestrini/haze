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

#ifndef HAZE_SIZE_H
#define HAZE_SIZE_H

#include <cmath>

namespace HAZE {

        class Size {
        public:
                Size(unsigned int width  = 0,
                     unsigned int height = 0) :
                        width_(width),
                        height_(height) { }

                unsigned int width()  const { return width_;  }
                unsigned int height() const { return height_; }

                void width(unsigned int width)   { width_  = width;  }
                void height(unsigned int height) { height_ = height; }

                void resize(const Size & size) {
                        width_  = size.width_;
                        height_ = size.height_;
                }
                void resize(float factor) {
                        width_  = int(std::abs(float(width_) * factor));
                        height_ = int(std::abs(float(height_) * factor));
                }

                void resize(unsigned int width,
                            unsigned int height) {
                        width_  = width;
                        height_ = height;
                }

        protected:

        private:
                unsigned int width_;
                unsigned int height_;
        };

}

#endif // HAZE_SIZE_H
