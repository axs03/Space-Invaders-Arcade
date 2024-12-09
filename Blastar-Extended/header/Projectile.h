//
//  Projectile.h
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/3/24.
//

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <vector>

using namespace std;

struct Projectile {
    float x, y, width, height;
    bool active;
    float time;
    float flameTime;
};

void fireBullet(vector<Projectile>& bullets, float playerX, float playerY, float playerWidth);
void updateBullets(vector<Projectile>& bullets);
void drawBullets(const vector<Projectile>& bullets);

#endif
