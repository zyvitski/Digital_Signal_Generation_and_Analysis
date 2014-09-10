//
//  Buffer.h
//  Processing
//
//  Created by Alexander Zywicki on 8/14/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __Processing__Buffer__
#define __Processing__Buffer__

#ifdef DEBUG
#include <assert.h>
#endif
#include <stddef.h>
#include "Sample.h"
namespace DSG{
    class Buffer {
    public:
        Buffer();
        Buffer(size_t size);
        Buffer(Buffer const& other);
        Buffer& operator=(Buffer const& other);
        virtual ~Buffer();
        Signal::Sample& operator[](size_t const& index);
        inline size_t const& Size()const;
    protected:
        Signal::Sample* _buffer;
        size_t _size;
    };
    inline size_t const& Buffer::Size()const{
        return _size;
    }
}
#endif /* defined(__Processing__Buffer__) */
