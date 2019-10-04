#include<windows.h>
#include<math.h>
#include<shellapi.h>

glm::mat4 proj;
HBITMAP hbm,hgm,hqm,lig1,lig2,lig3,lig4,lig5,lig6,lig7,lig8,lig9;
HICON hi,hiu;
HDC hdc,hgc,hbc,hqc;
PAINTSTRUCT ps;
int csize, csize2, plane = 0;
RECT rc;
HBRUSH brush;
HPEN hp;
HFONT hf;
char wild[1000];
FILE *fi;
int stx, sty, wx, wy,fr1,fr2,curwin=0,deep=0,peep=1;
char path[1000] = "C:\\Users\\ADE\\Documents\\Asteroid Technology\\Project1\\Materials",
ppath[1000]="C:\\Users\\ADE\\Documents\\Asteroid Technology\\Project1";
char content[1000000],how[1000],how1[10000],how2[100000],how3[100000],cantent[5000][20],stantent[5000][260];
HICON icontent[5000];
char *script;
HANDLE hhh;
WIN32_FIND_DATA wff;
SHFILEINFO shft;
HWND hwnd;
int layout = 1, mpo1, mpo2, inn = 0, mdon = 0, project[6] = { 0,0,0,0,0,0 };
float wx1 = 0.3333333333333, wy1 = 0.5,wx2=wx1,wy2=0.5,wx3=wx2,wy3=0.5,wx4=wx1,wy4=0.5,wx5,w,thm,thm1,thm2,thm3,thm4,thm5,thm6,thm7,thm8,thm9,thm10;
int scrn1 = 1, scrn2 = 2, scrn3 = 3, scrn4 = 7, scrn5 = 5, scrn6 = 4,panop=0;
int obmen=0,obx,oby,mens=0,mren=0,furs=-1,mensel=0;
BOOL receive=TRUE,game1=FALSE;
int menu = 0,menu1=0,menu2=0,skew=0,gamx,gamy,gamw,gamwy,gamon;
int mesp1=300, mesp2=300,ou,bu,mu,size=0,hover=-1,hover1=0,pop=0,pop1=100,pop2=100,pop3=0,pop4=-1,fm1,fm2;
HCURSOR hc;
LPMINMAXINFO lpm;
RECT client;
HBITMAP sefari;

char *source;
char *frag;
GLuint VAO, VBO, EBO;
GLuint shaderProgram;
int width, height,maclick=-1,manon=-1;
char matname[1000],catname[1000];
unsigned char* image;
BYTE read[6000000];
GLuint texture, fbo,hdr,hdrmap,blur,blurmap, rbo,sky1,sky2,sky3,sky4,sky5,sky6;
GLuint texture1,**diffuse,black,cubemap;
GLuint vertexShader;
GLuint fragmentShader;
int getback = 1,typz=-1;
char **texturename;
char faces[6][100]={"\\boxes\\front.bmp","\\boxes\\back.bmp","\\boxes\\up.bmp","\\boxes\\down.bmp",
"\\boxes\\right.bmp","\\boxes\\left.bmp"};
GLfloat square[10000] = {
	-1,-1,0,
	1,-1,0, 
	1, 1,0, 
	-1, 1,0,
	-1,-1,0
};

float tray[240] = {
	-0.9f, -0.9f, 0.0f,		0.9f, -0.9f, 0.0f,
	-0.9f, -0.8f, 0.0f,		0.9f, -0.8f, 0.0f,
	-0.9f, -0.7f, 0.0f,		0.9f, -0.7f, 0.0f,
	-0.9f, -0.6f, 0.0f,		0.9f, -0.6f, 0.0f,
	-0.9f, -0.5f, 0.0f,		0.9f, -0.5f, 0.0f,
	-0.9f, -0.4f, 0.0f,		0.9f, -0.4f, 0.0f,
	-0.9f, -0.3f, 0.0f,		0.9f, -0.3f, 0.0f,
	-0.9f, -0.2f, 0.0f,		0.9f, -0.2f, 0.0f,
	-0.9f, -0.1f, 0.0f,		0.9f, -0.1f, 0.0f,
	-0.9f, 0.0f, 0.0f,		0.9f, 0.0f, 0.0f,
	-0.9f, 0.1f, 0.0f,		0.9f, 0.1f, 0.0f,
	-0.9f, 0.2f, 0.0f,		0.9f, 0.2f, 0.0f,
	-0.9f, 0.3f, 0.0f,		0.9f, 0.3f, 0.0f,
	-0.9f, 0.4f, 0.0f,		0.9f, 0.4f, 0.0f,
	-0.9f, 0.5f, 0.0f,		0.9f, 0.5f, 0.0f,
	-0.9f, 0.6f, 0.0f,		0.9f, 0.6f, 0.0f,
	-0.9f, 0.7f, 0.0f,		0.9f, 0.7f, 0.0f,
	-0.9f, 0.8f, 0.0f,		0.9f, 0.8f, 0.0f,
	-0.9f, 0.9f, 0.0f,		0.9f, 0.9f, 0.0f,

	-0.9f, -0.9f, 0.0f,		-0.9f, 0.9f, 0.0f,
	-0.8f, -0.9f, 0.0f,		-0.8f, 0.9f, 0.0f,
	-0.7f, -0.9f, 0.0f,		-0.7f, 0.9f, 0.0f,
	-0.6f, -0.9f, 0.0f,		-0.6f, 0.9f, 0.0f,
	-0.5f, -0.9f, 0.0f,		-0.5f, 0.9f, 0.0f,
	-0.4f, -0.9f, 0.0f,		-0.4f, 0.9f, 0.0f,
	-0.3f, -0.9f, 0.0f,		-0.3f, 0.9f, 0.0f,
	-0.2f, -0.9f, 0.0f,		-0.2f, 0.9f, 0.0f,
	-0.1f, -0.9f, 0.0f,		-0.1f, 0.9f, 0.0f,
	0.0f, -0.9f, 0.0f,		0.0f, 0.9f, 0.0f,
	0.1f, -0.9f, 0.0f,		0.1f, 0.9f, 0.0f,
	0.2f, -0.9f, 0.0f,		0.2f, 0.9f, 0.0f,
	0.3f, -0.9f, 0.0f,		0.3f, 0.9f, 0.0f,
	0.4f, -0.9f, 0.0f,		0.4f, 0.9f, 0.0f,
	0.5f, -0.9f, 0.0f,		0.5f, 0.9f, 0.0f,
	0.6f, -0.9f, 0.0f,		0.6f, 0.9f, 0.0f,
	0.7f, -0.9f, 0.0f,		0.7f, 0.9f, 0.0f,
	0.8f, -0.9f, 0.0f,		0.8f, 0.9f, 0.0f,
	0.9f, -0.9f, 0.0f,		0.9f, 0.9f, 0.0f
};
float xx, yy, zz,xx1,yy1,zz1;

float ang1[6] , ang2[6] = { 3.243,3.243,3.243,3.243,3.243,3.243 }, ang3[6] = { 1.57,1.57,1.57,1.57, 1.57,1.57 }, can1, can2, can3, san1, san2, san3, ratio = 0;
float mng1[6], mng2[6]= { 3.243,3.243,3.243,3.243,3.243,3.243 }, mng3[6]= { 1.57,1.57,1.57,1.57, 1.57,1.57 };
GLfloat spri[]={
-1,-1,0, 1,1,1,	0,0,
 1,-1,0, 1,1,1,	1,0,
 1, 1,0, 1,1,1,	1,1,
-1, 1,0, 1,1,1,	0,1,
-1,-1,0, 1,1,1,	0,0
};

GLfloat screen[]={
-1,-1,0,0,0,
 1,-1,0,1,0,
 1, 1,0,1,1,
-1, 1,0,0,1,
-1,-1,0,0,0
};

GLfloat borderColor[] = { 1.0, 1.0, 1.0, 1.0 };

GLfloat quadri[] = {
	-1,-1,0, 1,1,1,	0,0,
	1,-1,0, 1,1,1,	1,0,
	1, 1,0, 1,1,1,	1,0.1504,
	-1, 1,0, 1,1,1,	0,0.1504,
	-1,-1,0, 1,1,1,	0,0
};

GLfloat ski[] = {
	-2.0,-2.0,2.0, 1,1,1,	0,0,
	 2.0,-2.0,2.0, 1,1,1,	0,1,
	 2.0, 2.0,2.0, 1,1,1,	1,1,
	-2.0, 2.0,2.0, 1,1,1,	1,0,
	-2.0,-2.0,2.0, 1,1,1,	0,0,

	-2.0,-2.0,-2.0, 1,1,1,	0,1,
	 2.0,-2.0,-2.0, 1,1,1,	0,0,
	 2.0, 2.0,-2.0, 1,1,1,	1,0,
	-2.0, 2.0,-2.0, 1,1,1,	1,1,
	-2.0,-2.0,-2.0, 1,1,1,	0,1,
	
	-2.0,2.0,-2.0, 1,1,1,	0,0,
	 2.0,2.0,-2.0, 1,1,1,	1,0,
	 2.0,2.0, 2.0, 1,1,1,	1,1,
	-2.0,2.0, 2.0, 1,1,1,	0,1,
	-2.0,2.0,-2.0, 1,1,1,	0,0,

	-2.0, -2.0,-2.0, 1,1,1,	1,0,
	 2.0, -2.0,-2.0, 1,1,1,	0,0,
	 2.0, -2.0, 2.0, 1,1,1,	0,1,
	-2.0, -2.0, 2.0, 1,1,1,	1,1,
	-2.0, -2.0,-2.0, 1,1,1,	1,0,

	 2.0,-2.0,-2.0, 1,1,1,	1,0,
	 2.0, 2.0,-2.0, 1,1,1,	0,0,
	 2.0, 2.0, 2.0, 1,1,1,	0,1,
	 2.0,-2.0, 2.0, 1,1,1,	1,1,
	 2.0,-2.0,-2.0, 1,1,1,	1,0,

	-2.0,-2.0,-2.0, 1,1,1,	0,0,
	-2.0, 2.0,-2.0, 1,1,1,	1,0,
	-2.0, 2.0, 2.0, 1,1,1,	1,1,
	-2.0,-2.0, 2.0, 1,1,1,	0,1,
	-2.0,-2.0,-2.0, 1,1,1,	0,0

};

GLfloat arrow[] = {
	0.1,0,0,	 0.0,0,0,
	0,0.1,0,	 0.0,0,0,
	0,0,0.1,	 0.0,0,0
};

GLfloat stik[] = {
	0.3,0,0,	 0.0,0,0,
	0,0.3,0,	 0.0,0,0,
	0,0,0.3,	 0.0,0,0
};

HANDLE hfile;
DWORD dwFileSize;
DWORD dwRead;
char *objs,*objsm,tree[1000000],report[300],impot[1000];
int report1 = 0, grab[6] = {0,0,0,0,0,0};
GLfloat vertices[100000] ;

GLuint indices[300000] ;
GLfloat *verr;
char **materil,matie[1000000];
int roll = 0, insid = 0, count = 0, click = -1, oclik[6] = { -1,-1,-1,-1,-1,-1 }, lkik = -1, lclick[6] = {-1,-1,-1,-1,-1,-1},plik = -1, pclick[6] = { -1,-1,-1,-1,-1,-1 }, fclick = -1, jlik = -1, jclick[6] = { -1,-1,-1,-1,-1,-1 }, mclick[6] = { -1,-1,-1,-1,-1,-1 }, mlik = -1, causo = 0;
int winx[6], winy[6], winwx[6], winwy[6], hwin = 0, box[6] = { 2,2,2,2,2,2 }, selet[6] = { 0,0,0,0,0,0 }, selet1, selet2, selet3 = 0, selet4 = 0;
GLuint loc;
char bit[4000000];
HBITMAP loa;
HICON huld;
DWORD attrib,dattrib;
int ball = 0,bull=0,*showobj;
float mx[6] = {-0.4,-0.4,-0.4,-0.4,-0.4,-0.4 }, my[6] = { 0,0,0,0,0,0 }, mz[6] = { 0,0,0,0,0,0 }, zoom[6] = { 1,1,1,1,1,1 },pan1,pan2,pan3,zmx,mp1,mp2,mmx=0,mmy=0,mmz=0;
float px, py, pz;
struct vectz {
	float x;
	float y;
	float z;
};
struct mantel {
	int Kd;
	int tex;
	int text;
	float Tr;
	int bum;
	int bump;
	int shade;
	float ss;
	float si;
	int Ks;
	int sm;
	int spemap;
	float emit;
	int emK;
	int emmap;

	float emr;
	float emg;
	float emb;
	int emt;
	int emtmap;
	float rfls;
	float rfi;
	int rfk;
	int rfmap;
	float NSI;
	float NORS;
};

struct extut {
	float x;
	float y;
};

extut mext[100000],lip[300];
vectz color[1000],**colr,betxx[1000000],*mauv,*scil,*rita,obrot,obrot1,grot,grot1;
mantel **matprop, prop[5000];
int objc = 0,*vers,*fcon,**fice,*mtc,fnice[1000000], **grup,*subg,grop[50000], fcice[1000000],fnom[1000000],repo=0,pilt=0,wireframe[6]={0,0,0,0,0,0};
float *bufary,handx[1000000],handy[1000000],handz[1000000];
vectz **gauv,**frame,**scal,**rota;
CHOOSECOLOR ccz;
COLORREF zcolor, zref[16];
int check = 0,matdisp[10000],chkd=0,mil=0,*matcount,bued=0,editcrea=0,edestroy=0,wheel=0,*gcont;
#define EDIT1 4
HWND hedit;
char *camera,*light;
char projname[]="Project 1";
float rot1,rot2,rot3,mot1,mot2,mot3,metio,metio1,metio2,metio3,metion1,metion2,metion3,metio4,metio5,metio6,mefar,menear,mox;
vectz mcolor,fol[6],**center;
char cls1[50], cls2[50], cls3[50], cls4[50], cls5[50], cls6[50], cls7[50], cls8[50], cls9[50], cls10[50], cls11[50], cls12[50],cls13[50],cls14[50];
char *pivot;
WORD trash;
GLuint depthMapFBO[13],depthMap[13];
float environment=1,environment1=0.3;
int free1, free2, free3,free4,free5,free6,free7,free8=0,free9,free10,bright[6]={0,0,0,0,0,0},verco=0,*obcc,obcg=1,hstp=0,hcnp=0;
int tres[6]={30,30,30,30,30,30},trew[6],pres[6]={0,0,0,0,0,0},prew[6],eres[6]={30,30,30,30,30,30},erew[6],mres[6]={0,0,0,0,0,0},mrew[6];
int tran1[10000],tran2[10000],tran3[10000],tran4[10000],tran5[10000];
#include "game.h"
#include "import.h"
#include "shadow.h"
#include "camera.h"
#include "pilot.h"
#include "telescope.h"
#include "material.h"
#include "shading.h"
#include "functions.h"
#include "extension.h"

