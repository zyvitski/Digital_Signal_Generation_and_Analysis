//
//  AnalogSaw.cpp
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/4/14.
//
//

#include "AnalogSaw.h"

Signal::Analog::Saw::Saw():Signal::Analog::AnalogGenerator(){
    
}
Signal::Analog::Saw::Saw(double const& frequency,double const& phase_offset):Signal::Analog::AnalogGenerator(frequency,phase_offset){
    
}
Signal::Analog::Saw::~Saw(){
    
}