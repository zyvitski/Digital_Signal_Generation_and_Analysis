//
//  SignalProcess.h
//  Waveform
//
//  Created by Alexander Zywicki on 8/20/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __Waveform__SignalProcess__
#define __Waveform__SignalProcess__

#include "Backend.h"

namespace Signal {
    class SignalProcess {
    public:
        SignalProcess();
        virtual ~SignalProcess();
        virtual inline bool Perform(Sample& signal)=0;
        virtual inline bool Perform(RingBuffer& signal)=0;
    };
}



#endif /* defined(__Waveform__SignalProcess__) */
