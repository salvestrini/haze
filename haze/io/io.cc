//
// Copyright (C) 2012 Francesco Salvestrini
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

#include "haze/core/debug.hh"
#include "haze/io/io.hh"

using namespace HAZE::IO;

Event * EventManager::poll()
{
        SDL_Event event_;
        Event *   tmp = 0;

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
                        KeyPress::Key k;

                        switch (event_.key.keysym.sym) {
                                case SDLK_UP:    k = KeyPress::ARROW_UP;
                                        break;
                                case SDLK_DOWN:  k = KeyPress::ARROW_DOWN;
                                        break;
                                case SDLK_LEFT:  k = KeyPress::ARROW_LEFT;
                                        break;
                                case SDLK_RIGHT: k = KeyPress::ARROW_RIGHT;
                                        break;
                                case SDLK_SPACE: k = KeyPress::SPACEBAR;
                                        break;
                                default:
                                        return tmp;
                        }

                        if (event_.type == SDL_KEYUP) {
                                DBG("Got a key-up");
                                tmp = new KeyUp(k);
                        } else {
                                DBG("Got a key-down");
                                tmp = new KeyDown(k);
                        }
                        break;
                }
                case SDL_MOUSEMOTION: {
                        DBG("Got mouse-motion (%d, %d, %d, %d)",
                            event_.motion.x,
                            event_.motion.y,
                            event_.motion.xrel,
                            event_.motion.yrel);
                        tmp = new MouseMotion(event_.motion.x,
                                              event_.motion.y,
                                              event_.motion.xrel,
                                              event_.motion.yrel);
                }
                case SDL_MOUSEBUTTONDOWN:
                case SDL_MOUSEBUTTONUP: {
                        if (event_.button.button == SDL_BUTTON_LEFT) {
                                DBG("Unhandled mouse-press");
                                return tmp;
                        }

                        switch (event_.button.button) {
                                case SDL_PRESSED:
                                        DBG("Got a mouse-down");
                                        break;
                                case SDL_RELEASED:
                                        DBG("Got a mouse-up");
                                        break;
                        }
                }
                default:
                        DBG("Unhandled event 0x%x in queue", event_.type);
                        break;
        }

        return tmp;
}
