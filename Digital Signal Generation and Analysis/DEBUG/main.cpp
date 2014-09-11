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
    
    long cycles = 100000000000;
    
    double step = TWOPI/(float)cycles;
    double phs=0;
    
    for (int i=0; i<cycles; ++i) {
        DSG::Taylor::Sine(phs);
        phs+=step;
    }
   
    return 0;
}
