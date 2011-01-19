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

#ifndef HAZE_IO
#define HAZE_IO

#include <haze/gfx/video.hxx>
#include <SDL/SDL_events.h>

namespace HAZE {
        namespace IO {

                class Event {
                public:
                        Event();
                        ~Event();

                        enum Type {
                                ApplicationQuit = 1,
                                VideoResize,
                                KeyUp,
                                KeyDown
                        };

                        virtual Type type() = 0;
                };

                class ApplicationQuit : public Event {
                public:
                        ApplicationQuit();
                        ~ApplicationQuit();

                        Type type()
                        { return Event::ApplicationQuit; }
                };

                class VideoResize : public Event {
                public:
                        VideoResize(HAZE::Video::size_type width,
                                    HAZE::Video::size_type height);
                        ~VideoResize();

                        Type type()
                        { return Event::VideoResize; }

                        HAZE::Video::size_type width();
                        HAZE::Video::size_type height();

                private:
                        HAZE::Video::size_type width_;
                        HAZE::Video::size_type height_;
                };

                class KeyPress : public Event {
                public:
                        enum Key {
                                ARROW_LEFT,
                                ARROW_RIGHT,
                                ARROW_UP,
                                ARROW_DOWN,
                                SPACEBAR,
                                ESCAPE
                        };

                        KeyPress(Key c);
                        ~KeyPress();

                        Key which();

                private:
                        Key which_;
                };

                class KeyUp : public KeyPress {
                public:
                        KeyUp(KeyPress::Key c);
                        ~KeyUp();

                        Type type()
                        { return Event::KeyUp; }
                };

                class KeyDown : public KeyPress {
                public:
                        KeyDown(KeyPress::Key c);
                        ~KeyDown();

                        Type type()
                        { return Event::KeyDown; }
                };

                class EventManager {
                public:
                        EventManager();
                        ~EventManager();

                        Event * poll();

                private:
                        static SDL_Event event_;
                };

        }
}

#endif
