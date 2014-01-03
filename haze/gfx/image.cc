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

#include "haze/config.hh"

#if HAVE_SDL2_IMAGE
#include "SDL_image.h"
#endif

#include "haze/core/log.hh"
#include "haze/utils/string.hh"
#include "haze/gfx/image.hh"

namespace haze {

        int image::count_ = 0;

        image::image(SDL_Surface * surface)
        {
                // DBG("Initializing image from surface");

                if (!surface) {
                        throw cannot_create();
                }

                surface_ = surface;

                resize(surface_->w, surface_->h);

                DBG("Image initialized from surface "
                    << width() << "x" << height());
        }

        image::image(const path & file)
        {
                // DBG("Initializing image from file " << quote(file.str()));

#if HAVE_SDL2_IMAGE
                if (count_ == 0) {
                        if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
                                throw cannot_load(file, "unknown format");
                        }
                        count_++;
                }

                surface_ = IMG_Load(file.str().c_str());
                if (!surface_) {
                        throw cannot_load(file, SDL_GetError());
                }

                resize(surface_->w, surface_->h);
#else
                throw cannot_load(file, "unsupported format");
#endif
                DBG("Image initialized from file "
                    << quote(file.str()) << " "
                    << width() << "x" << height());
        }

        image::~image()
        {
                SDL_FreeSurface(surface_);
                count_--;
                if (count_ == 0) {
#if HAVE_SDL2_IMAGE
                        IMG_Quit();
#endif
                }
        }

        image * image::clip(const rectangle<size_t, size_t> & rect) const
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
                        throw cannot_create();
                }

                SDL_Rect r;

                r.x = rect.x();
                r.y = rect.y();
                r.w = rect.width();
                r.h = rect.height();

                if (SDL_BlitSurface(surface_, &r, surface, NULL) != 0) {
                        throw cannot_create();
                }

                return new image(surface);
        }

        bool image::hasAlpha() const
        { return surface_->format->Amask ? true : false; }

        const void * image::data() const
        { return surface_->pixels; }

        size_t image::bpp() const
        { return surface_->format->BitsPerPixel; }

}
