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

#ifndef HAZE_HAZE
#define HAZE_HAZE

#include <stdint.h>
#include <string>

#include "haze/utils/utils.hh"
#include "haze/core/core.hh"
#include "haze/fs/fs.hh"
#include "haze/io/io.hh"
#include "haze/gfx/gfx.hh"
#include "haze/ui/ui.hh"

namespace haze {

        uint8_t     version_major();
        uint8_t     version_minor();
        uint8_t     version_micro();
        std::string version();

        void init();
        void fini();

}

#endif
