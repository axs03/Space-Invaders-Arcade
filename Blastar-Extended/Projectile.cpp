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
    Projectile bullet = {playerX + playerWidth / 2 - 5, playerY + 20, 10, 20, true};
    bullets.push_back(bullet);
}

void updateBullets(vector<Projectile>& bullets) {
    for (auto& bullet : bullets) {
        if (bullet.active) {
            bullet.y += 5.0f;
            if (bullet.y > 600.0f) bullet.active = false;
        }
    }
}

void drawBullets(const vector<Projectile>& bullets) {
    for (const auto& bullet : bullets) {
        if (!bullet.active) continue;

        glColor4f(1.0, 1.0, 0.0, 0.5); // yellow
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(bullet.x + bullet.width / 2, bullet.y + bullet.height / 2);
        for (int i = 0; i <= 20; ++i) {
            float angle = i * 2.0f * 3.14159f / 20;
            float radius = bullet.width * 1.5f;
            glVertex2f(bullet.x + bullet.width / 2 + cos(angle) * radius,
                       bullet.y + bullet.height / 2 + sin(angle) * radius);
        }
        glEnd();

        glColor3f(1.0, 0.0, 0.0); // red
        glBegin(GL_QUADS);
        glVertex2f(bullet.x, bullet.y);
        glVertex2f(bullet.x + bullet.width, bullet.y);
        glVertex2f(bullet.x + bullet.width, bullet.y + bullet.height);
        glVertex2f(bullet.x, bullet.y + bullet.height);
        glEnd();
    }
}

