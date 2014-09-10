//
//  FourierSaw.h
//  Waveform
//
//  Created by Alexander Zywicki on 8/21/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __Waveform__FourierSaw__
#define __Waveform__FourierSaw__

#include "FourierGenerator.h"
#include "Sin.h"

namespace DSG {
 
        
        /*!\brief Fourier Series Based Saw Wave
         */
        class FourierSaw: public FourierGenerator {
        public:
            FourierSaw();
            FourierSaw(double const& frequency,double const& phase_offset);
            virtual ~FourierSaw();
            virtual inline bool Perform( Sample& signal);
            virtual inline bool Perform( RingBuffer& signal);
            virtual double const& Frequency(double const& value);
            virtual double const& Frequency();
        protected:
            unsigned long _h;
            double _a;
            double phs;
            double stor;
            double _tmp;
            double iPI;
            unsigned short i;
        };
        
        inline bool FourierSaw::Perform( Sample& signal){
     
            stor=0;
            for (i=1; i<_h; ++i) {
                _tmp=DSG::Backend::Sin(_phasor*i);
                _tmp*=_harmonicTable.Saw(i);
                stor += _tmp ;
            }
            _pstep();
            stor*= _a;
            signal=stor;
            return true;
        }
        inline bool FourierSaw::Perform( RingBuffer& signal){
            signal.Flush();
            while (!signal.Full()) {
                if (Perform(_sample)) {
                    if(signal.Write(_sample)){
                    }else return false;
                }else return false;
            }return true;
        }
    
}

#endif /* defined(__Waveform__FourierSaw__) */
