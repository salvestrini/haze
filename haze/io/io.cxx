//
// Copyright (C) 2010 Francesco Salvestrini
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

#include "haze/io/io.hxx"

using namespace HAZE::IO;

Event::Event()
{ }

Event::~Event()
{ }

EventManager::EventManager()
{ }

EventManager::~EventManager()
{ }

Event * EventManager::poll()
{
        Event * tmp = 0;

        if (!SDL_PollEvent(&event_)) {
                return tmp;
        }

        switch (event_.type) {
                case SDL_KEYUP: {
                        //KeyUp * tmp = new KeyUp(event_.key.which);
                        break;
                }
                case SDL_KEYDOWN: {
                        //KeyDown * tmp = new KeyDown(event_.key.which);
                        break;
                }
                default:
                        break;
        }

        return tmp;
}
