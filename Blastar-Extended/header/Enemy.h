//
//  Enemy.h
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/3/24.
//

#ifndef ENEMY_H
#define ENEMY_H

#include "/opt/local/include/GL/glut.h"
#include <vector>
#include <cstdlib>

using namespace std;

struct Enemy {
    float x, y, width, height;
    bool active;
};

void spawnEnemy(vector<Enemy>& enemies);
void updateEnemies(vector<Enemy>& enemies);
void drawEnemies(const vector<Enemy>& enemies);

#endif
