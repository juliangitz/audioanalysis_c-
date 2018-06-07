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


        
        cout<<"bang"<<endl;
 
        
      
        //create some error margine
        if (prev_timeInterval > timeInterval - 0.05 && prev_timeInterval < timeInterval + 0.05){
           //std::cout<<"bpm match"<<std::endl;
            

            detectedInteval =timeInterval;
            
            cout<< detectedInteval <<endl;
            
          //  bpm = 60 / detectedInteval;
            
            //add detected inteval to the onset vector
            onsetData.push_back(detectedInteval);
            
            
            for (unsigned int i = 0; i< onsetData.size(); i++) {
                average =  average + onsetData[i];
            }
            
            //cout << "size"<<endl;
            //cout << size<<endl;
            average = average / onsetData.size();
           // cout << "average"<<endl;
           // cout << average<<endl;
            
            
            
            //ckeck if interval has a steady puslse
            pulseData.push_back(average);
            
            for (unsigned int i = 0; i< pulseData.size(); i++) {
                pulseAverage =  pulseAverage + pulseData[i];
            }
            pulseAverage = pulseAverage / pulseData.size();
            bpm = 60 / pulseAverage;
           // pulseAverage = pulseAverage / 10;
           // pulseAverage = 60 / pulseAverage;
            
          /*
            //if the data is bigger then 10 clear the whole list and count again
            if (pulseData.size() > 10){
                pulseData.clear();
            }
           */
           // cout << "bpm"<<endl;
           // cout << bpm<<endl;
          //  cout << pulseAverage<<endl;
           //  cout << "timeInterval"<<endl;
           // cout << timeInterval<<endl;
          
            pulse =pulseAverage;
            
          //  cout << "pulse"<<endl;
           // cout << pulse<<endl;
            
         
            
            
            
            
            
            
            if (average > timeInterval - 0.01 && average < timeInterval + 0.01 )
            {
                cout<<"bpm stady pulse"<<endl;
                steady_pulse= timeInterval;
                cout<<steady_pulse<<endl;
               
                counter = 0;
                
                
            }
            
                  /*
            else{
                   counter++;
                    }
            
            if (counter == 10){
                cout<<"hoi"<<endl;
                onsetData.clear();
                pulseData.clear();
            }
             */
            
         
            
                if (steady_pulse > prev_timeInterval - 0.01 && steady_pulse < prev_timeInterval + 0.01 )
                {
                    cout<<"bpm stady pulse"<<endl;
                    steadyPulseData.push_back(steady_pulse);
                }
            
                for (unsigned int i = 0; i< steadyPulseData.size(); i++) {
                    finalpulse =  finalpulse + steadyPulseData[i];
                    }
            
                finalpulse = finalpulse / steadyPulseData.size();
         
                cout<<"finalpulse"<<endl;
                cout<<finalpulse<<endl;
            
            
                finalbpm = 60 / finalpulse;
            
          
            
                cout<<"finalbpm"<<endl;
                cout<<finalbpm<<endl;
                    
            
            
            
            
            
            finalpulse = 0;
            average = 0;
            
            pulseAverage = 0;
            //cout the amound of onsets detected
         
            
       
        }
          
    
        
        prev_pulse = pulse;
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



