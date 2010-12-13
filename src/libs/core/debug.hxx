// -*- c++ -*-

//
// Copyright (C) 2009 Francesco Salvestrini
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

#include <iostream>
#include <cassert>

// XXX FIXME: Add code here ...
#define BACKTRACE()

// XXX FIXME: Add code here ...
#define ASSERT_HEADER()                                 \
{                                                       \
        do {                                            \
                std::cerr << "Got bug in "              \
                          << __PRETTY_FUNCTION__        \
                          << ":"                        \
                          << __LINE__;                  \
        } while (0);                                    \
}

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

// Redefine assert() as our ASSERT()
#ifdef assert
#undef assert
#endif
#define assert(X) ASSERT(X)

#endif
