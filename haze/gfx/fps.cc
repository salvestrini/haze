//
// Copyright (C) 2012, 2013 Francesco Salvestrini
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

#include <SDL/SDL.h>

#include "haze/gfx/fps.hh"

namespace haze {

        fps::fps(size_t fps)
        {
                framecount_ = 0;
                rate_       = FPS_DEFAULT;
                rateticks_  = (1000.0f / (float) FPS_DEFAULT);
                lastticks_  = SDL_GetTicks();

                rate(fps);
        }

        fps::~fps()
        { }

        void fps::rate(size_t value)
        {
                if (value < FPS_LOWER_LIMIT) {
                        rate_ = FPS_LOWER_LIMIT;
                } else if (value > FPS_UPPER_LIMIT) {
                        rate_ = FPS_UPPER_LIMIT;
                } else {
                        rate_ = value;
                }

                framecount_ = 0;
                rateticks_  = (1000.0f / (float) rate_);
        }

        size_t fps::rate(void)
        { return rate_; }

        void  fps::compensate()
        {
                Uint32 current_ticks;
                Uint32 target_ticks;

                framecount_++;

                current_ticks = SDL_GetTicks();
                target_ticks  = lastticks_ +
                        (Uint32) ((float) framecount_ * rateticks_);

                if (current_ticks <= target_ticks) {
                        SDL_Delay(target_ticks - current_ticks);
                } else {
                        framecount_ = 0;
                        lastticks_  = SDL_GetTicks();
                }
        }

}
