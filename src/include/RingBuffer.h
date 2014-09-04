//
//  RingBuffer.h
//  Waveform_Generation
//
//  Created by Alexander Zywicki on 7/24/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef Waveform_Generation_RingBuffer_h
#define Waveform_Generation_RingBuffer_h

#ifdef DEBUG
#include <iostream>
#endif

#include <atomic>
#include <math.h>
#include "Buffer.h"

namespace Signal {
    
    
    
    class RingBuffer:public Buffer {
    protected:
        std::atomic<size_t> _write;
        std::atomic<size_t> _read;
        size_t _count;
        size_t MASK;
        inline size_t next(size_t current);
        inline size_t make_pow_2(size_t number);
    public:
        RingBuffer();
        RingBuffer(const size_t size);
        RingBuffer(RingBuffer& buffer);
        RingBuffer& operator=(RingBuffer& buffer);
        virtual ~RingBuffer();
        inline bool Write(const Signal::Sample& elem);
        inline bool Read(Signal::Sample& elem);
        inline size_t const& Count()const;
        inline bool Full()const;
        inline bool Empty()const;
        inline void Flush();
#ifdef DEBUG
        friend std::ostream& operator<<(std::ostream& os,RingBuffer const& buffer);
#endif
    };
    inline bool RingBuffer::Full()const{
        return _count==this->_size;
    }
    inline bool RingBuffer::Empty()const{
        return _count==0;
    }
    inline void RingBuffer::Flush(){
        _write.store(0,std::memory_order_relaxed);
        _read.store(0,std::memory_order_relaxed);
        _count=0;
    }
    inline bool RingBuffer::Write(const Signal::Sample& elem){
        if (!Full()) {
            size_t write = _write.load(std::memory_order_acquire);
            _write.store(next(write),std::memory_order_release);
            this->_buffer[write] = elem;
            ++_count;
            return true;
        }else return false;
    }
    inline bool RingBuffer::Read(Signal::Sample& elem){
        if (!Empty()) {
            size_t read = _read.load(std::memory_order_acquire);
            _read.store(next(read),std::memory_order_release);
            elem = this->_buffer[read];
            --_count;
            return true;
        }else return false;
    }
    inline size_t const& RingBuffer::Count()const{
        return _count;
    }
    
    //note: RingBuffer implementation will force a power of 2 size to allow use of bitwise increment.
    inline size_t RingBuffer::next(size_t current){return (current+1) & MASK;}
    inline size_t RingBuffer::make_pow_2(size_t number){
        return pow(2, ceil(log(number)/log(2)));
    }
}
#endif
