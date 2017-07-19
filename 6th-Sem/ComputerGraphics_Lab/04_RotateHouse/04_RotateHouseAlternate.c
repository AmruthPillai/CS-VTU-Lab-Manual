#include <stdio.h>
#include <math.h>

// Apple Specific Compatibility Issues
#ifdef __APPLE__
	#include "GLUT/glut.h"
#else
	#include "GL\glut.h"
#endif

GLfloat theta;

void drawHouse() {
  glColor3f(1, 0, 0);
  glBegin(GL_LINE_LOOP);
    glVertex2f(150, 75);
    glVertex2f(350, 75);
    glVertex2f(350, 300);
    glVertex2f(150, 300);
  glEnd();

  glBegin(GL_LINE_LOOP);
    glVertex2f(200, 75);
    glVertex2f(300, 75);
    glVertex2f(300, 200);
    glVertex2f(200, 200);
  glEnd();

  glBegin(GL_LINES);
    // Triangle Left
    glVertex2f(150, 300);
    glVertex2f(250, 400);
    // Triangle Right
    glVertex2f(250, 400);
    glVertex2f(350, 300);
  glEnd();
}

void drawRotatedHouse() {
  glPushMatrix();

  glRotatef(theta, 0, 0, 1);

  glColor3f(1, 0, 0);
  glBegin(GL_LINE_LOOP);
    glVertex2f(150, 75);
    glVertex2f(350, 75);
    glVertex2f(350, 300);
    glVertex2f(150, 300);
  glEnd();

  glBegin(GL_LINE_LOOP);
    glVertex2f(200, 75);
    glVertex2f(300, 75);
    glVertex2f(300, 200);
    glVertex2f(200, 200);
  glEnd();

  glBegin(GL_LINES);
    // Triangle Left
    glVertex2f(150, 300);
    glVertex2f(250, 400);
    // Triangle Right
    glVertex2f(250, 400);
    glVertex2f(350, 300);
  glEnd();

  glPopMatrix();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  drawHouse();
  drawRotatedHouse();

  glFlush();
}

void glInit() {
  glClearColor(1, 1, 1, 1);
  glColor3f(1, 1, 0);
  glPointSize(10);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char **argv) {
  printf("Enter the angle of rotation: ");
  scanf("%f", &theta);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("House Rotation");
  glutDisplayFunc(display);
  glInit();
  glutMainLoop();
}
