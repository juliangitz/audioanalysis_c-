//
//  onsetdetector.cpp
//  audi0_v1_1
//
//  Created by Julian on 18/05/2018.
//
//

#include "onsetdetector.h"








void onsetDetection::detection(string numbertest, float detectValue, float input){
    
    
   
    curr_value = input;
    
  
    
    if(curr_value > detectValue && last_value < detectValue)
    {

        
        std::cout<<numbertest<<std::endl;
        kick = true;
        
        //bpm algorithm
        
        time = ofGetElapsedTimef();
  
        //ofResetElapsedTimeCounter();
        
        //calculate inteval in seconds between every detected beat
        timeInterval = time - prev_time;
        std::cout<<timeInterval<<std::endl;
        
        
        
      
        //create some error margine
        if (prev_timeInterval > timeInterval - 0.1 && prev_timeInterval < timeInterval + 0.1){
            std::cout<<"bpm match"<<std::endl;
           
            
            //TODO:
            //mesure i++ when elepsed time is 60 seconds give i and reset to 0?
            
        }
        prev_timeInterval = timeInterval;
        prev_time = time;
         //  ofResetElapsedTimeCounter();
        
        
    }
 
    
    if(last_value < detectValue)
    {
        kick = false;
        
    }
    
    //put this at the end of the code to make the current value the last one (again and again)
    last_value = curr_value;
    
    
}


