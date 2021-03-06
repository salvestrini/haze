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

#ifndef HAZE_CORE_THREAD
#define HAZE_CORE_THREAD

#include <string>

#include "SDL_thread.h"

#include "haze/core/pattern.hh"

namespace haze {

        class thread : public non_copyable {
        public:
                thread(const std::string & name = "unknown");
                virtual ~thread();

                std::string  name() { return name_; }

                void         start();
                void         stop();
                virtual void loop() = 0;

        private:
                SDL_Thread * thread_;
                std::string  name_;

                static int   run(void * opaque);
        };

}

#endif
