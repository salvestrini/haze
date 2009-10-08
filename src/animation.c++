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

#include "animation.h"

namespace HAZE {

        Animation::Animation(const std::vector<const std::string> & frames)
        {
#if 0
                std::vector<const std::string>::const_iterator iter;

                for (iter = frames.begin(); iter != frames.end(); iter++) {
                        frames_.push_back(Image((*iter)));
                }
#endif
        }

        void Animation::step(int count)
        {
#if 0
                if (count == 0) return;

                std::vector<Image>::size_type howmany = abs(count);
                std::vector<Image>::iterator  iter;

                if (count < 0) {
                        for (; howmany != 0; howmany--) {
                                iter--;
                                if (iter == frames_.begin()) {
                                        iter = frames_.last();
                                }
                        }
                } else {
                        for (; howmany != 0; howmany--) {
                                iter++;
                                if (iter == frames_.end()) {
                                        iter = frames_.begin();
                                }
                        }
                }
#endif
        }

}
