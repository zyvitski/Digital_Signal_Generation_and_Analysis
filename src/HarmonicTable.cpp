//
//  HarmonicTable.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 8/26/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "HarmonicTable.h"

Backend::HarmonicTable::HarmonicTable(){
    fillSaw();
}
Backend::HarmonicTable::~HarmonicTable(){
    
}


inline void Backend::HarmonicTable::fillSaw(){
    _saw[0]=0.0;
    for (int i=1; i<_size; ++i) {
        _saw[i] = 1.0/i;
    }
}