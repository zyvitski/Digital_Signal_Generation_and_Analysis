//
//  Square.h
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/3/14.
//
//

#ifndef Digital_Signal_Generation_and_Analysis_Square_h
#define Digital_Signal_Generation_and_Analysis_Square_h

#include "FourierGenerator.h"

namespace Signal {
    
    namespace Fourier{
        /*!\brief Fourier Series Based Square Wave
         */
        class Square: public FourierGenerator {
        public:
            Square();
            Square(double const& frequency,double const& phase_offset);
            virtual ~Square();
            virtual inline bool Perform(Sample& signal);
            virtual inline bool Perform(RingBuffer& signal);
            virtual double const& Frequency(double const& value);
            virtual double const& Frequency();
        protected:
            unsigned long _h;
            double _a;
            double phs;
            double stor;
            unsigned short i;
        };
        
        inline bool Square::Perform(Sample& signal){
            phs = _pstep();
            phs+= _phase_offset;
            phs -= (long)phs;
            stor=0;
            for (i=1; i<_h+1; i+=2) {
                stor += _harmonicTable.Saw(i) * sine(phs*i);
            }
            stor *= _a;
            signal = stor;
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
