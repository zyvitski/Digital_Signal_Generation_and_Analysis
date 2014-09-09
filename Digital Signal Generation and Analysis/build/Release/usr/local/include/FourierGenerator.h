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
        
        /*!\brief A Class Extending The SignalGenerator Class with functionality for generating a wave by summing sinusoids
         */
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
            
        };
        
        inline bool FourierGenerator::Perform(Sample& signal){
            signal = 0;
            return false;
        }
        inline bool FourierGenerator::Perform(RingBuffer& signal){
            signal.Flush();
            return false;
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
