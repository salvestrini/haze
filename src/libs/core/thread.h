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

#ifndef HAZE_THREAD_H
#define HAZE_THREAD_H

#include "settings.h"

#include <string>

#include <SDL/SDL_thread.h>

#include "log.h"
#include "utility.h"

class Thread : public NonCopyable {
        public:
                Thread(const std::string & name = "unknown");
                virtual ~Thread();

                std::string  name() { return name_; }

                void         start();
                void         stop();
                virtual void loop() = 0;

        private:
                SDL_Thread * thread_;
                std::string  name_;

                void         join();

                static int run(void * opaque);
};

#endif