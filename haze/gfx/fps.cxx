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

#include "haze/gfx/fps.hxx"

namespace HAZE {

        FPS::FPS(size_t fps)
        {
                manager_ = new FPSmanager;

                SDL_initFramerate(manager_);
                SDL_setFramerate(manager_, fps);
        }

        FPS::~FPS()
        { delete manager_; }

        void FPS::rate(size_t value)
        { SDL_setFramerate(manager_, value); }

        size_t FPS::rate(void)
        { return SDL_getFramerate(manager_); }

        void  FPS::compensate()
        { SDL_framerateDelay(manager_); }

}
