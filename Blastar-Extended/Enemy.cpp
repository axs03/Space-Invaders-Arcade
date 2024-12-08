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
    glEnable(GL_TEXTURE_2D);

    for (const auto& enemy : enemies) {
        if (!enemy.active) continue;

        glPushMatrix();
        
        
        glTranslatef(enemy.x + enemy.width / 2, enemy.y + enemy.height / 2, 0.0f);

        // Rotate 180 degrees
        glRotatef(180.0f, 0.0f, 0.0f, 1.0f);

        
        glTranslatef(-enemy.width / 2, -enemy.height / 2, 0.0f);

        glBindTexture(GL_TEXTURE_2D, enemy.textureID);

        
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex2f(enemy.width, 0.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex2f(enemy.width, enemy.height);
        glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, enemy.height);
        glEnd();

        glPopMatrix();
    }

    glDisable(GL_TEXTURE_2D);
}



