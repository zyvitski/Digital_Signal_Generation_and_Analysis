//
//  Queue.h
//  Waveform
//
//  Created by Alexander Zywicki on 8/23/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef Waveform_Queue_h
#define Waveform_Queue_h

#include <assert.h>
#include <atomic>
#include <math.h>
#ifdef DEBUG
#include <iostream>
#endif

namespace Backend {
    
    
    template <class element>
    class array {
    public:
        typedef element* pointer;
        typedef element& reference;
        
        array():_size(0),_array(nullptr){}
        array(unsigned long size):_size(size),_array(new element[size]){}
        array(array<element> const& other){
            _array = new element[other.Size()];
            _size = other.Size();
            *this = other;
        }
        array<element>& operator=(array<element> const& other){
            if (_size!=other._size) {
                if (_array!=nullptr) {
                    delete [] _array;
                }
                _size = other._size;
                _array = new element[_size];
            }
            for (int i=0; i<_size; ++i) {
                _array[i] = other._array[i];
            }
            return *this;
        }
        virtual ~array(){
            if (_array!=nullptr) {
                delete [] _array;
            }
            _size=0;
        }
        element& operator[](unsigned long const& index){
            assert(index<_size);
            return _array[index];
        }
        unsigned long const& Size()const{
            return _size;
        }
    protected:
        element* _array;
        unsigned long _size;
    };
    
    
    template <class element>
    class Queue:public array<element> {
    public:
        Queue():array<element>(0),_read(0),_write(0),_count(0),_MASK(0){}
        Queue(unsigned long size):array<element>(make_pow_2(size)),_read(0),_write(0),_count(0){
            _MASK = this->_size-1;
        }
        Queue(Queue<element> const& other):array<element>(other){
            _write.store(other._write.load(std::memory_order_acquire));
            _read.store(other._read.load(std::memory_order_acquire));
            _count = other._count;
            _MASK = other._size-1;
        }
        Queue<element>& operator=(Queue<element> const& other){
            array<element>::operator=(other);
            _write.store(other._write.load(std::memory_order_acquire));
            _read.store(other._read.load(std::memory_order_acquire));
            _count = other._count;
            _MASK = other._size-1;
            return *this;
        }
        virtual ~Queue(){
            Flush();
        }
        bool Write(element const& value){
            if (!Full()) {
                size_t write = _write.load(std::memory_order_acquire);
                _write.store(next(write),std::memory_order_release);
                this->_array[write] = value;
                ++_count;
                return true;
            }else return false;
        }
        bool Read(element& place){
            if (!Empty()) {
                size_t read = _read.load(std::memory_order_acquire);
                _read.store(next(read),std::memory_order_release);
                place = this->_array[read];
                --_count;
                return true;
            }else return false;
        }
        unsigned long const& Count()const{
            return _count;
        }
        bool Full()const{
            return _count==this->_size;
            
        }
        bool Empty()const{
            return _count==0;
        }
        void Flush(){
            _write.store(0,std::memory_order_relaxed);
            _read.store(0,std::memory_order_relaxed);
            _count=0;
        }
        
#ifdef DEBUG
        friend std::ostream& operator<<(std::ostream& os, Queue<element> const& queue){
            return os;
        }
#endif
    protected:
        std::atomic<unsigned long> _write;
        std::atomic<unsigned long> _read;
        unsigned long _count;
        unsigned long _MASK;
        inline unsigned long next(unsigned long value){
            return (value+1) & _MASK;
        }
        inline unsigned long make_pow_2(unsigned long value){
            return pow(2, ceil(log(value)/log(2)));
        }
    };
}


#endif
