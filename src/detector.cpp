//
//  detector.cpp
//  audi0_v1_1
//
//  Created by Julian on 18/05/2018.
//
//

#include "detector.h"




void detection::watchBand(int band) {
    curr_value = fftsignal[band];
    prev_value = curr_value;
};