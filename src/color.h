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

#ifndef COLOR_H
#define COLOR_H

namespace HAZE {

        class Color {
        public:
                Color(unsigned int red   = 0,
                      unsigned int green = 0,
                      unsigned int blue  = 0,
                      unsigned int alpha = 0) :
                        red_(red),
                        green_(green),
                        blue_(blue),
                        alpha_(alpha) {
                }
                ~Color() { };

                unsigned int r() { return red_;   }
                unsigned int g() { return green_; }
                unsigned int b() { return blue_;  }
                unsigned int a() { return alpha_; }

                void r(unsigned int v) { red_   = v; }
                void g(unsigned int v) { green_ = v; }
                void b(unsigned int v) { blue_  = v; }
                void a(unsigned int v) { alpha_ = v; }

        protected:

        private:
                unsigned int red_;
                unsigned int green_;
                unsigned int blue_;
                unsigned int alpha_;
        };

}

#endif // COLOR_H
