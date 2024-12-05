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

    glColor4f(1.0, 0.5, 0.0, 0.5); // orange
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(explosion.x, explosion.y); // center
    for (int i = 0; i <= 20; ++i) {
        float angle = i * 2.0f * 3.14159f / 20;
        glVertex2f(explosion.x + explosion.radius * cos(angle),
                   explosion.y + explosion.radius * sin(angle));
    }
    glEnd();
}

void updateExplosions(vector<Explosion>& explosions) {
    for (auto& explosion : explosions) {
        if (!explosion.active) continue;

        explosion.radius += 2.0f;
        if (explosion.radius > 50.0f) explosion.active = false;
    }
}
