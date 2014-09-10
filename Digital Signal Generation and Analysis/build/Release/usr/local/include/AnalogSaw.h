//
//  AnalogSaw.h
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/4/14.
//
//

#ifndef Digital_Signal_Generation_and_Analysis_AnalogSaw_h
#define Digital_Signal_Generation_and_Analysis_AnalogSaw_h

#include "AnalogGenerator.h"
namespace DSG {
    
        class AnalogSaw:public AnalogGenerator{
        public:
            AnalogSaw();
            AnalogSaw(double const& frequency,double const& phase_offset);
            virtual ~AnalogSaw();
            
            virtual inline bool Perform( Sample& signal);
            virtual inline bool Perform( RingBuffer& signal);
            
        };
        inline bool AnalogSaw::Perform( Sample& signal){
            double value = _pstep();

            value-=0.5;
            value*=2.0;
            signal = value;
            return true;
        }
        inline bool AnalogSaw::Perform( RingBuffer& signal){
            signal.Flush();
            while (!signal.Full()) {
                if (Perform(_sample)) {
                    if(signal.Write(_sample)){
                    }else return false;
                }else return false;
            }return true;
        }

    
}

#endif
