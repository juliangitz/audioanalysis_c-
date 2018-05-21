//
//  onsetdetector.h
//  audi0_v1_1
//
//  Created by Julian on 18/05/2018.
//
//

#ifndef onsetdetector_h
#define onsetdetector_h

//include openframeworks libs
#include "ofMain.h"



//include the detector polymorphism class
//#include "detector.h"

class onsetDetection
{
public:
 
    
  
    void detection(string numbertest,float detectValue, float input);
    
   
    
    float curr_value;
    float last_value;
    
    bool kick;
    
    float time;
    float prev_time;
    float  timeInterval;
    float  prev_timeInterval;
    
};



#endif /* onsetdetector_h */
