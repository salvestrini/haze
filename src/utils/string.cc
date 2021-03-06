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

#include <sstream>

#include "haze/utils/string.hh"

namespace haze {

        std::string quote(const std::string & s)
        { return std::string("`") + s + std::string("'"); }

        std::string quote(const char * s)
        { return quote(std::string(SAFE_CSTR(s))); }

        std::string tostring(int i)
        {
                std::stringstream s;

                s << i;

                return s.str();
        }

}
