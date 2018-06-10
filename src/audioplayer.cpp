//
//  audioplayer.cpp
//  audioanalysis copy
//
//  Created by Julian on 18/05/2018.
//
//

//TODO: fix arangement of peaking volume in inteface

#include "audioplayer.h"

void audioPlayer::setup(){
    
    //easy test
   
 // Audio.load("kickloop.wav");
   

    //more advanced tests:
   
    //Audio.load("vamp.mp3");
    
 //   Audio.load("profoundExperiences.flac");
   
   
    //harder test

    //Audio.load("OrganicPaprika.mp3");
    //Audio.load("04 Disco Boy.mp3");
  //  Audio.load("08 Rhythm & Sound - Carrier.flac");
    Audio.load("Disko Partizani.mp3");
    Audio.setVolume(0.5);
    Audio.setLoop(1);
    Audio.play();
    
}
