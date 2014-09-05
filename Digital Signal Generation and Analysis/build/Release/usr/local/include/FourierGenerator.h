//
//  FourierGenerator.h
//  Waveform
//
//  Created by Alexander Zywicki on 8/20/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __Waveform__FourierGenerator__
#define __Waveform__FourierGenerator__

#include "SignalGenerator.h"
#include "SineLUT.h"
#include "HarmonicTable.h"

namespace Signal {
    
    namespace Fourier{
        /*
         Fourier Generator is designed with built in phasor code for use in genorating classic analog style waveforms using fourier synthesis i.e. additive combination of sine waves based on a fourier series
         */
        static Backend::SineLUT<float, 32768> sine;
        static Backend::HarmonicTable _harmonicTable;
        class FourierGenerator: public SignalGenerator {
        public:
            FourierGenerator();
            FourierGenerator(double const& frequency,double const& phase_offset);
            virtual ~FourierGenerator();
            
            virtual inline bool Perform(Sample& signal);
            virtual inline bool Perform(RingBuffer& signal);
        protected:
            inline unsigned long _maxHarms(double _frq);
            Sample _sample;
            Sample _storage;
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
        };
        
        inline bool FourierGenerator::Perform(Sample& signal){
            signal = 0;
            return false;
        }
        inline bool FourierGenerator::Perform(RingBuffer& signal){
            signal.Flush();
            return false;
        }
        
        inline double FourierGenerator::_pstep(){
            double value = _phasor;
            _phasor+=_frequency;
            _phasor = _phasor-(unsigned long)_phasor;//cheaper %1
            return value;
        }
        inline double FourierGenerator::_pstep_rad(){
            return TWOPI * _pstep();
        }
        inline void FourierGenerator::_psync(){
            _phasor = 0;
        }
        
        inline unsigned long FourierGenerator::_maxHarms(double _frq){
            //double softLim = 0.45;
            //double hardLim = 0.5;
            double _s = Sample_Rate()* 0.45;
            _s/=_frq;
            return trunc(_s);
        }
    }
}
#endif /* defined(__Waveform__FourierGenerator__) */
