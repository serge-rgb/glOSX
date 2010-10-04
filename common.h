/*
 * common.h
 *
 *  Created on: 7/08/2008
 *      Author: monachus
 */

#ifndef COMMON_H_
#define COMMON_H_

#include<vector>
#include<iostream>
#include<string>
#include<fstream>

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#ifdef WIN32
#include<windows.h>

#include"GLee.h"
#include<GL/GLee.h>
#endif

#define GL_GLEXT_PROTOTYPES

#ifndef WIN32 //Unix machine

#ifdef __linux
#include<GL/gl.h>

#include<GL/glu.h>
#include<GL/glext.h>
#include <GL/glut.h>

#else // Macintosh

#include<OpenGL/gl.h>
#include<OpenGL/glu.h>
#include<OpenGL/glext.h>
#include <GLUT/glut.h>

#endif

#endif //Unix

using namespace std;

#endif /* COMMON_H_ */

