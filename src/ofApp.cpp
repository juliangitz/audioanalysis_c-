#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //seting up soundfile and playing it back
    sound.setup();
    
    //set up the fft and give the amound of bands to look at
    Fourier_transform.setup(8);
    

    

    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    // update the sound playing system
    //NOTE: is this needed?
    ofSoundUpdate();
    
    Fourier_transform.update();
 //   Fourier_transform.getData(0.5, 0);
//  Fourier_transform.getData(0.5, 3);
 //   kick.watchBand(1);
 //   hat.watchBand(3);
    
    
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
