#pragma once

#include "ofMain.h"

//include audio player
#include "audioplayer.h"

//include fft analysis
#include "FFT.h"

//include onsetdetection algorithm
#include "onsetdetector.h"
//#include "detector.h"


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
    
        onsetDetection detect;
    
    //peek finder
    vector<int> avragenumber;
    int avrage;
    bool chanche =false;
    
    vector<float> peakFinder;
    float peak = 0;
      int lastbigestNumber = 0;
    int bigestNumber = 0;
    
    
    float volumeToCheck = 0;
    vector<float> avrageVolumeList;
    float avrageVolume;
    
    float lastVolumeToCheck =0;
    
    //spectral flux
    vector <float> spectrum;
    vector <float> lastSpectrum;
    float flux = 0;
    vector<float> spectralFlux;
    bool dataAvalible = false;
    

    //------draw volume
    vector <float> volHistory;
    float scaledVol = 0.0;
    float detectionpoint = 0.0;
    
    
    vector <float> CleanVolHistory;
    float CleanScaledVol = 0.0;
    
 
};
