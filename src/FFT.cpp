//
//  FFT.cpp
//  audi0_v1_1
//
//  Created by Julian on 18/05/2018.
//
//

#include "FFT.h"


fft::fft(){};


fft::~fft(){};

void fft::setup(int bands){
    
    // the fft needs to be smoothed out, so we create an array of floats
    // for that purpose:
    fftsignal = new float[8192];
    for (int i = 0; i < 8192; i++){
        fftsignal[i] = 0;
    }
    
    //definehow many fft bands you want
    fftbands = bands;
   
    
    
}

void fft::update(){
    
    // grab the fft, and put in into the "fftsignal" array
        float * val = ofSoundGetSpectrum(fftbands);
    for (int i = 0;i < fftbands; i++){
        // let the smoothed calue sink to zero:
        fftsignal[i] *= 0.96f;
        
        
        
        
        // take the max, either the smoothed or the incoming:
        if (fftsignal[i] < val[i]) fftsignal[i] = val[i];
        
    }

}


void fft::draw(){
    float width = (float)(5*128) / fftbands;
    for (int i = 0;i < fftbands; i++){
        // (we use negative height here, because we want to flip them
        // because the top corner is 0,0)
        ofDrawRectangle(100+i*width,ofGetHeight()-100,width,-(fftsignal[i] * 200));
    }
    
    
}
/*
float fft::getData(float detectionlevel, int bandnumber){
    curr_value = fftsignal[bandnumber];
    prev_value = curr_value;
    return curr_value;
    
}
 */
