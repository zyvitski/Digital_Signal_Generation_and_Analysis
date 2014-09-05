//
//  TrivialGenerator.cpp
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/4/14.
//
//

#include "TrivialGenerator.h"

Signal::Trivial::TrivialGenerator::TrivialGenerator():Signal::SignalGenerator(){}
Signal::Trivial::TrivialGenerator::TrivialGenerator(double const& frequency,double const& phase_offset):Signal::SignalGenerator(frequency,phase_offset){}
Signal::Trivial::TrivialGenerator::~TrivialGenerator(){}
