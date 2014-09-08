//
//  BLITSaw.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 9/3/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "BLITSaw.h"

Signal::BLIT::Saw::Saw():BLIT::BLIT(){
    
}
Signal::BLIT::Saw::Saw(double const& frequency,double const& phase_offset):BLIT::BLIT(frequency,phase_offset){
    
}
Signal::BLIT::Saw::~Saw(){
    
}
double const& Signal::BLIT::Saw::Frequency(double const& value){
    _frequency=value;
    updateHarms();
    return _frequency;
}
void Signal::BLIT::Saw::updateHarms(){
    
}