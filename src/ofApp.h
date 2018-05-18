#pragma once

#include "ofMain.h"

//include audio player
#include "audioplayer.h"

//include fft analysis
#include "FFT.h"

//include onsetdetection algorithm
#include "onsetdetector.h"



#include "detector.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
        //make an instance of the audio player class
        audioPlayer sound;
    
        //create an instance of the fast fouier transform class
        fft Fourier_transform;
    
 
};
