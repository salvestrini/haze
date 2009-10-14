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

#include "haze/object.h++"

namespace HAZE {

        Object::Object(const std::string & name) :
                visible_(false),
                name_(name)
        { }

        Object::~Object()
        { }

        void Object::name(const std::string & name)
        { name_ = name; }

        const std::string & Object::name(void)
        { return name_; }

        void Object::show()
        { visible_ = true; }

        void Object::hide()
        { visible_ = false; }

        bool Object::visible()
        { return visible_; }

}
