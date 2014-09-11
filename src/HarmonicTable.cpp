//
//  HarmonicTable.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 8/26/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "HarmonicTable.h"
DSG::HarmonicTable::HarmonicTable(){
    fillSaw();
    fillTri();
}
DSG::HarmonicTable::~HarmonicTable(){}
inline void DSG::HarmonicTable::fillSaw(){
    _saw[0]=0.0;
    for (int i=1; i<_size; ++i) {
        _saw[i] = 1.0/i;
    }
}
inline void DSG::HarmonicTable::fillTri(){
    _triangle[0]=0.0;
    for (int i=1; i<_size; i+=2) {
        _triangle[i] =pow(-1.0, (i-1.0)*0.5)/(i*i);
    }
}