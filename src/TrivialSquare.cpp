//
//  TrivialSquare.cpp
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/4/14.
//
//

#include "TrivialSquare.h"

Signal::Trivial::TrivialSquare::TrivialSquare():Signal::Trivial::TrivialGenerator(),_phasor(0),_duty(0.5){
    
}
Signal::Trivial::TrivialSquare::TrivialSquare(double const& frequency,double const& phase_offset):Signal::Trivial::TrivialGenerator(frequency,phase_offset),_phasor(0),_duty(0.5){
    
}
Signal::Trivial::TrivialSquare::~TrivialSquare(){
    
}