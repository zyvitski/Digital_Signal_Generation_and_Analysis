//
//  SignalProcess.h
//  Waveform
//
//  Created by Alexander Zywicki on 8/20/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __Waveform__SignalProcess__
#define __Waveform__SignalProcess__

/*!\file SignalProcess.h
 *
 */

#include "Backend.h"
namespace DSG{
    
    /*! \brief An Abstract Base Class defining the basics API needed for audio generation
     */
    class SignalProcess {
        
    public:
        SignalProcess();
        virtual ~SignalProcess();
        virtual inline bool Perform( Sample::Sample& signal)=0;
        virtual inline bool Perform( RingBuffer& signal)=0;
    };
    
}



#endif /* defined(__Waveform__SignalProcess__) */
