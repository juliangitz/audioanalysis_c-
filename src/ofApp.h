#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();

	

		ofSoundPlayer 		beat;
		
    

		float 				* fftSmoothed;


		int nBandsToGet;
    
    
        float kickDetect;
    
    float curr_value;
    float last_value;
    
    float kickVolume;
    bool kick;
    
    float circleSize;
    int circleColor;
    float  circleShrink(float x);
    float newsize;
    int circleSides;
    
    
    
};

