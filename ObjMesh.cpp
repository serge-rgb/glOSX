/*
 * ObjMesh.cpp
 *
 *  Created on: 7/08/2008
 *      Author: monachus
 */

#include"ObjMesh.h"

/*This will only load obj models composed of triangles
with normals and texture coordinates*/
ObjMesh::ObjMesh(string fname)
{
	//Temporary place to store vertex info.
	vector <vec3f> vertArray, normArray;
	vector <vec2f> textArray;

	cout << "Loading OBJ mesh to memory..." << endl;
	ifstream file(fname.c_str());
	if (!file) {
		cout << "Unable to open file.\n";
		exit(-1);
	}
	while (!file.eof()) {
		char buf[128];
		file.getline(buf,128);
		string line(buf);
		if (line.find("v ", 0,2) == 0) { //Found a vertex
			vec3f v;
			sscanf(line.c_str(),"v %f %f %f",&v.x,&v.y,&v.z);
			vertArray.push_back(v);
		}
		if(line.find("vt ",0,3) == 0) { //Texture coordinate
			vec2f t;
			sscanf(line.c_str(),"vt %f %f",&t.x,&t.y);
			textArray.push_back(t);
			//printf("%f,%f\n",t.x,t.y);
		}
		if (line.find("vn ", 0,3) == 0) { //Found a vertex
			vec3f n;
			sscanf(line.c_str(),"vn %f %f %f",&n.x,&n.y,&n.z);
			normArray.push_back(n);
		}
		if(line.find("f ",0,2)==0){ //Found a triangle
			triangle tri;
			vector <vec3f> vertices;
			vector <vec3f> normals;
			vector <vec2f> texts;

			int a, b, c, d, e, f, g, h, i;
			sscanf(line.c_str(), "f %i/%i/%i %i/%i/%i %i/%i/%i",
				&a,&b,&c,
				&d,&e,&f,
				&g,&h,&i);

			vertices.resize(3);
			normals.resize(3);
			texts.resize(3);

			vertices[0] = vertArray[a-1];
			vertices[1] = vertArray[d-1];
			vertices[2] = vertArray[g-1];

			normals[0] = normArray[c-1];
			normals[1] = normArray[f-1];
			normals[2] = normArray[i-1];

			tri.vertices = vertices;
			tri.texts = texts;
			tri.normals = normals;

			faces.push_back(tri);
		}
	}

	printf("Loaded %d vertices, %d texcoords and %d normals. Totaling %d triangles\n",vertArray.size(),textArray.size(),
		normArray.size(),faces.size());
}

void ObjMesh::createDisplayList()
{
	cout << "Compiling display list..." << endl;
	dlist = glGenLists(1);
	glNewList(dlist, GL_COMPILE);
	this->sendMesh();
	glEndList();
}

void ObjMesh::callList()
{
	glCallList(dlist);
}

void ObjMesh::sendMesh()
{
	int len = faces.size();
	glBegin(GL_TRIANGLES);
	for(int i=0; i<len;++i){
		triangle tri = faces[i];
		for(int j=0; j<3; j++){
			vec3f v = tri.vertices[j];
			vec3f n = tri.normals[j];
			vec2f t = tri.texts[j];
			//THE FRICKIN' NORMAL GOES BEFORE THE VERTEX!!!! (4 hour bug)
			glNormal3f(n.x,n.y,n.z);
			glVertex3f(v.x,v.y,v.z);
		}
	}
	glEnd();
}

ObjMesh::~ObjMesh()
{
	faces.clear();
	// TODO Auto-generated destructor stub
}
