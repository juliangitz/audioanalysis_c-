//
//  audioplayer.cpp
//  audioanalysis copy
//
//  Created by Julian on 18/05/2018.
//
//

#include "audioplayer.h"

void audioPlayer::setup(){
    
    Audio.load("profoundExperiences.flac");
    
    Audio.setVolume(0.5);
    
    Audio.play();
    
}