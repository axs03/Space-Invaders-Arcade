//
//  Game.cpp
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/3/24.
//

#include "Game.h"
#include "/opt/local/include/GL/glut.h"

using namespace std;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glColor3f(1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0); // (0,0) to (800,600)
}

void checkCollisions(vector<Projectile>& bullets, vector<Enemy>& enemies) {
    for (auto& bullet : bullets) {
        for (auto& enemy : enemies) {
            if (bullet.active && enemy.active &&
                bullet.x < enemy.x + enemy.width && bullet.x + bullet.width > enemy.x &&
                bullet.y < enemy.y + enemy.height && bullet.y + bullet.height > enemy.y) {
                bullet.active = false;
                enemy.active = false;
            }
        }
    }
}
