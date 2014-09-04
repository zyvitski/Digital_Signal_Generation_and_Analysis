//
//  ClassicGenerator.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 8/20/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "ClassicGenerator.h"

Signal::ClassicGenerator::ClassicGenerator():SignalGenerator(),_phasor(0){
    
}
Signal::ClassicGenerator::ClassicGenerator(double const& frequency,double const& phase_offset):SignalGenerator(frequency,phase_offset),_phasor(0){}
Signal::ClassicGenerator::~ClassicGenerator(){}


