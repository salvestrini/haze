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

#ifndef HAZE_OBJECT_H
#define HAZE_OBJECT_H

#include "point.h"
#include "rectangle.h"

namespace HAZE {

        class Object {
        public:
                Object() : visible_(false), changed_(false) { }

                virtual void draw(const Rectangle & clipping) = 0;
                virtual void move(const Point & where)        = 0;
                virtual void resize(const Rectangle & box)    = 0;

                virtual void visible(bool v) { visible_ = v;    }
                virtual bool visible()       { return visible_; }

                virtual void changed(bool v) { changed_ = v;    }
                virtual bool changed()       { return changed_; }

        protected:
                bool visible_;
                bool changed_;

        private:
        };

}

#endif // HAZE_OBJECT_H
