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

#include "SDL.h"
#if HAVE_SDL2_MIXER
#include "SDL_mixer.h"
#endif

#include "haze/utils/string.hh"
#include "haze/core/log.hh"
#include "haze/sfx/sfx.hh"

namespace haze {
        namespace sfx {

                void init()
                {
                        if (!SDL_WasInit(SDL_INIT_AUDIO)) {
                                if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
                                        throw cant_init(SDL_GetError());
                                }

                                DBG("Supported decoders ("              <<
                                    tostring(Mix_GetNumChunkDecoders()) <<
                                    "):");
                                for (int i = 0;
                                     i < Mix_GetNumChunkDecoders();
                                     i++)
                                        DBG("  " << Mix_GetChunkDecoder(i));
                        }
                }

                void fini()
                { SDL_QuitSubSystem(SDL_INIT_AUDIO); }

        }
}
