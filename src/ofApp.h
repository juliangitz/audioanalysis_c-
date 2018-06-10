#pragma once

#include "ofMain.h"

//include audio player
#include "audioplayer.h"

//include fft analysis
#include "FFT.h"

//include onsetdetection algorithm
#include "onsetdetector.h"





class ofApp : public ofBaseApp{

	public:
    
    //basic openframework functions to keep the system running
		void setup();
		void update();
		void draw();

	
    
    
    //make an instance of the audio player class
        audioPlayer sound;
    
    //create an instance of the fast fouier transform class
        fft Fourier_transform;
     //create an instance of the onset detection class
        onsetDetection detect;
    
    //peek finder
    vector<int> avrageBandNumber;
    int avrageBand;
    bool calculateBand =false;
    
    vector<float> peakFinder;
    float peak = 0;
    int lastbigestNumber = 0;
    int bigestNumber = 0;
    float volumeToCheck = 0;
    
    vector<float> avrageVolumeList;
    float avrageVolume;
 
    
    //spectral flux
    vector <float> spectrum;
    vector <float> lastSpectrum;
    
    float flux = 0;
    
    vector<float> spectralFlux;
    
    bool dataAvalible = false;
    
    float lastVolumeToCheck =0;

    //------draw volume
    vector <float> volHistory;
    float AmplitudeVol = 0.0;
    float detectionpoint = 0.0;
    
    vector <float> CleanVolHistory;
    float CleanScaledVol = 0.0;
    
    

    
 
};
