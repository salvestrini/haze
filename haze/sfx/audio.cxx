//
// Copyright (C) 2010 Francesco Salvestrini
//                    Alessandro Massignan
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

#define __STDC_LIMIT_MACROS
#include <stdint.h>

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

#include "haze/core/log.hxx"
#include "haze/sfx/audio.hxx"

using namespace HAZE::SFX;

Audio::Audio()
        throw(CannotInitialize, WrongArgument)
{
        if (!SDL_WasInit(SDL_INIT_AUDIO)) {
                if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
                        throw CannotInitialize(SDL_GetError());
                }
        }

}

Audio::~Audio()
{ SDL_QuitSubSystem(SDL_INIT_AUDIO); }

size_t Audio::channels()
{ return channels_; }

size_t Audio::frequency()
{ return frequency_; }

size_t Audio::buffer()
{ return buffer_; }

size_t Audio::open(size_t frequency,
                   size_t format,
                   size_t channels,
                   size_t chunksize) {

    if ((frequency < 0 || frequency > INT32_MAX)  ||
        (format    < 0 || format    > UINT16_MAX) ||
        (channels  < 0 || channels  > INT32_MAX)  ||
        (chunksize < 0 || chunksize > INT32_MAX))  { 
        throw WrongArgument("open()");
    }

    DBG("Initializing audio\n"
        "\tfrequency: %d\n"
        "\tformat   : %x\n"
        "\tchannels : %d\n"
        "\tchunksize: %d\n",
        frequency, format, channels, chunksize);

    if (Mix_OpenAudio(frequency, format, channels, chunksize)) {
        throw CannotInitialize(SDL_GetError());
    }

    return 0;
}

size_t Audio::close() {
    DBG("Closing audio");

    Mix_CloseAudio();

    return 0;
}

