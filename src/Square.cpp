//
//  Square.cpp
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/3/14.
//
//

#include "Square.h"

Signal::Fourier::Square::Square():FourierGenerator(),_a(4.0/PI),_h(_maxHarms(_fHertz)),phs(0),stor(0){
}
Signal::Fourier::Square::Square(double const& frequency,double const& phase_offset):FourierGenerator(frequency,phase_offset),_a(4.0/PI),_h(_maxHarms(_fHertz)),phs(0),stor(0){
    _sample=0;
    _storage=0;
}
Signal::Fourier::Square::~Square(){}
double const& Signal::Fourier::Square::Frequency(double const& value){
    _fHertz = value;
    _frequency = _fHertz/Sample_Rate();
    _h = _maxHarms(_fHertz);
    return _fHertz;
}
double const& Signal::Fourier::Square::Frequency(){
    return this->_fHertz;
}