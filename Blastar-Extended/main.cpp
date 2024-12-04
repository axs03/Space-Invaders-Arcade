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
#include "utils.h"

using namespace std;

Player player = {400.0f, 50.0f, 50.0f, 50.0f};
vector<Projectile> bullets;
vector<Enemy> enemies;

bool leftKeyPressed = false;
bool rightKeyPressed = false;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawPlayer(player);
    drawBullets(bullets);
    drawEnemies(enemies);
    glFlush();
}

void timer(int value) {
    // player position based
    movePlayer(player, leftKeyPressed, rightKeyPressed);

    // bullets and enemies
    updateBullets(bullets);
    updateEnemies(enemies);
    checkCollisions(bullets, enemies);

    // new enemy occasionally
    if (rand() % 100 < 5) spawnEnemy(enemies);

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
    glutCreateWindow("Blastar");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    glutTimerFunc(16, timer, 0);

    glutMainLoop();
    return 0;
}
