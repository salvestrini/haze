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

#include "haze/haze.h++"
#include "haze/gfx/backends/sdl.h++"
#include "haze/sfx/backends/sdl.h++"
#include "haze/io/backends/sdl.h++"

namespace HAZE {

        Haze::Haze() :
                video_(0),
                audio_(0),
                controller_(0)
        {
                try {
                        try {
                                video_ = new SDLVideo("SDL");
                        } catch (Exception & e) {
                                log << "Cannot create SDL video backend "
                                    << "(" << e.what() << ")"
                                    << Log::endl;
                        }
                        try {
                                audio_ = new SDLAudio("SDL");
                        } catch (Exception & e) {
                                log << "Cannot create SDL audio backend "
                                    << "(" << e.what() << ")"
                                    << Log::endl;
                        }
                        try {
                                controller_ = new SDLController("SDL");
                        } catch (Exception & e) {
                                log << "Cannot create SDL controller backend "
                                    << "(" << e.what() << ")"
                                    << Log::endl;
                        }
                } catch (std::exception & e) {
                        log << "Got a bug "
                            << "(" << e.what() << ")"
                            << Log::endl;
                }
        }

        Haze::~Haze()
        {
                if (video_)      delete video_;
                if (audio_)      delete audio_;
                if (controller_) delete controller_;
        }

        bool Haze::initialized()
        { return (video_ != 0 || audio_ != 0 || controller_ != 0); }
}
