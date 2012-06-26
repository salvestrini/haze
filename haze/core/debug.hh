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

#ifndef HAZE_CORE_DEBUG
#define HAZE_CORE_DEBUG

#include <cstdlib>
#include <iostream>
#include <cassert>

void dump_backtrace();

#define BACKTRACE() dump_backtrace()

#define ASSERT_HEADER()                         \
{                                               \
	BUG();                                  \
}

// Redefine assert() as our ASSERT()
#ifdef assert
#undef assert
#endif
#define assert(X) ASSERT(X)

// Define our assert now
#ifdef NDEBUG
#define ASSERT(X)
#else
#define ASSERT(X)                               \
{                                               \
        do {                                    \
                if (!(X)) {                     \
                        ASSERT_HEADER();        \
                        BACKTRACE();            \
                }                               \
        } while (0);                            \
}
#endif

#include "haze/core/log.hh"

#define BUG()                                           \
do {                                                    \
	ERR("Got a bug in '%s' (%s:%d)",                \
	    __PRETTY_FUNCTION__, __FILE__, __LINE__);   \
	BACKTRACE();                                    \
	exit(-1);                                       \
} while (0)

#endif
