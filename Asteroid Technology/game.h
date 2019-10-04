void gameplay() {
	if (skew == 0) {
	hgc = CreateCompatibleDC(hdc);
	hgm = CreateCompatibleBitmap(hdc, wx, wy);
	SelectObject(hgc, hgm);
	gamx = stx; gamy = sty; gamw = wx; gamwy = wy;
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

	hiu = LoadIcon(GetModuleHandle(NULL), "ICO54"); DrawIcon(hgc, 2, 1, hiu);  DeleteObject(hiu);
	if(skew==0){ hiu = LoadIcon(GetModuleHandle(NULL), "ICO55"); DrawIcon(hgc, 90, 1, hiu);  DeleteObject(hiu); }
	else{ hiu = LoadIcon(GetModuleHandle(NULL), "ICO56"); DrawIcon(hgc, 90, 1, hiu);  DeleteObject(hiu); }

	hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
	SelectObject(hgc, hf);
	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);
	TextOut(hgc, 30, 3, "Game", 4);

	DeleteObject(hf);

	BitBlt(hdc, stx, sty, wx, wy, hgc, 0, 0, SRCCOPY);
	DeleteDC(hgc);
	DeleteObject(hgm);
	}
	else {
	hgc = CreateCompatibleDC(hdc);
	hgm = CreateCompatibleBitmap(hdc, csize, csize2-77);
	SelectObject(hgc, hgm);
	gamx = 0; gamy = 52; gamw = csize; gamwy = csize2-78;
	SetRect(&rc, 0, 0, csize, csize2-77);
	brush = CreateSolidBrush(RGB(20, 20, 20));
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	SetRect(&rc, 2, 20, csize - 2, csize2 - 78);
	brush = CreateSolidBrush(RGB(50, 50, 50));
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	SetRect(&rc, 0, 0, 20, 19);
	 { brush = CreateSolidBrush(RGB(50, 50, 50)); }
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	hiu = LoadIcon(GetModuleHandle(NULL), "ICO54"); DrawIcon(hgc, 2, 1, hiu);  DeleteObject(hiu);
	if(skew==0){ hiu = LoadIcon(GetModuleHandle(NULL), "ICO55"); DrawIcon(hgc, 90, 1, hiu);  DeleteObject(hiu); }
	else{ hiu = LoadIcon(GetModuleHandle(NULL), "ICO56"); DrawIcon(hgc, 90, 1, hiu);  DeleteObject(hiu); }

	hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
	SelectObject(hgc, hf);
	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);
	TextOut(hgc, 30, 3, "Game", 4);

	DeleteObject(hf);

	BitBlt(hdc, 0, 52, csize, csize2-77, hgc, 0, 0, SRCCOPY);
	DeleteDC(hgc);
	DeleteObject(hgm);
	
	}
}