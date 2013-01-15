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

#include "haze/core/debug.hh"
#include "haze/core/synchronization.hh"
#include "haze/core/exception.hh"

namespace HAZE {

        Semaphore::Semaphore(int value)
        {
                semaphore_ = SDL_CreateSemaphore(value);
                if (semaphore_ == NULL) {
                        throw Exception(std::string("Unable to "
                                                    "create semaphore, ") +
                                        SDL_GetError());
                }

                ASSERT(semaphore_);
        }

        Semaphore::~Semaphore()
        { SDL_DestroySemaphore(semaphore_); }

        void Semaphore::wait()
        {
                if (SDL_SemWait(semaphore_)) {
                        throw Exception(std::string("Unable to wait "
                                                    "semaphore, ") +
                                        SDL_GetError());
                }
        }

        void Semaphore::signal()
        {
                if (SDL_SemPost(semaphore_)) {
                        throw Exception(std::string("Unable to signal "
                                                    "semaphore, ") +
                                        SDL_GetError());
                }
        }

        Mutex::Mutex()
        {
                mutex_ = SDL_CreateMutex();
                if (mutex_ == NULL) {
                        throw Exception(std::string("Unable to "
                                                    "create mutex, ") +
                                        SDL_GetError());
                }

                ASSERT(mutex_);
        }

        Mutex::~Mutex()
        { SDL_DestroyMutex(mutex_); }

        void Mutex::lock()
        {
                if (SDL_LockMutex(mutex_)) {
                        throw Exception(std::string("Unable to lock "
                                                    "mutex, ") +
                                        SDL_GetError());
                }
        }

        void Mutex::unlock()
        {
                if (SDL_UnlockMutex(mutex_)) {
                        throw Exception(std::string("Unable to unlock "
                                                    "mutex, ") +
                                        SDL_GetError());
                }
        }

}
