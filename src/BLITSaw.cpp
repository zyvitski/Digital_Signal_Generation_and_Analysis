//
//  BLITSaw.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 9/3/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "BLITSaw.h"

DSG::BLITSaw::BLITSaw():BLIT::BLIT(){}
DSG::BLITSaw::BLITSaw(double const& frequency,double const& phase_offset):BLIT::BLIT(frequency,phase_offset){}
DSG::BLITSaw::~BLITSaw(){}
double const& DSG::BLITSaw::Frequency(double const& value){
    _frequency = value;
    _rate = _frequency/ Sample_Rate();
    C2_ = 1.0 / (Sample_Rate()/_frequency);
    
    updateHarms();
    state_ = -0.5 * a_; 
    return _rate;
}
void DSG::BLITSaw::updateHarms(){
    if (_nHarms<=0) {
        size_t max = (size_t)floor(0.5 * ( Sample_Rate()/ _frequency));
        m_ = 2* max +1;
    }
    else{
        m_ = 2* _nHarms +1;
    }
    a_ = m_/p_;
}