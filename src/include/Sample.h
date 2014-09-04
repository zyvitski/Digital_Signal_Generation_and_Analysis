//
//  Sample.h
//  Oscillators
//
//  Created by Alexander Zywicki on 8/5/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef Oscillators_Sample_h
#define Oscillators_Sample_h

#define CHANNEL_COUNT 2

#include <assert.h>

#ifdef DEBUG
#include <iostream>
#endif

namespace Signal {
    
    
    
    class Sample {
    public:
        Sample();
        Sample(float value);
        Sample(float c0,float c1);
        Sample(Sample const& samp);
        Sample& operator=(Sample const& samp);
        ~Sample();
        size_t Size()const;
        inline float& operator[](const size_t& index);
        inline float const& operator[](const size_t& index)const;
        Sample& operator=(float const& value);
        friend  Sample operator +(Sample const& s1,Sample const& s2);
        friend  Sample operator +(Sample const& samp,float val);
        friend  Sample operator +(float val,   Sample const& samp);
        friend  Sample operator -(Sample const& s1,Sample const& s2);
        friend  Sample operator -(Sample const& samp,float val);
        friend  Sample operator -(float val,   Sample const& samp);
        friend  Sample operator *(Sample const& s1,Sample const& s2);
        friend  Sample operator *(Sample const& samp,float val);
        friend  Sample operator *(float val,   Sample const& samp);
        friend  Sample operator /( Sample const& s1, Sample const& s2);
        friend  Sample operator /(Sample const& samp,float val);
        friend  Sample operator /(float val,   Sample const& samp);
        inline Sample& operator +=(Sample const& samp);
        inline Sample& operator +=(const float& samp);
        inline Sample& operator -=(Sample const& samp);
        inline Sample& operator -=(const float& samp);
        inline Sample& operator *=(Sample const& samp);
        inline Sample& operator *=(const float& samp);
        inline Sample& operator /=(Sample const& samp);
        inline Sample& operator /=(const float& samp);
        Sample& operator++();
        Sample operator++(int);
        Sample& operator--();
        Sample operator--(int);
        bool operator==(Sample& samp);
        bool operator !=(Sample& samp);
#ifdef DEBUG
        friend std::ostream& operator<<(std::ostream& os,Sample& samp);
#endif
    protected:
        float _buffer[CHANNEL_COUNT];
    };
    
    float& Sample::operator[](const size_t& index){
#ifdef DEBUG
        assert(index<CHANNEL_COUNT);
#endif
        return _buffer[index];
    }
    float const& Sample::operator[](const size_t& index)const{
#ifdef DEBUG
        assert(index<CHANNEL_COUNT);
#endif
        return _buffer[index];
    }
    inline Sample& Sample::operator +=(Sample const& samp){
        _buffer[0]+=samp._buffer[0];
        _buffer[1]+=samp._buffer[1];
        return *this;
    }
    inline Sample& Sample::operator +=(const float& samp){
        _buffer[0]+=samp;
        _buffer[1]+=samp;
        return *this;
    }
    inline Sample& Sample::operator -=(Sample const& samp){
        _buffer[0]-=samp._buffer[0];
        _buffer[1]-=samp._buffer[1];
        return *this;
    }
    inline Sample& Sample::operator -=(const float& samp){
        _buffer[0]-=samp;
        _buffer[1]-=samp;
        return *this;
    }
    inline Sample& Sample::operator *=(Sample const& samp){
        _buffer[0]*=samp._buffer[0];
        _buffer[1]*=samp._buffer[1];
        return *this;
    }
    inline Sample& Sample::operator *=(const float& samp){
        _buffer[0]*=samp;
        _buffer[1]*=samp;
        return *this;
    }
    inline Sample& Sample::operator /=(Sample const& samp){
        _buffer[0]/=samp._buffer[0];
        _buffer[1]/=samp._buffer[1];
        return *this;
    }
    inline Sample& Sample::operator /=(const float& samp){
        _buffer[0]/=samp;
        _buffer[1]/=samp;
        return *this;
    }
}
#endif
