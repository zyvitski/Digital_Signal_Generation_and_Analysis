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
    Signal::Set_Sample_Rate(44100);
    Signal::Analog::Square _sqr(160.0,0.0);
    DriverInit(&_sqr);
    Pa_Sleep(2000);
    DriverExit();
    return 0;
}
