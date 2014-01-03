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

#ifndef HAZE_CORE_DEBUG
#define HAZE_CORE_DEBUG

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#include "haze/core/log.hh"
#include "haze/utils/string.hh"

std::vector<std::string> backtrace();

#define BACKTRACE_DUMP()                                                \
        do {                                                            \
                std::vector<std::string> tmp(backtrace());              \
                                                                        \
                ERR("");                                                \
                if (tmp.size() != 0) {                                  \
                        ERR("Backtrace " <<                             \
                            "(" << tmp.size() << " stack frames):");    \
                        for (std::vector<std::string>::const_iterator i = \
                                     tmp.begin();                       \
                             i != tmp.end();                            \
                             i++)                                       \
                                ERR("  " << *i);                        \
                } else {                                                \
                        WRN("Backtrace is empty ...");                  \
                }                                                       \
                ERR("");                                                \
        } while (false)

#define ABORT() std::abort()

// Redefine assert() as our ASSERT()
#ifdef assert
#undef assert
#endif
#define assert(X) ASSERT(X)

// Define our assert now
#ifdef NDEBUG
#define ASSERT(X)
#else
#define ASSERT(X)                                                       \
        do {                                                            \
                if (!(X)) {                                             \
                        ERR("Assertion " << quote(_STR(X)) << " " <<    \
                            "failed in "                          <<    \
                            "'" <<  __PRETTY_FUNCTION__ << "' "   <<    \
                            "(" << __FILE__ << ":" << __LINE__ << ")"); \
                        BACKTRACE_DUMP();                               \
                        ABORT();                                        \
                }                                                       \
        } while (false)
#endif

#define BUG()                                                           \
        do {                                                            \
                ERR("Got a bug in '" <<  __PRETTY_FUNCTION__ << "' " << \
                    "(" << __FILE__ << ":" << __LINE__ << ")");         \
                BACKTRACE_DUMP();                                       \
                ABORT();                                                \
        } while (false)

#endif
