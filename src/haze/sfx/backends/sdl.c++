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

#include <string>

#include "SDL/SDL.h"

#include "haze/core/log.h++"
#include "haze/sfx/backends/sdl.h++"

namespace HAZE {

        SDLAudio::SDLAudio(const std::string & name)
                throw(CannotInitialize) :
                Audio(name),
                channels_(0),
                frequency_(0)
        {
                if (SDL_WasInit(SDL_INIT_VIDEO)) {
                        log << "SDL audio backend already initialized"
                            << Log::endl;
                } else {
                        if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
                                throw CannotInitialize(SDL_GetError());
                        }
                }

                log << "Initializing audio "
                    << channels_ << "@" << frequency_
                    << Log::endl;
        }

        SDLAudio::~SDLAudio()
        { SDL_QuitSubSystem(SDL_INIT_AUDIO); }

        size_t SDLAudio::channels()
        { return channels_; }

        size_t SDLAudio::frequency()
        { return frequency_; }

}
