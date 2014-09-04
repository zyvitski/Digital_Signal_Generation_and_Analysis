//
//  Driver.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 8/25/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//


#include "Driver.h"
PaStream* stream;

#define BUFFER_SIZE 4096

Signal::RingBuffer _buffer(BUFFER_SIZE);


int DriverInit(void * data){
    PaError err=0;
    
    err=Pa_Initialize();
    if (err!=paNoError) {
        printf(  "PortAudio error: %s\n", Pa_GetErrorText( err ) );
        return 1;
    }
    err = Pa_OpenDefaultStream(&stream, 0, 2, paFloat32,Signal::Sample_Rate(), BUFFER_SIZE, Callback, data);
    if (err!=paNoError) {
        printf(  "PortAudio error: %s\n", Pa_GetErrorText( err ) );
        return 1;
    }
    err = Pa_StartStream(stream);
    if (err!=paNoError) {
        printf(  "PortAudio error: %s\n", Pa_GetErrorText( err ) );
        return 1;
    }
    return 0;
}
int DriverExit(){
    PaError err=0;
    err = Pa_StopStream(stream);
    if (err!=paNoError) {
        printf(  "PortAudio error: %s\n", Pa_GetErrorText( err ) );
        return 1;
    }
    err = Pa_CloseStream( stream );
    if( err != paNoError ){
        printf(  "PortAudio error: %s\n", Pa_GetErrorText( err ) );
    }
    err = Pa_Terminate();
    if( err != paNoError ){
        printf(  "PortAudio error: %s\n", Pa_GetErrorText( err ) );
    }
    return 0;
}

int Callback( const void *input,
             void *output,
             unsigned long frameCount,
             const PaStreamCallbackTimeInfo* timeInfo,
             PaStreamCallbackFlags statusFlags,
             void *userData) {
    float* _in = (float*)input;
    float* _out = (float*)output;
    Signal::Sample _sample;
    int count=0;
    Signal::SignalProcess* _osc = (Signal::SignalProcess*)userData;
    if (_in!=nullptr) {
        while (!_buffer.Full()) {
            for (int i=0; i<_sample.Size(); ++i) {
                _sample[i]=_in[count++];
            }
            _buffer.Write(_sample);
        }
    }
    _osc->Perform(_buffer);
    if (_out!=nullptr) {
        for (int i=0; i<frameCount; ++i) {
            _buffer.Read(_sample);
            *_out++=_sample[0];
            *_out++=_sample[1];
        }
    }
    return 0;
}