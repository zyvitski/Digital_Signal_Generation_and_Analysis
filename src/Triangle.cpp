//
//  Triangle.cpp
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/8/14.
//
//



#include "Triangle.h"

Signal::Fourier::Triangle::Triangle():FourierGenerator(),_a(8.0/(PI*PI)),_h(_maxHarms(_fHertz)),phs(0),stor(0){
}
Signal::Fourier::Triangle::Triangle(double const& frequency,double const& phase_offset):FourierGenerator(frequency,phase_offset),_a(8.0/(PI*PI)),_h(_maxHarms(_fHertz)),phs(0),stor(0){
    _sample=0;
    _storage=0;
}
Signal::Fourier::Triangle::~Triangle(){}
double const& Signal::Fourier::Triangle::Frequency(double const& value){
    _fHertz = value;
    _frequency = _fHertz/Sample_Rate();
    _h = _maxHarms(_fHertz);
    return _fHertz;
}
double const& Signal::Fourier::Triangle::Frequency(){
    return this->_fHertz;
}