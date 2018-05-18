//
//  detector.h
//  audi0_v1_1
//
//  Created by Julian on 18/05/2018.
//
//

#ifndef detector_h
#define detector_h

//include openframeworks libs
#include "ofMain.h"

#include "FFT.h"


//make a polymorphic class to detect different bands
class detection : public fft {
public:
    void watchBand(int band);
    
    
 
   
protected:
      //to messure current value
    float curr_value;
    //to mesure previous value
    float prev_value;
    
};


#endif /* detector_h */
