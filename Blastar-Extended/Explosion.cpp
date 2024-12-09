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

    glColor4f(1.0f, 0.5f, 0.0f, 0.8f); // Bright orange with transparency
    glutSolidSphere(explosion.radius, 20, 20);

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

