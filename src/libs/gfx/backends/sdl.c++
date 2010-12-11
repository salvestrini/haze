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

#include <string>
#include <cassert>

#include <SDL/SDL.h>

#include "haze/core/log.h++"
#include "haze/gfx/backends/sdl.h++"

#define VIDEO_WIDTH  640
#define VIDEO_HEIGHT 480
#define VIDEO_BPP    8
#define VIDEO_HZ     60

namespace HAZE {

        SDLVideo::SDLVideo(const std::string & name)
                throw(CannotInitialize) :
                Video(name),
                width_(VIDEO_WIDTH),
                height_(VIDEO_HEIGHT),
                bpp_(VIDEO_BPP),
                hz_(VIDEO_HZ),
                context_(0)
        {
                if (SDL_WasInit(SDL_INIT_VIDEO)) {
                        log << "SDL video backend already initialized"
                            << Log::endl;
                } else {
                        if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
                                throw CannotInitialize(SDL_GetError());
                        }
                }

                log << "Initializing video "
                    << width_ << "x" << height_ << "@" << bpp_
                    << Log::endl;

                Uint32 flags = SDL_ANYFORMAT | SDL_OPENGL;

                int closest = SDL_VideoModeOK(width_, height_, bpp_, flags);
                if (closest <= 0) {
                        throw CannotInitialize("video mode unsupported");
                }

                // XXX FIXME: Ugly ...
                if (static_cast<unsigned int>(closest) != bpp_) {
                        bpp_ = closest;
                }

                log << "Closest video mode is "
                    << closest
                    << " bpp" << Log::endl;

                // Create the GL drawing context
                context_ = SDL_SetVideoMode(width_, height_, bpp_, flags);
                if (!context_) {
                        throw CannotInitialize(SDL_GetError());
                }

                log << "Video set to "
                    << width_ << "x" << height_
                    << "@" << bpp_
                    << "-" << hz_ << "Hz"
                    << Log::endl;

                // Set the GL attributes
                SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
                SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,   bpp_);

#if 0
                assert(bpp_ != 0);
                int tmp = bpp_ / 4;
                log << "Setting framebuffer to "
                    << tmp << " bits per channel"
                    << Log::endl;

                if (SDL_GL_SetAttribute(SDL_GL_RED_SIZE, tmp) != 0) {
                        log << "Cannot set SDL_GL_RED_SIZE attribute"
                            << Log::endl;
                }
                if (SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, tmp) != 0) {
                        log << "Cannot set SDL_GL_RED_SIZE attribute"
                            << Log::endl;
                }
                if (SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, tmp) != 0) {
                        log << "Cannot set SDL_GL_RED_SIZE attribute"
                            << Log::endl;
                }
                if (SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, tmp) != 0) {
                        log << "Cannot set SDL_GL_RED_SIZE attribute"
                            << Log::endl;
                }
#endif
        }

        SDLVideo::~SDLVideo()
        { SDL_QuitSubSystem(SDL_INIT_VIDEO); }

        unsigned int SDLVideo::width()
        { return width_; }

        unsigned int SDLVideo::height()
        { return height_; }

        unsigned int SDLVideo::bpp()
        { return bpp_; }

        unsigned int SDLVideo::hz()
        { return hz_; }

        void SDLVideo::refresh()
        { SDL_GL_SwapBuffers(); }

}
