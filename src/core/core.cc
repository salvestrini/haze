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

#include "SDL.h"

#include "haze/core/core.hh"

namespace haze {
        namespace core {

                void init()
                {
                        if (!SDL_WasInit(SDL_INIT_TIMER)) {
                                if (SDL_InitSubSystem(SDL_INIT_TIMER) < 0) {
                                        throw cant_init(SDL_GetError());
                                }
                        }
                        if (!SDL_WasInit(SDL_INIT_EVENTS)) {
                                if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0) {
                                        throw cant_init(SDL_GetError());
                                }
                        }
                }

                void fini()
                {
                        SDL_QuitSubSystem(SDL_INIT_EVENTS);
                        SDL_QuitSubSystem(SDL_INIT_TIMER);
                }

        }
}

