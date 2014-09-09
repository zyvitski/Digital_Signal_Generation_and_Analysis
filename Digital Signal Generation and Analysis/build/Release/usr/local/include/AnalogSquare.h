//
//  Square.h
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/4/14.
//
//

#ifndef Digital_Signal_Generation_and_Analysis_Square_h
#define Digital_Signal_Generation_and_Analysis_Square_h

#include "AnalogGenerator.h"
namespace Signal {
    namespace Analog{
        class Square:public AnalogGenerator{
        public:
            Square();
            Square(double const& frequency,double const& phase_offset);
            virtual ~Square();
            
            virtual inline bool Perform(Sample& signal);
            virtual inline bool Perform(RingBuffer& signal);
        protected:
            double _duty;//0-1.0
            
            
        };
        inline bool Square::Perform(Sample& signal){
            double value = _pstep();
            value+=_phase_offset;
            value-=(long)value;
            value-=0.5;
            value*=2.0;
            signal = value>=_duty ? -1.0: 1.0;
            return true;
        }
        inline bool Square::Perform(RingBuffer& signal){
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
