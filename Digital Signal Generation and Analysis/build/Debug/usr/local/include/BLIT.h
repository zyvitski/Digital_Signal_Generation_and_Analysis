//
//  BLIT.h
//  Waveform
//
//  Created by Alexander Zywicki on 9/2/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __Waveform__BLIT__
#define __Waveform__BLIT__

#include "SignalGenerator.h"
#include "Taylor.h"
#include "PI.h"
#include <limits>

namespace Signal {
    namespace BLIT{
        
        /*!\brief
         *See file ~/Research/alias-free-digital-synthesis-of-classic-analog-waveforms.pdf for details of concept
         */
        class BLIT:public SignalGenerator {
        public:
            BLIT();
            BLIT(double const& frequency,double const& phase_offset);
            virtual ~BLIT();
            virtual double const& Frequency(double const& value);//get and set frequency in hz
            virtual inline bool Perform(Sample& signal);
            virtual inline bool Perform(RingBuffer& signal);
        protected:
            virtual void updateHarms();
            
            Sample _sample;
            unsigned long _nHarms;
            unsigned long  m_;
            
            
            float phs;
            float tmp;
            float _denominator;
        };
        
        
        
        inline bool BLIT::Perform(Sample& signal){
#warning Needs testing
            phs =_pstep();
            _denominator = sin(phs*TWOPI);
            if (_denominator<=std::numeric_limits<float>::epsilon()) {
                tmp=1.0;
            }else{
                tmp = sin(phs*m_*TWOPI);
                tmp/= m_ * _denominator;
            }
            signal = tmp;
            return true;
        }
        inline bool BLIT::Perform(RingBuffer& signal){
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

#endif /* defined(__Waveform__BLIT__) */
