//
//  FourierSquare.cpp
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/3/14.
//
//

#include "FourierSquare.h"

DSG::FourierSquare::FourierSquare():FourierGenerator(),_a(4.0/PI),_h(_maxHarms(_frequency)+1),phs(0),stor(0){
}
DSG::FourierSquare::FourierSquare(double const& frequency,double const& phase_offset):FourierGenerator(frequency,phase_offset),_a(4.0/PI),_h(_maxHarms(_frequency)+1),phs(0),stor(0){
    _sample=0;
    _storage=0;
}
DSG::FourierSquare::~FourierSquare(){}
double const& DSG::FourierSquare::Frequency(double const& value){
    _frequency = value;
    _rate = _frequency/ Sample_Rate();
    _h = _maxHarms(_frequency)+1;
    return _frequency;
}
double const& DSG::FourierSquare::Frequency(){
    return this->_frequency;
}