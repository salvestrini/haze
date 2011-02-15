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

//#define __STDC_LIMIT_MACROS
//#include <stdint.h>

#include "haze/core/log.hxx"
#include "haze/sfx/audio.hxx"

using namespace HAZE::SFX;

Audio::Audio(size_t frequency,
             size_t channels)
        throw(CannotInitialize)
{
        if (!SDL_WasInit(SDL_INIT_AUDIO)) {

                if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
                        throw CannotInitialize(SDL_GetError());
                }
        }
}

Audio::~Audio()
{ SDL_QuitSubSystem(SDL_INIT_AUDIO); }

size_t Audio::frequency()
{ return frequency_; }

size_t Audio::channels()
{ return channels_; }

Music::Music() :
        music_(0)
{ }

Music::~Music()
{ stop(); }

void Music::play(const Path & file,
                 size_t       loops,
                 milliseconds fade_in)
{ }

void Music::pause()
{ }

void Music::resume()
{ }

void Music::rewind()
{ }

void Music::stop()
{ }

void Music::fade(milliseconds time)
{ }

size_t Music::volume()
{ return 0; }

void Music::volume(size_t value)
{ }
