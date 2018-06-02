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
    
    time = ofGetElapsedTimef();
    
    if(curr_value > detectValue && last_value < detectValue)
    {

       // std::cout<<numbertest<<std::endl;
        kick = true;
        
        //bpm algorithm
        
       
  
        //ofResetElapsedTimeCounter();
        
        //calculate inteval in seconds between every detected beat
        timeInterval = time - prev_time;
      //  std::cout<<timeInterval<<std::endl;
        
        
        
      
        //create some error margine
        if (prev_timeInterval > timeInterval - 0.1 && prev_timeInterval < timeInterval + 0.1){
           //std::cout<<"bpm match"<<std::endl;
            
            std::cout<<timeInterval<<std::endl;
            detectedInteval =timeInterval;
            counter++;
            //TODO:
            //mesure i++ when elepsed time is 60 seconds give i and reset to 0?
            
        }
        if (counter == 2){
            
        }
        
        
        
        //std::cout<<time<<std::endl;
        //if (time > minute){
        if (counter == 2){
           // std::cout<<"bpm is"<<std::endl;
            
            bpm = 60 / detectedInteval;
            
           // counter = counter * 30;
           // std::cout<<bpm<<std::endl;
            //set bmp detection for next minute
            //minute = minute + 2;
            //reset bpm counter to 0
            counter = 0;
            detectiontimes++;
            lastbpm = bpm;
        }
        
        if (detectiontimes == 2)
        {
            
            finalBpm = bpm + lastbpm;
            finalBpm = finalBpm/2;
            std::cout<<"final bpm is"<<std::endl;
            std::cout<<finalBpm<<std::endl;
            
            detectiontimes = 0;
        }
        
        
        prev_timeInterval = timeInterval;
        prev_time = time;
       
        
        
    }
 
    
    if(last_value < detectValue)
    {
        kick = false;
        
    }
    
    //put this at the end of the code to make the current value the last one (again and again)
    last_value = curr_value;
    
    
}


