#include <math.h>
#include <stdio.h>

// Apple Specific Compatibility Issues
#ifdef __APPLE__
#include "GLUT/glut.h"
#else
#include "GL\glut.h"
#endif

GLfloat h = 100;
GLfloat k = 100;
GLfloat theta;

void drawHouse() {
	// House
  glBegin(GL_LINE_LOOP);
  glVertex2f(0, 0);
  glVertex2f(0, 100);
  glVertex2f(100, 100);
  glVertex2f(100, 0);
  glEnd();

	// Door
  glBegin(GL_LINE_LOOP);
  glVertex2f(25, 0);
  glVertex2f(25, 50);
  glVertex2f(50, 50);
  glVertex2f(50, 0);
  glEnd();

	// Rooftop
  glBegin(GL_LINE_LOOP);
  glVertex2f(0, 100);
  glVertex2f(50, 150);
  glVertex2f(100, 100);
  glEnd();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glColor3f(0, 1, 0);
	glTranslatef(h, k, 0);
  drawHouse();

	glColor3f(1, 0, 0);
  glTranslatef(h, k, 0);
  glRotatef(theta, 0, 0, 1);
  glTranslatef(-h, -k, 0);
  drawHouse();

  glFlush();
}

void glInit() {
  glClearColor(1, 1, 1, 1);
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
