#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec3 normals;

out vec3 bloom;
out vec3 gloom;

out vec2 TexCoord;
out vec4 fall;
out vec3 trick;

vec3 normal;
uniform mat4 projection;
uniform float jade, cade, seet, mall, outline = 0, shad = 0, mear, check, persp,zoom,drange;
uniform vec3 menter,genter, shatio[13], can[13], san[13], chan, shan,oft;
uniform vec2 ratio;
vec3 yenter;
float dot2, thm1;
uniform int jik, jinside,find;
uniform vec3 scal,scil,mxh,mauv,gauv,rota,rota1,mota,mota1;
vec3 finder;
vec4 ghost;
void main()
{
	//transform position
	if(find==1){ 
	normal = vec3(position.y,position.z,position.x)*vec3(scal)*vec3(scil)/10;
	normal-=vec3(genter);
	//group rotation
	//x
	yenter.x = normal.x; yenter.y = (normal.y*mota.x) - (normal.z*mota1.x); yenter.z = (normal.y*mota1.x) + (normal.z*mota.x);
	//y
	normal.x = (yenter.x*mota.y) + (yenter.z*mota1.y); normal.y = yenter.y; normal.z = (yenter.x*-1 * mota1.y) + (yenter.z*mota.y);
	//z
	yenter.x = (normal.x*mota.z) - (normal.y*mota1.z); yenter.y = (normal.x*mota1.z) + (normal.y*mota.z); yenter.z = normal.z;
	normal = yenter+vec3(genter);

	//object rotation
	//x
	yenter.x = normal.x; yenter.y = (normal.y*rota.x) - (normal.z*rota1.x); yenter.z = (normal.y*rota1.x) + (normal.z*rota.x);
	//y
	normal.x = (yenter.x*rota.y) + (yenter.z*rota1.y); normal.y = yenter.y; normal.z = (yenter.x*-1 * rota1.y) + (yenter.z*rota.y);
	//z
	yenter.x = (normal.x*rota.z) - (normal.y*rota1.z); yenter.y = (normal.x*rota1.z) + (normal.y*rota.z); yenter.z = normal.z;
	normal=yenter;
	trick = vec3(normal);
	normal+=vec3(mauv)+vec3(gauv);
	fall.x=normal.x; fall.y= normal.y; fall.z= normal.z;
	//trick = vec3(position.x,position.y,position.z)*vec3(scal)*vec3(scil)/10;
	//get reflection position

	if(jinside<=0){ normal+=vec3(mxh); if(drange==1){ normal*=zoom; }  }
	else if(jinside==1){ normal+=shatio[jik]; }
	
	//normal rotation
	if(jinside<=0){
	//x
	yenter.x = normal.x; yenter.y = (normal.y*chan.x) - (normal.z*shan.x); yenter.z = (normal.y*shan.x) + (normal.z*chan.x);
	//y
	normal.x = (yenter.x*chan.y) + (yenter.z*shan.y); normal.y = yenter.y; normal.z = (yenter.x*-1 * shan.y) + (yenter.z*chan.y);
	//z
	yenter.x = (normal.x*chan.z) - (normal.y*shan.z); yenter.y = (normal.x*shan.z) + (normal.y*chan.z); yenter.z = normal.z;
	}
	else if(jinside==1){
	//x
	yenter.x = normal.x; yenter.y = (normal.y*can[jik].x) - (normal.z*san[jik].x); yenter.z = (normal.y*san[jik].x) + (normal.z*can[jik].x);
	//y
	normal.x = (yenter.x*can[jik].y) + (yenter.z*san[jik].y); normal.y = yenter.y; normal.z = (yenter.x*-1 * san[jik].y) + (yenter.z*can[jik].y);
	//z
	yenter.x = (normal.x*can[jik].z) - (normal.y*san[jik].z); yenter.y = (normal.x*san[jik].z) + (normal.y*can[jik].z); yenter.z = normal.z;
	}
	
	if(outline!=0){
		if (yenter.x >= menter.x*zoom) { yenter.x = yenter.x + 0.01; }
		else { yenter.x = yenter.x - 0.01; }
		if (yenter.y >= menter.y*zoom) { yenter.y = yenter.y + 0.01; }
		else { yenter.y = yenter.y - 0.01; }
		if (yenter.z >= menter.z*zoom) { yenter.z = yenter.z - 0.01; }
		else { yenter.z = yenter.z + 0.01; }
	
	}
	if(jinside<=0){
	if(drange==1){
	finder=vec3(yenter.x*ratio.x,yenter.y*ratio.y,((yenter.z/2)-1.0));
	 ghost= projection*vec4(finder, 1.0f); }
	else{  finder=vec3(yenter.x*ratio.x*zoom,yenter.y*ratio.y*zoom,((yenter.z/-5)));
	ghost=vec4(finder,1.0f); }
	}

	if(jinside==1){
	if(persp==2){
	finder=vec3(yenter.x*ratio.x*0.1,yenter.y*ratio.y*0.1, (yenter.z/-1));
	ghost=projection*vec4(finder,1.0f);
	ghost.z=((yenter.z/10)-1.0-0.0001)*ghost.w;
	}
	else{
	finder=vec3(yenter.x*ratio.x*0.1,yenter.y*ratio.y*0.1,(yenter.z/10)-1.0-0.0001);
	ghost=vec4(finder,1.0f);
	}
	}

	}
	else if(find==2){
	finder=vec3(position*zoom);
	normal = vec3(position.y,position.z,position.x)/10;
	if(jinside<=0){ normal+=vec3(mxh); if(drange==1){ normal*=zoom; }  }
	//x
	yenter.x = normal.x; yenter.y = (normal.y*chan.x) - (normal.z*shan.x); yenter.z = (normal.y*shan.x) + (normal.z*chan.x);
	//y
	normal.x = (yenter.x*chan.y) + (yenter.z*shan.y); normal.y = yenter.y; normal.z = (yenter.x*-1 * shan.y) + (yenter.z*chan.y);
	//z
	yenter.x = (normal.x*chan.z) - (normal.y*shan.z); yenter.y = (normal.x*shan.z) + (normal.y*chan.z); yenter.z = normal.z;
	
	if(jinside<=0){
	if(drange==1){
	finder=vec3(yenter.x*ratio.x,yenter.y*ratio.y,((yenter.z/2)-1.0));
	 ghost= projection*vec4(finder, 1.0f); }
	else{  finder=vec3(yenter.x*ratio.x*zoom,yenter.y*ratio.y*zoom,((yenter.z/-5)));
	ghost=vec4(finder,1.0f); }
	}

	}
	else{ finder=position; }
	//end of transformation
	
	//camera
	//trick =vec3(position.y,position.z,position.x)*vec3(scal)*vec3(scil)/10;
	//trick+=vec3(mauv)+vec3(gauv);

	if(find==1||find==2){ 
	if(drange==1&&jinside<=0){ gl_Position = vec4(vec2(ghost)*0.5,ghost.z,ghost.w); }else{ gl_Position = vec4(ghost); }
	}
	else{ gl_Position = vec4(finder, 1.0f); }
	
	if (check == 9) { gl_Position.x += oft.x; gl_Position.y += oft.y; gl_Position.z += oft.z; }
	if (check == 10) { gl_Position.x += oft.x; gl_Position.y += oft.y; gl_Position.z += oft.z; }
	if (check == 11) { gl_Position.x += oft.x; gl_Position.y += oft.y; gl_Position.z += oft.z; }

	

	gl_PointSize = 3;

	//normal transform
if(find==1){
	normal = vec3(normals.y,normals.z,normals.x);
normal-=vec3(genter);
//group rotation
	//x
	yenter.x = normal.x; yenter.y = (normal.y*mota.x) - (normal.z*mota1.x); yenter.z = (normal.y*mota1.x) + (normal.z*mota.x);
	//y
	normal.x = (yenter.x*mota.y) + (yenter.z*mota1.y); normal.y = yenter.y; normal.z = (yenter.x*-1 * mota1.y) + (yenter.z*mota.y);
	//z
	yenter.x = (normal.x*mota.z) - (normal.y*mota1.z); yenter.y = (normal.x*mota1.z) + (normal.y*mota.z); yenter.z = normal.z;
	normal=yenter;

	//object rotation
	//x
	yenter.x = normal.x; yenter.y = (normal.y*rota.x) - (normal.z*rota1.x); yenter.z = (normal.y*rota1.x) + (normal.z*rota.x);
	//y
	normal.x = (yenter.x*rota.y) + (yenter.z*rota1.y); normal.y = yenter.y; normal.z = (yenter.x*-1 * rota1.y) + (yenter.z*rota.y);
	//z
	yenter.x = (normal.x*rota.z) - (normal.y*rota1.z); yenter.y = (normal.x*rota1.z) + (normal.y*rota.z); yenter.z = normal.z;
	normal=yenter+genter;

//normal rotation
	//x
	yenter.x = normal.x; yenter.y = (normal.y*chan.x) - (normal.z*shan.x); yenter.z = (normal.y*shan.x) + (normal.z*chan.x);
	//y
	normal.x = (yenter.x*chan.y) + (yenter.z*shan.y); normal.y = yenter.y; normal.z = (yenter.x*-1 * shan.y) + (yenter.z*chan.y);
	//z
	yenter.x = (normal.x*chan.z) - (normal.y*shan.z); yenter.y = (normal.x*shan.z) + (normal.y*chan.z); yenter.z = normal.z;
	normal.x = yenter.x; normal.y = yenter.y; normal.z = yenter.z;
	bloom=vec3(normal.x,normal.y,normal.z);
}else{ 
normal = vec3(normals.y,normals.z,normals.x);
//normal rotation
	//x
	yenter.x = normal.x; yenter.y = (normal.y*chan.x) - (normal.z*shan.x); yenter.z = (normal.y*shan.x) + (normal.z*chan.x);
	//y
	normal.x = (yenter.x*chan.y) + (yenter.z*shan.y); normal.y = yenter.y; normal.z = (yenter.x*-1 * shan.y) + (yenter.z*chan.y);
	//z
	yenter.x = (normal.x*chan.z) - (normal.y*shan.z); yenter.y = (normal.x*shan.z) + (normal.y*chan.z); yenter.z = normal.z;
	normal.x = yenter.x; normal.y = yenter.y; normal.z = yenter.z;
	bloom=vec3(normal.x,normal.y,normal.z);
 }
	gloom=vec3(normals.x,normals.y,normals.z);
	if (cade == 1.0) { dot2 = 1; }
	else {
		
		dot2 = (normal.x*0.4) + (normal.y*-0.7) + (normal.z*0.7);
		dot2 += 1; dot2 /= 2; //dot2 += 0.3;
	}
	fall.w = dot2; 	
	if (jade == 2.0) { TexCoord = vec2(texCoord.x, texCoord.y); }
	if (jade == 1.0) { TexCoord = vec2(texCoord.x, 1.0 - texCoord.y); }

}
