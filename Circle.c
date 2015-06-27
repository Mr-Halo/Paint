#include <stdio.h>
#include <math.h>
#include "Circle.h"
/*
*Description:This file is used to paint a Circle
*Date:2015-06-27
*/
#define Pi 3.1415926
#define N 1000 /*Points to simulate a cirlce*/

void Circle(GLfloat r)
{
	int i;
	glBegin(GL_LINE_LOOP);
	for(i=0;i<N;i++)
	glVertex2f(r*cos(2*Pi*i/N),r*sin(2*Pi*i/N));
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	Circle(0.5);
	glFlush();
}

void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0,1.0,-1.0,1.0);
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	/*define Window size*/
	glutInitWindowSize(500,500);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Circle");
	glutDisplayFunc(display);
	glutMainLoop();
}
