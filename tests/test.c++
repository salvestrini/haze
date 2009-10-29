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

#include <iostream>

#include "haze/haze.h++"

#define LOG std::clog << "test: "
#define ERR std::cerr << "test: error: "

int main(int argc, char argv[])
{
        using namespace HAZE;

        try {
                Haze     haze;
                assert(haze.initialized());

                Video &      video      = haze.video();
                Audio &      audio      = haze.audio();
#if 0
                Controller & controller = haze.controller();
#endif

                LOG << "Video "
                    << video.width() << "x" << video.height()
                    << "@" << video.bpp()
                    << std::endl;

                LOG << "Audio "
                    << audio.channels() << "@" << audio.frequency()
                    << std::endl;

                Screen   screen_0("screen0");
                Screen   screen_1("screen1");

                Window   window_0("window0");
                Window   window_1("window1");

                screen_0.add(&window_0);
                screen_1.add(&window_1);

                screen_0.draw();
                screen_1.draw();

                screen_0.remove(&window_0);
                screen_1.remove(&window_1);

                screen_0.draw();
                screen_1.draw();
        } catch (Exception & e) {
                ERR << "Got the following exception: "
                          << e.what()
                          << std::endl;
                return 1;
        }

        return 0;
}
