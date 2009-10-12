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

#ifndef HAZE_IMAGE_H
#define HAZE_IMAGE_H

#include <string>
#include <boost/shared_ptr.hpp>

#include "bitmap.h++"
#include "point.h++"
#include "rectangle.h++"
#include "size.h++"

namespace HAZE {

        class Image : public Size {
        public:
                Image()          { }
                virtual ~Image() { }

                Image(const std::string & filename) {
                        bitmap_ = bitmapFactory.get(filename);
                }

                Image(const std::string & filename,
                      const Size &        size) {
                        bitmap_ = bitmapFactory.get(filename);
                        bitmap_->resize(size);
                }

                void                 load(const std::string & filename) {
                        bitmap_ = bitmapFactory.get(filename);
                }

                virtual void         draw(const Point &     origin,
                                          const Rectangle & clipping);
                virtual void         draw(const Point &     origin);

                virtual unsigned int width() const {
                        return bitmap_ ? bitmap_->width() : 0;
                }
                virtual unsigned int height() const {
                        return bitmap_ ? bitmap_->height() : 0;
                }

        protected:
                DECLARE_COPY_CTORS(Image);

                boost::shared_ptr<Bitmap> bitmap_;

        private:
        };

}

#endif // HAZE_IMAGE_H
