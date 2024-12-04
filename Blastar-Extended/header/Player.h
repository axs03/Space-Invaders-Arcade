//
//  Player.h
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/3/24.
//

#ifndef PLAYER_H
#define PLAYER_H

struct Player {
    float x, y;
    float width, height;
};

void drawPlayer(const Player& player);
void movePlayer(Player& player, bool leftKeyPressed, bool rightKeyPressed);

#endif
