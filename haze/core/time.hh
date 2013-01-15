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

#ifndef HAZE_CORE_TIME
#define HAZE_CORE_TIME

#include <SDL/SDL.h>

#include "haze/core/pattern.hh"
#include "haze/core/exception.hh"

namespace HAZE {

        class Timer : public NonCopyable {
        public:
                enum type {
                        ONESHOT,
                        PERIODIC
                };

                Timer(unsigned int period, // ms
                      type         mode);
                ~Timer();

                virtual void fire() = 0;

                class CantStart  : public Exception { };
                class CantCancel : public Exception { };

                void start();
                void cancel();
                bool isRunning();
                type mode();

        private:
                SDL_TimerID  id_;
                unsigned int period_;
                type         mode_;
        };

        class Time {
        public:
                Time();
                ~Time();

                void   delay(size_t milliseconds) const;
                size_t ticks() const;
        };
}

#endif
