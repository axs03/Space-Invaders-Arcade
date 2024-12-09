//
//  Player.cpp
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/2/24.
//

#include "Player.h"
#include "/opt/local/include/GL/glut.h"
#include <cmath>

void drawPlayer(const Player& player, float rotationAngle) {
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();

    glTranslatef(player.x + player.width / 2, player.y + player.height / 2, 0.0f);
    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-player.width / 2, -player.height / 2, 0.0f);

    glBindTexture(GL_TEXTURE_2D, player.textureID);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(player.width, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(player.width, player.height);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, player.height);
    glEnd();

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void movePlayer(Player& player, bool leftKeyPressed, bool rightKeyPressed) {
    if (leftKeyPressed) player.x -= 5.0f; // left
    if (rightKeyPressed) player.x += 5.0f; // right

    // bounds
    if (player.x < 0) player.x = 0;
    if (player.x > 800 - player.width) player.x = 800 - player.width;
}
