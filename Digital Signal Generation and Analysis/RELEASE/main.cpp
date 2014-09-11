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
    DSG::FourierSquare _sqr(220.0,0.0);
    
    DriverInit(&_sqr);
    Pa_Sleep(5000);
    DriverExit();
    return 0;
}
