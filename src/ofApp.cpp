#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(54, 54, 54);
    
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
    

    
    
  
    
    
    //spectral flux algorithm
    
    spectrum.clear();
    for (int i = 0; i< 10; i++){
        //add the fft values of all the bands to the spectrum vector
        spectrum.push_back(Fourier_transform.update(i));
        
    }
    //spectral flux claculation
    
    //do this after having revived the both the current and last value. (so ignore this code the first time )
    if (dataAvalible == true){
   
        for (unsigned int i = 0; i<spectrum.size(); i++ )
        {
            //compare current & last fft spectrum point
            float value = (spectrum[i] - lastSpectrum[i]);
            if (value > 0){
                flux = value;
                spectralFlux.push_back(flux);
            }
        
        }
        
    }
    
    
    spectralFlux.push_back(flux);
    
    //clean out data
    lastSpectrum.clear();
    
    //add the prev spectrum data point
    for (int i = 0; i< 10; i++){
        lastSpectrum.push_back(spectrum[i]);
        dataAvalible = true;
    }
 
    //-------Peak meter
    //this part of the code calculates whitch band to find the onset (bigestNumber)
    //and determine the treshold for the onset detection (peak)
    
    
    //reset peak meter to 0 to recalculate every time
    peak = 0;
    
    //add spectralFlux data for peak analysis
    for (int i = 0; i< 10; i++){
        peakFinder.push_back(spectralFlux[i]);
        
    }
    
    //peak/onset finding algorithm code
    
    for (unsigned int i = 0; i< 10; i++){
        //if current value is bigger than the last mesured biggest peak make the current one the biggest
        if (peakFinder[i] > peak){
            peak = peakFinder[i];
            
            bigestNumber = i;
            
            
            calculateBand = false;
            
            //push the biggest peak number to a vector to calculate the avrage biggest number
            if( bigestNumber != lastbigestNumber){
                
            avragenumber.push_back(bigestNumber);
                //after this code is run the algorithm can start calculating, all the nessesary data has been collected
                calculateBand =true;
                
            }
            
            //pass biggest number on to lastbigestNumber for comperison later
             lastbigestNumber = bigestNumber;
           
        }
      
        
    }
    //algorithm witch calculates witch fft band to find the onset
    
    //this code structure will be used a lot
    //its basicly how I calculate the avrage of a vector
    //here we calculate the avrage band to find the onset
    if (calculateBand == true)
        {
            for (unsigned int i = 0; i< avragenumber.size(); i++) {
                avrage =  avrage + avragenumber[i];
            }
            
    avrage = avrage / avragenumber.size();
    }
    
    //cout<< avrage <<endl;
   /*
    if (avragenumber.size() > 40)
    {
        avragenumber.clear();
        
    }
    */
   // volumeToCheck =  spectralFlux[avrage];
   // for (int i = 0; i< 10; i++){
    
    if (spectralFlux[avrage] > 0.6){
    
    avrageVolumeList.push_back(spectralFlux[avrage]);
        
    //}
   
    
    for (unsigned int i = 0; i< avrageVolumeList.size(); i++) {
        avrageVolume =  avrageVolume + avrageVolumeList[i];
    }
    avrageVolume = avrageVolume / avrageVolumeList.size();
    
    volumeToCheck = avrageVolume -0.2;
    //cout<<avVolume<<endl;
    };
    
   // lastVolumeToCheck = volumeToCheck;
   
    
    //------draw volume
    
    scaledVol = spectralFlux[avrage];
    
    //lets record the volume into an array
    volHistory.push_back( scaledVol );
    
    //if we are bigger the the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }
    
    
    //clean audio
    CleanScaledVol = Fourier_transform.update(avrage);
    
    //lets record the volume into an array
    CleanVolHistory.push_back( CleanScaledVol );
    
    //if we are bigger the the size we want to record - lets drop the oldest value
    if( CleanVolHistory.size() >= 400 ){
        CleanVolHistory.erase(CleanVolHistory.begin(), CleanVolHistory.begin()+1);
    }
    
    
    
    
    
    
    
    //cout<<volumeToCheck<<endl;
    
    
    peakFinder.clear();
   
   //  detect.detection("kick", 0.5, spectralFlux[5]);
   detect.detection("kick", volumeToCheck, spectralFlux[avrage]);
   // detect.detection("kick", lastVolumeToCheck, Fourier_transform.update(bigestNumber));
    
    //spectral flux
    //https://www.badlogicgames.com/wordpress/?p=161


    
 


    
   
    
    spectralFlux.clear();
   
    
    
  }

//--------------------------------------------------------------
void ofApp::draw(){
    
    //code to draw nice looking rectangle shapes on the screen
    ofNoFill();
    ofSetLineWidth(1);
    ofDrawRectangle(0, 451, 400, 150);
   
    
    ofSetLineWidth(1);
    ofDrawRectangle(0, 180, 400, 170);
    
    
    
   // Fourier_transform.draw();
    ofFill();
    float width = (float)20;
    //this part of the code is to
    for (int i = 0;i < 6; i++){

      //this is to color the band number we are curently monitoring white
        
        ofSetColor(100, 100, 100);
        
        if (i == avrage){
            ofSetColor(255, 255, 255);
        };
        
        //draw the fft bands on screen
        ofDrawRectangle(451+i*width,ofGetHeight()-165,width,-(spectralFlux[i] * 200));
     
    }
    
    //code to draw spectral flux processed audio on screen
    ofNoFill();
    ofBeginShape();
    for (unsigned int i = 0; i < volHistory.size(); i++){
        if( i == 0 ) ofVertex(i, 600);
   
  
      
        detectionpoint = 600 - volumeToCheck * 70;
        ofVertex(i, 600 - volHistory[i] * 70);
      
        if( i == volHistory.size() -1 ) ofVertex(i, 600);
       
    }
        ofEndShape(false);
    ofSetColor(200, 100, 100);
    ofDrawLine(0, detectionpoint, 400, detectionpoint);
  
    
 
    //code to draw clean fft band fignal (pre spectral flux processing)
    
    ofBeginShape();
    for (unsigned int i = 0; i < CleanVolHistory.size(); i++){
        if( i == 0 )
        ofVertex(i, 350);
        
        ofVertex(i, 350 - CleanVolHistory[i] * 70);
        
        if( i == CleanVolHistory.size() -1 )
            ofVertex(i, 350);
        
            }
    ofEndShape(false);
    
 
    
    
 //code to draw text to screen
    
    string reportString = "bpm: "+ofToString(detect.getBpm());
    ofDrawBitmapString(reportString, 32, 689);
    string audioString = "procesed audio: ";
    ofDrawBitmapString(audioString, 4, 448);
    string audio = "audio: ";
    ofDrawBitmapString(audio, 4, 175);
    
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
