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

#include "frame.h"

namespace HAZE {

        Frame::Frame(const struct defs & d) : defs_(d) {
                if (!(defs_.tl_.width() ==
                      defs_.l_.width()  ==
                      defs_.bl_.width())) {
                        // Error
                }
                if (!(defs_.tr_.width() ==
                      defs_.r_.width()  ==
                      defs_.br_.width())) {
                        // Error
                }
                if (!(defs_.tl_.height() ==
                      defs_.t_.height()  ==
                      defs_.tr_.height())) {
                        // Error
                }
                if (!(defs_.br_.height() ==
                      defs_.b_.height()  ==
                      defs_.bl_.height())) {
                        // Error
                }
        }

        void Frame::draw(const Rectangle & clipping)
        {
#if 0
                Point o(origin);
                int w = clipping.width();
                int h = clipping.height();

                int t_x;
                int t_y;

                // XXX FIXME: Pack top and bottom blits in a single for ...

                // Top
                defs_.tl_.draw(clipping, o);

                for (t_x = x + defs_.tl_.width();
                     t_x < this->x() + this->w() - defs_.tr_.width();
                     t_x++) {
                        defs_.t_.draw(t_x, y);
                }

                defs_.tr_.draw(clipping, t_x, y);

                // Middle
                defs_.l_.draw(clipping);
                defs_.r_.draw(clipping);

                // Bottom
                defs_.bl_.draw(clipping);
                
                for (t_x = x + defs_.bl_.width();
                     t_x < this->x() + this->w() - defs_.br_.width();
                     t_x++) {
                        defs_.t_.draw(t_x, y);
                }

                defs_.br_.draw(clipping);
#endif
        }

}
