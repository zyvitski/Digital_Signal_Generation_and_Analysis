//
//  Sine.h
//  Waveform
//
//  Created by Alexander Zywicki on 8/21/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __Waveform__Sine__
#define __Waveform__Sine__

#include "ClassicGenerator.h"


namespace Signal {
    class Sine: public ClassicGenerator {
    public:
        Sine();
        Sine(double const& frequency,double const& phase_offset);
        virtual ~Sine();
        virtual inline bool Perform(Sample& signal);
        virtual inline bool Perform(RingBuffer& signal);
    };
    
    inline bool Sine::Perform(Sample& signal){
        signal = sine((_pstep() + _phase_offset));
        return true;
    }
    inline bool Sine::Perform(RingBuffer& signal){
        signal.Flush();
        while (!signal.Full()) {
            if (Perform(_sample)) {
                if(signal.Write(_sample)){
                }else return false;
            }else return false;
        }return true;
    }
}
#endif /* defined(__Waveform__Sine__) */
