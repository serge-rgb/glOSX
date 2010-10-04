/*
 * Interface.cpp
 *
 *  Created on: Aug 4, 2008
 *      Author: monachus
 *
 *      This are callback functions to interface with glut.
 */

#include "interface.h"
#include "ObjMesh.h"


float rot = 0.0;
int width = W;
int height = H;
float aspRatio = W/H;

//ObjMesh mesh("ship.obj");
//ObjMesh mesh("Desk_Draws.obj");
//ObjMesh mesh("teapot.obj");
//ObjMesh mesh("cube.obj");
//ObjMesh mesh("ninja.obj");
//ObjMesh mesh("torus.obj");
ObjMesh mesh("bunny2.obj");
void engInit(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(W, H);
	glutCreateWindow("OpenGL");

	glutReshapeFunc(&resize);
	glutDisplayFunc(&display);
	glutIdleFunc(&idle);

	glEnable(GL_DEPTH_TEST);

	mesh.createDisplayList();
	//mesh.clear();
}

void simpleLighting()
{
	glEnable(GL_LIGHTING);

	GLfloat pos[] = {90,0,90,0};
	GLfloat color[] = {1,1,1,1};
	glShadeModel(GL_SMOOTH);
	glLightfv(GL_LIGHT0,GL_POSITION,pos);
	glLightfv(GL_LIGHT0,GL_COLOR,color);
	glEnable(GL_LIGHT0);
}

void resize(int w, int h)
{
	width = w;
	height = h;
	aspRatio = (float)w/h;
	glViewport(0,0,w,h);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0,1,2, 0,1,0, 0,1,0);
	glPushMatrix();
	glRotatef(rot,0,1,0);

	mesh.callList();
	//mesh.sendMesh();

	glPopMatrix();

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	gluPerspective(60,aspRatio,0.1,300);

	glutSwapBuffers();
}

void idle()
{
	glutPostRedisplay();
	rot += 1;
}


