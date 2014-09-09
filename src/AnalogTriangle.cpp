//
//  AnalogTriangle.cpp
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/9/14.
//
//

#include "AnalogTriangle.h"

Signal::Analog::Triangle::Triangle():Signal::Analog::AnalogGenerator(){
    
}
Signal::Analog::Triangle::Triangle(double const& frequency,double const& phase_offset):Signal::Analog::AnalogGenerator(frequency,phase_offset){
    
}
Signal::Analog::Triangle::~Triangle(){
    
}
