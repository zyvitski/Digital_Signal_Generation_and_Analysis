//
//  Taylor.h
//  Waveform
//
//  Created by Alexander Zywicki on 8/30/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __Waveform__Taylor__
#define __Waveform__Taylor__
#include "PI.h"
#include <math.h>
namespace DSG{
    namespace Backend{
        namespace Taylor {
            /*
             Sine Taylor Series expansion to a fixed number of terms
             sin(X) = x - x^3/3! + x^5/5! - x^7/7! + x^9/9!...+x^21/21!
             */
            double Sine(double const& x);//where x 0 - 2pi   
        }
    }
}

#endif /* defined(__Waveform__Taylor__) */
