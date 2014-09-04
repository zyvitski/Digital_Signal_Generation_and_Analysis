//
//  HarmonicTable.h
//  Waveform
//
//  Created by Alexander Zywicki on 8/26/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef Waveform_HarmonicTable_h
#define Waveform_HarmonicTable_h

#include "LUT.h"
#include <assert.h>
namespace Backend{
class HarmonicTable {
public:
    HarmonicTable();
    ~HarmonicTable();
    inline double const& Saw(unsigned short const& index);
protected:
    double _saw[8192];
    const short _size=8192;
    inline void fillSaw();
};

inline double const& HarmonicTable::Saw(unsigned short const& index){
#ifdef DEBUG
    assert(index<_size);
#endif
    return _saw[index];
}
}

#endif
