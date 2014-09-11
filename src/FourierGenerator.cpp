//
//  FourierGenerator.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 8/20/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "FourierGenerator.h"
DSG ::HarmonicTable DSG::FourierGenerator::_harmonicTable;
DSG ::SineLUT<float, 32768> DSG::FourierGenerator::_sineLut;
DSG::FourierGenerator::FourierGenerator():SignalGenerator(){
    
}
DSG::FourierGenerator::FourierGenerator(double const& frequency,double const& phase_offset):SignalGenerator(frequency,phase_offset){}
DSG::FourierGenerator::~FourierGenerator(){}