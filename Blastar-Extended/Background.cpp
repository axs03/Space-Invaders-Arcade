//
//  Background.cpp
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/8/24.
//

#include "Background.h"

using namespace std;

vector<Star> stars;

void initStars(int numStars) {
    stars.clear();
    srand(time(0));

    for (int i = 0; i < numStars; ++i) {
        Star newStar;
        newStar.x = (rand() % 800);
        newStar.y = (rand() % 600);
        newStar.speed = (rand() % 3 + 1) * 0.5f;
        newStar.size = (rand() % 3 + 1) * 0.5f;
        stars.push_back(newStar);
    }
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // stars light properties
    GLfloat light_position[] = { 400.0f, 300.0f, 1.0f, 1.0f };
    GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
}


void updateStars() {
    for (auto& star : stars) {
        star.y -= star.speed;
        if (star.y < 0) {
            star.y = 600;
            star.x = rand() % 800;
        }
    }
}


void drawStars() {
    glEnable(GL_POINT_SMOOTH);
    glPointSize(2.0f);  // Point size for stars

    glBegin(GL_POINTS);
    for (const auto& star : stars) {
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex2f(star.x, star.y);
    }
    glEnd();

    glDisable(GL_POINT_SMOOTH);
}
