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

#include <string>

#include <SDL/SDL_thread.h>

#include "debug.hxx"
#include "log.hxx"
#include "thread.hxx"
#include "exception.hxx"

namespace HAZE {

        int Thread::run(void * opaque)
        {
                ASSERT(opaque != 0);

                Thread * t = reinterpret_cast<Thread *>(opaque);

                DBG("Running thread %s loop", t->name().c_str());
                t->loop();

                return 0;
        }

        Thread::Thread(const std::string & name) :
                name_(name)
        {
                DBG("Thread %s created", name_.c_str());
        }

        void Thread::start()
        {
                if (thread_) {
                        WRN("Thread %s already started", name_.c_str());
                        return;
                }

                DBG("Starting thread %s", name_.c_str());

                thread_ = SDL_CreateThread(run, this);
                if (thread_ == 0) {
                        throw Exception(std::string("Unable to "
                                                    "create thread ") +
                                        name_ +
                                        SDL_GetError());
                }

                ASSERT(thread_);
        }

        void Thread::stop()
        {
                if (thread_) {
                        DBG("Stopping thread %s", name_.c_str());

                        int status;

                        SDL_WaitThread(thread_, &status);

                        thread_ = 0;
                } else {
                        WRN("Thread %s already stopped", name_.c_str());
                }

                ASSERT(!thread_);
        }

        Thread::~Thread()
        {
                stop();

                DBG("Thread %s destroyed", name_.c_str());
        }

}
