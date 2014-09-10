//
//  FourierSaw.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 8/21/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "FourierSaw.h"
DSG::FourierSaw::FourierSaw():FourierGenerator(),_a(3.6/3.0),_h(_maxHarms(_frequency)+1),iPI(1.0/PI),phs(0),stor(0),_tmp(0){
    _a*=iPI;
}
DSG::FourierSaw::FourierSaw(double const& frequency,double const& phase_offset):FourierGenerator(frequency,phase_offset),_a(3.6/3.0),_h(_maxHarms(_frequency)+1),iPI(1.0/PI),phs(0),stor(0),_tmp(0){
    _sample=0;
    _storage=0;
    _a*=iPI;
}
DSG::FourierSaw::~FourierSaw(){}
double const& DSG::FourierSaw::Frequency(double const& value){
    _frequency = value;
    _rate = _frequency/ Sample_Rate();
    _h = _maxHarms(_frequency)+1;
    return _frequency;
}
double const& DSG::FourierSaw::Frequency(){
    return this->_frequency;
}