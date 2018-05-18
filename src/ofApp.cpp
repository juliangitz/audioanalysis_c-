#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){	 

    
    
        //set the side resolution of the circle here:
   // ofSetCircleResolution(80);
    
    
	// load in sounds:
	beat.load("sounds/profoundExperiences.flac");

    
    
    

	// the fft needs to be smoothed out, so we create an array of floats
	// for that purpose:
	fftSmoothed = new float[8192];
	for (int i = 0; i < 8192; i++){
		fftSmoothed[i] = 0;
	}
	//definehow many fft bands you want
	nBandsToGet = 8;
    
    //play sample
    beat.play();
    
    
    kickDetect = 0.5;
    kickVolume = 0.0;
    kick = false;
    
    newsize = 0;
    circleSides = 4;

}




//--------------------------------------------------------------
void ofApp::update(){
	
	

	// update the sound playing system:
	ofSoundUpdate();	
	

    //set sample volume
	beat.setVolume(1);


	// (5) grab the fft, and put in into a "smoothed" array,
	//		by taking maximums, as peaks and then smoothing downward
	float * val = ofSoundGetSpectrum(nBandsToGet);		// request 128 values for fft
	for (int i = 0;i < nBandsToGet; i++){
        		// let the smoothed calue sink to zero:
		fftSmoothed[i] *= 0.96f;
        
        
    

		// take the max, either the smoothed or the incoming:
		if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
		
	}
    //print the 1st fft band volume value
    // std::cout<<fftSmoothed[0]<<std::endl;
    curr_value = fftSmoothed[0];
    
    last_value;
    
    
    if(curr_value > kickDetect && last_value < kickDetect)
    {
        std::cout<<"KICK"<<std::endl;
        
    
    }
    if(curr_value > kickDetect)
    {
        kick = true;
        
        
    }
    if(last_value < kickDetect)
    {
        kick = false;
        
        
    }
 
    //else(std::cout<<"noKICK"<<std::endl);
    
    //make last value cuur calue
    last_value = curr_value;
    
    
    kickVolume = ofMap(curr_value, 0.0, 0.17, 0.0, 1.0, true);
    circleColor = ofMap(curr_value, 0.0, 1.0, 0, 225, true);
    //circleSides = ofRandom(4, 10);
    circleSides = 80;

   // std::cout<<circleColor<<std::endl;
  
    
}



//--------------------------------------------------------------
void ofApp::draw(){
    ofSetCircleResolution(circleSides);
    ofBackground(200,80,circleColor);
	ofEnableAlphaBlending();
		ofSetColor(circleColor,255,255,100);
		ofDrawRectangle(100,ofGetHeight()-300,5*128,200);
	ofDisableAlphaBlending();
	
	// draw the fft resutls:
	ofSetColor(255,255,255,255);
	
	float width = (float)(5*128) / nBandsToGet;
	for (int i = 0;i < nBandsToGet; i++){
		// (we use negative height here, because we want to flip them
		// because the top corner is 0,0)
		ofDrawRectangle(100+i*width,ofGetHeight()-100,width,-(fftSmoothed[i] * 200));
	}
    //circle resizing part
    ofSetColor(circleColor, 58, circleColor);
    //ofFill();
    ofDrawCircle(200, 200, circleSize * 190.0f);
        //ofSetColor(245, 58, 135);
   // ofSetColor(245, 58, circleColor);
   
    if (kick == true) {
        circleSize = curr_value;
        newsize = curr_value;
    }
    if (kick == false){
        if (newsize > 0) {
          newsize = newsize -0.05;
        }
        else (newsize = 0);
        
        circleSize = newsize;
    };
    
    
        
    

}


