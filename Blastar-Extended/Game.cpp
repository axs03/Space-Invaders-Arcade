//
//  Game.cpp
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/3/24.
//

#include "Game.h"
#include "Explosion.h"
#include "/opt/local/include/GL/glut.h"

using namespace std;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


void checkCollisions(vector<Projectile>& bullets, vector<Enemy>& enemies, vector<Explosion>& explosions) {
    for (auto& bullet : bullets) {
        if (!bullet.active) continue;

        for (auto& enemy : enemies) {
            if (!enemy.active) continue;

            if (bullet.x < enemy.x + enemy.width &&
                bullet.x + bullet.width > enemy.x &&
                bullet.y < enemy.y + enemy.height &&
                bullet.y + bullet.height > enemy.y) {

                bullet.active = false;
                enemy.active = false;

                explosions.push_back({enemy.x + enemy.width / 2, enemy.y + enemy.height / 2, 10.0f, true});
            }
        }
    }
}

