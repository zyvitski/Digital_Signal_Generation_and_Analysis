//
//  BLIT.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 9/2/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "BLIT.h"

DSG::BLIT::BLIT():SignalGenerator(),phs(0){
    updateHarms();
}
DSG::BLIT::BLIT(double const& frequency,double const& phase_offset):SignalGenerator(frequency,phase_offset){
    _nHarms = ( Sample_Rate()*0.5)/_frequency;
    updateHarms();
}
DSG::BLIT::~BLIT(){}

double const& DSG::BLIT::Frequency(double const& value){
    this->SignalGenerator::Frequency(value);
    _nHarms = ( Sample_Rate()*0.5)/_frequency;
    updateHarms();
    return this->_frequency;
}
void DSG::BLIT::updateHarms(){
    if (_nHarms<=0) {
        size_t max = (size_t)floor(0.5 * ( Sample_Rate()/ _frequency));
        m_ = 2* max +1;
    }
    else{
        m_ = 2* _nHarms +1;
    }
}