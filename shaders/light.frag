varying vec3 norm;
varying vec3 pos;
varying vec3 eLightPos; 

#define CLIP(x) if ( x <= 0.0) x = 0.0;
void main(void)
{
	float ka,kd,ks,shine;
	float ia,id,is;
		
	ka = 0.3;
	kd = 0.3;
	ks = 0.6;
	shine = 45.0;
	
	ia = 1.0;
	id = 1.0;
	is = 1.0;
		
	vec3 camPos = vec3(0.0,1.0,2.0);
	
	vec3 V = normalize(camPos - pos);	   
	vec3 L = normalize(eLightPos - pos);  
	vec3 R = -L + 2.0*dot(norm,L)*norm;  
	
	float AmbI = ka*ia ;
	float DiffI =  kd*dot(L,norm)*id;
	float SpecI =  ks*pow(dot(R,V),shine)*is;
	
	float I = AmbI + DiffI;
	if (SpecI >= 0.0) I+=SpecI;
	
	gl_FragColor = vec4( 0.6, 0.6, 0.8, 1.0 );
	
	gl_FragColor *= I;	
}