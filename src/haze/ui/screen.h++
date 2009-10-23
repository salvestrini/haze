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

#include "haze/core/utility.h++"
#include "haze/gfx/rectangle.h++"
#include "haze/gfx/size.h++"
#include "haze/gfx/image.h++"
#include "haze/ui/widget.h++"
#include "haze/ui/window.h++"

#define SCREEN_DEFAULT_WIDTH  640
#define SCREEN_DEFAULT_HEIGHT 320
#define SCREEN_DEFAULT_BPP    HAZE::Screen::BPP32

namespace HAZE {

        class Screen : public RectangularWidget {
        public:
                enum bytesPerPixel {
                        BPP8 = 8, BPP16 = 16, BPP24 = 24, BPP32 = 32
                };

                Screen(const std::string & name,
                       unsigned int        width  = SCREEN_DEFAULT_WIDTH,
                       unsigned int        height = SCREEN_DEFAULT_HEIGHT,
                       bytesPerPixel       bpp    = SCREEN_DEFAULT_BPP);

                void         add(Window * w);
                void         remove(Window * w);
                void         draw();
                virtual void draw(const Rectangle & clipping);
                virtual void move(const Point & where);
                virtual void resize(const Size & box);

        protected:

        private:
                unsigned int        bpp_;
                std::list<Window *> windows_;
                Image               background_;

                NOT_COPYABLE(Screen);
        };

}

#endif