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
            
            
            
            //double Sine(double const& x,double const& n);
            inline int factorial(int const& i){
                int val=i;
                int cnt=i;
                while (cnt>1) {
                    --cnt;
                    val*=cnt;
                }
                return val;
            }
            inline double term(double const& x,double const& n){
                return (pow(x, n)/(double)Taylor::factorial(n));
            }
        }
    }
}

#endif /* defined(__Waveform__Taylor__) */
