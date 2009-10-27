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

#ifndef HAZE_GFX_BACKENDS_VIDEO
#define HAZE_GFX_BACKENDS_VIDEO

#include <string>
#include <boost/noncopyable.hpp>

#include "haze/core/exception.h++"

namespace HAZE {
        class Video : public boost::noncopyable {
        public:
                class CannotInitialize : public Exception { };

                Video(const std::string & name) throw(CannotInitialize);
                virtual ~Video();

                virtual unsigned int width()  = 0;
                virtual unsigned int height() = 0;
                virtual unsigned int bpp()    = 0;

                virtual void         refresh() = 0;

        private:
                std::string name_;
        };

}

#endif
