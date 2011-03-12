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
        throw(CannotInitialize) :
        frequency_(frequency),
        channels_(channels)
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
{
        (void) file;
        (void) loops;
        (void) fade_in;
}

void Music::pause()
{ }

void Music::resume()
{ }

void Music::rewind()
{ }

void Music::stop()
{ }

void Music::fade(milliseconds time)
{
        (void) time;
}

size_t Music::volume()
{ return 0; }

void Music::volume(size_t value)
{
        (void) value;
}

Sample::Sample()
{ }

Sample::~Sample()
{ }

size_t Sample::volume(size_t volume)
{
        (void) volume;

        return 0;
}

Channels::Channels(size_t amount)
{
        (void) amount;
}

Channels::~Channels()
{ }

size_t Channels::allocate(size_t amount)
{
        (void) amount;

        return 0;
}

size_t Channels::reserve(size_t index)
{
        (void) index;

        return 0;
}

void Channels::play(int          index,
                    Sample *     sample,
                    int          loops,
                    milliseconds fade_in,
                    milliseconds delay)
{
        (void) index;
        (void) sample;
        (void) loops;
        (void) fade_in;
        (void) delay;
}

void Channels::stop(int          index,
                    milliseconds delay)
{
        (void) index;
        (void) delay;
}

void Channels::fade(int          index,
                    milliseconds time)
{
        (void) index;
        (void) time;
}

void Channels::pause(int index)
{
        (void) index;
}

void Channels::resume(int index)
{
        (void) index;
}

Groups::Groups(size_t amount)
{
        (void) amount;
}

Groups::~Groups()
{ }

size_t Groups::assign(size_t channel,
                      int    index)
{
        (void) channel;
        (void) index;

        return 0;
}

size_t Groups::assign_range(size_t channels_from,
                            size_t channels_to,
                            int    index)
{
        (void) channels_from;
        (void) channels_to;
        (void) index;

        return 0;
}

void Groups::stop(int          index,
                  milliseconds delay)
{
        (void) index;
        (void) delay;
}

void Groups::fade(int          index,
                  milliseconds time)
{
        (void) index;
        (void) time;
}

size_t Groups::get_count(size_t index)
{
        (void) index;
        return 0;
}

int Groups::get_available(size_t index)
{
        (void) index;

        return 0;
}

int Groups::get_oldest(size_t index)
{
        (void) index;

        return 0;
}

int Groups::get_newer(size_t index)
{
        (void) index;

        return 0;
}
