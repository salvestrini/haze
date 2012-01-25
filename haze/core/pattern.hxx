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

#ifndef HAZE_CORE_PATTERN
#define HAZE_CORE_PATTERN

#include <map>
#include <list>
#include <functional>
#include <algorithm>

namespace HAZE {

        class NonCopyable {
        public:
                NonCopyable()  { };
                ~NonCopyable() { };

        private:
                NonCopyable(const NonCopyable &);
                const NonCopyable & operator =(const NonCopyable &);
        };

        class ReferenceCounter {
        public:
                ReferenceCounter() : count_(0) { }
                void increment()               { count_++; }
                int  decrement()               { return --count_; }

        private:
                int count_;
        };

        template<typename T> class SmartPointer {
        public:
                SmartPointer() :
                        data_(0), reference_(0) {
                        reference_ = new ReferenceCounter();
                        reference_->increment();
                }

                SmartPointer(T * value) :
                        data_(value), reference_(0) {
                        reference_ = new ReferenceCounter();
                        reference_->increment();
                }

                SmartPointer(const SmartPointer<T> & sp) :
                        data_(sp.data_),
                        reference_(sp.reference) {
                        reference_->increment();
                }

                ~SmartPointer() {
                        if (reference_->decrement() == 0) {
                                delete data_;
                                delete reference_;
                        }
                }

                T & operator* ()
                { return *data_; }

                T * operator->()
                { return data_; }

                SmartPointer<T> & operator = (const SmartPointer<T> & sp) {
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
                T *                data_;
                ReferenceCounter * reference_;
        };

        template<typename T> class Singleton : public NonCopyable {
        public:
                Singleton() { }
                ~Singleton() {
                        if (instance_) {
                                delete instance_;
                        }
                }

                T * operator->() {
                        if (instance_ == 0) {
                                instance_ = new T();
                        }
                        return instance_;
                }

        private:
                static T * instance_;
        };

        template <typename T> T * Singleton<T>::instance_ = 0;

#if 0
        template<class Key, class Type> class Factory {
        public:
                typedef boost::shared_ptr<Type> Data;

                Data get(const Key & key);

        protected:

        private:
                std::map<Key, Data> objects_;
        };

        template<class Key, class Type>
        typename Factory<Key, Type>::Data
        Factory<Key, Type>::get(const Key & key)
        {
                typename std::map<Key, Data>::iterator i;

                i = objects_.find(key);

                if (i == objects_.end()) {
                        Data tmp(new Type(key));
                        objects_.insert(std::make_pair(key, tmp));
                }

                return (*i).second;
        }
#endif

        template<class K, class T> class Factory {
        public:
                typedef SmartPointer<T> Data;

                Data get(const K & key) {
                        typename std::map<K, Data>::iterator i;

                        i = objects_.find(key);
                        if (i == objects_.end()) {
                                Data tmp(new T(key));
                                objects_.insert(std::make_pair(key, tmp));
                        }

                        return (*i).second;
                }

        private:
                std::map<K, Data> objects_;
        };

        template<typename T> class Observer {
        public:
                virtual void update(const T & parameters) = 0;
        };

        template<class T> class Subject {
        public:
                void attach(Observer<T> * observer) {
                        observers_.push_back(observer);
                }

                void detach(Observer<T> * observer) {
                        observers_.remove(observer);
                }

                void update() const {
                        std::for_each(observers_,
                                      std::mem_fun(&Observer<T>::update));
                }

        private:
                std::list<Observer<T> *> observers_;
        };

}

#endif
