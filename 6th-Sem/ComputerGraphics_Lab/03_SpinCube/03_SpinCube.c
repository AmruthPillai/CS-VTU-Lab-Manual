#include <stdio.h>

// Apple Specific Compatibility Issues
#ifdef __APPLE__
	#include "GLUT/glut.h"
#else
	#include "GL\glut.h"
#endif

GLfloat vertices[] = {
  -0.5, -0.5 , -0.5,
  -0.5, 0.5, -0.5,
  0.5, 0.5, -0.5,
  0.5, -0.5, -0.5,
  -0.5, -0.5, 0.5,
  -0.5, 0.5, 0.5,
  0.5, 0.5, 0.5,
  0.5, -0.5, 0.5
};

GLfloat colors[] = {
  0, 0, 0,
  0, 0, 1,
  0, 1, 0,
  0, 1, 1,
  1, 0, 0,
  1, 0, 1,
  1, 1, 0,
  1, 1, 1
};

GLbyte faces[] = {
  0, 1, 2, 3,
  2, 3, 7, 6,
  4, 5, 6, 7,
  4, 5, 1, 0,
  5, 6, 2, 1,
  0, 3, 7, 4
};

GLint currentBtn;

void mouse(int btn, int state, int x, int y) {
  currentBtn = btn;
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glRotated(0.06,
            currentBtn == GLUT_LEFT_BUTTON,
            currentBtn == GLUT_MIDDLE_BUTTON,
            currentBtn == GLUT_RIGHT_BUTTON);
  glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, faces);
  glFlush();
}

void glInit(int w, int h) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glEnableClientState(GL_COLOR_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, vertices);
  glColorPointer(3, GL_FLOAT, 0, colors);
  glEnable(GL_DEPTH_TEST);

  // Resize viewport to width and height
  glViewport(0, 0, w, h);

  // Maintain proper aspect ratio; otherwise the image would appear stretched
  if (h > w)
    glOrtho(-1.0, 1.0, -h / w, h / w, -1.0, 1.0);
  else
    glOrtho(-w / h, w / h, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitWindowSize(720, 720);
  glutCreateWindow("3D Spin Cube");
  glutDisplayFunc(display);
  glutIdleFunc(display);
  glutReshapeFunc(glInit);
  glutMouseFunc(mouse);
  glutMainLoop();
}
