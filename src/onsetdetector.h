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


//include the detector polymorphism class
//#include "detector.h"

class onsetDetection
{
public:
 
    //vector to calculate the moving average
    vector<float> onsetData;
    
    int timeswrong = 0;
    
    vector<float> pulseData;
    float pulseAverage =0;
    float pulse;
    float pulseInterval;
    float steady_pulse;
    vector <float>  steadyPulseData;
    float finalpulse =0;
    float finalbpm = 0;
    float prev_pulse;
    
    
   
  //  float detectInterval;
  //  float perv_detectInterval;
    
    
    
    float average = 0 ;
    float size= 0;
    
    void detection(string numbertest,float detectValue, float input);
    

    
    float curr_value;
    float last_value;
    
    bool kick;
    
    float time;
    float prev_time;
    float  timeInterval;
    float  prev_timeInterval;
   // float rememberInterval;
    float detectedInteval;
    float bpm;
   // float lastbpm;
    float finalBpm;
    
    //to count the beats in a minute
  
    int counter = 0;
   // int detectiontimes = 0;
    
};



#endif /* onsetdetector_h */
