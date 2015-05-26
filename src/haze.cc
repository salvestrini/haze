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

#include "version.hh"
#include "haze/haze.hh"

namespace haze {

        uint8_t version_major()
        { return HAZE_VERSION_MAJOR; }

        uint8_t version_minor()
        { return HAZE_VERSION_MINOR; }

        uint8_t version_micro()
        { return HAZE_VERSION_MICRO; }

        std::string version()
        {
                std::string tmp;

                tmp += tostring(HAZE_VERSION_MAJOR);
                tmp += ".";
                tmp += tostring(HAZE_VERSION_MINOR);
                tmp += ".";
                tmp += tostring(HAZE_VERSION_MICRO);

                return tmp.c_str();
        }

        void init()
        {
                DBG("Version " << version() << " initializing");

                utils::init();
                fs::init();
                core::init();
                io::init();
                gfx::init();
        }

        void fini()
        {
                gfx::fini();
                io::fini();
                core::fini();
                fs::fini();
                utils::fini();
        }

}
