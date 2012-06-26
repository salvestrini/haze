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

#ifndef HAZE_IO
#define HAZE_IO

#include <haze/gfx/video.hh>

#include <SDL/SDL_events.h>

namespace HAZE {
        namespace IO {

                class Event {
                public:
                        Event()
                        { }

                        virtual ~Event()
                        { }

                        enum Type {
                                ApplicationQuit = 1,
                                VideoResize,
                                KeyUp,
                                KeyDown,
                                MouseMotion
                        };

                        virtual Type type() const = 0;
                };

                class ApplicationQuit : public Event {
                public:
                        ApplicationQuit()
                        { }

                        virtual ~ApplicationQuit()
                        { }

                        Type type() const
                        { return Event::ApplicationQuit; }
                };

                class VideoResize : public Event {
                public:
                        VideoResize(HAZE::Video::size_type width,
                                    HAZE::Video::size_type height) :
                                width_(width),
                                height_(height)
                        { }

                        virtual ~VideoResize()
                        { }

                        Type type() const
                        { return Event::VideoResize; }

                        HAZE::Video::size_type width() const
                        { return width_; }

                        HAZE::Video::size_type height() const
                        { return height_; }

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

                        KeyPress(Key c) :
                                which_(c)
                        { }

                        virtual ~KeyPress()
                        { }

                        Key which()
                        { return which_; }

                private:
                        Key which_;
                };

                class KeyUp : public KeyPress {
                public:
                        KeyUp(KeyPress::Key c) :
                                KeyPress(c)
                        { }

                        virtual ~KeyUp()
                        { }

                        Type type() const
                        { return Event::KeyUp; }
                };

                class KeyDown : public KeyPress {
                public:
                        KeyDown(KeyPress::Key c) :
                                KeyPress(c)
                        { }

                        virtual ~KeyDown()
                        { }

                        Type type() const
                        { return Event::KeyDown; }
                };

                class MouseMotion : public Event {
                public:
                        MouseMotion(int          x,
                                    int          y,
                                    unsigned int rel_x,
                                    unsigned int rel_y) :
                                x_(x),
                                y_(y),
                                rel_x_(rel_x),
                                rel_y_(rel_y)
                        { }

                        virtual ~MouseMotion()
                        { }

                        Type type() const
                        { return Event::MouseMotion; }

                        int x() const          { return x_;     }
                        int y() const          { return y_;     }
                        int relative_x() const { return rel_x_; }
                        int relative_y() const { return rel_y_; }

                private:
                        int          x_;
                        int          y_;
                        unsigned int rel_x_;
                        unsigned int rel_y_;
                };

#if 0
                class MousePress : public Event {
                };

                class MouseButton : public MousePress {
                };

                class MouseWheel : public MousePress {
                };
#endif

                class EventManager {
                public:
                        EventManager()
                        { }

                        virtual ~EventManager()
                        { }

                        Event * poll();

                private:
                        SDL_Event event_;
                };

        }
}

#endif
