//
// Copyright (C) 2012, 2013 Francesco Salvestrini
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

#include "haze/core/log.hh"
#include "haze/sfx/audio.hh"

using namespace HAZE::SFX;

audio::audio(size_t frequency,
             size_t channels)
        throw(cannot_initialize) :
        frequency_(frequency),
        channels_(channels)
{
        if (!SDL_WasInit(SDL_INIT_AUDIO)) {

                if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
                        throw cannot_initialize(SDL_GetError());
                }
        }
}

audio::~audio()
{ SDL_QuitSubSystem(SDL_INIT_AUDIO); }

size_t audio::frequency()
{ return frequency_; }

size_t audio::channels()
{ return channels_; }

music::music()
{
#if HAVE_SDL_MIXER
        music_ = 0;
#endif
}

music::~music()
{ stop(); }

void music::play(const path & file,
                 size_t       loops,
                 milliseconds fade_in)
{
        (void) file;
        (void) loops;
        (void) fade_in;
}

void music::pause()
{ }

void music::resume()
{ }

void music::rewind()
{ }

void music::stop()
{ }

void music::fade(milliseconds time)
{
        (void) time;
}

size_t music::volume()
{ return 0; }

void music::volume(size_t value)
{
        (void) value;
}

sample::sample()
{ }

sample::~sample()
{ }

size_t sample::volume(size_t volume)
{
        (void) volume;

        return 0;
}

channels::channels(size_t amount)
{
        (void) amount;
}

channels::~channels()
{ }

size_t channels::allocate(size_t amount)
{
        (void) amount;

        return 0;
}

size_t channels::reserve(size_t index)
{
        (void) index;

        return 0;
}

void channels::play(int          index,
                    sample *     s,
                    int          loops,
                    milliseconds fade_in,
                    milliseconds delay)
{
        (void) index;
        (void) s;
        (void) loops;
        (void) fade_in;
        (void) delay;
}

void channels::stop(int          index,
                    milliseconds delay)
{
        (void) index;
        (void) delay;
}

void channels::fade(int          index,
                    milliseconds time)
{
        (void) index;
        (void) time;
}

void channels::pause(int index)
{
        (void) index;
}

void channels::resume(int index)
{
        (void) index;
}

groups::groups(size_t amount)
{
        (void) amount;
}

groups::~groups()
{ }

size_t groups::assign(size_t channel,
                      int    index)
{
        (void) channel;
        (void) index;

        return 0;
}

size_t groups::assign_range(size_t channels_from,
                            size_t channels_to,
                            int    index)
{
        (void) channels_from;
        (void) channels_to;
        (void) index;

        return 0;
}

void groups::stop(int          index,
                  milliseconds delay)
{
        (void) index;
        (void) delay;
}

void groups::fade(int          index,
                  milliseconds time)
{
        (void) index;
        (void) time;
}

size_t groups::get_count(size_t index)
{
        (void) index;
        return 0;
}

int groups::get_available(size_t index)
{
        (void) index;

        return 0;
}

int groups::get_oldest(size_t index)
{
        (void) index;

        return 0;
}

int groups::get_newer(size_t index)
{
        (void) index;

        return 0;
}
