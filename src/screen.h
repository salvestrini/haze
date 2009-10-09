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

#ifndef HAZE_SCREEN_H
#define HAZE_SCREEN_H

#include <list>

#include "log.h"
#include "object.h"
#include "rectangle.h"
#include "pointer.h"
#include "utility.h"
#include "size.h"

#define SCREEN_DEFAULT_WIDTH  640
#define SCREEN_DEFAULT_HEIGHT 320
#define SCREEN_DEFAULT_BPP    HAZE::Screen::BPP32

namespace HAZE {

        class Screen : public Object {
        public:
                enum bytesPerPixel {
                        BPP8 = 8, BPP16 = 16, BPP24 = 24, BPP32 = 32
                };

                Screen(unsigned int  width  = SCREEN_DEFAULT_WIDTH,
                       unsigned int  height = SCREEN_DEFAULT_HEIGHT,
                       bytesPerPixel bpp    = SCREEN_DEFAULT_BPP) :
                        size_(width, height),
                        bpp_(bpp)
                {
#if 0
                        log << "Screen "
                            << size_.width() << "x" << size_.height()
                            << " created"
                            << std::endl;
#endif
                }

                void         add(Object & o);
                void         remove(Object & o);
                void         draw() { draw(Rectangle(Point(0, 0), size_)); }
                virtual void draw(const Rectangle & clipping);
                virtual void move(const Point & where) { }
                virtual void resize(const Size & size);

        protected:
                DECLARE_COPY_CTORS(Screen);

        private:
                Size                size_;
                unsigned int        bpp_;
                std::list<Object *> objects_;
                Pointer             pointer_;
                Image               background_;
        };

}

#endif // HAZE_SCREEN_H
