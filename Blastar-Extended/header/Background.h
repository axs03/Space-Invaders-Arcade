//
//  Background.h
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/8/24.
//

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "/opt/local/include/GL/glut.h"
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Star {
    float x, y;     // pos
    float speed;    // speed
    float size;     // size
};

void initStars(int numStars);
void updateStars();
void drawStars();

#endif
