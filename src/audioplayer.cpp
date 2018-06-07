//
//  audioplayer.cpp
//  audioanalysis copy
//
//  Created by Julian on 18/05/2018.
//
//

#include "audioplayer.h"

void audioPlayer::setup(){
    
    //easy test
   
  //Audio.load("kickloop.wav");
   

    //more advanced tests:
   
    Audio.load("vamp.mp3");
   
  //  Audio.load("profoundExperiences.flac");
   //Audio.load("08 Rhythm & Sound - Carrier.flac");
    //harder test
   // Audio.load("07-congi_and_jafu-december-mkd.mp3");
    //Audio.load("OrganicPaprika.mp3");
    
    
    Audio.setVolume(0.5);
    Audio.setLoop(1);
    Audio.play();
    
}
