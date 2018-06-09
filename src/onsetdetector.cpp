//
//  onsetdetector.cpp
//  audi0_v1_1
//
//  Created by Julian on 18/05/2018.
//
//

#include "onsetdetector.h"








float onsetDetection::detection(string numbertest, float detectValue, float input){
    
    
   
    curr_value = input;
    
    time = ofGetElapsedTimef();
    
    if(curr_value > detectValue && last_value < detectValue)
    {

      
        kick = true;
        
        //calculate inteval in seconds between every detected beat
        timeInterval = time - prev_time;


        
       // cout<<"bang"<<endl;
 
        
      
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
            
            cout << "pulse"<<endl;
            cout << pulse<<endl;
            
            if (pulse < detectedInteval - 0.1){
                timeswrong++;
                cout<<"wrong data"<<endl;

                
            }
            
            if (pulse > detectedInteval +0.1 ){
                timeswrong++;
                cout<<"wrong data"<<endl;

                
            }
            
            if (timeswrong == 2){
                onsetData.clear();
                pulseData.clear();
                steadyPulseData.clear();
                avrageFinal.clear();
               
                cout<<"cleared data"<<endl;
               timeswrong = 0;
                
            }
           // pulseData.clear();
            
            
            
            
            if (pulse > detectedInteval - 0.01 && pulse < detectedInteval + 0.01 )
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
                    // steadyPulseData.push_back(steady_pulse);
                 
                 /*
                    switch (state) {
                        case 1:
                            steadyPulseData.push_back(steady_pulse);
                            break;
                        case 2:
                            steadyPulseData.push_back(pulse);
                            break;
                    
                    }
                    */
                    steadyPulseData.push_back(steady_pulse);
                  //  detectedInteval
                }
            
                for (unsigned int i = 0; i< steadyPulseData.size(); i++) {
                    finalpulse =  finalpulse + steadyPulseData[i];
                    }
            
                finalpulse = finalpulse / steadyPulseData.size();
         
                cout<<"finalpulse"<<endl;
                cout<<finalpulse<<endl;
            
            
                finalbpm = 60 / finalpulse;
            if (finalbpm < 70){
                finalbpm = finalbpm *2;
            }
          
            
                cout<<"finalbpm"<<endl;
                cout<<finalbpm<<endl;
            
           // finalbpm= roundf(finalbpm);
                    
           // cout<<"rounded finalbpm"<<endl;
            //cout<<finalbpm<<endl;
            
            //do this to prevent random values to enter into the final bpm
            if (finalbpm > 1)
            {
                
            avrageFinal.push_back(finalbpm);
            
            for (unsigned int i = 0; i< avrageFinal.size(); i++) {
                FinalResult =  FinalResult + avrageFinal[i];
            };
            
            FinalResult = FinalResult / avrageFinal.size();
          
            cout<<" avrage finalbpm"<<endl;
            cout<< avrageFinal.size() <<endl;
            // roundf(FinalResult);
            cout<<FinalResult<<endl;
                if (avrageFinal.size()> 1){
                    
                    cout<<"old result: "<<endl;
                    
                    cout<<FinalResult<<endl;
                   // FinalResult = 60 / detectedInteval;
                    steadyPulseData.clear();
                    
                    cout<<"current:"<<endl;
                    cout<<FinalResult<<endl;
                    
                    
                    bpmOut = FinalResult;
                   // bpmOut =definiteBpm;
                    
                }
             
              //  bpmOut =FinalResult;
                
            }
            
            //reset the avrage vlue to be devided to zero again:
            finalpulse = 0;
         
            average = 0;
            FinalResult = 0;
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

float onsetDetection::getBpm(){
   
    return bpmOut;
    
}



