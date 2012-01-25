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

#ifndef HAZE_CORE_LOG
#define HAZE_CORE_LOG

#include <cstdio>

#include "haze/settings.hxx"

extern const char * log_prefix_;

#if WANT_LOGS
#define LOG_SETPREFIX(X)                        \
        do {                                    \
                if (X) {                        \
                        log_prefix_ = X;        \
                }                               \
        } while (0)

#if WANT_DEBUG
#define DBG(FMT, ...)                           \
        fprintf(stdout,                         \
                "%s: " FMT "\n",                \
                log_prefix_,                    \
                ##__VA_ARGS__)
#else
#define DBG(FMT, ...)
#endif

#define WRN(FMT, ...)                           \
        fprintf(stderr,                         \
                "%s: " FMT "\n",                \
                log_prefix_,                    \
                ##__VA_ARGS__)
#define ERR(FMT, ...)                           \
        fprintf(stderr,                         \
                "%s: " FMT "\n",                \
                log_prefix_,                    \
                ##__VA_ARGS__)
#else
#define LOG_SETPREFIX(X)
#define DBG(FMT, ...)
#define WRN(FMT, ...)
#define ERR(FMT, ...)
#endif

#endif
