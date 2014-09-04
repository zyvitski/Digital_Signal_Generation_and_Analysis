//
//  Taylor.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 8/30/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "Taylor.h"


//sin(X) = x - x^3/3! + x^5/5! - x^7/7! + x^9/9!...+x^21/21!
/*
based on audible performance the LUT method for a sine wave is faster compared to this method.
 TO DO:
    Consider replacing pow function.(done)
    investigate if using pre computed 1.0/n factorials would work better than hoping that the compiler will handle it.
 */
double Backend::Taylor::Sine(double const& x){
    double phs = fabs(x);//range checking
    phs = fmod(phs,TWOPI);//range checking
    double val=phs;//term 1
    
    //instead of using a pow() function we are calculatig the running power by using the multiply acculmulate function.
    //it may look ugly but it should be faster
    phs*=x;
    phs*=x;
    val-=(phs * (1.0/6.0));
    phs*=x;
    phs*=x;
    val+=(phs *(1.0/120.0));
    phs*=x;
    phs*=x;
    val-=(phs *(1.0/5040.0));
    phs*=x;
    phs*=x;
    val+=(phs *(1.0/362880.0));
    phs*=x;
    phs*=x;
    val-=(phs*(1.0/39916800.0));
    phs*=x;
    phs*=x;
    val+=(phs*(1.0/6227020800.0));
    phs*=x;
    phs*=x;
    val-=(phs*(1.0/1307674368000.0));
    phs*=x;
    phs*=x;
    val+=(phs*(1.0/355687428096000.0));
    phs*=x;
    phs*=x;
    val-=(phs*(1.0/121645100408832000.0));
    phs*=x;
    phs*=x;
    val+=(phs*(1.0/51090942171709440000.0));
    //the hope is that the compiler is smart enough to evaluate 1.0/... at compile time be cause it will always be the same
    
    return val;
}
/*
double Taylor::Sine(double const& x,double const& n){
    double val=x;
    double phs = fabs(x);
    char sign = -1;
    phs = fmod(phs,TWOPI);
    int trm = 3;
    for (int i=1; i<n; ++i) {
        val+= sign* term(phs, trm);
        sign*=-1;
        trm+=2;
    }
    return val;  
}*/

