//
//  Enemy.cpp
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/2/24.
//

#include "Enemy.h"


using namespace std;

void spawnEnemy(vector<Enemy>& enemies) {
    Enemy enemy = {static_cast<float>(rand() % 750), 580.0f, 50.0f, 50.0f, true};
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
        glRotatef(180.0f, 0.0f, 0.0f, 1.0f); // rotation
        glTranslatef(-enemy.width / 2, -enemy.height / 2, 0.0f);

        
        glColor3f(1.0f, 0.0f, 0.0f); // Red color

        glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(enemy.width, 0.0f);
        glVertex2f(enemy.width, enemy.height);
        glVertex2f(0.0f, enemy.height);
        glEnd();

        glPopMatrix();
    }
}



