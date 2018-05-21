//
//  FFT.h
//  audi0_v1_1
//
//  Created by Julian on 18/05/2018.
//
//

#ifndef FFT_h
#define FFT_h

//include openframeworks libs
#include "ofMain.h"

class fft {
public:
    
    
    fft();
    
    ~fft();
    //
    float * fftsignal;
    
    //defines the amound of bands the fft is using
    int fftbands;
    
    //make a function for the setup
    void setup(int bands);
    
    //make a function for the update
    float update(int bands);
    
    //make a function for the draw
    void draw();
    
    
    //float getData(float detectionlevel, int bandnumber);
        
    //float to mesure current fft data point
    //float curr_value;
    //float to mesure previous fft data point
    //float prev_value;
    
};


#endif /* FFT_h */
