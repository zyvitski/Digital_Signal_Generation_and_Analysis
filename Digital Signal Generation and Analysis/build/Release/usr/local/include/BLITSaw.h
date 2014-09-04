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

namespace Signal {
    namespace BLIT{
        
        
        class BLITSaw:public BLIT::BLIT {
            BLITSaw();
            BLITSaw(double const& frequency,double const& phase_offset);
            virtual ~BLITSaw();
            virtual double const& Frequency(double const& value);//get and set frequency in hz
            virtual inline bool Perform(Sample& signal);
            virtual inline bool Perform(RingBuffer& signal);
        protected:
            virtual void updateHarms();
            
            
        };
        
        inline bool BLITSaw::Perform(Sample& signal){
#warning unimplimented BLITSaw Perform
            return true;
        }
        inline bool BLITSaw::Perform(RingBuffer& signal){
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
#endif /* defined(__Waveform__BLITSaw__) */
