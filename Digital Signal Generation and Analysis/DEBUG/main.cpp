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
    
    Signal::RingBuffer _buff(4096);
    Signal::Analog::Saw _saw(20.0,0.0);
    
    _saw.Perform(_buff);
    std::cout<<_buff<<std::endl;
    return 0;
}
