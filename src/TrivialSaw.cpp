//
//  TrivialSaw.c
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/4/14.
//
//

#include "TrivialSaw.h"

Signal::Trivial::TrivialSaw::TrivialSaw():Signal::Trivial::TrivialGenerator(),_phasor(0){
    
}
Signal::Trivial::TrivialSaw::TrivialSaw(double const& frequency,double const& phase_offset):Signal::Trivial::TrivialGenerator(frequency,phase_offset),_phasor(0){
    
}
Signal::Trivial::TrivialSaw::~TrivialSaw(){
    
}