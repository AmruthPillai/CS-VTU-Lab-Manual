#include <stdio.h>

// Apple Specific Compatibility Issues
#ifdef __APPLE__
	#include "GLUT/glut.h"
#else
	#include "GL\glut.h"
#endif

// Boolean Values
#define true 1
#define false 0

// Window Boundary
double xmin = 50, xmax = 100, ymax = 100, ymin = 50;
// Viewport Boundary
double xvmin = 200, yvmin = 200, xvmax = 300, yvmax = 300;

int cliptest(double p, double q, double *t1, double *t2) {
	double t = q / p;

	if (p < 0) {
		if (t > *t1) *t1 = t;
		if (t > *t2) return false; // Line Portion is Outside
	} else if (p > 0) {
		if (t < *t2) *t2 = t;
		if (t < *t1) return false;
	} else {
		if (q < 0) return false; // Line Portion is Outside
	}
}

void liangBarsky(double x0, double y0, double x1, double y1) {
	double dx = x1 - x0,
		dy = y1 - y0,
		tc = 0, t1 = 1;

		if (cliptest(-dx, x0 - xmin, &tc, &t1)) // inside test w.r.t. left edge
			if (cliptest(dx, xmax - x0, &tc, &t1)) // inside test w.r.t. right edge
				if (cliptest(-dy, y0 - ymin, &tc, &t1)) // inside test w.r.t. bottom edge
					if (cliptest(dy, ymax - y0, &tc, &t1)) { // inside test w.r.t. top edge
						if (t1 < 1) {
							x1 = x0 + t1 * dx;
							y1 = y0 + t1 * dy;
						}

						if (tc > 0) {
							x0 = x0 + tc * dx;
							y0 = y0 + tc * dy;
						}

						// `sx` and `sy` are used to scale the line
						// it zooms into the clipping window
						double sx = (xvmax - xvmin) / (xmax - xmin);
						double sy = (yvmax - yvmin) / (ymax - ymin);

						double vx0 = xvmin + (x0 - xmin) * sx;
						double vy0 = yvmin + (y0 - ymin) * sy;

						double vx1 = xvmin + (x1 - xmin) * sx;
						double vy1 = yvmin + (y1 - ymin) * sy;

						// Draw Bounding Box for Clipped Line
						glColor3f(1, 0, 0);
						glBegin(GL_LINE_LOOP);
						glVertex2f(xvmin, yvmin);
						glVertex2f(xvmax, yvmin);
						glVertex2f(xvmax, yvmax);
						glVertex2f(xvmin, yvmax);
						glEnd();

						// Draw Clipped Line
						glColor3f(0, 0, 1);
						glBegin(GL_LINES);
						glVertex2f(vx0, vy0);
						glVertex2f(vx1, vy1);
						glEnd();
					}
}

void display() {
	// Line Cooordinates
	double x0 = 60, y0 = 20,
		x1 = 80, y1 = 120;

	glClear(GL_COLOR_BUFFER_BIT);

	// Draw Bounding Box for Unclipped Line
	glColor3f(0, 0, 1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xmin, ymin);
	glVertex2f(xmax, ymin);
	glVertex2f(xmax, ymax);
	glVertex2f(xmin, ymax);
	glEnd();

	// Draw Unclipped Line
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(x0, y0);
	glVertex2f(x1, y1);
	glEnd();

	// Call liangBarsky() by passing Line Arguments
	liangBarsky(x0, y0, x1, y1);
	glFlush();
}

// Initialize Point Sizes and Colors
void init() {
	glClearColor(1, 1, 1, 1);
	glColor3f(1, 0, 0);
	glPointSize(1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Liang-Barsky Line Clipping Algorithm");

  glutDisplayFunc(display);

	init();
  glutMainLoop();

  return 0;
}
