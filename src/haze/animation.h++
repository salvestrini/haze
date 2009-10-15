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

#ifndef HAZE_ANIMATION_H
#define HAZE_ANIMATION_H

#include <vector>
#include <string>

#include "haze/image.h++"

namespace HAZE {

        class Animation {
        public:
                Animation(const std::vector<const std::string> & frames);

                void step(int count);
                void stepForward()  { step(1);  }
                void stepBackward() { step(-1); }

        protected:

        private:
#if 0
                std::vector<Image>           frames_;
                std::vector<Image>::iterator current_;
#endif
        };

}

#endif // HAZE_ANIMATION_H