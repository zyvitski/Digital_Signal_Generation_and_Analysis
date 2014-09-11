//
//  AnalogGenerator.cpp
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/4/14.
//
//
#include "AnalogGenerator.h"
DSG::AnalogGenerator::AnalogGenerator():DSG::SignalGenerator(){}
DSG::AnalogGenerator::AnalogGenerator(double const& frequency,double const& phase_offset):DSG::SignalGenerator(frequency,phase_offset){}
DSG::AnalogGenerator::~AnalogGenerator(){}
