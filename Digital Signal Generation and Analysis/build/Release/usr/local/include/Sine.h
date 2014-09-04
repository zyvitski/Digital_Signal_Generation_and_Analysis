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

#define SINE_USE_DEFAULT 0
#define SINE_USE_LUT 1
#define SINE_USE_TAYLOR 2


#define SINE_IMPL 1
/*
 if SINE_IMPL is 1 sine class will use look up table
 elif SINE_IMPLE is 2 use custom taylor series sine
 else will use built in
 */
#if SINE_IMPL ==0
#include <math.h>
#elif SINE_IMPL ==2
#include "Taylor.h"
#endif

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
        //uses LUT
#if SINE_IMPL == SINE_USE_LUT
        signal = sine((_pstep() + _phase_offset));
#elif SINE_IMPL==SINE_USE_TAYLOR
        signal = Backend::Taylor::Sine((_pstep()+_phase_offset)*TWOPI);
#else
        signal = sin((_pstep()+_phase_offset)*TWOPI);
#endif

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
