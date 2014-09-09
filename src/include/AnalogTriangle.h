//
//  AnalogTriangle.h
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/9/14.
//
//

#ifndef Digital_Signal_Generation_and_Analysis_AnalogTriangle_h
#define Digital_Signal_Generation_and_Analysis_AnalogTriangle_h

#include "AnalogGenerator.h"
namespace Signal {
    namespace Analog{
        class Triangle:public AnalogGenerator{
        public:
            Triangle();
            Triangle(double const& frequency,double const& phase_offset);
            virtual ~Triangle();
            
            virtual inline bool Perform(Sample& signal);
            virtual inline bool Perform(RingBuffer& signal);
            
        };
        inline bool Triangle::Perform(Sample& signal){
            double value = _pstep();
            value+=_phase_offset;
            value+=0.25;
            value-=(long)value;
            value-=0.5;
            value*=2.0;
            value = value <0.0 ?  value: -1*value;
            value+=0.5;
            value*=2.0;
            signal = value;
            return true;
        }
        inline bool Triangle::Perform(RingBuffer& signal){
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
