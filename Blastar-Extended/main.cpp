//
//  main.cpp
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/2/24.
//

#include <iostream>
#include "/opt/local/include/GL/glut.h"

using namespace std;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();

    glFlush();
}

void display_two() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_POLYGON);
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, 0.0, 1.0);
    glEnd();
    
    glFlush();
}

void init()
{
    glClearColor(0.000, 0.110, 0.392, 0.0); // JMU Gold

    glColor3f(0.314, 0.314, 0.000); // JMU Purpleq

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Main");
    glutDisplayFunc(display_two);
    init();
    glutMainLoop();
}

