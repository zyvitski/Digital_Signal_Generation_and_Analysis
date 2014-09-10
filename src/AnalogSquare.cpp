//
//  AnalogSquare.cpp
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/4/14.
//
//

#include "AnalogSquare.h"

DSG::AnalogSquare::AnalogSquare():DSG::AnalogGenerator(),_duty(0.5){
    
}
DSG::AnalogSquare::AnalogSquare(double const& frequency,double const& phase_offset):DSG::AnalogGenerator(frequency,phase_offset),_duty(0.5){
    
}
DSG::AnalogSquare::~AnalogSquare(){
    
}