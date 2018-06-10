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
    fftsignal = new float[bands];
    for (int i = 0; i < bands; i++){
        fftsignal[i] = 0;
    }
    
    //definehow many fft bands you want
    fftbands = bands;
   
    
    
}

float fft::update(int bands){
    
    // grab the fft, and put in into the "fftsignal" array
        float * val = ofSoundGetSpectrum(fftbands);
    for (int i = 0;i < fftbands; i++){
        // let the smoothed calue sink to zero:
        fftsignal[i] *= 0.86f;
        
        
      
        // take the max, either the smoothed or the incoming:
        if (fftsignal[i] < val[i]) fftsignal[i] = val[i];
        
    }
    //get the fft out of this class in combination with the next line
    float curr_value =  fftsignal[bands];
    
    return curr_value;
   

}


