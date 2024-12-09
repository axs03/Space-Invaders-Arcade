//
//  Game.h
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/3/24.
//

#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Player.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Explosion.h"

extern float screenShakeTime;

using namespace std;

void init(Player& player, vector<Enemy>& enemies);
void checkCollisions(vector<Projectile>& bullets,vector<Enemy>& enemies,vector<Explosion>& explosions);

#endif
