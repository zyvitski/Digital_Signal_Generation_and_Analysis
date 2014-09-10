//
//  FourierSquare.h
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/3/14.
//
//

#ifndef Digital_Signal_Generation_and_Analysis_FourierSquare_h
#define Digital_Signal_Generation_and_Analysis_FourierSquare_h

#include "FourierGenerator.h"

namespace DSG {
    

        /*!\brief Fourier Series Based FourierSquare Wave
         */
        class FourierSquare: public FourierGenerator {
        public:
            FourierSquare();
            FourierSquare(double const& frequency,double const& phase_offset);
            virtual ~FourierSquare();
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
        
        inline bool FourierSquare::Perform( Sample& signal){
            phs = _pstep();

            stor=0;
            for (i=1; i<_h; i+=2) {
                stor += _harmonicTable.Saw(i) * DSG::Backend::Sin(phs*i);
            }
            stor *= _a;
            signal = stor;
            return true;
        }
        inline bool FourierSquare::Perform( RingBuffer& signal){
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
