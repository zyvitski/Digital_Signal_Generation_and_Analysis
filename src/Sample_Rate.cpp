//
//  Sample_Rate.cpp
//  Oscillators
//
//  Created by Alexander Zywicki on 8/6/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "Sample_Rate.h"

double Signal::SampleRate::sample_rate;
double Signal::SampleRate::sample_rate_inverse;

void Signal::SampleRate::Set(double const& value){
    sample_rate = value;
    sample_rate_inverse = 1.0f/value;
}
double const& Signal::SampleRate::Sample_Rate(){
    return sample_rate;
}
double const& Signal::SampleRate::Sample_Rate_Inverse(){
    return sample_rate_inverse;
}

