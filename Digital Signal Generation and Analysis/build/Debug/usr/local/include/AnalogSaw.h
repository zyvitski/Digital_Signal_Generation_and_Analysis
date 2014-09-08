//
//  Saw.h
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/4/14.
//
//

#ifndef Digital_Signal_Generation_and_Analysis_Saw_h
#define Digital_Signal_Generation_and_Analysis_Saw_h

#include "AnalogGenerator.h"
namespace Signal {
    namespace Analog{
        class Saw:public AnalogGenerator{
        public:
            Saw();
            Saw(double const& frequency,double const& phase_offset);
            virtual ~Saw();
            
            virtual inline bool Perform(Sample& signal);
            virtual inline bool Perform(RingBuffer& signal);
            
        };
        inline bool Saw::Perform(Sample& signal){
            double value = _pstep();
            value+=_phase_offset;
            value-=(long)value;
            value-=0.5;
            value*=2.0;
            signal = value;
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

#endif
