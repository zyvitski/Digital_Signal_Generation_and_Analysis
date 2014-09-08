//
//  SignalGenerator.h
//  Waveform
//
//  Created by Alexander Zywicki on 8/20/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __Waveform__SignalGenerator__
#define __Waveform__SignalGenerator__


#include "SignalProcess.h"

namespace Signal {
    
    /*!\brief A Base Class extending the SignalProcess API with functionality for signal generation
     */
    
    class SignalGenerator: public SignalProcess {
    public:
        SignalGenerator();
        SignalGenerator(double const& frequency,double const& phase_offset);
        virtual ~SignalGenerator();
        
        virtual inline bool Perform(Sample& signal);
        virtual inline bool Perform(RingBuffer& signal);
        
        virtual double const& Frequency()const;//get frequency in Hz
        virtual double const& Frequency(double const& value);//get and set frequency in hz
        virtual double const& PhaseOffset()const;
        virtual double const& PhaseOffset(double const& value);
    protected:
        double _frequency;//in percent sample rate 0.0 - 1.0
        double _fHertz;//in hertz
        double _phase_offset;//Phase Offset 0-1 cycles
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
    
    
    inline bool SignalGenerator::Perform(Sample& signal){
        signal = 0;
        return false;
    }
    inline bool SignalGenerator::Perform(RingBuffer& signal){
        signal.Flush();
        return false;
    }
    inline double SignalGenerator::_pstep(){
        double value = _phasor;
        _phasor+=_frequency;
        _phasor = _phasor-(unsigned long)_phasor;//cheaper %1
        return value;
    }
    inline double SignalGenerator::_pstep_rad(){
        return TWOPI * _pstep();
    }
    inline void SignalGenerator::_psync(){
        _phasor = 0;
    }

}


#endif /* defined(__Waveform__SignalGenerator__) */
