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
#include <vector>




class onsetDetection
{
public:
 
   
    
  
    
    
    //buffers and values that are used in the algotithm
  
    //vector to calculate the moving average
    vector<float> onsetData;
    
   
    float pulse;
   
    float steady_pulse;
    
    
    vector <float>  steadyPulseData;
    float finalpulse =0;
    float finalbpm = 0;
    float average = 0 ;
   
    
    
    
    //audio data point values
    float curr_value;
    float last_value;
    
    
    //time calculation values
    float time;
    float prev_time;
    float  timeInterval;
    float  prev_timeInterval;

    float detectedInteval;
   
 
   
   
    vector <float> avrageFinal;
    float FinalResult=0;
    float bpmOut = 0;

    //to calculate the times the calculated data is wrong
    int timeswrong = 0;

    //----------functions
    
    //the main algorithm function
    void detection(float detectValue, float input);
    //to return the final bpm
    float getBpm();

    


    
    
    
};



#endif /* onsetdetector_h */
