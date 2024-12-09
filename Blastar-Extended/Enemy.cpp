//
//  Enemy.cpp
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/2/24.
//

#include "Enemy.h"


using namespace std;

void spawnEnemy(vector<Enemy>& enemies) {
    Enemy enemy = {static_cast<float>(rand() % 750), 580.0f, 25.0f, 25.0f, true};
    enemies.push_back(enemy);
}

void updateEnemies(vector<Enemy>& enemies) {
    for (auto& enemy : enemies) {
        if (enemy.active) {
            enemy.y -= 2.0f;
            if (enemy.y < 0.0f) enemy.active = false;
        }
    }
}


void drawEnemies(const vector<Enemy>& enemies) {
    for (const auto& enemy : enemies) {
        if (!enemy.active) continue;

        glPushMatrix();
        
        glTranslatef(enemy.x + enemy.width / 2, enemy.y + enemy.height / 2, 0.0f);

        // rotation
        static float rotationAngle = 0.0f;
        rotationAngle += 1.0f;
        glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);

        // color for the enemy
        glColor3f(0.5f, 1.0f, 0.0f); // Green color

        glBegin(GL_QUADS);
        glVertex2f(-enemy.width / 2, -enemy.height / 2);
        glVertex2f(enemy.width / 2, -enemy.height / 2);
        glVertex2f(enemy.width / 2, enemy.height / 2);
        glVertex2f(-enemy.width / 2, enemy.height / 2);
        glEnd();

        int numSegments = 20;
        float radius = enemy.width / 2;
        float angleStep = 3.14159f / numSegments;

        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, enemy.height / 2);
        for (int i = 0; i <= numSegments; ++i) {
            float angle = i * angleStep;
            glVertex2f(cos(angle) * radius, enemy.height / 2 + sin(angle) * radius);
        }
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, -enemy.height / 2);
        for (int i = 0; i <= numSegments; ++i) {
            float angle = i * angleStep;
            glVertex2f(cos(angle) * radius, -enemy.height / 2 - sin(angle) * radius);
        }
        glEnd();

        glPopMatrix();
    }
}
