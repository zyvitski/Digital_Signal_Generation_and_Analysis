//
//  Square.h
//  Digital Signal Generation and Analysis
//
//  Created by Alexander Zywicki on 9/3/14.
//
//

#ifndef Digital_Signal_Generation_and_Analysis_Square_h
#define Digital_Signal_Generation_and_Analysis_Square_h

#include "ClassicGenerator.h"

namespace Signal {
    
    
    class Square: public ClassicGenerator {
    public:
        Square();
        Square(double const& frequency,double const& phase_offset);
        virtual ~Square();
        virtual inline bool Perform(Sample& signal);
        virtual inline bool Perform(RingBuffer& signal);
        virtual double const& Frequency(double const& value);
        virtual double const& Frequency();
    protected:
        unsigned long _h;
        double _a;
        double tmp;
        double stor;
        double iPI;
        unsigned short i;
    };
    
    inline bool Square::Perform(Sample& signal){
#warning Unimplimented Square Perform
        return true;
    }
    inline bool Square::Perform(RingBuffer& signal){
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
