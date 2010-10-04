/*
 * ObjMesh.h
 *
 *  Created on: 7/08/2008
 *      Author: monachus
 */

#ifndef OBJMESH_H_
#define OBJMESH_H_

#include "common.h"

struct vec3f 
{
	float x,y,z;
};
struct vec2f
{
	float x,y;
};
struct vec3i
{
	int x,y,z;
};
struct triangle
{
	vector <vec3f> vertices;
	vector <vec3f> normals;
	vector <vec2f> texts;
};


class ObjMesh {
public:
	ObjMesh(string);
	void createDisplayList();
	void sendMesh();
	void callList();
	virtual ~ObjMesh();
private:
	vector < triangle > faces;
	GLuint dlist;
};

#endif /* OBJMESH_H_ */
