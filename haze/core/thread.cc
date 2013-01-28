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

#include "haze/core/thread.hh"
#include "haze/core/debug.hh"
#include "haze/core/log.hh"
#include "haze/core/exception.hh"

namespace HAZE {

        int thread::run(void * opaque)
        {
                ASSERT(opaque != 0);

                thread * t = reinterpret_cast<thread *>(opaque);

                DBG("Running thread '" <<  t->name() << "' loop");
                t->loop();

                return 0;
        }

        thread::thread(const std::string & name) :
                name_(name)
        { DBG("Thread '" << name_ << "'%s created"); }

        void thread::start()
        {
                if (thread_) {
                        WRN("Thread '" << name_ << "' already started");
                        return;
                }

                DBG("Starting thread '" << name_ << "'");

                thread_ = SDL_CreateThread(run, this);
                if (thread_ == 0) {
                        throw exception(std::string("Unable to "
                                                    "create thread ") +
                                        name_                         +
                                        " "                           +
                                        SDL_GetError());
                }

                ASSERT(thread_);
        }

        void thread::stop()
        {
                if (thread_) {
                        DBG("Stopping thread '" << name_ << "'");
                        int status;

                        SDL_WaitThread(thread_, &status);

                        thread_ = 0;
                } else
                        WRN("Thread '" << name_ << "' already stopped");

                ASSERT(!thread_);
        }

        thread::~thread()
        {
                stop();

                DBG("Thread '" << name_ << "' destroyed");
        }

}
