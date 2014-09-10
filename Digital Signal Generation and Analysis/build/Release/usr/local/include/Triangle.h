//
//  Triangle.h
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/8/14.
//
//

#ifndef Digital_Signal_Generation_and_Analysis_Triangle_h
#define Digital_Signal_Generation_and_Analysis_Triangle_h

#include "FourierGenerator.h"

namespace DSG {
    
    namespace Fourier{
        /*!\brief Fourier Series Based Triangle Wave
         */
        class Triangle: public FourierGenerator {
        public:
            Triangle();
            Triangle(double const& frequency,double const& phase_offset);
            virtual ~Triangle();
            virtual inline bool Perform(Signal::Sample& signal);
            virtual inline bool Perform(Signal::RingBuffer& signal);
            virtual double const& Frequency(double const& value);
            virtual double const& Frequency();
        protected:
            unsigned long _h;
            double _a;
            double phs;
            double stor;
            unsigned short i;
        };
        
        inline bool Triangle::Perform(Signal::Sample& signal){
            phs = _pstep();

            stor=0;
            for (i=1; i<_h; i+=2) {
                stor+=_harmonicTable.Triangle(i)*DSG::Backend::Sin(phs*i);
            }
            stor*=_a;
            signal=stor;
            return true;
        }
        inline bool Triangle::Perform(Signal::RingBuffer& signal){
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
