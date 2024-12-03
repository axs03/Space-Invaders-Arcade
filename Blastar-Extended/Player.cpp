//
//  Player\.cpp
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/2/24.
//

#include "Player.h"
#include "/opt/local/include/GL/glut.h"

void drawPlayer(const Player& player) {
    glBegin(GL_POLYGON);
    glVertex2f(player.x, player.y);
    glVertex2f(player.x + player.width, player.y);
    glVertex2f(player.x + player.width, player.y + player.height);
    glVertex2f(player.x, player.y + player.height);
    glEnd();
}

void movePlayer(Player& player, char direction) {
    if (direction == 'a') player.x -= 10.0f; // left
    if (direction == 'd') player.x += 10.0f; // right
}
