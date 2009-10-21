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

#include <string>

#include "haze/point.h++"
#include "haze/rectangle.h++"
#include "haze/size.h++"

namespace HAZE {

        class Object {
        public:
                Object(const std::string & name);
                virtual ~Object();

                virtual void draw(const Rectangle & clipping) = 0;
                virtual void move(const Point & where)        = 0;
                virtual void resize(const Size & size)        = 0;

                void                name(const std::string & name);
                const std::string & name(void);

                void                show();
                void                hide();
                virtual bool        visible();

                virtual operator    std::string();

        protected:
                bool        visible_;

        private:
                std::string name_;
        };

}

#endif // HAZE_OBJECT_H
