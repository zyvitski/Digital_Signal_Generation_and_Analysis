//
//  main.cpp
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/3/14.
//
//

#include "Signal.h"
#include "Backend.h"



int main(){
    DSG::Sample_Rate(44100);
    DSG::FourierSaw _sqr(9.0,0.0);
    
    DriverInit(&_sqr);
    Pa_Sleep(20000);
    DriverExit();
    return 0;
}
