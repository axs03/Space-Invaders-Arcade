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

    GLfloat emissionColor[] = {0.5f, 0.5f, 1.0f, 1.0f}; // Blue glow
    glMaterialfv(GL_FRONT, GL_EMISSION, emissionColor);

    glBindTexture(GL_TEXTURE_2D, player.textureID);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(player.width, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(player.width, player.height);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, player.height);
    glEnd();

    GLfloat noEmission[] = {0.0f, 0.0f, 0.0f, 1.0f};
    glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    drawPlayerAura(player);
}


float glowIntensity = 0.5f;
bool increasing = true;

void updateGlowIntensity() {
    if (increasing) {
        glowIntensity += 0.01f;
        if (glowIntensity >= 1.0f) increasing = false;
    } else {
        glowIntensity -= 0.01f;
        if (glowIntensity <= 0.5f) increasing = true;
    }
}

void drawPlayerAura(const Player& player) {
    glPushMatrix();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    glColor4f(0.5f, 0.5f, 1.0f, glowIntensity);
    float auraRadius = player.width * 1.5f;

    glTranslatef(player.x + player.width / 2.0f, player.y + player.height / 2.0f, 0.0f);
    glutSolidSphere(auraRadius, 150, 150);
    glDisable(GL_BLEND);

    glPopMatrix();
}


void updatePlayerLight(const Player& player) {
    GLfloat lightPos[] = {player.x + player.width / 2.0f, player.y + player.height / 2.0f, 1.0f, 1.0f};
    GLfloat lightColor[] = {0.5f, 0.5f, 1.0f, 1.0f}; // Soft blue light
    GLfloat ambientColor[] = {0.2f, 0.2f, 0.5f, 1.0f};

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT2); // Use a unique light slot

    glLightfv(GL_LIGHT2, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT2, GL_AMBIENT, ambientColor);
    glLightfv(GL_LIGHT2, GL_SPECULAR, lightColor);
}

void movePlayer(Player& player, bool leftKeyPressed, bool rightKeyPressed) {
    if (leftKeyPressed) player.x -= 5.0f; // left
    if (rightKeyPressed) player.x += 5.0f; // right

    // bounds
    if (player.x < 0) player.x = 0;
    if (player.x > 800 - player.width) player.x = 800 - player.width;
}
