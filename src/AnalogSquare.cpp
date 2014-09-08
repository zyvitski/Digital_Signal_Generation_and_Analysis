//
//  AnalogSquare.cpp
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/4/14.
//
//

#include "AnalogSquare.h"

Signal::Analog::Square::Square():Signal::Analog::AnalogGenerator(),_duty(0.5){
    
}
Signal::Analog::Square::Square(double const& frequency,double const& phase_offset):Signal::Analog::AnalogGenerator(frequency,phase_offset),_duty(0.5){
    
}
Signal::Analog::Square::~Square(){
    
}