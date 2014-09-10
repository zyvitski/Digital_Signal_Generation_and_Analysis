//
//  AnalogGenerator.h
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/4/14.
//
//

#ifndef Digital_Signal_Generation_and_Analysis_AnalogGenerator_h
#define Digital_Signal_Generation_and_Analysis_AnalogGenerator_h

#include "SignalGenerator.h"

namespace DSG {
    namespace Analog{
        /*
         Analog generator is a base class used for the generation of "Analog" non bandlimited waveforms. Analog meaning composed of line segments generated in a pure mathmatical manor as if it were pure analog voltage.
         */
        class AnalogGenerator:public SignalGenerator{
        public:
            AnalogGenerator();
            AnalogGenerator(double const& frequency,double const& phase_offset);
            virtual ~AnalogGenerator();
            
            virtual inline bool Perform(Signal::Sample& signal);
            virtual inline bool Perform(Signal::RingBuffer& signal);
        protected:
            Signal::Sample _sample;
        };
        
        inline bool AnalogGenerator::Perform(Signal::Sample& signal){
            signal = 0;
            return false;
        }
        inline bool AnalogGenerator::Perform(Signal::RingBuffer& signal){
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
