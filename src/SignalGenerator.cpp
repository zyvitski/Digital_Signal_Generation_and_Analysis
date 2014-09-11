//
//  SignalGenerator.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 8/20/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#include "SignalGenerator.h"
DSG::SignalGenerator::SignalGenerator():_rate(0),_phase_offset(0),_frequency(0),_phasor(0){

}
DSG::SignalGenerator::SignalGenerator(double const& frequency,double const& phase_offset):_rate(frequency/ Sample_Rate()),_frequency(frequency),_phase_offset(phase_offset),_phasor(0){}
DSG::SignalGenerator::~SignalGenerator(){}
double const& DSG::SignalGenerator::Frequency()const{
    return _frequency;
}
double const& DSG::SignalGenerator::Frequency(double const& value){
    _frequency = value;
    _rate = _frequency/ Sample_Rate();
    return _frequency;
}
double const& DSG::SignalGenerator::PhaseOffset()const{
    return _phase_offset;
}
double const& DSG::SignalGenerator::PhaseOffset(double const& value){
    _phase_offset-=value;
    _phasor-=_phase_offset;
    _phase_offset=value;
    return _phase_offset;
}