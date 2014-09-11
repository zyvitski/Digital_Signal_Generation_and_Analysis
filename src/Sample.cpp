//
//  Sample.cpp
//  Oscillators
//
//  Created by Alexander Zywicki on 8/10/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#include "Sample.h"
DSG:: Sample::Sample(){
    _buffer[0]=0;
    _buffer[1]=0;
}
DSG:: Sample::Sample(float value){
    *this = value;
}
DSG:: Sample::Sample(float c0,float c1){
    _buffer[0]=c0;
    _buffer[1]=c1;
}
DSG:: Sample::Sample(DSG:: Sample const& samp){
    *this = samp;
}
DSG:: Sample& DSG:: Sample::operator=(DSG:: Sample const& samp){
    _buffer[0]=samp._buffer[0];
    _buffer[1]=samp._buffer[1];
    return *this;
}
DSG:: Sample::~Sample(){
    _buffer[0]=0;
    _buffer[1]=0;
}
size_t DSG:: Sample::Size()const{
    return CHANNEL_COUNT;
}
DSG:: Sample& DSG:: Sample::operator=(float const& value){
    _buffer[0]=value;
    _buffer[1]=value;
    return *this;
}
//math
DSG:: Sample operator +(DSG:: Sample const& s1,DSG:: Sample const& s2){
    return  DSG:: Sample(s1[0]+s2[0],s1[1]+s2[1]);
}
DSG:: Sample operator +(DSG:: Sample const& samp,float val){
    return  DSG:: Sample(samp[0]+val,samp[1]+val);
}
DSG:: Sample operator +(float val,   DSG:: Sample const& samp){
    return  DSG:: Sample(samp[0]+val,samp[1]+val);
}

DSG:: Sample operator -(DSG:: Sample const& s1,DSG:: Sample const& s2){
    return  DSG:: Sample(s1[0]-s2[0],s1[1]-s2[1]);
}
DSG:: Sample operator -(DSG:: Sample const& samp,float val){
    return  DSG:: Sample(samp[0]-val,samp[1]-val);
}
DSG:: Sample operator -(float val,   DSG:: Sample const& samp){
    return  DSG:: Sample(samp[0]-val,samp[1]-val);
}
DSG:: Sample operator *(DSG:: Sample const& s1,DSG:: Sample const& s2){
    return  DSG:: Sample(s1[0]*s2[0],s1[1]*s2[1]);
}
DSG:: Sample operator *(DSG:: Sample const& samp,float val){
    return  DSG:: Sample(samp[0]*val,samp[1]*val);
}
DSG:: Sample operator *(float val,   DSG:: Sample const& samp){
    return  DSG:: Sample(samp[0]*val,samp[1]*val);
}
DSG:: Sample operator /( DSG:: Sample const& s1, DSG:: Sample const& s2){
    return  DSG:: Sample(s1[0]/s2[0],s1[1]/s2[1]);
}
DSG:: Sample operator /(DSG:: Sample const& samp,float val){
    return  DSG:: Sample(samp[0]/val,samp[1]/val);
}
DSG:: Sample operator /(float val,   DSG:: Sample const& samp){
    return  DSG:: Sample(val/samp[0],val/samp[1]);
}
DSG:: Sample& DSG:: Sample::operator++(){
    ++(*this)[0];
    ++(*this)[1];
    return *this;
}
DSG:: Sample DSG:: Sample::operator++(int){
    Sample s = *this;
    ++(*this);
    return s;
}
DSG:: Sample& DSG:: Sample::operator--(){
    --(*this)[0];
    --(*this)[1];
    return *this;
}
DSG:: Sample DSG:: Sample::operator--(int){
    Sample s = *this;
    --(*this);
    return s;
}
bool DSG:: Sample::operator==(DSG:: Sample& samp){
    if (_buffer[0]==samp[0] && _buffer[1]==samp[1]) {
        return true;
    }else return false;
}
bool DSG:: Sample::operator !=(DSG:: Sample& samp){
    if (!(*this==samp)) {
        return true;
    }else return false;
}
#ifdef DEBUG
std::ostream& DSG:: operator<<(std::ostream& os,DSG:: Sample& samp){
    for (size_t i=0; i<CHANNEL_COUNT; ++i) {
        os<<samp[i]<<" ";
    }
    return os;
}
#endif