/*
 * shader.cpp
 *
 *  Created on: 12/08/2008
 *      Author: monachus
 */

#include "shader.h"
string loadShaderSrc(const char* fname)
{
	string src = "";

	ifstream file;
	file.open(fname);

	if(file.is_open()){
		string line;
		while(!file.eof()){
			getline(file,line);
			src += line + "\n";
		}
	}
	else cout << "Unable to open\n";

	file.close();

	return src;
}
int printOglError(char *file, int line)
{
    //
    // Returns 1 if an OpenGL error occurred, 0 otherwise.
    //
    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    while (glErr != GL_NO_ERROR)
    {
        printf("glError in file %s @ line %d: %s\n", file, line, gluErrorString(glErr));
        retCode = 1;
        glErr = glGetError();
    }
    return retCode;
}

void printShaderInfoLog(GLuint shader)
{
    int infologLength = 0;
    int charsWritten  = 0;
    GLchar *infoLog;

    printOpenGLError();  // Check for OpenGL errors

    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infologLength);

    printOpenGLError();  // Check for OpenGL errors

    if (infologLength > 0)
    {
        infoLog = (GLchar *)malloc(infologLength);
        if (infoLog == NULL)
        {
            printf("ERROR: Could not allocate InfoLog buffer\n");
            exit(1);
        }
        glGetShaderInfoLog(shader, infologLength, &charsWritten, infoLog);
        printf("Shader InfoLog:\n%s\n\n", infoLog);
        free(infoLog);
    }
    printOpenGLError();  // Check for OpenGL errors
}

void printProgramInfoLog(GLuint program)
{
    int infologLength = 0;
    int charsWritten  = 0;
    GLchar *infoLog;

    printOpenGLError();  // Check for OpenGL errors

    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infologLength);

    printOpenGLError();  // Check for OpenGL errors

    if (infologLength > 0)
    {
        infoLog = (GLchar *)malloc(infologLength);
        if (infoLog == NULL)
        {
            printf("ERROR: Could not allocate InfoLog buffer\n");
            exit(1);
        }
        glGetProgramInfoLog(program, infologLength, &charsWritten, infoLog);
        printf("Program InfoLog:\n%s\n\n", infoLog);
        free(infoLog);
    }
    printOpenGLError();  // Check for OpenGL errors
}

GLuint newShader(string s,GLenum type)
{
	GLuint so = glCreateShader(type);

	GLint sLen[1];
	const GLchar* sStrs[1];

	sStrs[0] = (const GLchar*) s.c_str();
	sLen[0] = s.length();

	glShaderSource(so,1,sStrs, sLen);

	glCompileShader(so);

	printShaderInfoLog(so);
	return so;
}

GLuint newProgram(GLuint vs,GLuint fs)
{
	GLuint prog = glCreateProgram();

	glAttachShader(prog,vs);
	glAttachShader(prog,fs);

	glLinkProgram(prog);

	printProgramInfoLog(prog);

	glUseProgram(prog);
	return prog;
}