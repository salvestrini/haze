//
// Copyright (C) 2012 Francesco Salvestrini
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

#ifndef HAZE_CORE_LOG
#define HAZE_CORE_LOG

#include "haze/settings.hh"

#include <cstdio>
#include <iostream>

#if WANT_LOGS
extern const char * log_prefix_;

#define LOG_SETPREFIX(X)                        \
        do {                                    \
                if (X) {                        \
                        log_prefix_ = X;        \
                }                               \
        } while (false)

#define _LOG(STREAM, MSG)                               \
	do {                                            \
	        if (log_prefix_)                        \
		        STREAM << log_prefix_ << ": ";  \
		STREAM << MSG << std::endl;             \
	} while (false)
#else
#define LOG_SETPREFIX(X)  do { } while (false)
#define _LOG(STREAM, MSG) do { } while (false)
#endif

#if WANT_DEBUG
#define DBG(MSG) _LOG(std::cout, MSG)
#else
#define DBG(MSG)
#endif
#define WRN(MSG) _LOG(std::cout, MSG)
#define ERR(MSG) _LOG(std::cout, MSG)

#endif
