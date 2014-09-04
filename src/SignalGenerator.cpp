//
//  SignalGenerator.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 8/20/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "SignalGenerator.h"
Signal::SignalGenerator::SignalGenerator():_frequency(0),_phase_offset(0),_fHertz(0){

}
Signal::SignalGenerator::SignalGenerator(double const& frequency,double const& phase_offset):_frequency(frequency/Sample_Rate()),_fHertz(frequency),_phase_offset(phase_offset){}
Signal::SignalGenerator::~SignalGenerator(){}

double const& Signal::SignalGenerator::Frequency()const{
    return _fHertz;
}
double const& Signal::SignalGenerator::Frequency(double const& value){
    _fHertz = value;
    _frequency = _fHertz/Sample_Rate();
    return _fHertz;
}
double const& Signal::SignalGenerator::PhaseOffset()const{
    return _phase_offset;
}
double const& Signal::SignalGenerator::PhaseOffset(double const& value){
    _phase_offset = value;
    return _phase_offset;
}


