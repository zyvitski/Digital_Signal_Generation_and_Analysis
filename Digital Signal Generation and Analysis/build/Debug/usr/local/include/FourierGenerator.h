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

namespace DSG {
    
    namespace Fourier{
        /*
         Fourier Generator is designed with built in phasor code for use in genorating classic analog style waveforms using fourier synthesis i.e. additive combination of sine waves based on a fourier series
         */
        
        static DSG::Backend::HarmonicTable _harmonicTable;
        
        /*!\brief A Class Extending The SignalGenerator Class with functionality for generating a wave by summing sinusoids
         */
        class FourierGenerator: public SignalGenerator {
        public:
            FourierGenerator();
            FourierGenerator(double const& frequency,double const& phase_offset);
            virtual ~FourierGenerator();
            
            virtual inline bool Perform(Signal::Sample& signal);
            virtual inline bool Perform(Signal::RingBuffer& signal);
        protected:
            inline unsigned long _maxHarms(double _frq);
            Signal::Sample _sample;
            Signal::Sample _storage;
            
        };
        
        inline bool FourierGenerator::Perform(Signal::Sample& signal){
            signal = 0;
            return false;
        }
        inline bool FourierGenerator::Perform(Signal::RingBuffer& signal){
            signal.Flush();
            return false;
        }
        
                
        inline unsigned long FourierGenerator::_maxHarms(double _frq){
            //double softLim = 0.45;
            //double hardLim = 0.5;
            
            double _s = Signal::Sample_Rate()* (20000.0/Signal::Sample_Rate());//uses harmonic roll of based on max human hearing and sample rate
            _s/=_frq;
            return trunc(_s);
        }
    }
}
#endif /* defined(__Waveform__FourierGenerator__) */
