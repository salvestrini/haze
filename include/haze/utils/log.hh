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

#ifndef HAZE_UTILS_LOG
#define HAZE_UTILS_LOG

#include <iostream>

namespace haze {
        extern const char * logs_prefix_;
}

#define LOGS_PREFIX_SET(X)                      \
        do {                                    \
                if (X)                          \
                        haze::logs_prefix_ = X; \
        } while (false)
#define _LOG(STREAM, TXT)                                       \
        do {                                                    \
                if (haze::logs_prefix_)                         \
                        STREAM << haze::logs_prefix_ << ": ";   \
                STREAM << TXT << std::endl;                     \
        } while (false)

namespace haze {
        extern bool logs_debug_;
}

#define DBG(TXT) do {                                   \
	if (haze::logs_debug_) _LOG(std::cout, TXT);    \
} while (0)
#define MSG(TXT) _LOG(std::cout, TXT)
#define WRN(TXT) _LOG(std::cout, TXT)
#define ERR(TXT) _LOG(std::cout, TXT)

#endif
