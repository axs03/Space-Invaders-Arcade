//
//  Explosion.cpp
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/4/24.
//

//#include <vector>
#include "/opt/local/include/GL/glut.h"
#include "Explosion.h"
#include <vector>

using namespace std;

void drawExplosion(const Explosion& explosion) {
    if (!explosion.active) return;

    glPushMatrix();
    glTranslatef(explosion.x, explosion.y, 0.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    GLfloat emissionColor[] = {1.0f, 0.5f, 0.0f, 1.0f}; // Orange glow
    glMaterialfv(GL_FRONT, GL_EMISSION, emissionColor);

    glColor4f(1.0f, 0.5f, 0.0f, 0.8f); // Bright orange with transparency
    glutSolidSphere(explosion.radius, 20, 20);

    GLfloat noEmission[] = {0.0f, 0.0f, 0.0f, 1.0f};
    glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
    glDisable(GL_BLEND);
    glPopMatrix();
}

void updateExplosions(vector<Explosion>& explosions) {
    for (auto& explosion : explosions) {
        if (!explosion.active) continue;

        explosion.radius += 2.0f;
        if (explosion.radius > 50.0f) explosion.active = false;
    }
}

void updateExplosionLight(const Explosion& explosion) {
    if (!explosion.active) return;

    GLfloat lightPos[] = {explosion.x, explosion.y, 1.0f, 1.0f};
    GLfloat lightColor[] = {1.0f, 0.5f, 0.0f, 1.0f}; // Orange light

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);

    glLightfv(GL_LIGHT1, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT1, GL_SPECULAR, lightColor);

    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0f);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.1f);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.01f);
}
