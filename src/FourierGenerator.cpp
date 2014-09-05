//
//  FourierGenerator.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 8/20/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "FourierGenerator.h"

Signal::Fourier::FourierGenerator::FourierGenerator():SignalGenerator(),_phasor(0){
    
}
Signal::Fourier::FourierGenerator::FourierGenerator(double const& frequency,double const& phase_offset):SignalGenerator(frequency,phase_offset),_phasor(0){}
Signal::Fourier::FourierGenerator::~FourierGenerator(){}


