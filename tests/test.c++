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

#include "haze.h++"

int main(int argc, char argv[])
{
        {
                using namespace HAZE;

                Screen screen_0;
                Screen screen_1;

                Window window_0;
                Window window_1;

                screen_0.add(window_0);
                screen_1.add(window_1);

                screen_0.draw();
                screen_1.draw();

                screen_0.remove(window_0);
                screen_1.remove(window_1);

                screen_0.draw();
                screen_1.draw();
        }

        return 0;
}
