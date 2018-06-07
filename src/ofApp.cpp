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
    
   /*
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
    */
    
    
    
    
    
   peak = 0;
    
    
    
    //spectral flux algorithm
    
    spectrum.clear();
    for (int i = 0; i< 10; i++){
        //add the fft values of all the bands to the spectrum vector
        spectrum.push_back(Fourier_transform.update(i));
        
    }
    
    if (dataAvalible == true){
        //flux claculation
        for (unsigned int i = 0; i<spectrum.size(); i++ )
        {
         
            float value = (spectrum[i] - lastSpectrum[i]);
            if (value > 0){
                flux = value;
                spectralFlux.push_back(flux);
            }
            

             // cout<<flux<<endl;
    
        }
        
    }
    
    
    spectralFlux.push_back(flux);
    
    
    lastSpectrum.clear();
    
    for (int i = 0; i< 10; i++){
        //add the prev spectrum data
        lastSpectrum.push_back(spectrum[i]);
        dataAvalible = true;
    }
    
    for (int i = 0; i< spectralFlux.size(); i++){
        float fluxvalue = spectralFlux[1];
      //  cout<< fluxvalue << endl;
    }
    

    peak = 0;
    
    for (int i = 0; i< 10; i++){
        peakFinder.push_back(spectralFlux[i]);
        
    }
    
    for (unsigned int i = 0; i< 10; i++){
        if (peakFinder[i] > peak){
            peak = peakFinder[i];
            
            bigestNumber = i;
            
          
                
        
       
            
            
            chanche =false;
            if( bigestNumber != lastbigestNumber){
            avragenumber.push_back(bigestNumber);
              //  cout<<bigestNumber<<endl;
                chanche =true;
            }
             lastbigestNumber = bigestNumber;
           
        }
       //   cout << "The biggest volume is: " << lastVolumeToCheck << endl;
        
    }
    if (chanche == true)
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
    
   // Fourier_transform.draw();

    float width = (float)10;
    //
    for (int i = 0;i < 10; i++){
        // (we use negative height here, because we want to flip them
        // because the top corner is 0,0)
       // int number;
         ofSetColor(100, 100, 100);
        //number = spectralFlux[i];
        if (i == avrage){
            ofSetColor(255, 255, 255);
           // cout<<"bam"<<endl;
        };
        
        
        ofDrawRectangle(100+i*width,ofGetHeight()-100,width,-(spectralFlux[i] * 200));
     
    }

    
    
    
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
