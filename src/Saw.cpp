//
//  Saw.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 8/21/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "Saw.h"
Signal::Fourier::Saw::Saw():FourierGenerator(),_a(3.6/3.0),_h(_maxHarms(_fHertz)),iPI(1.0/PI),phs(0),stor(0){
    _a*=iPI;
}
Signal::Fourier::Saw::Saw(double const& frequency,double const& phase_offset):FourierGenerator(frequency,phase_offset),_a(3.6/3.0),_h(_maxHarms(_fHertz)),iPI(1.0/PI),phs(0),stor(0){
    _sample=0;
    _storage=0;
    _a*=iPI;
}
Signal::Fourier::Saw::~Saw(){}
double const& Signal::Fourier::Saw::Frequency(double const& value){
    _fHertz = value;
    _frequency = _fHertz/Sample_Rate();
    _h = _maxHarms(_fHertz);
    return _fHertz;
}
double const& Signal::Fourier::Saw::Frequency(){
    return this->_fHertz;
}