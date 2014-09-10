//
//  HarmonicTable.h
//  Waveform
//
//  Created by Alexander Zywicki on 8/26/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef Waveform_HarmonicTable_h
#define Waveform_HarmonicTable_h

#include "LUT.h"
#include <math.h>
#ifdef DEBUG
#include <assert.h>
#endif
namespace DSG{
    namespace Backend{
        class HarmonicTable {
        public:
            HarmonicTable();
            ~HarmonicTable();
            inline double const& Saw(unsigned short const& index);
            inline double const& Triangle(unsigned short const& index);
        protected:
            double _saw[8192];
            double _triangle[8192];
            const short _size=8192;
            inline void fillSaw();
            inline void fillTri();
        };
        
        inline double const& HarmonicTable::Saw(unsigned short const& index){
#ifdef DEBUG
            assert(index<_size);
#endif
            return _saw[index];
        }
        inline double const& HarmonicTable::Triangle(unsigned short const& index){
#ifdef DEBUG
            assert(index<_size);
#endif
            return _triangle[index];
        }
    }
}
#endif
