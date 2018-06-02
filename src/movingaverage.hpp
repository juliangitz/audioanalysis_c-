//
//  movingaverage.hpp
//  audi0_v1_1
//
//  Created by Julian on 02/06/2018.
//

#ifndef movingaverage_hpp
#define movingaverage_hpp

//include openframeworks libs
#include "ofMain.h"

class movingAverage {
    
public:
    
    movingAverage();
    ~movingAverage();
    
//    std::vector <float> buffer;
    

  
    
    void addDetection(float val);
    
    float average();
    
    unsigned int period;
    
    
    
private:
    
    
    
};

#endif /* movingaverage_hpp */
