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

#ifndef HAZE_GFX_GEOMETRY
#define HAZE_GFX_GEOMETRY

#include <cstdlib>
#include <cmath>
#include <utility>

#include "haze/gfx/math.hh"

namespace HAZE {

        template<typename TYPE = size_t> class bounding_box {
        public:
                bounding_box(TYPE width  = 0,
                             TYPE height = 0) :
                        width_(width),
                        height_(height)
                { }

                virtual ~bounding_box()
                { }

                typedef TYPE size_type;

                TYPE width() const
                { return width_; }

                TYPE height() const
                { return height_; }

                void width(TYPE value)
                { width_ = value; }

                void height(TYPE value)
                { height_ = value; }

                void resize(TYPE width,
                            TYPE height) {
                        width_  = width;
                        height_ = height;
                }

                void resize(const bounding_box & bbox) {
                        width_  = bbox.width_;
                        height_ = bbox.height_;
                }

                void resize(float factor) {
                        width_  = static_cast<TYPE>(std::abs(float(width_)  *
                                                             factor));
                        height_ = static_cast<TYPE>(std::abs(float(height_) *
                                                             factor));
                }

                void clear() {
                        width_ = height_ = 0;
                }

                HAZE::bounding_box<TYPE> size() const
                { return *this; }

        private:
                TYPE width_;
                TYPE height_;
        };

        template<typename TYPE>
        bounding_box<TYPE> max(const bounding_box<TYPE> & a,
                               const bounding_box<TYPE> & b)
        {
                // XXX FIXME: What a shame ...
                return bounding_box<TYPE>(a.width()  > b.width()  ?
                                          a.width()  : b.width()  ,
                                          a.height() > b.height() ?
                                          a.height() : b.height());
        }

        template<typename PTYPE = int,
                 typename STYPE = size_t> class rectangle :
                public MATH::point<PTYPE>,
                public bounding_box<STYPE> {
        public:
                rectangle() { }

                rectangle(PTYPE x, PTYPE y, STYPE w, STYPE h) :
                        MATH::point<PTYPE>(x, y),
                        bounding_box<STYPE>(w, h)
                { }

                rectangle(const MATH::point<PTYPE> &  origin,
                          const bounding_box<STYPE> & bbox) :
                        MATH::point<PTYPE>(origin),
                        bounding_box<STYPE>(bbox)
                { }

                virtual ~rectangle()
                { }
        };

}

#endif
