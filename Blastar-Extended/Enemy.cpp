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

void spawnEnemy(vector<Enemy>& enemies) {
    Enemy enemy = {static_cast<float>(rand() % 750), 580.0f, 50.0f, 20.0f, true};
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
        if (enemy.active) {
            glBegin(GL_POLYGON);
            glVertex2f(enemy.x, enemy.y);
            glVertex2f(enemy.x + enemy.width, enemy.y);
            glVertex2f(enemy.x + enemy.width, enemy.y + enemy.height);
            glVertex2f(enemy.x, enemy.y + enemy.height);
            glEnd();
        }
    }
}
