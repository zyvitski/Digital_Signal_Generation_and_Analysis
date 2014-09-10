//
//  Saw.h
//  Waveform
//
//  Created by Alexander Zywicki on 8/21/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __Waveform__Saw__
#define __Waveform__Saw__

#include "FourierGenerator.h"
#include "Sin.h"

namespace DSG {
    namespace Fourier{
        /*!\brief Fourier Series Based Saw Wave
         */
        class Saw: public FourierGenerator {
        public:
            Saw();
            Saw(double const& frequency,double const& phase_offset);
            virtual ~Saw();
            virtual inline bool Perform(Signal::Sample& signal);
            virtual inline bool Perform(Signal::RingBuffer& signal);
            virtual double const& Frequency(double const& value);
            virtual double const& Frequency();
        protected:
            unsigned long _h;
            double _a;
            double phs;
            double stor;
            double iPI;
            unsigned short i;
        };
        
        inline bool Saw::Perform(Signal::Sample& signal){
            phs=_pstep();
            phs+=_phase_offset;
            phs -= (long)phs;
            signal=0;
            for (i=1; i<_h+1; ++i) {
                stor += _harmonicTable.Saw(i)* DSG::Backend::Sin(phs*(i));
            }
            stor*= _a;
            signal=stor;
            return true;
        }
        inline bool Saw::Perform(Signal::RingBuffer& signal){
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
