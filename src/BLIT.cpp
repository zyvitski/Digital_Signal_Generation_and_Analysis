//
//  BLIT.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 9/2/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "BLIT.h"

Signal::BLIT::BLIT():SignalGenerator(){
    updateHarms();
}
Signal::BLIT::BLIT(double const& frequency,double const& phase_offset):SignalGenerator(frequency,phase_offset){
    updateHarms();
}
Signal::BLIT::~BLIT(){}

double const& Signal::BLIT::Frequency(double const& value){
    this->SignalGenerator::Frequency(value);
    updateHarms();
    return this->_fHertz;
}
void Signal::BLIT::updateHarms(){
    if (_nHarms<=0) {
        size_t max = (size_t)floor(0.5 * (Sample_Rate()/ _fHertz));
        m_ = 2* max +1;
    }
    else{
        m_ = 2* _nHarms +1;
    }
}