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

#ifndef HAZE_GFX
#define HAZE_GFX

#include "haze/gfx/math.hh"
#include "haze/gfx/camera.hh"
#include "haze/gfx/view.hh"
#include "haze/gfx/font.hh"
#include "haze/gfx/geometry.hh"
#include "haze/gfx/image.hh"
#include "haze/gfx/text.hh"
#include "haze/gfx/video.hh"

namespace haze {
        namespace gfx {

                class cant_init : public exception {
                public:
                        cant_init(const std::string & what) :
                                exception(what) { }
                };

                void init();
                void fini();

        }
}

#endif
