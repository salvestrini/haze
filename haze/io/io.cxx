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

#include "haze/core/debug.hxx"
#include "haze/io/io.hxx"

using namespace HAZE::IO;

Event::Event()
{ }

Event::~Event()
{ }

ApplicationQuit::ApplicationQuit()
{ }

ApplicationQuit::~ApplicationQuit()
{ }

VideoResize::VideoResize(HAZE::Video::size_type width,
                         HAZE::Video::size_type height) :
        width_(width),
        height_(height)
{ }

VideoResize::~VideoResize()
{ }

HAZE::Video::size_type VideoResize::width()
{ return width_; }

HAZE::Video::size_type VideoResize::height()
{ return height_; }

KeyPress::KeyPress(Key c) :
        which_(c)
{ }

KeyPress::~KeyPress()
{ }

KeyUp::KeyUp(KeyPress::Key c) :
        KeyPress(c)
{ }

KeyUp::~KeyUp()
{ }

KeyDown::KeyDown(KeyPress::Key c) :
        KeyPress(c)
{ }

KeyDown::~KeyDown()
{ }

SDL_Event EventManager::event_;

EventManager::EventManager()
{ }

EventManager::~EventManager()
{ }

Event * EventManager::poll()
{
        Event * tmp = 0;

        if (!SDL_PollEvent(&event_)) {
                // DBG("No event in queue");
                return tmp;
        }

        // DBG("Got event type %d", event_.type);

        switch (event_.type) {
                case SDL_QUIT:
                        DBG("Got an application-quit event");
                        tmp = new ApplicationQuit();
                        break;

                case SDL_VIDEORESIZE:
                        DBG("Got a video-resize (%d, %d) event",
                            event_.resize.w, event_.resize.h);
                        tmp = new VideoResize(event_.resize.w,
                                              event_.resize.h);
                        break;

                case SDL_KEYUP:
                case SDL_KEYDOWN: {
                        DBG("Got key-press");

                        KeyPress::Key k;

                        switch (event_.key.keysym.sym) {
                        case SDLK_UP:    k = KeyPress::ARROW_UP;    break;
                        case SDLK_DOWN:  k = KeyPress::ARROW_DOWN;  break;
                        case SDLK_LEFT:  k = KeyPress::ARROW_LEFT;  break;
                        case SDLK_RIGHT: k = KeyPress::ARROW_RIGHT; break;
                        case SDLK_SPACE: k = KeyPress::SPACEBAR;    break;
                        default:
                                return tmp;
                        }

                        if (event_.type == SDL_KEYUP) {
                                DBG("It's a key-up");
                                tmp = new KeyUp(k);
                        } else {
                                DBG("It's a key-down");
                                tmp = new KeyDown(k);
                        }
                        break;
                }
                default:
                        DBG("Unhandled event in queue");
                        break;
        }

        return tmp;
}
