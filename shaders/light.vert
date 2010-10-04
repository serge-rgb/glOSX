varying vec3 norm; //normal
varying vec3 pos; // position
varying vec3 eLightPos; //eye light pos


void main(void)
{
	eLightPos = vec3(0.0,-100.0,0.0);
	
	norm = normalize(gl_NormalMatrix * gl_Normal);
	pos = vec3(gl_ModelViewMatrix * gl_Vertex);
	
   
   gl_Position = ftransform();   
}


