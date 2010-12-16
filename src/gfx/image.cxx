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
                surface_ = SDL_LoadBMP(file.c_str());
                if (!surface_) {
                        throw CannotLoad(file);
                }

                width(surface_->w);
                height(surface_->h);
        }

        Image::~Image()
        { SDL_FreeSurface(surface_); }

        bool Image::hasAlpha() const
        { return surface_->format->Amask ? true : false; }

        const void * Image::data() const
        { return surface_->pixels; }

        size_t Image::bpp() const
        { return surface_->format->BitsPerPixel; }

}
