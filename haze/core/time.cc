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

#include <unistd.h>

#include "haze/core/time.hh"
#include "haze/core/debug.hh"

namespace HAZE {

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
                id_(NULL),
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
        { return (id_ != NULL) ? true : false; }

        timer::type timer::mode()
        { return mode_; }

        void timer::start()
        {
                if (id_ != NULL) {
                        // Timer already started ...
                        return;
                }

                id_ = SDL_AddTimer(period_,
                                   timer_callback,
                                   reinterpret_cast<void *>(this));
                if (id_ == NULL)
                        throw cannot_start();
        }

        void timer::cancel()
        {
                if (id_ == NULL)
                        return;

                if (SDL_RemoveTimer(id_) != SDL_TRUE)
                        throw cannot_cancel();
        }

        time::time()
        { }

        time::~time()
        { }

        void time::delay(size_t milliseconds) const
        { SDL_Delay(milliseconds); }

        size_t time::ticks() const
        { return SDL_GetTicks(); }

}
