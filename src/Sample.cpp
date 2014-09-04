//
//  Sample.cpp
//  Oscillators
//
//  Created by Alexander Zywicki on 8/10/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "Sample.h"

Signal::Sample::Sample(){
    _buffer[0]=0;
    _buffer[1]=0;
}
Signal::Sample::Sample(float value){
    *this = value;
}
Signal::Sample::Sample(float c0,float c1){
    _buffer[0]=c0;
    _buffer[1]=c1;
}
Signal::Sample::Sample(Signal::Sample const& samp){
    *this = samp;
}
Signal::Sample& Signal::Sample::operator=(Signal::Sample const& samp){
    _buffer[0]=samp._buffer[0];
    _buffer[1]=samp._buffer[1];
    return *this;
}
Signal::Sample::~Sample(){
    _buffer[0]=0;
    _buffer[1]=0;
}
size_t Signal::Sample::Size()const{
    return CHANNEL_COUNT;
}


Signal::Sample& Signal::Sample::operator=(float const& value){
    _buffer[0]=value;
    _buffer[1]=value;
    return *this;
}
//math

Signal::Sample operator +(Signal::Sample const& s1,Signal::Sample const& s2){
    return  Signal::Sample(s1[0]+s2[0],s1[1]+s2[1]);
}
Signal::Sample operator +(Signal::Sample const& samp,float val){
    return  Signal::Sample(samp[0]+val,samp[1]+val);
}
Signal::Sample operator +(float val,   Signal::Sample const& samp){
    return  Signal::Sample(samp[0]+val,samp[1]+val);
}

Signal::Sample operator -(Signal::Sample const& s1,Signal::Sample const& s2){
    return  Signal::Sample(s1[0]-s2[0],s1[1]-s2[1]);
}
Signal::Sample operator -(Signal::Sample const& samp,float val){
    return  Signal::Sample(samp[0]-val,samp[1]-val);
}
Signal::Sample operator -(float val,   Signal::Sample const& samp){
    return  Signal::Sample(samp[0]-val,samp[1]-val);
}
Signal::Sample operator *(Signal::Sample const& s1,Signal::Sample const& s2){
    return  Signal::Sample(s1[0]*s2[0],s1[1]*s2[1]);
}
Signal::Sample operator *(Signal::Sample const& samp,float val){
    return  Signal::Sample(samp[0]*val,samp[1]*val);
}
Signal::Sample operator *(float val,   Signal::Sample const& samp){
    return  Signal::Sample(samp[0]*val,samp[1]*val);
}
Signal::Sample operator /( Signal::Sample const& s1, Signal::Sample const& s2){
    return  Signal::Sample(s1[0]/s2[0],s1[1]/s2[1]);
}
Signal::Sample operator /(Signal::Sample const& samp,float val){
    return  Signal::Sample(samp[0]/val,samp[1]/val);
}
Signal::Sample operator /(float val,   Signal::Sample const& samp){
    return  Signal::Sample(val/samp[0],val/samp[1]);
}

Signal::Sample& Signal::Sample::operator++(){
    ++(*this)[0];
    ++(*this)[1];
    return *this;
}
Signal::Sample Signal::Sample::operator++(int){
    Sample s = *this;
    ++(*this);
    return s;
}
Signal::Sample& Signal::Sample::operator--(){
    --(*this)[0];
    --(*this)[1];
    return *this;
}
Signal::Sample Signal::Sample::operator--(int){
    Sample s = *this;
    --(*this);
    return s;
}
bool Signal::Sample::operator==(Signal::Sample& samp){
    if (_buffer[0]==samp[0] && _buffer[1]==samp[1]) {
        return true;
    }else return false;
}
bool Signal::Sample::operator !=(Signal::Sample& samp){
    if (!(*this==samp)) {
        return true;
    }else return false;
}
#ifdef DEBUG
std::ostream& Signal::operator<<(std::ostream& os,Signal::Sample& samp){
    for (size_t i=0; i<CHANNEL_COUNT; ++i) {
        os<<samp[i]<<" ";
    }
    return os;
}
#endif
