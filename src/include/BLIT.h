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
            
            //------------------------------------------------------------------------------------//
            /*
             Built in Phasor.
             Internal use only.
             */
            double _phasor;
            inline double _pstep();//ramp wave from 0.0-1.0 based on frequency and phase offset
            inline double _pstep_rad();//ramp wave from 0.0 -2pi based on frequency and phase offset
            inline void _psync();//sets phasor back to 0.0 for use doing hard sync
            //------------------------------------------------------------------------------------//
            
            float phs;
            float tmp;
            float _denominator;
        };
        
        
        
        inline bool BLIT::Perform(Sample& signal){
            phs =Backend::Taylor::Sine(_pstep_rad());
            _denominator = phs;
            if (_denominator<=std::numeric_limits<float>::epsilon()) {
                tmp=1.0;
            }else{
                tmp = Backend::Taylor::Sine(phs*m_);
                tmp/= m_* _denominator;
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
        
        inline double BLIT::_pstep(){
            double value = _phasor;
            _phasor+=_frequency;
            _phasor = _phasor-(unsigned long)_phasor;//cheaper %1
            return value;
        }
        inline double BLIT::_pstep_rad(){
            return TWOPI * _pstep();
        }
        inline void BLIT::_psync(){
            _phasor = 0;
        }
    }
}

#endif /* defined(__Waveform__BLIT__) */
