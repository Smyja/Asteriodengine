#include<windows.h>

void upmenu() {
	hgc = CreateCompatibleDC(hdc);
	hgm = CreateCompatibleBitmap(hdc, csize, 20);
	SelectObject(hgc, hgm);
	
	SetRect(&rc, 0, 0, csize, 20);
	brush = CreateSolidBrush(RGB(50, 50, 50));
	FillRect(hgc, &rc, brush);
	
	hf = CreateFont(14,6,0,0,0,0,0,0,DEFAULT_CHARSET,0,0,0,DEFAULT_GUI_FONT,"ARIAL");
	SelectObject(hgc, hf);
	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);
	TextOut(hgc, 10, 2, "File", 4);
	TextOut(hgc, 43, 2, "Execute", 7);
	TextOut(hgc, 98, 2, "Build", 5);
	TextOut(hgc, 139, 2, "Build Options", 13);
	TextOut(hgc, 225, 2, "Tools", 5);

	DeleteObject(hf); DeleteObject(brush);
	BitBlt(hdc, 0, 0, csize, 20, hgc, 0, 0, SRCCOPY);
	DeleteDC(hgc);
	DeleteObject(hgm);
}

void run() {

	hgc = CreateCompatibleDC(hdc);
	hgm = CreateCompatibleBitmap(hdc, csize, 30);
	SelectObject(hgc, hgm);

	SetRect(&rc, 0, 0, csize, 30);
	brush = CreateSolidBrush(RGB(50, 50, 50));
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);
	brush = CreateSolidBrush(RGB(100, 100, 100));
	SelectObject(hgc,brush);
	hp = CreatePen(PS_SOLID, 1, RGB(60,60, 60));
	SelectObject(hgc, hp);
	RoundRect(hgc, csize / 2 - 28, 5, csize / 2 , 27, 5, 5);
	RoundRect(hgc, csize / 2 + 38, 5, csize / 2 , 27, 5, 5);
	if (menu == 1) { menu1 = 0; }
	if(menu1==0){ RoundRect(hgc, csize - 45, 1, csize - 10, 29, 5, 5);  }
	Rectangle(hgc, csize / 2 - 8, 5, csize / 2 + 14, 27);
	DeleteObject(brush); 
	if (menu1 == 1) {
		brush = CreateSolidBrush(RGB(100, 100, 200));
		SelectObject(hgc, brush);
		RoundRect(hgc, csize - 45, 1, csize - 10, 29, 5, 5);
	}
	DeleteObject(hp); DeleteObject(brush);

	hiu = LoadIcon(GetModuleHandle(NULL), "ICO4");
	DrawIcon(hgc, csize/2, 8, hiu); 	DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO5");
	DrawIcon(hgc, csize / 2 - 24, 8, hiu); 	DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO6");
	DrawIcon(hgc, csize / 2 + 20, 9, hiu); 	DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO7");
	DrawIcon(hgc, csize - 40, 2, hiu); 	DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO12");
	DrawIcon(hgc, 10, 7, hiu); 	DeleteObject(hiu);
	DeleteObject(brush);
	hf = CreateFont(15, 7, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
	SelectObject(hgc, hf);
	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);
	TextOut(hgc, 40, 8, "Asteroid Technology", 20);
	DeleteObject(hf);
	DeleteObject(hf); DeleteObject(brush);
	BitBlt(hdc, 0, 21, csize, 30, hgc, 0, 0, SRCCOPY);
	DeleteDC(hgc);
	DeleteObject(hgm);
}

void status() {
	hgc = CreateCompatibleDC(hdc);
	hgm = CreateCompatibleBitmap(hdc, csize, 30);
	SelectObject(hgc, hgm);

	if (report1 == 0) { brush = CreateSolidBrush(RGB(100, 100, 100)); }
	else if(report1==1){ brush = CreateSolidBrush(RGB(255, 100, 50));  }
	else if (report1 == 2) { brush = CreateSolidBrush(RGB(50, 100, 255)); }
	SelectObject(hgc, brush);
	hp = CreatePen(PS_SOLID, 1, RGB(60, 60, 60));
	SelectObject(hgc, hp);
	Rectangle(hgc, 0, 0, csize, 33);
	DeleteObject(brush); DeleteObject(hp);
	DeleteObject(hf); DeleteObject(brush);
	
	hf = CreateFont(15, 7, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
	SelectObject(hgc, hf);
	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);
	TextOut(hgc, 5, 5, report, strlen(report));
	DeleteObject(hf);

	BitBlt(hdc, 0, csize2-25, csize, 25, hgc, 0, 0, SRCCOPY);
	DeleteDC(hgc);
	DeleteObject(hgm);
}

void view() { ou=0;
	if(skew==1&&gamon==1){ ou=1; }
	if(ou==0){
	hgc = CreateCompatibleDC(hdc);
	hgm = CreateCompatibleBitmap(hdc, wx, wy);
	SelectObject(hgc, hgm);

	SetRect(&rc, 1, 20, wx-2, wy-2);
	brush = CreateSolidBrush(RGB(50, 50, 50));
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);
	
	hf = CreateFont(15, 7, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
	SelectObject(hgc, hf);
	ou = 25; bu = tres[hover1]; oclik[hover1] = -1; mclick[hover1] = -1; jclick[hover1] = -1; lclick[hover1] = -1; pclick[hover1] = -1;
	for (int a = 0,b=0,c=0,d=0;a < strlen(tree);a++) {
		how[b] = tree[a]; b++;
		if (tree[a+1] == ':') { how[b] = 0; b = 0; c++;
		if (mlik == c - 1&&bu>=30&&bu<wy-2) {
			SetRect(&rc,  1, bu - 2,  wx - 3, bu + 18);
			brush = CreateSolidBrush(RGB(200, 100, 100));
			FillRect(hgc, &rc, brush);
			DeleteObject(brush);
		}
		if (mpo1 > stx&&mpo1<stx + wx&&mpo2 - sty>bu - 2 && mpo2 - sty < bu + 18&&pop==0 && menu == 0&&bu>=30&&bu<wy-2) {
			if(obmen==0){
			SetRect(&rc, 1, bu-2, wx-3, bu+18);
			brush = CreateSolidBrush(RGB(100, 100, 200)); 
			FillRect(hgc, &rc, brush);
			DeleteObject(brush); 
			}
			oclik[hover1] = c-1;
			 }
		
if(bu>=30&&bu<wy-2){
		TextOut(hgc, ou, bu, how, strlen(how)); 
		if (click!=c-1) { hiu = LoadIcon(GetModuleHandle(NULL), "ICO33"); }else{ hiu = LoadIcon(GetModuleHandle(NULL), "ICO34"); }
		DrawIcon(hgc, 5, bu+1, hiu); DeleteObject(hiu);
}
		bu += 20; 
		if (click != c - 1) { for (0;a < strlen(tree);a++) { if (tree[a] == '\n') { break; } } }
		
		else { a+=2; d=0;
			for (0;a < strlen(tree);a++) {
				if (tree[a] == '\n') { break; }
				how[b] = tree[a]; b++;
				if (tree[a + 1] == ';') {  how[b] = 0; b = 0; a+=1; d++;
				if (click == c - 1&&fclick==d-1&&bu>=30&&bu<wy-2) {
					SetRect(&rc,  1, bu - 2,  wx - 3, bu + 18);
					brush = CreateSolidBrush(RGB(100, 200, 100));
					FillRect(hgc, &rc, brush);
					DeleteObject(brush);
				}
				if (mpo1 > stx&&mpo1<stx + wx&&mpo2 - sty>bu - 2 && mpo2 - sty < bu + 18 && pop == 0 && menu == 0 && bu >= 30 && bu < wy - 2) {
				if(obmen==0){
					SetRect(&rc, 1, bu - 2, wx - 3, bu + 18);
					brush = CreateSolidBrush(RGB(100, 100, 200));
					FillRect(hgc, &rc, brush);
					DeleteObject(brush);
				}
				mclick[hover1] = d - 1;
				}

				if(bu>=30&&bu<wy-2){ TextOut(hgc, ou+10, bu, how, strlen(how)); }
				bu += 20;
				}
			}
		}


		}
		if (bu +30> wy) { break; }
	}
	DeleteObject(hf);

	for (int a = 0,b=0,c=0;a < strlen(camera);a++) {
		how[b] = camera[a]; b++;
		if (camera[a + 1] == ':') { how[b] = 0; b = 0;  c++;
	//underlayer
	if (jlik == c - 1&&bu>=30&&bu<wy-2) {
			SetRect(&rc,  1, bu - 2,  wx - 3, bu + 18);
			brush = CreateSolidBrush(RGB(200, 100, 100));
			FillRect(hgc, &rc, brush);
			DeleteObject(brush); 
		}
	if (mpo1 > stx&&mpo1<stx + wx&&mpo2 - sty>bu - 2 && mpo2 - sty < bu + 18 && pop == 0&&menu==0&&bu>=30&&bu<wy-2) {
		if (obmen == 0) {
			SetRect(&rc, 1, bu - 2, wx - 3, bu + 18);
			brush = CreateSolidBrush(RGB(100, 100, 200));
			FillRect(hgc, &rc, brush);
			DeleteObject(brush); 
			}
	jclick[hover1] = c-1;
		}
if(bu>=30&&bu<wy-2){ hiu = LoadIcon(GetModuleHandle(NULL), "ICO41");  DrawIcon(hgc, 5, bu + 1, hiu); DeleteObject(hiu);
		TextOut(hgc, ou, bu, how, strlen(how)); }
		bu += 20;
	for(0;a<strlen(camera);a++){ if(camera[a]==';'){break;} }
		}
	}
	//pivot
	for (int a = 0,b=0,c=0;a < strlen(pivot);a++) {
		how[b] = pivot[a]; b++;
		if (pivot[a + 1] == ':') { how[b] = 0; b = 0;  c++;
	//underlayer
	if (plik == c - 1&&bu>=30&&bu<wy-2) {
			SetRect(&rc,  1, bu - 2,  wx - 3, bu + 18);
			brush = CreateSolidBrush(RGB(200, 100, 100));
			FillRect(hgc, &rc, brush);
			DeleteObject(brush); 
		}
	if (mpo1 > stx&&mpo1<stx + wx&&mpo2 - sty>bu - 2 && mpo2 - sty < bu + 18 && pop == 0&&menu==0&&bu>=30&&bu<wy-2) {
	if(obmen==0){	
		SetRect(&rc, 1, bu - 2, wx - 3, bu + 18);
			brush = CreateSolidBrush(RGB(100, 100, 200));
			FillRect(hgc, &rc, brush);
			DeleteObject(brush); 
			}
	pclick[hover1] = c-1;
		}
if(bu>=30&&bu<wy-2){hiu = LoadIcon(GetModuleHandle(NULL), "ICO57");  DrawIcon(hgc, 5, bu + 1, hiu); DeleteObject(hiu);
		TextOut(hgc, ou, bu, how, strlen(how));
		}
		bu += 20;
	for(0;a<strlen(pivot);a++){ if(pivot[a]==';'){break;} }
		}
	}
//light
	for (int a = 0,b=0,c=0;a < strlen(light);a++) {
		how[b] = light[a]; b++;
		if (light[a + 1] == ':') { how[b] = 0; b = 0;  c++;
	//underlayer
	if (lkik == c - 1&&bu>=30&&bu<wy-2) {
			SetRect(&rc,  1, bu - 2,  wx - 3, bu + 18);
			brush = CreateSolidBrush(RGB(200, 100, 100));
			FillRect(hgc, &rc, brush);
			DeleteObject(brush); 
		}
	if (mpo1 > stx&&mpo1<stx + wx&&mpo2 - sty>bu - 2 && mpo2 - sty < bu + 18 && pop == 0&&menu==0&&bu>=30&&bu<wy-2) {
if(obmen==0){	
		SetRect(&rc, 1, bu - 2, wx - 3, bu + 18);
			brush = CreateSolidBrush(RGB(100, 100, 200));
			FillRect(hgc, &rc, brush);
			DeleteObject(brush); 
			}
	lclick[hover1] = c-1;
		}
if(light[a+2]=='1'&&bu>=30&&bu<wy-2){ hiu = LoadIcon(GetModuleHandle(NULL), "ICO59");  DrawIcon(hgc, 5, bu , hiu); DeleteObject(hiu); }
if(light[a+2]=='2'&&bu>=30&&bu<wy-2){ hiu = LoadIcon(GetModuleHandle(NULL), "ICO60");  DrawIcon(hgc, 5, bu-2 , hiu); DeleteObject(hiu); }
if(light[a+2]=='3'&&bu>=30&&bu<wy-2){ hiu = LoadIcon(GetModuleHandle(NULL), "ICO58");  DrawIcon(hgc, 5, bu - 2, hiu); DeleteObject(hiu); }
if(bu>=30&&bu<wy-2){ TextOut(hgc, ou, bu, how, strlen(how)); }
		bu += 20;
	for(0;a<strlen(light);a++){ if(light[a]==';'){break;} }
		}
	}
	DeleteObject(brush); DeleteObject(hp);
	//scrollbar
	hp=CreatePen(PS_SOLID,1,RGB(20,20,20)); SelectObject(hgc,hp);
	brush=CreateSolidBrush(RGB(80,80,80)); SelectObject(hgc,brush);
	thm1=bu-tres[hover1];
	thm2=(wy-3)-21;
	if(thm2>thm1){ thm3=thm2; }
	else{ thm1-=thm2; thm4=thm1/20.0*2.0; thm3=thm2-thm4; }
	trew[hover1]=thm3; if(thm3<20){ thm3=20; } 
	if(tres[hover1]<30){ thm6=30-tres[hover1]; thm6=thm6/20.0*2.0; thm5=21+thm6; }
	else{ thm5=21; }
	RoundRect(hgc,wx-12,thm5,wx-2,thm5+thm3,7,7);
	DeleteObject(brush); DeleteObject(hp);
	//painting
	brush = CreateSolidBrush(RGB(20, 20, 20));
	SetRect(&rc, 0, 0, wx, 21);	FillRect(hgc, &rc, brush);
	SetRect(&rc, 0, 0, 2, wy);	FillRect(hgc, &rc, brush);
	SetRect(&rc, wx - 2, 0, wx, wy);	FillRect(hgc, &rc, brush);
	SetRect(&rc, 0, wy - 2, wx, wy);	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	SetRect(&rc, 0, 0, 20, 19);
	if (hover == hover1) { brush = CreateSolidBrush(RGB(100, 100, 200)); }
	else { brush = CreateSolidBrush(RGB(50, 50, 50)); }
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	hiu = LoadIcon(GetModuleHandle(NULL), "ICO8"); DrawIcon(hgc, 2, 1, hiu); DeleteObject(hiu);
	hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
	SelectObject(hgc, hf);
	TextOut(hgc, 30, 3, "Asteroid Tree", 13);
	DeleteObject(hf);
//end painting
	BitBlt(hdc, stx, sty, wx, wy, hgc, 0, 0, SRCCOPY);
	DeleteDC(hgc);
	DeleteObject(hgm);
	}
}
void pilot() { ou=1;
if(game1==FALSE){ou=0;} if(gamon==1){ ou=0; }
	if(ou==0){ 
	ou=0;
	if(skew==1&&gamon==1){ ou=1; }
	if(ou==0){
	hgc = CreateCompatibleDC(hdc);
	hgm = CreateCompatibleBitmap(hdc, wx, wy);
	SelectObject(hgc, hgm);

	SetRect(&rc, 0, 0, wx, wy);
	brush = CreateSolidBrush(RGB(20, 20, 20));
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	SetRect(&rc, 2, 20, wx - 2, wy - 2);
	brush = CreateSolidBrush(RGB(50, 50, 50));
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	SetRect(&rc, 0, 0, 20, 19);
	if (hover == hover1) { brush = CreateSolidBrush(RGB(100, 100, 200)); }
	else { brush = CreateSolidBrush(RGB(50, 50, 50)); }
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	if (box[hover1] != 0) {
		SetRect(&rc, 118, 1, 136, 19);
		if (box[hover1] == 1) { brush = CreateSolidBrush(RGB(100, 100, 200)); }
		else if (box[hover1] == 2) { brush = CreateSolidBrush(RGB(50, 50, 50)); }
		FillRect(hgc, &rc, brush);
		DeleteObject(brush);
	}

	if (bright[hover1] == 1) {
		SetRect(&rc, 164, 1, 183, 19);
		brush = CreateSolidBrush(RGB(50, 50, 50));
		FillRect(hgc, &rc, brush);
		DeleteObject(brush);
	}

	if (grab[hover1] == 1) {
		SetRect(&rc, 141, 1, 161, 19);
		brush = CreateSolidBrush(RGB(100, 100, 200)); 
		FillRect(hgc, &rc, brush);
		DeleteObject(brush);
	}
	if (grab[hover1] == 2) {
		SetRect(&rc, 141, 1, 161, 19);
		brush = CreateSolidBrush(RGB(200, 100, 100));
		FillRect(hgc, &rc, brush);
		DeleteObject(brush);
	}
	
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO9"); DrawIcon(hgc, 2, 1, hiu); DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO27"); DrawIcon(hgc, 120, 1, hiu); DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO32"); DrawIcon(hgc, 135, -2, hiu); DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO64"); DrawIcon(hgc, 165, 1, hiu); DeleteObject(hiu);
	
	hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
	SelectObject(hgc, hf);
	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);
	TextOut(hgc, 30, 3, "Asteroid Pilot", 15);

	DeleteObject(hf);
	
	//pilot
	ship();
	

	hbc = CreateCompatibleDC(hdc);
	hbm = CreateCompatibleBitmap(hdc, wx-2, wy-21);
	SelectObject(hbc, hbm);
	SetBitmapBits(hbm,(wx-2)*(wy-21)*4, &read);
	BitBlt(hgc, 1, 20, wx - 2, wy - 21, hbc, 0, 0, SRCCOPY);
	DeleteDC(hbc);
	DeleteObject(hbm);

	if (project[hover1] == 0) { TextOut(hgc, 10, 30, "Perspective", 12); }
	else{ TextOut(hgc, 10, 30, "Orthographic", 13); }
	BitBlt(hdc, stx, sty, wx, wy, hgc, 0, 0, SRCCOPY);
	DeleteDC(hgc);
	DeleteObject(hgm);
	} }
	else { gamon=1; gameplay(); }
}

void propet() {
	ou = 0;
	if (skew == 1 && gamon == 1) { ou = 1; }
	if (ou == 0) {
	hgc = CreateCompatibleDC(hdc);
	hgm = CreateCompatibleBitmap(hdc, wx, wy);
	SelectObject(hgc, hgm);
	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);
	SetRect(&rc, 2, 20, wx - 2, wy - 2);
	brush = CreateSolidBrush(RGB(50, 50, 50));
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);
	bu=0;
	mark();

	SetRect(&rc, wx-1, 0, wx, wy);
	brush = CreateSolidBrush(RGB(20, 20, 20));
	FillRect(hgc, &rc, brush);
	SetRect(&rc, 0, wy-1, wx, wy);
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);
	
	//scrollbar
	hp = CreatePen(PS_SOLID, 1, RGB(20, 20, 20)); SelectObject(hgc, hp);
	brush = CreateSolidBrush(RGB(80, 80, 80)); SelectObject(hgc, brush);
	thm1 = bu;
	thm2 = (wy - 3) - 21;
	if (thm2>thm1) { thm3 = thm2; }
	else { thm1 -= thm2; thm4 = thm1 / 20.0*2.0; thm3 = thm2 - thm4; }
	prew[hover1] = thm3; if (thm3<20) { thm3 = 20; }
	if (pres[hover1]>0) { thm6 = pres[hover1]; thm6 = thm6 / 20.0*2.0; thm5 = 21 + thm6; }
	else { thm5 = 21; }
	RoundRect(hgc, wx - 12, thm5, wx - 2, thm5 + thm3, 7, 7);
	DeleteObject(brush); DeleteObject(hp);
	//painting
	brush = CreateSolidBrush(RGB(20, 20, 20));
	SetRect(&rc, 0, 0, wx, 21);	FillRect(hgc, &rc, brush);
	SetRect(&rc, 0, 0, 2, wy);	FillRect(hgc, &rc, brush);
	SetRect(&rc, wx - 2, 0, wx, wy);	FillRect(hgc, &rc, brush);
	SetRect(&rc, 0, wy - 2, wx, wy);	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	SetRect(&rc, 0, 0, 20, 19);
	if (hover == hover1) { brush = CreateSolidBrush(RGB(100, 100, 200)); }
	else { brush = CreateSolidBrush(RGB(50, 50, 50)); }
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	hiu = LoadIcon(GetModuleHandle(NULL), "ICO10"); DrawIcon(hgc, 2, 1, hiu);  DeleteObject(hiu);

	hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
	SelectObject(hgc, hf);
	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);
	TextOut(hgc, 30, 3, "Properties", 11);
	DeleteObject(hf);
	//end painting
	BitBlt(hdc, stx, sty, wx, wy, hgc, 0, 0, SRCCOPY);
	DeleteDC(hgc);
	DeleteObject(hgm);
	}
}

void material(){
	ou = 0;
	if (skew == 1 && gamon == 1) { ou = 1; }
	if (ou == 0) {
	hgc = CreateCompatibleDC(hdc);
	hgm = CreateCompatibleBitmap(hdc, wx, wy);
	SelectObject(hgc, hgm);

	SetRect(&rc, 2, 20, wx - 2, wy - 2);
	brush = CreateSolidBrush(RGB(50, 50, 50));
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);


	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);
	
	if(manon>=0){
	bu=matprop[mlik][manon].Kd;
	hp = CreatePen(PS_SOLID, 1, RGB(0, 0, 0)); SelectObject(hgc, hp);
	brush = CreateSolidBrush(RGB(colr[mlik][bu].x*255.0, colr[mlik][bu].y * 255.0, colr[mlik][bu].z * 255.0)); SelectObject(hgc, brush);
	Rectangle(hgc, 10, 200-mres[hover1], wx-14, 215-mres[hover1]);
	DeleteObject(brush);
	bu=matprop[mlik][manon].Ks;
	//specular
	brush = CreateSolidBrush(RGB(colr[mlik][bu].x*255.0, colr[mlik][bu].y * 255.0, colr[mlik][bu].z * 255.0)); SelectObject(hgc, brush);
	Rectangle(hgc, 50, 385-mres[hover1], wx-14, 400-mres[hover1]);
	DeleteObject(brush); DeleteObject(hp);
	//emmission color
	brush = CreateSolidBrush(RGB(matprop[mlik][manon].emr*255.0, matprop[mlik][manon].emg*255.0,matprop[mlik][manon].emb*255.0)); SelectObject(hgc, brush);
	Rectangle(hgc, 10, 590-mres[hover1], wx - 14, 607-mres[hover1]);
	DeleteObject(brush); DeleteObject(hp);

	hp = CreatePen(PS_SOLID, 1, RGB(0, 0, 0)); SelectObject(hgc, hp);
	brush = CreateSolidBrush(RGB(80,80, 80)); SelectObject(hgc, brush);
	Rectangle(hgc, 50, 220-mres[hover1], wx - 14, 235-mres[hover1]);
	
	Rectangle(hgc, 10, 247-mres[hover1], 20, 257-mres[hover1]);
	Rectangle(hgc, 10, 292-mres[hover1], 20, 302-mres[hover1]);
	Rectangle(hgc, 10, 344-mres[hover1], 20, 354-mres[hover1]);
	Rectangle(hgc, 10, 445-mres[hover1], 20, 455-mres[hover1]);
	Rectangle(hgc, 10, 533-mres[hover1], 20, 543-mres[hover1]);
	Rectangle(hgc, 10, 572-mres[hover1], 20, 582-mres[hover1]);
	Rectangle(hgc, 75, 572-mres[hover1], 85, 582-mres[hover1]);
	Rectangle(hgc, 135,572-mres[hover1], 145,582-mres[hover1]);
	Rectangle(hgc, 10, 702-mres[hover1], 20, 712-mres[hover1]);

	Rectangle(hgc, 10, 267-mres[hover1], wx-14, 282-mres[hover1]);
	Rectangle(hgc, 10, 314-mres[hover1], wx - 14, 329-mres[hover1]);
	Rectangle(hgc, 80, 405-mres[hover1], wx - 14, 422-mres[hover1]);
	Rectangle(hgc, 80, 425-mres[hover1], wx - 14, 442-mres[hover1]);
	Rectangle(hgc, 10, 465-mres[hover1], wx - 14, 480-mres[hover1]);
	Rectangle(hgc, 40, 485-mres[hover1], wx - 14, 500-mres[hover1]);
	Rectangle(hgc, 10, 550-mres[hover1], wx - 14, 565-mres[hover1]);
	Rectangle(hgc, 80, 510-mres[hover1], wx - 14, 527-mres[hover1]);
	
	Rectangle(hgc, 80, 660-mres[hover1], wx - 14, 677-mres[hover1]);
	Rectangle(hgc, 50, 680-mres[hover1], wx - 14, 697-mres[hover1]);
	Rectangle(hgc, 55, 740-mres[hover1], wx - 14, 757-mres[hover1]);

	Rectangle(hgc, 10, 610-mres[hover1], wx - 14, 627-mres[hover1]);
	Rectangle(hgc, 10, 720-mres[hover1], wx - 14, 737-mres[hover1]);
	MoveToEx(hgc, 1, 240-mres[hover1], NULL); LineTo(hgc, wx - 2, 240-mres[hover1]);
	MoveToEx(hgc, 1, 287-mres[hover1], NULL); LineTo(hgc, wx - 2, 287-mres[hover1]);
	MoveToEx(hgc, 1, 334-mres[hover1], NULL); LineTo(hgc, wx - 2, 334-mres[hover1]);
	MoveToEx(hgc, 1, 360 - mres[hover1], NULL); LineTo(hgc, wx - 2, 360 - mres[hover1]);
	MoveToEx(hgc, 1, 505 - mres[hover1], NULL); LineTo(hgc, wx - 2, 505 - mres[hover1]);
	MoveToEx(hgc, 1, 635 - mres[hover1], NULL); LineTo(hgc, wx - 2, 635 - mres[hover1]);
	MoveToEx(hgc, 1, 738 - mres[hover1], NULL); LineTo(hgc, wx - 2, 738 - mres[hover1]);
	DeleteObject(brush); 
	
	brush = CreateSolidBrush(RGB(200, 200, 200)); SelectObject(hgc, brush);
	if(matprop[mlik][manon].text==1){ Rectangle(hgc,12,249-mres[hover1],18,255-mres[hover1]); }
	if (matprop[mlik][manon].bum == 1) { Rectangle(hgc, 12, 294-mres[hover1], 18, 300-mres[hover1]); }
	if (matprop[mlik][manon].sm == 1) { Rectangle(hgc, 12, 447-mres[hover1], 18, 453-mres[hover1]); }
	if (matprop[mlik][manon].shade == 0) { Rectangle(hgc, 12, 346-mres[hover1], 18, 352-mres[hover1]); }
	if (matprop[mlik][manon].emK == 1) { Rectangle(hgc, 12, 535-mres[hover1], 18, 541-mres[hover1]); }
	if (matprop[mlik][manon].emt==1) { Rectangle(hgc, 12, 574-mres[hover1], 18, 580-mres[hover1]); }
	if (matprop[mlik][manon].emt==2) { Rectangle(hgc, 77, 574-mres[hover1], 83, 580-mres[hover1]); }
	if (matprop[mlik][manon].emt==3) { Rectangle(hgc, 137, 574-mres[hover1], 143, 580-mres[hover1]); }
	if (matprop[mlik][manon].rfk==1) { Rectangle(hgc, 12, 704-mres[hover1], 18, 710-mres[hover1]); }

	DeleteObject(hp);

	hf = CreateFont(15, 7, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
	SelectObject(hgc, hf);
	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);
	TextOut(hgc, 10, 155-mres[hover1], catname, strlen(catname));

	SetTextColor(hgc,RGB( 200, 200, 200));
	TextOut(hgc, 10, 180-mres[hover1], "Color", 5);
	TextOut(hgc, 10, 220-mres[hover1], "Alpha", 5);

	TextOut(hgc, 25, 245-mres[hover1], "Texture", 8); 
	TextOut(hgc, 25, 292-mres[hover1], "Bump", 5);
	TextOut(hgc, 25, 340-mres[hover1], "Shadeless", 10);
	TextOut(hgc, 10, 365-mres[hover1], "Specular", 9);
	TextOut(hgc, 10, 385-mres[hover1], "Color", 5);
	TextOut(hgc, 10, 405-mres[hover1], "Intensity", 10);
	TextOut(hgc, 10, 425-mres[hover1], "Brilliance", 11);
	TextOut(hgc, 25, 445-mres[hover1], "Specular Map", 13);
	TextOut(hgc, 10, 485-mres[hover1], "NSI",3);
	TextOut(hgc, 10, 510 - mres[hover1], "Emittance", 10);
	TextOut(hgc, 25, 530 - mres[hover1], "Emission Map", 13);
	TextOut(hgc, 25, 570 - mres[hover1], "None", 4);
	TextOut(hgc, 90, 570 - mres[hover1], "Color",5);
	TextOut(hgc, 150, 570 - mres[hover1], "Map", 3);
	TextOut(hgc, 10, 640 - mres[hover1], "Reflection", 11);
	TextOut(hgc, 10, 660 - mres[hover1], "Strength",9);
	TextOut(hgc, 10, 680 - mres[hover1], "RFI",3);
	TextOut(hgc, 25, 700 - mres[hover1], "Reflection Map",15);
	TextOut(hgc, 10, 740 - mres[hover1], "NormS",5);
	
	sprintf_s(how3, "%f", matprop[mlik][manon].Tr);
	SetTextColor(hgc, RGB(0, 0, 0));
	SetRect(&rc, 53, 220-mres[hover1], wx - 16, 235-mres[hover1]); DrawText(hgc, how3, -1, &rc, NULL);
	//specular
	sprintf_s(how3, "%f", matprop[mlik][manon].si);
	SetRect(&rc, 83, 405- mres[hover1], wx - 16, 420 - mres[hover1]); DrawText(hgc, how3, -1, &rc, NULL);
	sprintf_s(how3, "%f", matprop[mlik][manon].ss);
	SetRect(&rc, 83, 425 - mres[hover1], wx - 16, 440 - mres[hover1]); DrawText(hgc, how3, -1, &rc, NULL);
	//emit
	sprintf_s(how3, "%f", matprop[mlik][manon].emit);
	SetRect(&rc, 83, 511 - mres[hover1], wx - 16, 527 - mres[hover1]); DrawText(hgc, how3, -1, &rc, NULL);
	//NSI
	sprintf_s(how3, "%f", matprop[mlik][manon].NSI);
	SetRect(&rc,50,485-mres[hover1],wx-16,505-mres[hover1]); DrawText(hgc,how3,-1,&rc,NULL);
	//reflection
	sprintf_s(how3, "%f", matprop[mlik][manon].rfls);
	SetRect(&rc,82,660-mres[hover1],wx-16,680-mres[hover1]); DrawText(hgc,how3,-1,&rc,NULL);
	//refraction
	sprintf_s(how3, "%f", matprop[mlik][manon].rfi);
	SetRect(&rc,52,680-mres[hover1],wx-16,700-mres[hover1]); DrawText(hgc,how3,-1,&rc,NULL);
	//Normal Strength
	sprintf_s(how3, "%f", matprop[mlik][manon].NORS);
	SetRect(&rc,57,741-mres[hover1],wx-16,760-mres[hover1]); DrawText(hgc,how3,-1,&rc,NULL);
	
	//Emmission texture
	if (matprop[mlik][manon].emtmap>=0) {
		sprintf_s(how3, "");
		for (int a = 0, b = 0, c = 0;a < strlen(texturename[mlik]);a++) {
			if (b >= matprop[mlik][manon].emtmap) {
				for (0;a < strlen(texturename[mlik]);a++) { how3[c] = texturename[mlik][a]; c++; if (texturename[mlik][a + 1] == ';') { how3[c] = 0; break; } }
				break;
			}
			if (texturename[mlik][a] == ';') { b++; }
		}

		SetRect(&rc,13,610-mres[hover1], wx-16, 627-mres[hover1]); DrawText(hgc, how3, -1, &rc, NULL);
	}
	//reflection texture
	if (matprop[mlik][manon].rfk>=0) {
		sprintf_s(how3, "");
		for (int a = 0, b = 0, c = 0;a < strlen(texturename[mlik]);a++) {
			if (b >= matprop[mlik][manon].rfmap) {
				for (0;a < strlen(texturename[mlik]);a++) { how3[c] = texturename[mlik][a]; c++; if (texturename[mlik][a + 1] == ';') { how3[c] = 0; break; } }
				break;
			}
			if (texturename[mlik][a] == ';') { b++; }
		}

		SetRect(&rc,13,720-mres[hover1], wx-16, 740-mres[hover1]); DrawText(hgc, how3, -1, &rc, NULL);
	}

	//Emission
	if (matprop[mlik][manon].emK >= 0) {
		sprintf_s(how3, "");
		for (int a = 0, b = 0, c = 0;a < strlen(texturename[mlik]);a++) {
			if (b >= matprop[mlik][manon].emmap) {
				for (0;a < strlen(texturename[mlik]);a++) { how3[c] = texturename[mlik][a]; c++; if (texturename[mlik][a + 1] == ';') { how3[c] = 0; break; } }
				break;
			}
			if (texturename[mlik][a] == ';') { b++; }
		}

		SetRect(&rc, 13, 550 - mres[hover1], wx - 16, 565 - mres[hover1]); DrawText(hgc, how3, -1, &rc, NULL);
	}
	//specular
if(matprop[mlik][manon].sm>=0){
	sprintf_s(how3, "");
	for (int a = 0,b=0,c=0;a < strlen(texturename[mlik]);a++) {
		if (b >= matprop[mlik][manon].spemap) {
			for (0;a < strlen(texturename[mlik]);a++){ how3[c]=texturename[mlik][a]; c++; if(texturename[mlik][a+1]==';'){ how3[c]=0; break;} }
			break;
		}
		if (texturename[mlik][a] == ';'){ b++; }
	}
	
	SetRect(&rc, 13, 465-mres[hover1], wx - 16, 480-mres[hover1]); DrawText(hgc, how3, -1, &rc, NULL);
	}

	if(matprop[mlik][manon].text>=0){
	sprintf_s(how3, "");
	for (int a = 0,b=0,c=0;a < strlen(texturename[mlik]);a++) {
		if (b >= matprop[mlik][manon].tex) {
			for (0;a < strlen(texturename[mlik]);a++){ how3[c]=texturename[mlik][a]; c++; if(texturename[mlik][a+1]==';'){ how3[c]=0; break;} }
			break;
		}
		if (texturename[mlik][a] == ';'){ b++; }
	}
	SetRect(&rc, 13, 267-mres[hover1], wx - 16, 282-mres[hover1]); DrawText(hgc, how3, -1, &rc, NULL);
	}

	

if(matprop[mlik][manon].bum>=0){
sprintf_s(how3, "");
	for (int a = 0,b=0,c=0;a < strlen(texturename[mlik]);a++) {
		if (b >= matprop[mlik][manon].bump) {
			for (0;a < strlen(texturename[mlik]);a++){ how3[c]= texturename[mlik][a]; c++; if(texturename[mlik][a+1]==';'){ how3[c]=0; break;} }
			break;
		}
		if (texturename[mlik][a] == ';'){ b++; }
	}
	SetRect(&rc, 13, 314-mres[hover1], wx - 16, 329-mres[hover1]); DrawText(hgc, how3, -1, &rc, NULL);
	}
	DeleteObject(hf);

	shading();
	hbc = CreateCompatibleDC(hdc);
	hbm = CreateCompatibleBitmap(hdc, wx - 4, 150);
	SelectObject(hbc, hbm);
	SetBitmapBits(hbm, (wx - 4)*(150) * 4, &read);
	SetTextColor(hbc,RGB(255,255,255));
	SetBkMode(hbc,TRANSPARENT);
	hf=CreateFont(15,7,0,0,0,0,0,0,DEFAULT_CHARSET,0,0,0,DEFAULT_GUI_FONT,"ARIAL"); SelectObject(hbc,hf);
	TextOut(hbc,20,130,catname,strlen(catname));
	DeleteObject(hf);
	hp = CreatePen(PS_SOLID, 2, RGB(40, 40, 40)); SelectObject(hbc, hp);
	brush = CreateSolidBrush(RGB(80, 80, 80)); SelectObject(hbc, brush);
	Rectangle(hbc, 10, 10, 40, 105);
	DeleteObject(brush); DeleteObject(hp);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO48"); DrawIcon(hbc, 16, 15, hiu);  DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO49"); DrawIcon(hbc, 16, 32, hiu);  DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO50"); DrawIcon(hbc, 16, 49, hiu);  DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO51"); DrawIcon(hbc, 16, 66, hiu);  DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO52"); DrawIcon(hbc, 16, 83, hiu);  DeleteObject(hiu);

	BitBlt(hgc, 2, 20, wx - 4, 150, hbc, 0, 0, SRCCOPY);
	DeleteDC(hbc);
	DeleteObject(hbm);
	}
	else {
	hbc = CreateCompatibleDC(hdc);
	SelectObject(hbc, sefari);
	ou = 2; bu = 20;
	for (0;ou<wx - 2;ou += 997) {
		BitBlt(hgc, ou, bu, 997, 887, hbc, 0, 0, SRCCOPY);
	} bu += 997;
	for (0;bu<wy - 21;bu += 997) {
		BitBlt(hgc, ou, bu, 997, 887, hbc, 0, 0, SRCCOPY);
	}
	DeleteDC(hbc);

	hiu = LoadIcon(GetModuleHandle(NULL), "ICO47"); DrawIcon(hgc, wx/2-115, wy/2-15, hiu);  DeleteObject(hiu);
	hf = CreateFont(20, 9, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
	SelectObject(hgc, hf);
	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);
	TextOut(hgc, wx/2-80, wy/2-7, "No Active Material", 19);
	DeleteObject(hf);
	}
	bu=750-171;
	if(manon>=0){
	//scrollbar
	hp = CreatePen(PS_SOLID, 1, RGB(20, 20, 20)); SelectObject(hgc, hp);
	brush = CreateSolidBrush(RGB(80, 80, 80)); SelectObject(hgc, brush);
	thm1 = bu;
	thm2 = (wy - 3) - 171;
	if (thm2>thm1) { thm3 = thm2; }
	else { thm1 -= thm2; thm4 = thm1 / 20.0*2.0; thm3 = thm2 - thm4; }
	mrew[hover1] = thm3; if (thm3<20) { thm3 = 20; }
	if (mres[hover1]>0) { thm6 = mres[hover1]; thm6 = thm6 / 20.0*2.0; thm5 = 171 + thm6; }
	else { thm5 = 171; }
	RoundRect(hgc, wx - 12, thm5, wx - 2, thm5 + thm3, 7, 7);
	DeleteObject(brush); DeleteObject(hp);
	}
	//painting
	brush = CreateSolidBrush(RGB(20, 20, 20));
	SetRect(&rc, 0, 0, wx, 21);	FillRect(hgc, &rc, brush);
	SetRect(&rc, 0, 0, 2, wy);	FillRect(hgc, &rc, brush);
	SetRect(&rc, wx - 2, 0, wx, wy);	FillRect(hgc, &rc, brush);
	SetRect(&rc, 0, wy - 2, wx, wy);	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	SetRect(&rc, 0, 0, 20, 19);
	if (hover == hover1) { brush = CreateSolidBrush(RGB(100, 100, 200)); }
	else { brush = CreateSolidBrush(RGB(50, 50, 50)); }
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	hiu = LoadIcon(GetModuleHandle(NULL), "ICO46"); DrawIcon(hgc, 2, 1, hiu);  DeleteObject(hiu);

	hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
	SelectObject(hgc, hf);
	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);
	TextOut(hgc, 30, 3, "Material", 9);
	DeleteObject(hf);
	//end painting
	BitBlt(hdc, stx, sty, wx, wy, hgc, 0, 0, SRCCOPY);
	DeleteDC(hgc);
	DeleteObject(hgm);
	}
}

void title() {
	ou = 0;
	if (skew == 1 && gamon == 1) { ou = 1; }
	if (ou == 0) {
	hgc = CreateCompatibleDC(hdc);
	hgm = CreateCompatibleBitmap(hdc, wx, wy);
	SelectObject(hgc, hgm);

	SetRect(&rc, 0, 0, wx, wy);
	brush = CreateSolidBrush(RGB(20, 20, 20));
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	SetRect(&rc, 2, 20, wx - 2, wy - 2);
	brush = CreateSolidBrush(RGB(50, 50, 50));
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	SetRect(&rc, 0, 0, 20, 19);
	if (hover == hover1) { brush = CreateSolidBrush(RGB(100, 100, 200)); }
	else { brush = CreateSolidBrush(RGB(50, 50, 50)); }
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	hiu = LoadIcon(GetModuleHandle(NULL), "ICO53");
	DrawIcon(hgc, 2, 1, hiu);  DeleteObject(hiu);

	hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
	SelectObject(hgc, hf);
	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);
	TextOut(hgc, 30, 3, "Project", 8);
	if(peep==1){
	ou=50;
	for (int a = 0,b=0;a < strlen(script);a++) {
		how[b] = script[a]; b++;
		if (script[a + 1] == ';') {
			how[b] = 0; b = 0;
		TextOut(hgc,32,ou,how,strlen(how));
		ou += 15;
		a++; }
	}
	}
	DeleteObject(hf);

	if(peep==0){ hiu = LoadIcon(GetModuleHandle(NULL), "ICO33");	DrawIcon(hgc, 5, 31, hiu);  DeleteObject(hiu); }
	else{ hiu = LoadIcon(GetModuleHandle(NULL), "ICO34");	DrawIcon(hgc, 5, 31, hiu);  DeleteObject(hiu); }

	hf = CreateFont(15, 7, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
	SelectObject(hgc, hf);
	SetTextColor(hgc, RGB(100, 255, 100));
	SetBkMode(hgc, TRANSPARENT);
	TextOut(hgc, 20, 30, projname, strlen(projname));

	DeleteObject(hf);

	BitBlt(hdc, stx, sty, wx, wy, hgc, 0, 0, SRCCOPY);
	DeleteDC(hgc);
	DeleteObject(hgm);
	}
}

void gloss() {
	ou = 0;
	if (skew == 1 && gamon == 1) { ou = 1; }
	if (ou == 0) {
	hgc = CreateCompatibleDC(hdc);
	hgm = CreateCompatibleBitmap(hdc, wx, wy);
	SelectObject(hgc, hgm);

	SetRect(&rc, 0, 0, wx, wy);
	brush = CreateSolidBrush(RGB(20, 20, 20));
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	SetRect(&rc, 2, 20, wx - 2, wy - 2);
	brush = CreateSolidBrush(RGB(50, 50, 50));
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	SetRect(&rc, 0, 0, 20, 19);
	if (hover == hover1) { brush = CreateSolidBrush(RGB(100, 100, 200)); }
	else { brush = CreateSolidBrush(RGB(50, 50, 50)); }
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	hiu = LoadIcon(GetModuleHandle(NULL), "ICO26");
	DrawIcon(hgc, 2, 1, hiu);  DeleteObject(hiu);

	hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
	SelectObject(hgc, hf);
	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);
	TextOut(hgc, 30, 3, "Glossary", 11);

	DeleteObject(hf);

	BitBlt(hdc, stx, sty, wx, wy, hgc, 0, 0, SRCCOPY);
	DeleteDC(hgc);
	DeleteObject(hgm);
	}
}

void explore() {
	ou = 0;
	if (skew == 1 && gamon == 1) { ou = 1; }
	if (ou == 0) {
	hgc = CreateCompatibleDC(hdc);
	hgm = CreateCompatibleBitmap(hdc, wx, wy);
	SelectObject(hgc, hgm);

	SetRect(&rc, 2, 20, wx - 2, wy - 2);
	brush = CreateSolidBrush(RGB(50, 50, 50));
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
	SelectObject(hgc, hf);
	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);

	fr1 = 10; fr2 = eres[hover1]; selet[hover1] = -1;
	for (int a = 0,b=0,c=-1;a < strlen(content);a ++) {
		how[b] = content[a]; b++;
		if (content[a + 1] == ';') {
			c++;

			if (mpo1 - stx>fr1-1&&mpo1-stx<fr1+72&&mpo2-sty>fr2-1&&mpo2-sty<fr2+50&&fr2 < wy) {
				SetRect(&rc, fr1 - 1, fr2 - 1, fr1 + 72, fr2 + 50);
				brush = CreateSolidBrush(RGB(100, 100, 200));
				FillRect(hgc, &rc, brush);
				DeleteObject(brush); selet[hover1] = c+1;
			}
			how[b] = 0;  
		if (fr2 < wy ) {
		DrawIcon(hgc, fr1+20, fr2, icontent[c]);
		SetRect(&rc, fr1, fr2+32, fr1 + 70, fr2 + 60); DrawText(hgc, how, -1, &rc, DT_CENTER );
		}
		if (fr1 > selet1 - 72) { selet1 = fr1 + 72; } selet2 = fr2+70;
		if (fr2 + sty > csize2 - 25) { selet2 = wy - 20; }
		fr1 += 75; b = 0; 
		for (0;a < strlen(content);a++) { if (content[a] == '\n'|| content[a] == '\r') { break; } }
		if (fr1 >= wx - 70) { fr1 = 10; fr2 += 70; }
		}
	}
	bu=fr2+75;
	//scrollbar
	hp = CreatePen(PS_SOLID, 1, RGB(20, 20, 20)); SelectObject(hgc, hp);
	brush = CreateSolidBrush(RGB(80, 80, 80)); SelectObject(hgc, brush);
	thm1 = bu - eres[hover1];
	thm2 = (wy - 3) - 21;
	if (thm2>thm1) { thm3 = thm2; }
	else { thm1 -= thm2; thm4 = thm1 / 20.0*2.0; thm3 = thm2 - thm4; }
	erew[hover1] = thm3; if (thm3<20) { thm3 = 20; }
	if (eres[hover1]<30) { thm6 = 30 - eres[hover1]; thm6 = thm6 / 20.0*2.0; thm5 = 21 + thm6; }
	else { thm5 = 21; }
	RoundRect(hgc, wx - 12, thm5, wx - 2, thm5 + thm3, 7, 7);
	DeleteObject(brush); DeleteObject(hp);

	//painting
	brush = CreateSolidBrush(RGB(20, 20, 20));
	SetRect(&rc, 0, 0, wx, 21);	FillRect(hgc, &rc, brush);
	SetRect(&rc, 0, 0, 2, wy);	FillRect(hgc, &rc, brush);
	SetRect(&rc, wx - 2, 0, wx, wy);	FillRect(hgc, &rc, brush);
	SetRect(&rc, 0, wy - 2, wx, wy);	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	SetRect(&rc, 0, 0, 20, 19);
	if (hover == hover1) { brush = CreateSolidBrush(RGB(100, 100, 200)); }
	else { brush = CreateSolidBrush(RGB(50, 50, 50)); }
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	hiu = LoadIcon(GetModuleHandle(NULL), "ICO11"); DrawIcon(hgc, 2, 1, hiu);  DeleteObject(hiu);

	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);
	TextOut(hgc, 30, 3, "Asteroid explorer", 18);
	DeleteObject(hf);
	//end painting

	BitBlt(hdc, stx, sty, wx, wy, hgc, 0, 0, SRCCOPY);
	DeleteDC(hgc);
	DeleteObject(hgm);
	}
}

void FOCUS(HWND hwnd) {
	sprintf_s(how, "%s\\scripts\\*", ppath);
	hhh = FindFirstFile(how, &wff);
	FindNextFile(hhh, &wff); int a = 0; sprintf_s(content, "");
	while (FindNextFile(hhh, &wff) != 0) {
		sprintf_s(how, "%s", wff.cFileName);
		bu = strlen(how);
		if(how[bu-1]=='t'&&how[bu -2] == 'p'&&how[bu - 3] == 'i'&&how[bu - 4] == 'r'&&how[bu - 5] == 'c'&&how[bu - 6] == 's'&&how[bu - 7] == 'a'&&how[bu - 8] == '.'){
		sprintf_s(content, "%s%s;", content, how);
		}
	}
	FindClose(hhh);
	bu = strlen(content);
	script = (char*)malloc(sizeof(char*)*(bu + 3));
	sprintf(script, "%s", content);

	sprintf_s(how, "%s\\*", path);
	hhh = FindFirstFile(how, &wff);
	FindNextFile(hhh, &wff); a = 0; sprintf_s(content, "");
	if (deep > 0) { a = 1; sprintf_s(content, "Back;test\n");
	sprintf_s(cantent[0], "back..");
	icontent[0] = LoadIcon(GetModuleHandle(NULL),"ICO28");
	}
	while (FindNextFile(hhh, &wff) != 0) {
		sprintf_s(how, "%s", wff.cFileName);
		sprintf_s(stantent[a], "%s", wff.cFileName);
		sprintf_s(content, "%s %s;%s\\%s\n", content, how, path, how);
		sprintf_s(how, "%s\\%s", path, wff.cFileName);
		SHGetFileInfo(how, attrib, &shft, sizeof(shft), SHGFI_ICON | SHGFI_TYPENAME);
		sprintf_s(cantent[a],"%s",shft.szTypeName);
		if (cantent[a][0]=='O'&&cantent[a][1]=='B'&&cantent[a][2]=='J'&&cantent[a][3]==' ') { icontent[a]=LoadIcon(GetModuleHandle(NULL),"ICO65"); }
		else{ icontent[a] = shft.hIcon; }
		a++;
	}
	FindClose(hhh);
	
}

void MESAGE(char *title, char *text) {
	mu = 0; bu = 0;
	for (ou = 0;ou < strlen(text);ou++) {
		mu += 7; if (mu > bu) { bu = mu; } if (text[ou] == '\n') { mu = 0; }
	}
	if (bu < 100) { ou = 106; }
	else { ou = bu+6; }
	hgc = CreateCompatibleDC(hdc);
	hgm = CreateCompatibleBitmap(hdc, ou+10, 50);
	SelectObject(hgc, hgm);
	
	SetRect(&rc, 1, 1, ou-1, 49);
	brush = CreateSolidBrush(RGB(20, 20, 20));
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	hf = CreateFont(15, 7, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
	SelectObject(hgc, hf);
	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);
	TextOut(hgc, 3, 10, text, strlen(text));
	DeleteObject(hf);

	BitBlt(hdc, mesp1, mesp2, ou, 50, hgc, 0, 0, SRCCOPY);
	DeleteDC(hgc);
	DeleteObject(hgm);
}

void layot() {
	hgc = CreateCompatibleDC(hdc);
	hgm = CreateCompatibleBitmap(hdc, 120, 275);
	SelectObject(hgc, hgm);

	SetRect(&rc, 1, 1, 120, 275);
	brush = CreateSolidBrush(RGB(20, 20, 20));
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	if (mpo1 > csize - 120 && mpo1 < csize&&mpo2>50 && mpo2 < 325) {
		brush = CreateSolidBrush(RGB(100, 100, 200)); menu2 = 0;
		if (mpo2 > 8 + 50 && mpo2 < 50 + 29) { SetRect(&rc, 1, 8, 120, 29); FillRect(hgc, &rc, brush); menu2 = 1; }
		if (mpo2 > 28 + 50 && mpo2 < 50 + 49) { SetRect(&rc, 1, 28, 120, 49); FillRect(hgc, &rc, brush); menu2 = 2; }
		if (mpo2 > 48 + 50 && mpo2 < 50 + 69) { SetRect(&rc, 1, 48, 120, 69); FillRect(hgc, &rc, brush); menu2 = 3; }
		if (mpo2 > 68 + 50 && mpo2 < 50 + 89) { SetRect(&rc, 1, 68, 120, 89); FillRect(hgc, &rc, brush); menu2 = 4; }
		if (mpo2 > 88 + 50 && mpo2 < 50 + 109) { SetRect(&rc, 1, 88, 120, 109); FillRect(hgc, &rc, brush); menu2 = 5; }
		if (mpo2 > 108 + 50 && mpo2 < 50 + 129) { SetRect(&rc, 1, 108, 120, 129); FillRect(hgc, &rc, brush); menu2 = 6; }
		if (mpo2 > 128 + 50 && mpo2 < 50 + 149) { SetRect(&rc, 1, 128, 120, 149); FillRect(hgc, &rc, brush); menu2 = 7; }
		if (mpo2 > 148 + 50 && mpo2 < 50 + 169) { SetRect(&rc, 1, 148, 120, 169); FillRect(hgc, &rc, brush); menu2 = 8; }
		if (mpo2 > 168 + 50 && mpo2 < 50 + 189) { SetRect(&rc, 1, 168, 120, 189); FillRect(hgc, &rc, brush); menu2 = 9; }
		if (mpo2 > 188 + 50 && mpo2 < 50 + 209) { SetRect(&rc, 1, 188, 120, 209); FillRect(hgc, &rc, brush); menu2 = 10; }
		if (mpo2 > 208 + 50 && mpo2 < 50 + 229) { SetRect(&rc, 1, 208, 120, 229); FillRect(hgc, &rc, brush); menu2 = 11; }
		if (mpo2 > 228 + 50 && mpo2 < 50 + 249) { SetRect(&rc, 1, 228, 120, 249); FillRect(hgc, &rc, brush); menu2 = 12; }
		if (mpo2 > 248 + 50 && mpo2 < 50 + 269) { SetRect(&rc, 1, 248, 120, 269); FillRect(hgc, &rc, brush); menu2 = 13; }
		
		DeleteObject(brush);
	}

	hiu = LoadIcon(GetModuleHandle(NULL), "ICO13");
	DrawIcon(hgc, 10, 10, hiu);  DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO14");
	DrawIcon(hgc, 10, 30, hiu);  DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO15");
	DrawIcon(hgc, 10, 50, hiu);  DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO16");
	DrawIcon(hgc, 10, 70, hiu);  DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO17");
	DrawIcon(hgc, 10, 90, hiu);  DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO18");
	DrawIcon(hgc, 10, 110, hiu);  DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO19");
	DrawIcon(hgc, 10, 130, hiu);  DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO20");
	DrawIcon(hgc, 10, 150, hiu);  DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO21");
	DrawIcon(hgc, 10, 170, hiu);  DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO22");
	DrawIcon(hgc, 10, 190, hiu);  DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO23");
	DrawIcon(hgc, 10, 210, hiu);  DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO24");
	DrawIcon(hgc, 10, 230, hiu);  DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO25");
	DrawIcon(hgc, 10, 250, hiu);  DeleteObject(hiu);

	hf = CreateFont(15, 7, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
	SelectObject(hgc, hf);
	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);
	TextOut(hgc, 40, 10, "Layout 1", 9);
	TextOut(hgc, 40, 30, "Layout 2", 9);
	TextOut(hgc, 40, 50, "Layout 3", 9);
	TextOut(hgc, 40, 70, "Layout 4", 9);
	TextOut(hgc, 40, 90, "Layout 5", 9);
	TextOut(hgc, 40, 110, "Layout 6", 9);
	TextOut(hgc, 40, 130, "Layout 7", 9);
	TextOut(hgc, 40, 150, "Layout 8", 9);
	TextOut(hgc, 40, 170, "Layout 9", 9);
	TextOut(hgc, 40, 190, "Layout 10", 10);
	TextOut(hgc, 40, 210, "Layout 11", 10);
	TextOut(hgc, 40, 230, "Layout 12", 10);
	TextOut(hgc, 40, 250, "Layout 13", 10);
	DeleteObject(hf);

	BitBlt(hdc, csize-120, 50, 120, 275, hgc, 0, 0, SRCCOPY);
	DeleteDC(hgc);
	DeleteObject(hgm);
}

void arrange() {
	if (layout == 1) {
		hover1 = 0;
		stx = 0; sty = 52; wx = wx1*csize; wy = wy1* (csize2 - 76); 
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn1 == 1) { view(); } if (scrn1 == 2) { pilot(); }if (scrn1 == 3) { propet(); }if (scrn1 == 4) { gloss(); }if (scrn1 == 5) { explore(); } if (scrn1 == 6) { telescope(); } if(scrn1==7){ material(); } if (scrn1 == 8) { title(); }
		hover1++;
		stx = stx + wx;  wx = wx2*csize;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn2 == 1) { view(); } if (scrn2 == 2) { pilot(); }if (scrn2 == 3) { propet(); }if (scrn2 == 4) { gloss(); }if (scrn2 == 5) { explore(); } if (scrn2 == 6) { telescope(); } if (scrn2 == 7) { material(); }  if (scrn2 == 8) { title(); }
		hover1++;
		stx = stx + wx;  wx = csize - stx;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn3 == 1) { view(); } if (scrn3 == 2) { pilot(); }if (scrn3 == 3) { propet(); }if (scrn3 == 4) { gloss(); }if (scrn3 == 5) { explore(); }  if (scrn3 == 6) { telescope(); } if(scrn3==7){ material(); } if (scrn3 == 8) { title(); }
		hover1++;
		wx = 0; sty += wy; wy = (csize2 - 25) - sty;
		stx = 0;  wx = wx3*csize;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn4 == 1) { view(); } if (scrn4 == 2) { pilot(); }if (scrn4 == 3) { propet(); }if (scrn4 == 4) { gloss(); }if (scrn4 == 5) { explore(); } if (scrn4 == 6) { telescope(); } if (scrn4 == 7) { material(); }  if (scrn4 == 8) { title(); }
		stx += wx;  wx = (csize - stx);
		hover1++;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn5 == 1) { view(); } if (scrn5 == 2) { pilot(); }if (scrn5 == 3) { propet(); }if (scrn5 == 4) { gloss(); }if (scrn5 == 5) { explore(); } if (scrn5 == 6) { telescope(); } if (scrn5 == 7) { material(); }  if (scrn5 == 8) { title(); }
	}
	if (layout == 2) {
		hover1 = 0;
		stx = 0; sty = 52; wx = wx1*csize; wy = wy1* (csize2 - 76);
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn1 == 1) { view(); } if (scrn1 == 2) { pilot(); }if (scrn1 == 3) { propet(); }if (scrn1 == 4) { gloss(); }if (scrn1 == 5) { explore(); } if (scrn1 == 6) { telescope(); } if (scrn1 == 7) { material(); }  if (scrn1 == 8) { title(); }
		hover1++;
		stx = stx + wx;  wx = wx2*csize;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn2 == 1) { view(); } if (scrn2 == 2) { pilot(); }if (scrn2 == 3) { propet(); }if (scrn2 == 4) { gloss(); }if (scrn2 == 5) { explore(); } if (scrn2 == 6) { telescope(); } if (scrn2 == 7) { material(); }  if (scrn2 == 8) { title(); }
		hover1++;
		stx = stx + wx;  wx = csize - stx;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn3 == 1) { view(); } if (scrn3 == 2) { pilot(); }if (scrn3 == 3) { propet(); }if (scrn3 == 4) { gloss(); }if (scrn3 == 5) { explore(); } if (scrn3 == 6) { telescope(); } if (scrn3 == 7) { material(); }  if (scrn3 == 8) { title(); }
		hover1++;
		wx = 0; sty += wy; wy = (csize2 - 25) - sty;
		stx = 0;   wx = wx3*csize;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn4 == 1) { view(); } if (scrn4 == 2) { pilot(); }if (scrn4 == 3) { propet(); }if (scrn4 == 4) { gloss(); }if (scrn4 == 5) { explore(); } if (scrn4 == 6) { telescope(); } if (scrn4 == 7) { material(); } if (scrn4 == 8) { title(); }
		stx = stx + wx;  wx = wx4*csize;
		hover1++;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn5 == 1) { view(); } if (scrn5 == 2) { pilot(); }if (scrn5 == 3) { propet(); }if (scrn5 == 4) { gloss(); }if (scrn5 == 5) { explore(); } if (scrn5 == 6) { telescope(); } if (scrn5 == 7) { material(); } if (scrn5 == 8) { title(); }
		stx += wx;  wx = (csize - stx);
		hover1++;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn6 == 1) { view(); } if (scrn6 == 2) { pilot(); }if (scrn6 == 3) { propet(); }if (scrn6 == 4) { gloss(); }if (scrn6 == 5) { explore(); } if (scrn6 == 6) { telescope(); } if (scrn6 == 7) { material(); } if (scrn6 == 8) { title(); }
	}
	if (layout == 3) {
		hover1 = 0;
		stx = 0; sty = 52; wx = csize; wy = wy1* (csize2 - 76);
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn1 == 1) { view(); } if (scrn1 == 2) { pilot(); }if (scrn1 == 3) { propet(); }if (scrn1 == 4) { gloss(); }if (scrn1 == 5) { explore(); } if (scrn1 == 6) { telescope(); } if (scrn1 == 7) { material(); } if (scrn1 == 8) { title(); }
		sty += wy; wy = (csize2 - 25 )- sty ;
		hover1++;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn2 == 1) { view(); } if (scrn2 == 2) { pilot(); }if (scrn2 == 3) { propet(); }if (scrn2 == 4) { gloss(); }if (scrn2 == 5) { explore(); } if (scrn2 == 6) { telescope(); } if (scrn2 == 7) { material(); } if (scrn2 == 8) { title(); }
			}
	if (layout == 4) {
		hover1 = 0;
		stx = 0; sty = 52; wx = wx1*csize; wy = (csize2 - 25) - sty;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn1 == 1) { view(); } if (scrn1 == 2) { pilot(); }if (scrn1 == 3) { propet(); }if (scrn1 == 4) { gloss(); }if (scrn1 == 5) { explore(); } if (scrn1 == 6) { telescope(); } if (scrn1 == 7) { material(); } if (scrn1 == 8) { title(); }
		hover1++;
		stx += wx; wx = csize - wx;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn2 == 1) { view(); } if (scrn2 == 2) { pilot(); }if (scrn2 == 3) { propet(); }if (scrn2 == 4) { gloss(); }if (scrn2 == 5) { explore(); } if (scrn2 == 6) { telescope(); } if (scrn2 == 7) { material(); } if (scrn2 == 8) { title(); }
	}
	if (layout == 5) {
		hover1 = 0;
		stx = 0; sty = 52; wx = wx1*csize; wy = wy1*(csize2 - 76);
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn1 == 1) { view(); } if (scrn1 == 2) { pilot(); }if (scrn1 == 3) { propet(); }if (scrn1 == 4) { gloss(); }if (scrn1 == 5) { explore(); } if (scrn1 == 6) { telescope(); } if (scrn1 == 7) { material(); } if (scrn1 == 8) { title(); }
		stx += wx; wx = csize - wx; 
		hover1++;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn2 == 1) { view(); } if (scrn2 == 2) { pilot(); }if (scrn2 == 3) { propet(); }if (scrn2 == 4) { gloss(); }if (scrn2 == 5) { explore(); } if (scrn2 == 6) { telescope(); } if (scrn2 == 7) { material(); } if (scrn2 == 8) { title(); }
		hover1++;
		stx = 0;  wx = csize; sty += wy; wy = (csize2 - 25) - sty;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn3 == 1) { view(); } if (scrn3 == 2) { pilot(); }if (scrn3 == 3) { propet(); }if (scrn3 == 4) { gloss(); }if (scrn3 == 5) { explore(); } if (scrn3 == 6) { telescope(); } if (scrn3 == 7) { material(); } if (scrn3 == 8) { title(); }

	}
	if (layout == 6) {
		hover1 = 0;
		stx = 0; sty = 52; wx = wx1*csize; wy = (csize2-25)-sty;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn1 == 1) { view(); } if (scrn1 == 2) { pilot(); }if (scrn1 == 3) { propet(); }if (scrn1 == 4) { gloss(); }if (scrn1 == 5) { explore(); } if (scrn1 == 6) { telescope(); } if (scrn1 == 7) { material(); } if (scrn1 == 8) { title(); }
		hover1++;
		stx += wx; wx = csize - wx; wy = wy1*(csize2 - 76);
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn2 == 1) { view(); } if (scrn2 == 2) { pilot(); }if (scrn2 == 3) { propet(); }if (scrn2 == 4) { gloss(); }if (scrn2 == 5) { explore(); } if (scrn2 == 6) { telescope(); } if (scrn2 == 7) { material(); } if (scrn2 == 8) { title(); }
		hover1++;
		sty += wy; wy = (csize2 - 25) - sty;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn3 == 1) { view(); } if (scrn3 == 2) { pilot(); }if (scrn3 == 3) { propet(); }if (scrn3 == 4) { gloss(); }if (scrn3 == 5) { explore(); } if (scrn3 == 6) { telescope(); } if (scrn3 == 7) { material(); } if (scrn3 == 8) { title(); }

	}
	if (layout == 7) {
		hover1 = 0;
		stx = 0; sty = 52; wx = wx1*csize; wy = wy1*(csize2 - 76);
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn1 == 1) { view(); } if (scrn1 == 2) { pilot(); }if (scrn1 == 3) { propet(); }if (scrn1 == 4) { gloss(); }if (scrn1 == 5) { explore(); } if (scrn1 == 6) { telescope(); } if (scrn1 == 7) { material(); } if (scrn1 == 8) { title(); }
		sty += wy;  wy = (csize2 - 25) - sty;
		hover1++;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn2 == 1) { view(); } if (scrn2 == 2) { pilot(); }if (scrn2 == 3) { propet(); }if (scrn2 == 4) { gloss(); }if (scrn2 == 5) { explore(); } if (scrn2 == 6) { telescope(); } if (scrn2 == 7) { material(); } if (scrn2 == 8) { title(); }
		hover1++;
		stx += wx; wx = csize - stx; sty = 52; wy = (csize2 - 25) - sty;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn3 == 1) { view(); } if (scrn3 == 2) { pilot(); }if (scrn3 == 3) { propet(); }if (scrn3 == 4) { gloss(); }if (scrn3 == 5) { explore(); } if (scrn3 == 6) { telescope(); } if (scrn3 == 7) { material(); } if (scrn3 == 8) { title(); }

	}
	if (layout == 9) {
		hover1 = 0;
		stx = 0; sty = 52; wx = csize; wy = wy1*(csize2 - 76);
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn1 == 1) { view(); } if (scrn1 == 2) { pilot(); }if (scrn1 == 3) { propet(); }if (scrn1 == 4) { gloss(); }if (scrn1 == 5) { explore(); } if (scrn1 == 6) { telescope(); } if (scrn1 == 7) { material(); } if (scrn1 == 8) { title(); }
		hover1++;
		sty += wy; wx = wx1*csize; wy = (csize2 - 25) - sty;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn2 == 1) { view(); } if (scrn2 == 2) { pilot(); }if (scrn2 == 3) { propet(); }if (scrn2 == 4) { gloss(); }if (scrn2 == 5) { explore(); } if (scrn2 == 6) { telescope(); } if (scrn2 == 7) { material(); } if (scrn2 == 8) { title(); }
		hover1++;
		stx += wx; wx = csize - stx;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn3 == 1) { view(); } if (scrn3 == 2) { pilot(); }if (scrn3 == 3) { propet(); }if (scrn3 == 4) { gloss(); }if (scrn3 == 5) { explore(); } if (scrn3 == 6) { telescope(); } if (scrn3 == 7) { material(); } if (scrn3 == 8) { title(); }

	}
	if (layout == 8) {
		hover1 = 0;
		stx = 0; sty = 52; wx = wx1*csize; wy = (csize2 - 25) - sty;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn1 == 1) { view(); } if (scrn1 == 2) { pilot(); }if (scrn1 == 3) { propet(); }if (scrn1 == 4) { gloss(); }if (scrn1 == 5) { explore(); } if (scrn1 == 6) { telescope(); } if (scrn1 == 7) { material(); } if (scrn1 == 8) { title(); }
		hover1++;
		stx += wx; wx = csize - wx; wy = wy1*(csize2 - 76);
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn2 == 1) { view(); } if (scrn2 == 2) { pilot(); }if (scrn2 == 3) { propet(); }if (scrn2 == 4) { gloss(); }if (scrn2 == 5) { explore(); } if (scrn2 == 6) { telescope(); } if (scrn2 == 7) { material(); } if (scrn2 == 8) { title(); }
		hover1++;
		sty += wy; wy = wy2*(csize2 - 76);
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn3 == 1) { view(); } if (scrn3 == 2) { pilot(); }if (scrn3 == 3) { propet(); }if (scrn3 == 4) { gloss(); }if (scrn3 == 5) { explore(); } if (scrn3 == 6) { telescope(); } if (scrn3 == 7) { material(); } if (scrn3 == 8) { title(); }
		hover1++;
		sty += wy; wy = (csize2 - 25) - sty;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn4 == 1) { view(); } if (scrn4 == 2) { pilot(); }if (scrn4 == 3) { propet(); }if (scrn4 == 4) { gloss(); }if (scrn4 == 5) { explore(); } if (scrn4 == 6) { telescope(); } if (scrn4 == 7) { material(); } if (scrn4 == 8) { title(); }

	}
	if (layout == 10) {
		hover1 = 0;
		stx = 0; sty = 52; wx = wx1*csize;  wy = wy1*(csize2 - 76);
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn2 == 1) { view(); } if (scrn2 == 2) { pilot(); }if (scrn2 == 3) { propet(); }if (scrn2 == 4) { gloss(); }if (scrn2 == 5) { explore(); } if (scrn2 == 6) { telescope(); } if (scrn2 == 7) { material(); } if (scrn2 == 8) { title(); }
		hover1++;
		sty += wy; wy = wy2*(csize2 - 76);
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn3 == 1) { view(); } if (scrn3 == 2) { pilot(); }if (scrn3 == 3) { propet(); }if (scrn3 == 4) { gloss(); }if (scrn3 == 5) { explore(); } if (scrn3 == 6) { telescope(); } if (scrn3 == 7) { material(); } if (scrn3 == 8) { title(); }
		hover1++;
		sty += wy; wy = (csize2 - 25) - sty;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn4 == 1) { view(); } if (scrn4 == 2) { pilot(); }if (scrn4 == 3) { propet(); }if (scrn4 == 4) { gloss(); }if (scrn4 == 5) { explore(); } if (scrn4 == 6) { telescope(); } if (scrn4 == 7) { material(); } if (scrn4 == 8) { title(); }
		hover1++;
		stx +=wx ; sty = 52;  wx = csize - wx; wy = (csize2 - 25) - sty;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn1 == 1) { view(); } if (scrn1 == 2) { pilot(); }if (scrn1 == 3) { propet(); }if (scrn1 == 4) { gloss(); }if (scrn1 == 5) { explore(); } if (scrn1 == 6) { telescope(); } if (scrn1 == 7) { material(); } if (scrn1 == 8) { title(); }
	}
	if (layout == 11) {
		hover1 = 0;
		stx = 0; sty = 52; wx = wx1*csize; wy = wy1* (csize2 - 76);
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn1 == 1) { view(); } if (scrn1 == 2) { pilot(); }if (scrn1 == 3) { propet(); }if (scrn1 == 4) { gloss(); }if (scrn1 == 5) { explore(); } if (scrn1 == 6) { telescope(); } if (scrn1 == 7) { material(); } if (scrn1 == 8) { title(); }
		hover1++;
		stx = stx + wx;  wx = wx2*csize;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn2 == 1) { view(); } if (scrn2 == 2) { pilot(); }if (scrn2 == 3) { propet(); }if (scrn2 == 4) { gloss(); }if (scrn2 == 5) { explore(); } if (scrn2 == 6) { telescope(); } if (scrn2 == 7) { material(); } if (scrn2 == 8) { title(); }
		hover1++;
		stx = stx + wx;  wx = csize - stx;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn3 == 1) { view(); } if (scrn3 == 2) { pilot(); }if (scrn3 == 3) { propet(); }if (scrn3 == 4) { gloss(); }if (scrn3 == 5) { explore(); } if (scrn3 == 6) { telescope(); } if (scrn3 == 7) { material(); } if (scrn3 == 8) { title(); }
		hover1++;
		wx = 0; sty += wy; wy = (csize2 - 25) - sty;
		stx = 0;  wx = (csize - stx);
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn4 == 1) { view(); } if (scrn4 == 2) { pilot(); }if (scrn4 == 3) { propet(); }if (scrn4 == 4) { gloss(); }if (scrn4 == 5) { explore(); } if (scrn4 == 6) { telescope(); } if (scrn4 == 7) { material(); } if (scrn4 == 8) { title(); }
		}
	if (layout == 12) {
		hover1 = 0;
		stx = 0; sty = 52;  wy = wy1* (csize2 - 76);
		 wx = (csize - stx);
		 winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		 if (scrn4 == 1) { view(); } if (scrn4 == 2) { pilot(); }if (scrn4 == 3) { propet(); }if (scrn4 == 4) { gloss(); }if (scrn4 == 5) { explore(); } if (scrn4 == 6) { telescope(); } if (scrn4 == 7) { material(); } if (scrn4 == 8) { title(); }
		hover1++;
		stx = 0; sty +=wy ; wx = wx1*csize; wy =(csize2 - 25)-sty;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn1 == 1) { view(); } if (scrn1 == 2) { pilot(); }if (scrn1 == 3) { propet(); }if (scrn1 == 4) { gloss(); }if (scrn1 == 5) { explore(); } if (scrn1 == 6) { telescope(); } if (scrn1 == 7) { material(); } if (scrn1 == 8) { title(); }
		hover1++;
		stx = stx + wx;  wx = wx2*csize;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn2 == 1) { view(); } if (scrn2 == 2) { pilot(); }if (scrn2 == 3) { propet(); }if (scrn2 == 4) { gloss(); }if (scrn2 == 5) { explore(); } if (scrn2 == 6) { telescope(); } if (scrn2 == 7) { material(); } if (scrn2 == 8) { title(); }
		hover1++;
		stx = stx + wx;  wx = csize - stx;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn3 == 1) { view(); } if (scrn3 == 2) { pilot(); }if (scrn3 == 3) { propet(); }if (scrn3 == 4) { gloss(); }if (scrn3 == 5) { explore(); } if (scrn3 == 6) { telescope(); } if (scrn3 == 7) { material(); } if (scrn3 == 8) { title(); }

		}
	if (layout == 13) {
		hover1 = 0;
		stx = 0; sty = 52;  wx = wx1*csize; wy = (csize2 - 76) *wy1;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn1 == 1) { view(); } if (scrn1 == 2) { pilot(); }if (scrn1 == 3) { propet(); }if (scrn1 == 4) { gloss(); }if (scrn1 == 5) { explore(); } if (scrn1 == 6) { telescope(); } if (scrn1 == 7) { material(); } if (scrn1 == 8) { title(); }
		hover1++;
		stx = stx + wx;   wx = csize - stx;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn2 == 1) { view(); } if (scrn2 == 2) { pilot(); }if (scrn2 == 3) { propet(); }if (scrn2 == 4) { gloss(); }if (scrn2 == 5) { explore(); } if (scrn2 == 6) { telescope(); } if (scrn2 == 7) { material(); } if (scrn2 == 8) { title(); }
		hover1++;
		stx = 0; sty += wy;  wx = csize*wx2; wy = (csize2 - 25) - sty;
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn3 == 1) { view(); } if (scrn3 == 2) { pilot(); }if (scrn3 == 3) { propet(); }if (scrn3 == 4) { gloss(); }if (scrn3 == 5) { explore(); } if (scrn3 == 6) { telescope(); } if (scrn3 == 7) { material(); } if (scrn3 == 8) { title(); }
		hover1++;
		stx += wx;  wx = csize-stx; 
		winx[hover1] = stx; winy[hover1] = sty; winwx[hover1] = wx; winwy[hover1] = wy;
		if (scrn4 == 1) { view(); } if (scrn4 == 2) { pilot(); }if (scrn4 == 3) { propet(); }if (scrn4 == 4) { gloss(); }if (scrn4 == 5) { explore(); } if (scrn4 == 6) { telescope(); } if (scrn4 == 7) { material(); } if (scrn4 == 8) { title(); }

	}
}

void sizing() {

	if (layout == 1) {
		if (mpo2>72 && mpo2<(wy1*(csize2 - 76) + 52) && mpo1 >= (wx1*csize) - 2 && mpo1 <= (wx1*csize) + 2 && size != 1) { size = 1; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<72 || mpo2>(wy1*(csize2 - 76) + 52) || mpo1 < (wx1*csize) - 2 || mpo1 >(wx1*csize) + 2) { if (size == 1) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//second
		if (mpo2>72 && mpo2<(wy1*(csize2 - 76) + 52) && mpo1 >= ((wx1*csize) + (wx2*csize)) - 2 && mpo1 <= ((wx1*csize) + (wx2*csize)) + 2 && size != 2) { size = 2; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<72 || mpo2>(wy1*(csize2 - 76) + 52) || mpo1 < ((wx1*csize) + (wx2*csize)) - 2 || mpo1 >((wx1*csize) + (wx2*csize)) + 2) { if (size == 2) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//third
		if (mpo2>((wy1*(csize2 - 76)) + 72) && mpo2<csize2 - 25 && mpo1 >= (wx3*csize) - 2 && mpo1 <= (wx3*csize) + 2 && size != 3) { size = 3; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<((wy1*(csize2 - 76)) + 72) || mpo2>csize2 - 25 || mpo1 < (wx3*csize) - 2 || mpo1 >(wx3*csize) + 2) { if (size == 3) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//fourth
		if (mpo2>((wy1*(csize2 - 76)) + 52) - 2 && mpo2<((wy1*(csize2 - 76)) + 52) + 2 && size != 4) { size = 4; hc = LoadCursor(NULL, IDC_SIZENS); SetCursor(hc); }
		else if (mpo2<((wy1*(csize2 - 76)) + 52) - 2 || mpo2>((wy1*(csize2 - 76)) + 52) + 2) { if (size == 4) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
	}
	if (layout == 2) {
		if (mpo2>72 && mpo2<(wy1*(csize2 - 76) + 52) && mpo1 >= (wx1*csize) - 2 && mpo1 <= (wx1*csize) + 2 && size != 1) { size = 1; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<72 || mpo2>(wy1*(csize2 - 76) + 52) || mpo1 < (wx1*csize) - 2 || mpo1 >(wx1*csize) + 2) { if (size == 1) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//second
		if (mpo2>72 && mpo2<(wy1*(csize2 - 76) + 52) && mpo1 >= ((wx1*csize) + (wx2*csize)) - 2 && mpo1 <= ((wx1*csize) + (wx2*csize)) + 2 && size != 2) { size = 2; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<72 || mpo2>(wy1*(csize2 - 76) + 52) || mpo1 < ((wx1*csize) + (wx2*csize)) - 2 || mpo1 >((wx1*csize) + (wx2*csize)) + 2) { if (size == 2) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//third
		if (mpo2>((wy1*(csize2 - 76)) + 72) && mpo2<csize2 - 25 && mpo1 >= (wx3*csize) - 2 && mpo1 <= (wx3*csize) + 2 && size != 3) { size = 3; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<((wy1*(csize2 - 76)) + 72) || mpo2>csize2 - 25 || mpo1 < (wx3*csize) - 2 || mpo1 >(wx3*csize) + 2) { if (size == 3) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//fourth
		if (mpo2>((wy1*(csize2 - 76)) + 52) - 2 && mpo2<((wy1*(csize2 - 76)) + 52) + 2 && size != 4) { size = 4; hc = LoadCursor(NULL, IDC_SIZENS); SetCursor(hc); }
		else if (mpo2<((wy1*(csize2 - 76)) + 52) - 2 || mpo2>((wy1*(csize2 - 76)) + 52) + 2) { if (size == 4) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//fifth
		if (mpo2>((wy1*(csize2 - 76)) + 72) && mpo2<csize2 - 25 && mpo1 >= ((wx3*csize) + (wx4*csize)) - 2 && mpo1 <= ((wx3*csize) + (wx4*csize)) + 2 && size != 3) { size = 5; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<((wy1*(csize2 - 76)) + 72) || mpo2>csize2 - 25 || mpo1 < ((wx3*csize) + (wx4*csize)) - 2 || mpo1 >((wx3*csize) + (wx4*csize)) + 2) { if (size == 5) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }

	}
	if (layout == 3) {
		if (mpo2>((wy1*(csize2 - 76)) + 52) - 2 && mpo2<((wy1*(csize2 - 76)) + 52) + 2 && size != 1) { size = 1; hc = LoadCursor(NULL, IDC_SIZENS); SetCursor(hc); }
		else if (mpo2<((wy1*(csize2 - 76)) + 52) - 2 || mpo2>((wy1*(csize2 - 76)) + 52) + 2) { if (size == 1) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
	}
	if (layout == 4) {
		if (mpo2>72 && mpo2<csize2 - 25 && mpo1 >= (wx1*csize) - 2 && mpo1 <= (wx1*csize) + 2 && size != 1) { size = 1; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<72 || mpo2>csize2 -25|| mpo1 < (wx1*csize) - 2 || mpo1 >(wx1*csize) + 2) { if (size == 1) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
	}
	if (layout == 5) {
		if (mpo2>72 && mpo2<(wy1*(csize2 - 76) + 52) && mpo1 >= (wx1*csize) - 2 && mpo1 <= (wx1*csize) + 2 && size != 1) { size = 1; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<72 || mpo2>(wy1*(csize2 - 76) + 52) || mpo1 < (wx1*csize) - 2 || mpo1 >(wx1*csize) + 2) { if (size == 1) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//second
		if (mpo2>((wy1*(csize2 - 76)) + 52) - 2 && mpo2<((wy1*(csize2 - 76)) + 52) + 2 && size != 2) { size = 2; hc = LoadCursor(NULL, IDC_SIZENS); SetCursor(hc); }
		else if (mpo2<((wy1*(csize2 - 76)) + 52) - 2 || mpo2>((wy1*(csize2 - 76)) + 52) + 2) { if (size == 2) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
	}
	if (layout == 6) {
		if (mpo2>72 && mpo2<csize2 - 25 && mpo1 >= (wx1*csize) - 2 && mpo1 <= (wx1*csize) + 2 && size != 1) { size = 1; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<72 || mpo2>csize2 - 25 || mpo1 < (wx1*csize) - 2 || mpo1 >(wx1*csize) + 2) { if (size == 1) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//second
		if (mpo1 >= (wx1*csize) && mpo2>((wy1*(csize2 - 76)) + 52) - 2 && mpo2<((wy1*(csize2 - 76)) + 52) + 2 && size != 2) { size = 2; hc = LoadCursor(NULL, IDC_SIZENS); SetCursor(hc); }
		else if (mpo2<((wy1*(csize2 - 76)) + 52) - 2 || mpo2>((wy1*(csize2 - 76)) + 52) + 2 || mpo1 < (wx1*csize)) { if (size == 2) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }

	}
	if (layout == 7) {
		if (mpo1 < (wx1*csize) && mpo2>((wy1*(csize2 - 76)) + 52) - 2 && mpo2<((wy1*(csize2 - 76)) + 52) + 2 && size != 2) { size = 2; hc = LoadCursor(NULL, IDC_SIZENS); SetCursor(hc); }
		else if (mpo2<((wy1*(csize2 - 76)) + 52) - 2 || mpo2>((wy1*(csize2 - 76)) + 52) + 2 || mpo1 >(wx1*csize)) { if (size == 2) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//second
		if (mpo2>72 && mpo2<csize2 - 25 && mpo1 >= (wx1*csize) - 2 && mpo1 <= (wx1*csize) + 2 && size != 1) { size = 1; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<72 || mpo2>csize2 - 25 || mpo1 < (wx1*csize) - 2 || mpo1 >(wx1*csize) + 2) { if (size == 1) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
	}
	if (layout == 8) {
		if (mpo2>72 && mpo2<csize2 - 25 && mpo1 >= (wx1*csize) - 2 && mpo1 <= (wx1*csize) + 2 && size != 1) { size = 1; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<72 || mpo2>csize2 - 25 || mpo1 < (wx1*csize) - 2 || mpo1 >(wx1*csize) + 2) { if (size == 1) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//second
		if (mpo1 >= (wx1*csize) && mpo2>((wy1*(csize2 - 76)) + 52) - 2 && mpo2<((wy1*(csize2 - 76)) + 52) + 2 && size != 2) { size = 2; hc = LoadCursor(NULL, IDC_SIZENS); SetCursor(hc); }
		else if (mpo2<((wy1*(csize2 - 76)) + 52) - 2 || mpo2>((wy1*(csize2 - 76)) + 52) + 2 || mpo1 < (wx1*csize)) { if (size == 2) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//third
		if (mpo1 >= (wx1*csize) && mpo2>((wy1*(csize2 - 76)) + (wy2*(csize2 - 76)) + 52) - 2 && mpo2<((wy1*(csize2 - 76)) + (wy2*(csize2 - 76)) + 52) + 2 && size != 3) { size = 3; hc = LoadCursor(NULL, IDC_SIZENS); SetCursor(hc); }
		else if (mpo2<((wy1*(csize2 - 76)) + (wy2*(csize2 - 76)) + 52) - 2 || mpo2>((wy1*(csize2 - 76)) + (wy2*(csize2 - 76)) + 52) + 2 || mpo1 < (wx1*csize)) { if (size == 3) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }

	}
	if (layout == 9) {
		if (mpo2>(wy1*(csize2 - 76) + 72) && mpo2<csize2 - 25 && mpo1 >= (wx1*csize) - 2 && mpo1 <= (wx1*csize) + 2 && size != 1) { size = 1; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<(wy1*(csize2 - 76) + 72) || mpo2>csize2 - 25 || mpo1 < (wx1*csize) - 2 || mpo1 >(wx1*csize) + 2) { if (size == 1) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//second
		if (mpo2>((wy1*(csize2 - 76)) + 52) - 2 && mpo2<((wy1*(csize2 - 76)) + 52) + 2 && size != 2) { size = 2; hc = LoadCursor(NULL, IDC_SIZENS); SetCursor(hc); }
		else if (mpo2<((wy1*(csize2 - 76)) + 52) - 2 || mpo2>((wy1*(csize2 - 76)) + 52) + 2) { if (size == 2) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }

	}
	if (layout == 10) {
		if (mpo2>72 && mpo2<csize2 - 25 && mpo1 >= (wx1*csize) - 2 && mpo1 <= (wx1*csize) + 2 && size != 1) { size = 1; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<72 || mpo2>csize2 - 25 || mpo1 < (wx1*csize) - 2 || mpo1 >(wx1*csize) + 2) { if (size == 1) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//second
		if (mpo1 <= (wx1*csize) && mpo2>((wy1*(csize2 - 76)) + 52) - 2 && mpo2<((wy1*(csize2 - 76)) + 52) + 2 && size != 2) { size = 2; hc = LoadCursor(NULL, IDC_SIZENS); SetCursor(hc); }
		else if (mpo2<((wy1*(csize2 - 76)) + 52) - 2 || mpo2>((wy1*(csize2 - 76)) + 52) + 2 || mpo1 >(wx1*csize)) { if (size == 2) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//third
		if (mpo1 <= (wx1*csize) && mpo2>((wy1*(csize2 - 76)) + (wy2*(csize2 - 76)) + 52) - 2 && mpo2<((wy1*(csize2 - 76)) + (wy2*(csize2 - 76)) + 52) + 2 && size != 3) { size = 3; hc = LoadCursor(NULL, IDC_SIZENS); SetCursor(hc); }
		else if (mpo2<((wy1*(csize2 - 76)) + (wy2*(csize2 - 76)) + 52) - 2 || mpo2>((wy1*(csize2 - 76)) + (wy2*(csize2 - 76)) + 52) + 2 || mpo1 >(wx1*csize)) { if (size == 3) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }

	}
	if (layout == 11) {
		if (mpo2>72 && mpo2<(wy1*(csize2 - 76) + 52) && mpo1 >= (wx1*csize) - 2 && mpo1 <= (wx1*csize) + 2 && size != 1) { size = 1; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<72 || mpo2>(wy1*(csize2 - 76) + 52) || mpo1 < (wx1*csize) - 2 || mpo1 >(wx1*csize) + 2) { if (size == 1) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//second
		if (mpo2>72 && mpo2<(wy1*(csize2 - 76) + 52) && mpo1 >= ((wx1*csize) + (wx2*csize)) - 2 && mpo1 <= ((wx1*csize) + (wx2*csize)) + 2 && size != 2) { size = 2; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<72 || mpo2>(wy1*(csize2 - 76) + 52) || mpo1 < ((wx1*csize) + (wx2*csize)) - 2 || mpo1 >((wx1*csize) + (wx2*csize)) + 2) { if (size == 2) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//third
		if (mpo2>((wy1*(csize2 - 76)) + 52) - 2 && mpo2<((wy1*(csize2 - 76)) + 52) + 2 && size != 3) { size = 3; hc = LoadCursor(NULL, IDC_SIZENS); SetCursor(hc); }
		else if (mpo2<((wy1*(csize2 - 76)) + 52) - 2 || mpo2>((wy1*(csize2 - 76)) + 52) + 2) { if (size == 3) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
	}
	if (layout == 12) {
		if (mpo2>(wy1*(csize2 - 76) + 72) && mpo2<csize2 - 25 && mpo1 >= (wx1*csize) - 2 && mpo1 <= (wx1*csize) + 2 && size != 1) { size = 1; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<(wy1*(csize2 - 76) + 72) || mpo2>csize2 - 25 || mpo1 < (wx1*csize) - 2 || mpo1 >(wx1*csize) + 2) { if (size == 1) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//second
		if (mpo2>(wy1*(csize2 - 76) + 72) && mpo2<csize2 - 25 && mpo1 >= ((wx1*csize) + (wx2*csize)) - 2 && mpo1 <= ((wx1*csize) + (wx2*csize)) + 2 && size != 2) { size = 2; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<(wy1*(csize2 - 76) + 72) || mpo2>csize2 - 25 || mpo1 < ((wx1*csize) + (wx2*csize)) - 2 || mpo1 >((wx1*csize) + (wx2*csize)) + 2) { if (size == 2) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//third
		if (mpo2>((wy1*(csize2 - 76)) + 52) - 2 && mpo2<((wy1*(csize2 - 76)) + 52) + 2 && size != 3) { size = 3; hc = LoadCursor(NULL, IDC_SIZENS); SetCursor(hc); }
		else if (mpo2<((wy1*(csize2 - 76)) + 52) - 2 || mpo2>((wy1*(csize2 - 76)) + 52) + 2) { if (size == 3) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
	}
	if (layout == 13) {
		if (mpo2>72 && mpo2<(wy1*(csize2 - 76) + 52) && mpo1 >= (wx1*csize) - 2 && mpo1 <= (wx1*csize) + 2 && size != 1) { size = 1; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<72 || mpo2>(wy1*(csize2 - 76) + 52) || mpo1 < (wx1*csize) - 2 || mpo1 >(wx1*csize) + 2) { if (size == 1) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//second
		if (mpo2 >((wy1*(csize2 - 76)) + 72) && mpo2 < csize2 - 25 && mpo1 >= (wx2*csize) - 2 && mpo1 <= (wx2*csize) + 2 && size != 2) { size = 2; hc = LoadCursor(NULL, IDC_SIZEWE); SetCursor(hc); }
		else if (mpo2<((wy1*(csize2 - 76)) + 72) || mpo2>csize2 - 25 || mpo1 < ((wx2*csize)) - 2 || mpo1 >((wx2*csize)) + 2) { if (size == 2) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
		//third
		if (mpo2>((wy1*(csize2 - 76)) + 52) - 2 && mpo2<((wy1*(csize2 - 76)) + 52) + 2 && size != 3) { size = 3; hc = LoadCursor(NULL, IDC_SIZENS); SetCursor(hc); }
		else if (mpo2<((wy1*(csize2 - 76)) + 52) - 2 || mpo2>((wy1*(csize2 - 76)) + 52) + 2) { if (size == 3) { size = 0; hc = LoadCursor(NULL, IDC_ARROW); SetCursor(hc); } }
	}
}

void resiz() {
	if (layout == 1 && mdon == 1) {
		if (size == 1) {
			wx5 = wx2 + wx1; wx1 = (mpo1); wx1 /= csize;
			if (wx1 <= (100.0 / csize)) { wx1 = (100.0 / csize); }
			{ wx2 = (wx5 - wx1); } if (wx2 <= (100.0 / csize)) { wx2 = (100.0 / csize); wx1 = wx5 - wx2; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (size == 2) {
			wx5 = wx2; wx2 = (mpo1 - (wx1*csize)); wx2 /= csize;
			if (wx2 <= (100.0 / csize)) { wx2 = (100.0 / csize); }
			if ((wx2 + wx1)*csize > csize - 100) { wx5 = (csize - 100.0) / csize; wx2 = wx5 - wx1; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (size == 3) {
			wx3 = (mpo1); wx3 /= csize;
			if (wx3 <= (100.0 / csize)) { wx3 = (100.0 / csize); }
			if ((wx3)*csize > csize - 100) { wx3 = (csize - 100.0) / csize; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (size == 4) {
			wy1 = (mpo2 - 52); wy1 /= (csize2 - 76);
			if (wy1 <= (100.0 / (csize2 - 76))) { wy1 = (100.0 / (csize2 - 76)); }
			if ((wy1)*(csize2 - 76) > (csize2 - 76) - 100) { wy1 = ((csize2 - 76) - 100.0) / (csize2 - 76); }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
	}
	//layout 2
	if (layout == 2 && mdon == 1) {
		if (size == 1) {
			wx5 = wx2 + wx1; wx1 = (mpo1); wx1 /= csize;
			if (wx1 <= (100.0 / csize)) { wx1 = (100.0 / csize); }
			{ wx2 = (wx5 - wx1); } if (wx2 <= (100.0 / csize)) { wx2 = (100.0 / csize); wx1 = wx5 - wx2; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (size == 2) {
			wx5 = wx2; wx2 = (mpo1 - (wx1*csize)); wx2 /= csize;
			if (wx2 <= (100.0 / csize)) { wx2 = (100.0 / csize); }
			if ((wx2 + wx1)*csize > csize - 100) { wx5 = (csize - 100.0) / csize; wx2 = wx5 - wx1; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (size == 3) {
			wx5 = wx4 + wx3; wx3 = (mpo1); wx3 /= csize;
			if (wx3 <= (100.0 / csize)) { wx3 = (100.0 / csize); }  wx4 = (wx5 - wx3);
			if (wx4 <= (100.0 / csize)) { wx4 = (100.0 / csize); wx3 = wx5 - wx4; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (size == 5) {
			wx5 = wx4; wx4 = (mpo1 - (wx3*csize)); wx4 /= csize;
			if (wx4 <= (100.0 / csize)) { wx4 = (100.0 / csize); }
			if ((wx4 + wx3)*csize > csize - 100) { wx5 = (csize - 100.0) / csize; wx4 = wx5 - wx3; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (size == 4) {
			wy1 = (mpo2 - 52); wy1 /= (csize2 - 76);
			if (wy1 <= (100.0 / (csize2 - 76))) { wy1 = (100.0 / (csize2 - 76)); }
			if ((wy1)*(csize2 - 76) > (csize2 - 76) - 100) { wy1 = ((csize2 - 76) - 100.0) / (csize2 - 76); }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
	}
	//layout 3
	if (layout == 3 && mdon == 1) {
		if (size == 1) {
			wy1 = (mpo2 - 52); wy1 /= (csize2 - 76);
			if (wy1 <= (100.0 / (csize2 - 76))) { wy1 = (100.0 / (csize2 - 76)); }
			if ((wy1)*(csize2 - 76) > (csize2 - 76) - 100) { wy1 = ((csize2 - 76) - 100.0) / (csize2 - 76); }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
	}
	//layout 4
	if (layout == 4 && mdon == 1) {
		if (size == 1) {
			wx1 = (mpo1); wx1 /= csize;
			if (wx1 <= (100.0 / csize)) { wx1 = (100.0 / csize); }
			if ((wx1)*csize > csize - 100) { wx1 = (csize - 100.0) / csize; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
	}
	//layout 5
	if (layout == 5 && mdon == 1) {
		if (size == 1) {
			wx1 = (mpo1); wx1 /= csize;
			if (wx1 <= (100.0 / csize)) { wx1 = (100.0 / csize); }
			if ((wx1)*csize > csize - 100) { wx1 = (csize - 100.0) / csize; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (size == 2) {
			wy1 = (mpo2 - 52); wy1 /= (csize2 - 76);
			if (wy1 <= (100.0 / (csize2 - 76))) { wy1 = (100.0 / (csize2 - 76)); }
			if ((wy1)*(csize2 - 76) > (csize2 - 76) - 100) { wy1 = ((csize2 - 76) - 100.0) / (csize2 - 76); }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
	}
	//layout 6
	if (layout == 6 && mdon == 1) {
		if (size == 1) {
			wx1 = (mpo1); wx1 /= csize;
			if (wx1 <= (100.0 / csize)) { wx1 = (100.0 / csize); }
			if ((wx1)*csize > csize - 100) { wx1 = (csize - 100.0) / csize; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (size == 2) {
			wy1 = (mpo2 - 52); wy1 /= (csize2 - 76);
			if (wy1 <= (100.0 / (csize2 - 76))) { wy1 = (100.0 / (csize2 - 76)); }
			if ((wy1)*(csize2 - 76) > (csize2 - 76) - 100) { wy1 = ((csize2 - 76) - 100.0) / (csize2 - 76); }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
	}
	//layout 7
	if (layout == 7 && mdon == 1) {
		if (size == 1) {
			wx1 = (mpo1); wx1 /= csize;
			if (wx1 <= (100.0 / csize)) { wx1 = (100.0 / csize); }
			if ((wx1)*csize > csize - 100) { wx1 = (csize - 100.0) / csize; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (size == 2) {
			wy1 = (mpo2 - 52); wy1 /= (csize2 - 76);
			if (wy1 <= (100.0 / (csize2 - 76))) { wy1 = (100.0 / (csize2 - 76)); }
			if ((wy1)*(csize2 - 76) > (csize2 - 76) - 100) { wy1 = ((csize2 - 76) - 100.0) / (csize2 - 76); }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
	}
	//layout 8
	if (layout == 8 && mdon == 1) {
		if (size == 1) {
			wx1 = (mpo1); wx1 /= csize;
			if (wx1 <= (100.0 / csize)) { wx1 = (100.0 / csize); }
			if ((wx1)*csize > csize - 100) { wx1 = (csize - 100.0) / csize; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}

		if (size == 2) {
			wx5 = wy2 + wy1;	wy1 = (mpo2 - 52); wy1 /= (csize2 - 76);
			if (wy1 <= (100.0 / (csize2 - 76))) { wy1 = (100.0 / (csize2 - 76)); }	wy2 = (wx5 - wy1);
			if (wy2 < 100.0 / (csize2 - 76)) { wy2 = (100.0 / (csize2 - 76)); wy1 = wx5 - wy2; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (size == 3) {
			wx5 = wy2 + wy1; wy2 = (mpo2 - 52) - (wy1*(csize2 - 76)); wy2 /= (csize2 - 76);
			if (wy2 <= (100.0 / (csize2 - 76))) { wy2 = (100.0 / (csize2 - 76)); }
			if ((wy2 + wy1)*(csize2 - 76) >(csize2 - 76) - 100) { wy2 = ((csize2 - 76) - 100.0) / (csize2 - 76); wy2 -= wy1; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
	}
	//layout 9
	if (layout == 9 && mdon == 1) {
		if (size == 1) {
			wx1 = (mpo1); wx1 /= csize;
			if (wx1 <= (100.0 / csize)) { wx1 = (100.0 / csize); }
			if ((wx1)*csize > csize - 100) { wx1 = (csize - 100.0) / csize; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (size == 2) {
			wy1 = (mpo2 - 52); wy1 /= (csize2 - 76);
			if (wy1 <= (100.0 / (csize2 - 76))) { wy1 = (100.0 / (csize2 - 76)); }
			if ((wy1)*(csize2 - 76) > (csize2 - 76) - 100) { wy1 = ((csize2 - 76) - 100.0) / (csize2 - 76); }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
	}
	//layout 10
	if (layout == 10 && mdon == 1) {
		if (size == 1) {
			wx1 = (mpo1); wx1 /= csize;
			if (wx1 <= (100.0 / csize)) { wx1 = (100.0 / csize); }
			if ((wx1)*csize > csize - 100) { wx1 = (csize - 100.0) / csize; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}

		if (size == 2) {
			wx5 = wy2 + wy1;	wy1 = (mpo2 - 52); wy1 /= (csize2 - 76);
			if (wy1 <= (100.0 / (csize2 - 76))) { wy1 = (100.0 / (csize2 - 76)); }	wy2 = (wx5 - wy1);
			if (wy2 < 100.0 / (csize2 - 76)) { wy2 = (100.0 / (csize2 - 76)); wy1 = wx5 - wy2; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (size == 3) {
			wx5 = wy2 + wy1; wy2 = (mpo2 - 52) - (wy1*(csize2 - 76)); wy2 /= (csize2 - 76);
			if (wy2 <= (100.0 / (csize2 - 76))) { wy2 = (100.0 / (csize2 - 76)); }
			if ((wy2 + wy1)*(csize2 - 76) >(csize2 - 76) - 100) { wy2 = ((csize2 - 76) - 100.0) / (csize2 - 76); wy2 -= wy1; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
	}
	//layout 11
	if (layout == 11 && mdon == 1) {
		if (size == 1) {
			wx5 = wx2 + wx1; wx1 = (mpo1); wx1 /= csize;
			if (wx1 <= (100.0 / csize)) { wx1 = (100.0 / csize); }
			{ wx2 = (wx5 - wx1); } if (wx2 <= (100.0 / csize)) { wx2 = (100.0 / csize); wx1 = wx5 - wx2; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (size == 2) {
			wx5 = wx2; wx2 = (mpo1 - (wx1*csize)); wx2 /= csize;
			if (wx2 <= (100.0 / csize)) { wx2 = (100.0 / csize); }
			if ((wx2 + wx1)*csize > csize - 100) { wx5 = (csize - 100.0) / csize; wx2 = wx5 - wx1; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (size == 3) {
			wy1 = (mpo2 - 52); wy1 /= (csize2 - 76);
			if (wy1 <= (100.0 / (csize2 - 76))) { wy1 = (100.0 / (csize2 - 76)); }
			if ((wy1)*(csize2 - 76) > (csize2 - 76) - 100) { wy1 = ((csize2 - 76) - 100.0) / (csize2 - 76); }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
	}
	//layout 12
	if (layout == 12 && mdon == 1) {
		if (size == 1) {
			wx5 = wx2 + wx1; wx1 = (mpo1); wx1 /= csize;
			if (wx1 <= (100.0 / csize)) { wx1 = (100.0 / csize); }
			{ wx2 = (wx5 - wx1); } if (wx2 <= (100.0 / csize)) { wx2 = (100.0 / csize); wx1 = wx5 - wx2; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (size == 2) {
			wx5 = wx2; wx2 = (mpo1 - (wx1*csize)); wx2 /= csize;
			if (wx2 <= (100.0 / csize)) { wx2 = (100.0 / csize); }
			if ((wx2 + wx1)*csize > csize - 100) { wx5 = (csize - 100.0) / csize; wx2 = wx5 - wx1; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (size == 3) {
			wy1 = (mpo2 - 52); wy1 /= (csize2 - 76);
			if (wy1 <= (100.0 / (csize2 - 76))) { wy1 = (100.0 / (csize2 - 76)); }
			if ((wy1)*(csize2 - 76) > (csize2 - 76) - 100) { wy1 = ((csize2 - 76) - 100.0) / (csize2 - 76); }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
	}
	//layout 13
	if (layout == 13 && mdon == 1) {
		if (size == 1) {
			wx1 = (mpo1); wx1 /= csize;
			if (wx1 <= (100.0 / csize)) { wx1 = (100.0 / csize); }
			if ((wx1)*csize > csize - 100) { wx1 = (csize - 100.0) / csize; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (size == 2) {
			wx2 = (mpo1); wx2 /= csize;
			if (wx2 <= (100.0 / csize)) { wx2 = (100.0 / csize); }
			if ((wx2)*csize > csize - 100) { wx2 = (csize - 100.0) / csize; }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
		if (size == 3) {
			wy1 = (mpo2 - 52); wy1 /= (csize2 - 76);
			if (wy1 <= (100.0 / (csize2 - 76))) { wy1 = (100.0 / (csize2 - 76)); }
			if ((wy1)*(csize2 - 76) > (csize2 - 76) - 100) { wy1 = ((csize2 - 76) - 100.0) / (csize2 - 76); }
			ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE);
		}
	}
}

void alignt() {

	if (layout == 1) {
		if (mpo1 > 0 && mpo1 < 20 && mpo2>52 && mpo2 < 72 && hover != 0) { hover = 0; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 > 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 0) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >(wx1*csize) && mpo1 < (wx1*csize) + 20 && mpo2>52 && mpo2 < 72 && hover != 1) { hover = 1; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < (wx1*csize) || mpo1 >(wx1*csize) + 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 1) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >((wx1 + wx2)*csize) && mpo1 < ((wx1 + wx2)*csize) + 20 && mpo2>52 && mpo2 < 72 && hover != 2) { hover = 2; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < ((wx1 + wx2)*csize) || mpo1 >((wx1 + wx2)*csize) + 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 2) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >0 && mpo1 < 20 && mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < (wy1*(csize2 - 76)) + 72 && hover != 3) { hover = 3; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 >20 || mpo2 < (wy1*(csize2 - 76)) + 52 || mpo2 >(wy1*(csize2 - 76)) + 72) { if (hover == 3) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >(wx3*csize) && mpo1 <(wx3*csize) + 20 && mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < (wy1*(csize2 - 76)) + 72 && hover != 4) { hover = 4; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < (wx3*csize) || mpo1 >(wx3*csize) + 20 || mpo2 < (wy1*(csize2 - 76)) + 52 || mpo2 >(wy1*(csize2 - 76)) + 72) { if (hover == 4) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }
	}
	if (layout == 2) {
		if (mpo1 > 0 && mpo1 < 20 && mpo2>52 && mpo2 < 72 && hover != 0) { hover = 0; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 > 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 0) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >(wx1*csize) && mpo1 < (wx1*csize) + 20 && mpo2>52 && mpo2 < 72 && hover != 1) { hover = 1; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < (wx1*csize) || mpo1 >(wx1*csize) + 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 1) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >((wx1 + wx2)*csize) && mpo1 < ((wx1 + wx2)*csize) + 20 && mpo2>52 && mpo2 < 72 && hover != 2) { hover = 2; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < ((wx1 + wx2)*csize) || mpo1 >((wx1 + wx2)*csize) + 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 2) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >0 && mpo1 < 20 && mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < (wy1*(csize2 - 76)) + 72 && hover != 3) { hover = 3; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 >20 || mpo2 < (wy1*(csize2 - 76)) + 52 || mpo2 >(wy1*(csize2 - 76)) + 72) { if (hover == 3) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >(wx3*csize) && mpo1 <(wx3*csize) + 20 && mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < (wy1*(csize2 - 76)) + 72 && hover != 4) { hover = 4; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < (wx3*csize) || mpo1 >(wx3*csize) + 20 || mpo2 < (wy1*(csize2 - 76)) + 52 || mpo2 >(wy1*(csize2 - 76)) + 72) { if (hover == 4) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >((wx3 + wx4)*csize) && mpo1 <((wx3 + wx4)*csize) + 20 && mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < (wy1*(csize2 - 76)) + 72 && hover != 5) { hover = 5; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < ((wx3 + wx4)*csize) || mpo1 >((wx3 + wx4)*csize) + 20 || mpo2 < (wy1*(csize2 - 76)) + 52 || mpo2 >(wy1*(csize2 - 76)) + 72) { if (hover == 5) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

	}
	if (layout == 3) {
		if (mpo1 > 0 && mpo1 < 20 && mpo2>52 && mpo2 < 72 && hover != 0) { hover = 0; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 > 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 0) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >0 && mpo1 < 20 && mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < (wy1*(csize2 - 76)) + 72 && hover != 1) { hover = 1; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 >20 || mpo2 < (wy1*(csize2 - 76)) + 52 || mpo2 >(wy1*(csize2 - 76)) + 72) { if (hover == 1) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

	}
	if (layout == 4) {
		if (mpo1 > 0 && mpo1 < 20 && mpo2>52 && mpo2 < 72 && hover != 0) { hover = 0; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 > 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 0) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >(wx1*csize) && mpo1 < (wx1*csize) + 20 && mpo2>52 && mpo2 < 72 && hover != 1) { hover = 1; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < (wx1*csize) || mpo1 >(wx1*csize) + 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 1) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

	}
	if (layout == 5) {
		if (mpo1 > 0 && mpo1 < 20 && mpo2>52 && mpo2 < 72 && hover != 0) { hover = 0; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 > 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 0) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >(wx1*csize) && mpo1 < (wx1*csize) + 20 && mpo2>52 && mpo2 < 72 && hover != 1) { hover = 1; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < (wx1*csize) || mpo1 >(wx1*csize) + 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 1) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >0 && mpo1 < 20 && mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < (wy1*(csize2 - 76)) + 72 && hover != 2) { hover = 2; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 >20 || mpo2 < (wy1*(csize2 - 76)) + 52 || mpo2 >(wy1*(csize2 - 76)) + 72) { if (hover == 2) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

	}
	if (layout == 6) {
		if (mpo1 > 0 && mpo1 < 20 && mpo2>52 && mpo2 < 72 && hover != 0) { hover = 0; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 > 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 0) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >(wx1*csize) && mpo1 < (wx1*csize) + 20 && mpo2>52 && mpo2 < 72 && hover != 1) { hover = 1; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < (wx1*csize) || mpo1 >(wx1*csize) + 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 1) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >(wx1*csize) && mpo1 < (wx1*csize) + 20 && mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < (wy1*(csize2 - 76)) + 72 && hover != 2) { hover = 2; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < (wx1*csize) || mpo1 >(wx1*csize) + 20 || mpo2 < (wy1*(csize2 - 76)) + 52 || mpo2 >(wy1*(csize2 - 76)) + 72) { if (hover == 2) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

	}
	if (layout == 7) {
		if (mpo1 >(wx1*csize) && mpo1 < (wx1*csize) + 20 && mpo2>52 && mpo2 < 72 && hover != 2) { hover = 2; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < (wx1*csize) || mpo1 >(wx1*csize)+ 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 2) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >0 && mpo1 <  20 && mpo2>52 && mpo2 < 72 && hover != 0) { hover = 0; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 > 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 0) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >0 && mpo1 <  20 && mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < (wy1*(csize2 - 76)) + 72 && hover != 1) { hover = 1; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 > 20 || mpo2 < (wy1*(csize2 - 76)) + 52 || mpo2 >(wy1*(csize2 - 76)) + 72) { if (hover == 1) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

	}
	if (layout == 8) {
		if (mpo1 > 0 && mpo1 < 20 && mpo2>52 && mpo2 < 72 && hover != 0) { hover = 0; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 > 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 0) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >(wx1*csize) && mpo1 < (wx1*csize) + 20 && mpo2>52 && mpo2 < 72 && hover != 1) { hover = 1; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < (wx1*csize) || mpo1 >(wx1*csize) + 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 1) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >(wx1*csize) && mpo1 < (wx1*csize) + 20 && mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < (wy1*(csize2 - 76)) + 72 && hover != 2) { hover = 2; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < (wx1*csize) || mpo1 >(wx1*csize) + 20 || mpo2 < (wy1*(csize2 - 76)) + 52 || mpo2 >(wy1*(csize2 - 76)) + 72) { if (hover == 2) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >(wx1*csize) && mpo1 < (wx1*csize) + 20 && mpo2>((wy1 + wy2)*(csize2 - 76)) + 52 && mpo2 < ((wy1 + wy2)*(csize2 - 76)) + 72 && hover != 3) { hover = 3; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < (wx1*csize) || mpo1 >(wx1*csize) + 20 || mpo2 < ((wy1 + wy2)*(csize2 - 76)) + 52 || mpo2 >((wy1 + wy2)*(csize2 - 76)) + 72) { if (hover == 3) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

	}
	if (layout == 9) {
		if (mpo1 > 0 && mpo1 < 20 && mpo2>52 && mpo2 < 72 && hover != 0) { hover = 0; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 > 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 0) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >0 && mpo1 < 20 && mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < (wy1*(csize2 - 76)) + 72 && hover != 1) { hover = 1; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 >20 || mpo2 < (wy1*(csize2 - 76)) + 52 || mpo2 >(wy1*(csize2 - 76)) + 72) { if (hover == 1) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >(wx1*csize) && mpo1 <(wx1*csize) + 20 && mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < (wy1*(csize2 - 76)) + 72 && hover != 2) { hover = 2; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < (wx1*csize) || mpo1 >(wx1*csize) + 20 || mpo2 < (wy1*(csize2 - 76)) + 52 || mpo2 >(wy1*(csize2 - 76)) + 72) { if (hover == 2) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

	}
	if (layout == 10) {
		if (mpo1 >(wx1*csize) && mpo1 < (wx1*csize) + 20 && mpo2>52 && mpo2 < 72 && hover != 3) { hover = 3; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < (wx1*csize) || mpo1 >(wx1*csize) + 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 3) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >0 && mpo1 < 20 && mpo2>52 && mpo2 < 72 && hover != 0) { hover = 0; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 > 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 0) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >0 && mpo1 <  20 && mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < (wy1*(csize2 - 76)) + 72 && hover != 1) { hover = 1; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 >20 || mpo2 < (wy1*(csize2 - 76)) + 52 || mpo2 >(wy1*(csize2 - 76)) + 72) { if (hover == 1) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >0 && mpo1 < 20 && mpo2>((wy1 + wy2)*(csize2 - 76)) + 52 && mpo2 < ((wy1 + wy2)*(csize2 - 76)) + 72 && hover != 2) { hover = 2; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 > 20 || mpo2 < ((wy1 + wy2)*(csize2 - 76)) + 52 || mpo2 >((wy1 + wy2)*(csize2 - 76)) + 72) { if (hover == 2) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

	}
	if (layout == 11) {
		if (mpo1 > 0 && mpo1 < 20 && mpo2>52 && mpo2 < 72 && hover != 0) { hover = 0; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 > 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 0) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >(wx1*csize) && mpo1 < (wx1*csize) + 20 && mpo2>52 && mpo2 < 72 && hover != 1) { hover = 1; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < (wx1*csize) || mpo1 >(wx1*csize) + 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 1) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >((wx1 + wx2)*csize) && mpo1 < ((wx1 + wx2)*csize) + 20 && mpo2>52 && mpo2 < 72 && hover != 2) { hover = 2; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < ((wx1 + wx2)*csize) || mpo1 >((wx1 + wx2)*csize) + 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 2) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >0 && mpo1 < 20 && mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < (wy1*(csize2 - 76)) + 72 && hover != 3) { hover = 3; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 >20 || mpo2 < (wy1*(csize2 - 76)) + 52 || mpo2 >(wy1*(csize2 - 76)) + 72) { if (hover == 3) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

	}
	if (layout == 12) {
		if (mpo1 > 0 && mpo1 < 20 && mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < (wy1*(csize2 - 76)) + 72 && hover != 1) { hover = 1; ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); }
		else if (mpo1 < 0 || mpo1 > 20 || mpo2 <(wy1*(csize2 - 76)) + 52 || mpo2 >(wy1*(csize2 - 76)) + 72) { if (hover == 1) { hover = -1;  ValidateRect(hwnd, &client); InvalidateRect(hwnd, &client, TRUE); } }

		if (mpo1 >(wx1*csize) && mpo1 < (wx1*csize) + 20 && mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < (wy1*(csize2 - 76)) + 72 && hover != 2) { hover = 2; ValidateRect(hwnd, &client); InvalidateRect(hwnd, NULL, TRUE); }
		else if (mpo1 < (wx1*csize) || mpo1 >(wx1*csize) + 20 || mpo2 < (wy1*(csize2 - 76)) + 52 || mpo2 >(wy1*(csize2 - 76)) + 72) { if (hover == 2) { hover = -1;  ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); } }

		if (mpo1 >((wx1 + wx2)*csize) && mpo1 < ((wx1 + wx2)*csize) + 20 && mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < (wy1*(csize2 - 76)) + 72 && hover != 3) { hover = 3; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		else if (mpo1 < ((wx1 + wx2)*csize) || mpo1 >((wx1 + wx2)*csize) + 20 || mpo2 < (wy1*(csize2 - 76)) + 52 || mpo2 >(wy1*(csize2 - 76)) + 72) { if (hover == 3) { hover = -1;  ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); } }

		if (mpo1 >0 && mpo1 < 20 && mpo2> 52 && mpo2 <  72 && hover != 0) { hover = 0; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		else if (mpo1 < 0 || mpo1 >20 || mpo2 <  52 || mpo2 > 72) { if (hover == 0) { hover = -1;  ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); } }

	}
	if (layout == 13) {
		if (mpo1 > 0 && mpo1 < 20 && mpo2>52 && mpo2 < 72 && hover != 0) { hover = 0; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		else if (mpo1 < 0 || mpo1 > 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 0) { hover = -1;  ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); } }

		if (mpo1 >(wx1*csize) && mpo1 < (wx1*csize) + 20 && mpo2>52 && mpo2 < 72 && hover != 1) { hover = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		else if (mpo1 < (wx1*csize) || mpo1 >(wx1*csize) + 20 || mpo2 < 52 || mpo2 > 72) { if (hover == 1) { hover = -1;  ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); } }

		if (mpo1 >0 && mpo1 < 20 && mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < (wy1*(csize2 - 76)) + 72 && hover != 3) { hover = 2; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		else if (mpo1 < 0 || mpo1 >20 || mpo2 < (wy1*(csize2 - 76)) + 52 || mpo2 >(wy1*(csize2 - 76)) + 72) { if (hover == 2) { hover = -1;  ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); } }

		if (mpo1 >(wx2*csize) && mpo1 <(wx2*csize) + 20 && mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < (wy1*(csize2 - 76)) + 72 && hover != 3) { hover = 3; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		else if (mpo1 < (wx2*csize) || mpo1 >(wx2*csize) + 20 || mpo2 < (wy1*(csize2 - 76)) + 52 || mpo2 >(wy1*(csize2 - 76)) + 72) { if (hover == 3) { hover = -1;  ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); } }
	}

}


//last function

void last() {
	if (pop == 1) {

		SetRect(&rc, pop1, pop2, pop1 + 360, pop2 + 200);
		if (mpo1 > pop1&&mpo1<pop1 + 180 && mpo2 - pop2 > 10 && mpo2 - pop2 < 30 && pop3 != 1) { pop3 = 1; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
		else if (mpo1 < pop1 || mpo1>pop1 + 180 || mpo2 - pop2 < 10 || mpo2 - pop2 > 30) { if (pop3 == 1) { pop3 = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }

		if (mpo1 > pop1&&mpo1<pop1 + 180 && mpo2 - pop2>30 && mpo2 - pop2<50 && pop3 != 2) { pop3 = 2; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
		else if (mpo1 < pop1 || mpo1>pop1 + 180 || mpo2 - pop2 < 30 || mpo2 - pop2 > 50) { if (pop3 == 2) { pop3 = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }

		if (mpo1 > pop1&&mpo1<pop1 + 180 && mpo2 - pop2>50 && mpo2 - pop2<70 && pop3 != 3) { pop3 = 3; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
		else if (mpo1 < pop1 || mpo1>pop1 + 180 || mpo2 - pop2 < 50 || mpo2 - pop2 > 70) { if (pop3 == 3) { pop3 = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }

		if (mpo1 > pop1&&mpo1<pop1 + 180 && mpo2 - pop2 > 70 && mpo2 - pop2 < 90 && pop3 != 4) { pop3 = 4; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
		else if (mpo1 < pop1 || mpo1>pop1 + 180 || mpo2 - pop2 < 70 || mpo2 - pop2 > 90) { if (pop3 == 4) { pop3 = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }

		if (mpo1 > pop1&&mpo1<pop1 + 180 && mpo2 - pop2 > 90 && mpo2 - pop2 < 110 && pop3 != 5) { pop3 = 5; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
		else if (mpo1 < pop1 || mpo1>pop1 + 180 || mpo2 - pop2 < 90 || mpo2 - pop2 > 110) { if (pop3 == 5) { pop3 = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }

		if (mpo1 > pop1&&mpo1<pop1 + 180 && mpo2 - pop2 > 110 && mpo2 - pop2 < 130 && pop3 != 6) { pop3 = 6; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
		else if (mpo1 < pop1 || mpo1>pop1 + 180 || mpo2 - pop2 < 110 || mpo2 - pop2 > 130) { if (pop3 == 6) { pop3 = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }

		if (mpo1 > pop1&&mpo1<pop1 + 180 && mpo2 - pop2 > 130 && mpo2 - pop2 < 150 && pop3 != 7) { pop3 = 7; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
		else if (mpo1 < pop1 || mpo1>pop1 + 180 || mpo2 - pop2 < 130 || mpo2 - pop2 > 150) { if (pop3 == 7) { pop3 = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }

		if (mpo1 > pop1+180&&mpo1<pop1 + 360 && mpo2 - pop2 > 10 && mpo2 - pop2 < 30 && pop3 != 8) { pop3 = 8; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
		else if (mpo1 < pop1+180 || mpo1>pop1 + 360 || mpo2 - pop2 < 10 || mpo2 - pop2 > 30) { if (pop3 == 8) { pop3 = 0; ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }

	}
}

void final() {
	

	if (menu == 1 && menu2 == 1) {
		menu = 0; menu1 = 0; menu2 = 0;
		if (layout != 1) { wx1 = 0.3333333; wx2 = wx1; wx3 = wx1; wy1 = 0.6; } ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE);
		layout = 1;
	}
	if (menu == 1 && menu2 == 2) {
		menu = 0; menu1 = 0; menu2 = 0;
		if (layout != 2) { wx1 = 0.3333333; wx2 = wx1; wx3 = wx1; wx4 = wx1; wy1 = 0.5; } ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE);
		layout = 2;
	}
	if (menu == 1 && menu2 == 3) {
		menu = 0; menu1 = 0; menu2 = 0;
		if (layout != 3) { wy1 = 0.5; } ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE);
		layout = 3;
	}
	if (menu == 1 && menu2 == 4) {
		menu = 0; menu1 = 0; menu2 = 0;
		if (layout != 4) { wx1 = 0.5; } ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE);
		layout = 4;
	}
	if (menu == 1 && menu2 == 5) {
		menu = 0; menu1 = 0; menu2 = 0;
		if (layout != 5) { wx1 = 0.5; wy1 = 0.5; } ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE);
		layout = 5;
	}
	if (menu == 1 && menu2 == 6) {
		menu = 0; menu1 = 0; menu2 = 0;
		if (layout != 6) { wx1 = 0.5; wy1 = 0.5; } ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE);
		layout = 6;
	}
	if (menu == 1 && menu2 == 7) {
		menu = 0; menu1 = 0; menu2 = 0;
		if (layout != 7) { wx1 = 0.5; wy1 = 0.5; } ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE);
		layout = 7;
	}
	if (menu == 1 && menu2 == 8) {
		menu = 0; menu1 = 0; menu2 = 0;
		if (layout != 8) { wx1 = 0.5; wy1 = 0.3333333; wy2 = 0.3333333; } ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE);
		layout = 8;
	}
	if (menu == 1 && menu2 == 9) {
		menu = 0; menu1 = 0; menu2 = 0;
		if (layout != 9) { wx1 = 0.5;  wy1 = 0.5; } ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE);
		layout = 9;
	}
	if (menu == 1 && menu2 == 10) {
		menu = 0; menu1 = 0; menu2 = 0;
		if (layout != 10) { wx1 = 0.5; wy1 = 0.3333333; wy2 = 0.3333333; } ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE);
		layout = 10;
	}
	if (menu == 1 && menu2 == 11) {
		menu = 0; menu1 = 0; menu2 = 0;
		if (layout != 11) { wy1 = 0.5; wx1 = 0.3333333; wx2 = 0.3333333; } ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE);
		layout = 11;
	}
	if (menu == 1 && menu2 == 12) {
		menu = 0; menu1 = 0; menu2 = 0;
		if (layout != 12) { wx1 = 0.333333; wx3 = 0.3333333; wx2 = 0.3333333; wy1 = 0.5; } ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE);
		layout = 12;
	}
	if (menu == 1 && menu2 == 13) {
		menu = 0; menu1 = 0; menu2 = 0;
		if (layout != 13) { wx1 = 0.5; wy1 = 0.5; wx2 = 0.5; } ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE);
		layout = 13;
	}


	if (mpo1 > csize - 50 && mpo1 < csize - 10 && mpo2>23 && mpo2 < 50) { menu = 1; SetRect(&rc, csize - 130, 20, csize, 325);  ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); }
	else if (mpo1<csize - 120 || mpo1>csize || mpo2 < 50 || mpo2>325) { if (menu == 1) { menu = 0;  menu2 = 0; SetRect(&rc, csize - 130, 20, csize, 325);  ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE); } }


	if (size != 0) { mdon = 1; }
	
	if (pop != 0) { 

		if (layout == 1) {
			if (pop3 != 0) {
				if (pop4 == 0) { scrn1 = pop3; }
				if (pop4 == 1) { scrn2 = pop3; }
				if (pop4 == 2) { scrn3 = pop3; }
				if (pop4 == 3) { scrn4 = pop3; }
				if (pop4 == 4) { scrn5 = pop3; }
			}
		}
		if (layout == 2) {
			if (pop3 != 0) {
				if (pop4 == 0) { scrn1 = pop3; }
				if (pop4 == 1) { scrn2 = pop3; }
				if (pop4 == 2) { scrn3 = pop3; }
				if (pop4 == 3) { scrn4 = pop3; }
				if (pop4 == 4) { scrn5 = pop3; }
				if (pop4 == 5) { scrn6 = pop3; }
			}
		}
		if (layout == 3) {
			if (pop3 != 0) { 
				if (pop4==0) { scrn1 = pop3; }
				if (pop4 == 1) { scrn2 = pop3; }
			}
		}
		if (layout == 4) {
			if (pop3 != 0) { 
				if (pop4==0) { scrn1 = pop3; }
				if (pop4 == 1) { scrn2 = pop3; }
			}
		}
		if (layout == 5) {
			if (pop3 != 0) {
				if (pop4 == 0) { scrn1 = pop3; }
				if (pop4 == 1) { scrn2 = pop3; }
				if (pop4 == 2) { scrn3 = pop3; }
			}
		}
		if (layout == 6) {
			if (pop3 != 0) {
				if (pop4 == 0) { scrn1 = pop3; }
				if (pop4 == 1) { scrn2 = pop3; }
				if (pop4 == 2) { scrn3 = pop3; }
			}
		}
		if (layout == 7) {
			if (pop3 != 0) {
				if (pop4 == 0) { scrn1 = pop3; }
				if (pop4 == 1) { scrn2 = pop3; }
				if (pop4 == 2) { scrn3 = pop3; }
			}
		}
		if (layout == 9) {
			if (pop3 != 0) {
				if (pop4 == 0) { scrn1 = pop3; }
				if (pop4 == 1) { scrn2 = pop3; }
				if (pop4 == 2) { scrn3 = pop3; }
			}
		}
		if (layout == 8 ||  layout == 11  || layout == 13) {
			if (pop3 != 0) {
				if (pop4 == 0) { scrn1 = pop3; }
				if (pop4 == 1) { scrn2 = pop3; }
				if (pop4 == 2) { scrn3 = pop3; }
				if (pop4 == 3) { scrn4 = pop3; }
			}
		}
		if (layout == 10 ) {
			if (pop3 != 0) {
				if (pop4 == 3) { scrn1 = pop3; }
				if (pop4 == 0) { scrn2 = pop3; }
				if (pop4 == 1) { scrn3 = pop3; }
				if (pop4 == 2) { scrn4 = pop3; }
			}
		}
		if (layout == 12) {
			if (pop3 != 0) {
				if (pop4 == 1) { scrn1 = pop3; }
				if (pop4 == 2) { scrn2 = pop3; }
				if (pop4 == 3) { scrn3 = pop3; }
				if (pop4 == 0) { scrn4 = pop3; }
			}
		}
		
		pop = 0; hover = -1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }



	if (layout == 1&& pop != 1) {
		if (hover == 0) { pop4 = hover; pop1 = 0; pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 1) { pop4 = hover; pop1 = (wx1*csize); pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 2) { pop4 = hover; pop1 = ((wx1 + wx2)*csize); pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 3) { pop4 = hover; pop1 = 0; pop2 = (wy1*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 4) { pop4 = hover; pop1 = (wx3*csize); pop2 = (wy1*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
	}
	if (layout == 2 && pop != 1) {
		if (hover == 0) { pop4 = hover; pop1 = 0; pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 1) { pop4 = hover; pop1 = (wx1*csize); pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 2) { pop4 = hover; pop1 = ((wx1 + wx2)*csize); pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 3) { pop4 = hover; pop1 = 0; pop2 = (wy1*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 4) { pop4 = hover; pop1 = (wx3*csize); pop2 = (wy1*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 5) { pop4 = hover; pop1 = ((wx4 + wx3)*csize); pop2 = (wy1*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
	}
	if (layout == 3 && pop != 1) {
		if (hover == 0) { pop4 = hover; pop1 = 0; pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 1) { pop4 = hover; pop1 = 0; pop2 = (wy1*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
	}
	if (layout == 4 && pop != 1) {
		if (hover == 0) { pop4 = hover; pop1 = 0; pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 1) { pop4 = hover; pop1 = (wx1*csize); pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
	}
	if (layout == 5 && pop != 1) {
		if (hover == 0) { pop4 = hover; pop1 = 0; pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 1) { pop4 = hover; pop1 = (wx1*csize); pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 2) { pop4 = hover; pop1 = 0; pop2 = (wy1*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
	}
	if (layout == 6 && pop != 1) {
		if (hover == 0) { pop4 = hover; pop1 = 0; pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 1) { pop4 = hover; pop1 = (wx1*csize); pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 2) { pop4 = hover; pop1 = (wx1*csize); pop2 = (wy1*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
	}
	if (layout == 7 && pop != 1) {
		if (hover == 2) { pop4 = hover; pop1 = (wx1*csize); pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 0) { pop4 = hover; pop1 = 0; pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 1) { pop4 = hover; pop1 = 0; pop2 = (wy1*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
	}
	if (layout == 8 && pop != 1) {
		if (hover == 0) { pop4 = hover; pop1 = 0; pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 1) { pop4 = hover; pop1 = (wx1*csize); pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 2) { pop4 = hover; pop1 = (wx1*csize); pop2 = (wy1*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 3) { pop4 = hover; pop1 = (wx1*csize); pop2 = ((wy1 + wy2)*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
	}
	if (layout == 9 && pop != 1) {
		if (hover == 1) { pop4 = hover; pop1 = 0; pop2 = (wy1*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 2) { pop4 = hover; pop1 = (wx1*csize); pop2 = (wy1*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 0) { pop4 = hover; pop1 = 0; pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
	}
	if (layout == 10 && pop != 1) {
		if (hover == 3) { pop4 = hover; pop1 = (wx1*csize); pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 0) { pop4 = hover; pop1 = 0; pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 1) { pop4 = hover; pop1 = 0; pop2 = (wy1*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 2) { pop4 = hover; pop1 = 0; pop2 = ((wy1 + wy2)*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
	}
	if (layout == 11 && pop != 1) {
		if (hover == 0) { pop4 = hover; pop1 = 0; pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 1) { pop4 = hover; pop1 = (wx1*csize); pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 2) { pop4 = hover; pop1 = ((wx1 + wx2)*csize); pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 3) { pop4 = hover; pop1 = 0; pop2 = (wy1*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
	}
	if (layout == 12 && pop != 1) {
		if (hover == 1) { pop4 = hover; pop1 = 0; pop2 = (wy1*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 2) { pop4 = hover; pop1 = (wx1*csize); pop2 = (wy1*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 3) { pop4 = hover; pop1 = ((wx1 + wx2)*csize); pop2 = (wy1*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 0) { pop4 = hover; pop1 = 0; pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
	}
	if (layout == 13 && pop != 1) {
		if (hover == 0) { pop4 = hover; pop1 = 0; pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 1) { pop4 = hover; pop1 = (wx1*csize); pop2 = 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 2) { pop4 = hover; pop1 = 0; pop2 = (wy1*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
		if (hover == 3) { pop4 = hover; pop1 = (wx2*csize); pop2 = (wy1*(csize2 - 76)) + 73; pop = 1; ValidateRect(hwnd, NULL); InvalidateRect(hwnd, NULL, TRUE); }
	}
	
}