/*
 * main.cpp
 *
 *  Created on: 7/08/2008
 *      Author: monachus
 */

#include "common.h"
#include "interface.h"
#include "shader.h"
#include "ObjMesh.h"

int main(int argc,char**argv)
{
	string vss = loadShaderSrc("shaders/light.vert");
	string fss = loadShaderSrc("shaders/light.frag");

	engInit(argc,argv);

	GLuint vs = newShader(vss,GL_VERTEX_SHADER);
	GLuint fs = newShader(fss,GL_FRAGMENT_SHADER);

	GLuint prog = newProgram(vs,fs);
	glUseProgram(prog);
	glutMainLoop();
}
