//
// Copyright (C) 2012, 2013, 2014 Francesco Salvestrini
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

#include "haze/core/time.hh"
#include "haze/core/debug.hh"

namespace haze {

        static Uint32 timer_callback(Uint32 interval, void * param)
        {
                timer * this_ = reinterpret_cast<timer *>(param);

                this_->fire();

                switch (this_->mode()) {
                        case timer::ONESHOT:
                                return 0;
                        case timer::PERIODIC:
                                return interval;
                        default:
                                BUG();
                                return -1;
                }
        }

        timer::timer(unsigned int period, // ms
                     type         mode) :
                id_(0),
                period_(period),
                mode_(mode)
        { }

        timer::~timer()
        {
                try {
                        cancel();
                } catch (...) {
                        // What should we do ?
                }
        }

        bool timer::is_running()
        { return (id_ ? true : false); }

        timer::type timer::mode()
        { return mode_; }

        void timer::start()
        {
                if (id_ != NULL) {
                        // Timer already started ...
                        return;
                }

                id_ = new SDL_TimerID;
                if (!id_)
                        throw cannot_start();

                *id_ = SDL_AddTimer(period_,
                                    timer_callback,
                                    reinterpret_cast<void *>(this));
                if (!*id_)
                        throw cannot_start();
        }

        void timer::cancel()
        {
                if (id_ == 0)
                        return;

                if (SDL_RemoveTimer(*id_) != SDL_TRUE)
                        throw cannot_cancel();

                delete id_;

                id_ = 0;
        }

        time::time()
        { }

        time::~time()
        { }

        void time::delay(size_t milliseconds) const
        { SDL_Delay(milliseconds); }

        size_t time::ticks() const
        { return SDL_GetTicks(); }


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
