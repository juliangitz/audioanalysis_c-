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

      
        kick = true;
        
        //calculate inteval in seconds between every detected beat
        timeInterval = time - prev_time;

        
        
      
        //create some error margine
        if (prev_timeInterval > timeInterval - 0.1 && prev_timeInterval < timeInterval + 0.1){
           //std::cout<<"bpm match"<<std::endl;
            
            std::cout<<timeInterval<<std::endl;
            detectedInteval =timeInterval;
            
            bpm = 60 / detectedInteval;
            //add detected inteval to the onset vector
            onsetData.push_back(bpm);
            
        
            
            for (unsigned int i = 0; i< onsetData.size(); i++) {
                average =  average + onsetData[i];
            }
            //cout << "size"<<endl;
            //cout << size<<endl;
            average = average / onsetData.size();
            cout << "average"<<endl;
            cout << average<<endl;
            
            average = 0;
            //cout the amound of onsets detected
            counter++;
            
            
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



