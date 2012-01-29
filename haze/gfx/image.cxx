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

#include <SDL/SDL_image.h>

#include "haze/gfx/image.hxx"

namespace HAZE {

        int Image::count_ = 0;

        Image::Image(SDL_Surface * surface)
        {
                if (!surface) {
                        throw CannotCreate();
                }

                surface_ = surface;

                width(surface_->w);
                height(surface_->h);
        }

        Image::Image(const Path & file)
        {
                if (count_ == 0) {
                        if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
                                throw CannotLoad(file, "unknown format");
                        }

                        count_++;
                }

                surface_ = IMG_Load(file.c_str());
                if (!surface_) {
                        throw CannotLoad(file, SDL_GetError());
                }

                width(surface_->w);
                height(surface_->h);
        }

        Image::~Image()
        {
                SDL_FreeSurface(surface_);
                count_--;
                if (count_ == 0) {
                        IMG_Quit();
                }
        }

        Image * Image::clip(const Rectangle<size_t, size_t> & rect) const
        {
                SDL_Surface * surface;
                Uint32        rmask, gmask, bmask, amask;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
                rmask = 0xff000000;
                gmask = 0x00ff0000;
                bmask = 0x0000ff00;
                amask = 0x000000ff;
#else
                rmask = 0x000000ff;
                gmask = 0x0000ff00;
                bmask = 0x00ff0000;
                amask = 0xff000000;
#endif

                surface = SDL_CreateRGBSurface(SDL_SWSURFACE,
                                               rect.width(), rect.height(),
                                               32,
                                               rmask, gmask, bmask, amask);
                if (surface == NULL) {
                        throw CannotCreate();
                }

                SDL_Rect r;

                r.x = rect.x();
                r.y = rect.y();
                r.w = rect.width();
                r.h = rect.height();

                if (SDL_BlitSurface(surface_, &r, surface, NULL) != 0) {
                        throw CannotCreate();
                }

                return new Image(surface);
        }

        bool Image::hasAlpha() const
        { return surface_->format->Amask ? true : false; }

        const void * Image::data() const
        { return surface_->pixels; }

        size_t Image::bpp() const
        { return surface_->format->BitsPerPixel; }

}
