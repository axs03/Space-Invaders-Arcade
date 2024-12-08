//
//  Player.h
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/3/24.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "/opt/local/include/GL/glut.h"

struct Player {
    float x, y;
    float width, height; 
    GLuint textureID;
};

void drawPlayer(const Player& player, float rotationAngle);
void movePlayer(Player& player, bool leftKeyPressed, bool rightKeyPressed);

#endif
