//
//  AnalogSquare.h
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/4/14.
//
//

#ifndef Digital_Signal_Generation_and_Analysis_AnalogSquare_h
#define Digital_Signal_Generation_and_Analysis_AnalogSquare_h

#include "AnalogGenerator.h"
namespace DSG {
    class AnalogSquare:public AnalogGenerator{
    public:
        AnalogSquare();
        AnalogSquare(double const& frequency,double const& phase_offset);
        virtual ~AnalogSquare();
        
        virtual inline bool Perform( Sample& signal);
        virtual inline bool Perform( RingBuffer& signal);
    protected:
        float _duty;//0-1.0
        
        
    };
    inline bool AnalogSquare::Perform( Sample& signal){
        double value = _pstep();
        value-=0.5;
        value*=2.0;
        signal = value>=_duty ? -1.0: 1.0;
        return true;
    }
    inline bool AnalogSquare::Perform( RingBuffer& signal){
        signal.Flush();
        while (!signal.Full()) {
            if (Perform(_sample)) {
                if(signal.Write(_sample)){
                }else return false;
            }else return false;
        }return true;
    }
}
#endif
