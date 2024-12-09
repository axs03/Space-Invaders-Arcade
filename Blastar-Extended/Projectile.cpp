//
//  Projectile.cpp
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/3/24.
//

#include "Projectile.h"
#include "/opt/local/include/GL/glut.h"

using namespace std;

void fireBullet(vector<Projectile>& bullets, float playerX, float playerY, float playerWidth) {
    Projectile bullet = {playerX + playerWidth / 2 - 5, playerY + 20, 10, 15, true, 0.0f, 0.0f};
    bullets.push_back(bullet);
}

void updateBullets(vector<Projectile>& bullets) {
    for (auto& bullet : bullets) {
        if (bullet.active) {
            bullet.time += 0.1f;
            bullet.flameTime += 0.1f; // flametime
            bullet.y += 5.0f; // go upwards

            // sinusoidal motion to the x position
            bullet.x += sin(bullet.time * 1.0f) * 1.4f; // freq adjustment

            if (bullet.y > 600.0f) bullet.active = false;
        }
    }
}

void drawBullets(const vector<Projectile>& bullets) {
    for (const auto& bullet : bullets) {
        if (!bullet.active) continue;

        glPushMatrix();
        
        glTranslatef(bullet.x + bullet.width / 2, bullet.y + bullet.height / 2, 0.0f);

        // color for the missile body
        glColor3f(0.8f, 0.8f, 0.8f); // Light gray color

        glBegin(GL_QUADS);
        glVertex2f(-bullet.width / 2, -bullet.height / 2);
        glVertex2f(bullet.width / 2, -bullet.height / 2);
        glVertex2f(bullet.width / 2, bullet.height / 2);
        glVertex2f(-bullet.width / 2, bullet.height / 2);
        glEnd();

        glColor3f(1.0f, 0.0f, 0.0f); // red tip color

        glBegin(GL_TRIANGLES);
        glVertex2f(-bullet.width / 2, bullet.height / 2);
        glVertex2f(bullet.width / 2, bullet.height / 2);
        glVertex2f(0.0f, bullet.height);
        glEnd();
        
        // flame effect
        float flameSize = 10.0f + 5.0f * sin(bullet.flameTime * 10.0f); // Animate flame size
        glColor4f(1.0f, 0.5f, 0.0f, 0.8f); // Orange color with transparency

        glBegin(GL_TRIANGLES);
        glVertex2f(-bullet.width / 4, -bullet.height / 2);
        glVertex2f(bullet.width / 4, -bullet.height / 2);
        glVertex2f(0.0f, -bullet.height / 2 - flameSize);
        glEnd();

        glPopMatrix();
    }
}

