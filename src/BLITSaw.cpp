//
//  BLITSaw.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 9/3/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "BLITSaw.h"

DSG::BLITSaw::BLITSaw():BLIT::BLIT(){
    
}
DSG::BLITSaw::BLITSaw(double const& frequency,double const& phase_offset):BLIT::BLIT(frequency,phase_offset){
    
}
DSG::BLITSaw::~BLITSaw(){
    
}
double const& DSG::BLITSaw::Frequency(double const& value){
    _rate=value;
    updateHarms();
    return _rate;
}
void DSG::BLITSaw::updateHarms(){
    
}