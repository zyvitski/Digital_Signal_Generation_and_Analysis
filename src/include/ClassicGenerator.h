//
//  ClassicGenerator.h
//  Waveform
//
//  Created by Alexander Zywicki on 8/20/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __Waveform__ClassicGenerator__
#define __Waveform__ClassicGenerator__

#include "SignalGenerator.h"
#include "SineLUT.h"
#include "HarmonicTable.h"

namespace Signal {
    
    
    /*
     Classic Generator is designed with built in phasor code for use in genorating classic analog style waveforms
     */
    static Backend::SineLUT<float, 32768> sine;
    static Backend::HarmonicTable _harmonicTable;
    class ClassicGenerator: public SignalGenerator {
    public:
        ClassicGenerator();
        ClassicGenerator(double const& frequency,double const& phase_offset);
        virtual ~ClassicGenerator();
        
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
    
    inline bool ClassicGenerator::Perform(Sample& signal){
        signal = 0;
        return false;
    }
    inline bool ClassicGenerator::Perform(RingBuffer& signal){
        signal.Flush();
        return false;
    }
    
    inline double ClassicGenerator::_pstep(){
        double value = _phasor;
        _phasor+=_frequency;
        _phasor = _phasor-(unsigned long)_phasor;//cheaper %1
        return value;
    }
    inline double ClassicGenerator::_pstep_rad(){
        return TWOPI * _pstep();
    }
    inline void ClassicGenerator::_psync(){
        _phasor = 0;
    }
    
    inline unsigned long ClassicGenerator::_maxHarms(double _frq){
        //double softLim = 0.45;
        //double hardLim = 0.5;
        double _s = Sample_Rate()* 0.45;
        _s/=_frq;
        return trunc(_s);
    }
}
#endif /* defined(__Waveform__ClassicGenerator__) */
