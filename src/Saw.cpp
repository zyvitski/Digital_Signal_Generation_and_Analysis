//
//  Saw.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 8/21/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "Saw.h"
Signal::Saw::Saw():ClassicGenerator(),_a(5.0/3.0),_h(_maxHarms(_fHertz)),iPI(1.0/PI),tmp(0),stor(0){}
Signal::Saw::Saw(double const& frequency,double const& phase_offset):ClassicGenerator(frequency,phase_offset),_a(5.0/3.0),_h(_maxHarms(_fHertz)),iPI(1.0/PI),tmp(0),stor(0){
    _sample=0;
    _storage=0;
}
Signal::Saw::~Saw(){}
double const& Signal::Saw::Frequency(double const& value){
    _fHertz = value;
    _frequency = _fHertz/Sample_Rate();
    _h = _maxHarms(_fHertz);
    return _fHertz;
}
double const& Signal::Saw::Frequency(){
    return this->_fHertz;
}