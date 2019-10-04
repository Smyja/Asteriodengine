#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <windows.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include<gl/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<soil.h>
#include"define.h"


void EnableOpenGL(HWND hwnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL(HWND hwnd, HDC hDC, HGLRC hRC);

LRESULT CALLBACK WndProc(HWND hwnd, UINT message,WPARAM wParam, LPARAM lParam)
{

	switch (message)
	{
	case WM_PAINT: {
		hqc = BeginPaint(hwnd, &ps);
		gamon=0; 
		hdc = CreateCompatibleDC(hqc);
		hqm = CreateCompatibleBitmap(hqc, csize, csize2);
		SelectObject(hdc, hqm);

		if (plane == 0) {
			hgc = CreateCompatibleDC(hdc);
			hgm = CreateCompatibleBitmap(hdc, csize, csize2);
			SelectObject(hgc, hgm);
			hbc = CreateCompatibleDC(hdc);
			SelectObject(hbc, hbm);
			BitBlt(hgc, 0, 0, csize, csize2, hbc, 0, 0, SRCCOPY);
			DeleteDC(hbc);
			BitBlt(hdc, 0, 0, csize, csize2, hgc, 0, 0, SRCCOPY);
			DeleteDC(hgc);
			DeleteObject(hgm);
		}
		if (plane == 1) {
			hgc = CreateCompatibleDC(hdc);
			hgm = CreateCompatibleBitmap(hdc, csize, csize2);
			SelectObject(hgc, hgm);

			brush = CreateSolidBrush(RGB(20, 20, 20));
			SetRect(&rc, 0, 0, csize, csize2);
			FillRect(hgc, &rc, brush);
			DeleteObject(brush);

			hbc = CreateCompatibleDC(hdc);
			//asteroid
			SelectObject(hbc, lig2);
			BitBlt(hgc, csize / 2 - 125, 0, 250, 167, hbc, 0, 0, SRCAND);
			SelectObject(hbc, lig1);
			BitBlt(hgc, csize/2-125, 0, 250, 167, hbc, 0, 0, SRCPAINT);
			//asteroid name
			SelectObject(hbc, lig4);
			BitBlt(hgc, 50, 200, 388, 57, hbc, 0, 0, SRCAND);
			SelectObject(hbc, lig3);
			BitBlt(hgc, 50, 200, 388, 57, hbc, 0, 0, SRCPAINT);
			//line
			SelectObject(hbc, lig6);
			BitBlt(hgc, 27, 260, 689, 26, hbc, 0, 0, SRCAND);
			SelectObject(hbc, lig5);
			BitBlt(hgc, 27, 260, 689, 26, hbc, 0, 0, SRCPAINT);
			//crystal
			SelectObject(hbc, lig8);
			BitBlt(hgc, csize-285, csize2-70, 281, 80, hbc, 0, 0, SRCAND);
			SelectObject(hbc, lig7);
			BitBlt(hgc, csize-285, csize2-70, 281, 80, hbc, 0, 0, SRCPAINT);
			//end
		
			//other operations
			hf = CreateFont(17, 7, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
			SelectObject(hgc, hf);
			SetTextColor(hgc, RGB(255, 255, 255));
			SetBkMode(hgc, TRANSPARENT);

			hiu = LoadIcon(GetModuleHandle(NULL), "ICO1");
			DrawIcon(hgc, 50, 300, hiu);	TextOut(hgc, 90, 307, "New Project", 11);	DeleteObject(hiu);
			hiu = LoadIcon(GetModuleHandle(NULL), "ICO2");
			DrawIcon(hgc, 50, 335, hiu);	TextOut(hgc, 90, 342, "Open Project", 12);	DeleteObject(hiu);
			hiu = LoadIcon(GetModuleHandle(NULL), "ICO3");
			DrawIcon(hgc, 50, 370, hiu);	TextOut(hgc, 90, 377, "Examples", 8);	DeleteObject(hiu);
			DeleteObject(hf);

			//more operations
			hf = CreateFont(25, 10, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
			SelectObject(hgc, hf);
			SetTextColor(hgc, RGB(255, 255, 255));
			SetBkMode(hgc, TRANSPARENT);

			TextOut(hgc, 300, 300, "Recent", 6);
			//last
			TextOut(hgc, 600, 300, "Collection", 10);
			DeleteObject(hf);

			hf = CreateFont(17, 7, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
			SelectObject(hgc, hf);
			SetTextColor(hgc, RGB(255, 255, 255));
			SetBkMode(hgc, TRANSPARENT);
			TextOut(hgc, 600, 350, "About", 5);
			TextOut(hgc, 600, 380, "Learn", 5);

			SelectObject(hbc, lig9);
			BitBlt(hgc, 600, 410, 300, 169, hbc, 0, 0, SRCCOPY);
			
			DeleteObject(hf);
			
			DeleteDC(hbc);
			BitBlt(hdc, 0, 0, csize, csize2, hgc, 0, 0, SRCCOPY);
			DeleteDC(hgc);
			DeleteObject(hgm);
		}

		if (plane == 2) {
			hgc = CreateCompatibleDC(hdc);
			hgm = CreateCompatibleBitmap(hdc, csize, 100);
			SelectObject(hgc, hgm);

			BitBlt(hdc, 0, 0, csize, 100, hgc, 0, 0, SRCCOPY);
			DeleteDC(hgc);
			DeleteObject(hgm);


			upmenu();
			run();

			 arrange();
			
			status();
			if (selet3 >0) { DrawIcon(hdc, mpo1, mpo2, huld); }
			//item select
			if(pop==1){
			hgc = CreateCompatibleDC(hdc);
			hgm = CreateCompatibleBitmap(hdc, 360, 160);
			SelectObject(hgc, hgm);

			SetRect(&rc, 1, 1, 360, 160);
			brush = CreateSolidBrush(RGB(20, 20, 20));
			FillRect(hgc, &rc, brush);
			DeleteObject(brush);

			
			brush = CreateSolidBrush(RGB(100, 100, 200));
			if (mpo1 >pop1&&mpo1<pop1+360&&mpo2>pop2&&mpo2<pop2+160&&obmen==0) { 
			if(mpo2-pop2 >10 && mpo2-pop2<30&&mpo1-pop1<180){ SetRect(&rc, 1, 8, 180, 29); FillRect(hgc, &rc, brush); }
			if (mpo2 - pop2>30 && mpo2 - pop2<50 && mpo1 - pop1<180) { SetRect(&rc, 1, 28, 180, 49); FillRect(hgc, &rc, brush); }
			if (mpo2 - pop2>50 && mpo2 - pop2<70 && mpo1 - pop1<180) { SetRect(&rc, 1, 48, 180, 69); FillRect(hgc, &rc, brush); }
			if (mpo2 - pop2>70 && mpo2 - pop2<90 && mpo1 - pop1<180) { SetRect(&rc, 1, 68, 180, 89); FillRect(hgc, &rc, brush); }
			if (mpo2 - pop2>90 && mpo2 - pop2<110 && mpo1 - pop1<180) { SetRect(&rc, 1, 88, 180, 109); FillRect(hgc, &rc, brush); }
			if (mpo2 - pop2>110 && mpo2 - pop2<130 && mpo1 - pop1<180) { SetRect(&rc, 1, 108, 180, 129); FillRect(hgc, &rc, brush); }
			if (mpo2 - pop2>130 && mpo2 - pop2<150 && mpo1 - pop1<180) { SetRect(&rc, 1, 128, 180, 149); FillRect(hgc, &rc, brush); }
			if (mpo2 - pop2>10 && mpo2 - pop2<30 && mpo1 - pop1>180) { SetRect(&rc, 180, 8, 360, 29); FillRect(hgc, &rc, brush); }
			}
			DeleteObject(brush);

			hiu = LoadIcon(GetModuleHandle(NULL), "ICO8");	DrawIcon(hgc, 10, 10, hiu); DeleteObject(hiu);
			hiu = LoadIcon(GetModuleHandle(NULL), "ICO9");	DrawIcon(hgc, 10, 30, hiu); DeleteObject(hiu);
			hiu = LoadIcon(GetModuleHandle(NULL), "ICO10");	DrawIcon(hgc, 10, 50, hiu); DeleteObject(hiu);
			hiu = LoadIcon(GetModuleHandle(NULL), "ICO26");	DrawIcon(hgc, 10, 70, hiu); DeleteObject(hiu);
			hiu = LoadIcon(GetModuleHandle(NULL), "ICO11");	DrawIcon(hgc, 10, 90, hiu); DeleteObject(hiu);
			hiu = LoadIcon(GetModuleHandle(NULL), "ICO41");	DrawIcon(hgc, 10, 112, hiu); DeleteObject(hiu);
			hiu = LoadIcon(GetModuleHandle(NULL), "ICO46");	DrawIcon(hgc, 10, 130, hiu); DeleteObject(hiu);
			hiu = LoadIcon(GetModuleHandle(NULL), "ICO53");	DrawIcon(hgc, 180, 10, hiu); DeleteObject(hiu);

			hf = CreateFont(15, 7, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
			SelectObject(hgc, hf);
			SetTextColor(hgc, RGB(255, 255, 255));
			SetBkMode(hgc, TRANSPARENT);
			TextOut(hgc, 40, 10, "Asteroid Tree", 14);
			TextOut(hgc, 40, 30, "Asteroid Pilot", 15);
			TextOut(hgc, 40, 50, "Properties", 11);
			TextOut(hgc, 40, 70, "Glossary", 9);
			TextOut(hgc, 40, 90, "Asteroid Explorer", 18);
			TextOut(hgc, 40, 110, "Camera", 7);
			TextOut(hgc, 40, 130, "Material", 8);
			TextOut(hgc, 210, 10, "Project", 7);
			DeleteObject(hf);


			BitBlt(hdc, pop1, pop2, 360, 160, hgc, 0, 0, SRCCOPY);
			DeleteDC(hgc);
			DeleteObject(hgm);
		}

		
		if(obmen==1){
		hgc = CreateCompatibleDC(hdc);
		hgm = CreateCompatibleBitmap(hdc, 220, 60);
		SelectObject(hgc, hgm);

		SetRect(&rc,0,0,180,50);
		brush = CreateSolidBrush(RGB(20, 20, 20));
		FillRect(hgc, &rc, brush);
		DeleteObject(brush);

		brush = CreateSolidBrush(RGB(100, 100, 200));
		if (mpo1 >obx&&mpo1<obx+180&&mpo2>oby&&mpo2<oby+60) { furs=-1;
		if(mpo2-oby>10&&mpo2-oby<30&&mpo1-obx<180){ SetRect(&rc,1,8,179,29); FillRect(hgc, &rc, brush); furs=1; }
		}
		DeleteObject(brush);

		hiu = LoadIcon(GetModuleHandle(NULL), "ICO66");	DrawIcon(hgc,7,2, hiu); DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO67");	DrawIcon(hgc,160,8, hiu); DeleteObject(hiu);

		hf = CreateFont(15, 7, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetTextColor(hgc, RGB(255, 255, 255));
		SetBkMode(hgc, TRANSPARENT);
		TextOut(hgc, 40, 10, "CandeLink", 10);
		DeleteObject(hf);

		BitBlt(hdc, obx, oby, 180, 50, hgc, 0, 0, SRCCOPY);
		DeleteDC(hgc);
		DeleteObject(hgm);


		//other pop
		if(furs==1){
		hgc = CreateCompatibleDC(hdc);
		hgm = CreateCompatibleBitmap(hdc, 220, 250);
		SelectObject(hgc, hgm);

		SetRect(&rc,0,0,180,250);
		brush = CreateSolidBrush(RGB(20, 20, 20));
		FillRect(hgc, &rc, brush);
		DeleteObject(brush);

		brush = CreateSolidBrush(RGB(100, 100, 200));
		/*if (mpo1 >obx&&mpo1<obx+180&&mpo2>oby&&mpo2<oby+60) { 
		if(mpo2-oby >10&&mpo2-oby<30&&mpo1-obx<180){ SetRect(&rc,1,8,179,29); FillRect(hgc, &rc, brush); free1=1; }
		
		}
		*/
		DeleteObject(brush);

		hf = CreateFont(15, 7, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetTextColor(hgc, RGB(255, 255, 255));
		SetBkMode(hgc, TRANSPARENT);
		brush = CreateSolidBrush(RGB(100, 100, 200));
		bu=mens+10;
		for(int a=0,b=0,i=0;a<strlen(light);a++){
		how3[b]=light[a]; b++;
		if(light[a]==':'){ how3[b-1]=0; b=0; i++;
		if(bu>=0&&bu<250){ 
		if(mpo2-oby >bu&&mpo2-oby<bu+30&&mpo1-obx>181&&mpo1-obx<181+180-11){ SetRect(&rc,1,bu-5,179,bu+23); FillRect(hgc, &rc, brush); free1=1; mensel=i; }
		if(light[a+1]=='1'){ hiu=LoadIcon(GetModuleHandle(NULL),"ICO61"); }
		else if(light[a+1]=='2'){ hiu=LoadIcon(GetModuleHandle(NULL),"ICO63"); }
		else if(light[a+1]=='3'){ hiu=LoadIcon(GetModuleHandle(NULL),"ICO62"); }
		DrawIcon(hgc,7,bu-2,hiu); DeleteObject(hiu);
		TextOut(hgc,40,bu,how3,strlen(how3)); bu+=30;
		for(0;a<strlen(light);a++){ if(light[a]==';'){ break; } }
		}
		}
		if(bu>250){ break;}
		}
		DeleteObject(hf);
		DeleteObject(brush);

		//scrollbar
	hp=CreatePen(PS_SOLID,1,RGB(20,20,20)); SelectObject(hgc,hp);
	brush=CreateSolidBrush(RGB(80,80,80)); SelectObject(hgc,brush);
	thm1=bu-mens;
	thm2=246;
	if(thm2>thm1){ thm3=thm2; }
	else{ thm1-=thm2; thm4=thm1/30.0*2.0; thm3=thm2-thm4; }
	mren=thm3; if(thm3<20){ thm3=20; } 
	if (mens>0) { thm6=mens; thm6=thm6/20.0*2.0; thm5=thm6; }
	else { thm5=2; }
	RoundRect(hgc,180-11,thm5,180-1,thm5+thm3,7,7);
	DeleteObject(brush); DeleteObject(hp);

		BitBlt(hdc, obx+181, oby+10, 180, 250, hgc, 0, 0, SRCCOPY);
		DeleteDC(hgc);
		DeleteObject(hgm);
		}

		}

		}

		



		//MESSAGEBOX
		if (menu == 1) { layot(); }

		BitBlt(hqc, 0, 0, csize, csize2, hdc, 0, 0, SRCCOPY);
		DeleteDC(hdc);
		DeleteObject(hqm);

		EndPaint(hwnd, &ps);
		break; }

			
	case WM_SIZE: {
		csize = LOWORD(lParam);
		csize2 = HIWORD(lParam);
		menu = 0; menu1 = 0; menu2 = 0;
		SetRect(&client, 0, 0, csize, csize2);
		if (pop != 0) { pop = 0; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		break; }

	case WM_TIMER: {
		if (plane == 0) {
			
			SetWindowLong(hwnd, GWL_STYLE, WS_VISIBLE | WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN);
			MoveWindow(hwnd, GetSystemMetrics(SM_CXSCREEN) / 2 - 500, GetSystemMetrics(SM_CYSCREEN) / 2 - 370, 1000, 700, TRUE);
			hi = LoadIcon(GetModuleHandle(NULL), "ICO");
			SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hi);
			plane = 2; 
			KillTimer(hwnd, 1);
		}
		if(editcrea>0){ SendMessage(hedit,EM_SETSEL,(WPARAM)3,(LPARAM)3); }
		if (plane == 2&&report1!=0&&repo==0) {
			KillTimer(hwnd, 1);
			report1 = 0; sprintf(report, "");
			SetRect(&rc, 0, csize2 - 25, csize, csize2);
			ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
		}
		if (repo == 0) { KillTimer(hwnd, 1); }
		if (plane == 2&& repo == 1) { 
			repo = 0; report1 = 0; sprintf(report, "");
			import(impot); 
			KillTimer(hwnd, 1); SetTimer(hwnd, 1, 3000, NULL); SendMessage(hwnd,WM_LBUTTONDOWN,1,1); SendMessage(hwnd,WM_LBUTTONUP,1,1); 
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
if(edestroy==1){ edicek(); DestroyWindow(hedit); SetFocus(hwnd); editcrea=0; hc=LoadCursor(NULL,IDC_ARROW); SetCursor(hc); edestroy=0; }
		break; }

	case WM_RBUTTONDOWN: {
if (layout!=10&&layout!=12) { if (curwin == 1) { ou = scrn1; }if (curwin == 2) { ou = scrn2; }if (curwin == 3) { ou = scrn3; }if (curwin == 4) { ou = scrn4; }if (curwin == 5) { ou = scrn5; }if (curwin == 6) { ou = scrn6; } }
if(layout==10){ if (curwin == 4) { ou = scrn1; }if (curwin ==1) { ou = scrn2; }if (curwin == 2) { ou = scrn3; }if (curwin == 3) { ou = scrn4; } }
if (layout == 12) { if (curwin == 2) { ou = scrn1; }if (curwin == 3) { ou = scrn2; }if (curwin == 4) { ou = scrn3; }if (curwin == 1) { ou = scrn4; } }
hwin=curwin-1;

	if (ou == 1 && mpo2 > winy[curwin - 1] + 20&&mpo1-winx[curwin-1]<winwx[curwin-1]-12) {
	if (oclik[curwin - 1]>= 0) { mlik=oclik[hwin]; fclick=-1; jlik = -1; lkik=-1;  }else{ if(mclick[hwin]<0){ mlik=-1;} }
	if (mclick[curwin-1]>=0) { fclick=mclick[hwin]; jlik=-1; lkik=-1;   }else{ fclick=-1; }
	
	if(mlik>=0){ obmen=1; obx=mpo1; oby=mpo2; furs=-1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd,NULL,TRUE); }
	if (fclick >= 0) { obmen=1; obx=mpo1; oby=mpo2; furs=-1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd,NULL,TRUE); }
	}

	break; }

case WM_MBUTTONUP:{
if(panop>0){ panop=0; roll=0; ReleaseCapture(); }
break;	}

case WM_MBUTTONDOWN:{
if (layout!=10&&layout!=12) { if (curwin == 1) { ou = scrn1; }if (curwin == 2) { ou = scrn2; }if (curwin == 3) { ou = scrn3; }if (curwin == 4) { ou = scrn4; }if (curwin == 5) { ou = scrn5; }if (curwin == 6) { ou = scrn6; } }
if(layout==10){ if (curwin == 4) { ou = scrn1; }if (curwin ==1) { ou = scrn2; }if (curwin == 2) { ou = scrn3; }if (curwin == 3) { ou = scrn4; } }
if (layout == 12) { if (curwin == 2) { ou = scrn1; }if (curwin == 3) { ou = scrn2; }if (curwin == 4) { ou = scrn3; }if (curwin == 1) { ou = scrn4; } }
if(ou==2){ panop=3; roll=1; }
break; 
}

	case WM_MOUSEWHEEL:{
	wheel=(short)HIWORD(wParam); thm3=wheel/12.0;
if (layout!=10&&layout!=12) { if (curwin == 1) { ou = scrn1; }if (curwin == 2) { ou = scrn2; }if (curwin == 3) { ou = scrn3; }if (curwin == 4) { ou = scrn4; }if (curwin == 5) { ou = scrn5; }if (curwin == 6) { ou = scrn6; } }
if(layout==10){ if (curwin == 4) { ou = scrn1; }if (curwin ==1) { ou = scrn2; }if (curwin == 2) { ou = scrn3; }if (curwin == 3) { ou = scrn4; } }
if (layout == 12) { if (curwin == 2) { ou = scrn1; }if (curwin == 3) { ou = scrn2; }if (curwin == 4) { ou = scrn3; }if (curwin == 1) { ou = scrn4; } }
hwin=curwin-1;
if(ou==2){
if(panop!=2){ 
zoom[hwin]+=(thm3/100*zoom[hwin]); 
if(zoom[hwin]<=0){ zoom[hwin]=0; }
}
 else{
		can1 = cos(ang1[hwin]); san1 = sin(ang1[hwin]);
		can2 = cos(ang2[hwin]); san2 = sin(ang2[hwin]);
		can3 = cos(-ang3[hwin]); san3 = sin(-ang3[hwin]);
		thm=thm3/100;
		thm5 = 0;
		thm6 = 0;
		thm7 = thm;
		thm8 = (thm7*san2) + (thm5*can2);
		thm9 = (thm5*-san2) + (thm7*can2);
		thm7 = thm6;
		thm5 = thm8;
		thm6 = (thm7*can1) + (thm9*-san1);
		thm8 = (thm7*san1) + (thm9*can1);
		mx[hwin] += thm5; my[hwin] += thm6; mz[hwin] += thm8;
 }
SetRect(&rc, winx[curwin - 1], winy[curwin - 1], winx[curwin - 1] + winwx[curwin - 1], winy[curwin - 1] + winwy[curwin - 1]);
ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
}
//properties
if(ou==3){ pres[curwin-1]-=thm3; 
if(pres[hwin]<0){ pres[hwin]=0; }
if(pres[hwin]>0){ thm6=pres[hwin]; thm6=thm6/20.0*2.0; thm5=21+thm6; }
else{ thm5=21; }
if((thm5+prew[hwin])>winwy[hwin] -3){
thm3=(thm5+prew[hwin])-(winwy[hwin]-3);
thm3=thm3*20.0/2.0;
pres[hwin]-=thm3;
}
if(editcrea>0){ edestroy=1; SetTimer(hwnd,1,100,NULL); }
SetRect(&rc,winx[curwin-1],winy[curwin-1],winx[curwin-1]+winwx[curwin-1],winy[curwin-1]+winwy[curwin-1]);
ValidateRect(hwnd,&rc); InvalidateRect(hwnd,NULL,TRUE); }
//tree
if(ou==1){ tres[curwin-1]+=thm3; 
if(tres[hwin]>30){ tres[hwin]=30; }
if(tres[hwin]<30){ thm6=30-tres[hwin]; thm6=thm6/20.0*2.0; thm5=21+thm6; }
else{ thm5=21; }
if((thm5+trew[hwin])>winwy[hwin] -3){
thm3=(thm5+trew[hwin])-(winwy[hwin]-3);
thm3=thm3*20.0/2.0;
tres[hwin]+=thm3;
}
if(editcrea>0){ edestroy=1; SetTimer(hwnd,1,100,NULL); }
SetRect(&rc,winx[curwin-1],winy[curwin-1],winx[curwin-1]+winwx[curwin-1],winy[curwin-1]+winwy[curwin-1]);
ValidateRect(hwnd,&rc); InvalidateRect(hwnd,NULL,TRUE); }
//explorer
if(ou==5){ eres[curwin-1]+=thm3; 
if(eres[hwin]>30){ eres[hwin]=30; }
if(eres[hwin]<30){ thm6=30-eres[hwin]; thm6=thm6/20.0*2.0; thm5=21+thm6; }
else{ thm5=21; }
if((thm5+erew[hwin])>winwy[hwin] -3){
thm3=(thm5+erew[hwin])-(winwy[hwin]-3);
thm3=thm3*20.0/2.0;
eres[hwin]+=thm3;
}
if(editcrea>0){ edestroy=1; SetTimer(hwnd,1,100,NULL); }
SetRect(&rc,winx[curwin-1],winy[curwin-1],winx[curwin-1]+winwx[curwin-1],winy[curwin-1]+winwy[curwin-1]);
ValidateRect(hwnd,&rc); InvalidateRect(hwnd,NULL,TRUE); }

//material
if(ou==7){ mres[curwin-1]-=thm3; 
if(mres[hwin]<0){ mres[hwin]=0; }
if(mres[hwin]>0){ thm6=mres[hwin]; thm6=thm6/20.0*2.0; thm5=171+thm6; }
else{ thm5=171; }
if((thm5+mrew[hwin])>winwy[hwin] -3){
thm3=(thm5+mrew[hwin])-(winwy[hwin]-3);
thm3=thm3*20.0/2.0;
mres[hwin]-=thm3;
}
if(editcrea>0){ edestroy=1; SetTimer(hwnd,1,100,NULL); }
SetRect(&rc,winx[curwin-1],winy[curwin-1],winx[curwin-1]+winwx[curwin-1],winy[curwin-1]+winwy[curwin-1]);
ValidateRect(hwnd,&rc); InvalidateRect(hwnd,NULL,TRUE); }

	break; }

	case WM_LBUTTONDOWN: {

	if (plane==2&&game1==FALSE) {
if(obmen==1){
if(mpo1-obx>0&&mpo1-obx<180&&mpo2-oby>0&&mpo2-oby<60){ }
else{ 
if(furs==1){
if(mensel>=0){ lip[mensel-1].x=mlik; lip[mensel-1].y=fclick; }
}
obmen=0; ValidateRect(hwnd,NULL); InvalidateRect(hwnd,NULL,TRUE); }
}
else{
if(mpo1>csize/2-8&&mpo1<csize/2+14&&mpo2>26&&mpo2<48){ game1=TRUE; ValidateRect(hwnd,NULL); InvalidateRect(hwnd,NULL,TRUE); }
		if (causo > 0) { mdon = 1; }
		final();
if (layout != 10&&layout!=12) { if (curwin == 1) { ou = scrn1; }if (curwin == 2) { ou = scrn2; }if (curwin == 3) { ou = scrn3; }if (curwin == 4) { ou = scrn4; }if (curwin == 5) { ou = scrn5; }if (curwin == 6) { ou = scrn6; } }
if(layout==10){ if (curwin == 4) { ou = scrn1; }if (curwin ==1) { ou = scrn2; }if (curwin == 2) { ou = scrn3; }if (curwin == 3) { ou = scrn4; } }
if (layout == 12) { if (curwin == 2) { ou = scrn1; }if (curwin == 3) { ou = scrn2; }if (curwin == 4) { ou = scrn3; }if (curwin == 1) { ou = scrn4; } }

if(editcrea>0){ 
SendMessage(hedit,WM_GETTEXT,sizeof(how3)/sizeof(how3[0]),reinterpret_cast<LPARAM>(how3));
edicek();
DestroyWindow(hedit); SetFocus(hwnd);
editcrea=0; hc=LoadCursor(NULL,IDC_ARROW); SetCursor(hc);
}


//EDITS
if(ou==3&&causo==0){ hwin=curwin-1;
if(lkik>=0){
if(mpo1-winx[hwin]>winwx[hwin]-40&&mpo1-winx[hwin]<winwx[hwin]-22&&typz==0&&mpo2-winy[hwin]>316-pres[hwin]&&mpo2-winy[hwin]<336-pres[hwin]){ lip[lkik].x=-1; lip[lkik].y=-1; ValidateRect(hwnd,NULL); InvalidateRect(hwnd,NULL,TRUE); }
if(mpo1-winx[hwin]>winwx[hwin]-40&&mpo1-winx[hwin]<winwx[hwin]-22&&typz==1&&mpo2-winy[hwin]>376-pres[hwin]&&mpo2-winy[hwin]<396-pres[hwin]){ lip[lkik].x=-1; lip[lkik].y=-1; ValidateRect(hwnd,NULL); InvalidateRect(hwnd,NULL,TRUE); }
if(mpo1-winx[hwin]>winwx[hwin]-40&&mpo1-winx[hwin]<winwx[hwin]-22&&typz==2&&mpo2-winy[hwin]>251-pres[hwin]&&mpo2-winy[hwin]<271-pres[hwin]){ lip[lkik].x=-1; lip[lkik].y=-1; ValidateRect(hwnd,NULL); InvalidateRect(hwnd,NULL,TRUE); }
}

if(mlik>=0||fclick>=0){
	//first
if(mpo1-winx[hwin]>20&&mpo1-winx[hwin]<(winwx[hwin]/3)-7&&mpo2-winy[hwin]>180-pres[hwin]&&mpo2-winy[hwin]<194-pres[hwin]&&mpo2-winy[hwin]>35&&mpo1-winx[hwin]>10){
if(mlik>=0&&fclick<0){ sprintf(how3,"%f",scil[mlik].x); }
if(mlik>=0&&fclick>=0){ sprintf(how3,"%f",scal[mlik][fclick].x); }
hedit=CreateWindow("edit",how3,WS_CHILD|WS_CLIPCHILDREN|ES_MULTILINE|ES_AUTOVSCROLL|WS_VISIBLE,23+winx[hwin],180+winy[hwin]-pres[hwin],(winwx[hwin]/3)-30,14,hwnd,(HMENU)EDIT1,GetModuleHandle(NULL),NULL);
hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
SendMessage(hedit,WM_SETFONT,(WPARAM)hf,1);
editcrea=7;
thm2=mpo1-(25+winx[hwin]);
SetFocus(hedit);
SendMessage(hedit,EM_SETSEL,(WPARAM)thm2/6,(LPARAM)thm2/6);
}
//second
if(mpo1-winx[hwin]>20+(winwx[hwin]/3)&&mpo1-winx[hwin]<(winwx[hwin]/3*2)-7&&mpo2-winy[hwin]>180-pres[hwin]&&mpo2-winy[hwin]<194-pres[hwin]&&mpo2-winy[hwin]>35&&mpo1-winx[hwin]>10){
if(mlik>=0&&fclick<0){ sprintf(how3,"%f",scil[mlik].y); }
if(mlik>=0&&fclick>=0){ sprintf(how3,"%f",scal[mlik][fclick].y); }
hedit=CreateWindow("edit",how3,WS_CHILD|WS_CLIPCHILDREN|ES_MULTILINE|ES_AUTOVSCROLL|WS_VISIBLE,23+winx[hwin]+(winwx[hwin]/3),180+winy[hwin]-pres[hwin],(winwx[hwin]/3)-30,14,hwnd,(HMENU)EDIT1,GetModuleHandle(NULL),NULL);
hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
SendMessage(hedit,WM_SETFONT,(WPARAM)hf,1);
editcrea=8;
thm2=mpo1-(25+winx[hwin]+(winwx[hwin]/3));
SetFocus(hedit);
SendMessage(hedit,EM_SETSEL,(WPARAM)thm2/6,(LPARAM)thm2/6);
}

//third
if(mpo1-winx[hwin]>20+(winwx[hwin]/3*2)&&mpo1-winx[hwin]<winwx[hwin]-13&&mpo2-winy[hwin]>180-pres[hwin]&&mpo2-winy[hwin]<194-pres[hwin]&&mpo2-winy[hwin]>35&&mpo1-winx[hwin]>10){
if(mlik>=0&&fclick<0){ sprintf(how3,"%f",scil[mlik].z); }
if(mlik>=0&&fclick>=0){ sprintf(how3,"%f",scal[mlik][fclick].z); }
hedit=CreateWindow("edit",how3,WS_CHILD|WS_CLIPCHILDREN|ES_MULTILINE|ES_AUTOVSCROLL|WS_VISIBLE,23+winx[hwin]+(winwx[hwin]/3*2),180+winy[hwin]-pres[hwin],(winwx[hwin]/3)-35,14,hwnd,(HMENU)EDIT1,GetModuleHandle(NULL),NULL);
hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
SendMessage(hedit,WM_SETFONT,(WPARAM)hf,1);
editcrea=9;
thm2=mpo1-(25+winx[hwin]+(winwx[hwin]/3*2));
SetFocus(hedit);
SendMessage(hedit,EM_SETSEL,(WPARAM)thm2/6,(LPARAM)thm2/6);
}

}

if(jlik>=0){
if(mpo1-winx[hwin]>30&&mpo1-winx[hwin]<(winwx[hwin]/2)-7&&mpo2-winy[hwin]>169-pres[hwin]&&mpo2-winy[hwin]<186-pres[hwin]&&mpo2-winy[hwin]>35&&mpo1-winx[hwin]>10){
//camera
if(jlik>=0){
	for (int a = 0,b=0,e=0;a < strlen(camera);a++){
		if(b>=jlik){ 
		for(0;a<strlen(camera);a++){ how1[e]=camera[a]; e++; if(camera[a+1]==':'){ how1[e]=0; break;} } a+=2; e=0; 
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;hstp=a;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		hcnp=a;
		break;}
		if (camera[a] == ';'){ b++;}
		}
}
hedit=CreateWindow("edit",how3,WS_CHILD|WS_CLIPCHILDREN|ES_MULTILINE|ES_AUTOVSCROLL|WS_VISIBLE,33+winx[hwin],170+winy[hwin]-pres[hwin],(winwx[hwin]/2)-41,14,hwnd,(HMENU)EDIT1,GetModuleHandle(NULL),NULL);
hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
SendMessage(hedit,WM_SETFONT,(WPARAM)hf,1);
editcrea=10;
thm2=mpo1-(33+winx[hwin]);
SetFocus(hedit);
SendMessage(hedit,EM_SETSEL,(WPARAM)thm2/6,(LPARAM)thm2/6);
}
//near fov	
if(mpo1-winx[hwin]>40+(winwx[hwin]/2)&&mpo1-winx[hwin]<(winwx[hwin]-12)-7&&mpo2-winy[hwin]>169-pres[hwin]&&mpo2-winy[hwin]<186-pres[hwin]&&mpo2-winy[hwin]>35&&mpo1-winx[hwin]>10){
//camera
if(jlik>=0){
	for (int a = 0,b=0,e=0;a < strlen(camera);a++){
		if(b>=jlik){ 
		for(0;a<strlen(camera);a++){ how1[e]=camera[a]; e++; if(camera[a+1]==':'){ how1[e]=0; break;} } a+=2; e=0; 
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;hstp=a;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		hcnp=a;
		break;}
		if (camera[a] == ';'){ b++;}
		}
}
hedit=CreateWindow("edit",how3,WS_CHILD|WS_CLIPCHILDREN|ES_MULTILINE|ES_AUTOVSCROLL|WS_VISIBLE,45+winx[hwin]+(winwx[hwin]/2),170+winy[hwin]-pres[hwin],(winwx[hwin]-12)-(winwx[hwin]/2)-47,14,hwnd,(HMENU)EDIT1,GetModuleHandle(NULL),NULL);
hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
SendMessage(hedit,WM_SETFONT,(WPARAM)hf,1);
editcrea=10;
thm2=mpo1-(45+winx[hwin]+(winwx[hwin]/2));
SetFocus(hedit);
SendMessage(hedit,EM_SETSEL,(WPARAM)thm2/6,(LPARAM)thm2/6);
}

//near ratio	
if(mpo1-winx[hwin]>10&&mpo1-winx[hwin]<(winwx[hwin]/2)-7&&mpo2-winy[hwin]>209-pres[hwin]&&mpo2-winy[hwin]<226-pres[hwin]&&mpo2-winy[hwin]>35&&mpo1-winx[hwin]>10){
//camera
if(jlik>=0){
	for (int a = 0,b=0,e=0;a < strlen(camera);a++){
if(b>=jlik){ 
for(0;a<strlen(camera);a++){ how1[e]=camera[a]; e++; if(camera[a+1]==':'){ how1[e]=0; break;} } a+=2; e=0; 
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;hstp=a;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
hcnp=a;
break;}
if (camera[a] == ';'){ b++;}
}
}
hedit=CreateWindow("edit",how3,WS_CHILD|WS_CLIPCHILDREN|ES_MULTILINE|ES_AUTOVSCROLL|WS_VISIBLE,11+winx[hwin],210+winy[hwin]-pres[hwin],(winwx[hwin]/2)-18,14,hwnd,(HMENU)EDIT1,GetModuleHandle(NULL),NULL);
hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
SendMessage(hedit,WM_SETFONT,(WPARAM)hf,1);
editcrea=10;
thm2=mpo1-(11+winx[hwin]);
SetFocus(hedit);
SendMessage(hedit,EM_SETSEL,(WPARAM)thm2/6,(LPARAM)thm2/6);
}

//near ratio	
if(mpo1-winx[hwin]>19+(winwx[hwin]/2)&&mpo1-winx[hwin]<(winwx[hwin]-12)&&mpo2-winy[hwin]>209-pres[hwin]&&mpo2-winy[hwin]<226-pres[hwin]&&mpo2-winy[hwin]>35&&mpo1-winx[hwin]>10){
//camera
if(jlik>=0){
for (int a = 0,b=0,e=0;a < strlen(camera);a++){
if(b>=jlik){ 
for(0;a<strlen(camera);a++){ how1[e]=camera[a]; e++; if(camera[a+1]==':'){ how1[e]=0; break;} } a+=2; e=0; 
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;hstp=a;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
hcnp=a;
break;}
if (camera[a] == ';'){ b++;}
}
}
hedit=CreateWindow("edit",how3,WS_CHILD|WS_CLIPCHILDREN|ES_MULTILINE|ES_AUTOVSCROLL|WS_VISIBLE,24+winx[hwin]+(winwx[hwin]/2),210+winy[hwin]-pres[hwin],(winwx[hwin]-12)-26-(winwx[hwin]/2),14,hwnd,(HMENU)EDIT1,GetModuleHandle(NULL),NULL);
hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
SendMessage(hedit,WM_SETFONT,(WPARAM)hf,1);
editcrea=10;
thm2=mpo1-(24+(winwx[hwin]/2)+winx[hwin]);
SetFocus(hedit);
SendMessage(hedit,EM_SETSEL,(WPARAM)thm2/6,(LPARAM)thm2/6);
}

//near scl	
if(mpo1-winx[hwin]>40&&mpo1-winx[hwin]<(winwx[hwin]-12)-7&&mpo2-winy[hwin]>229-pres[hwin]&&mpo2-winy[hwin]<246-pres[hwin]&&mpo2-winy[hwin]>35&&mpo1-winx[hwin]>10){
//camera
if(jlik>=0){
for (int a = 0,b=0,e=0;a < strlen(camera);a++){
if(b>=jlik){ 
for(0;a<strlen(camera);a++){ how1[e]=camera[a]; e++; if(camera[a+1]==':'){ how1[e]=0; break;} } a+=2; e=0; 
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;hstp=a;
for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
hcnp=a;
break;}
if (camera[a] == ';'){ b++;}
}
}
hedit=CreateWindow("edit",how3,WS_CHILD|WS_CLIPCHILDREN|ES_MULTILINE|ES_AUTOVSCROLL|WS_VISIBLE,43+winx[hwin],230+winy[hwin]-pres[hwin],(winwx[hwin]-12)-45,14,hwnd,(HMENU)EDIT1,GetModuleHandle(NULL),NULL);
hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
SendMessage(hedit,WM_SETFONT,(WPARAM)hf,1);
editcrea=10;
thm2=mpo1-(43+winx[hwin]);
SetFocus(hedit);
SendMessage(hedit,EM_SETSEL,(WPARAM)thm2/6,(LPARAM)thm2/6);
}



}


if(mlik>=0||fclick>=0||lkik>=0||jlik>=0){
//first
if(mpo1-winx[hwin]>20&&mpo1-winx[hwin]<(winwx[hwin]/3)-7&&mpo2-winy[hwin]>100-pres[hwin]&&mpo2-winy[hwin]<114-pres[hwin]&&mpo2-winy[hwin]>35&&mpo1-winx[hwin]>10){
if(mlik>=0&&fclick<0){ sprintf(how3,"%f",px + mauv[mlik].x); }
if(mlik>=0&&fclick>=0){ sprintf(how3,"%f",px + mauv[mlik].x+gauv[mlik][fclick].x); }
if(lkik>=0){
for (int a = 0, b = 0, e = 0;a < strlen(light);a++) {
			if (b >= lkik) {
	for (0;a<strlen(light);a++) { how1[e] = light[a]; e++; if (light[a + 1] == ':') { how1[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0; hstp=a;
	for (0;a<strlen(light);a++) { how3[e] = light[a]; e++; if (light[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
	hcnp=a;
	break;
			}
			if (light[a] == ';') { b++; }
		}
}
//end of light
if(jlik>=0){
	for (int a = 0,b=0,e=0;a < strlen(camera);a++){
		if(b>=jlik){ 
		for(0;a<strlen(camera);a++){ how1[e]=camera[a]; e++; if(camera[a+1]==':'){ how1[e]=0; break;} } a+=2; e=0; hstp=a;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		hcnp=a;
		break;}
		if (camera[a] == ';'){ b++;}
		}
}
hedit=CreateWindow("edit",how3,WS_CHILD|WS_CLIPCHILDREN|ES_MULTILINE|ES_AUTOVSCROLL|WS_VISIBLE,23+winx[hwin],100+winy[hwin]-pres[hwin],(winwx[hwin]/3)-30,14,hwnd,(HMENU)EDIT1,GetModuleHandle(NULL),NULL);
hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
SendMessage(hedit,WM_SETFONT,(WPARAM)hf,1);
editcrea=1;
thm2=mpo1-(25+winx[hwin]);
SetFocus(hedit);
SendMessage(hedit,EM_SETSEL,(WPARAM)thm2/6,(LPARAM)thm2/6);
}
//second
if(mpo1-winx[hwin]>20+(winwx[hwin]/3)&&mpo1-winx[hwin]<(winwx[hwin]/3*2)-7&&mpo2-winy[hwin]>100-pres[hwin]&&mpo2-winy[hwin]<114-pres[hwin]&&mpo2-winy[hwin]>35&&mpo1-winx[hwin]>10){
if(mlik>=0&&fclick<0){ sprintf(how3,"%f",py + mauv[mlik].y); }
if(mlik>=0&&fclick>=0){ sprintf(how3,"%f",py + mauv[mlik].y+gauv[mlik][fclick].y); }
if(lkik>=0){
for (int a = 0, b = 0, e = 0;a < strlen(light);a++) {
			if (b >= lkik) {
	for (0;a<strlen(light);a++) { how1[e] = light[a]; e++; if (light[a + 1] == ':') { how1[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0; hstp=a;
	for (0;a<strlen(light);a++) { how3[e] = light[a]; e++; if (light[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
	hcnp=a;
	break;
			}
			if (light[a] == ';') { b++; }
		}
}
//end of light
if(jlik>=0){
	for (int a = 0,b=0,e=0;a < strlen(camera);a++){
		if(b>=jlik){ 
		for(0;a<strlen(camera);a++){ how1[e]=camera[a]; e++; if(camera[a+1]==':'){ how1[e]=0; break;} } a+=2; e=0; 
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;hstp=a;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		hcnp=a;
		break;}
		if (camera[a] == ';'){ b++;}
		}
}
hedit=CreateWindow("edit",how3,WS_CHILD|WS_CLIPCHILDREN|ES_MULTILINE|ES_AUTOVSCROLL|WS_VISIBLE,23+winx[hwin]+(winwx[hwin]/3),100+winy[hwin]-pres[hwin],(winwx[hwin]/3)-30,14,hwnd,(HMENU)EDIT1,GetModuleHandle(NULL),NULL);
hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
SendMessage(hedit,WM_SETFONT,(WPARAM)hf,1);
editcrea=2;
thm2=mpo1-(25+winx[hwin]+(winwx[hwin]/3));
SetFocus(hedit);
SendMessage(hedit,EM_SETSEL,(WPARAM)thm2/6,(LPARAM)thm2/6);
}

//third
if(mpo1-winx[hwin]>20+(winwx[hwin]/3*2)&&mpo1-winx[hwin]<winwx[hwin]-13&&mpo2-winy[hwin]>100-pres[hwin]&&mpo2-winy[hwin]<114-pres[hwin]&&mpo2-winy[hwin]>35&&mpo1-winx[hwin]>10){
if(mlik>=0&&fclick<0){ sprintf(how3,"%f",pz + mauv[mlik].z); }
if(mlik>=0&&fclick>=0){ sprintf(how3,"%f",pz + mauv[mlik].z+gauv[mlik][fclick].z); }
if(lkik>=0){
for (int a = 0, b = 0, e = 0;a < strlen(light);a++) {
	if (b >= lkik) {
	for (0;a<strlen(light);a++) { how1[e] = light[a]; e++; if (light[a + 1] == ':') { how1[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0; hstp=a;
	for (0;a<strlen(light);a++) { how3[e] = light[a]; e++; if (light[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
	hcnp=a;
	break;
			}
			if (light[a] == ';') { b++; }
		}
}
//end of light
if(jlik>=0){
	for (int a = 0,b=0,e=0;a < strlen(camera);a++){
		if(b>=jlik){ 
		for(0;a<strlen(camera);a++){ how1[e]=camera[a]; e++; if(camera[a+1]==':'){ how1[e]=0; break;} } a+=2; e=0; 
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;hstp=a;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		hcnp=a;
		break;}
		if (camera[a] == ';'){ b++;}
		}
}
hedit=CreateWindow("edit",how3,WS_CHILD|WS_CLIPCHILDREN|ES_MULTILINE|ES_AUTOVSCROLL|WS_VISIBLE,23+winx[hwin]+(winwx[hwin]/3*2),100+winy[hwin]-pres[hwin],(winwx[hwin]/3)-35,14,hwnd,(HMENU)EDIT1,GetModuleHandle(NULL),NULL);
hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
SendMessage(hedit,WM_SETFONT,(WPARAM)hf,1);
editcrea=3;
thm2=mpo1-(25+winx[hwin]+(winwx[hwin]/3*2));
SetFocus(hedit);
SendMessage(hedit,EM_SETSEL,(WPARAM)thm2/6,(LPARAM)thm2/6);
}
//rotation
//first
if(mpo1-winx[hwin]>20&&mpo1-winx[hwin]<(winwx[hwin]/3)-7&&mpo2-winy[hwin]>140-pres[hwin]&&mpo2-winy[hwin]<154-pres[hwin]&&mpo2-winy[hwin]>35&&mpo1-winx[hwin]>10){
if(mlik>=0&&fclick<0){ sprintf(how3,"%f",rita[mlik].x); }
if(mlik>=0&&fclick>=0){ sprintf(how3,"%f",rota[mlik][fclick].x); }
free1=0;
if(lkik>=0){
for (int a = 0, b = 0, e = 0;a < strlen(light);a++) {
	if (b >= lkik) {
	for (0;a<strlen(light);a++) { how1[e] = light[a]; e++; if (light[a + 1] == ':') { how1[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0; free1=atoi(cls1);
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0; hstp=a;
	for (0;a<strlen(light);a++) { how3[e] = light[a]; e++; if (light[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
	hcnp=a;
	break;
			}
			if (light[a] == ';') { b++; }
		}
}
//end of light
if(jlik>=0){
	for (int a = 0,b=0,e=0;a < strlen(camera);a++){
		if(b>=jlik){ 
		for(0;a<strlen(camera);a++){ how1[e]=camera[a]; e++; if(camera[a+1]==':'){ how1[e]=0; break;} } a+=2; e=0; 
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;hstp=a;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		hcnp=a;
		break;}
		if (camera[a] == ';'){ b++;}
		}
}
if(free1==0){
hedit=CreateWindow("edit",how3,WS_CHILD|WS_CLIPCHILDREN|ES_MULTILINE|ES_AUTOVSCROLL|WS_VISIBLE,23+winx[hwin],140+winy[hwin]-pres[hwin],(winwx[hwin]/3)-30,14,hwnd,(HMENU)EDIT1,GetModuleHandle(NULL),NULL);
hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
SendMessage(hedit,WM_SETFONT,(WPARAM)hf,1);
editcrea=4;
thm2=mpo1-(25+winx[hwin]);
SetFocus(hedit);
SendMessage(hedit,EM_SETSEL,(WPARAM)thm2/6,(LPARAM)thm2/6);
}
}
//second
if(mpo1-winx[hwin]>20+(winwx[hwin]/3)&&mpo1-winx[hwin]<(winwx[hwin]/3*2)-7&&mpo2-winy[hwin]>140-pres[hwin]&&mpo2-winy[hwin]<154-pres[hwin]&&mpo2-winy[hwin]>35&&mpo1-winx[hwin]>10){
if(mlik>=0&&fclick<0){ sprintf(how3,"%f",rita[mlik].y); }
if(mlik>=0&&fclick>=0){ sprintf(how3,"%f",rota[mlik][fclick].y); }
free1=0;
if(lkik>=0){
for (int a = 0, b = 0, e = 0;a < strlen(light);a++) {
	if (b >= lkik) {
	for (0;a<strlen(light);a++) { how1[e] = light[a]; e++; if (light[a + 1] == ':') { how1[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0; free1=atoi(cls1);
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0; hstp=a;
	for (0;a<strlen(light);a++) { how3[e] = light[a]; e++; if (light[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
	hcnp=a;
	break;
			}
			if (light[a] == ';') { b++; }
		}
}
//end of light
if(jlik>=0){
	for (int a = 0,b=0,e=0;a < strlen(camera);a++){
		if(b>=jlik){ 
		for(0;a<strlen(camera);a++){ how1[e]=camera[a]; e++; if(camera[a+1]==':'){ how1[e]=0; break;} } a+=2; e=0; 
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;hstp=a;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		hcnp=a;
		break;}
		if (camera[a] == ';'){ b++;}
		}
}
if(free1==0){
hedit=CreateWindow("edit",how3,WS_CHILD|WS_CLIPCHILDREN|ES_MULTILINE|ES_AUTOVSCROLL|WS_VISIBLE,23+winx[hwin]+(winwx[hwin]/3),140+winy[hwin]-pres[hwin],(winwx[hwin]/3)-30,14,hwnd,(HMENU)EDIT1,GetModuleHandle(NULL),NULL);
hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
SendMessage(hedit,WM_SETFONT,(WPARAM)hf,1);
editcrea=5;
thm2=mpo1-(25+winx[hwin]+(winwx[hwin]/3));
SetFocus(hedit);
SendMessage(hedit,EM_SETSEL,(WPARAM)thm2/6,(LPARAM)thm2/6);
}
}

//third
if(mpo1-winx[hwin]>20+(winwx[hwin]/3*2)&&mpo1-winx[hwin]<winwx[hwin]-13&&mpo2-winy[hwin]>140-pres[hwin]&&mpo2-winy[hwin]<154-pres[hwin]&&mpo2-winy[hwin]>35&&mpo1-winx[hwin]>10){
if(mlik>=0&&fclick<0){ sprintf(how3,"%f",rita[mlik].z); }
if(mlik>=0&&fclick>=0){ sprintf(how3,"%f",rota[mlik][fclick].z); }
free1=0;
if(lkik>=0){
for (int a = 0, b = 0, e = 0;a < strlen(light);a++) {
	if (b >= lkik) {
	for (0;a<strlen(light);a++) { how1[e] = light[a]; e++; if (light[a + 1] == ':') { how1[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0; free1=atoi(cls1);
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0; hstp=a;
	for (0;a<strlen(light);a++) { how3[e] = light[a]; e++; if (light[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
	hcnp=a;
	break;
			}
			if (light[a] == ';') { b++; }
		}
}
//end of light
if(jlik>=0){
	for (int a = 0,b=0,e=0;a < strlen(camera);a++){
		if(b>=jlik){ 
		for(0;a<strlen(camera);a++){ how1[e]=camera[a]; e++; if(camera[a+1]==':'){ how1[e]=0; break;} } a+=2; e=0; 
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;hstp=a;
		for (0;a<strlen(camera);a++) { how3[e] = camera[a]; e++; if (camera[a + 1] == ',') { how3[e] = 0; break; } } a += 2; e = 0;
		hcnp=a;
		break;}
		if (camera[a] == ';'){ b++;}
		}
}
if(free1==0){
hedit=CreateWindow("edit",how3,WS_CHILD|WS_CLIPCHILDREN|ES_MULTILINE|ES_AUTOVSCROLL|WS_VISIBLE,23+winx[hwin]+(winwx[hwin]/3*2),140+winy[hwin]-pres[hwin],(winwx[hwin]/3)-35,14,hwnd,(HMENU)EDIT1,GetModuleHandle(NULL),NULL);
hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
SendMessage(hedit,WM_SETFONT,(WPARAM)hf,1);
editcrea=6;
thm2=mpo1-(25+winx[hwin]+(winwx[hwin]/3*2));
SetFocus(hedit);
SendMessage(hedit,EM_SETSEL,(WPARAM)thm2/6,(LPARAM)thm2/6);
}
}


}

}
//END OF EDITS

if (ou == 2&&mpo2>winy[curwin-1]+20&&mdon==0) {
	roll = 1; hwin = curwin - 1;  if(grab[hwin]!=0){ hc = LoadCursor(GetModuleHandle(NULL), "CUR3"); SetCursor(hc); }else{ SetCapture(hwnd); }
}
if (ou == 5 &&mpo1<winx[curwin-1]+winwx[curwin-1]-12&& mpo2>winy[curwin - 1] + 20 && mdon == 0&&selet[curwin - 1] !=0) {
	hwin = curwin - 1;	huld = icontent[selet[curwin - 1] - 1]; selet4 = selet[curwin - 1] - 1; selet3 = 1; hc = LoadCursor(GetModuleHandle(NULL), "CUR"); SetCursor(hc); count = 0;
}
if (ou == 8 && mpo2 - winy[curwin - 1] > 20) {
	if(mpo1-winx[curwin-1]>2&&mpo1-winx[curwin-1]<20&&mpo2-winy[curwin-1]>30&&mpo2-winy[curwin-1]<47){ 
		if (peep == 0) { peep = 1; }else{ peep=0; }
	}
	ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
}

if (ou == 7 && mpo2 > winy[curwin - 1] + 170 && manon >= 0) {
	if (mpo1 - winx[curwin - 1]>10 && mpo1 - winx[curwin - 1]<20 && mpo2 - winy[curwin - 1]>247-mres[curwin-1] && mpo2 - winy[curwin - 1]<257-mres[curwin-1] && matprop[mlik][manon].tex >= 0) {
		if (matprop[mlik][manon].text == 0) { matprop[mlik][manon].text = 1; }else { matprop[mlik][manon].text = 0; }
		ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
	}
	if (mpo1 - winx[curwin - 1]>10 && mpo1 - winx[curwin - 1]<20 && mpo2 - winy[curwin - 1]>533 - mres[curwin - 1] && mpo2 - winy[curwin - 1]<543 - mres[curwin - 1] && matprop[mlik][manon].emK >= 0) {
		if (matprop[mlik][manon].emK == 0) { matprop[mlik][manon].emK = 1; }
		else { matprop[mlik][manon].emK = 0; }
		ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
	}
	if (mpo1 - winx[curwin - 1]>10 && mpo1 - winx[curwin - 1]<20 && mpo2 - winy[curwin - 1]>572-mres[curwin-1] && mpo2 - winy[curwin - 1]<582-mres[curwin-1]) {
		matprop[mlik][manon].emt=1;
		ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
	}
	if (mpo1 - winx[curwin - 1]>75 && mpo1 - winx[curwin - 1]<85 && mpo2 - winy[curwin - 1]>572-mres[curwin-1] && mpo2 - winy[curwin - 1]<582-mres[curwin-1]) {
		matprop[mlik][manon].emt=2;
		ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
	}
	if (mpo1 - winx[curwin-1]>135&&mpo1-winx[curwin-1]<145&&mpo2-winy[curwin-1]>572-mres[curwin-1]&&mpo2-winy[curwin-1]<582-mres[curwin-1]){
		matprop[mlik][manon].emt=3;
		ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
	}
	if (mpo1 - winx[curwin-1]>10&&mpo1-winx[curwin-1]<20&&mpo2-winy[curwin-1]>702-mres[curwin-1]&&mpo2-winy[curwin-1]<712-mres[curwin-1]&& matprop[mlik][manon].rfk>=0){
		if (matprop[mlik][manon].rfk == 0) { matprop[mlik][manon].rfk = 1; }else { matprop[mlik][manon].rfk = 0; }
		ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
	}

	if (mpo1 - winx[curwin - 1]>10 && mpo1 - winx[curwin - 1]<20 && mpo2 - winy[curwin - 1]>445-mres[curwin-1] && mpo2 - winy[curwin - 1]<455-mres[curwin-1] && matprop[mlik][manon].sm >= 0) {
		if (matprop[mlik][manon].sm == 0) { matprop[mlik][manon].sm = 1; }else { matprop[mlik][manon].sm = 0; }
		ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
	}
	if (mpo1 - winx[curwin - 1]>10 && mpo1 - winx[curwin - 1]<20 && mpo2 - winy[curwin - 1]>292-mres[curwin-1] && mpo2 - winy[curwin - 1]<302-mres[curwin-1] && matprop[mlik][manon].bump >= 0) {
		if (matprop[mlik][manon].bum == 0) { matprop[mlik][manon].bum = 1; }else { matprop[mlik][manon].bum = 0; }
	ValidateRect(hwnd,&client); InvalidateRect(hwnd,&client,TRUE);
	}
	if (mpo1 - winx[curwin - 1]>10 && mpo1 - winx[curwin - 1]<20 && mpo2 - winy[curwin - 1]>344-mres[curwin-1] && mpo2 - winy[curwin - 1]<354-mres[curwin-1]) {
	if (matprop[mlik][manon].shade==1) { matprop[mlik][manon].shade=0; }else { matprop[mlik][manon].shade=1; }
	ValidateRect(hwnd,&client); InvalidateRect(hwnd,&client,TRUE);
	}
	//emmision color
	if (mpo1 - winx[curwin - 1]>10 && mpo1 - winx[curwin - 1]<winwx[curwin-1]-14&&mpo2-winy[curwin-1]>590-mres[curwin-1]&&mpo2-winy[curwin-1]<607-mres[curwin-1] ) {
	zcolor=RGB(matprop[mlik][manon].emr*255,matprop[mlik][manon].emg*255,matprop[mlik][manon].emb*255);
	ccz.lStructSize = sizeof(CHOOSECOLOR);
	ccz.hwndOwner = hwnd;
	ccz.hInstance = NULL;
	ccz.rgbResult = zcolor;
	ccz.lpCustColors = zref;
	ccz.Flags = CC_RGBINIT | CC_FULLOPEN;
	ccz.lpfnHook = NULL;
	if (ChooseColor(&ccz)) {
	zcolor=ccz.rgbResult;
	matprop[mlik][manon].emr =GetRValue(zcolor)/255.0;	matprop[mlik][manon].emg=GetGValue(zcolor)/255.0;	matprop[mlik][manon].emb=GetBValue(zcolor)/255.0;
	
	ValidateRect(hwnd,&client); InvalidateRect(hwnd,&client,TRUE);
	}
	}
	if (mpo1 - winx[curwin - 1]>10 && mpo1 - winx[curwin - 1]<winwx[curwin-1]-14 && mpo2 - winy[curwin - 1]>200-mres[curwin-1] && mpo2 - winy[curwin - 1]<215-mres[curwin-1] ) {
			bu=matprop[mlik][manon].Kd;
			zcolor=RGB(colr[mlik][bu].x*255,colr[mlik][bu].y*255,colr[mlik][bu].z*255);
			ccz.lStructSize = sizeof(CHOOSECOLOR);
			ccz.hwndOwner = hwnd;
			ccz.hInstance = NULL;
			ccz.rgbResult = zcolor;
			ccz.lpCustColors = zref;
			ccz.Flags = CC_RGBINIT | CC_FULLOPEN;
			ccz.lpfnHook = NULL;
			if (ChooseColor(&ccz)) {
	zcolor=ccz.rgbResult;
	bu=matprop[mlik][manon].Kd;
	colr[mlik][bu].x =GetRValue(zcolor)/255.0;	colr[mlik][bu].y=GetGValue(zcolor) / 255.0;	colr[mlik][bu].z =GetBValue(zcolor) / 255.0;
	
	ValidateRect(hwnd,&client); InvalidateRect(hwnd,&client,TRUE);
	}
	}
	//specular
	if (mpo1 - winx[curwin - 1]>50 && mpo1 - winx[curwin - 1]<winwx[curwin-1]-14 && mpo2 - winy[curwin - 1]>385-mres[curwin-1] && mpo2 - winy[curwin - 1]<400-mres[curwin-1] ) {
			bu=matprop[mlik][manon].Ks;
			zcolor=RGB(colr[mlik][bu].x*255,colr[mlik][bu].y*255,colr[mlik][bu].z*255);
			ccz.lStructSize = sizeof(CHOOSECOLOR);
			ccz.hwndOwner = hwnd;
			ccz.hInstance = NULL;
			ccz.rgbResult = zcolor;
			ccz.lpCustColors = zref;
			ccz.Flags = CC_RGBINIT | CC_FULLOPEN;
			ccz.lpfnHook = NULL;
			if (ChooseColor(&ccz)) {
	zcolor=ccz.rgbResult;
	bu=matprop[mlik][manon].Ks;
	colr[mlik][bu].x =GetRValue(zcolor)/255.0;	colr[mlik][bu].y=GetGValue(zcolor) / 255.0;	colr[mlik][bu].z =GetBValue(zcolor) / 255.0;
	
	ValidateRect(hwnd,&client); InvalidateRect(hwnd,&client,TRUE);
	}
	}

}
if (ou == 7 && mpo2 > winy[curwin - 1] + 20&&mpo2<winy[curwin-1]+170&&manon>=0) {
	
	if (mpo1 - winx[curwin - 1] > 10 && mpo1 - winx[curwin - 1] < 40 && mpo2 - winy[curwin - 1]>30 && mpo2 - winy[curwin - 1] < 125) {
		if(mpo2-winy[curwin-1]>30&&mpo2-winy[curwin-1]<52){ 
			sprintf(how1, "%sbinaries\\cube.bin", wild);
			fi = fopen(how1, "r");
			if (fi != NULL) {
				fseek(fi, 0, SEEK_END);
				ou = ftell(fi);
				fseek(fi, 0, SEEK_SET);
				for (int a = 0;a < ou;a++) { square[a] = (fgetc(fi) - 100) / 25.0; }
				fclose(fi);
				bull = ou;
			}
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
	if(mpo2-winy[curwin-1]>52&&mpo2-winy[curwin-1]<68){ 
			sprintf(how1, "%sbinaries\\plane.bin", wild);
			fi = fopen(how1, "r");
			if (fi != NULL) {
				fseek(fi, 0, SEEK_END);
				ou = ftell(fi);
				fseek(fi, 0, SEEK_SET);
				for (int a = 0,b=0;a < ou;a++,b++) { square[a] = (fgetc(fi) - 100) / 25.0; }
				fclose(fi);
				bull = ou;
			}
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
	if(mpo2-winy[curwin-1]>70&&mpo2-winy[curwin-1]<84){ 
			sprintf(how1, "%sbinaries\\circle.bin", wild);
			fi = fopen(how1, "r");
			if (fi != NULL) {
				fseek(fi, 0, SEEK_END);
				ou = ftell(fi);
				fseek(fi, 0, SEEK_SET);
				for (int a = 0;a < ou;a++) { square[a] = (fgetc(fi) - 100) / 25.0; }
				fclose(fi);
				bull = ou;
			}
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
	if(mpo2-winy[curwin-1]>84&&mpo2-winy[curwin-1]<105){ 
			sprintf(how1, "%sbinaries\\hexagon.bin", wild);
			fi = fopen(how1, "r");
			if (fi != NULL) {
				fseek(fi, 0, SEEK_END);
				ou = ftell(fi);
				fseek(fi, 0, SEEK_SET);
				for (int a = 0;a < ou;a++) { square[a] = (fgetc(fi) - 100) / 25.0; }
				fclose(fi);
				bull = ou;
			}
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
	if(mpo2-winy[curwin-1]>106&&mpo2-winy[curwin-1]<124){ 
			sprintf(how1, "%sbinaries\\cylinder.bin", wild);
			fi = fopen(how1, "r");
			if (fi != NULL) {
				fseek(fi, 0, SEEK_END);
				ou = ftell(fi);
				fseek(fi, 0, SEEK_SET);
				for (int a = 0;a < ou;a++) { square[a] = (fgetc(fi) - 100) / 25.0; }
				fclose(fi);
				bull = ou;
			}
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
	}else{
	mdon = 1; ball = 1; hwin = curwin - 1;
	}
}
if(ou==1&&mpo1-winx[curwin-1]>winwx[curwin-1]-12&&mpo1-winx[curwin-1]<winwx[curwin-1]-2){ hwin=curwin-1; mdon=1; causo=100; }
if(ou==3&&mpo1-winx[curwin-1]>winwx[curwin-1]-12&&mpo1-winx[curwin-1]<winwx[curwin-1]-2){ hwin=curwin-1; mdon=1; causo=101; }
if(ou==5&&mpo1-winx[curwin-1]>winwx[curwin-1]-12&&mpo1-winx[curwin-1]<winwx[curwin-1]-2){ hwin=curwin-1; mdon=1; causo=102; }
if(ou==7&&mpo1-winx[curwin-1]>winwx[curwin-1]-12&&mpo1-winx[curwin-1]<winwx[curwin-1]-2&&mpo2-winy[curwin-1]>171){ hwin=curwin-1; mdon=1; causo=103; }

if (ou == 1 && mpo2 > winy[curwin - 1] + 20&&mpo1-winx[curwin-1]<winwx[curwin-1]-12) {
	
	if (oclik[curwin - 1] >= 0 && mpo1 < winx[curwin - 1] + 16) { manon = -1; if (click == oclik[curwin - 1]) {   click = -1; if(getback==1){ for(int q=0;q<6;q++){ mx[q]=fol[q].x; my[q]=fol[q].y; mz[q]=fol[q].z; } } mil=0; } else { manon = -1;  click = oclik[curwin - 1]; if (mil == 0) { mil = 1; if(getback==1){  for(int q=0;q<6;q++){ fol[q].x = mx[q]; fol[q].y = my[q]; fol[q].z = mz[q]; }} } fclick = -1; } mlik = click; jlik = -1; lkik=-1;  }
	if (oclik[curwin-1] >= 0 && mpo1 > winx[curwin - 1] + 16) { manon = -1; click=-1; if (mlik == oclik[curwin - 1]&&click<0) {  mlik = -1;  if(getback==1){ for(int q=0;q<6;q++){ mx[q]=fol[q].x; my[q]=fol[q].y; mz[q]=fol[q].z; } } mil=0; } else { manon = -1;  mlik = oclik[curwin - 1]; if(mil==0){ mil=1; if(getback==1){  for(int q=0;q<6;q++){ fol[q].x = mx[q]; fol[q].y = my[q]; fol[q].z = mz[q]; } } } fclick = -1; } jlik=-1; lkik=-1; }
	if (mclick >= 0&&mclick[curwin-1]>=0) { if (fclick == mclick[curwin - 1]) {  fclick = -1;  } else { fclick = mclick[curwin - 1]; manon = -1; }   }
	//camera
	if (jclick[curwin - 1] >= 0) { manon = -1; if(mlik>=0&&getback==1){ for (int q = 0;q<6;q++) { mx[q] = fol[q].x; my[q] = fol[q].y; mz[q] = fol[q].z; } mil=0; } if (jlik == jclick[curwin - 1]) { jlik = -1; } else { jlik = jclick[curwin - 1]; }  mlik = -1; fclick = -1; click = -1; lkik=-1; 
	
	}
	//light
	if (lclick[curwin - 1] >= 0) { manon = -1; if(mlik>=0&&getback==1){ for (int q = 0;q<6;q++) { mx[q] = fol[q].x; my[q] = fol[q].y; mz[q] = fol[q].z; } mil=0; } if (lkik == lclick[curwin - 1]) { lkik = -1; } else { lkik = lclick[curwin - 1]; }  mlik = -1; fclick = -1; click = -1; jlik=-1; }
	
	if (mlik >=0&&fclick<0&&oclik[curwin-1]>=0) { px=0; py=0; pz=0;
	for (bu=0;bu<=gcont[mlik];bu++) {
	px+=(center[mlik][bu].x+gauv[mlik][bu].x+mauv[mlik].x); py+=(center[mlik][bu].y+gauv[mlik][bu].y+mauv[mlik].y); pz+=(center[mlik][bu].z+gauv[mlik][bu].z+mauv[mlik].z);
	}
	if(bu>0){ px/=bu; py/=bu; pz/=bu; }
	}
	
	if (fclick >= 0&&mlik>=0) {
	px=center[mlik][fclick].x+ mauv[mlik].x + gauv[mlik][fclick].x;  py = center[mlik][fclick].y+ mauv[mlik].y + gauv[mlik][fclick].y; pz = center[mlik][fclick].z+ mauv[mlik].z + gauv[mlik][fclick].z;
	chkd=0;
	for (int a = 0,b=0;a < fcon[mlik];a++){ 
	if(b>fclick){ check=a+1;
	for(0;a<fcon[mlik];a++){ if(fice[mlik][a]==-2){ matdisp[chkd]=fice[mlik][a+2]; chkd++; } if(fice[mlik][a]==-3){ break; } }
	break; }
	if(fice[mlik][a]==-3){ b++; } }
		
	}

	ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
}

if (ou == 3 && mpo2 > winy[curwin - 1] + 20 && mdon == 0) { 
	hwin = curwin - 1;
	if (maclick >= 0&&mpo2>winy[hwin]+200-pres[hwin]) {
		if(manon!=maclick){ manon=maclick; sprintf(catname,"%s",matname); }else{ manon=-1; }
		ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
	}
	if(mlik>=0&&fclick<0&&mpo1-winx[hwin]>83&&mpo1-winx[hwin]<104&&mpo2-winy[hwin]>51&&mpo2-winy[hwin]<63){ if(showobj[mlik]==1){ showobj[mlik]=0;}else{ showobj[mlik]=1; } 
	ValidateRect(hwnd,NULL); InvalidateRect(hwnd,NULL,TRUE); }
	if (fclick >= 0) {
		if (mpo1 - winx[hwin] > 10 && mpo1 - winx[hwin] < 20 & mpo2 - winy[hwin]>207-pres[hwin] && mpo2 - winy[hwin] < 217-pres[hwin]) {
			if (fice[mlik][check] == -4) { fice[mlik][check] = -5; }
			else { fice[mlik][check] = -4; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (mpo1 - winx[hwin] > 110 && mpo1 - winx[hwin] < 120 & mpo2 - winy[hwin]>207-pres[hwin] && mpo2 - winy[hwin] < 217-pres[hwin]) {
			if (fice[mlik][check + 1] == -8) { fice[mlik][check + 1] = -9; }
			else { fice[mlik][check + 1] = -8; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (mpo1 - winx[hwin] > 70 && mpo1 - winx[hwin] < 80 & mpo2 - winy[hwin]>207-pres[hwin] && mpo2 - winy[hwin] < 217-pres[hwin]) {
			if (fice[mlik][check + 2] == -10) { fice[mlik][check + 2] = -11; }
			else { fice[mlik][check + 2] = -10; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}

		if (mpo1 - winx[hwin] > 190 && mpo1 - winx[hwin] < 210 && mpo2 - winy[hwin]>202-pres[hwin] && mpo2 - winy[hwin] < 222-pres[hwin]) {
			zcolor=RGB(frame[mlik][fclick].z*255,frame[mlik][fclick].y*255,frame[mlik][fclick].x*255);
			ccz.lStructSize = sizeof(CHOOSECOLOR);
			ccz.hwndOwner = hwnd;
			ccz.hInstance = NULL;
			ccz.rgbResult = zcolor;
			ccz.lpCustColors = zref;
			ccz.Flags = CC_RGBINIT | CC_FULLOPEN;
			ccz.lpfnHook = NULL;
			if (ChooseColor(&ccz)) {
	zcolor=ccz.rgbResult;
	frame[mlik][fclick].z =GetRValue(zcolor)/255.0;	frame[mlik][fclick].y=GetGValue(zcolor) / 255.0;	frame[mlik][fclick].x =GetBValue(zcolor) / 255.0;
	
				ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
			}
		}
		
	}
	//light
	if(lkik>=0){
	if(typz==2){
	if (mpo1 - winx[hwin]>50 && mpo1 - winx[hwin]<70 && mpo2 - winy[hwin]>138-pres[hwin] && mpo2 - winy[hwin]<158-pres[hwin] ) { 
	for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
		if(c-1>=lkik){
		for (0;a < strlen(light);a++) { if (q >= 5) { how3[b] = 0; break; } how3[b]= light[a]; b++; if (light[a] == ',') { q++; } }
		for(b=0;a<strlen(light);a++){ how1[b]= light[a]; b++;
		if(light[a+1]==','){ how1[b]=0; thm3=atof(how1); a+=2; b=0;
		for (0;a < strlen(light);a++){ how1[b]= light[a]; b++; if(light[a+1]==','){ break;} } how1[b]=0; thm4=atof(how1); b=0; a+=2; 
q=0;	for (0;a < strlen(light);a++) { if (q >= 1) { matname[b] = 0; break; } matname[b]= light[a]; b++; if (light[a] == ',') { q++; } }  b=0;
		for (0;a < strlen(light);a++) { how1[b] = light[a]; b++; if (light[a + 1] == ',') { break; } } how1[b] = 0; thm5 = atof(how1); b = 0; a++;
		for (b=0;a < strlen(light);a++){ how2[b]= light[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how3[b]= light[a]; b++;
		if (light[a] == ':') { c++; }
		}
	zcolor=RGB(thm5*255,thm3*255,thm4*255);
	ccz.lStructSize = sizeof(CHOOSECOLOR);
	ccz.hwndOwner = hwnd;
	ccz.hInstance = NULL;
	ccz.rgbResult = zcolor;
	ccz.lpCustColors = zref;
	ccz.Flags = CC_RGBINIT | CC_FULLOPEN;
	ccz.lpfnHook = NULL;
	if (ChooseColor(&ccz)) {
		zcolor = ccz.rgbResult;
	thm3= GetRValue(zcolor); thm4= GetGValue(zcolor); thm5= GetBValue(zcolor);
	sprintf(light,"%s%f,%f,%s%f%s",how3,thm4/255.0,thm5/255.0, matname,thm3/255.0,how2);
	ValidateRect(hwnd, &client); InvalidateRect(hwnd,&client,TRUE);
		}
	}
}
if(typz!=2){
	if (mpo1 - winx[hwin]>50 && mpo1 - winx[hwin]<70 && mpo2 - winy[hwin]>168-pres[hwin] && mpo2 - winy[hwin]<188-pres[hwin] ) { 
	for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
		if(c-1>=lkik){
		for (0;a < strlen(light);a++) { if (q >= 8) { how3[b] = 0; break; } how3[b]= light[a]; b++; if (light[a] == ',') { q++; } }
		for(b=0;a<strlen(light);a++){ how1[b]= light[a]; b++;
		if(light[a+1]==','){ how1[b]=0; thm3=atof(how1); a+=2; b=0;
		for (0;a < strlen(light);a++){ how1[b]= light[a]; b++; if(light[a+1]==','){ break;} } how1[b]=0; thm4=atof(how1); b=0; a+=2; 
q=0;	for (0;a < strlen(light);a++) { if (q >= 5) { matname[b] = 0; break; } matname[b]= light[a]; b++; if (light[a] == ',') { q++; } }  b=0;
		for (0;a < strlen(light);a++) { how1[b] = light[a]; b++; if (light[a + 1] == ',') { break; } } how1[b] = 0; thm5 = atof(how1); b = 0; a++;
		for (b=0;a < strlen(light);a++){ how2[b]= light[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how3[b]= light[a]; b++;
		if (light[a] == ':') { c++; }
		}
	zcolor=RGB(thm5*255,thm3*255,thm4*255);
	ccz.lStructSize = sizeof(CHOOSECOLOR);
	ccz.hwndOwner = hwnd;
	ccz.hInstance = NULL;
	ccz.rgbResult = zcolor;
	ccz.lpCustColors = zref;
	ccz.Flags = CC_RGBINIT | CC_FULLOPEN;
	ccz.lpfnHook = NULL;
	if (ChooseColor(&ccz)) {
		zcolor = ccz.rgbResult;
	thm3= GetRValue(zcolor); thm4= GetGValue(zcolor); thm5= GetBValue(zcolor);
	sprintf(light,"%s%f,%f,%s%f%s",how3,thm4/255.0,thm5/255.0, matname,thm3/255.0,how2);
	ValidateRect(hwnd, &client); InvalidateRect(hwnd,&client,TRUE);
		}
}
if (mpo1 - winx[hwin]>100 && mpo1 - winx[hwin]<120 && mpo2 - winy[hwin]>238-pres[hwin] && mpo2 - winy[hwin]<258-pres[hwin] ) { 
	for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
		if(c-1>=lkik){
		for (0;a < strlen(light);a++) { if (q >= 12) { how3[b] = 0; break; } how3[b]= light[a]; b++; if (light[a] == ',') { q++; } }
		for(b=0;a<strlen(light);a++){ how1[b]= light[a]; b++;
		if(light[a+1]==','){ how1[b]=0; thm3=atof(how1); a+=2; b=0;
		for (0;a < strlen(light);a++){ how1[b]= light[a]; b++; if(light[a+1]==','){ break;} } how1[b]=0; thm4=atof(how1); b=0; a+=2; 
		for (0;a < strlen(light);a++) { how1[b] = light[a]; b++; if (light[a + 1] == ',') { break; } } how1[b] = 0; thm5 = atof(how1); b = 0; a++;
		for (b=0;a < strlen(light);a++){ how2[b]= light[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how3[b]= light[a]; b++;
		if (light[a] == ':') { c++; }
		}
	zcolor=RGB(thm3*255,thm4*255,thm5*255);
	ccz.lStructSize = sizeof(CHOOSECOLOR);
	ccz.hwndOwner = hwnd;
	ccz.hInstance = NULL;
	ccz.rgbResult = zcolor;
	ccz.lpCustColors = zref;
	ccz.Flags = CC_RGBINIT | CC_FULLOPEN;
	ccz.lpfnHook = NULL;
	if (ChooseColor(&ccz)) {
		zcolor = ccz.rgbResult;
	thm3= GetRValue(zcolor)/255.0; thm4= GetGValue(zcolor)/255.0; thm5= GetBValue(zcolor)/255.0;
	sprintf(light, "%s%f,%f,%f%s", how3, thm3, thm4, thm5, how2);
	ValidateRect(hwnd, &client); InvalidateRect(hwnd,&client,TRUE);
		}
	}

if (mpo1 - winx[hwin]>10 && mpo1 - winx[hwin]<20 && mpo2 - winy[hwin]>222-pres[hwin] && mpo2 - winy[hwin]<232-pres[hwin] ) {  
	for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
	if(c-1>=lkik){
	for (0;a < strlen(light);a++) { if (q >= 11) { how3[b] = 0; break; } how3[b]= light[a]; b++; if (light[a] == ',') { q++; } }
	for(b=0;a<strlen(light);a++){ how1[b]= light[a]; b++;
	if(light[a+1]==','){ how1[b]=0; a++;
	for (b=0;a < strlen(light);a++){ how2[b]= light[a]; b++; }
	how2[b]=0;
	break;}
	}
	break;}
	how3[b]= light[a]; b++;
	if (light[a] == ':') { c++; }
	}
	thm3 = atof(how1);
	if (thm3==0) { thm3 = 1; }else{ thm3=0; }
	sprintf(light, "%s%f%s", how3, thm3, how2);
	ValidateRect(hwnd, &client); InvalidateRect(hwnd,&client,TRUE);
	}
//directional specular
if(typz==0){
	if (mpo1 - winx[hwin]>10 && mpo1 - winx[hwin]<20 && mpo2 - winy[hwin]>292-pres[hwin] && mpo2 - winy[hwin]<302-pres[hwin] ) {  
	for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
	if(c-1>=lkik){
	for (0;a < strlen(light);a++) { if (q >= 16) { how3[b] = 0; break; } how3[b]= light[a]; b++; if (light[a] == ',') { q++; } }
	for(b=0;a<strlen(light);a++){ how1[b]= light[a]; b++;
	if(light[a+1]==','){ how1[b]=0; a++;
	for (b=0;a < strlen(light);a++){ how2[b]= light[a]; b++; }
	how2[b]=0;
	break;}
	}
	break;}
	how3[b]= light[a]; b++;
	if (light[a] == ':') { c++; }
	}
	thm3 = atoi(how1);
	if (thm3==0) { thm3 = 1; }else{ thm3=0; }
	sprintf(light, "%s%f%s", how3, thm3, how2);
	ValidateRect(hwnd, &client); InvalidateRect(hwnd,&client,TRUE);
	}
}
//flash specular
if(typz==1){
	if (mpo1 - winx[hwin]>10 && mpo1 - winx[hwin]<20 && mpo2 - winy[hwin]>352-pres[hwin] && mpo2 - winy[hwin]<372-pres[hwin] ) {  
	for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
	if(c-1>=lkik){
	for (0;a < strlen(light);a++) { if (q >= 19) { how3[b] = 0; break; } how3[b]= light[a]; b++; if (light[a] == ',') { q++; } }
	for(b=0;a<strlen(light);a++){ how1[b]= light[a]; b++;
	if(light[a+1]==','){ how1[b]=0; a++;
	for (b=0;a < strlen(light);a++){ how2[b]= light[a]; b++; }
	how2[b]=0;
	break;}
	}
	break;}
	how3[b]= light[a]; b++;
	if (light[a] == ':') { c++; }
	}
	thm3 = atoi(how1);
	if (thm3==0) { thm3 = 1; }else{ thm3=0; }
	sprintf(light, "%s%f%s", how3, thm3, how2);
	ValidateRect(hwnd, &client); InvalidateRect(hwnd,&client,TRUE);
	}
}

}
if(typz==1){
if (mpo1 - winx[hwin]>10 && mpo1 - winx[hwin]<20 && mpo2 - winy[hwin]>332-pres[hwin] && mpo2 - winy[hwin]<342-pres[hwin] ) {  
	for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
	if(c-1>=lkik){
	for (0;a < strlen(light);a++) { if (q >= 18) { how[b] = 0; break; } how[b]= light[a]; b++; if (light[a] == ',') { q++; } }
	for(b=0;a<strlen(light);a++){ how1[b]= light[a]; b++;
	if(light[a+1]==','){ how1[b]=0; a++;
	for (b=0;a < strlen(light);a++){ how2[b]= light[a]; b++; }
	how2[b]=0;
	break;}
	}
	break;}
	how[b]= light[a]; b++;
	if (light[a] == ':') { c++; }
	}
	thm3 = atoi(how1);
	if (thm3<=0) { thm3 = 1; }else{ thm3=0; }
	sprintf(light, "%s%f%s", how, thm3, how2);
	ValidateRect(hwnd, &client); InvalidateRect(hwnd,&client,TRUE);
	}
}

	}
	//camera
	if (jlik >= 0) {
		//color
		if (mpo1 - winx[hwin]>80 && mpo1 - winx[hwin]<100 && mpo2 - winy[hwin]>287-pres[hwin] && mpo2 - winy[hwin]<307-pres[hwin] ) { 
		for (int a = 0,b=0,c=0,q=0;a < strlen(camera);a++){ 
		if(c-1>=jlik){
		for (0;a < strlen(camera);a++) { if (q >= 16) { how3[b] = 0; break; } how3[b]=camera[a]; b++; if (camera[a] == ',') { q++; } }
		for(b=0;a<strlen(camera);a++){ how1[b]=camera[a]; b++;
		if(camera[a+1]==','){ how1[b]=0; thm3=atof(how1); a+=2; b=0;
		for (0;a < strlen(camera);a++){ how1[b]=camera[a]; b++; if(camera[a+1]==','){ break;} } how1[b]=0; thm4=atof(how1); b=0; a+=2;
		for (0;a < strlen(camera);a++) { how1[b] = camera[a]; b++; if (camera[a + 1] == ',') { break; } } how1[b] = 0; thm5 = atof(how1); b = 0; a++;
		for (b=0;a < strlen(camera);a++){ how2[b]=camera[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how3[b]=camera[a]; b++;
		if (camera[a] == ':') { c++; }
		}
		zcolor=RGB(thm3,thm4,thm5);
		ccz.lStructSize = sizeof(CHOOSECOLOR);
		ccz.hwndOwner = hwnd;
		ccz.hInstance = NULL;
		ccz.rgbResult = zcolor;
		ccz.lpCustColors = zref;
		ccz.Flags = CC_RGBINIT | CC_FULLOPEN;
		ccz.lpfnHook = NULL;
		if (ChooseColor(&ccz)) {
			zcolor = ccz.rgbResult;
		thm3= GetRValue(zcolor); thm4= GetGValue(zcolor); thm5= GetBValue(zcolor);
		sprintf(camera,"%s%f,%f,%f%s",how3,thm3,thm4,thm5,how2);
		ValidateRect(hwnd, &client); InvalidateRect(hwnd,&client,TRUE);
		}
		
		}

		//one
		if (mpo1 - winx[hwin]>10 && mpo1 - winx[hwin]<20 && mpo2 - winy[hwin]>250-pres[hwin] && mpo2 - winy[hwin]<260-pres[hwin] ) { 
			for (int a = 0,b=0,c=0,q=0;a < strlen(camera);a++){ 
		if(c-1>=jlik){
		for (0;a < strlen(camera);a++) { if (q >= 11) { how[b] = 0; break; } how[b]=camera[a]; b++; if (camera[a] == ',') { q++; } }
		ou=a;
		for(b=0;a<strlen(camera);a++){ how1[b]=camera[a]; b++;
		if(camera[a+1]==','){ how1[b]=0;
		break;}
		}
		break;}
		how[b]=camera[a]; b++;
		if (camera[a] == ':') { c++; }
		}
			for (int q = 0,y=0;q < strlen(camera);q++) {
			if(camera[q]==':'){ y=0;
			for(0;q<strlen(camera);q++) { 
			if(y>=11){ camera[q]='0'; break;}
			if(camera[q]==','){ y++; } }
			}

			}
		
		camera[ou]='1';
		ValidateRect(hwnd, &client); InvalidateRect(hwnd,&client,TRUE);
		}
		if (mpo1 - winx[hwin]>70 && mpo1 - winx[hwin]<80 && mpo2 - winy[hwin]>250-pres[hwin] && mpo2 - winy[hwin]<260-pres[hwin] ) {  
			for (int a = 0,b=0,c=0,q=0;a < strlen(camera);a++){ 
		if(c-1>=jlik){
		for (0;a < strlen(camera);a++) { if (q >= 12) { how[b] = 0; break; } how[b]=camera[a]; b++; if (camera[a] == ',') { q++; } }
		for(b=0;a<strlen(camera);a++){ how1[b]=camera[a]; b++;
		if(camera[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(camera);a++){ how2[b]=camera[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=camera[a]; b++;
		if (camera[a] == ':') { c++; }
		}
		thm3 = atoi(how1);
		if (thm3<=0) { thm3 = 1; }else{ thm3=0; }
		sprintf(camera, "%s%f%s", how, thm3, how2);
		ValidateRect(hwnd, &client); InvalidateRect(hwnd,&client,TRUE);
		}
		if (mpo1 - winx[hwin]>155 && mpo1 - winx[hwin]<165 && mpo2 - winy[hwin]>250-pres[hwin] && mpo2 - winy[hwin]<260-pres[hwin] ) { 
			for (int a = 0,b=0,c=0,q=0;a < strlen(camera);a++){ 
		if(c-1>=jlik){
		for (0;a < strlen(camera);a++) { if (q >= 13) { how[b] = 0; break; } how[b]=camera[a]; b++; if (camera[a] == ',') { q++; } }
		for(b=0;a<strlen(camera);a++){ how1[b]=camera[a]; b++;
		if(camera[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(camera);a++){ how2[b]=camera[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=camera[a]; b++;
		if (camera[a] == ':') { c++; }
		}
		thm3 = atoi(how1);
		if (thm3<=0) { thm3 = 1; }else{ thm3=0; }
		sprintf(camera, "%s%f%s", how, thm3, how2);
		ValidateRect(hwnd, &client); InvalidateRect(hwnd,&client,TRUE);
		}
		if (mpo1 - winx[hwin]>10 && mpo1 - winx[hwin]<20 && mpo2 - winy[hwin]>315-pres[hwin] && mpo2 - winy[hwin]<325-pres[hwin] ) { 
			for (int a = 0,b=0,c=0,q=0;a < strlen(camera);a++){ 
		if(c-1>=jlik){
		for (0;a < strlen(camera);a++) { if (q >= 19) { how[b] = 0; break; } how[b]=camera[a]; b++; if (camera[a] == ',') { q++; } }
		for(b=0;a<strlen(camera);a++){ how1[b]=camera[a]; b++;
		if(camera[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(camera);a++){ how2[b]=camera[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=camera[a]; b++;
		if (camera[a] == ':') { c++; }
		}
		thm3=0; 
		sprintf(camera, "%s%f%s", how, thm3, how2);
		ValidateRect(hwnd, &client); InvalidateRect(hwnd,&client,TRUE);
		}
		if (mpo1 - winx[hwin]>72 && mpo1 - winx[hwin]<82 && mpo2 - winy[hwin]>315-pres[hwin] && mpo2 - winy[hwin]<325-pres[hwin] ) { 
			for (int a = 0,b=0,c=0,q=0;a < strlen(camera);a++){ 
		if(c-1>=jlik){
		for (0;a < strlen(camera);a++) { if (q >= 19) { how[b] = 0; break; } how[b]=camera[a]; b++; if (camera[a] == ',') { q++; } }
		for(b=0;a<strlen(camera);a++){ how1[b]=camera[a]; b++;
		if(camera[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(camera);a++){ how2[b]=camera[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=camera[a]; b++;
		if (camera[a] == ':') { c++; }
		}
		thm3=1; 
		sprintf(camera, "%s%f%s", how, thm3, how2);
		ValidateRect(hwnd, &client); InvalidateRect(hwnd,&client,TRUE);
		}
		if (mpo1 - winx[hwin]>157 && mpo1 - winx[hwin]<167 && mpo2 - winy[hwin]>315-pres[hwin] && mpo2 - winy[hwin]<325-pres[hwin] ) { 
			for (int a = 0,b=0,c=0,q=0;a < strlen(camera);a++){ 
		if(c-1>=jlik){
		for (0;a < strlen(camera);a++) { if (q >= 19) { how[b] = 0; break; } how[b]=camera[a]; b++; if (camera[a] == ',') { q++; } }
		for(b=0;a<strlen(camera);a++){ how1[b]=camera[a]; b++;
		if(camera[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(camera);a++){ how2[b]=camera[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=camera[a]; b++;
		if (camera[a] == ':') { c++; }
		}
		thm3=2; 
		sprintf(camera, "%s%f%s", how, thm3, how2);
		ValidateRect(hwnd, &client); InvalidateRect(hwnd,&client,TRUE);
		}

		}
		
}

if (ou == 6) {
if (mpo1 - winx[curwin - 1]>104 && mpo1 - winx[curwin - 1] < 123) {
		if (bright[curwin - 1] == 0) { bright[curwin - 1] = 1; }
		else { bright[curwin - 1] = 0; }
		SetRect(&rc, winx[curwin - 1], winy[curwin - 1], winx[curwin - 1] + winwx[curwin - 1], winy[curwin - 1] + winwy[curwin - 1]);
		ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
	}
}

if (ou == 2 && mpo2 < winy[curwin - 1] + 20 && mdon == 0) {
	if (mpo1 - winx[curwin - 1]>118 && mpo1 - winx[curwin - 1] < 136) { 
		if (box[curwin - 1] == 0) { box[curwin - 1] = 1; }else if(box[curwin - 1] == 1) { box[curwin - 1] = 2; }else{ box[curwin-1]=0; }
		SetRect(&rc, winx[curwin - 1], winy[curwin - 1], winx[curwin - 1] +winwx[curwin-1], winy[curwin - 1] + winwy[curwin-1]);
		ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
	}
	if (mpo1 - winx[curwin - 1]>164 && mpo1 - winx[curwin - 1] < 183) {
		if (bright[curwin - 1] == 0) { bright[curwin - 1] = 1; }
		else { bright[curwin - 1] = 0; }
		SetRect(&rc, winx[curwin - 1], winy[curwin - 1], winx[curwin - 1] + winwx[curwin - 1], winy[curwin - 1] + winwy[curwin - 1]);
		ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
	}
	if (mpo1 - winx[curwin - 1]>141 && mpo1 - winx[curwin - 1] < 161) {
		if (grab[curwin - 1] == 0) { grab[curwin - 1] = 1; }
		else if(grab[curwin - 1] == 1){ grab[curwin - 1] = 2; }
		else{ grab[curwin - 1] = 0;  }
		SetRect(&rc, winx[curwin - 1]+140, winy[curwin - 1], winx[curwin - 1] + 170, winy[curwin - 1] + 20);
		ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
	}
}

	}
	}
if (plane == 2&&game1==TRUE) { 
if(mpo1>csize/2+14&&mpo1<csize/2+38&&mpo2>26&&mpo2<48){ game1=FALSE; ValidateRect(hwnd,NULL); InvalidateRect(hwnd,NULL,TRUE); }
if(mpo1-gamx>88&&mpo1-gamx<106&&mpo2-gamy>1&&mpo2-gamy<19){ if(skew==0){ skew=1; }else{ skew=0; } ValidateRect(hwnd,NULL); InvalidateRect(hwnd,NULL,TRUE); }
}
		break; }

	case WM_LBUTTONUP: {
		if (plane == 2) {
		mdon = 0; roll = 0; ReleaseCapture(); ball = 0;
		if (causo != 0) { hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); }
		if (grab[hwin] != 0) { hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); }
		causo = 0;
		if (selet3 > 0) { ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); 
		if (count ==0) { 
			if (cantent[selet4][0] == 'F'&&cantent[selet4][1] == 'i'&&cantent[selet4][2] == 'l'&&cantent[selet4][3] == 'e'&&cantent[selet4][4] == ' '&&cantent[selet4][5] == 'f'&&cantent[selet4][6] == 'o'&&cantent[selet4][7] == 'l'&&cantent[selet4][8] == 'd'&&cantent[selet4][9] == 'e'&&cantent[selet4][10] == 'r') { 
				sprintf(path, "%s\\%s", path, stantent[selet4]); deep++;
				SendMessage(hwnd, WM_SETFOCUS, 1, 0); 
				ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
			}
		if (cantent[selet4][0] == 'b'&&cantent[selet4][1] == 'a'&&cantent[selet4][2] == 'c'&&cantent[selet4][3] == 'k'&&cantent[selet4][4] == '.'&&cantent[selet4][5] == '.') { 
			ou = strlen(path); sprintf(how, "%s", path); deep--;
			for (0;ou > 0;ou--) { if (path[ou] == '\\') { break; } }
			for (bu = 0;bu < ou-1;bu++) { path[bu] = how[bu]; } path[bu + 1] = 0;
				SendMessage(hwnd, WM_SETFOCUS, 1, 0); 
				ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
			}
		}
		else {
			if (selet3 == 2&& cantent[selet4][0] == 'O'&&cantent[selet4][1] == 'B'&&cantent[selet4][2] == 'J'&&cantent[selet4][3] == ' ') {
				sprintf(impot, "%s\\%s", path, stantent[selet4]);
				sprintf(report, "Loading Object..."); report1 = 2;
				SetRect(&rc, 0, csize2 - 25, csize, csize2);
				ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
				repo = 1;
				SetTimer(hwnd, 1, 10, NULL);
			}
		}

		if (selet3 == 4) {
		//texture
	if(mpo2-winy[curwin-1]>240-mres[curwin-1]&&mpo2-winy[curwin-1]<287-mres[curwin-1]){
	{
		
		sprintf(how2, "%s\\%s", path, stantent[selet4]);
		
		if (matprop[mlik][manon].tex <= -1) {
			free1 = matcount[mlik];
			realloc(diffuse[mlik], sizeof(GLuint*)*(free1 + 3));
		free3=strlen(texturename[mlik])+strlen(how2);
		sprintf(how3,"%s",texturename[mlik]);
		texturename[mlik] = (char*)malloc(free3 * sizeof(char*));
		sprintf(texturename[mlik], "%s%s;", how3, how2);
			matprop[mlik][manon].text=1; matprop[mlik][manon].tex=free1;
			matcount[mlik]++;
		}

		image = SOIL_load_image(how2, &width, &height, 0, SOIL_LOAD_RGBA);
		if (image) {
			bu = matprop[mlik][manon].tex;
			glGenTextures(1, &diffuse[mlik][bu]);
			glBindTexture(GL_TEXTURE_2D, diffuse[mlik][bu]);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
			glGenerateMipmap(GL_TEXTURE_2D);
			SOIL_free_image_data(image);
			glBindTexture(GL_TEXTURE_2D, 0);
			
			{
				sprintf_s(how3, ""); ou=0;
				for (int a = 0, b = 0, c = 0;a < strlen(texturename[mlik]);a++) {
					if (b >= matprop[mlik][manon].tex) { how3[c] = 0; 
			for (0;a < strlen(texturename[mlik]);a++) { if (texturename[mlik][a + 1] == ';') { break; } } a++;
			for (0;a < strlen(texturename[mlik]);a++) { how1[ou] = texturename[mlik][a]; ou++;  }
						break;
					}
					if (texturename[mlik][a] == ';') { b++; }
					how3[c]=texturename[mlik][a]; c++;
				}
			}
			how1[ou]=0;
			free2=strlen(texturename[mlik]);
			free3=strlen(how3)+strlen(how2)+strlen(how1);
			if(free3>free2){ 
		texturename[mlik] = (char*)malloc(free3 * sizeof(char*)); 
			}
		sprintf(texturename[mlik],"%s%s%s",how3,how2,how1);
			
			//rename
		}
	}
	}
	//emission map
	if(mpo2-winy[curwin-1]>600-mres[curwin-1]&&mpo2-winy[curwin-1]<635-mres[curwin-1]){
		{
		sprintf(how2, "%s\\%s", path, stantent[selet4]);
		if (matprop[mlik][manon].emtmap <= -1) {
			free1 = matcount[mlik];
			realloc(diffuse[mlik], sizeof(GLuint*)*(free1 + 3));
			free3 = strlen(texturename[mlik]) + strlen(how2);
			sprintf(how3, "%s", texturename[mlik]);
			texturename[mlik] = (char*)malloc(free3 * sizeof(char*));
			sprintf(texturename[mlik], "%s%s;", how3, how2);
			matprop[mlik][manon].emt = 3; matprop[mlik][manon].emtmap = free1;
			matcount[mlik]++;
		}

		image = SOIL_load_image(how2, &width, &height, 0, SOIL_LOAD_RGBA);
		if (image) {
			bu = matprop[mlik][manon].emtmap;
			glGenTextures(1, &diffuse[mlik][bu]);
			glBindTexture(GL_TEXTURE_2D, diffuse[mlik][bu]);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
			glGenerateMipmap(GL_TEXTURE_2D);
			SOIL_free_image_data(image);
			glBindTexture(GL_TEXTURE_2D, 0);
			
			{
				sprintf_s(how3, ""); ou=0;
				for (int a = 0, b = 0, c = 0;a < strlen(texturename[mlik]);a++) {
					if (b >= matprop[mlik][manon].emmap) { how3[c] = 0; 
			for (0;a < strlen(texturename[mlik]);a++) { if (texturename[mlik][a + 1] == ';') { break; } } a++;
			for (0;a < strlen(texturename[mlik]);a++) { how1[ou] = texturename[mlik][a]; ou++;  }
						break;
					}
					if (texturename[mlik][a] == ';') { b++; }
					how3[c]=texturename[mlik][a]; c++;
				}
			}
			how1[ou]=0;
			free2 = strlen(texturename[mlik]);
			free3 = strlen(how3) + strlen(how2) + strlen(how1);
			if (free3>free2) {
				texturename[mlik] = (char*)malloc(free3 * sizeof(char*));
			}
			sprintf(texturename[mlik],"%s%s%s",how3,how2,how1);
			//rename
		}
	}
	}
	//emission
	if(mpo2-winy[curwin-1]>520-mres[curwin-1]&&mpo2-winy[curwin-1]<583-mres[curwin-1]){
		{
		sprintf(how2, "%s\\%s", path, stantent[selet4]);
		if (matprop[mlik][manon].emmap <= -1) {
			free1 = matcount[mlik];
			realloc(diffuse[mlik], sizeof(GLuint*)*(free1 + 3));
			free3 = strlen(texturename[mlik]) + strlen(how2);
			sprintf(how3, "%s", texturename[mlik]);
			texturename[mlik] = (char*)malloc(free3 * sizeof(char*));
			sprintf(texturename[mlik], "%s%s;", how3, how2);
			matprop[mlik][manon].emK = 1; matprop[mlik][manon].emmap = free1;
			matcount[mlik]++;
		}

		image = SOIL_load_image(how2, &width, &height, 0, SOIL_LOAD_RGBA);
		if (image) {
			bu = matprop[mlik][manon].emmap;
			glGenTextures(1, &diffuse[mlik][bu]);
			glBindTexture(GL_TEXTURE_2D, diffuse[mlik][bu]);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
			glGenerateMipmap(GL_TEXTURE_2D);
			SOIL_free_image_data(image);
			glBindTexture(GL_TEXTURE_2D, 0);
			
			{
				sprintf_s(how3, ""); ou=0;
				for (int a = 0, b = 0, c = 0;a < strlen(texturename[mlik]);a++) {
					if (b >= matprop[mlik][manon].emmap) { how3[c] = 0; 
			for (0;a < strlen(texturename[mlik]);a++) { if (texturename[mlik][a + 1] == ';') { break; } } a++;
			for (0;a < strlen(texturename[mlik]);a++) { how1[ou] = texturename[mlik][a]; ou++;  }
						break;
					}
					if (texturename[mlik][a] == ';') { b++; }
					how3[c]=texturename[mlik][a]; c++;
				}
			}
			how1[ou]=0;
			free2 = strlen(texturename[mlik]);
			free3 = strlen(how3) + strlen(how2) + strlen(how1);
			if (free3>free2) {
				texturename[mlik] = (char*)malloc(free3 * sizeof(char*));
			}
			sprintf(texturename[mlik],"%s%s%s",how3,how2,how1);
			//rename
		}
	}
	}
	//specular
	if(mpo2-winy[curwin-1]>443-mres[curwin-1]&&mpo2-winy[curwin-1]<506-mres[curwin-1]){ 
		{
		sprintf(how2, "%s\\%s", path, stantent[selet4]);
		if (matprop[mlik][manon].spemap <= -1) {
			free1 = matcount[mlik];
			realloc(diffuse[mlik], sizeof(GLuint*)*(free1 + 3));
			free3 = strlen(texturename[mlik]) + strlen(how2);
			sprintf(how3, "%s", texturename[mlik]);
			texturename[mlik] = (char*)malloc(free3 * sizeof(char*));
			sprintf(texturename[mlik], "%s%s;", how3, how2);
			matprop[mlik][manon].sm = 1; matprop[mlik][manon].spemap = free1;
			matcount[mlik]++;
		}

		image = SOIL_load_image(how2, &width, &height, 0, SOIL_LOAD_RGBA);
		if (image) {
			bu = matprop[mlik][manon].spemap;
			glGenTextures(1, &diffuse[mlik][bu]);
			glBindTexture(GL_TEXTURE_2D, diffuse[mlik][bu]);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
			glGenerateMipmap(GL_TEXTURE_2D);
			SOIL_free_image_data(image);
			glBindTexture(GL_TEXTURE_2D, 0);
			
			{
				sprintf_s(how3, ""); ou=0;
				for (int a = 0, b = 0, c = 0;a < strlen(texturename[mlik]);a++) {
					if (b >= matprop[mlik][manon].spemap) { how3[c] = 0; 
			for (0;a < strlen(texturename[mlik]);a++) { if (texturename[mlik][a + 1] == ';') { break; } } a++;
			for (0;a < strlen(texturename[mlik]);a++) { how1[ou] = texturename[mlik][a]; ou++;  }
						break;
					}
					if (texturename[mlik][a] == ';') { b++; }
					how3[c]=texturename[mlik][a]; c++;
				}
			}
			how1[ou]=0;
			free2 = strlen(texturename[mlik]);
			free3 = strlen(how3) + strlen(how2) + strlen(how1);
			if (free3>free2) {
				texturename[mlik] = (char*)malloc(free3 * sizeof(char*));
			}
			sprintf(texturename[mlik],"%s%s%s",how3,how2,how1);
			//rename
		}
	}
	}
	//reflection
	if(mpo2-winy[curwin-1]>710-mres[curwin-1]&&mpo2-winy[curwin-1]<742-mres[curwin-1]){ 
		{
		sprintf(how2, "%s\\%s", path, stantent[selet4]);
		if (matprop[mlik][manon].rfmap <= -1) {
			free1 = matcount[mlik];
			realloc(diffuse[mlik], sizeof(GLuint*)*(free1 + 3));
			free3 = strlen(texturename[mlik]) + strlen(how2);
			sprintf(how3, "%s", texturename[mlik]);
			texturename[mlik] = (char*)malloc(free3 * sizeof(char*));
			sprintf(texturename[mlik], "%s%s;", how3, how2);
			matprop[mlik][manon].rfk = 1; matprop[mlik][manon].rfmap = free1;
			matcount[mlik]++;
		}

		image = SOIL_load_image(how2, &width, &height, 0, SOIL_LOAD_RGBA);
		if (image) {
			bu = matprop[mlik][manon].rfmap;
			glGenTextures(1, &diffuse[mlik][bu]);
			glBindTexture(GL_TEXTURE_2D, diffuse[mlik][bu]);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
			glGenerateMipmap(GL_TEXTURE_2D);
			SOIL_free_image_data(image);
			glBindTexture(GL_TEXTURE_2D, 0);
			
			{
				sprintf_s(how3, ""); ou=0;
				for (int a = 0, b = 0, c = 0;a < strlen(texturename[mlik]);a++) {
					if (b >= matprop[mlik][manon].rfmap) { how3[c] = 0; 
			for (0;a < strlen(texturename[mlik]);a++) { if (texturename[mlik][a + 1] == ';') { break; } } a++;
			for (0;a < strlen(texturename[mlik]);a++) { how1[ou] = texturename[mlik][a]; ou++;  }
						break;
					}
					if (texturename[mlik][a] == ';') { b++; }
					how3[c]=texturename[mlik][a]; c++;
				}
			}
			how1[ou]=0;
			free2 = strlen(texturename[mlik]);
			free3 = strlen(how3) + strlen(how2) + strlen(how1);
			if (free3>free2) {
				texturename[mlik] = (char*)malloc(free3 * sizeof(char*));
			}
			sprintf(texturename[mlik],"%s%s%s",how3,how2,how1);
			//rename
		}
	}
	}
	//bump
	if(mpo2-winy[curwin-1]>287-mres[curwin-1]&&mpo2-winy[curwin-1]<350-mres[curwin-1]){ 
	{
		sprintf(how2, "%s\\%s", path, stantent[selet4]);
		if (matprop[mlik][manon].bump <= -1) {
			free1 = matcount[mlik];
			realloc(diffuse[mlik], sizeof(GLuint*)*(free1 + 3));
			free3 = strlen(texturename[mlik]) + strlen(how2);
			sprintf(how3, "%s", texturename[mlik]);
			texturename[mlik] = (char*)malloc(free3 * sizeof(char*));
			sprintf(texturename[mlik], "%s%s;", how3, how2);
			matprop[mlik][manon].bum = 1; matprop[mlik][manon].bump = free1;
			matcount[mlik]++;
		}

		image = SOIL_load_image(how2, &width, &height, 0, SOIL_LOAD_RGBA);
		if (image) {
			bu = matprop[mlik][manon].bump;
			glGenTextures(1, &diffuse[mlik][bu]);
			glBindTexture(GL_TEXTURE_2D, diffuse[mlik][bu]);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
			glGenerateMipmap(GL_TEXTURE_2D);
			SOIL_free_image_data(image);
			glBindTexture(GL_TEXTURE_2D, 0);
			
			{
				sprintf_s(how3, ""); ou=0;
				for (int a = 0, b = 0, c = 0;a < strlen(texturename[mlik]);a++) {
					if (b >= matprop[mlik][manon].bump) { how3[c] = 0; 
			for (0;a < strlen(texturename[mlik]);a++) { if (texturename[mlik][a + 1] == ';') { break; } } a++;
			for (0;a < strlen(texturename[mlik]);a++) { how1[ou] = texturename[mlik][a]; ou++;  }
						break;
					}
					if (texturename[mlik][a] == ';') { b++; }
					how3[c]=texturename[mlik][a]; c++;
				}
			}
			how1[ou]=0;
			free2 = strlen(texturename[mlik]);
			free3 = strlen(how3) + strlen(how2) + strlen(how1);
			if (free3>free2) {
				texturename[mlik] = (char*)malloc(free3 * sizeof(char*));
			}
			sprintf(texturename[mlik],"%s%s%s",how3,how2,how1);
			//rename
		}
	}
	}
		}

		}
		selet3 = 0;
		}
		break;}

	case WM_MOUSEMOVE: {
		mpo1 = LOWORD(lParam);
		mpo2 = HIWORD(lParam);

		if (plane == 2) {
			if (selet3 > 0) { ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); count = 1; }
	if(obmen==1){
if(mpo1>obx&&mpo1<obx+400&&mpo2>oby&&mpo2<oby+400){ SetRect(&rc,obx,oby,obx+400,oby+400); ValidateRect(hwnd,&rc); InvalidateRect(hwnd,&rc,TRUE); }
		}
			
if (layout != 10&&layout!=12) { if (curwin == 1) { ou = scrn1; }if (curwin == 2) { ou = scrn2; }if (curwin == 3) { ou = scrn3; }if (curwin == 4) { ou = scrn4; }if (curwin == 5) { ou = scrn5; }if (curwin == 6) { ou = scrn6; } }
if(layout==10){ if (curwin == 4) { ou = scrn1; }if (curwin ==1) { ou = scrn2; }if (curwin == 2) { ou = scrn3; }if (curwin == 3) { ou = scrn4; } }
if (layout == 12) { if (curwin == 2) { ou = scrn1; }if (curwin == 3) { ou = scrn2; }if (curwin == 4) { ou = scrn3; }if (curwin == 1) { ou = scrn4; } }
if (ou == 3 && mpo2 - winy[curwin - 1] > 240-pres[curwin-1]) {
	SetRect(&rc, winx[curwin - 1], winy[curwin - 1]+240-pres[curwin-1], winx[curwin - 1] + winwx[curwin - 1], winy[curwin - 1] + winwy[curwin - 1]);
	ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
}
else {
	if(maclick>=0){
		SetRect(&rc, winx[curwin - 1], winy[curwin - 1] + 240-pres[curwin-1], winx[curwin - 1] + winwx[curwin - 1], winy[curwin - 1] + winwy[curwin - 1]);
		ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
	}
}


if (ou == 5&&mpo2>winy[curwin-1]&&mdon==0) { 
	SetRect(&rc, winx[curwin - 1], winy[curwin - 1], winx[curwin - 1]+winwx[curwin-1], winy[curwin - 1] + winwy[curwin - 1]);
	ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
}
else {
	if (selet[hwin] > 0) { ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
}
if (ou == 1 && mpo2>winy[curwin - 1] + 20 && mdon == 0) {
	SetRect(&rc, winx[curwin - 1] , winy[curwin - 1] + 20, winx[curwin - 1]+winwx[curwin-1] , winy[curwin - 1]+winwy[curwin-1] );
	ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
}

if (ou == 7&&manon>=0&&mdon==0) { hwin=curwin-1;
	if (mpo1 - winx[hwin]>10 && mpo1 - winx[hwin]<50 && mpo2 - winy[hwin]>220-mres[hwin]  && mpo2 - winy[hwin]<235-mres[hwin]&&mpo2-winy[hwin]>150 && causo == 0) { causo = 1000; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<10 || mpo1 - winx[hwin]>50 || mpo2 - winy[hwin]<220-mres[hwin]  || mpo2 - winy[hwin]>235-mres[hwin] ) { if (causo == 1000) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//specular
	if (mpo1 - winx[hwin]>10 && mpo1 - winx[hwin]<70 && mpo2 - winy[hwin]>405 - mres[hwin] && mpo2 - winy[hwin]<420 - mres[hwin] && mpo2 - winy[hwin]>150 && causo == 0) { causo = 104; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<10 || mpo1 - winx[hwin]>70 || mpo2 - winy[hwin]<405 - mres[hwin] || mpo2 - winy[hwin]>420 - mres[hwin]) { if (causo == 104) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	if (mpo1 - winx[hwin]>10 && mpo1 - winx[hwin]<70 && mpo2 - winy[hwin]>425 - mres[hwin] && mpo2 - winy[hwin]<440 - mres[hwin] && mpo2 - winy[hwin]>150 && causo == 0) { causo = 105; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<10 || mpo1 - winx[hwin]>70 || mpo2 - winy[hwin]<425 - mres[hwin] || mpo2 - winy[hwin]>440 - mres[hwin]) { if (causo == 105) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//emit
	if (mpo1 - winx[hwin]>10 && mpo1 - winx[hwin]<70 && mpo2 - winy[hwin]>510 - mres[hwin] && mpo2 - winy[hwin]<525 - mres[hwin] && mpo2 - winy[hwin]>150 && causo == 0) { causo = 106; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<10 || mpo1 - winx[hwin]>70 || mpo2 - winy[hwin]<510 - mres[hwin] || mpo2 - winy[hwin]>525 - mres[hwin]) { if (causo == 106) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }

	//Nors
	if (mpo1 - winx[hwin]>10 && mpo1 - winx[hwin]<50 && mpo2 - winy[hwin]>740 - mres[hwin] && mpo2 - winy[hwin]<755 - mres[hwin] && mpo2 - winy[hwin]>150 && causo == 0) { causo = 110; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<10 || mpo1 - winx[hwin]>50 || mpo2 - winy[hwin]<740 - mres[hwin] || mpo2 - winy[hwin]>755 - mres[hwin]) { if (causo == 110) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//NSI
	if (mpo1 - winx[hwin]>10 && mpo1 - winx[hwin]<40 && mpo2 - winy[hwin]>485 - mres[hwin] && mpo2 - winy[hwin]<500 - mres[hwin] && mpo2 - winy[hwin]>150 && causo == 0) { causo = 107; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<10 || mpo1 - winx[hwin]>40 || mpo2 - winy[hwin]<485 - mres[hwin] || mpo2 - winy[hwin]>500 - mres[hwin]) { if (causo == 107) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//REFLECTION
	if (mpo1 - winx[hwin]>10 && mpo1 - winx[hwin]<70 && mpo2 - winy[hwin]>660 - mres[hwin] && mpo2 - winy[hwin]<675 - mres[hwin] && mpo2 - winy[hwin]>150 && causo == 0) { causo = 108; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<10 || mpo1 - winx[hwin]>70 || mpo2 - winy[hwin]<660 - mres[hwin] || mpo2 - winy[hwin]>675 - mres[hwin]) { if (causo == 108) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//refractive index
	if (mpo1 - winx[hwin]>10 && mpo1 - winx[hwin]<40 && mpo2 - winy[hwin]>680 - mres[hwin] && mpo2 - winy[hwin]<695 - mres[hwin] && mpo2 - winy[hwin]>150 && causo == 0) { causo = 109; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<10 || mpo1 - winx[hwin]>40 || mpo2 - winy[hwin]<680 - mres[hwin] || mpo2 - winy[hwin]>695 - mres[hwin]) { if (causo == 109) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }

}

if (ou == 3 && mpo2>winy[curwin - 1] + 20 && mdon == 0) { hwin=curwin-1;

if (mlik >= 0 || fclick >= 0 || jlik>=0) {
	//one
	if(mpo1-winx[hwin]>5&&mpo1-winx[hwin]<20&&mpo2-winy[hwin]>100-pres[hwin]&&mpo2-winy[hwin]<115-pres[hwin]&&causo==0){ causo=1; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<5 || mpo1 - winx[hwin]>20 || mpo2 - winy[hwin]<100-pres[hwin] || mpo2 - winy[hwin]>115-pres[hwin]) { if(causo==1){ hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo=0; } }
	//two
	thm4 = winwx[hwin] / 3 + 10;
	if (mpo1 - winx[hwin]>thm4-3 && mpo1 - winx[hwin]<thm4+20 && mpo2 - winy[hwin]>100-pres[hwin] && mpo2 - winy[hwin]<115-pres[hwin] && causo == 0) { causo = 2; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<thm4-3 || mpo1 - winx[hwin]>thm4 + 20 || mpo2 - winy[hwin]<100-pres[hwin] || mpo2 - winy[hwin]>115-pres[hwin]) { if (causo == 2) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//three
	thm4 = winwx[hwin] / 3*2 + 10;
	if (mpo1 - winx[hwin]>thm4 - 3 && mpo1 - winx[hwin]<thm4 + 20 && mpo2 - winy[hwin]>100-pres[hwin] && mpo2 - winy[hwin]<115-pres[hwin] && causo == 0) { causo = 3; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<thm4 - 3 || mpo1 - winx[hwin]>thm4 + 20 || mpo2 - winy[hwin]<100-pres[hwin] || mpo2 - winy[hwin]>115-pres[hwin]) { if (causo == 3) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }

	//one
	if (mpo1 - winx[hwin]>5 && mpo1 - winx[hwin]<20 && mpo2 - winy[hwin]>140-pres[hwin] && mpo2 - winy[hwin]<155-pres[hwin] && causo == 0) { causo = 4; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<5 || mpo1 - winx[hwin]>20 || mpo2 - winy[hwin]<140-pres[hwin] || mpo2 - winy[hwin]>155-pres[hwin]) { if (causo ==4) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//two
	thm4 = winwx[hwin] / 3 + 10;
	if (mpo1 - winx[hwin]>thm4 - 3 && mpo1 - winx[hwin]<thm4 + 20 && mpo2 - winy[hwin]>140-pres[hwin] && mpo2 - winy[hwin]<155-pres[hwin] && causo == 0) { causo = 5; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<thm4 - 3 || mpo1 - winx[hwin]>thm4 + 20 || mpo2 - winy[hwin]<140-pres[hwin] || mpo2 - winy[hwin]>155-pres[hwin]) { if (causo == 5) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//three
	thm4 = winwx[hwin] / 3 * 2 + 10;
	if (mpo1 - winx[hwin]>thm4 - 3 && mpo1 - winx[hwin]<thm4 + 20 && mpo2 - winy[hwin]>140-pres[hwin] && mpo2 - winy[hwin]<155-pres[hwin] && causo == 0) { causo =6; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<thm4 - 3 || mpo1 - winx[hwin]>thm4 + 20 || mpo2 - winy[hwin]<140-pres[hwin] || mpo2 - winy[hwin]>155-pres[hwin]) { if (causo == 6) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }

	if(jlik<0){
	//one
	if (mpo1 - winx[hwin]>5 && mpo1 - winx[hwin]<20 && mpo2 - winy[hwin]>180-pres[hwin] && mpo2 - winy[hwin]<195-pres[hwin] && causo == 0) { causo = 7; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<5 || mpo1 - winx[hwin]>20 || mpo2 - winy[hwin]<180-pres[hwin] || mpo2 - winy[hwin]>195-pres[hwin]) { if (causo == 7) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//two
	thm4 = winwx[hwin] / 3 + 10;
	if (mpo1 - winx[hwin]>thm4 - 3 && mpo1 - winx[hwin]<thm4 + 20 && mpo2 - winy[hwin]>180-pres[hwin] && mpo2 - winy[hwin]<195-pres[hwin] && causo == 0) { causo = 8; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<thm4 - 3 || mpo1 - winx[hwin]>thm4 + 20 || mpo2 - winy[hwin]<180-pres[hwin] || mpo2 - winy[hwin]>195-pres[hwin]) { if (causo == 8) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//three
	thm4 = winwx[hwin] / 3 * 2 + 10;
	if (mpo1 - winx[hwin]>thm4 - 3 && mpo1 - winx[hwin]<thm4 + 20 && mpo2 - winy[hwin]>180-pres[hwin] && mpo2 - winy[hwin]<195-pres[hwin] && causo == 0) { causo = 9; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<thm4 - 3 || mpo1 - winx[hwin]>thm4 + 20 || mpo2 - winy[hwin]<180-pres[hwin] || mpo2 - winy[hwin]>195-pres[hwin]) { if (causo == 9) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	
	}

	if (jlik >= 0) {
	//one
	if (mpo1 - winx[hwin]>5 && mpo1 - winx[hwin]<30 && mpo2 - winy[hwin]>170-pres[hwin] && mpo2 - winy[hwin]<185-pres[hwin] && causo == 0) { causo = 7; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<5 || mpo1 - winx[hwin]>30 || mpo2 - winy[hwin]<170-pres[hwin] || mpo2 - winy[hwin]>185-pres[hwin]) { if (causo == 7) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//two
	thm4 = winwx[hwin] / 2 + 10;
	if (mpo1 - winx[hwin]>thm4 - 3 && mpo1 - winx[hwin]<thm4 + 40 && mpo2 - winy[hwin]>170-pres[hwin] && mpo2 - winy[hwin]<185-pres[hwin] && causo == 0) { causo = 8; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<thm4 - 3 || mpo1 - winx[hwin]>thm4 + 40 || mpo2 - winy[hwin]<170-pres[hwin] || mpo2 - winy[hwin]>185-pres[hwin]) { if (causo == 8) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//one
	if (mpo1 - winx[hwin]>5 && mpo1 - winx[hwin]<30 && mpo2 - winy[hwin]>230-pres[hwin] && mpo2 - winy[hwin]<245-pres[hwin] && causo == 0) { causo = 9; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<5 || mpo1 - winx[hwin]>30 || mpo2 - winy[hwin]<230-pres[hwin] || mpo2 - winy[hwin]>245-pres[hwin]) { if (causo == 9) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//one
	if (mpo1 - winx[hwin]>5 && mpo1 - winx[hwin]<40 && mpo2 - winy[hwin]>265-pres[hwin] && mpo2 - winy[hwin]<280-pres[hwin] && causo == 0) { causo = 10; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<5 || mpo1 - winx[hwin]>40 || mpo2 - winy[hwin]<265-pres[hwin] || mpo2 - winy[hwin]>280-pres[hwin]) { if (causo == 10) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//two
	thm4 = winwx[hwin] / 2 + 10;
	if (mpo1 - winx[hwin]>thm4 - 3 && mpo1 - winx[hwin]<thm4 + 60 && mpo2 - winy[hwin]>265-pres[hwin] && mpo2 - winy[hwin]<280-pres[hwin] && causo == 0) { causo = 11; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<thm4 - 3 || mpo1 - winx[hwin]>thm4 + 60 || mpo2 - winy[hwin]<265-pres[hwin] || mpo2 - winy[hwin]>280-pres[hwin]) { if (causo == 11) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//one
	if (mpo1 - winx[hwin]>5 && mpo1 - winx[hwin]<40 && mpo2 - winy[hwin]>330-pres[hwin] && mpo2 - winy[hwin]<345-pres[hwin] && causo == 0) { causo = 12; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<5 || mpo1 - winx[hwin]>40 || mpo2 - winy[hwin]<330-pres[hwin] || mpo2 - winy[hwin]>345-pres[hwin]) { if (causo == 12) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }

	}

}

if(lkik>=0){
	//one
	if(mpo1-winx[hwin]>5&&mpo1-winx[hwin]<20&&mpo2-winy[hwin]>100-pres[hwin]&&mpo2-winy[hwin]<115-pres[hwin]&&causo==0){ causo=1; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<5 || mpo1 - winx[hwin]>20 || mpo2 - winy[hwin]<100-pres[hwin] || mpo2 - winy[hwin]>115-pres[hwin]) { if(causo==1){ hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo=0; } }
	//two
	thm4 = winwx[hwin] / 3 + 10;
	if (mpo1 - winx[hwin]>thm4-3 && mpo1 - winx[hwin]<thm4+20 && mpo2 - winy[hwin]>100-pres[hwin] && mpo2 - winy[hwin]<115-pres[hwin] && causo == 0) { causo = 2; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<thm4-3 || mpo1 - winx[hwin]>thm4 + 20 || mpo2 - winy[hwin]<100-pres[hwin] || mpo2 - winy[hwin]>115-pres[hwin]) { if (causo == 2) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//three
	thm4 = winwx[hwin] / 3*2 + 10;
	if (mpo1 - winx[hwin]>thm4 - 3 && mpo1 - winx[hwin]<thm4 + 20 && mpo2 - winy[hwin]>100-pres[hwin] && mpo2 - winy[hwin]<115-pres[hwin] && causo == 0) { causo = 3; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<thm4 - 3 || mpo1 - winx[hwin]>thm4 + 20 || mpo2 - winy[hwin]<100-pres[hwin] || mpo2 - winy[hwin]>115-pres[hwin]) { if (causo == 3) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	
	if(typz==2){
	//one
	if(mpo1-winx[hwin]>5&&mpo1-winx[hwin]<50&&mpo2-winy[hwin]>170-pres[hwin]&&mpo2-winy[hwin]<185-pres[hwin]&&causo==0){ causo=4; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<5 || mpo1 - winx[hwin]>50 || mpo2 - winy[hwin]<170-pres[hwin] || mpo2 - winy[hwin]>185-pres[hwin]) { if(causo==4){ hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo=0; } }
	//one
	if (mpo1 - winx[hwin]>5 && mpo1 - winx[hwin]<50 && mpo2 - winy[hwin]>190 - pres[hwin] && mpo2 - winy[hwin]<205 - pres[hwin] && causo == 0) { causo = 5; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<5 || mpo1 - winx[hwin]>50 || mpo2 - winy[hwin]<190 - pres[hwin] || mpo2 - winy[hwin]>205 - pres[hwin]) { if (causo == 5) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//one
	if (mpo1 - winx[hwin]>5 && mpo1 - winx[hwin]<50 && mpo2 - winy[hwin]>210 - pres[hwin] && mpo2 - winy[hwin]<225 - pres[hwin] && causo == 0) { causo = 6; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<5 || mpo1 - winx[hwin]>50 || mpo2 - winy[hwin]<210 - pres[hwin] || mpo2 - winy[hwin]>225 - pres[hwin]) { if (causo == 6) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }

	}
	if(typz==0){
	//one
	if(mpo1-winx[hwin]>5&&mpo1-winx[hwin]<50&&mpo2-winy[hwin]>200-pres[hwin]&&mpo2-winy[hwin]<215-pres[hwin]&&causo==0){ causo=7; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<5 || mpo1 - winx[hwin]>50 || mpo2 - winy[hwin]<200-pres[hwin] || mpo2 - winy[hwin]>215-pres[hwin]) { if(causo==7){ hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo=0; } }
	//one
	if (mpo1 - winx[hwin]>5 && mpo1 - winx[hwin]<50 && mpo2 - winy[hwin]>270 - pres[hwin] && mpo2 - winy[hwin]<285 - pres[hwin] && causo == 0) { causo = 8; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<5 || mpo1 - winx[hwin]>50 || mpo2 - winy[hwin]<270 - pres[hwin] || mpo2 - winy[hwin]>285 - pres[hwin]) { if (causo == 8) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	}
	if(typz==1){
	//one
	if(mpo1-winx[hwin]>5&&mpo1-winx[hwin]<50&&mpo2-winy[hwin]>200-pres[hwin]&&mpo2-winy[hwin]<215-pres[hwin]&&causo==0){ causo=7; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<5 || mpo1 - winx[hwin]>50 || mpo2 - winy[hwin]<200-pres[hwin] || mpo2 - winy[hwin]>215-pres[hwin]) { if(causo==7){ hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo=0; } }
	//one
	if (mpo1 - winx[hwin]>5 && mpo1 - winx[hwin]<50 && mpo2 - winy[hwin]>270 - pres[hwin] && mpo2 - winy[hwin]<285 - pres[hwin] && causo == 0) { causo = 8; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<5 || mpo1 - winx[hwin]>50 || mpo2 - winy[hwin]<270 - pres[hwin] || mpo2 - winy[hwin]>285 - pres[hwin]) { if (causo == 8) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//one
	if (mpo1 - winx[hwin]>5 && mpo1 - winx[hwin]<50 && mpo2 - winy[hwin]>290 - pres[hwin] && mpo2 - winy[hwin]<305 - pres[hwin] && causo == 0) { causo = 9; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<5 || mpo1 - winx[hwin]>50 || mpo2 - winy[hwin]<290 - pres[hwin] || mpo2 - winy[hwin]>305 - pres[hwin]) { if (causo == 9) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//one
	if (mpo1 - winx[hwin]>5 && mpo1 - winx[hwin]<50 && mpo2 - winy[hwin]>310 - pres[hwin] && mpo2 - winy[hwin]<325 - pres[hwin] && causo == 0) { causo = 10; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<5 || mpo1 - winx[hwin]>50 || mpo2 - winy[hwin]<310 - pres[hwin] || mpo2 - winy[hwin]>325 - pres[hwin]) { if (causo == 10) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }

	}

	if(typz!=2){
	//one
	if (mpo1 - winx[hwin]>5 && mpo1 - winx[hwin]<20 && mpo2 - winy[hwin]>140-pres[hwin] && mpo2 - winy[hwin]<155-pres[hwin] && causo == 0) { causo = 4; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<5 || mpo1 - winx[hwin]>20 || mpo2 - winy[hwin]<140-pres[hwin] || mpo2 - winy[hwin]>155-pres[hwin]) { if (causo ==4) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//two
	thm4 = winwx[hwin] / 3 + 10;
	if (mpo1 - winx[hwin]>thm4 - 3 && mpo1 - winx[hwin]<thm4 + 20 && mpo2 - winy[hwin]>140-pres[hwin] && mpo2 - winy[hwin]<155-pres[hwin] && causo == 0) { causo = 5; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<thm4 - 3 || mpo1 - winx[hwin]>thm4 + 20 || mpo2 - winy[hwin]<140-pres[hwin] || mpo2 - winy[hwin]>155-pres[hwin]) { if (causo == 5) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	//three
	thm4 = winwx[hwin] / 3 * 2 + 10;
	if (mpo1 - winx[hwin]>thm4 - 3 && mpo1 - winx[hwin]<thm4 + 20 && mpo2 - winy[hwin]>140-pres[hwin] && mpo2 - winy[hwin]<155-pres[hwin] && causo == 0) { causo =6; hc = LoadCursor(GetModuleHandle(NULL), "CUR4");  SetCursor(hc); }
	if (mpo1 - winx[hwin]<thm4 - 3 || mpo1 - winx[hwin]>thm4 + 20 || mpo2 - winy[hwin]<140-pres[hwin] || mpo2 - winy[hwin]>155-pres[hwin]) { if (causo == 6) { hc = LoadCursor(NULL, IDC_ARROW);  SetCursor(hc); causo = 0; } }
	}

}


}


if (ou == 2 && selet3 > 0 && selet3 != 2) { if (cantent[selet4][0]=='O'&&cantent[selet4][1] == 'B'&&cantent[selet4][2] == 'J'&&cantent[selet4][3] == ' ') { hc = LoadCursor(GetModuleHandle(NULL), "CUR1"); } else { hc = LoadCursor(GetModuleHandle(NULL), "CUR2"); } SetCursor(hc); selet3 = 2; }
if (ou == 5 && selet3 >0 && selet3 != 1) { hc = LoadCursor(GetModuleHandle(NULL), "CUR");  SetCursor(hc); selet3 = 1; }
if(ou==7&&selet3>0){ 
if(mpo2-winy[curwin-1]>240-mres[curwin-1]&&mpo2-winy[curwin-1]>170&&mpo2-winy[curwin-1]<742-mres[curwin-1]&&manon>=0 ){ if(selet3 != 4){ hc = LoadCursor(GetModuleHandle(NULL), "CUR");  SetCursor(hc); selet3 = 4; } }
else{ if(selet3 != 5){ hc = LoadCursor(GetModuleHandle(NULL), "CUR2"); SetCursor(hc); selet3 = 5; } }
}
if (ou != 5&&ou!=2 &&ou!=7&& selet3 >0 && selet3 != 3) { hc = LoadCursor(GetModuleHandle(NULL), "CUR2"); SetCursor(hc); selet3 = 3; }

if (mdon == 1&&causo>0) {
	thm = mpo1 - fm1; thm /= 100;
	if (manon >= 0&&causo==1000) {
		matprop[mlik][manon].Tr += thm;
		if(matprop[mlik][manon].Tr>1.0){ matprop[mlik][manon].Tr=1.0; }
		if (matprop[mlik][manon].Tr<0.0) { matprop[mlik][manon].Tr = 0.0; }
	}
	//specular
	if (manon >= 0&&causo==104) {
		matprop[mlik][manon].si += (thm*10);
		if (matprop[mlik][manon].si<0.1) { matprop[mlik][manon].si = 0.1; }
	}
	if (manon >= 0&&causo==105) {
		matprop[mlik][manon].ss += thm;
		//if(matprop[mlik][manon].ss>1.0){ matprop[mlik][manon].ss=1.0; }
		if (matprop[mlik][manon].ss<0.0) { matprop[mlik][manon].ss = 0.0; }
	}
	if (manon >= 0&&causo==106) {
		matprop[mlik][manon].emit += thm;
		if (matprop[mlik][manon].emit<0.0) { matprop[mlik][manon].emit = 0.0; }
	}
	//NORS
	if (manon >= 0&&causo==110) {
		matprop[mlik][manon].NORS+=thm;
		if (matprop[mlik][manon].NORS<-1.0) { matprop[mlik][manon].NORS=-1.0; }
		if (matprop[mlik][manon].NORS>1.0) { matprop[mlik][manon].NORS=1.0; }
	}
	//NSI
	if (manon >= 0&&causo==107) {
		matprop[mlik][manon].NSI+=thm;
		if (matprop[mlik][manon].NSI<0.0) { matprop[mlik][manon].NSI = 0.0; }
	}
	//reflection
	if (manon >= 0&&causo==108) {
		matprop[mlik][manon].rfls+=thm;
		if (matprop[mlik][manon].rfls<0.0) { matprop[mlik][manon].rfls = 0.0; }
		if (matprop[mlik][manon].rfls>1.0) { matprop[mlik][manon].rfls = 1.0; }
	}
	//refraction
	if (manon >= 0&&causo==109) {
		matprop[mlik][manon].rfi+=thm;
		if (matprop[mlik][manon].rfi<0.0) { matprop[mlik][manon].rfi = 0.0; }
	}

	if (mlik >= 0 && fclick < 0) {
		if (causo == 1) { mauv[mlik].x += thm; }
		if (causo == 2) { mauv[mlik].y += thm; }
		if (causo == 3) { mauv[mlik].z += thm; }
	}
	if (mlik >= 0 && fclick < 0) {
		if (causo == 7) { scil[mlik].x += thm; }
		if (causo == 8) { scil[mlik].y += thm; }
		if (causo == 9) { scil[mlik].z += thm; }
	}
	if (mlik >= 0 && fclick < 0) {
		if (causo == 4) { rita[mlik].x += (thm*100); }
		if (causo == 5) { rita[mlik].y += (thm*100); }
		if (causo == 6) { rita[mlik].z += (thm*100); }
}

	if (mlik >= 0 && fclick >= 0) {
		if (causo == 1) { gauv[mlik][fclick].x += thm; }
		if (causo == 2) { gauv[mlik][fclick].y += thm; }
		if (causo == 3) { gauv[mlik][fclick].z += thm; }
	}
	if (mlik >= 0 && fclick >= 0) {
		if (causo == 7) { scal[mlik][fclick].x += thm; }
		if (causo == 8) { scal[mlik][fclick].y += thm; }
		if (causo == 9) { scal[mlik][fclick].z += thm; }
	}
	if (mlik >= 0 && fclick >= 0) {
		if (causo == 4) { rota[mlik][fclick].x += (thm*100); }
		if (causo == 5) { rota[mlik][fclick].y += (thm*100); }
		if (causo == 6) { rota[mlik][fclick].z += (thm*100); }
	}
	//lamp
	if(lkik>=0){
	if (causo == 1) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
		if(c-1>=lkik){
		for (0;a < strlen(light);a++) { if (q >= 1) { how[b] = 0; break; } how[b]=light[a]; b++; if (light[a] == ',') { q++; } }
		for(b=0;a<strlen(light);a++){ how1[b]=light[a]; b++;
		if(light[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(light);a++){ how2[b]=light[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=light[a]; b++;
		if (light[a] == ':') { c++; }
		}
		thm3 = atof(how1) + thm;
		sprintf(light, "%s%f%s", how, thm3, how2);
		}
	if (causo == 2) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
		if(c-1>=lkik){
		for (0;a < strlen(light);a++) { if (q >= 2) { how[b] = 0; break; } how[b]=light[a]; b++; if (light[a] == ',') { q++; } }
		for(b=0;a<strlen(light);a++){ how1[b]=light[a]; b++;
		if(light[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(light);a++){ how2[b]=light[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=light[a]; b++;
		if (light[a] == ':') { c++; }
		}
		thm3 = atof(how1) + thm;
		sprintf(light, "%s%f%s", how, thm3, how2);
		}
	if (causo == 3) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
		if(c-1>=lkik){
		for (0;a < strlen(light);a++) { if (q >= 3) { how[b] = 0; break; } how[b]=light[a]; b++; if (light[a] == ',') { q++; } }
		for(b=0;a<strlen(light);a++){ how1[b]=light[a]; b++;
		if(light[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(light);a++){ how2[b]=light[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=light[a]; b++;
		if (light[a] == ':') { c++; }
		}
		thm3 = atof(how1) + thm;
		sprintf(light, "%s%f%s", how, thm3, how2);
		}
	if(typz==2){
	if (causo == 4) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
		if(c-1>=lkik){
		for (0;a < strlen(light);a++) { if (q >= 7) { how[b] = 0; break; } how[b]=light[a]; b++; if (light[a] == ',') { q++; } }
		for(b=0;a<strlen(light);a++){ how1[b]=light[a]; b++;
		if(light[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(light);a++){ how2[b]=light[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=light[a]; b++;
		if (light[a] == ':') { c++; }
		}
		thm3 = atof(how1) + thm;
		if(thm3<=0){ thm3=0; }
		sprintf(light, "%s%f%s", how, thm3, how2);
		}
	if (causo == 5) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
		if(c-1>=lkik){
		for (0;a < strlen(light);a++) { if (q >= 4) { how[b] = 0; break; } how[b]=light[a]; b++; if (light[a] == ',') { q++; } }
		for(b=0;a<strlen(light);a++){ how1[b]=light[a]; b++;
		if(light[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(light);a++){ how2[b]=light[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=light[a]; b++;
		if (light[a] == ':') { c++; }
		}
		thm3 = atof(how1) + thm;
		if(thm3<=0){ thm3=0; }
		sprintf(light, "%s%f%s", how, thm3, how2);
		}
	if (causo == 6) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
		if(c-1>=lkik){
		for (0;a < strlen(light);a++) { if (q >= 9) { how[b] = 0; break; } how[b]=light[a]; b++; if (light[a] == ',') { q++; } }
		for(b=0;a<strlen(light);a++){ how1[b]=light[a]; b++;
		if(light[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(light);a++){ how2[b]=light[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=light[a]; b++;
		if (light[a] == ':') { c++; }
		}
		thm3 = atof(how1) + thm;
		if(thm3<=0){ thm3=0; }
		sprintf(light, "%s%f%s", how, thm3, how2);
		}
	}
	if(typz!=2){
	if (causo == 4) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
		if(c-1>=lkik){
		for (0;a < strlen(light);a++) { if (q >= 4) { how[b] = 0; break; } how[b]=light[a]; b++; if (light[a] == ',') { q++; } }
		for(b=0;a<strlen(light);a++){ how1[b]=light[a]; b++;
		if(light[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(light);a++){ how2[b]=light[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=light[a]; b++;
		if (light[a] == ':') { c++; }
		}
		thm3 = atof(how1) + (thm*100);
		if(thm3>360){ thm3=0; } if(thm3<0){ thm3=360; }
		sprintf(light, "%s%f%s", how, thm3, how2);
		}
	if (causo == 5) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
		if(c-1>=lkik){
		for (0;a < strlen(light);a++) { if (q >= 5) { how[b] = 0; break; } how[b]=light[a]; b++; if (light[a] == ',') { q++; } }
		for(b=0;a<strlen(light);a++){ how1[b]=light[a]; b++;
		if(light[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(light);a++){ how2[b]=light[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=light[a]; b++;
		if (light[a] == ':') { c++; }
		}
		thm3 = atof(how1) + (thm*100);
		if(thm3>360){ thm3=0; } if(thm3<0){ thm3=360; }
		sprintf(light, "%s%f%s", how, thm3, how2);
		}
	if (causo == 6) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
		if(c-1>=lkik){
		for (0;a < strlen(light);a++) { if (q >= 6) { how[b] = 0; break; } how[b]=light[a]; b++; if (light[a] == ',') { q++; } }
		for(b=0;a<strlen(light);a++){ how1[b]=light[a]; b++;
		if(light[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(light);a++){ how2[b]=light[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=light[a]; b++;
		if (light[a] == ':') { c++; }
		}
		thm3 = atof(how1) + (thm*100);
		if(thm3>360){ thm3=0; } if(thm3<0){ thm3=360; }
		sprintf(light, "%s%f%s", how, thm3, how2);
		}
	if (causo == 7) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
		if(c-1>=lkik){
		for (0;a < strlen(light);a++) { if (q >= 10) { how[b] = 0; break; } how[b]=light[a]; b++; if (light[a] == ',') { q++; } }
		for(b=0;a<strlen(light);a++){ how1[b]=light[a]; b++;
		if(light[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(light);a++){ how2[b]=light[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=light[a]; b++;
		if (light[a] == ':') { c++; }
		}
		thm3 = atof(how1) + thm;
		if(thm3<=0){ thm3=0; }
		sprintf(light, "%s%f%s", how, thm3, how2);
		}
	if (causo == 8) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
		if(c-1>=lkik){
		for (0;a < strlen(light);a++) { if (q >= 7) { how[b] = 0; break; } how[b]=light[a]; b++; if (light[a] == ',') { q++; } }
		for(b=0;a<strlen(light);a++){ how1[b]=light[a]; b++;
		if(light[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(light);a++){ how2[b]=light[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=light[a]; b++;
		if (light[a] == ':') { c++; }
		}
		thm3 = atof(how1) +thm;
		if(thm3<=0){ thm3=0; }
		sprintf(light, "%s%f%s", how, thm3, how2);
		}
	if (causo == 9) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
		if(c-1>=lkik){
		for (0;a < strlen(light);a++) { if (q >= 16) { how[b] = 0; break; } how[b]=light[a]; b++; if (light[a] == ',') { q++; } }
		for(b=0;a<strlen(light);a++){ how1[b]=light[a]; b++;
		if(light[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(light);a++){ how2[b]=light[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=light[a]; b++;
		if (light[a] == ':') { c++; }
		}
		thm3 = atof(how1) + thm;
		if(thm3<=0){ thm3=0; }
		sprintf(light, "%s%f%s", how, thm3, how2);
		}
	if (causo == 10&&typz==1) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(light);a++){ 
		if(c-1>=lkik){
		for (0;a < strlen(light);a++) { if (q >= 17) { how[b] = 0; break; } how[b]=light[a]; b++; if (light[a] == ',') { q++; } }
		for(b=0;a<strlen(light);a++){ how1[b]=light[a]; b++;
		if(light[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(light);a++){ how2[b]=light[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=light[a]; b++;
		if (light[a] == ':') { c++; }
		}
		thm3 = atof(how1) + thm;
		if (thm3 <= 0) { thm3 = 0; }
		if (thm3 >= 1) { thm3 = 1; }
		sprintf(light, "%s%f%s", how, thm3, how2);
}

	}

	}
	//camera
	if (jlik >= 0) {

		if (causo == 1) {
		for (int a = 0,b=0,c=0;a < strlen(camera);a++){ 
		if(c-1>=jlik){ how[b]=0;
		for(b=0;a<strlen(camera);a++){ how1[b]=camera[a]; b++;
		if(camera[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(camera);a++){ how2[b]=camera[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=camera[a]; b++;
		if (camera[a] == ':') { c++; }
		}
		thm3 = atof(how1) + thm;
		sprintf(camera, "%s%f%s", how, thm3, how2);
		}
		if (causo == 2) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(camera);a++){ 
		if(c-1>=jlik){
		for (0;a < strlen(camera);a++) { if (q >= 1) { how[b] = 0; break; } how[b]=camera[a]; b++; if (camera[a] == ',') { q++; } }
		for(b=0;a<strlen(camera);a++){ how1[b]=camera[a]; b++;
		if(camera[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(camera);a++){ how2[b]=camera[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=camera[a]; b++;
		if (camera[a] == ':') { c++; }
		}
		thm3 = atof(how1) + thm;
		sprintf(camera, "%s%f%s", how, thm3, how2);
		}
		if (causo == 3) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(camera);a++){ 
		if(c-1>=jlik){
		for (0;a < strlen(camera);a++) { if (q >= 2) { how[b] = 0; break; } how[b]=camera[a]; b++; if (camera[a] == ',') { q++; } }
		for(b=0;a<strlen(camera);a++){ how1[b]=camera[a]; b++;
		if(camera[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(camera);a++){ how2[b]=camera[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=camera[a]; b++;
		if (camera[a] == ':') { c++; }
		}
		thm3 = atof(how1) + thm;
		sprintf(camera, "%s%f%s", how, thm3, how2);
		}
		if (causo == 4) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(camera);a++){ 
		if(c-1>=jlik){
		for (0;a < strlen(camera);a++) { if (q >= 3) { how[b] = 0; break; } how[b]=camera[a]; b++; if (camera[a] == ',') { q++; } }
		for(b=0;a<strlen(camera);a++){ how1[b]=camera[a]; b++;
		if(camera[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(camera);a++){ how2[b]=camera[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=camera[a]; b++;
		if (camera[a] == ':') { c++; }
		}
		thm3 = atof(how1) + (thm*100.0); 
		if(thm3>360){ thm3=0; } if(thm3<0){ thm3=360; }
		sprintf(camera, "%s%f%s", how, thm3, how2);
		}
		if (causo == 5) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(camera);a++){ 
		if(c-1>=jlik){
		for (0;a < strlen(camera);a++) { if (q >= 4) { how[b] = 0; break; } how[b]=camera[a]; b++; if (camera[a] == ',') { q++; } }
		for(b=0;a<strlen(camera);a++){ how1[b]=camera[a]; b++;
		if(camera[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(camera);a++){ how2[b]=camera[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=camera[a]; b++;
		if (camera[a] == ':') { c++; }
		}
		thm3 = atof(how1) + (thm*100.0);
		if (thm3>360) { thm3 = 0; } if (thm3<0) { thm3 = 360; }
		sprintf(camera, "%s%f%s", how, thm3, how2);
		}
		if (causo == 6) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(camera);a++){ 
		if(c-1>=jlik){
		for (0;a < strlen(camera);a++) { if (q >= 5) { how[b] = 0; break; } how[b]=camera[a]; b++; if (camera[a] == ',') { q++; } }
		for(b=0;a<strlen(camera);a++){ how1[b]=camera[a]; b++;
		if(camera[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(camera);a++){ how2[b]=camera[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=camera[a]; b++;
		if (camera[a] == ':') { c++; }
		}
		thm3 = atof(how1) + (thm*100.0);
		if (thm3>360) { thm3 = 0; } if (thm3<0) { thm3 = 360; }
		sprintf(camera, "%s%f%s", how, thm3, how2);
		}
		if (causo == 7) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(camera);a++){ 
		if(c-1>=jlik){
		for (0;a < strlen(camera);a++) { if (q >= 6) { how[b] = 0; break; } how[b]=camera[a]; b++; if (camera[a] == ',') { q++; } }
		for(b=0;a<strlen(camera);a++){ how1[b]=camera[a]; b++;
		if(camera[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(camera);a++){ how2[b]=camera[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=camera[a]; b++;
		if (camera[a] == ':') { c++; }
		}
		thm3 = atof(how1) + (thm*100.0);
		if(thm3<0){ thm3=0; }
		sprintf(camera, "%s%f%s", how, thm3, how2);
		}
		if (causo == 8) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(camera);a++){ 
		if(c-1>=jlik){
		for (0;a < strlen(camera);a++) { if (q >= 7) { how[b] = 0; break; } how[b]=camera[a]; b++; if (camera[a] == ',') { q++; } }
		for(b=0;a<strlen(camera);a++){ how1[b]=camera[a]; b++;
		if(camera[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(camera);a++){ how2[b]=camera[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=camera[a]; b++;
		if (camera[a] == ':') { c++; }
		}
		thm3 = atof(how1) + (thm*10.0);
		if (thm3<0) { thm3 = 0; }
		sprintf(camera, "%s%f%s", how, thm3, how2);
		}
		if (causo == 9) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(camera);a++){ 
		if(c-1>=jlik){
		for (0;a < strlen(camera);a++) { if (q >= 10) { how[b] = 0; break; } how[b]=camera[a]; b++; if (camera[a] == ',') { q++; } }
		for(b=0;a<strlen(camera);a++){ how1[b]=camera[a]; b++;
		if(camera[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(camera);a++){ how2[b]=camera[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=camera[a]; b++;
		if (camera[a] == ':') { c++; }
		}
		thm3 = atof(how1) + thm;
		if (thm3<0) { thm3 = 0; }
		sprintf(camera, "%s%f%s", how, thm3, how2);
		}
		if (causo == 10) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(camera);a++){ 
		if(c-1>=jlik){
		for (0;a < strlen(camera);a++) { if (q >= 14) { how[b] = 0; break; } how[b]=camera[a]; b++; if (camera[a] == ',') { q++; } }
		for(b=0;a<strlen(camera);a++){ how1[b]=camera[a]; b++;
		if(camera[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(camera);a++){ how2[b]=camera[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=camera[a]; b++;
		if (camera[a] == ':') { c++; }
		}
		thm3 = atof(how1) + (thm*100);
		if (thm3<0) { thm3 = 0; }
		sprintf(camera, "%s%f%s", how, thm3, how2);
		}
		if (causo == 11) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(camera);a++){ 
		if(c-1>=jlik){
		for (0;a < strlen(camera);a++) { if (q >= 15) { how[b] = 0; break; } how[b]=camera[a]; b++; if (camera[a] == ',') { q++; } }
		for(b=0;a<strlen(camera);a++){ how1[b]=camera[a]; b++;
		if(camera[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(camera);a++){ how2[b]=camera[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=camera[a]; b++;
		if (camera[a] == ':') { c++; }
		}
		thm3 = atof(how1) + (thm*100);
		if (thm3<0) { thm3 = 0; } if(thm3>100){ thm3=100; }
		sprintf(camera, "%s%f%s", how, thm3, how2);
		}
		if (causo == 12) {
		for (int a = 0,b=0,c=0,q=0;a < strlen(camera);a++){ 
		if(c-1>=jlik){
		for (0;a < strlen(camera);a++) { if (q >= 20) { how[b] = 0; break; } how[b]=camera[a]; b++; if (camera[a] == ',') { q++; } }
		for(b=0;a<strlen(camera);a++){ how1[b]=camera[a]; b++;
		if(camera[a+1]==','){ how1[b]=0; a++;
		for (b=0;a < strlen(camera);a++){ how2[b]=camera[a]; b++; }
		how2[b]=0;
		break;}
		}
		break;}
		how[b]=camera[a]; b++;
		if (camera[a] == ':') { c++; }
		}
		thm3 = atof(how1) + (thm);
		if (thm3<0) { thm3 = 0; }
		sprintf(camera, "%s%f%s", how, thm3, how2);
		}
	}

	//scrollbar
	if (causo == 100) {
	thm1 = mpo2 - fm2;
	thm1 = thm1*20.0/2.0;
	tres[hwin] -= thm1;
	if(tres[hwin]>30){ tres[hwin]=30; }

	if(tres[hwin]<30){ thm6=30-tres[hwin]; thm6=thm6/20.0*2.0; thm5=21+thm6; }
	else{ thm5=21; }
	if((thm5+trew[hwin])>winwy[hwin] -3){
	thm3=(thm5+trew[hwin])-(winwy[hwin]-3);
	thm3=thm3*20.0/2.0;
	tres[hwin]+=thm3;
	}
	
	}
	//proper
	if (causo == 101) {
	thm1 = mpo2 - fm2;
	thm1 = thm1*20.0/2.0;
	pres[hwin] += thm1;
	if(pres[hwin]<0){ pres[hwin]=0; }

	if(pres[hwin]>0){ thm6=pres[hwin]; thm6=thm6/20.0*2.0; thm5=21+thm6; }
	else{ thm5=21; }
	if((thm5+prew[hwin])>winwy[hwin] -3){
	thm3=(thm5+prew[hwin])-(winwy[hwin]-3);
	thm3=thm3*20.0/2.0;
	pres[hwin]-=thm3;
	}
	}
	//explorer
	if (causo == 102) {
	thm1 = mpo2 - fm2;
	thm1 = thm1*20.0/2.0;
	eres[hwin] -= thm1;
	if(eres[hwin]>30){ eres[hwin]=30; }

	if(eres[hwin]<30){ thm6=30-eres[hwin]; thm6=thm6/20.0*2.0; thm5=21+thm6; }
	else{ thm5=21; }
	if((thm5+erew[hwin])>winwy[hwin] -3){
	thm3=(thm5+erew[hwin])-(winwy[hwin]-3);
	thm3=thm3*20.0/2.0;
	eres[hwin]+=thm3;
	}
	}
	//material
	if (causo == 103) {
	thm1 = mpo2 - fm2;
	thm1 = thm1*20.0/2.0;
	mres[hwin] += thm1;
	if(mres[hwin]<0){ mres[hwin]=0; }

	if(mres[hwin]>0){ thm6=mres[hwin]; thm6=thm6/20.0*2.0; thm5=171+thm6; }
	else{ thm5=171; }
	if((thm5+mrew[hwin])>winwy[hwin] -3){
	thm3=(thm5+mrew[hwin])-(winwy[hwin]-3);
	thm3=thm3*20.0/2.0;
	mres[hwin]-=thm3;
	}
	}

	ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
}

if (ball == 1) {
	if (mpo1 > fm1) { thm = mpo1 - fm1; mng1[hwin] += 0.05*thm;  if (mng1[hwin]>6.28) { mng1[hwin] = 0; } }
	else if (mpo1<fm1) { thm = fm1 - mpo1; mng1[hwin] -= 0.05*thm; if (mng1[hwin] < 0) { mng1[hwin] = 6.28; } }
	if (mpo2 > fm2) { thm = mpo2 - fm2; mng2[hwin] -= 0.05*thm; if (mng2[hwin] < 0) { mng2[hwin] = 6.28; } }
	else if (mpo2 < fm2) { thm = fm2 - mpo2; mng2[hwin] += 0.05*thm; if (mng2[hwin] > 6.28) { mng2[hwin] = 0; } }
	SetRect(&rc,winx[hwin], winy[hwin], winx[hwin]+winwx[hwin], winy[hwin]+winy[hwin] + 170);
	ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
}
	if (roll == 1) {
	if(panop==0){
		if (grab[hwin] == 0) {
			if (mpo1 > fm1) { thm = mpo1 - fm1; ang1[hwin] += 0.05*thm;  if (ang1[hwin]>6.28) { ang1[hwin] = 0; } }
			else if (mpo1<fm1) { thm = fm1 - mpo1; ang1[hwin] -= 0.05*thm; if (ang1[hwin] < 0) { ang1[hwin] = 6.28; }}
			if (mpo2 > fm2) { thm = mpo2 - fm2; ang2[hwin] -= 0.05*thm; if (ang2[hwin] < 0) { ang2[hwin] = 6.28; } }
			else if (mpo2 < fm2) { thm = fm2 - mpo2; ang2[hwin] += 0.05*thm; if (ang2[hwin] > 6.28) { ang2[hwin] = 0; } }
		}
		else if(grab[hwin]==1) {
			if (mpo1 > fm1) {
		can1 = cos(ang1[hwin]); san1 = sin(ang1[hwin]);
		can2 = cos(ang2[hwin]); san2 = sin(ang2[hwin]);
		can3 = cos(-ang3[hwin]); san3 = sin(-ang3[hwin]);
		thm = mpo1 - fm1; thm /= zoom[hwin];
		thm5 = thm*can3*0.005;
		thm6 = thm*san3*0.005;
		thm7 = 0;
		thm8 = (thm5*can2) + (thm7*san2);
		thm9 = (thm5*-san2) + (thm7*can2);
		thm7 = thm6;
		thm5 = thm8;
		thm6 = (thm7*can1) + (thm9*-san1);
		thm8 = (thm7*san1) + (thm9*can1);
		mx[hwin] += thm5; my[hwin] += thm6; mz[hwin] += thm8;
		
			}
		
			else if (mpo1<fm1) { 
				can1 = cos(ang1[hwin]); san1 = sin(ang1[hwin]);
				can2 = cos(ang2[hwin]); san2 = sin(ang2[hwin]);
				can3 = cos(-ang3[hwin]); san3 = sin(-ang3[hwin]);
			thm = fm1 - mpo1;  thm /= zoom[hwin];
			thm5 = thm*can3*0.005;
			thm6 = thm*san3*0.005;
			thm7 = 0;
			thm8 = (thm5*can2) + (thm7*san2);
			thm9 = (thm5*-san2) + (thm7*can2);
			thm7 = thm6;
			thm5 = thm8;
			thm6 = (thm7*can1) + (thm9*-san1);
			thm8 = (thm7*san1) + (thm9*can1);
			mx[hwin] -= thm5; my[hwin] -= thm6; mz[hwin] -= thm8;
			}

			if (mpo2 > fm2) { 
				can1 = cos(ang1[hwin]); san1 = sin(ang1[hwin]);
				can2 = cos(ang2[hwin]); san2 = sin(ang2[hwin]);
				can3 = cos(-ang3[hwin]); san3 = sin(-ang3[hwin]);
			thm = mpo2 - fm2; thm /= zoom[hwin];
			thm5 = thm*-san3*0.005;
			thm6 = thm*can3*0.005;
			thm7 = 0;
			thm8 = (thm7*san2) + (thm5*can2);
			thm9 = (thm5*-san2) + (thm7*can2);
			thm7 = thm6;
			thm5 = thm8;
			thm6 = (thm7*can1) + (thm9*-san1);
			thm8 = (thm7*san1) + (thm9*can1);
			mx[hwin] += thm5; my[hwin] += thm6; mz[hwin] += thm8;
			
			}
			else if (mpo2<fm2) { 
				can1 = cos(ang1[hwin]); san1 = sin(ang1[hwin]);
				can2 = cos(ang2[hwin]); san2 = sin(ang2[hwin]);
				can3 = cos(-ang3[hwin]); san3 = sin(-ang3[hwin]);
			thm = fm2 - mpo2;  thm /= zoom[hwin];
			thm5 = thm*-san3*0.005;
			thm6 = thm*can3*0.005;
			thm7 = 0;
			thm8 = (thm7*san2) + (thm5*can2);
			thm9 = (thm5*-san2) + (thm7*can2);
			thm7 = thm6;
			thm5 = thm8;
			thm6 = (thm7*can1) + (thm9*-san1);
			thm8 = (thm7*san1) + (thm9*can1);
			mx[hwin] -= thm5; my[hwin] -= thm6; mz[hwin] -= thm8;
			}
		}
		else {
			if (mpo2 > fm2) {
				can1 = cos(ang1[hwin]); san1 = sin(ang1[hwin]);
				can2 = cos(ang2[hwin]); san2 = sin(ang2[hwin]);
				can3 = cos(-ang3[hwin]); san3 = sin(-ang3[hwin]);
				thm = mpo2 - fm2; thm /= zoom[hwin]; thm /= 100.0;
				thm5 = 0;
				thm6 = 0;
				thm7 = thm;
				thm8 = (thm7*san2) + (thm5*can2);
				thm9 = (thm5*-san2) + (thm7*can2);
				thm7 = thm6;
				thm5 = thm8;
				thm6 = (thm7*can1) + (thm9*-san1);
				thm8 = (thm7*san1) + (thm9*can1);
				mx[hwin] += thm5; my[hwin] += thm6; mz[hwin] += thm8;

			}
			else if (mpo2<fm2) {
				can1 = cos(ang1[hwin]); san1 = sin(ang1[hwin]);
				can2 = cos(ang2[hwin]); san2 = sin(ang2[hwin]);
				can3 = cos(-ang3[hwin]); san3 = sin(-ang3[hwin]);
				thm = fm2 - mpo2;  thm /= zoom[hwin]; thm /= 100.0;
				thm5 = 0;
				thm6 = 0;
				thm7 = thm;
				thm8 = (thm7*san2) + (thm5*can2);
				thm9 = (thm5*-san2) + (thm7*can2);
				thm7 = thm6;
				thm5 = thm8;
				thm6 = (thm7*can1) + (thm9*-san1);
				thm8 = (thm7*san1) + (thm9*can1);
				mx[hwin] -= thm5; my[hwin] -= thm6; mz[hwin] -= thm8;
			}
		}
	}
	//CHINERI
	else if(panop==1||panop==3){
	if (mpo1 > fm1) {
		can1 = cos(ang1[hwin]); san1 = sin(ang1[hwin]);
		can2 = cos(ang2[hwin]); san2 = sin(ang2[hwin]);
		can3 = cos(-ang3[hwin]); san3 = sin(-ang3[hwin]);
		thm = mpo1 - fm1; thm /= zoom[hwin];
		thm5 = thm*can3*0.005;
		thm6 = thm*san3*0.005;
		thm7 = 0;
		thm8 = (thm5*can2) + (thm7*san2);
		thm9 = (thm5*-san2) + (thm7*can2);
		thm7 = thm6;
		thm5 = thm8;
		thm6 = (thm7*can1) + (thm9*-san1);
		thm8 = (thm7*san1) + (thm9*can1);
		mx[hwin] += thm5; my[hwin] += thm6; mz[hwin] += thm8;
		
			}
		
			else if (mpo1<fm1) { 
				can1 = cos(ang1[hwin]); san1 = sin(ang1[hwin]);
				can2 = cos(ang2[hwin]); san2 = sin(ang2[hwin]);
				can3 = cos(-ang3[hwin]); san3 = sin(-ang3[hwin]);
			thm = fm1 - mpo1;  thm /= zoom[hwin];
			thm5 = thm*can3*0.005;
			thm6 = thm*san3*0.005;
			thm7 = 0;
			thm8 = (thm5*can2) + (thm7*san2);
			thm9 = (thm5*-san2) + (thm7*can2);
			thm7 = thm6;
			thm5 = thm8;
			thm6 = (thm7*can1) + (thm9*-san1);
			thm8 = (thm7*san1) + (thm9*can1);
			mx[hwin] -= thm5; my[hwin] -= thm6; mz[hwin] -= thm8;
			}

			if (mpo2 > fm2) { 
				can1 = cos(ang1[hwin]); san1 = sin(ang1[hwin]);
				can2 = cos(ang2[hwin]); san2 = sin(ang2[hwin]);
				can3 = cos(-ang3[hwin]); san3 = sin(-ang3[hwin]);
			thm = mpo2 - fm2; thm /= zoom[hwin];
			thm5 = thm*-san3*0.005;
			thm6 = thm*can3*0.005;
			thm7 = 0;
			thm8 = (thm7*san2) + (thm5*can2);
			thm9 = (thm5*-san2) + (thm7*can2);
			thm7 = thm6;
			thm5 = thm8;
			thm6 = (thm7*can1) + (thm9*-san1);
			thm8 = (thm7*san1) + (thm9*can1);
			mx[hwin] += thm5; my[hwin] += thm6; mz[hwin] += thm8;
			
			}
			else if (mpo2<fm2) { 
				can1 = cos(ang1[hwin]); san1 = sin(ang1[hwin]);
				can2 = cos(ang2[hwin]); san2 = sin(ang2[hwin]);
				can3 = cos(-ang3[hwin]); san3 = sin(-ang3[hwin]);
			thm = fm2 - mpo2;  thm /= zoom[hwin];
			thm5 = thm*-san3*0.005;
			thm6 = thm*can3*0.005;
			thm7 = 0;
			thm8 = (thm7*san2) + (thm5*can2);
			thm9 = (thm5*-san2) + (thm7*can2);
			thm7 = thm6;
			thm5 = thm8;
			thm6 = (thm7*can1) + (thm9*-san1);
			thm8 = (thm7*san1) + (thm9*can1);
			mx[hwin] -= thm5; my[hwin] -= thm6; mz[hwin] -= thm8;
			}

	}
	else if(panop==2){
	 {
	if (mpo2 > fm2) {
		can1 = cos(ang1[hwin]); san1 = sin(ang1[hwin]);
		can2 = cos(ang2[hwin]); san2 = sin(ang2[hwin]);
		can3 = cos(-ang3[hwin]); san3 = sin(-ang3[hwin]);
		thm = mpo2 - fm2; thm /= zoom[hwin]; thm /= 100.0;
		thm5 = 0;
		thm6 = 0;
		thm7 = thm;
		thm8 = (thm7*san2) + (thm5*can2);
		thm9 = (thm5*-san2) + (thm7*can2);
		thm7 = thm6;
		thm5 = thm8;
		thm6 = (thm7*can1) + (thm9*-san1);
		thm8 = (thm7*san1) + (thm9*can1);
		mx[hwin] += thm5; my[hwin] += thm6; mz[hwin] += thm8;
	
	}
	else if (mpo2<fm2) {
		can1 = cos(ang1[hwin]); san1 = sin(ang1[hwin]);
		can2 = cos(ang2[hwin]); san2 = sin(ang2[hwin]);
		can3 = cos(-ang3[hwin]); san3 = sin(-ang3[hwin]);
		thm = fm2 - mpo2;  thm /= zoom[hwin]; thm /= 100.0;
		thm5 = 0;
		thm6 = 0;
		thm7 = thm;
		thm8 = (thm7*san2) + (thm5*can2);
		thm9 = (thm5*-san2) + (thm7*can2);
		thm7 = thm6;
		thm5 = thm8;
		thm6 = (thm7*can1) + (thm9*-san1);
		thm8 = (thm7*san1) + (thm9*can1);
		mx[hwin] -= thm5; my[hwin] -= thm6; mz[hwin] -= thm8;
			}
		}
	}

	SetRect(&rc, winx[hwin], winy[hwin], winx[hwin] + winwx[hwin], winy[hwin] + winwy[hwin]);
	ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
			}

			extend();
			if (pop == 1) { last(); }
			if (pop == 0) { alignt(); }
			if (causo == 0) { resiz(); }

			if (mdon == 0&&selet3==0&&roll==0&&causo==0) { sizing(); }

		if (mpo1 > csize - 50 && mpo1 < csize - 10&&mpo2>23&&mpo2<50&&menu1!=1&&menu==0 ) { menu1 = 1; SetRect(&rc, csize - 50, 20, csize-8, 50);  ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
		else if (mpo1<csize - 50 || mpo1 > csize - 10 || mpo2 < 23 || mpo2>50) { if (menu1 != 0&&menu==0) { menu1 = 0; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

			if (mpo1 > csize - 120 && mpo1 < csize&&mpo2>50 && mpo2 < 325&&menu==1) {
				SetRect(&rc, csize - 120, 50, csize, 325);
				if (mpo2 > 8 + 50 && mpo2 < 29 + 50 && inn != 1) { inn = 1; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
				else if (mpo2 < 8 + 50 || mpo2 > 29 + 50) { if (inn == 1) { inn = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }
				if (mpo2 > 28 + 50 && mpo2 < 49 + 50 && inn != 2) { inn = 2; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
				else if (mpo2 < 28 + 50 || mpo2 > 49 + 50) { if (inn == 2) { inn = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }
				if (mpo2 > 48 + 50 && mpo2 < 69 + 50 && inn != 3) { inn = 3; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
				else if (mpo2 < 48 + 50 || mpo2 > 69 + 50) { if (inn == 3) { inn = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }
				if (mpo2 > 68 + 50 && mpo2 < 89 + 50 && inn != 4) { inn = 4; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
				else if (mpo2 < 68 + 50 || mpo2 > 89 + 50) { if (inn == 4) { inn = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }
				if (mpo2 > 88 + 50 && mpo2 < 109 + 50 && inn != 5) { inn = 5; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
				else if (mpo2 < 88 + 50 || mpo2 > 109 + 50) { if (inn == 5) { inn = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }
				if (mpo2 > 108 + 50 && mpo2 < 129 + 50 && inn != 6) { inn = 6; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
				else if (mpo2 < 108 + 50 || mpo2 > 129 + 50) { if (inn == 6) { inn = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }
				if (mpo2 > 128 + 50 && mpo2 < 149 + 50 && inn != 7) { inn = 7; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
				else if (mpo2 < 128 + 50 || mpo2 > 149 + 50) { if (inn == 7) { inn = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }
				if (mpo2 > 148 + 50 && mpo2 < 169 + 50 && inn != 8) { inn = 8; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
				else if (mpo2 < 148 + 50 || mpo2 > 169 + 50) { if (inn == 8) { inn = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }
				if (mpo2 > 168 + 50 && mpo2 < 189 + 50 && inn != 9) { inn = 9; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
				else if (mpo2 < 168 + 50 || mpo2 > 189 + 50) { if (inn == 9) { inn = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }
				if (mpo2 > 188 + 50 && mpo2 < 209 + 50 && inn != 10) { inn = 10; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
				else if (mpo2 < 188 + 50 || mpo2 > 209 + 50) { if (inn == 10) { inn = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }
				if (mpo2 > 208 + 50 && mpo2 < 229 + 50 && inn != 11) { inn = 11; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
				else if (mpo2 < 208 + 50 || mpo2 > 229 + 50) { if (inn == 11) { inn = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }
				if (mpo2 > 228 + 50 && mpo2 < 249 + 50 && inn != 12) { inn = 12; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
				else if (mpo2 < 228 + 50 || mpo2 > 249 + 50) { if (inn == 12) { inn = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }
				if (mpo2 > 248 + 50 && mpo2 < 269 + 50 && inn != 13) { inn = 13; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
				else if (mpo2 < 248 + 50 || mpo2 > 269 + 50) { if (inn == 13) { inn = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }

			}
			else { if (inn != 0) { inn = 0; menu2 = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }
		

		
		}
		fm1 = mpo1; fm2 = mpo2;
		break; }

	case WM_CHAR: {
		switch (LOWORD(wParam)) {
		case 'Z':
		case 'z': {
			if (game1 == FALSE&&plane == 2) {
			if (layout != 10 && layout != 12) { if (curwin == 1) { ou = scrn1; }if (curwin == 2) { ou = scrn2; }if (curwin == 3) { ou = scrn3; }if (curwin == 4) { ou = scrn4; }if (curwin == 5) { ou = scrn5; }if (curwin == 6) { ou = scrn6; } }
			if (layout == 10) { if (curwin == 4) { ou = scrn1; }if (curwin == 1) { ou = scrn2; }if (curwin == 2) { ou = scrn3; }if (curwin == 3) { ou = scrn4; } }
			if (layout == 12) { if (curwin == 2) { ou = scrn1; }if (curwin == 3) { ou = scrn2; }if (curwin == 4) { ou = scrn3; }if (curwin == 1) { ou = scrn4; } }
			if (ou == 2 && mpo2 > winy[curwin - 1] + 20 && mdon == 0) {
				hwin = curwin - 1;
			if(wireframe[hwin]==1){ wireframe[hwin] = 0; }else{ wireframe[hwin]=1; }
				SetRect(&rc, winx[curwin - 1], winy[curwin - 1], winx[curwin - 1] + winwx[curwin - 1], winy[curwin - 1] + winwy[curwin - 1]);
				ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
			}
			}
		break; }

		case '1': {
			if (game1 == FALSE&&plane == 2) {
			if (layout != 10 && layout != 12) { if (curwin == 1) { ou = scrn1; }if (curwin == 2) { ou = scrn2; }if (curwin == 3) { ou = scrn3; }if (curwin == 4) { ou = scrn4; }if (curwin == 5) { ou = scrn5; }if (curwin == 6) { ou = scrn6; } }
			if (layout == 10) { if (curwin == 4) { ou = scrn1; }if (curwin == 1) { ou = scrn2; }if (curwin == 2) { ou = scrn3; }if (curwin == 3) { ou = scrn4; } }
			if (layout == 12) { if (curwin == 2) { ou = scrn1; }if (curwin == 3) { ou = scrn2; }if (curwin == 4) { ou = scrn3; }if (curwin == 1) { ou = scrn4; } }
			if (ou == 2 && mpo2 > winy[curwin - 1] + 20 && mdon == 0) {
				hwin = curwin - 1;
				ang1[hwin] = 0; ang2[hwin] = 3.142; ang3[hwin] = 1.57;
				SetRect(&rc, winx[curwin - 1], winy[curwin - 1], winx[curwin - 1] + winwx[curwin - 1], winy[curwin - 1] + winwy[curwin - 1]);
				ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
			}
			}
			break; }
		case '2': {
			if (game1 == FALSE&&plane == 2) {
			if (layout != 10 && layout != 12) { if (curwin == 1) { ou = scrn1; }if (curwin == 2) { ou = scrn2; }if (curwin == 3) { ou = scrn3; }if (curwin == 4) { ou = scrn4; }if (curwin == 5) { ou = scrn5; }if (curwin == 6) { ou = scrn6; } }
			if (layout == 10) { if (curwin == 4) { ou = scrn1; }if (curwin == 1) { ou = scrn2; }if (curwin == 2) { ou = scrn3; }if (curwin == 3) { ou = scrn4; } }
			if (layout == 12) { if (curwin == 2) { ou = scrn1; }if (curwin == 3) { ou = scrn2; }if (curwin == 4) { ou = scrn3; }if (curwin == 1) { ou = scrn4; } }
			if (ou == 2 && mpo2 > winy[curwin - 1] + 20 && mdon == 0) {
				hwin = curwin - 1;
				ang1[hwin] = 3.143; ang2[hwin] = 3.142; ang3[hwin] = 1.57;
				SetRect(&rc, winx[curwin - 1], winy[curwin - 1], winx[curwin - 1] + winwx[curwin - 1], winy[curwin - 1] + winwy[curwin - 1]);
				ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
			}
			}
			break; }
		case '3': {
			if (game1 == FALSE&&plane == 2) {
			if (layout != 10 && layout != 12) { if (curwin == 1) { ou = scrn1; }if (curwin == 2) { ou = scrn2; }if (curwin == 3) { ou = scrn3; }if (curwin == 4) { ou = scrn4; }if (curwin == 5) { ou = scrn5; }if (curwin == 6) { ou = scrn6; } }
			if (layout == 10) { if (curwin == 4) { ou = scrn1; }if (curwin == 1) { ou = scrn2; }if (curwin == 2) { ou = scrn3; }if (curwin == 3) { ou = scrn4; } }
			if (layout == 12) { if (curwin == 2) { ou = scrn1; }if (curwin == 3) { ou = scrn2; }if (curwin == 4) { ou = scrn3; }if (curwin == 1) { ou = scrn4; } }
			if (ou == 2 && mpo2 > winy[curwin - 1] + 20 && mdon == 0) {
				hwin = curwin - 1;
				ang1[hwin] = 1.57; ang2[hwin] = 3.143; ang3[hwin] = 1.57;
				SetRect(&rc, winx[curwin - 1], winy[curwin - 1], winx[curwin - 1] + winwx[curwin - 1], winy[curwin - 1] + winwy[curwin - 1]);
				ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
			}
			}
			break; }
		case '4': {
			if (game1 == FALSE&&plane == 2) {
			if (layout != 10 && layout != 12) { if (curwin == 1) { ou = scrn1; }if (curwin == 2) { ou = scrn2; }if (curwin == 3) { ou = scrn3; }if (curwin == 4) { ou = scrn4; }if (curwin == 5) { ou = scrn5; }if (curwin == 6) { ou = scrn6; } }
			if (layout == 10) { if (curwin == 4) { ou = scrn1; }if (curwin == 1) { ou = scrn2; }if (curwin == 2) { ou = scrn3; }if (curwin == 3) { ou = scrn4; } }
			if (layout == 12) { if (curwin == 2) { ou = scrn1; }if (curwin == 3) { ou = scrn2; }if (curwin == 4) { ou = scrn3; }if (curwin == 1) { ou = scrn4; } }
			if (ou == 2 && mpo2 > winy[curwin - 1] + 20 && mdon == 0) {
				hwin = curwin - 1;
				ang1[hwin] = 4.712; ang2[hwin] = 3.143; ang3[hwin] = 1.57;
				SetRect(&rc, winx[curwin - 1], winy[curwin - 1], winx[curwin - 1] + winwx[curwin - 1], winy[curwin - 1] + winwy[curwin - 1]);
				ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
			}
			}
			break; }
		case '6': {
			if (game1 == FALSE&&plane == 2) {
			if (layout != 10 && layout != 12) { if (curwin == 1) { ou = scrn1; }if (curwin == 2) { ou = scrn2; }if (curwin == 3) { ou = scrn3; }if (curwin == 4) { ou = scrn4; }if (curwin == 5) { ou = scrn5; }if (curwin == 6) { ou = scrn6; } }
			if (layout == 10) { if (curwin == 4) { ou = scrn1; }if (curwin == 1) { ou = scrn2; }if (curwin == 2) { ou = scrn3; }if (curwin == 3) { ou = scrn4; } }
			if (layout == 12) { if (curwin == 2) { ou = scrn1; }if (curwin == 3) { ou = scrn2; }if (curwin == 4) { ou = scrn3; }if (curwin == 1) { ou = scrn4; } }
			if (ou == 2 && mpo2 > winy[curwin - 1] + 20 && mdon == 0) {
				hwin = curwin - 1;
				ang1[hwin] = 0; ang2[hwin] = 4.712; ang3[hwin] = 1.57;
				SetRect(&rc, winx[curwin - 1], winy[curwin - 1], winx[curwin - 1] + winwx[curwin - 1], winy[curwin - 1] + winwy[curwin - 1]);
				ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
			}
			}
			break; }
		case '5': {
			if (game1 == FALSE&&plane == 2) {
			if (layout != 10 && layout != 12) { if (curwin == 1) { ou = scrn1; }if (curwin == 2) { ou = scrn2; }if (curwin == 3) { ou = scrn3; }if (curwin == 4) { ou = scrn4; }if (curwin == 5) { ou = scrn5; }if (curwin == 6) { ou = scrn6; } }
			if (layout == 10) { if (curwin == 4) { ou = scrn1; }if (curwin == 1) { ou = scrn2; }if (curwin == 2) { ou = scrn3; }if (curwin == 3) { ou = scrn4; } }
			if (layout == 12) { if (curwin == 2) { ou = scrn1; }if (curwin == 3) { ou = scrn2; }if (curwin == 4) { ou = scrn3; }if (curwin == 1) { ou = scrn4; } }
			if (ou == 2 && mpo2 > winy[curwin - 1] + 20 && mdon == 0) {
				hwin = curwin - 1;
				ang1[hwin] = 0; ang2[hwin] = 1.57; ang3[hwin] = 1.57;
				SetRect(&rc, winx[curwin - 1], winy[curwin - 1], winx[curwin - 1] + winwx[curwin - 1], winy[curwin - 1] + winwy[curwin - 1]);
				ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
			}
			}
			break; }
		}
		break; }

	case WM_KEYUP:{
	switch(LOWORD(wParam)){
	case VK_SHIFT:{
	if(panop==1){ panop=0;}
	break;}
	case VK_CONTROL:{
	if(panop==2){ panop=0;}
	break;}
	}
	}break;

	case WM_KEYDOWN: {
		switch (LOWORD(wParam)) {
		case VK_ESCAPE:{
		if(obmen>0){ obmen=0; ValidateRect(hwnd,NULL); InvalidateRect(hwnd,NULL,TRUE); }
		break;}

		case VK_SHIFT:{
		panop=1;
		break;}

		case VK_CONTROL:{
		panop=2;
		break;}

		case VK_ADD: {
			if (game1==FALSE&&plane == 2) {
			if (layout != 10 && layout != 12) { if (curwin == 1) { ou = scrn1; }if (curwin == 2) { ou = scrn2; }if (curwin == 3) { ou = scrn3; }if (curwin == 4) { ou = scrn4; }if (curwin == 5) { ou = scrn5; }if (curwin == 6) { ou = scrn6; } }
			if (layout == 10) { if (curwin == 4) { ou = scrn1; }if (curwin == 1) { ou = scrn2; }if (curwin == 2) { ou = scrn3; }if (curwin == 3) { ou = scrn4; } }
			if (layout == 12) { if (curwin == 2) { ou = scrn1; }if (curwin == 3) { ou = scrn2; }if (curwin == 4) { ou = scrn3; }if (curwin == 1) { ou = scrn4; } }
			if (ou == 2 && mpo2 > winy[curwin - 1] + 20 && mdon == 0) {
				hwin = curwin - 1;
				zoom[hwin] += (0.1*zoom[hwin]);
				SetRect(&rc, winx[curwin - 1], winy[curwin - 1], winx[curwin - 1] + winwx[curwin - 1], winy[curwin - 1] + winwy[curwin - 1]);
				ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
			}
			}
			break;}
		case VK_SUBTRACT: {
			if (game1 == FALSE&&plane == 2) {
				if (layout != 10 && layout != 12) { if (curwin == 1) { ou = scrn1; }if (curwin == 2) { ou = scrn2; }if (curwin == 3) { ou = scrn3; }if (curwin == 4) { ou = scrn4; }if (curwin == 5) { ou = scrn5; }if (curwin == 6) { ou = scrn6; } }
			if (layout == 10) { if (curwin == 4) { ou = scrn1; }if (curwin == 1) { ou = scrn2; }if (curwin == 2) { ou = scrn3; }if (curwin == 3) { ou = scrn4; } }
			if (layout == 12) { if (curwin == 2) { ou = scrn1; }if (curwin == 3) { ou = scrn2; }if (curwin == 4) { ou = scrn3; }if (curwin == 1) { ou = scrn4; } }
			if (ou == 2 && mpo2 > winy[curwin - 1] + 20 && mdon == 0) {
				hwin = curwin - 1;
				zoom[hwin] -= (0.1*zoom[hwin]);
				if(zoom[hwin]<0.0000000001){ zoom[hwin]=0.0000000001; }
				SetRect(&rc, winx[curwin - 1], winy[curwin - 1], winx[curwin - 1] + winwx[curwin - 1], winy[curwin - 1] + winwy[curwin - 1]);
				ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
			}
			}
			break;}
		case VK_RIGHT: {
			if (game1 == FALSE&&plane == 2) {
			if (layout != 10 && layout != 12) { if (curwin == 1) { ou = scrn1; }if (curwin == 2) { ou = scrn2; }if (curwin == 3) { ou = scrn3; }if (curwin == 4) { ou = scrn4; }if (curwin == 5) { ou = scrn5; }if (curwin == 6) { ou = scrn6; } }
			if (layout == 10) { if (curwin == 4) { ou = scrn1; }if (curwin == 1) { ou = scrn2; }if (curwin == 2) { ou = scrn3; }if (curwin == 3) { ou = scrn4; } }
			if (layout == 12) { if (curwin == 2) { ou = scrn1; }if (curwin == 3) { ou = scrn2; }if (curwin == 4) { ou = scrn3; }if (curwin == 1) { ou = scrn4; } }
			if (ou == 2 && mpo2 > winy[curwin - 1] + 20 && mdon == 0) {
				hwin = curwin - 1;
				ang1[hwin] += 0.3; if (ang1[hwin] > 6.28) { ang1[hwin] = 0; }
				SetRect(&rc, winx[curwin - 1], winy[curwin - 1], winx[curwin - 1] + winwx[curwin - 1], winy[curwin - 1] + winwy[curwin - 1]);
				ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
			}
			}
			break;}
		case VK_LEFT: {
			if (game1 == FALSE&&plane == 2) {
			if (layout != 10 && layout != 12) { if (curwin == 1) { ou = scrn1; }if (curwin == 2) { ou = scrn2; }if (curwin == 3) { ou = scrn3; }if (curwin == 4) { ou = scrn4; }if (curwin == 5) { ou = scrn5; }if (curwin == 6) { ou = scrn6; } }
			if (layout == 10) { if (curwin == 4) { ou = scrn1; }if (curwin == 1) { ou = scrn2; }if (curwin == 2) { ou = scrn3; }if (curwin == 3) { ou = scrn4; } }
			if (layout == 12) { if (curwin == 2) { ou = scrn1; }if (curwin == 3) { ou = scrn2; }if (curwin == 4) { ou = scrn3; }if (curwin == 1) { ou = scrn4; } }
			if (ou == 2 && mpo2 > winy[curwin - 1] + 20 && mdon == 0) {
				hwin = curwin - 1;
				ang1[hwin] -= 0.3; if (ang1[hwin] < 0) { ang1[hwin] = 6.28; }
				SetRect(&rc, winx[curwin - 1], winy[curwin - 1], winx[curwin - 1] + winwx[curwin - 1], winy[curwin - 1] + winwy[curwin - 1]);
				ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
			}
			}
			break;}
		case VK_UP: {
		if (game1 == FALSE&&plane == 2) {
			if (layout != 10 && layout != 12) { if (curwin == 1) { ou = scrn1; }if (curwin == 2) { ou = scrn2; }if (curwin == 3) { ou = scrn3; }if (curwin == 4) { ou = scrn4; }if (curwin == 5) { ou = scrn5; }if (curwin == 6) { ou = scrn6; } }
			if (layout == 10) { if (curwin == 4) { ou = scrn1; }if (curwin == 1) { ou = scrn2; }if (curwin == 2) { ou = scrn3; }if (curwin == 3) { ou = scrn4; } }
			if (layout == 12) { if (curwin == 2) { ou = scrn1; }if (curwin == 3) { ou = scrn2; }if (curwin == 4) { ou = scrn3; }if (curwin == 1) { ou = scrn4; } }
			if (ou == 2 && mpo2 > winy[curwin - 1] + 20 && mdon == 0) {
				hwin = curwin - 1;
				ang2[hwin] += 0.3; if (ang2[hwin] > 6.28) { ang2[hwin] = 0; }
				SetRect(&rc, winx[curwin - 1], winy[curwin - 1], winx[curwin - 1] + winwx[curwin - 1], winy[curwin - 1] + winwy[curwin - 1]);
				ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
			}
			}
			break;}
		case VK_DOWN: {
			if (game1 == FALSE&&plane == 2) {
			if (layout != 10 && layout != 12) { if (curwin == 1) { ou = scrn1; }if (curwin == 2) { ou = scrn2; }if (curwin == 3) { ou = scrn3; }if (curwin == 4) { ou = scrn4; }if (curwin == 5) { ou = scrn5; }if (curwin == 6) { ou = scrn6; } }
			if (layout == 10) { if (curwin == 4) { ou = scrn1; }if (curwin == 1) { ou = scrn2; }if (curwin == 2) { ou = scrn3; }if (curwin == 3) { ou = scrn4; } }
			if (layout == 12) { if (curwin == 2) { ou = scrn1; }if (curwin == 3) { ou = scrn2; }if (curwin == 4) { ou = scrn3; }if (curwin == 1) { ou = scrn4; } }
			if (ou == 2 && mpo2 > winy[curwin - 1] + 20 && mdon == 0) {
				hwin = curwin - 1;
				ang2[hwin] -= 0.3; if (ang2[hwin] < 0) { ang2[hwin] = 6.28; }
				SetRect(&rc, winx[curwin - 1], winy[curwin - 1], winx[curwin - 1] + winwx[curwin - 1], winy[curwin - 1] + winwy[curwin - 1]);
				ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
			}
			}
			break;}
		case VK_SPACE: {
			if (game1 == FALSE&&plane == 2) {
			if (layout != 10 && layout != 12) { if (curwin == 1) { ou = scrn1; }if (curwin == 2) { ou = scrn2; }if (curwin == 3) { ou = scrn3; }if (curwin == 4) { ou = scrn4; }if (curwin == 5) { ou = scrn5; }if (curwin == 6) { ou = scrn6; } }
			if (layout == 10) { if (curwin == 4) { ou = scrn1; }if (curwin == 1) { ou = scrn2; }if (curwin == 2) { ou = scrn3; }if (curwin == 3) { ou = scrn4; } }
			if (layout == 12) { if (curwin == 2) { ou = scrn1; }if (curwin == 3) { ou = scrn2; }if (curwin == 4) { ou = scrn3; }if (curwin == 1) { ou = scrn4; } }
			if (ou == 2 && mpo2 > winy[curwin - 1] + 20 && mdon == 0) {
				if (project[curwin - 1] == 0) { project[curwin - 1] = 1; }
				else { project[curwin-1] = 0; }
				SetRect(&rc, winx[curwin - 1], winy[curwin - 1], winx[curwin - 1] + winwx[curwin - 1], winy[curwin - 1] + winwy[curwin - 1]);
				ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
			}
			}
			break;}
					   }
		break; }
	case WM_CREATE: {
		hbm = LoadBitmap(GetModuleHandle(NULL), "COVER");
		lig1 = LoadBitmap(GetModuleHandle(NULL), "LOGO");
		lig2 = LoadBitmap(GetModuleHandle(NULL), "LOGOM");
		lig3 = LoadBitmap(GetModuleHandle(NULL), "TECH");
		lig4 = LoadBitmap(GetModuleHandle(NULL), "TECHM");
		lig5 = LoadBitmap(GetModuleHandle(NULL), "LIN");
		lig6 = LoadBitmap(GetModuleHandle(NULL), "LINM");
		lig7 = LoadBitmap(GetModuleHandle(NULL), "CRY");
		lig8 = LoadBitmap(GetModuleHandle(NULL), "CRYM");
		lig9 = LoadBitmap(GetModuleHandle(NULL), "DISP");
		sefari = LoadBitmap(GetModuleHandle(NULL), "BACK");

		SetTimer(hwnd, 1, 100, NULL);
		hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc);
		bufary = (float*)malloc(sizeof(float*)*200000000);
		showobj = (int*)malloc(sizeof(int*)*500000);
		obcc = (int*)malloc(sizeof(int*)*500000);
		materil = (char**)malloc(sizeof(char**)*500000);
		diffuse = (GLuint**)malloc(sizeof(GLuint**)*500000);
		matprop = (mantel**)malloc(sizeof(mantel**)*500000);
		colr = (vectz**)malloc(sizeof(vectz**)*500000);
		gcont=(int*)malloc(sizeof(int*)*500000);
		mauv = (vectz*)malloc(sizeof(vectz*)*500000);
		scil = (vectz*)malloc(sizeof(vectz*)*500000);
		rita = (vectz*)malloc(sizeof(vectz*)*500000);
		gauv = (vectz**)malloc(sizeof(vectz**)*500000);
		scal = (vectz**)malloc(sizeof(vectz**)*500000);
		rota = (vectz**)malloc(sizeof(vectz**)*500000);
		frame = (vectz**)malloc(sizeof(vectz**)*500000);
		center = (vectz**)malloc(sizeof(vectz**)*500000);
		fice = (int**)malloc(sizeof(int**)*500000);
		grup = (int**)malloc(sizeof(int**)*500000);
		subg = (int*)malloc(sizeof(int*)*500000);
		matcount = (int*)malloc(sizeof(int*)*500000);
		fcon = (int*)malloc(sizeof(int*)*500000);
		vers = (int*)malloc(sizeof(int*)*500000);
		mtc = (int*)malloc(sizeof(int*)*500000);
		camera = (char*)malloc(sizeof(char*)*500000);
		light = (char*)malloc(sizeof(char*)*500000);
		pivot = (char*)malloc(sizeof(char*)*500000);
		texturename = (char**)malloc(sizeof(char**)*500000);

		verr = (GLfloat*)malloc(sizeof(GLfloat*)*50000);

		GetModuleFileName(GetModuleHandle(NULL), wild, MAX_PATH);
		for (int a = strlen(wild);a > 0;a--) { if (wild[a] == '\\') { wild[a] = 0; break; } }
		sprintf_s(wild, "%s\\", wild);
		
		sprintf(how1, "%sbinaries\\cube.bin", wild);
		
		fi = fopen(how1, "r");
	if(fi!=NULL){
		fseek(fi, 0, SEEK_END);
		ou = ftell(fi);
		fseek(fi, 0, SEEK_SET);
		for (int a = 0;a < ou;a++){ square[a]=(fgetc(fi)- 100)/25.0;  }
		fclose(fi);
		bull = ou;
	}
		
	for(int a=0;a<300;a++){ lip[a].x=-1; lip[a].y=-1; }
	sprintf(camera, "Camera 1:-0.5,0.2,0.1,0,0,0,1000,0.1,16,9,0.8,1,1,1,500,100,50,50,50,1,3.2,;Camera 2:0.4,0.4,0.1,0,0,90,1000,0.1,16,9,0.8,0,1,1,600,100, 100,50,20,2,3.2,;");
	sprintf(light, "Directional:1,0.8,0.4,0.5,0,90,90,0.1,1,1,5,1,0,0,0,1,1,;Flashlight:2,0.8,0.5,0.2,0,90,90,15,0.2,1,12,1,0,0,0,1,0.1,0.8,1,1,;Point:3,0.1,-0.5,0.4,10,0.7,0.5,5,1,0.2,;");
	sprintf(pivot, "Pivot 1:0.2,0.3,0.4;");
	}
	break;

	case WM_GETMINMAXINFO: {
		lpm = (LPMINMAXINFO)lParam;
		lpm->ptMinTrackSize.x = 500;
		lpm->ptMinTrackSize.y = 400;
		break; }

	case WM_SETFOCUS: {
		FOCUS(hwnd);
		ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		break;
	}
	case WM_KILLFOCUS: {
		menu = 0; menu1 = 0;  menu2 = 0; if (pop != 0) { pop = 0; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
	  break; }

	case WM_ERASEBKGND: {
		return 1;
		break;}

	case WM_COMMAND:{
	switch(LOWORD(wParam)){
	
	case EDIT1:{
	SendMessage(hedit,WM_GETTEXT,sizeof(how1)/sizeof(how1[0]),reinterpret_cast<LPARAM>(how1));
	for(int i=0;i<strlen(how1);i++){
	if(how1[i]=='\n'||how1[i]=='\r'){ i+=2;
	for(0;i<strlen(how1);i++){ how3[i-2]=how1[i]; }
	how3[i-2]=0; edestroy=1; SetTimer(hwnd,1,10,NULL);
	break;}
	how3[i]=how1[i];
	}
	//if(editcrea>0){ SendMessage(hedit,WM_GETTEXT,sizeof(how3)/sizeof(how3[0]),reinterpret_cast<LPARAM>(how3)); edestroy=2; SetTimer(hwnd,1,10,NULL); }
	break;}

	}
	break; }

	case WM_CTLCOLOREDIT: {
	HDC hrc=(HDC)wParam;
	SetTextColor(hrc,RGB(255,255,255));
	SetBkColor(hrc,RGB(80,80,80));
		break; }

	case WM_CLOSE:
		PostQuitMessage(0);
		break;

	case WM_DESTROY:
		DestroyWindow(hwnd);
		PostQuitMessage(0);
		break;



	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
}


int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int iCmdShow)
{
	HDC hDC;
	HGLRC hRC;
	BOOL bQuit = FALSE;
	

	WNDCLASSEX wc;
	HWND hwnd;
	MSG msg;


	memset(&wc, 0, sizeof(wc));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.hCursor = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;

	wc.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(1, 33, 32));
	wc.lpszClassName = "GLSample";
	wc.hIcon = LoadIcon(GetModuleHandle(NULL), "ICO");
	wc.hIconSm = LoadIcon(GetModuleHandle(NULL), "ICO");
	wc.lpszMenuName = NULL;

	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(0, "GLSample", "Asteroid Technology",
		WS_POPUP|WS_VISIBLE|WS_CLIPCHILDREN,
		GetSystemMetrics(SM_CXSCREEN) / 2 - 350, GetSystemMetrics(SM_CYSCREEN) / 2 - 250, 700, 500,
		NULL, NULL, hInstance, NULL);

	hfile = CreateFile("vertex.h", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	dwFileSize = GetFileSize(hfile, NULL);
	source = (LPSTR)GlobalAlloc(GPTR, dwFileSize + 1);
	
	if (source != NULL) {
		if (ReadFile(hfile, source, dwFileSize, &dwRead, NULL)) { source[dwFileSize] = 0; }
	}
	else { MessageBox(NULL, "Error loading Kernel", "Error", MB_ICONEXCLAMATION | MB_OK); }
	CloseHandle(hfile);

	hfile = CreateFile("fragment.h", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	dwFileSize = GetFileSize(hfile, NULL);
	frag = (LPSTR)GlobalAlloc(GPTR, dwFileSize + 1);

	if (frag != NULL) {
		if (ReadFile(hfile, frag, dwFileSize, &dwRead, NULL)) { frag[dwFileSize] = 0; }
	}
	else { MessageBox(NULL, "Error loading Kernel", "Error", MB_ICONEXCLAMATION | MB_OK); }
	CloseHandle(hfile);

	EnableOpenGL(hwnd, &hDC, &hRC);
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		return -1;
	}


	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &source, NULL);
	glCompileShader(vertexShader);


	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &frag, NULL);
	glCompileShader(fragmentShader);


	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glGenTextures(1, &texture);
	glGenTextures(1, &black);



	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//generate reflection cubemap
	glGenTextures(1, &cubemap);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemap);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemap);
	width = 512; height = 512;
	for (GLuint i = 0;i<6; i++){
	sprintf(how1,"C:\\CRYSTAL PROGRAMS\\Asteroid Technology\\Asteroid Technology%s",faces[i]);
	image = SOIL_load_image(how1, &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X+i, 0,GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	if(!image){ sprintf(report,"Error in startup"); report1=1; SetTimer(hwnd,1,3000,NULL); }
	}
	
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R,GL_CLAMP_TO_EDGE);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);


	//end of cubemap
	width = 997; height = 997;
	sefari = LoadBitmap(GetModuleHandle(NULL), "BACKi");
	GetBitmapBits(sefari, sizeof(bit), &bit);
	glGenTextures(1, &black);
	glBindTexture(GL_TEXTURE_2D, black);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bit);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);

	loa = LoadBitmap(GetModuleHandle(NULL), "SPRITE");
	GetBitmapBits(loa, sizeof(bit), &bit);
	width = 950; height = 536;
	
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bit);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	DeleteObject(loa);
	//sky box
	width = 512; height = 512;
	loa = LoadBitmap(GetModuleHandle(NULL), "SKY1");
	GetBitmapBits(loa, sizeof(bit), &bit);
	glGenTextures(1, &sky1);
	glBindTexture(GL_TEXTURE_2D, sky1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bit);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
	DeleteObject(loa);
	//SKY2
	loa = LoadBitmap(GetModuleHandle(NULL), "SKY2");
	GetBitmapBits(loa, sizeof(bit), &bit);
	glGenTextures(1, &sky2);
	glBindTexture(GL_TEXTURE_2D, sky2);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bit);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
	DeleteObject(loa);
	//SKY3
	loa = LoadBitmap(GetModuleHandle(NULL), "SKY3");
	GetBitmapBits(loa, sizeof(bit), &bit);
	glGenTextures(1, &sky3);
	glBindTexture(GL_TEXTURE_2D, sky3);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bit);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
	DeleteObject(loa);
	//SKY4
	loa = LoadBitmap(GetModuleHandle(NULL), "SKY4");
	GetBitmapBits(loa, sizeof(bit), &bit);
	glGenTextures(1, &sky4);
	glBindTexture(GL_TEXTURE_2D, sky4);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bit);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
	DeleteObject(loa);
	//SKY5
	loa = LoadBitmap(GetModuleHandle(NULL), "SKY5");
	GetBitmapBits(loa, sizeof(bit), &bit);
	glGenTextures(1, &sky5);
	glBindTexture(GL_TEXTURE_2D, sky5);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bit);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
	DeleteObject(loa);
	//SKY6
	loa = LoadBitmap(GetModuleHandle(NULL), "SKY6");
	GetBitmapBits(loa, sizeof(bit), &bit);
	glGenTextures(1, &sky6);
	glBindTexture(GL_TEXTURE_2D, sky6);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bit);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
	DeleteObject(loa);

	for(int a=0;a<13;a++){
	glGenFramebuffers(1, &depthMapFBO[a]);
	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO[a]);
	glGenTextures(1, &depthMap[a]);
	glBindTexture(GL_TEXTURE_2D, depthMap[a]);
	glTexImage2D(GL_TEXTURE_2D,0,GL_DEPTH_COMPONENT,1024,1024,0,GL_DEPTH_COMPONENT,GL_FLOAT,NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap[a], 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}
	//hdr
	glGenFramebuffers(1, &hdr);
	glBindFramebuffer(GL_FRAMEBUFFER, hdr);
	glGenTextures(1, &hdrmap);
	glBindTexture(GL_TEXTURE_2D, hdrmap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1500, 1500, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, hdrmap, 0);

	//blur
	glGenFramebuffers(1, &blur);
	glBindFramebuffer(GL_FRAMEBUFFER, blur);

	glGenTextures(1, &blurmap);
	glBindTexture(GL_TEXTURE_2D, blurmap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, 1500, 1500, 0, GL_RGB, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, blurmap, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	
	

	glGenFramebuffers(1, &fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);

	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, 1500, 1500, 0, GL_RGB, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture1, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	

	glGenRenderbuffers(1, &rbo);
	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 1500, 1500);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	//end of codes
	GLuint attachments[2] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1 };
	glDrawBuffers(2, attachments);


	while (!bQuit)
	{

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{

			if (msg.message == WM_QUIT)
			{
				bQuit = TRUE;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{

			
		}
	}

	DisableOpenGL(hwnd, hDC, hRC);
	glDeleteFramebuffers(1, &fbo);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	DestroyWindow(hwnd);

	return msg.wParam;
}


void EnableOpenGL(HWND hwnd, HDC *hDC, HGLRC *hRC)
{
	PIXELFORMATDESCRIPTOR pfd;
	int iFormat;

	
	*hDC = GetDC(hwnd);

	
	ZeroMemory(&pfd, sizeof(pfd));
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;
	iFormat = ChoosePixelFormat(*hDC, &pfd);
	SetPixelFormat(*hDC, iFormat, &pfd);

	
	*hRC = wglCreateContext(*hDC);
	wglMakeCurrent(*hDC, *hRC);

}



void DisableOpenGL(HWND hwnd, HDC hDC, HGLRC hRC)
{
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(hRC);
	ReleaseDC(hwnd, hDC);
}