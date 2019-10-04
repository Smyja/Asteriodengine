#version 330 core
layout(location = 0) out vec4 color;
layout(location = 1) out vec4 blurcolor;

in vec2 TexCoord;
in vec4 fall;

in vec3 trick;
in vec3 bloom;
in vec3 gloom;


uniform sampler2D ourTexture;
uniform sampler2D ourTexture2;
uniform sampler2D depth1;
uniform sampler2D depth2;
uniform sampler2D depth3;
uniform sampler2D depth4;
uniform sampler2D depth5;
uniform sampler2D depth6;
uniform sampler2D depth7;
uniform sampler2D depth8;
uniform sampler2D depth9;


uniform sampler2D emmap;
uniform sampler2D specmap;
uniform sampler2D emiss;
uniform samplerCube cubemap;
uniform sampler2D reflectmap;

float offset=1/300.0;
vec2 offsets[9] = vec2[](
	vec2(-offset, offset), // top-left
	vec2(0.0f, offset), // top-center
	vec2(offset, offset), // top-right
	vec2(-offset, 0.0f), // center-left
	vec2(0.0f, 0.0f), // center-center
	vec2(offset, 0.0f), // center-right
	vec2(-offset, -offset), // bottom-left
	vec2(0.0f, -offset), // bottom-center
	vec2(offset, -offset) // bottom-right
	);
float kernel[9] = float[](
	-1, -1, -1,
	-1, 9, -1,
	-1, -1, -1
	);
vec3 sampleTex[9];

uniform mat4 projection;
uniform vec3 wire;
uniform float check,seet,bi,gi,ri,mall,bright,bright1;
vec4 textcolor;
vec4 nory;
float  dot2,dot1;
uniform float mode,mode1,mode2,mode3,mode4,outline=0,shad=0,mooz;
vec4 frag;
vec3 reflt,reflt1;
vec3 gory;
uniform vec2 ratio,specular,hi;
//ligthing
uniform float index,cut,findex,emit,dindex;
uniform vec3 poinx[300],poinc[300],pox[300];
uniform vec3 fdir[300];
uniform vec4 foth[300],dipo[300],fpo[300],fcol[300],properties,properties2;
uniform vec3 diot[300],fscol[300],ecat;
uniform vec4 dico[300],diter[300],emty;
uniform vec3 shatio[13], can[13], san[13],specolor,look;
uniform vec2 gamma;
//end lighting
float thm1,thm2,thm3,thm7,thm9;
vec3 thm4,thm5,thm6;
vec2 thm8;
int grain;
//shadow param
uniform int sun[13],flash[13];

void main()
{
	
	if (check == 12.0f) {
if(mode2==0&&mode3==0&&mode3==0){ color = texture(ourTexture, TexCoord); 

}
else{
	color=vec4(0);

for (int i = 0; i < 9; i++)
{
	sampleTex[i] = vec3(texture(ourTexture, TexCoord.st + offsets[i])); 
}
if(mode2==1){
//shapen
thm4 = vec3(0);
kernel[0] = -1; kernel[1] = -1; kernel[2] = -1;
kernel[3] = -1; kernel[4] = 9; kernel[5] = -1;
kernel[6] = -1; kernel[7] = -1; kernel[8] = -1;
for (int i = 0; i < 9; i++) { thm4 += sampleTex[i] * kernel[i]; }
color+=vec4(thm4,1);
}
//blur
if(mode3==1){
thm4 = vec3(0);
kernel[0] = 1.0 / 16.0; kernel[1] = 2.0 / 16.0; kernel[2] = 1.0 / 16.0;
kernel[3] = 2.0 / 16.0; kernel[4] = 4.0 / 16.0; kernel[5] = 2.0 / 16.0;
kernel[6] = 1.0 / 16.0; kernel[7] = 2.0 / 16.0; kernel[8] = 1.0 / 16.0;
for (int i = 0; i < 9; i++) { thm4 += sampleTex[i] * kernel[i]; }
color += vec4(thm4, 1);
}

}
//hdr transform
color.rgb=vec3(1.0)-exp(-color.rgb*0.2);
if(gamma.x==1){ color.rgb = pow(color.rgb, vec3(1.0/2.2)); }
//color = color/(color + 1); color.w=frag.w;

	}
	else{

	if (check == 11.0f) { frag = vec4(1.0f, 1.0f, 0.2f, 1.0f); }
	if (check == 10.0f) { frag = vec4(0.1f, 0.2f, 1.0f, 1.0f); }
	if (check == 9.0f) { frag = vec4(1.0f, 0.2f, 1.0f, 1.0f); }
	if (check == 8.0f) { frag = vec4(0.2f, 0.5f, 1.0f, 1.0f); }
	if (check == 1.0f) { frag = vec4(0.5f, 0.5f, 0.5f, 1.0f); }
	if (check == 2.0f) { frag = texture(ourTexture, TexCoord); }
	if (check == 5.0f) { frag = vec4(1.0f, 0.0f, 0.0f, 1.0f); }
	if (check == 4.0f) { frag = vec4(0.0f, 1.0f, 0.0f, 1.0f); }
	if (check == 3.0f) { frag = vec4(0.0f, 0.0f, 1.0f, 1.0f); }
	if (check == 6.0f) { 
		if(mall==0){
		if (seet < 0.1) { discard; }
		if (hi.x == 1) {
			 nory = texture(ourTexture2, TexCoord);  normalize(nory*2.0-1.0);
		dot2 = (nory.x*-0.8) + (nory.y*-0.8)+(nory.z*0.2*hi.y);
		dot2 += 1; dot2 /= 2;  dot2 *= 4;  dot2+0.01;		nory.x = dot2; nory.y = dot2; nory.z = dot2;
		nory.a = 1.0;
		}
		else { nory = vec4(1.0, 1.0, 1.0, 1.0); }
thm4=vec3(fall.w*nory);
		frag = vec4(vec3(ecat.x, ecat.y, ecat.z), seet);
//reflection
if(properties2.x>0){
if(properties2.y<=0){
thm5=normalize(trick-look); 
thm6 = reflect(thm5, normalize(bloom));
thm6=normalize(vec3(thm6.z,thm6.x,thm6.y));
if(ri==1){ nory=texture(reflectmap,TexCoord); thm7=properties2.x*((nory.x+nory.y+nory.z)/3.0); }
else{ thm7=properties2.x;}
nory = texture(cubemap, thm6);
thm5=vec3(nory.z*(thm7)+frag.x*(1- thm7),nory.y*(thm7)+frag.y*(1- thm7),nory.x*(thm7)+frag.z*(1- thm7));
frag=vec4(thm5,frag.w);
}
else{
thm5=normalize(trick-look); 
thm6=refract(thm5, normalize(bloom), properties2.y);
thm6=normalize(vec3(thm6.z,thm6.x,thm6.y));
if(ri==1){ nory=texture(reflectmap,TexCoord); thm7=properties2.x*((nory.x+nory.y+nory.z)/3.0); }
else{ thm7=properties2.x;}
nory = texture(cubemap, thm6);
thm5=vec3(nory.z*(thm7)+frag.x*(1- thm7),nory.y*(thm7)+frag.y*(1- thm7),nory.x*(thm7)+frag.z*(1- thm7));
frag=vec4(thm5,frag.w);
}
}
frag=vec4(vec3(frag)*thm4,frag.w);
		thm2=1;
		if (gi>0) { nory = texture(emiss, TexCoord); thm2 = (nory.x + nory.y + nory.z) / 3.0;  }
	if(emty.x==1){ frag+=vec4(frag.x*emit*thm2,frag.y*emit*thm2,frag.z*emit*thm2,seet); }
	else if(emty.x==2){ frag+=vec4(emty.w*emit*thm2,emty.z*emit*thm2,emty.y*emit*thm2,seet);}
	else{ nory=texture(emmap,TexCoord); frag+=vec4(nory.x*emit*thm2,nory.y*emit*thm2,nory.z*emit*thm2,seet); }
		}
		else{ 
		frag = vec4(wire, seet);  
		thm2 = 1;
		if (gi>0) { nory = texture(emiss, TexCoord); thm2 = (nory.x + nory.y + nory.z) / 3.0; }
		frag += vec4(wire*emit*thm2,seet);
		}
		frag.w=seet;
		}

	if (check == 7.0f) {
		if (mall == 0) {
		if (seet < 0.1) { discard; }
		if (hi.x == 1) { nory = texture(ourTexture2, TexCoord);  normalize(nory*2.0-1.0);
		dot2 = (nory.x*-0.8) + (nory.y*-0.8)+(nory.z*0.2*hi.y);
		dot2 += 1; dot2 /= 2;  dot2 *= 4;  dot2+0.01;		nory.x = dot2; nory.y = dot2; nory.z = dot2;
		nory.a = 1.0;
		thm4=vec3(fall.w*nory);
		textcolor = texture(ourTexture, TexCoord);
		}
		else { thm4=vec3(fall.w); textcolor = texture(ourTexture, TexCoord); }
		
		if (textcolor.a < 0.1) {
			discard;
		}
		frag = vec4(textcolor.b, textcolor.g, textcolor.r, textcolor.a*seet);
//reflection
if(properties2.x>0){
if(properties2.y<=0){
thm5=normalize(trick-look); 
thm6 = reflect(thm5, normalize(bloom));
thm6=normalize(vec3(thm6.z,thm6.x,thm6.y));
if(ri==1){ nory=texture(reflectmap,TexCoord); thm7=properties2.x*((nory.x+nory.y+nory.z)/3.0); }
else{ thm7=properties2.x;}
nory = texture(cubemap, thm6);
thm5=vec3(nory.z*(thm7)+frag.x*(1- thm7),nory.y*(thm7)+frag.y*(1- thm7),nory.x*(thm7)+frag.z*(1- thm7));
frag=vec4(thm5,frag.w);
}
else{
thm5=normalize(trick-look); 
thm6=refract(thm5, normalize(bloom), properties2.y);
thm6=normalize(vec3(thm6.z,thm6.x,thm6.y));
if(ri==1){ nory=texture(reflectmap,TexCoord); thm7=properties2.x*((nory.x+nory.y+nory.z)/3.0); }
else{ thm7=properties2.x;}
nory = texture(cubemap, thm6);
thm5=vec3(nory.z*(thm7)+frag.x*(1- thm7),nory.y*(thm7)+frag.y*(1- thm7),nory.x*(thm7)+frag.z*(1- thm7));
frag=vec4(thm5,frag.w);
}
}
frag=vec4(vec3(frag)*thm4,frag.w);
//emission
	thm2 = 1;
	if (gi>0) { nory = texture(emiss, TexCoord); thm2 = (nory.x + nory.y + nory.z) / 3.0; }
	if(emty.x==1){ frag+=vec4(frag.x*emit*thm2,frag.y*emit*thm2,frag.z*emit*thm2,seet); }
	else if(emty.x==2){ frag+=vec4(emty.w*emit*thm2,emty.z*emit*thm2,emty.y*emit*thm2,seet);}
	else{ nory=texture(emmap,TexCoord); frag+=vec4(nory.z*emit*thm2,nory.y*emit*thm2,nory.x*emit*thm2,seet);  }
	frag.w = textcolor.a*seet;
	}
	else { frag = vec4(wire, seet); 
	thm2 = 1;
	if (gi>0) { nory = texture(emiss, TexCoord); thm2 = (nory.x + nory.y + nory.z) / 3.0; }
	frag += vec4(wire*emit*thm2, seet);
	frag.w = seet;
	}
	
	}
	if (mode == 1) { dot2 = frag.x + frag.y + frag.z; dot2 /= 3.0; frag.x = dot2; frag.y = dot2; frag.z = dot2; }
	if (mode1 == 1) { frag.x = 1.0-frag.x; frag.y = 1.0 - frag.y; frag.z = 1.0 - frag.z; }

	//final coloring
	if(outline==0){

	if(bright>1){ color = vec4(frag); }
	else{ 
//lighting
if(shad==1){
	//point light

thm4=vec3(0,0,0);
	for(int a=0;a<index;a++){
thm1=trick.x-poinx[a].x; thm1*=thm1;
thm2 = trick.y - poinx[a].y; thm2*=thm2;
thm3 = trick.z - poinx[a].z; thm3*=thm3;
thm1=thm1+thm2+thm3;
thm1=sqrt(thm1);
thm1=pox[a].y/thm1;
thm3=thm1*poinc[a].x*pox[a].x; thm2=thm1*poinc[a].y*pox[a].x; thm1=thm1*poinc[a].z*pox[a].x;
thm4.x+=frag.x*thm1; thm4.y+=frag.y*thm2; thm4.z+=frag.z*thm3;
//ambience
thm1=pox[a].z*poinc[a].x; thm2=pox[a].z*poinc[a].y; thm3=pox[a].z*poinc[a].z; 
thm4.x+=frag.x*thm1; thm4.y+=frag.y*thm2; thm4.z+=frag.z*thm3;

}
//end of point light


//directional light
for(int a=0;a<dindex;a++){
thm5=diot[a]-vec3(dipo[a]);
thm6=trick-vec3(dipo[a]);
thm7=dot(normalize(thm5),normalize(thm6));
if(thm7<0){
//ambience
thm1 = diter[a].x*dico[a].x; thm2 = diter[a].x*dico[a].y; thm3 = diter[a].x*dico[a].z;
thm4.x+=frag.x*thm1; thm4.y+=frag.y*thm2; thm4.z+=frag.z*thm3;
}
else {	thm7=1;
//shadow process
if(sun[a]>=0){
grain=sun[a];
gory=vec3(fall)+shatio[grain];
//x
thm5.x = gory.x; thm5.y = (gory.y*can[grain].x) - (gory.z*san[grain].x); thm5.z = (gory.y*san[grain].x) + (gory.z*can[grain].x);
//y
gory.x = (thm5.x*can[grain].y) + (thm5.z*san[grain].y); gory.y = thm5.y; gory.z = (thm5.x*-1 * san[grain].y) + (thm5.z*can[grain].y);
//z
thm5.x = (gory.x*can[grain].z) - (gory.y*san[grain].z); thm5.y = (gory.x*san[grain].z) + (gory.y*can[grain].z); thm5.z = gory.z;
gory=vec3(thm5.x*ratio.x*0.1,thm5.y*ratio.y*0.1,(thm5.z/10)-1.0-0.0001);
gory=gory*0.5+0.5;
if(grain==0){ dot2 = texture(depth1, gory.xy).r; }
else if(grain==1){ dot2 = texture(depth2, gory.xy).r; }
else if(grain==2){ dot2 = texture(depth3, gory.xy).r; }
else if(grain==3){ dot2 = texture(depth4, gory.xy).r; }
else if(grain==4){ dot2 = texture(depth5, gory.xy).r; }
else if(grain==5){ dot2 = texture(depth6, gory.xy).r; }
else if(grain==6){ dot2 = texture(depth7, gory.xy).r; }
else if(grain==7){ dot2 = texture(depth8, gory.xy).r; }
else if(grain==8){ dot2 = texture(depth9, gory.xy).r; }

dot1=gory.z;
thm5=diot[a]-vec3(dipo[a]);
thm1=max(0.08*(dot(gloom,thm5)),0.008);
//pcf
thm7 = 0.0;
if(grain==0){ thm8 = 1.0/textureSize(depth1, 0); }
else if(grain==1){  thm8 = 1.0/textureSize(depth2, 0); }
else if(grain==2){  thm8 = 1.0/textureSize(depth3, 0); }
else if(grain==3){  thm8 = 1.0/textureSize(depth4, 0); }
else if(grain==4){  thm8 = 1.0/textureSize(depth5, 0); }
else if(grain==5){  thm8 = 1.0/textureSize(depth6, 0); }
else if(grain==6){  thm8 = 1.0/textureSize(depth7, 0); }
else if(grain==7){  thm8 = 1.0/textureSize(depth8, 0); }
else if(grain==8){  thm8 = 1.0/textureSize(depth9, 0); }


for(int x = -1; x <= 1; ++x)
{
for(int y = -1; y <= 1; ++y)
{
if(grain==0){ dot2 = texture(depth1, gory.xy + vec2(x, y) *thm8).r; }
else if(grain==1){ dot2 = texture(depth2, gory.xy + vec2(x, y) *thm8).r; }
else if(grain==2){ dot2 = texture(depth3, gory.xy + vec2(x, y) *thm8).r; }
else if(grain==3){ dot2 = texture(depth4, gory.xy + vec2(x, y) *thm8).r; }
else if(grain==4){ dot2 = texture(depth5, gory.xy + vec2(x, y) *thm8).r; }
else if(grain==5){ dot2 = texture(depth6, gory.xy + vec2(x, y) *thm8).r; }
else if(grain==6){ dot2 = texture(depth7, gory.xy + vec2(x, y) *thm8).r; }
else if(grain==7){ dot2 = texture(depth8, gory.xy + vec2(x, y) *thm8).r; }
else if(grain==8){ dot2 = texture(depth9, gory.xy + vec2(x, y) *thm8).r; }


thm7 += dot1 - thm1 > dot2 ? 0.0 : 1.0;
}
}
thm7 /= 9.0;
}
//end of shadow
thm4.x += frag.x*dico[a].x*dico[a].w*thm7; thm4.y += frag.y*dico[a].y*dico[a].w*thm7; thm4.z += frag.z*dico[a].z*dico[a].w*thm7;

if(dipo[a].w>0){
//specular
thm6=vec3(diot[a].x,diot[a].y,diot[a].z);
thm6 = normalize(thm6-vec3(dipo[a]));
thm5 = reflect(bloom,thm6);
thm6 = normalize(vec3(0,0,5)-trick);
thm1 = pow(max(dot(thm6, thm5), 0.0), specular.x);
if (thm1<0) { thm1 = 0; } 
thm6=vec3(specolor)*thm1*specular.y;
if(bi>0){ nory= texture(specmap, TexCoord); thm2=(nory.x+nory.y+nory.z)/3.0; thm6*=thm2; }
thm4+=thm6*thm7*dico[a].w;

if(hi.x==1&&properties.x>0){
	thm6 = vec3(diot[a].x, diot[a].y, diot[a].z);
	thm6 = normalize(thm6 - vec3(dipo[a]));
	nory = texture(ourTexture2, TexCoord); normalize(nory*2.0-1.0); thm5=vec3(nory);
	thm5 = reflect(bloom, thm6);
	thm6 = normalize(vec3(0,0,5) - trick);
	thm1 = pow(max(dot(thm6, thm5), 0.0), specular.x);
	if (thm1<0) { thm1 = 0; }
	thm6 = vec3(specolor*thm1*specular.y);
	if (bi>0) { nory=texture(specmap,TexCoord); thm2=(nory.x+nory.y+nory.z) / 3.0; thm6*=thm2; }
	thm4+=thm6*thm7*dico[a].w*properties.x;
}
}

//ambience
thm1 = diter[a].x*dico[a].x; thm2 = diter[a].x*dico[a].y; thm3 = diter[a].x*dico[a].z;
thm4.x += frag.x*thm1; thm4.y += frag.y*thm2; thm4.z += frag.z*thm3; 

}


}


//flashlight
for(int a=0;a<findex;a++){
thm5=fdir[a]-vec3(fpo[a]);
thm6=trick-vec3(fpo[a]);
thm7=dot(normalize(thm5),normalize(thm6));
if(thm7<foth[a].w){ 
	thm1 = foth[a].z*fcol[a].x; thm2 = foth[a].z*fcol[a].y; thm3 = foth[a].z*fcol[a].z;
	thm4.x += frag.x*thm1; thm4.y += frag.y*thm2; thm4.z += frag.z*thm3;
}
else{ 
thm9=1;
//shadow process
if(flash[a]>=0){
grain=flash[a];
gory=vec3(fall)+shatio[grain];
//x
thm5.x = gory.x; thm5.y = (gory.y*can[grain].x) - (gory.z*san[grain].x); thm5.z = (gory.y*san[grain].x) + (gory.z*can[grain].x);
//y
gory.x = (thm5.x*can[grain].y) + (thm5.z*san[grain].y); gory.y = thm5.y; gory.z = (thm5.x*-1 * san[grain].y) + (thm5.z*can[grain].y);
//z
thm5.x = (gory.x*can[grain].z) - (gory.y*san[grain].z); thm5.y = (gory.x*san[grain].z) + (gory.y*can[grain].z); thm5.z = gory.z;
gory=vec3(thm5.x*ratio.x*0.1,thm5.y*ratio.y*0.1,(thm5.z/-1));
nory=projection*vec4(gory,1.0f);
 nory.z=((thm5.z/10)-1.0-0.0001);
gory.x=nory.x/nory.w; gory.y=nory.y/nory.w; gory.z=nory.z;
gory=gory*0.5+0.5;

if(grain==0){ dot2 = texture(depth1, gory.xy).r; }
else if(grain==1){ dot2 = texture(depth2, gory.xy).r; }
else if(grain==2){ dot2 = texture(depth3, gory.xy).r; }
else if(grain==3){ dot2 = texture(depth4, gory.xy).r; }
else if(grain==4){ dot2 = texture(depth5, gory.xy).r; }
else if(grain==5){ dot2 = texture(depth6, gory.xy).r; }
else if(grain==6){ dot2 = texture(depth7, gory.xy).r; }
else if(grain==7){ dot2 = texture(depth8, gory.xy).r; }
else if(grain==8){ dot2 = texture(depth9, gory.xy).r; }




dot1=gory.z;
thm5=fdir[a]-vec3(fpo[a]);
thm1 = max(0.08 * (dot(gloom, thm5)), 0.008);

//pcf
thm9 = 0.0;
if(grain==0){ thm8 = 1.0/textureSize(depth1, 0); }
else if(grain==1){  thm8 = 1.0/textureSize(depth2, 0); }
else if(grain==2){  thm8 = 1.0/textureSize(depth3, 0); }
else if(grain==3){  thm8 = 1.0/textureSize(depth4, 0); }
else if(grain==4){  thm8 = 1.0/textureSize(depth5, 0); }
else if(grain==5){  thm8 = 1.0/textureSize(depth6, 0); }
else if(grain==6){  thm8 = 1.0/textureSize(depth7, 0); }
else if(grain==7){  thm8 = 1.0/textureSize(depth8, 0); }
else if(grain==8){  thm8 = 1.0/textureSize(depth9, 0); }




for(int x = -1; x <= 1; ++x)
{
for(int y = -1; y <= 1; ++y)
{
if(grain==0){ dot2 = texture(depth1, gory.xy + vec2(x, y) *thm8).r; }
else if(grain==1){ dot2 = texture(depth2, gory.xy + vec2(x, y) *thm8).r; }
else if(grain==2){ dot2 = texture(depth3, gory.xy + vec2(x, y) *thm8).r; }
else if(grain==3){ dot2 = texture(depth4, gory.xy + vec2(x, y) *thm8).r; }
else if(grain==4){ dot2 = texture(depth5, gory.xy + vec2(x, y) *thm8).r; }
else if(grain==5){ dot2 = texture(depth6, gory.xy + vec2(x, y) *thm8).r; }
else if(grain==6){ dot2 = texture(depth7, gory.xy + vec2(x, y) *thm8).r; }
else if(grain==7){ dot2 = texture(depth8, gory.xy + vec2(x, y) *thm8).r; }
else if(grain==8){ dot2 = texture(depth9, gory.xy + vec2(x, y) *thm8).r; }




thm9 += dot1 - thm1 > dot2 ? 0.0 : 1.0;
}
}
thm9 /= 9.0;

}


	thm1 = trick.x - fpo[a].x; thm1*=thm1;
	thm2 = trick.y - fpo[a].y; thm2*=thm2;
	thm3 = trick.z - fpo[a].z; thm3*=thm3;
	thm1 = thm1 + thm2 + thm3;
	thm1 = sqrt(thm1);
	thm1 = foth[a].x / thm1;
	if (fcol[a].w == 1) { thm1 *= (thm7 - foth[a].w); }
//shadow
	//diffuse
	thm3 = thm1*fcol[a].x*foth[a].y; thm2 = thm1*fcol[a].y*foth[a].y; thm1 = thm1*fcol[a].z*foth[a].y;
	thm4.x += frag.x*thm1*thm9; thm4.y += frag.y*thm2*thm9; thm4.z += frag.z*thm3*thm9;
	
if(fpo[a].w>0){
	//specular
	thm6 = vec3(fdir[a].x,fdir[a].y, fdir[a].z);
	thm6 = normalize(thm6 - vec3(fpo[a]));
	thm5 = reflect(bloom,thm6);
	thm6 = normalize(vec3(0,0,5) - trick);
	thm2 = dot(thm5, thm6);
	thm2 = pow(max(dot(thm6, thm5), 0.0), specular.x);
	if (thm2<0) { thm2 = 0; }
	thm6 = vec3(specolor*thm2*specular.y*thm1);
	if (bi>0) { nory = texture(specmap, TexCoord); thm2 = (nory.x + nory.y + nory.z) / 3.0; thm6 *= thm2; }
	thm4 += thm6*thm9*foth[a].y;

	if(hi.x==1&&properties.x>0){
	thm6 = vec3(fdir[a].x,fdir[a].y, fdir[a].z);
	thm6 = normalize(thm6 - vec3(fpo[a]));
	nory = texture(ourTexture2, TexCoord); normalize(nory*2.0-1.0); thm5=vec3(nory);
	thm5 = reflect(bloom,thm6);
	thm6 = normalize(vec3(0,0,5) - trick);
	thm2 = dot(thm5, thm6);
	thm2 = pow(max(dot(thm6, thm5), 0.0), specular.x);
	if (thm2<0) { thm2 = 0; }
	thm6 = vec3(specolor*thm2*specular.y*thm1);
	if (bi>0) { nory = texture(specmap, TexCoord); thm2 = (nory.x + nory.y + nory.z) / 3.0; thm6 *= thm2; }
	thm4 += thm6*thm9*foth[a].y*properties.x;
}
	}

	//ambience
thm1 = foth[a].z*fcol[a].x; thm2 = foth[a].z*fcol[a].y; thm3 = foth[a].z*fcol[a].z;
thm4.x += frag.x*thm1; thm4.y += frag.y*thm2; thm4.z += frag.z*thm3;
}


}
thm2 = 1;
if (gi>0) { nory = texture(emiss, TexCoord); thm2 = (nory.x + nory.y + nory.z) / 3.0; }
thm4 += vec3(frag.x*emit*thm2, frag.y*emit*thm2, frag.z*emit*thm2);

	color = vec4(vec3(thm4+vec3(frag*bright)),frag.w);
	thm1=dot(color.rgb,vec3(0.2126,0.7152,0.0722));
if(thm1>1.0){ blurcolor=color; }
blurcolor=vec4(vec3(color),1);
}
//end of calculation
else{
color = vec4(frag.x*bright1, frag.y*bright1, frag.z*bright1, frag.w);
}
}

	}
	else{ color=vec4(0.1,0.3,1.0,1.0); }
//hdr close braces
}

}
