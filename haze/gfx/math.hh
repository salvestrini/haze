//
// Copyright (C) 2012, 2013, 2014 Francesco Salvestrini
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

#ifndef HAZE_GFX_MATH
#define HAZE_GFX_MATH

#include <cmath>

namespace haze {
        namespace math {

                //
                // vector2
                //

                template <typename TYPE> class vector2 {
                public :
                        vector2();
                        vector2(TYPE X, TYPE Y);
                        
                        template <typename U>
                        explicit vector2(const vector2<U>& vector);
                        
                        typedef TYPE size_type;

                        TYPE x;
                        TYPE y;
                };
                
                template <typename TYPE>
                inline vector2<TYPE>::vector2() :
                        x(0), y(0)
                { }

                template <typename TYPE>
                inline vector2<TYPE>::vector2(TYPE X, TYPE Y) :
                        x(X), y(Y)
                { }

                template <typename TYPE>
                template <typename U>
                inline vector2<TYPE>::vector2(const vector2<U>& vector) :
                        x(static_cast<TYPE>(vector.x)),
                        y(static_cast<TYPE>(vector.y))
                { }

                template <typename TYPE>
                inline vector2<TYPE> operator -(const vector2<TYPE>& rhs)
                { return vector2<TYPE>(-rhs.x, -rhs.y); }

                template <typename TYPE>
                inline vector2<TYPE>& operator +=(vector2<TYPE>&       lhs,
                                                  const vector2<TYPE>& rhs)
                {
                        lhs.x += rhs.x;
                        lhs.y += rhs.y;

                        return lhs;
                }

                template <typename TYPE>
                inline vector2<TYPE>& operator -=(vector2<TYPE>&       lhs,
                                                  const vector2<TYPE>& rhs)
                {
                        lhs.x -= rhs.x;
                        lhs.y -= rhs.y;

                        return lhs;
                }

                template <typename TYPE>
                inline vector2<TYPE> operator +(const vector2<TYPE>& lhs,
                                                const vector2<TYPE>& rhs)
                { return vector2<TYPE>(lhs.x + rhs.x, lhs.y + rhs.y); }

                template <typename TYPE>
                inline vector2<TYPE> operator -(const vector2<TYPE>& lhs,
                                                const vector2<TYPE>& rhs)
                { return vector2<TYPE>(lhs.x - rhs.x, lhs.y - rhs.y); }

                template <typename TYPE>
                inline vector2<TYPE> operator *(const vector2<TYPE>& lhs,
                                                TYPE                 rhs)
                { return vector2<TYPE>(lhs.x * rhs, lhs.y * rhs); }

                template <typename TYPE>
                inline vector2<TYPE> operator *(TYPE                 lhs,
                                                const vector2<TYPE>& rhs)
                { return vector2<TYPE>(rhs.x * lhs, rhs.y * lhs); }

                template <typename TYPE>
                inline vector2<TYPE>& operator *=(vector2<TYPE>& lhs,
                                                  TYPE           rhs)
                {
                        lhs.x *= rhs;
                        lhs.y *= rhs;

                        return lhs;
                }

                template <typename TYPE>
                inline vector2<TYPE> operator /(const vector2<TYPE>& lhs,
                                                TYPE                 rhs)
                { return vector2<TYPE>(lhs.x / rhs, lhs.y / rhs); }

                template <typename TYPE>
                inline vector2<TYPE>& operator /=(vector2<TYPE>& lhs,
                                                  TYPE           rhs)
                {
                        lhs.x /= rhs;
                        lhs.y /= rhs;

                        return lhs;
                }

                template <typename TYPE>
                inline bool operator ==(const vector2<TYPE>& lhs,
                                        const vector2<TYPE>& rhs)
                { return (lhs.x == rhs.x) && (lhs.y == rhs.y); }

                template <typename TYPE>
                inline bool operator !=(const vector2<TYPE>& lhs,
                                        const vector2<TYPE>& rhs)
                { return (lhs.x != rhs.x) || (lhs.y != rhs.y); }

                typedef vector2<int>          vector2i;
                typedef vector2<unsigned int> vector2u;
                typedef vector2<float>        vector2f;

                //
                // vector3
                //

                template <typename TYPE> class vector3 {
                public :
                        vector3();
                        vector3(TYPE X, TYPE Y, TYPE Z);
                        
                        template <typename U>
                        explicit vector3(const vector3<U>& vector);
                        
                        typedef TYPE size_type;

                        TYPE x;
                        TYPE y;
                        TYPE z;
                };

                template <typename TYPE>
                inline vector3<TYPE>::vector3() :
                        x(0), y(0), z(0)
                { }

                template <typename TYPE>
                inline vector3<TYPE>::vector3(TYPE X, TYPE Y, TYPE Z) :
                        x(X), y(Y), z(Z)
                { }

                template <typename TYPE>
                template <typename U>
                inline vector3<TYPE>::vector3(const vector3<U>& vector) :
                        x(static_cast<TYPE>(vector.x)),
                        y(static_cast<TYPE>(vector.y)),
                        z(static_cast<TYPE>(vector.z))
                { }

                template <typename TYPE>
                inline vector3<TYPE> operator -(const vector3<TYPE>& lhs)
                { return vector3<TYPE>(-lhs.x, -lhs.y, -lhs.z); }

                template <typename TYPE>
                inline vector3<TYPE>& operator +=(vector3<TYPE>&       lhs,
                                                  const vector3<TYPE>& rhs)
                {
                        lhs.x += rhs.x;
                        lhs.y += rhs.y;
                        lhs.z += rhs.z;

                        return lhs;
                }

                template <typename TYPE>
                inline vector3<TYPE>& operator -=(vector3<TYPE>&       lhs,
                                                  const vector3<TYPE>& rhs)
                {
                        lhs.x -= rhs.x;
                        lhs.y -= rhs.y;
                        lhs.z -= rhs.z;

                        return lhs;
                }

                template <typename TYPE>
                inline vector3<TYPE> operator +(const vector3<TYPE>& lhs,
                                                const vector3<TYPE>& rhs)
                {
                        return vector3<TYPE>(lhs.x + rhs.x,
                                             lhs.y + rhs.y,
                                             lhs.z + rhs.z);
                }

                template <typename TYPE>
                inline vector3<TYPE> operator -(const vector3<TYPE>& lhs,
                                                const vector3<TYPE>& rhs)
                {
                        return vector3<TYPE>(lhs.x - rhs.x,
                                             lhs.y - rhs.y,
                                             lhs.z - rhs.z);
                }

                template <typename TYPE>
                inline vector3<TYPE> operator *(const vector3<TYPE>& lhs,
                                                TYPE                 rhs)
                {
                        return vector3<TYPE>(lhs.x * rhs,
                                             lhs.y * rhs,
                                             lhs.z * rhs);
                }

                template <typename TYPE>
                inline vector3<TYPE> operator *(TYPE                 lhs,
                                                const vector3<TYPE>& rhs)
                {
                        return vector3<TYPE>(rhs.x * lhs,
                                             rhs.y * lhs,
                                             rhs.z * lhs);
                }

                template <typename TYPE>
                inline vector3<TYPE>& operator *=(vector3<TYPE>& lhs,
                                                  TYPE           rhs)
                {
                        lhs.x *= rhs;
                        lhs.y *= rhs;
                        lhs.z *= rhs;

                        return lhs;
                }

                template <typename TYPE>
                inline vector3<TYPE> operator /(const vector3<TYPE>& lhs,
                                                TYPE                 rhs)
                {
                        return vector3<TYPE>(lhs.x / rhs,
                                             lhs.y / rhs,
                                             lhs.z / rhs);
                }

                template <typename TYPE>
                inline vector3<TYPE>& operator /=(vector3<TYPE>& lhs,
                                                  TYPE           rhs)
                {
                        lhs.x /= rhs;
                        lhs.y /= rhs;
                        lhs.z /= rhs;

                        return lhs;
                }

                template <typename TYPE>
                inline bool operator ==(const vector3<TYPE>& lhs,
                                        const vector3<TYPE>& rhs)
                {
                        return ((lhs.x == rhs.x) &&
                                (lhs.y == rhs.y) &&
                                (lhs.z == rhs.z));
                }

                template <typename TYPE>
                inline bool operator !=(const vector3<TYPE>& lhs,
                                        const vector3<TYPE>& rhs)
                {
                        return ((lhs.x != rhs.x) ||
                                (lhs.y != rhs.y) ||
                                (lhs.z != rhs.z));
                }

                typedef vector3<int>   vector3i;
                typedef vector3<float> vector3f;

                //
                // point
                //

                template<typename TYPE> TYPE radians2angle(TYPE radians)
                { return radians * 180 / M_PI; }

                template<typename TYPE = float> class point {
                public:
                        point(const point & p) :
                                x_(p.x()),
                                y_(p.y()),
                                z_(p.z())
                        { }

                        point(TYPE x = 0,
                              TYPE y = 0,
                              TYPE z = 0) :
                                x_(x),
                                y_(y),
                                z_(z)
                        { }

                        virtual ~point()
                        { }

                        typedef TYPE size_type;

                        TYPE  x() const { return x_; }
                        TYPE  y() const { return y_; }
                        TYPE  z() const { return z_; }

                        void  x(TYPE v) { x_ = v; }
                        void  y(TYPE v) { y_ = v; }
                        void  z(TYPE v) { z_ = v; }

                        void  move(TYPE x,
                                   TYPE y,
                                   TYPE z) {
                                x_ = x;
                                y_ = y;
                                z_ = z;
                        }

                private:
                        TYPE x_;
                        TYPE y_;
                        TYPE z_;
                };

                //
                // rectangle
                //

                template<typename TYPE = int> class rectangle {
                public:
                        rectangle(TYPE width,
                                  TYPE height) :
                                from_(0, 0),
                                to_(width, height)
                        { }

                        rectangle(const point<TYPE> & from,
                                  const point<TYPE> & to) :
                                from_(from),
                                to_(to)
                        { }

                        virtual ~rectangle()
                        { }

                        typedef TYPE size_type;

                        virtual TYPE width() const
                        { return std::abs(to_.x() - from_.x()); }

                        virtual void width(const TYPE & v)
                        {
                                TYPE c(from_.x() + (to_.x() - from_.x()) / 2);

                                from_.x(c - v / 2);
                                to_.x(c + v / 2);
                        }

                        virtual TYPE height() const
                        { return std::abs(to_.y() - from_.y()); }

                        // XXX FIXME: Do resizing around the center
                        virtual void height(const TYPE & v)
                        {
                                TYPE c(from_.y() + (to_.y() - from_.y()) / 2);

                                from_.y(c - v / 2);
                                to_.y(c + v / 2);
                        }

                        virtual void resize(const TYPE & w,
                                            const TYPE & h) {
                                width(w);
                                height(h);
                        }

                private:
                        point<TYPE> from_;
                        point<TYPE> to_;
                };

        }
}

#endif
