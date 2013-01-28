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

#ifndef HAZE_CORE_PATTERN
#define HAZE_CORE_PATTERN

#include <map>
#include <list>
#include <functional>
#include <algorithm>

namespace HAZE {

        class non_copyable {
        public:
                non_copyable()  { };
                ~non_copyable() { };

        private:
                non_copyable(const non_copyable &);
                const non_copyable & operator =(const non_copyable &);
        };

        class reference_counter {
        public:
                reference_counter() : count_(0) { }
                void increment()                { count_++; }
                int  decrement()                { return --count_; }

        private:
                int count_;
        };

        template<typename TYPE> class smart_pointer {
        public:
                smart_pointer() :
                        data_(0), reference_(0) {
                        reference_ = new reference_counter();
                        reference_->increment();
                }

                smart_pointer(TYPE * value) :
                        data_(value), reference_(0) {
                        reference_ = new reference_counter();
                        reference_->increment();
                }

                smart_pointer(const smart_pointer<TYPE> & sp) :
                        data_(sp.data_),
                        reference_(sp.reference) {
                        reference_->increment();
                }

                ~smart_pointer() {
                        if (reference_->decrement() == 0) {
                                delete data_;
                                delete reference_;
                        }
                }

                TYPE & operator* ()
                { return *data_; }

                TYPE * operator->()
                { return data_; }

                smart_pointer<TYPE> &
                operator = (const smart_pointer<TYPE> & sp) {
                        if (this != &sp) {
                                if (reference_->decrement() == 0) {
                                        delete data_;
                                        delete reference_;
                                }

                                data_      = sp.data_;
                                reference_ = sp.reference_;
                                reference_->increment();
                        }

                        return *this;
                }

        private:
                TYPE *              data_;
                reference_counter * reference_;
        };

        template<typename TYPE> class singleton : public non_copyable {
        public:
                singleton() { }
                ~singleton() {
                        if (instance_)
                                delete instance_;
                }

                TYPE * operator->() {
                        if (instance_ == 0) {
                                instance_ = new TYPE();
                        }
                        return instance_;
                }

        private:
                static TYPE * instance_;
        };

        template<typename TYPE> TYPE * singleton<TYPE>::instance_ = 0;

        template<typename KEY, typename TYPE> class factory {
        public:
                typedef smart_pointer<TYPE> data;

                data get(const KEY & key) {
                        typename std::map<KEY, data>::iterator i;

                        i = objects_.find(key);
                        if (i == objects_.end()) {
                                data tmp(new TYPE(key));
                                objects_.insert(std::make_pair(key, tmp));
                        }

                        return (*i).second;
                }

        private:
                std::map<KEY, data> objects_;
        };

        template<typename TYPE> class observer {
        public:
                virtual void update(const TYPE & parameters) = 0;
        };

        template<typename TYPE> class Subject {
        public:
                void attach(observer<TYPE> * observer) {
                        observers_.push_back(observer);
                }

                void detach(observer<TYPE> * observer) {
                        observers_.remove(observer);
                }

                void update() const {
                        std::for_each(observers_,
                                      std::mem_fun(&observer<TYPE>::update));
                }

        private:
                std::list<observer<TYPE> *> observers_;
        };

}

#endif
