//
//  TrivialGenerator.h
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/4/14.
//
//

#ifndef Digital_Signal_Generation_and_Analysis_TrivialGenerator_h
#define Digital_Signal_Generation_and_Analysis_TrivialGenerator_h

#include "SignalGenerator.h"

namespace Signal {
    namespace Trivial{
        /*
         Trivial generator is a base class used for the generation of "trivial" non bandlimited waveforms. Trivial meaning composed of line segments generated in a pure mathmatical manor as if it were pure analog voltage.
         */
        class TrivialGenerator:public SignalGenerator{
        public:
            TrivialGenerator();
            TrivialGenerator(double const& frequency,double const& phase_offset);
            virtual ~TrivialGenerator();
            
            virtual inline bool Perform(Sample& signal);
            virtual inline bool Perform(RingBuffer& signal);
        protected:
            Sample _sample;
        };
        
        inline bool TrivialGenerator::Perform(Sample& signal){
            signal = 0;
            return false;
        }
        inline bool TrivialGenerator::Perform(RingBuffer& signal){
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
