//
// Copyright (C) 2012, 2013 Francesco Salvestrini
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

namespace haze {
        namespace io {

                class event {
                public:
                        event()
                        { }

                        virtual ~event()
                        { }

                        enum Type {
                                application_quit = 1,
                                video_resize,
                                key_up,
                                key_down,
                                mouse_motion
                        };

                        virtual Type type() const = 0;
                };

                class application_quit : public event {
                public:
                        application_quit()
                        { }

                        virtual ~application_quit()
                        { }

                        Type type() const
                        { return event::application_quit; }
                };

                class video_resize : public event {
                public:
                        video_resize(haze::video::size_type width,
                                     haze::video::size_type height) :
                                width_(width),
                                height_(height)
                        { }

                        virtual ~video_resize()
                        { }

                        Type type() const
                        { return event::video_resize; }

                        haze::video::size_type width() const
                        { return width_; }

                        haze::video::size_type height() const
                        { return height_; }

                private:
                        haze::video::size_type width_;
                        haze::video::size_type height_;
                };

                class key_press : public event {
                public:
                        enum Key {
                                ARROW_LEFT,
                                ARROW_RIGHT,
                                ARROW_UP,
                                ARROW_DOWN,
                                SPACEBAR,
                                ESCAPE
                        };

                        key_press(Key c) :
                                which_(c)
                        { }

                        virtual ~key_press()
                        { }

                        Key which()
                        { return which_; }

                private:
                        Key which_;
                };

                class key_up : public key_press {
                public:
                        key_up(key_press::Key c) :
                                key_press(c)
                        { }

                        virtual ~key_up()
                        { }

                        Type type() const
                        { return event::key_up; }
                };

                class key_down : public key_press {
                public:
                        key_down(key_press::Key c) :
                                key_press(c)
                        { }

                        virtual ~key_down()
                        { }

                        Type type() const
                        { return event::key_down; }
                };

                class mouse_motion : public event {
                public:
                        mouse_motion(int          x,
                                     int          y,
                                     unsigned int rel_x,
                                     unsigned int rel_y) :
                                x_(x),
                                y_(y),
                                rel_x_(rel_x),
                                rel_y_(rel_y)
                        { }

                        virtual ~mouse_motion()
                        { }

                        Type type() const
                        { return event::mouse_motion; }

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
                class mouse_press : public event {
                };

                class mouse_button : public mouse_press {
                };

                class mouse_wheel : public mouse_press {
                };
#endif

                class event_manager {
                public:
                        event_manager()
                        { }

                        virtual ~event_manager()
                        { }

                        event * poll();

                private:
                        SDL_Event event_;
                };

        }
}

#endif
