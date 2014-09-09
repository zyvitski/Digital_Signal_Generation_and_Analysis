//
//  Saw.h
//  Waveform
//
//  Created by Alexander Zywicki on 9/3/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __Waveform__Saw__
#define __Waveform__Saw__

#include "BLIT.h"

namespace Signal {
    namespace BLIT{
        /*!\brief
         *See file ~/Research/alias-free-digital-synthesis-of-classic-analog-waveforms.pdf for details of concept
         */
        
        class Saw:public BLIT::BLIT {
            Saw();
            Saw(double const& frequency,double const& phase_offset);
            virtual ~Saw();
            virtual double const& Frequency(double const& value);//get and set frequency in hz
            virtual inline bool Perform(Sample& signal);
            virtual inline bool Perform(RingBuffer& signal);
        protected:
            virtual void updateHarms();
            
            
        };
        
        inline bool Saw::Perform(Sample& signal){
#warning unimplimented BLIT Saw Perform
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
}
#endif /* defined(__Waveform__Saw__) */
