//
//  Game.h
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/3/24.
//

#ifndef GAME_H
#define GAME_H

#include <vector>
#include "player.h"
#include "projectile.h"
#include "enemy.h"

void init();
void checkCollisions(vector<Projectile>& bullets, vector<Enemy>& enemies);

#endif
