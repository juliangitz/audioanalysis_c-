//
//  FFT.h
//  audi0_v1_1
//
//  Created by Julian on 18/05/2018.
//
//

#ifndef FFT_h
#define FFT_h

//this class is based on the code from the openframeworks sound fft examples
//openframeworks/examples/sound/soundPlayerFFTExample

//include openframeworks libs
#include "ofMain.h"

class fft {
public:
    
    
    fft();
    
    ~fft();
    
    float * fftsignal;
    
    //defines the amound of bands the fft is using
    int fftbands;
    
    //make a function for the setup
    void setup(int bands);
    
    //make a function for the update
    float update(int bands);
    
 
    

};


#endif /* FFT_h */
