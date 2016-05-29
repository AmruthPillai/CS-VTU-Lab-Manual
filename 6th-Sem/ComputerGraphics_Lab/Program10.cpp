#include<stdlib.h>
#include<GL/glut.h>
#define maxx 20
#define maxy 25
#define dx 20
#define dy 20

GLfloat x[maxx]={0.0},y[maxy]={0.0};
GLfloat x0=50.0,y0=50.0;
GLint i,j;

void Del(void);
void multiDelay(void);

void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.5);
	glMatrixMode(GL_PROJECTION);
	glLineWidth(2.0);
	glLoadIdentity();
	gluOrtho2D(0.0,500.0,0.0,500.0);
}

void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	for(i=0;i<maxx;i++) x[i]=x0+i*dx;
	for(j=0;j<maxy;j++) y[j]=y0+j*dy;

	for(i=0;i<maxx-1;i++){
	for(j=0;j<maxy-1;j++)
		{
		    glBegin(GL_LINE_LOOP);
			multiDelay();
			glVertex2f(x[i],y[j]);
			multiDelay();
			glVertex2f(x[i],y[j+1]);
			multiDelay();
			glEnd();

			glBegin(GL_LINE_LOOP);
			glVertex2f(x[i+1],y[j+1]);
			multiDelay();
			glVertex2f(x[i+1],y[j]);
			multiDelay();
			glEnd();

			glBegin(GL_LINES);
			multiDelay();
			glVertex2f(x[i],y[j]);
			multiDelay();
			glVertex2f(x[i+1],y[j+1]);
multiDelay();
			glVertex2f(x[i],y[j+1]);
			multiDelay();
			glVertex2f(x[i+1],y[j]);
multiDelay();
			glVertex2f(x[i],y[j]);
			multiDelay();
			glVertex2f(x[i+1],y[j]);
			
			glEnd();

			multiDelay();
		}

	multiDelay();
	}
	glFlush();
}
void multiDelay(void){
Del();
Del();
Del();
}
void Del(void){
for(int m=0;m<1000;m++)
		for(int k=0;k<10000;k++);
			
		glFlush();
}

void main(int argc , char **argv)
{

	glutInit(&argc,argv);
	
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);

	glutInitWindowSize(500,500);

	glutCreateWindow("mesh");

	glutDisplayFunc(display);

	myinit();

	glutMainLoop();
}