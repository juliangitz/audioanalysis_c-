//
//  audioplayer.cpp
//  audioanalysis copy
//
//  Created by Julian on 18/05/2018.
//
//



#include "audioplayer.h"

void audioPlayer::setup(){
    //audio to test algorithm with:
    
    
    //this is  the audio in my data folder of the openframeworks project,
    //to play a sound file you will probably have to add your own files to the data folder and replace the name
    
    
   
    Audio.load("Disko Partizani.mp3");
    
   
    
    //standart audio settings looping and volume
    Audio.setVolume(0.5);
    Audio.setLoop(1);
    //play audio
    Audio.play();
    
}
