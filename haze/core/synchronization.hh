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

#ifndef HAZE_CORE_SYNCHRONIZATION
#define HAZE_CORE_SYNCHRONIZATION

#include "SDL_mutex.h"

#include "haze/core/pattern.hh"

namespace haze {

        class semaphore : public non_copyable {
        public:
                semaphore(int value);
                virtual ~semaphore();

                void wait();
                void signal();

        private:
                SDL_sem * semaphore_;
        };

        class mutex : public non_copyable {
        public:
                mutex();
                virtual ~mutex();

                void lock();
                void unlock();

        private:
                SDL_mutex * mutex_;
        };

        class guard : public non_copyable {
        public:
                guard(mutex & mutex) : mutex_(mutex) {
                        mutex_.lock();
                }

                virtual ~guard() {
                        mutex_.unlock();
                }

        private:
                mutex & mutex_;
        };

}
#endif
