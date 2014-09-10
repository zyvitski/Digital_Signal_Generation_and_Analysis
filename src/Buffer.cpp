//
//  Buffer.cpp
//  Processing
//
//  Created by Alexander Zywicki on 8/14/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "Buffer.h"



DSG::Buffer::Buffer():_size(0),_buffer(nullptr){}
DSG::Buffer::Buffer(size_t size):_size(size),_buffer(new  Sample[size]){}
DSG::Buffer::Buffer(Buffer const& other) {
    _buffer = new  Sample[_size];
    _size = other._size;
    *this = other;
}
DSG::Buffer& DSG::Buffer::operator=(Buffer const& other){
    if (_size!=other._size) {
        if (_buffer!=nullptr) {
            delete [] _buffer;
        }
        _size = other._size;
        _buffer = new  Sample[_size];
    }
    for (int i=0; i<_size; ++i) {
        _buffer[i] = other._buffer[i];
    }
    return *this;
}
DSG::Buffer::~Buffer(){
    if (_buffer!=nullptr) {
        delete [] _buffer;
    }
}
DSG:: Sample& DSG::Buffer::operator[](size_t const& index){
#ifdef DEBUG
    assert(index<_size);
#endif
    return _buffer[index];
}

