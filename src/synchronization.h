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

#ifndef HAZE_SYNCHRONIZATION_H
#define HAZE_SYNCHRONIZATION_H

#include "config.h"

#include <SDL/SDL_thread.h>

#include "utility.h"

class Semaphore : public NonCopyable {
        public:
                Semaphore(int value);
                virtual ~Semaphore();

                void wait();
                void signal();

        private:
                SDL_sem * semaphore_;
};

class Mutex : public NonCopyable {
	public:
		Mutex();
		virtual ~Mutex();

		void lock();
		void unlock();

	private:
		SDL_mutex * mutex_;
};

class Guard : public NonCopyable {
	public:
		Guard(Mutex & mutex) : mutex_(mutex) {
			mutex_.lock();
		}

		virtual ~Guard() {
			mutex_.unlock();
		}

	private:
		Mutex & mutex_;
};

#endif