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

#include "haze/config.hh"

#if HAVE_EXECINFO_H
#include <execinfo.h>
#endif

#include "haze/core/log.hh"
#include "haze/core/debug.hh"

#define MAX_BACKTRACE_FRAMES 200

std::vector<std::string> backtrace()
{
        std::vector<std::string> tmp;

#if HAVE_BACKTRACE && HAVE_BACKTRACE_SYMBOLS
        void *  array[MAX_BACKTRACE_FRAMES];
        size_t  size;
        char ** strings;
        size_t  i;

        size    = backtrace(array, MAX_BACKTRACE_FRAMES);
        strings = backtrace_symbols(array, size);

        if (strings) {
                for (i = 0; i < size; i++)
                        tmp.push_back(strings[i]);

                free(strings);
        }
#endif

        return tmp;
}
