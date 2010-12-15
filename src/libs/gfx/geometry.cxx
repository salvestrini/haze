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

        Size::Size(size_t width,
                   size_t height) :
                width_(width),
                height_(height)
        { }

        Size::~Size()
        { }

        size_t Size::width() const
        { return width_; }

        size_t Size::height() const
        { return height_; }

        void Size::width(size_t width)
        { width_ = width; }

        void Size::height(size_t height)
        { height_ = height; }

        void Size::resize(const Size & size)
        {
                width_  = size.width_;
                height_ = size.height_;
        }

        void Size::resize(float factor)
        {
                width_  = static_cast<size_t>(std::abs(float(width_)  *
                                                       factor));
                height_ = static_cast<size_t>(std::abs(float(height_) *
                                                       factor));
        }

        void Size::resize(size_t width,
                          size_t height)
        {
                width_  = width;
                height_ = height;
        }

        Point::Point(int x, int y) :
                x_(x), y_(y)
        { }

        Point::~Point()
        { }

        int Point::x() const
        { return x_; }

        int Point::y() const
        { return y_; }

        void Point::x(int v)
        { x_ = v; }

        void Point::y(int v)
        { y_ = v; }

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

        size_t Rectangle::width()  const
        { return size_.width(); }

        size_t Rectangle::height() const
        { return size_.height(); }

        void Rectangle::width(size_t v)
        { size_.width(v); }

        void Rectangle::height(size_t v)
        { size_.height(v); }

        const Size & Rectangle::size() const
        { return size_; }

        void Rectangle::resize(const Size & s)
        { size_ = s; }

}
