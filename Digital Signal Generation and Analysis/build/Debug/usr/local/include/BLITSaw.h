//
//  BLITSaw.h
//  Waveform
//
//  Created by Alexander Zywicki on 9/3/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __Waveform__BLITSaw__
#define __Waveform__BLITSaw__

#include "BLIT.h"

namespace DSG {
    /*!\brief
     *See file ~/Research/alias-free-digital-synthesis-of-classic-analog-waveforms.pdf for details of concept
     */
    class BLITSaw:public DSG::BLIT {
        BLITSaw();
        BLITSaw(double const& frequency,double const& phase_offset);
        virtual ~BLITSaw();
        virtual double const& Frequency(double const& value);//get and set frequency in hz
        virtual inline bool Perform( Sample& signal);
        virtual inline bool Perform( RingBuffer& signal);
    protected:
        virtual void updateHarms();
        float a_;
        float p_;
        float state_;
        float C2_;
        
    };
    inline bool BLITSaw::Perform( Sample& signal){
#warning Untested BLITSaw Perform
        
        phs =_pstep();
        _denominator = sin(phs*TWOPI);
        if (_denominator<=std::numeric_limits<float>::epsilon()) {
            tmp=a_;
        }else{
            tmp = sin(phs*m_*TWOPI);
            tmp/= p_ * _denominator;
        }
        tmp+=state_-C2_;
        state_  = tmp * 0.995;
        signal = tmp;
        return true;
    }
    inline bool BLITSaw::Perform( RingBuffer& signal){
        signal.Flush();
        while (!signal.Full()) {
            if (Perform(_sample)) {
                if(signal.Write(_sample)){
                }else return false;
            }else return false;
        }return true;
    }
}
#endif /* defined(__Waveform__BLITSaw__) */