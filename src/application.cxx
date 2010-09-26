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

#include "config.h"

#include <stdexcept>
#include <string>

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#include "application.h"
#include "log.h"

Application::Application(const std::string & name,
                         int                 width,
                         int                 height) :
	name_(name)
{
        if (SDL_Init(SDL_INIT_EVERYTHING)) {
                throw std::runtime_error(std::string("Unable to initialize "
                                                     "application, ") +
                                                     SDL_GetError());
        }

        SDL_WM_SetCaption(name_.c_str(), 0);

        const SDL_VideoInfo* video;

        video = SDL_GetVideoInfo();
        if (video == NULL) {
                throw std::runtime_error(std::string("Unable to initialize "
                                                     "video, ") +
                                                     SDL_GetError());
        }

        SDL_GL_SetAttribute(SDL_GL_RED_SIZE,      5);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,    5);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,     5);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,   16);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,  1);

        if (SDL_SetVideoMode(width, height,
                             video->vfmt->BitsPerPixel,
                             SDL_OPENGL) == 0) {
                throw std::runtime_error(std::string("Unable to initialize "
                                                     "video mode, ") +
                                                     SDL_GetError());
        }
}

Application::~Application()
{ SDL_Quit(); }

void Application::sleep(size_t ms) const
{ DBG("Sleeping for %d ms", ms); SDL_Delay(ms); }
