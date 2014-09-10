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
    DSG:: Set_Sample_Rate(44100);
    DSG:: RingBuffer _buff(4096);
    DSG::FourierSaw _saw(20.0,0.0);
    DSG::
    
    
    _saw.Perform(_buff);
    std::cout<<_buff<<std::endl;
   
    return 0;
}
