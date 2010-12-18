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

#ifndef HAZE_CORE_TIMER
#define HAZE_CORE_TIMER

#include <SDL/SDL.h>

#include "core/pattern.hxx"
#include "core/exception.hxx"

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

        class Delay {
        public:
                Delay(long milliseconds);
                ~Delay();

                void wait();

        private:
                long timeout_;
        };

}

#endif
