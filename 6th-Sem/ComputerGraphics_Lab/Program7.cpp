#include <GL/glut.h>  
#include <stdlib.h>
#include<math.h>

char title[] = "Teapot";

GLfloat v[4][3] = { 
	  {0,0,1.0} 
	, {0.0,0.942809,-0.333333}
	, {-0.816497,-0.471405,-0.333333}
	, {0.816497,-0.471405,-0.333333}
};

void delay(int delayNum) {
	for (int k = 0; k < delayNum; k++) {
		for (int m = 0; m < 1000; m++) {
			for (int n = 0; n < 1000; n++);
		}
		glFlush();
	}
}

void drawAxes(int rotationAxis[3]) {
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(800.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 800.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 800.0f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-800.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -800.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -800.0f);

	glColor3f(1.0f, 0.0f, 0.0f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(rotationAxis[0], rotationAxis[1], rotationAxis[2]);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-rotationAxis[0], -rotationAxis[1], -rotationAxis[2]);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.0f, -5.0f);

	glEnd();
}

void wall(double thickness) {
	glPushMatrix();
	glTranslated(0.5, 0.5*thickness, 0.5);
	glScaled(1.0, thickness, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();
}
void tableLeg(double thick, double len) {
	glPushMatrix();
	glTranslated(0, len / 2,0);
	glScaled(thick, len, thick);
	glutSolidCube(1.0);
	glPopMatrix();
}
void table(double topw, double topt, double legt, double legl) {
	glPushMatrix();
	glTranslated(0, legl, 0);
	glScaled(topw, topt, topw);
	glutSolidCube(1.0);
	glPopMatrix();

	double dist = ((0.95*topw) / 2.0) - (legt / 2.0);

	glPushMatrix();
	glTranslated(dist, 0, dist);
	tableLeg(legt, legl);
	glTranslated(0,0, -2 * dist);
	tableLeg(legt, legl);
	glTranslated(-2 * dist, 0, 2 * dist);
	tableLeg(legt,legl);
	glTranslated(0, 0 ,- 2 * dist);
	tableLeg(legt,legl);
	glPopMatrix();
}
void displayShadedTeaPot(GLfloat size) {
	GLfloat mat_ambient[] = { 0.7f,0.7f,0.7f };
	GLfloat mat_diffuse[] = { 0.5f,0.5f,0.5f,1.0f };
	GLfloat mat_specular[] = { 1.0f,1.0f,1.0f,1.0f };
	GLfloat ma_shininess[] = { 90.0f };

	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_ambient);

	GLfloat lightint[] = { 0.7f,0.7f,0.7f,1.0f };
	GLfloat lightpos[] = {2.0f,6.0f,3.0f,0.0f};

	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightint);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double winht = 1.0;
	glOrtho(-winht * 64 / 48.0, winht * 64 / 48.0, -winht, winht, 0.1, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.3, 1.3, 2.0, 0.0, 0.25, 0.0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotated(90.0, 0.0, 0.0, 1.0);
	wall(0.02);
	glPopMatrix();

	glPushMatrix();
	glRotated(-90.0, 1.0, 0.0, 0.0);
	wall(0.02);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.4, 0.0, 0.4);
	table(0.6, 0.02, 0.02, 0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.6, 0.38, 0.5);
	glRotated(30, 0,1, 0);
	glutSolidTeapot(size);
	glPopMatrix();

	glFlush();
}
void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	displayShadedTeaPot(0.08);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow(title);
	glutDisplayFunc(display);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	glutIdleFunc(display);
	glViewport(0, 0, 640, 480);

	glutMainLoop();
	return 0;
}