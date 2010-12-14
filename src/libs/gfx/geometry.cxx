//
// Copyright (C) 2010 Francesco Salvestrini
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

#include <cmath>

#include "gfx/geometry.hxx"

namespace HAZE {

        Size::Size(unsigned int width,
                   unsigned int height) :
                width_(width),
                height_(height)
        { }

        Size::~Size()
        { }

        unsigned int Size::width() const
        { return width_; }

        unsigned int Size::height() const
        { return height_; }

        void Size::width(unsigned int width)
        { width_  = width; }

        void Size::height(unsigned int height)
        { height_ = height; }

        void Size::resize(const Size & size)
        {
                width_  = size.width_;
                height_ = size.height_;
        }

        void Size::resize(float factor)
        {
                width_  = int(std::abs(float(width_)  * factor));
                height_ = int(std::abs(float(height_) * factor));
        }

        void Size::resize(unsigned int width,
                          unsigned int height)
        {
                width_  = width;
                height_ = height;
        }

        Point::Point(int x, int y) :
                p_(x, y)
        { }

        Point::~Point()
        { }

        int Point::x() const
        { return p_.first; }

        int Point::y() const
        { return p_.second; }

        void Point::x(int v)
        { p_.first = v; }

        void Point::y(int v)
        { p_.second = v; }

        Rectangle::Rectangle() :
                size_(0, 0),
                origin_(0, 0)
        { }

        Rectangle::Rectangle(const Point & origin,
                             const Size &  size) :
                size_(size),
                origin_(origin)
        { }

        Rectangle::Rectangle(const Point & p1,
                             const Point & p2)
        {
                Point p1_, p2_;

                if (p1.x() > p2.x()) {
                        p1_.x(p2.x());
                        p2_.x(p1.x());
                } else {
                        p1_.x(p1.x());
                        p2_.x(p2.x());
                }
                if (p1.y() > p2.y()) {
                        p1_.y(p2.y());
                        p2_.y(p1.y());
                } else {
                        p1_.y(p1.y());
                        p2_.y(p2.y());
                }

                origin_ = p1;
                size_   = Size(p2_.x() - p1_.x(),
                               p2_.y() - p1_.x());
        }

        Rectangle::~Rectangle()
        { }

        void Rectangle::move(const Point & where)
        { origin_ = where; }


        int Rectangle::x() const
        { return origin_.x(); }

        int Rectangle::y() const
        { return origin_.y(); }

        void Rectangle::x(int v)
        { origin_.x(v); }

        void Rectangle::y(int v)
        { origin_.y(v); }

        unsigned int Rectangle::width()  const
        { return size_.width(); }

        unsigned int Rectangle::height() const
        { return size_.height(); }

        void Rectangle::width(unsigned int v)
        { size_.width(v); }

        void Rectangle::height(unsigned int v)
        { size_.height(v); }

        const Size & Rectangle::size() const
        { return size_; }

        void Rectangle::resize(const Size & s)
        { size_ = s; }

}
