//
//  FourierTriangle.cpp
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/8/14.
//
//
#include "FourierTriangle.h"
DSG::FourierTriangle::FourierTriangle():FourierGenerator(),_a(8.0/(PI*PI)),_h(_maxHarms(_frequency)+1),phs(0),stor(0){
}
DSG::FourierTriangle::FourierTriangle(double const& frequency,double const& phase_offset):FourierGenerator(frequency,phase_offset),_a(8.0/(PI*PI)),_h(_maxHarms(_frequency)+1),phs(0),stor(0){
    _sample=0;
    _storage=0;
}
DSG::FourierTriangle::~FourierTriangle(){}
double const& DSG::FourierTriangle::Frequency(double const& value){
    _frequency = value;
    _rate = _frequency/ Sample_Rate();
    _h = _maxHarms(_frequency)+1;
    return _frequency;
}
double const& DSG::FourierTriangle::Frequency(){
    return this->_frequency;
}