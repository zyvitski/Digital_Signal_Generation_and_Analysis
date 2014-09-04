//
//  main.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 8/20/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "Backend.h"
#include "Signal.h"
#include "Oscillators.h"


int main(int argc, const char * argv[])
{
    
    double stp = TWOPI/1000.0;
    double phs=0;
    for (int i=0; i<1000; ++i) {
        std::cout<<Taylor::Sine(phs)<<std::endl;
        phs+=stp;
    }
    
    return 0;
    Set_Sample_Rate(44100);
    
    Saw _s(30,0.0);
    
    DriverInit(&_s);
    Pa_Sleep(10000);
    DriverExit();
    
    
    return 0;
}

