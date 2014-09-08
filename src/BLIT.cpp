//
//  BLIT.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 9/2/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "BLIT.h"

Signal::BLIT::BLIT::BLIT():SignalGenerator(),phs(0){
    updateHarms();
}
Signal::BLIT::BLIT::BLIT(double const& frequency,double const& phase_offset):SignalGenerator(frequency,phase_offset){
    _nHarms = (Sample_Rate()*0.5)/_fHertz;
    updateHarms();
}
Signal::BLIT::BLIT::~BLIT(){}

double const& Signal::BLIT::BLIT::Frequency(double const& value){
    this->SignalGenerator::Frequency(value);
    _nHarms = (Sample_Rate()*0.5)/_fHertz;
    updateHarms();
    return this->_fHertz;
}
void Signal::BLIT::BLIT::updateHarms(){
    if (_nHarms<=0) {
        size_t max = (size_t)floor(0.5 * (Sample_Rate()/ _fHertz));
        m_ = 2* max +1;
    }
    else{
        m_ = 2* _nHarms +1;
    }
}