//
//  Enemy.cpp
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/2/24.
//

#include "Enemy.h"
#include "/opt/local/include/GL/glut.h"
#include <cstdlib>

using namespace std;

void spawnEnemy(std::vector<Enemy>& enemies) {
    Enemy enemy = {static_cast<float>(rand() % 750), 580.0f, 50.0f, 50.0f, true};
    enemies.push_back(enemy);
}

void updateEnemies(std::vector<Enemy>& enemies) {
    for (auto& enemy : enemies) {
        if (enemy.active) {
            enemy.y -= 2.0f;
            if (enemy.y < 0.0f) enemy.active = false;
        }
    }
}

void drawEnemies(const std::vector<Enemy>& enemies) {
    for (const auto& enemy : enemies) {
        if (enemy.active) {
            glColor3f(1.0, 0.0, 0.0);
            float radius = enemy.width / 2;

            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(enemy.x + radius, enemy.y + radius); // center
            for (int i = 0; i <= 20; ++i) {
                float angle = i * 2.0f * 3.14159f / 20;
                glVertex2f(enemy.x + radius + radius * cos(angle), enemy.y + radius + radius * sin(angle));
            }
            glEnd();
        }
    }
}

