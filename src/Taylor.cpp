//
//  Taylor.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 8/30/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "Taylor.h"
//sin(X) = x - x^3/3! + x^5/5! - x^7/7! + x^9/9!...+x^21/21!
double DSG::Taylor::Sine(double const& x){
    double phs = x<0 ?1.0-(-1*x):x;
    while (phs>TWOPI) {
        phs-=TWOPI;
    }
    double val=phs;//term 1
    //instead of using a pow() function we are calculatig the running power by using the multiply acculmulate function.
    //it may look ugly but it should be faster
    phs*=x;
    phs*=x;
    val-=(phs * 0.1666666666666666666666666666666666666666666666666666);
    phs*=x;
    phs*=x;
    val+=(phs * 0.0083333333333333333333333333333333333333333333333333);
    phs*=x;
    phs*=x;
    val-=(phs * 0.0001984126984126984126984126984126984126984126984126);
    phs*=x;
    phs*=x;
    val+=(phs * 0.0000027557319223985890652557319223985890652557319223);
    phs*=x;
    phs*=x;
    val-=(phs * 0.0000000250521083854417187750521083854417187750521083);
    phs*=x;
    phs*=x;
    val+=(phs * 0.0000000001605904383682161459939237717015494793272571);
    phs*=x;
    phs*=x;
    val-=(phs * 0.0000000000007647163731819816475901131985788070444155);
    phs*=x;
    phs*=x;
    val+=(phs * 0.0000000000000028114572543455207631989455830103200162);
    phs*=x;
    phs*=x;
    val-=(phs * 0.0000000000000000082206352466243297169559812368722807);
    phs*=x;
    phs*=x;
    val+=(phs * 0.0000000000000000000195729410633912612308475743735054);
    return val;
}