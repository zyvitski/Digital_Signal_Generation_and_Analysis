//
//  Sine.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 8/21/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "Sine.h"


Signal::Sine::Sine():ClassicGenerator(){}
Signal::Sine::Sine(double const& frequency,double const& phase_offset):ClassicGenerator(frequency,phase_offset){
    _sample=0;
    _storage=0;
}
Signal::Sine::~Sine(){}



