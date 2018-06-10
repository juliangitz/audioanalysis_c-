//
//  onsetdetector.cpp
//  audi0_v1_1
//
//  Created by Julian on 18/05/2018.
//
//

#include "onsetdetector.h"







//the core of the bpm detection algorithm is inside of this function:
//pass in detection value and audio input
void onsetDetection::detection(float detectValue, float input){
    
    
    //mesure input
    curr_value = input;
    
    //messure elapsed time for bpm estimation
    time = ofGetElapsedTimef();
    
    //first layer onset detection layer - is the last value below and the current above the threshold? then go on to the next step
    if(curr_value > detectValue && last_value < detectValue)
    {

        //calculate inteval in seconds between every detected onset
        timeInterval = time - prev_time;

        //create some error margine for the next detection layer
        //second detection layer - if there is a detection calculate the avrage with previous detection results
        if (prev_timeInterval > timeInterval - 0.05 && prev_timeInterval < timeInterval + 0.05)
            {
           
            
                detectedInteval = timeInterval;
            
                cout<< detectedInteval <<endl;
            
                //add detected inteval to the onset vector
                onsetData.push_back(detectedInteval);
            
                //calculate avrage
                for (unsigned int i = 0; i< onsetData.size(); i++)
                    {
                        averageInterval =  averageInterval + onsetData[i];
                    }
            
            
                averageInterval = averageInterval / onsetData.size();
           
            
            
                //check the avrage pulse, if its below the curently detected inteval to many times we have to recalculate everything,
                //there might have been a bpm chanche.
            
                //these functions signal a wrong detection above and below the current detected input amplitude
            
                if (averageInterval < detectedInteval - 0.1)
                    {
                        
                        timeswrong++;
                        cout<<"wrong data"<<endl;
                
                    }
            
                if (averageInterval > detectedInteval +0.1 )
                    {
                        timeswrong++;
                        cout<<"wrong data"<<endl;
    
                    }
            
            
                //it the detection is wrong to many times clear out al the buffers to recalculate the system (set everything to 0 basicly)
                if (timeswrong == 1)
                    {
                        onsetData.clear();
                        //  pulseData.clear();
                        steadyPulseData.clear();
                        avrageFinal.clear();
                
                        //reset counter
                        timeswrong = 0;
               
                    
                    }
          
            
            
            
                //thirt layer of onset detection
                //this time there is a smaller error margin so now les detected values will be able to make it trough
                //basicly detects if there is an interval witch would have a steady pulse with the previous messured intervals
                if (averageInterval > detectedInteval - 0.01 && averageInterval < detectedInteval + 0.01 )
                    {
                
                
                //steady pulse is now the steady messured inteval
                steady_pulse= timeInterval;
                
                cout<<"bpm steady pulse"<<endl;
                cout<<steady_pulse<<endl;
               
              
                
            }
            
          
         
                //check the steady_pulse interval with this last detected interval with a small error margin
                if (steady_pulse > prev_timeInterval - 0.01 && steady_pulse < prev_timeInterval + 0.01 )
                    {
                       
                        steadyPulseData.push_back(steady_pulse);
                
                    }
            
                //calculate the avarage again:
                for (unsigned int i = 0; i< steadyPulseData.size(); i++)
                    {
                    
                        finalpulse =  finalpulse + steadyPulseData[i];
                    
                    }
            
                finalpulse = finalpulse / steadyPulseData.size();
         
                cout<<"finalpulse"<<endl;
                cout<<finalpulse<<endl;
            
                //devide the final bpm value by 60 to get the bpm from detected the inteval
                finalbpm = 60 / finalpulse;
            
                //I will asume that the bpm will always be above 65 to make sure that if the result is 60 instead of 120 it would still tell me 120 bpm
                if (finalbpm < 65)
                {
                    
                    finalbpm = finalbpm *2;
                    
                }
          
            
               
            
            
                //do this to prevent random values to enter into the final bpm
                if (finalbpm > 1)
                    {
                        //calculate avrage again and push to vector
                        avrageFinal.push_back(finalbpm);
            
                        for (unsigned int i = 0; i< avrageFinal.size(); i++)
                            {
                                FinalResult =  FinalResult + avrageFinal[i];
                            };
            
                FinalResult = FinalResult / avrageFinal.size();
          
            
                        cout<<" avrage finalbpm"<<endl;
                        cout<< avrageFinal.size() <<endl;
                   
                        //if the avrage result is bigger than 0 start returning the bpm
                        if (avrageFinal.size()> 0)
                            {
                                //unless its above 200 bpm (im asuming thats not going to be the case to prevent big values to enter into the bpm out
                                if (FinalResult<200)
                                {
                    
                                    bpmOut = FinalResult;
                                    
                                }
                            }
                
                        if (avrageFinal.size()> 1)
                            {
                 
                                //if correct twice reset the buffer and start counting the bpm
                                steadyPulseData.clear();
      
                            }
               
                        }
            
                //reset some values to be run again next "interation" of the code
            
                //reset the avrage vlue to be devided to zero again:
                finalpulse = 0;
                averageInterval = 0;
                FinalResult = 0;
           

            
            }
          
    
        //set some numbers to remember for next time (to do compatisions)
        prev_timeInterval = timeInterval;
        prev_time = time;
       
       
        
    }
 
    
  
    //put this at the end of the code to make the current value the last one (again and again)
    last_value = curr_value;
    
    
}

//function to return the bpm
float onsetDetection::getBpm()
    {
        //return bpm
        return bpmOut;
    }



