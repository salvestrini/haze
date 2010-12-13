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

#ifndef HAZE_SFX_BACKENDS_SDL
#define HAZE_SFX_BACKENDS_SDL

#include "haze/sfx/backends/audio.h++"

namespace HAZE {

        class SDLAudio : public Audio {
        public:
                SDLAudio(const std::string & name)
                        throw(CannotInitialize);
                virtual ~SDLAudio();

                virtual size_t channels();
                virtual size_t frequency();

        private:
                size_t channels_;
                size_t frequency_;
        };

}

#endif
