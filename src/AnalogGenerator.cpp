//
//  AnalogGenerator.cpp
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/4/14.
//
//

#include "AnalogGenerator.h"

Signal::Analog::AnalogGenerator::AnalogGenerator():Signal::SignalGenerator(){}
Signal::Analog::AnalogGenerator::AnalogGenerator(double const& frequency,double const& phase_offset):Signal::SignalGenerator(frequency,phase_offset){}
Signal::Analog::AnalogGenerator::~AnalogGenerator(){}
