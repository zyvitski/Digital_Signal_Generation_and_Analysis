//
//  TrivialSquare.h
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/4/14.
//
//

#ifndef Digital_Signal_Generation_and_Analysis_TrivialSquare_h
#define Digital_Signal_Generation_and_Analysis_TrivialSquare_h

#include "TrivialGenerator.h"
namespace Signal {
    namespace Trivial{
        class TrivialSquare:public TrivialGenerator{
            TrivialSquare();
            TrivialSquare(double const& frequency,double const& phase_offset);
            virtual ~TrivialSquare();
            
            virtual inline bool Perform(Sample& signal);
            virtual inline bool Perform(RingBuffer& signal);
        protected:
            double _phasor;
            double _duty;//0-1.0
            
            
        };
        inline bool TrivialSquare::Perform(Sample& signal){
            double value = _phasor;
            _phasor+=_frequency;
            _phasor = _phasor-(unsigned long)_phasor;//cheaper %1
            value+=_phase_offset;
            value = value-(unsigned long)value;
            
            signal = value>=_duty ? 1.0: -1.0;
            return true;
        }
        inline bool TrivialSquare::Perform(RingBuffer& signal){
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
