#include <stdio.h>
#include <stdlib.h>

// Apple Specific Compatibility Issues
#ifdef __APPLE__
	#include "GLUT/glut.h"
#else
	#include "GL\glut.h"
#endif

// Width & Height of the Mesh
#define maxx 20
#define maxy 25

// Width & Height of Individual Cell
#define dx 20
#define dy 15

GLfloat x[maxx] = {0}, y[maxy] = {0};
GLfloat x0 = 50, y0 = 50;
GLint i, j;

long int loop;

void glInit() {
  glClearColor(1, 1, 1, 1);
  glPointSize(5);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 500, 0, 500);
  glutPostRedisplay();
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);

  for (i = 0; i < maxx; i++)
    x[i] = x0 + i * dx;
  for (j = 0; j < maxy; j++)
    y[j] = y0 + j * dy;

  for (i = 0; i < maxx - 1; i++) {
    for (j = 0; j < maxy - 1; j++) {
      glColor3f(0, 0, 1);

      glBegin(GL_LINE_LOOP);
        glVertex2f(x[i], y[j]);
        glVertex2f(x[i], y[j + 1]);
        glVertex2f(x[i + 1], y[j + 1]);
        glVertex2f(x[i + 1], y[j]);
      glEnd();

			// Delay
			for (loop = 0; loop < 100000000; loop++);
			glFlush();
    }
  }

  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Rectangular Mesh");
  glutDisplayFunc(display);
  glInit();
  glutMainLoop();
}
