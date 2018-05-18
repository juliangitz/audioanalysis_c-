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
#include "detector.h"

class onsetDetection : public detection
{
public:
 
    
    
    
    void setup(float kickdetect);
    
    void update();
    
    void draw();
    
    
    
    //-----------------
    
    float kickdetect;
    
    bool kick;
    
    
    detection kickanalysis;
//    detection hat;
};



#endif /* onsetdetector_h */
