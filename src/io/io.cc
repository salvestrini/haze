//
// Copyright (C) 2012, 2013, 2014 Francesco Salvestrini
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

#include "haze/utils/debug.hh"
#include "haze/io/io.hh"

namespace haze {
        namespace io {

                event * event_manager::poll()
                {
                        SDL_Event event_;
                        event *   tmp = 0;

                        if (!SDL_PollEvent(&event_)) {
                                // DBG("No event in queue");
                                return tmp;
                        }

                        // DBG("Got event type %d", event_.type);

                        switch (event_.type) {
                        case SDL_QUIT:
                                DBG("Got an application-quit event");
                                tmp = new application_quit();
                                break;
#if 0
                        case SDL_VIDEORESIZE:
                                DBG("Got a video-resize event " <<
                                    "("  << event_.resize.w     <<
                                    ", " << event_.resize.h     <<
                                    ")");
                                tmp = new video_resize(event_.resize.w,
                                                       event_.resize.h);
                                break;
#endif
                        case SDL_KEYUP:
                        case SDL_KEYDOWN: {
                                key_press::Key k;

                                switch (event_.key.keysym.sym) {
                                case SDLK_UP:    k = key_press::ARROW_UP;
                                        break;
                                case SDLK_DOWN:  k = key_press::ARROW_DOWN;
                                        break;
                                case SDLK_LEFT:  k = key_press::ARROW_LEFT;
                                        break;
                                case SDLK_RIGHT: k = key_press::ARROW_RIGHT;
                                        break;
                                case SDLK_SPACE: k = key_press::SPACEBAR;
                                        break;
                                default:
                                        return tmp;
                                }

                                if (event_.type == SDL_KEYUP) {
                                        DBG("Got a key-up");
                                        tmp = new key_up(k);
                                } else {
                                        DBG("Got a key-down");
                                        tmp = new key_down(k);
                                }
                                break;
                        }
                        case SDL_MOUSEMOTION: {
                                DBG("Got mouse-motion " <<
                                    "("                 <<
                                    event_.motion.x     <<
                                    ", "                <<
                                    event_.motion.y     <<
                                    ", "                <<
                                    event_.motion.xrel  <<
                                    ", "                <<
                                    event_.motion.yrel  <<
                                    ")");
                                tmp = new mouse_motion(event_.motion.x,
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
                                DBG("Unhandled event " <<
                                    int(event_.type)   <<
                                    " in queue");
                                break;
                        }

                        return tmp;
                }

                void init()
                { }

                void fini()
                { }

        }
}
