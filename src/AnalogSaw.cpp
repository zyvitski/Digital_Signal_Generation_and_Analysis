//
//  AnalogAnalogSaw.cpp
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/4/14.
//
//
#include "AnalogSaw.h"
DSG::AnalogSaw::AnalogSaw():DSG::AnalogGenerator(){}
DSG::AnalogSaw::AnalogSaw(double const& frequency,double const& phase_offset):DSG::AnalogGenerator(frequency,phase_offset){}
DSG::AnalogSaw::~AnalogSaw(){}