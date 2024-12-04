//
//  Player.cpp
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/2/24.
//

#include "Player.h"
#include "/opt/local/include/GL/glut.h"

void drawPlayer(const Player& player) {
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(player.x, player.y);
    glVertex2f(player.x + player.width / 2, player.y + player.height);
    glVertex2f(player.x + player.width, player.y);
    glEnd();
}


void movePlayer(Player& player, bool leftKeyPressed, bool rightKeyPressed) {
    if (leftKeyPressed) player.x -= 5.0f; // left
    if (rightKeyPressed) player.x += 5.0f; // right

    // bounds
    if (player.x < 0) player.x = 0;
    if (player.x > 800 - player.width) player.x = 800 - player.width;
}
