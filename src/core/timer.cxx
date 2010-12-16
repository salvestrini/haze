//
// Copyright (C) 2010 Francesco Salvestrini
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

#include "core/timer.hxx"
#include "core/debug.hxx"

namespace HAZE {

        Uint32 timerCallback(Uint32 interval, void * param)
        {
                Timer * this_ = reinterpret_cast<Timer *>(param);

                this_->fire();

                switch (this_->mode()) {
                        case Timer::ONESHOT:
                                return 0;
                        case Timer::PERIODIC:
                                return interval;
                        default:
                                BUG();
                                return -1;
                }
        }

        Timer::Timer(unsigned int period, // ms
                     type         mode) :
                id_(NULL),
                period_(period),
                mode_(mode)
        { }

        Timer::~Timer()
        {
                try {
                        cancel();
                } catch (...) {
                        // What should we do ?
                }
        }

        bool Timer::isRunning()
        { return (id_ != NULL) ? true : false; }

        Timer::type Timer::mode()
        { return mode_; }

        void Timer::start()
        {
                if (id_ != NULL) {
                        // Timer already started ...
                        return;
                }

                id_ = SDL_AddTimer(period_,
                                   timerCallback,
                                   reinterpret_cast<void *>(this));
                if (id_ == NULL) {
                        throw CantStart();
                }
        }

        void Timer::cancel()
        {
                if (id_ == NULL) {
                        // Timer not started
                        return;
                }

                if (SDL_RemoveTimer(id_) != SDL_TRUE) {
                        throw CantCancel();
                }
        }
}
