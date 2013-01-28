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

#ifndef HAZE_GFX_FPS
#define HAZE_GFX_FPS

#include <cstdlib>

namespace HAZE {

#define FPS_UPPER_LIMIT 100
#define FPS_LOWER_LIMIT 1
#define FPS_DEFAULT     30

        class fps {
        public:
                fps(size_t fps = FPS_DEFAULT);
                ~fps();

                void   rate(size_t value);
                size_t rate(void);

                void   compensate();

        private:
                Uint32 framecount_;
                float  rateticks_;
                Uint32 lastticks_;
                Uint32 rate_;
        };

}

#endif
