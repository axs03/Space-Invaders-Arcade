//
//  Explosion.h
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/4/24.
//

#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <vector>

using namespace std;

struct Explosion {
    float x, y;
    float radius;
    bool active;
};

void drawExplosion(const Explosion& explosion);
void updateExplosions(vector<Explosion>& explosions);

#endif
