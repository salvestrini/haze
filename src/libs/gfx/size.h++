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

#ifndef HAZE_GFX_SIZE
#define HAZE_GFX_SIZE

#include <string>

namespace HAZE {

        class Size {
        public:
                Size(unsigned int width  = 0,
                     unsigned int height = 0);
                virtual ~Size();

                unsigned int width()  const;
                unsigned int height() const;

                void         width(unsigned int width);
                void         height(unsigned int height);

                void         resize(const Size & size);
                void         resize(float factor);
                void         resize(unsigned int width,
                                    unsigned int height);

                virtual      operator std::string() const;

        protected:

        private:
                unsigned int width_;
                unsigned int height_;
        };

}

#endif
