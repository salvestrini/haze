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
                log << "Haze instance creation in progress ..."
                    << Log::endl;

                try {
                        video_ = new SDLVideo("SDL");
                        log << "Video backend initialized"
                            << Log::endl;
                } catch (Exception & e) {
                        throw e;
                }

                try {
                        audio_ = new SDLAudio("SDL");
                        log << "Audio backend initialized"
                            << Log::endl;
                } catch (Exception & e) {
                        delete video_; video_ = 0;
                        throw e;
                }

                try {
                        controller_ = new SDLController("SDL");
                        log << "Controller backend initialized"
                            << Log::endl;
                } catch (Exception & e) {
                        delete video_; video_ = 0;
                        delete audio_; audio_ = 0;
                        throw e;
                }

                log << "Haze instance created successfully"
                    << Log::endl;
        }

        Haze::~Haze()
        {
                if (video_)      delete video_;
                if (audio_)      delete audio_;
                if (controller_) delete controller_;

                log << "Haze instance destroyed successfully"
                    << Log::endl;
        }

        bool Haze::initialized()
        { return (video_ != 0 || audio_ != 0 || controller_ != 0); }

        Video & Haze::video()
        { return *video_; }

        Audio & Haze::audio()
        { return *audio_; }

        Controller & Haze::controller()
        { return *controller_; }
}
