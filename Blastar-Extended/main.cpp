//
//  main.cpp
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/2/24.
//

#include "/opt/local/include/GL/glut.h"
#include "Player.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Game.h"
#include "Explosion.h"
#include "utils.h"
#include "TextureLoader.h"

using namespace std;

Player player = {400.0f, 50.0f, 50.0f, 50.0f};
vector<Projectile> bullets;
vector<Enemy> enemies;
vector<Explosion> explosions;

bool leftKeyPressed = false;
bool rightKeyPressed = false;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawPlayer(player, 180);
    drawBullets(bullets);
    drawEnemies(enemies);

    // Draw explosions
    for (const auto& explosion : explosions) {
        updateExplosionLight(explosion);
        drawExplosion(explosion);
    }

    glFlush();
}

void timer(int value) {
    movePlayer(player, leftKeyPressed, rightKeyPressed);
    updateBullets(bullets);
    updateEnemies(enemies);
    updateExplosions(explosions);

    checkCollisions(bullets, enemies, explosions);

    if (rand() % 100 < 5) {
        spawnEnemy(enemies);
    }
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void keyboardDown(unsigned char key, int x, int y) {
    if (key == 'a') leftKeyPressed = true;
    if (key == 'd') rightKeyPressed = true;
    if (key == ' ') fireBullet(bullets, player.x, player.y, player.width);
}

void keyboardUp(unsigned char key, int x, int y) {
    if (key == 'a') leftKeyPressed = false;
    if (key == 'd') rightKeyPressed = false;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Blastar Extended");

    init(player, enemies);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    glutTimerFunc(16, timer, 0);

    glutMainLoop();
    return 0;
}

