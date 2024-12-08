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
#include "Background.h"

using namespace std;

Player player = {400.0f, 50.0f, 50.0f, 50.0f};
vector<Projectile> bullets;
vector<Enemy> enemies;
vector<Explosion> explosions;

bool leftKeyPressed = false;
bool rightKeyPressed = false;



void timer(int value) {
    movePlayer(player, leftKeyPressed, rightKeyPressed);
    updateBullets(bullets);
    updateEnemies(enemies);
    updateExplosions(explosions);

    checkCollisions(bullets, enemies, explosions);

    if (rand() % 500 < 5) {
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


void setupLighting() {
    glEnable(GL_LIGHTING);  // Enable lighting
    glEnable(GL_LIGHT0);    // Enable light source 0 (you can have multiple lights)

    // Define a light source (directional light in this case)
    GLfloat light_position[] = { 0.0f, 0.0f, 1.0f, 0.0f };  // Directional light (coming from the z-axis)
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);  // Set light position

    GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };  // Ambient light (global light)
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);  // Set ambient light

    GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };  // Diffuse light (main light)
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);  // Set diffuse light (white)

    GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };  // Specular light (for highlights)
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);  // Set specular light
}


void setMaterialProperties() {
    GLfloat material_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };  // Low ambient reflection (dark objects)
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);

    GLfloat material_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };  // High diffuse reflection (light objects)
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);

    GLfloat material_specular[] = { 0.5f, 0.5f, 0.5f, 1.0f };  // Medium specular reflection (shine)
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);

    GLfloat material_shininess[] = { 32.0f };  // High shininess for a glossy effect
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, material_shininess);
}




void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    setupLighting();
    setMaterialProperties();
    
    drawStars();
    updateStars();
    
    updatePlayerLight(player);
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

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Blastar Extended");

    initStars(150);
    init(player, enemies);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    glutTimerFunc(16, timer, 0);

    glutMainLoop();
    return 0;
}

