//
//  Saw.h
//  Waveform
//
//  Created by Alexander Zywicki on 8/21/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __Waveform__Saw__
#define __Waveform__Saw__

#include "ClassicGenerator.h"


namespace Signal {
    
    
    class Saw: public ClassicGenerator {
    public:
        Saw();
        Saw(double const& frequency,double const& phase_offset);
        virtual ~Saw();
        virtual inline bool Perform(Sample& signal);
        virtual inline bool Perform(RingBuffer& signal);
        virtual double const& Frequency(double const& value);
        virtual double const& Frequency();
    protected:
        unsigned long _h;
        double _a;
        double tmp;
        double stor;
        double iPI;
        unsigned short i;
    };
    
    inline bool Saw::Perform(Sample& signal){
        tmp=_pstep();
        tmp+=_phase_offset;
        signal=0;
        for (i=1; i<_h+1; ++i) {
            stor += _harmonicTable.Saw(i)* sine(tmp*(i));
        }
        stor*= _a*iPI;
        signal=stor;
        return true;
    }
    inline bool Saw::Perform(RingBuffer& signal){
        signal.Flush();
        while (!signal.Full()) {
            if (Perform(_sample)) {
                if(signal.Write(_sample)){
                }else return false;
            }else return false;
        }return true;
    }
}

#endif /* defined(__Waveform__Saw__) */