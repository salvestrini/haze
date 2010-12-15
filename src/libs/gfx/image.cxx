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

#include "gfx/image.hxx"

namespace HAZE {

        Image::Image(const Path & file)
        {
#if 0
                SDL_Surface * temp = SDL_LoadBMP(file.c_str());
                surface_ = SDL_ConvertSurface(temp,
                                              video.surface().format(),
                                              SDL_SWSURFACE);
                SDL_FreeSurface(temp);
#endif
                surface_ = SDL_LoadBMP(file.c_str());

                width(surface_->w);
                height(surface_->h);
        }

        Image::~Image()
        {
                SDL_FreeSurface(surface_);
        }

        void Image::draw(const Point &     origin,
                         const Rectangle & clipping)
        {
        }

        void Image::draw(const Point & origin)
        {
        }

}
