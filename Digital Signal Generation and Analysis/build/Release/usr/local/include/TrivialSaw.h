//
//  TrivialSaw.h
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/4/14.
//
//

#ifndef Digital_Signal_Generation_and_Analysis_TrivialSaw_h
#define Digital_Signal_Generation_and_Analysis_TrivialSaw_h

#include "TrivialGenerator.h"
namespace Signal {
    namespace Trivial{
        class TrivialSaw:public TrivialGenerator{
        public:
            TrivialSaw();
            TrivialSaw(double const& frequency,double const& phase_offset);
            virtual ~TrivialSaw();
            
            virtual inline bool Perform(Sample& signal);
            virtual inline bool Perform(RingBuffer& signal);
        protected:
            double _phasor;
            
            
        };
        inline bool TrivialSaw::Perform(Sample& signal){
            double value = _phasor;
            _phasor+=_frequency;
            _phasor = _phasor-(unsigned long)_phasor;//cheaper %1
            value+=_phase_offset;
            value = value-(unsigned long)value;
            value-=0.5;
            value*=2.0;
            signal =value;
            return true;
        }
        inline bool TrivialSaw::Perform(RingBuffer& signal){
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
