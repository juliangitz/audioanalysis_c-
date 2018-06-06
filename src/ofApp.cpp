#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //TODO: add algorythm that looks if pres detaction is simular to current detection
    
    
    
    //seting up soundfile and playing it back
    sound.setup();
    
    //set up the fft and give the amound of bands to look at
    Fourier_transform.setup(1024);
    

    
    
    bool kick = false;
    
    
};

//--------------------------------------------------------------
void ofApp::update(){
    // update the sound playing system
    //NOTE: is this needed?
    ofSoundUpdate();
    
    
    peak = 0;
    
    for (int i = 0; i< 10; i++){
        peakFinder.push_back(Fourier_transform.update(i));
       
        }
    
    for (unsigned int i = 0; i< peakFinder.size(); i++){
        if (peakFinder[i] > peak){
            peak = peakFinder[i];
            bigestNumber = i;
            volumeToCheck = Fourier_transform.update(bigestNumber);
            volumeToCheck = volumeToCheck - 0.8;
            lastVolumeToCheck = volumeToCheck;
        }
  //  cout << "The biggest volume is: " << volumeToCheck << endl;
   
    }
    
    
    
    
   peak = 0;
    
   /*
    for (int i = 0; i< 512; i++){
        if (peakFinder[i] > peak){
            peak = i;
        }
     cout << "The biggest number is: " << peak << endl;
        
    }
    */
    
    peakFinder.clear();
    
    
    //   Fourier_transform.getData(0.5, 0);
//  Fourier_transform.getData(0.5, 3);
 //   kickanalysis.watchBand(1);
 //   hat.watchBand(3);
   //std::cout<<Fourier_transform.update(0)<<std::endl;
    
    //this is just to test it out but get som better text in here than 1, 2, 3
    
    
    detect.detection("kick", lastVolumeToCheck, Fourier_transform.update(bigestNumber));
    
    
   // detect.detection("kick", 0.6, Fourier_transform.update(0));
    // detect.detection("3", 0.1, Fourier_transform.update(5));
    
    
  }

//--------------------------------------------------------------
void ofApp::draw(){
    
    Fourier_transform.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
