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
    
    //_____easy test
   
    // Audio.load("kickloop.wav");
   

    //_____normal tests:
   
    //Audio.load("vamp.mp3");
    //Audio.load("profoundExperiences.flac");
   
   
    //_____hard test

    //Audio.load("OrganicPaprika.mp3");
    // Audio.load("04 Disco Boy.mp3");
    Audio.load("08 Rhythm & Sound - Carrier.flac");
    // Audio.load("Disko Partizani.mp3");
    // Audio.load("kick test.wav");
   
    
    //standart audio settings looping and volume
    Audio.setVolume(0.5);
    Audio.setLoop(1);
    //play audio
    Audio.play();
    
}
