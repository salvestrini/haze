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

#include "log.h"

namespace HAZE {

        Log log;

        Log & operator<<(Log &        log,
                         const char * v)
        {
                static_cast<std::ostream &>(log) << v;
                return log;
        }

        Log & operator<<(Log &               log,
                         const std::string & v)
        {
                static_cast<std::ostream &>(log) << v;
                return log;
        }

        Log & operator<<(Log & log,
                         int   v)
        {
                static_cast<std::ostream &>(log) << v;
                return log;
        }

        Log & operator<<(Log &        log,
                         unsigned int v)
        {
                static_cast<std::ostream &>(log) << v;
                return log;
        }

        Log & operator<<(Log & log,
                         char  v)
        {
                static_cast<std::ostream &>(log) << v;
                return log;
        }

#if 0
        Log & Log::operator<<(Log & (*m)(Log &))
        {
                if (*m == & std::endl) {
                        log << std::endl;
                }

                return (*this);
        }
#endif

}
