//
//  FourierTriangle.h
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/8/14.
//
//

#ifndef Digital_Signal_Generation_and_Analysis_FourierTriangle_h
#define Digital_Signal_Generation_and_Analysis_FourierTriangle_h

#include "FourierGenerator.h"

namespace DSG {
    

        /*!\brief Fourier Series Based FourierTriangle Wave
         */
        class FourierTriangle: public FourierGenerator {
        public:
            FourierTriangle();
            FourierTriangle(double const& frequency,double const& phase_offset);
            virtual ~FourierTriangle();
            virtual inline bool Perform( Sample& signal);
            virtual inline bool Perform( RingBuffer& signal);
            virtual double const& Frequency(double const& value);
            virtual double const& Frequency();
        protected:
            unsigned long _h;
            double _a;
            double phs;
            double stor;
            unsigned short i;
        };
        
        inline bool FourierTriangle::Perform( Sample& signal){
            phs = _pstep();

            stor=0;
            for (i=1; i<_h; i+=2) {
                stor+=_harmonicTable.Triangle(i)*_sineLut(phs*i);
            }
            stor*=_a;
            signal=stor;
            return true;
        }
        inline bool FourierTriangle::Perform( RingBuffer& signal){
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
