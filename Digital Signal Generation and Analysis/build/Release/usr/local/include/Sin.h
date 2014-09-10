//
//  Sin.h
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/6/14.
//
//

#ifndef Digital_Signal_Generation_and_Analysis_Sin_h
#define Digital_Signal_Generation_and_Analysis_Sin_h

#include "PI.h"
namespace DSG{
namespace Backend {
#define sin_native 0
#define sin_tay 1
#define sin_lut 2
    
#define sin_impl sin_lut
    //0-1 phase
    
#if sin_impl == sin_native
#include <math.h>
#elif sin_impl == sin_tay
#include "Taylor.h"
#elif sin_impl == sin_lut
#include "SineLUT.h"
#else
#include <math.h>
#endif
    
    
    inline double Sin(double const& phs){
        //phs 0-1
#if sin_impl == sin_native
        return sin(TWOPI * phs);
#elif sin_impl == sin_tay
        return Taylor::Sine(phs*TWOPI);
#elif sin_impl == sin_lut
        static DSG::Backend::SineLUT<float, 32768> sine;
        return sine(phs);
#else
        return sin(TWOPI*phs);
#endif
    }
}
}

#endif
