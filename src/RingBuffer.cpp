//
//  RingBuffer.cpp
//  Oscillators
//
//  Created by Alexander Zywicki on 8/10/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "RingBuffer.h"




Signal::RingBuffer::RingBuffer():Buffer(0),_read(0),_write(0),_count(0),MASK(0){}

Signal::RingBuffer::RingBuffer(const size_t size):Buffer(make_pow_2(size)),_read(0),_write(0),_count(0){
    MASK = this->_size-1;
}

Signal::RingBuffer::RingBuffer(RingBuffer& buffer):Buffer(buffer){
    _write.store(buffer._write.load(std::memory_order_acquire));
    _read.store(buffer._read.load(std::memory_order_acquire));
    _count = buffer._count;
    MASK = buffer._size-1;
}

Signal::RingBuffer& Signal::RingBuffer::operator=(RingBuffer& buffer){
    Buffer::operator=(buffer);
    _write.store(buffer._write.load(std::memory_order_acquire));
    _read.store(buffer._read.load(std::memory_order_acquire));
    _count = buffer._count;
    MASK = buffer._size-1;
    return *this;
}
Signal::RingBuffer::~RingBuffer(){Flush();}





#ifdef DEBUG
std::ostream& Signal::operator<<(std::ostream& os,Signal::RingBuffer const& buffer){
    if (!buffer.Empty()) {
        size_t index= buffer._read;
        size_t count=buffer.Count();
        size_t size = buffer.Size();
        for (int i=0; i<count; ++i) {
            os<<index<<": "<<buffer._buffer[index]<<std::endl;
            index = ((index+1)%size);
        }
    }return os;
}

#endif
