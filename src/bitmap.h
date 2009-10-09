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

#ifndef HAZE_BITMAP_H
#define HAZE_BITMAP_H

#include <string>
#include <utility>
#include <boost/shared_ptr.hpp>

#include "factory.h"
#include "buffer.h"
#include "size.h"

namespace HAZE {

        class Bitmap : public Size {
        public:
                Bitmap(const std::string & filename) :
                        Size(0, 0), buffer_(0) {
                        // XXX FIXME: Add code here
                }

        protected:

        private:
                Buffer *     buffer_;
        };

        class BitmapFactory : public Factory {
        public:
                boost::shared_ptr<Bitmap> get(const std::string & filename);

        protected:

        private:
                std::map<std::string,
                         boost::shared_ptr<Bitmap> > objects_;
        };

        extern BitmapFactory bitmapFactory;
}

#endif // HAZE_BITMAP_H
