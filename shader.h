/*
 * shader.h
 *
 *  Created on: 12/08/2008
 *      Author: monachus
 */

#ifndef SHADER_H_
#define SHADER_H_

#include"common.h"

#define MAXSIZE 1048576
#define _FILE (char *)__FILE__

string loadShaderSrc(const char* fname);
int printOglError(char *file, int line);
#define printOpenGLError() printOglError(_FILE,__LINE__);
void printShaderInfoLog(GLuint shader);
void printProgramInfoLog(GLuint program);
GLuint newShader(string s,GLenum type);
GLuint newProgram(GLuint vs,GLuint fs);

#endif /* SHADER_H_ */
