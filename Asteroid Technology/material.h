void mark() {
	if (mlik >= 0 && fclick<0) {
		for (int w = 0, x = 0, m = 0;w < strlen(tree);w++) {
			if (x >= mlik) {
				for (0;w < strlen(tree);w++) { how1[m] = tree[w]; m++; if (tree[w + 1] == ':') { how1[m] = 0; break; } }
				break;
			}
			if (tree[w] == '\n') { x++; }
		}
		hf = CreateFont(17, 8, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 35, 30-pres[hover1], wx - 12, wy); DrawText(hgc, how1, -1, &rc, NULL);
		DeleteObject(hf);

		hf = CreateFont(15, 7, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 35, 80-pres[hover1], wx - 12, wy); DrawText(hgc, "Position", -1, &rc, NULL);
		SetRect(&rc, 35, 120-pres[hover1], wx - 12, wy); DrawText(hgc, "Rotation", -1, &rc, NULL);
		SetRect(&rc, 35, 160-pres[hover1], wx - 12, wy); DrawText(hgc, "Scale", -1, &rc, NULL);
		SetRect(&rc, 30, 210-pres[hover1], wx - 12, wy); DrawText(hgc, "Material(s)", -1, &rc, NULL);
		DeleteObject(hf);

		hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 10, 50-pres[hover1], wx - 12, wy); DrawText(hgc, "Type: Object", -1, &rc, NULL);
		SetRect(&rc, 10, 100-pres[hover1], wx - 12, wy); DrawText(hgc, "Z", -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 10, 100-pres[hover1], wx - 12, wy); DrawText(hgc, "Y", -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 10, 100-pres[hover1], wx - 12, wy); DrawText(hgc, "X", -1, &rc, NULL);

		SetRect(&rc, 10, 140-pres[hover1], wx - 12, wy); DrawText(hgc, "X", -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 10, 140-pres[hover1], wx - 12, wy); DrawText(hgc, "Y", -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 10, 140-pres[hover1], wx - 12, wy); DrawText(hgc, "Z", -1, &rc, NULL);

		SetRect(&rc, 10, 180-pres[hover1], wx - 12, wy); DrawText(hgc, "X", -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 10, 180-pres[hover1], wx - 12, wy); DrawText(hgc, "Y", -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 10, 180-pres[hover1], wx - 12, wy); DrawText(hgc, "Z", -1, &rc, NULL);
		thm = 240-pres[hover1]; maclick = -1;
		for (int t = 0, k = 0, l = 0;t < strlen(materil[mlik]);t++) {
			how1[k] = materil[mlik][t]; k++;
			if (materil[mlik][t + 1] == ';') {
				t++;
				how1[k] = 0; k = 0;
				bu = matprop[mlik][l].Kd;
				thm1 = colr[mlik][bu].x * 255; thm2 = colr[mlik][bu].y * 255; thm3 = colr[mlik][bu].z * 255;
				brush = CreateSolidBrush(RGB(thm1, thm2, thm3)); SelectObject(hgc, brush);
				hp = CreatePen(PS_SOLID, 1, RGB(thm1, thm2, thm3)); SelectObject(hgc, hp);
				Ellipse(hgc, 8, thm, 23, thm + 15);
				DeleteObject(brush); DeleteObject(hp);
				if (mpo1 - stx > 0 && mpo1 - stx < wx&&mpo2-sty>thm&&mpo2-sty<thm+15) {
					SetTextColor(hgc, RGB(100, 100, 200)); maclick = l; sprintf(matname, "%s", how1);
				}else{ SetTextColor(hgc,RGB(255,255,255)); }
				SetRect(&rc, 30, thm, wx - 12, wy); DrawText(hgc, how1, -1, &rc, NULL);
				thm += 20; l++; SetTextColor(hgc, RGB(255, 255, 255));
			}
		}

		if(showobj[mlik]==1){
		brush = CreateSolidBrush(RGB(90,90,90)); SetRect(&rc,83,51-pres[hover1],104,63-pres[hover1]);
		FillRect(hgc,&rc,brush); DeleteObject(brush);
		}

		hiu = LoadIcon(GetModuleHandle(NULL), "ICO31"); DrawIcon(hgc, 85, 49-pres[hover1], hiu); DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO37"); DrawIcon(hgc, 5, 30-pres[hover1], hiu); DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO35"); DrawIcon(hgc, 5, 76-pres[hover1], hiu);  DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO36"); DrawIcon(hgc, 5, 120-pres[hover1], hiu);  DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO39"); DrawIcon(hgc, 5, 158-pres[hover1], hiu);  DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO38"); DrawIcon(hgc, 5, 210-pres[hover1], hiu);  DeleteObject(hiu);

		brush = CreateSolidBrush(RGB(80, 80, 80)); SelectObject(hgc, brush);
		hp = CreatePen(PS_SOLID, 1, RGB(10, 10, 10)); SelectObject(hgc, hp);
		Rectangle(hgc, 19, 99-pres[hover1], (wx / 3)-7+2, 114-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3), 99-pres[hover1], (wx / 3 * 2) - 7+2, 114-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3 * 2), 99 -pres[hover1], wx - 12, 114-pres[hover1]+2);

		Rectangle(hgc, 19, 139-pres[hover1], (wx / 3) - 7+2, 154-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3), 139-pres[hover1], (wx / 3 * 2) - 7+2, 154-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3 * 2), 139-pres[hover1], wx - 12, 154-pres[hover1]+2);

		Rectangle(hgc, 19, 179-pres[hover1], (wx / 3) - 7+2, 194-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3), 179-pres[hover1], (wx / 3 * 2) - 7+2, 194-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3 * 2), 179-pres[hover1], wx - 12, 194-pres[hover1]+2);
		DeleteObject(brush); DeleteObject(hp);

		MoveToEx(hgc, 0, 205-pres[hover1], NULL); LineTo(hgc, wx, 205-pres[hover1]);

		sprintf_s(how1, "%f", px + mauv[mlik].x);
		SetRect(&rc, 23, 100-pres[hover1], (wx / 3) - 9, 114-pres[hover1]); DrawText(hgc, how1, -1, &rc, NULL);
		sprintf_s(how1, "%f", py + mauv[mlik].y);
		SetRect(&rc, 23 + (wx / 3), 100-pres[hover1], (wx / 3 * 2) - 9, 114-pres[hover1]); DrawText(hgc, how1, -1, &rc, NULL);
		sprintf_s(how1, "%f", pz + mauv[mlik].z);
		SetRect(&rc, 23 + (wx / 3 * 2), 100-pres[hover1], wx - 14, 114-pres[hover1]); DrawText(hgc, how1, -1, &rc, NULL);
		//rotation
		sprintf_s(how1, "%f", rita[mlik].x);
		SetRect(&rc, 23, 140 - pres[hover1], (wx / 3) - 9, 155 - pres[hover1]); DrawText(hgc, how1, -1, &rc, NULL);
		sprintf_s(how1, "%f", rita[mlik].y);
		SetRect(&rc, 23 + (wx / 3), 140 - pres[hover1], (wx / 3 * 2) - 9, 155 - pres[hover1]); DrawText(hgc, how1, -1, &rc, NULL);
		sprintf_s(how1, "%f", rita[mlik].z);
		SetRect(&rc, 23 + (wx / 3 * 2), 140 - pres[hover1], wx - 14, 155 - pres[hover1]); DrawText(hgc, how1, -1, &rc, NULL);

		//scale
		sprintf_s(how1, "%f", scil[mlik].x);
		SetRect(&rc, 23, 180 - pres[hover1], (wx / 3) - 9, 195 - pres[hover1]); DrawText(hgc, how1, -1, &rc, NULL);
		sprintf_s(how1, "%f", scil[mlik].y);
		SetRect(&rc, 23 + (wx / 3), 180 - pres[hover1], (wx / 3 * 2) - 9, 195 - pres[hover1]); DrawText(hgc, how1, -1, &rc, NULL);
		sprintf_s(how1, "%f", scil[mlik].z);
		SetRect(&rc, 23 + (wx / 3 * 2), 180 - pres[hover1], wx - 14, 195 - pres[hover1]); DrawText(hgc, how1, -1, &rc, NULL);


bu=thm+pres[hover1];
		DeleteObject(hf);
	}

	if (mlik >= 0 && fclick >= 0) {
		for (int w = 0, x = 0, m = 0;w < strlen(tree);w++) {
			if (x >= mlik) {
				for (0;w < strlen(tree);w++) { if (tree[w - 1] == ':') { break; } }
				x = 0;
				for (0;w < strlen(tree);w++) { if (x >= fclick) { break; } if (tree[w] == ';') { x++; } }
				for (0;w < strlen(tree);w++) { how1[m] = tree[w]; m++; if (tree[w + 1] == ';') { how1[m] = 0; break; } }
				break;
			}
			if (tree[w] == '\n') { x++; }
		}
		hf = CreateFont(17, 8, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 35, 30-pres[hover1], wx - 12, wy); DrawText(hgc, how1, -1, &rc, NULL);
		DeleteObject(hf);

		hf = CreateFont(15, 7, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 35, 80-pres[hover1], wx - 12, wy); DrawText(hgc, "Position", -1, &rc, NULL);
		SetRect(&rc, 35, 120-pres[hover1], wx - 12, wy); DrawText(hgc, "Rotation", -1, &rc, NULL);
		SetRect(&rc, 35, 160-pres[hover1], wx - 12, wy); DrawText(hgc, "Scale", -1, &rc, NULL);
		SetRect(&rc, 30, 230-pres[hover1], wx - 12, wy); DrawText(hgc, "Material(s)", -1, &rc, NULL);
		DeleteObject(hf);

		hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 10, 50-pres[hover1], wx - 12, wy); DrawText(hgc, "Type: Group", -1, &rc, NULL);
		SetRect(&rc, 10, 100-pres[hover1], wx - 12, wy); DrawText(hgc, "Z", -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 10, 100-pres[hover1], wx - 12, wy); DrawText(hgc, "Y", -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 10, 100-pres[hover1], wx - 12, wy); DrawText(hgc, "X", -1, &rc, NULL);

		SetRect(&rc, 10, 140-pres[hover1], wx - 12, wy); DrawText(hgc, "X", -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 10, 140-pres[hover1], wx - 12, wy); DrawText(hgc, "Y", -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 10, 140-pres[hover1], wx - 12, wy); DrawText(hgc, "Z", -1, &rc, NULL);

		SetRect(&rc, 10, 180-pres[hover1], wx - 12, wy); DrawText(hgc, "X", -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 10, 180-pres[hover1], wx - 12, wy); DrawText(hgc, "Y", -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 10, 180-pres[hover1], wx - 12, wy); DrawText(hgc, "Z", -1, &rc, NULL);

		SetRect(&rc, 25, 205-pres[hover1], wx - 12, wy); DrawText(hgc, "Shade", -1, &rc, NULL);
		SetRect(&rc, 85, 205-pres[hover1], wx - 12, wy); DrawText(hgc, "Dot", -1, &rc, NULL);
		SetRect(&rc, 125, 205-pres[hover1], wx - 12, wy); DrawText(hgc, "Wireframe", -1, &rc, NULL);
		
		thm = 260-pres[hover1];
		for (int t = 0,ll=0,kk=0,mm=0;t < chkd;t++) {
			bu = matdisp[t];
			for (ll = 0,kk=0;ll < strlen(materil[mlik]);ll++) {
			if(kk>=bu){ 
			for(mm=0;ll<strlen(materil[mlik]);ll++){ how1[mm]=materil[mlik][ll]; mm++; if(materil[mlik][ll+1]==';'){ how1[mm]=0; break;} }
			break;}
			if (materil[mlik][ll] == ';') { kk++; }
			}
			bu = matprop[mlik][bu].Kd;
			thm1 = colr[mlik][bu].x * 255; thm2 = colr[mlik][bu].y * 255; thm3 = colr[mlik][bu].z * 255;

			brush = CreateSolidBrush(RGB(thm1, thm2, thm3)); SelectObject(hgc, brush);
			hp = CreatePen(PS_SOLID, 1, RGB(thm1, thm2, thm3)); SelectObject(hgc, hp);
			Ellipse(hgc, 8, thm, 23, thm + 15);
			DeleteObject(brush); DeleteObject(hp);
			SetRect(&rc, 30, thm, wx - 12, wy); DrawText(hgc, how1, -1, &rc, NULL);
			thm += 20;
		}
		
	

		hiu = LoadIcon(GetModuleHandle(NULL), "ICO40"); DrawIcon(hgc, 5, 30-pres[hover1], hiu); DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO35"); DrawIcon(hgc, 5, 76-pres[hover1], hiu);  DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO36"); DrawIcon(hgc, 5, 120-pres[hover1], hiu);  DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO39"); DrawIcon(hgc, 5, 158-pres[hover1], hiu);  DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO38"); DrawIcon(hgc, 5, 230-pres[hover1], hiu);  DeleteObject(hiu);

		brush = CreateSolidBrush(RGB(80, 80, 80)); SelectObject(hgc, brush);
		hp = CreatePen(PS_SOLID, 1, RGB(10, 10, 10)); SelectObject(hgc, hp);
		Rectangle(hgc, 19, 99-pres[hover1], (wx / 3)-7+2, 114-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3), 99-pres[hover1], (wx / 3 * 2) - 7+2, 114-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3 * 2), 99 -pres[hover1], wx - 12, 114-pres[hover1]+2);

		Rectangle(hgc, 19, 139-pres[hover1], (wx / 3) - 7+2, 154-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3), 139-pres[hover1], (wx / 3 * 2) - 7+2, 154-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3 * 2), 139-pres[hover1], wx - 12, 154-pres[hover1]+2);

		Rectangle(hgc, 19, 179-pres[hover1], (wx / 3) - 7+2, 194-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3), 179-pres[hover1], (wx / 3 * 2) - 7+2, 194-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3 * 2), 179-pres[hover1], wx - 12, 194-pres[hover1]+2);

		Rectangle(hgc, 10, 207-pres[hover1], 20, 217-pres[hover1]);
		Rectangle(hgc, 70, 207-pres[hover1], 80, 217-pres[hover1]);
		Rectangle(hgc, 110, 207-pres[hover1], 120, 217-pres[hover1]);
		
		DeleteObject(brush);

		brush = CreateSolidBrush(RGB(frame[mlik][fclick].z*255, frame[mlik][fclick].y * 255, frame[mlik][fclick].x * 255)); SelectObject(hgc, brush);
		Rectangle(hgc, 190, 202-pres[hover1], 210, 222-pres[hover1]);
		DeleteObject(brush);
		brush = CreateSolidBrush(RGB(250, 250, 250)); SelectObject(hgc, brush);
		if (fice[mlik][check] == -4) { Rectangle(hgc, 12, 209-pres[hover1], 18, 215-pres[hover1]); }
		if (fice[mlik][check + 1] == -9) { Rectangle(hgc, 112, 209-pres[hover1], 118, 215-pres[hover1]); }
		if (fice[mlik][check + 2] == -11) { Rectangle(hgc, 72, 209-pres[hover1], 78, 215-pres[hover1]); }

		DeleteObject(brush); 
		DeleteObject(hp);

		MoveToEx(hgc, 0, 225-pres[hover1], NULL); LineTo(hgc, wx, 225-pres[hover1]);
		MoveToEx(hgc, 0, 425-pres[hover1], NULL); LineTo(hgc, wx, 425-pres[hover1]);

		sprintf_s(how1, "%f", px + mauv[mlik].x + gauv[mlik][fclick].x);
		SetRect(&rc, 23, 100-pres[hover1], (wx / 3) - 9, 114-pres[hover1]); DrawText(hgc, how1, -1, &rc, NULL);
		sprintf_s(how1, "%f", py + mauv[mlik].y + gauv[mlik][fclick].y);
		SetRect(&rc, 23 + (wx / 3), 100-pres[hover1], (wx / 3 * 2) - 9, 114-pres[hover1]); DrawText(hgc, how1, -1, &rc, NULL);
		sprintf_s(how1, "%f", pz + mauv[mlik].z + gauv[mlik][fclick].z);
		SetRect(&rc, 23 + (wx / 3 * 2), 100-pres[hover1], wx - 14, 114-pres[hover1]); DrawText(hgc, how1, -1, &rc, NULL);
		//rotation
		sprintf_s(how1, "%f", rota[mlik][fclick].x);
		SetRect(&rc, 23, 140 - pres[hover1], (wx / 3) - 9, 155 - pres[hover1]); DrawText(hgc, how1, -1, &rc, NULL);
		sprintf_s(how1, "%f", rota[mlik][fclick].y);
		SetRect(&rc, 23 + (wx / 3), 140 - pres[hover1], (wx / 3 * 2) - 9, 155 - pres[hover1]); DrawText(hgc, how1, -1, &rc, NULL);
		sprintf_s(how1, "%f", rota[mlik][fclick].z);
		SetRect(&rc, 23 + (wx / 3 * 2), 140 - pres[hover1], wx - 14, 155 - pres[hover1]); DrawText(hgc, how1, -1, &rc, NULL);

		//scale
		sprintf_s(how1, "%f", scal[mlik][fclick].x);
		SetRect(&rc, 23, 180 - pres[hover1], (wx / 3) - 9, 195 - pres[hover1]); DrawText(hgc, how1, -1, &rc, NULL);
		sprintf_s(how1, "%f", scal[mlik][fclick].y);
		SetRect(&rc, 23 + (wx / 3), 180 - pres[hover1], (wx / 3 * 2) - 9, 195 - pres[hover1]); DrawText(hgc, how1, -1, &rc, NULL);
		sprintf_s(how1, "%f", scal[mlik][fclick].z);
		SetRect(&rc, 23 + (wx / 3 * 2), 180 - pres[hover1], wx - 14, 195 - pres[hover1]); DrawText(hgc, how1, -1, &rc, NULL);
		
		bu=thm+pres[hover1];
		DeleteObject(hf);
	}

	//camera
	if (jlik >= 0) {
		for (int a = 0,b=0,e=0;a < strlen(camera);a++){
		if(b>=jlik){ 
		for(0;a<strlen(camera);a++){ how1[e]=camera[a]; e++; if(camera[a+1]==':'){ how1[e]=0; break;} } a+=2; e=0;
		for (0;a<strlen(camera);a++) { cls1[e] = camera[a]; e++; if (camera[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { cls2[e] = camera[a]; e++; if (camera[a + 1] == ',') { cls2[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { cls3[e] = camera[a]; e++; if (camera[a + 1] == ',') { cls3[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { cls4[e] = camera[a]; e++; if (camera[a + 1] == ',') { cls4[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { cls5[e] = camera[a]; e++; if (camera[a + 1] == ',') { cls5[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { cls6[e] = camera[a]; e++; if (camera[a + 1] == ',') { cls6[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { cls7[e] = camera[a]; e++; if (camera[a + 1] == ',') { cls7[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { cls8[e] = camera[a]; e++; if (camera[a + 1] == ',') { cls8[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { cls9[e] = camera[a]; e++; if (camera[a + 1] == ',') { cls9[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { cls10[e] = camera[a]; e++; if (camera[a + 1] == ',') { cls10[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { cls11[e] = camera[a]; e++; if (camera[a + 1] == ',') { cls11[e] = 0; break; } } a += 2; e = 0;
		
		for (0;a<strlen(camera);a++) { how[e] = camera[a]; e++; if (camera[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; thm5=atof(how);
		for (0;a<strlen(camera);a++) { how[e] = camera[a]; e++; if (camera[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; thm6 = atof(how);
		for (0;a<strlen(camera);a++) { how[e] = camera[a]; e++; if (camera[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; thm7 = atof(how);

		for (0;a<strlen(camera);a++) { cls12[e] = camera[a]; e++; if (camera[a + 1] == ',') { cls12[e] = 0; break; } } a += 2; e = 0;
		for (0;a<strlen(camera);a++) { cls13[e] = camera[a]; e++; if (camera[a + 1] == ',') { cls13[e] = 0; break; } } a += 2; e = 0;

		for (0;a<strlen(camera);a++) { how[e] = camera[a]; e++; if (camera[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; thm3 = atof(how);
		for (0;a<strlen(camera);a++) { how[e] = camera[a]; e++; if (camera[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; thm8 = atof(how);
		for (0;a<strlen(camera);a++) { how[e] = camera[a]; e++; if (camera[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; thm9 = atof(how);

		for (0;a<strlen(camera);a++) { how[e] = camera[a]; e++; if (camera[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; thm2 = atof(how);
		for (0;a<strlen(camera);a++) { cls14[e] = camera[a]; e++; if (camera[a + 1] == ',') { cls14[e] = 0; break; } } a += 2; e = 0; 
		break;}
		if (camera[a] == ';'){ b++;}
		}
		hf = CreateFont(17, 8, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 35, 30-pres[hover1], wx - 12, wy); DrawText(hgc, how1, -1, &rc, NULL);
		DeleteObject(hf);

		hf = CreateFont(15, 7, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 35, 80-pres[hover1], wx - 12, wy); DrawText(hgc, "Position", -1, &rc, NULL);
		SetRect(&rc, 35, 120-pres[hover1], wx - 12, wy); DrawText(hgc, "Rotation", -1, &rc, NULL);
		SetRect(&rc, 35, 190-pres[hover1], wx - 12, wy); DrawText(hgc, "Ratio", -1, &rc, NULL);
		SetRect(&rc, (wx / 2) + 5, 208-pres[hover1], wx - 12, wy); DrawText(hgc, ":", -1, &rc, NULL);
		DeleteObject(hf);

		hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 10, 50-pres[hover1], wx - 12, wy); DrawText(hgc, "Type: Video Camera", -1, &rc, NULL);
		SetRect(&rc, 10, 100-pres[hover1], wx - 12, wy); DrawText(hgc, "Z", -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 10, 100-pres[hover1], wx - 12, wy); DrawText(hgc, "Y", -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 10, 100-pres[hover1], wx - 12, wy); DrawText(hgc, "X", -1, &rc, NULL);

		SetRect(&rc, 10, 140-pres[hover1], wx - 12, wy); DrawText(hgc, "X", -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 10, 140-pres[hover1], wx - 12, wy); DrawText(hgc, "Y", -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 10, 140-pres[hover1], wx - 12, wy); DrawText(hgc, "Z", -1, &rc, NULL);

		SetRect(&rc, 10, 170-pres[hover1], wx - 12, wy); DrawText(hgc, "Far", -1, &rc, NULL);
		SetRect(&rc, wx /2+ 10, 170-pres[hover1], wx - 12, wy); DrawText(hgc, "Near", -1, &rc, NULL);

		SetRect(&rc,10, 230-pres[hover1], wx - 12, wy); DrawText(hgc, "SCL", -1, &rc, NULL);
		SetRect(&rc, 25, 250-pres[hover1], wx - 12, wy); DrawText(hgc, "Default", -1, &rc, NULL);
		SetRect(&rc, 85, 250-pres[hover1], wx - 12, wy); DrawText(hgc, "Perspective", -1, &rc, NULL);
		SetRect(&rc, 170, 250-pres[hover1], wx - 12, wy); DrawText(hgc, "Viewport Size", -1, &rc, NULL);

		SetRect(&rc, 10, 270-pres[hover1], wx - 12, wy); DrawText(hgc, "Size", -1, &rc, NULL);
		SetRect(&rc, wx/2, 270-pres[hover1], wx - 12, wy); DrawText(hgc, "Percentage", -1, &rc, NULL);

		SetRect(&rc, 10, 290-pres[hover1], wx - 12, wy); DrawText(hgc, "Background", -1, &rc, NULL);

		SetRect(&rc, 25, 315-pres[hover1], wx - 12, wy); DrawText(hgc, "None", -1, &rc, NULL);
		SetRect(&rc, 85, 315-pres[hover1], wx - 12, wy); DrawText(hgc, "Image", -1, &rc, NULL);
		SetRect(&rc, 170, 315-pres[hover1], wx - 12, wy); DrawText(hgc, "Skybox", -1, &rc, NULL);
		SetRect(&rc, 10, 333-pres[hover1], wx - 12, wy); DrawText(hgc, "Scale", -1, &rc, NULL);

		DeleteObject(hf);
		

		hiu = LoadIcon(GetModuleHandle(NULL), "ICO42"); DrawIcon(hgc, 5, 30-pres[hover1], hiu); DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO35"); DrawIcon(hgc, 5, 76-pres[hover1], hiu);  DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO36"); DrawIcon(hgc, 5, 120-pres[hover1], hiu);  DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO43"); DrawIcon(hgc, 5, 190-pres[hover1], hiu);  DeleteObject(hiu);

		brush = CreateSolidBrush(RGB(80, 80, 80)); SelectObject(hgc, brush);
		hp = CreatePen(PS_SOLID, 1, RGB(10, 10, 10)); SelectObject(hgc, hp);
		Rectangle(hgc, 19, 99-pres[hover1], (wx / 3) - 7+2, 114-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3), 99-pres[hover1], (wx / 3 * 2) - 7+2, 114-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3 * 2), 99-pres[hover1], wx - 12, 114-pres[hover1]+2);

		Rectangle(hgc, 19, 139-pres[hover1], (wx / 3) - 7+2, 154-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3), 139-pres[hover1], (wx / 3 * 2) - 7+2, 154-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3 * 2), 139-pres[hover1], wx - 12, 154-pres[hover1]+2);
		
		MoveToEx(hgc, 0, 163-pres[hover1], NULL); LineTo(hgc, wx, 163-pres[hover1]);

		Rectangle(hgc, 30, 169-pres[hover1], (wx / 2) - 7, 186-pres[hover1]);
		Rectangle(hgc, 40 + (wx / 2), 169-pres[hover1], (wx -12), 186-pres[hover1]);

		Rectangle(hgc, 10, 209-pres[hover1], (wx / 2) - 7, 226-pres[hover1]);
		Rectangle(hgc, 19 + (wx / 2), 209-pres[hover1], (wx - 12), 226-pres[hover1]+2);

		Rectangle(hgc, 40, 269-pres[hover1], (wx / 2) - 7, 286-pres[hover1]);
	if(70+(wx/2)<wx-12){ Rectangle(hgc, 70 + (wx / 2), 269-pres[hover1], (wx - 12), 286-pres[hover1]); }

		Rectangle(hgc, 40, 229-pres[hover1], wx-12, 246-pres[hover1]);

		Rectangle(hgc, 10, 252-pres[hover1], 20, 262-pres[hover1]);
		Rectangle(hgc, 70, 252-pres[hover1], 80, 262-pres[hover1]);
		Rectangle(hgc, 155, 252-pres[hover1], 165, 262-pres[hover1]);
		

		Rectangle(hgc, 10, 317-pres[hover1], 20, 327-pres[hover1]);
		Rectangle(hgc, 70, 317-pres[hover1], 80, 327-pres[hover1]);
		Rectangle(hgc, 155, 317-pres[hover1], 165, 327-pres[hover1]);

		Rectangle(hgc, 50, 333-pres[hover1], wx-12, 350-pres[hover1]);
		DeleteObject(brush);
		brush = CreateSolidBrush(RGB(250, 250, 250)); SelectObject(hgc, brush);
		if(thm5==1){ Rectangle(hgc, 12, 254-pres[hover1], 18, 260-pres[hover1]); }
		if(thm6==1){ Rectangle(hgc, 72, 254-pres[hover1], 78, 260-pres[hover1]); }
		if(thm7==1){ Rectangle(hgc, 157, 254-pres[hover1], 163, 260-pres[hover1]); }

		if(thm2==0){ Rectangle(hgc, 12, 319-pres[hover1], 18, 325-pres[hover1]); }
		if (thm2 == 1) { Rectangle(hgc, 72, 319-pres[hover1], 78, 325-pres[hover1]); }
		if (thm2 == 2) { Rectangle(hgc, 157, 319-pres[hover1], 163, 325-pres[hover1]); }

		DeleteObject(brush);
		brush = CreateSolidBrush(RGB(thm3, thm8, thm9)); SelectObject(hgc, brush);
		Rectangle(hgc, 80, 287-pres[hover1], 100, 307-pres[hover1]);
		DeleteObject(brush); DeleteObject(hp);


		hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 25, 100-pres[hover1], wx/3-7, wy); DrawText(hgc, cls1, -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 25, 100-pres[hover1], wx/3*2-7, wy); DrawText(hgc, cls2, -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 25, 100-pres[hover1], wx - 12, wy); DrawText(hgc, cls3, -1, &rc, NULL);

		SetRect(&rc, 25, 140-pres[hover1], wx / 3 - 7, wy); DrawText(hgc, cls4, -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 25, 140-pres[hover1], wx / 3*2 - 7, wy); DrawText(hgc, cls5, -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 25, 140-pres[hover1], wx - 12, wy); DrawText(hgc, cls6, -1, &rc, NULL);

		SetRect(&rc, 33, 170-pres[hover1], wx/2-7, wy); DrawText(hgc, cls7, -1, &rc, NULL);
		SetRect(&rc, wx / 2 + 45, 170-pres[hover1], wx - 12, wy); DrawText(hgc, cls8, -1, &rc, NULL);

		SetRect(&rc, 12, 210-pres[hover1], wx/2-7, wy); DrawText(hgc, cls9, -1, &rc, NULL);
		SetRect(&rc, wx / 2 + 24, 210-pres[hover1], wx - 12, wy); DrawText(hgc, cls10, -1, &rc, NULL);

		SetRect(&rc, 43, 230-pres[hover1], wx-13, wy); DrawText(hgc, cls11, -1, &rc, NULL);

		SetRect(&rc, 43, 270-pres[hover1], wx / 2 - 7, wy); DrawText(hgc, cls12, -1, &rc, NULL);
		SetRect(&rc, wx / 2 + 72, 270-pres[hover1], wx - 12, wy); DrawText(hgc, cls13, -1, &rc, NULL);

		SetRect(&rc, 52, 334-pres[hover1], wx - 12, wy); DrawText(hgc, cls14, -1, &rc, NULL);
		bu=334+20;
		DeleteObject(hf);
	}

	//light
	if (lkik >= 0) { typz=-1;
		for (int a = 0, b = 0, e = 0;a < strlen(light);a++) {
			if (b >= lkik) {
	for (0;a<strlen(light);a++) { how1[e] = light[a]; e++; if (light[a + 1] == ':') { how1[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls1[e] = light[a]; e++; if (light[a + 1] == ',') { cls1[e] = 0; break; } } a += 2; e = 0;
	if (cls1[0] != '3') {
	for (0;a<strlen(light);a++) { cls2[e] = light[a]; e++; if (light[a + 1] == ',') { cls2[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls3[e] = light[a]; e++; if (light[a + 1] == ',') { cls3[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls4[e] = light[a]; e++; if (light[a + 1] == ',') { cls4[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls5[e] = light[a]; e++; if (light[a + 1] == ',') { cls5[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls6[e] = light[a]; e++; if (light[a + 1] == ',') { cls6[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls7[e] = light[a]; e++; if (light[a + 1] == ',') { cls7[e] = 0; break; } } a += 2; e = 0;
	
	for (0;a<strlen(light);a++) { cls10[e] = light[a]; e++; if (light[a + 1] == ',') { cls10[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { how[e] = light[a]; e++; if (light[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; thm6 = atof(how);
	for (0;a<strlen(light);a++) { how[e] = light[a]; e++; if (light[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; thm7 = atof(how);

	for (0;a<strlen(light);a++) { cls8[e] = light[a]; e++; if (light[a + 1] == ',') { cls8[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls9[e] = light[a]; e++; if (light[a + 1] == ',') { cls9[e] = 0; break; } } a += 2; e = 0;

	for (0;a<strlen(light);a++) { how[e] = light[a]; e++; if (light[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; thm3 = atof(how);
	for (0;a<strlen(light);a++) { how[e] = light[a]; e++; if (light[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; thm8 = atof(how);
	for (0;a<strlen(light);a++) { how[e] = light[a]; e++; if (light[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; thm9 = atof(how);

	for (0;a<strlen(light);a++) { how[e] = light[a]; e++; if (light[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; thm5 = atof(how);
	for (0;a<strlen(light);a++) { cls11[e] = light[a]; e++; if (light[a + 1] == ',') { cls11[e] = 0; break; } } a += 2; e = 0;
	if(cls1[0]=='2'){
	for (0;a<strlen(light);a++) { cls12[e] = light[a]; e++; if (light[a + 1] == ',') { cls12[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls13[e] = light[a]; e++; if (light[a + 1] == ',') { cls13[e] = 0; break; } } a += 2; e = 0;
	}
	for (0;a<strlen(light);a++) { how[e] = light[a]; e++; if (light[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; free9=atoi(how);
	}
	else {
	for (0;a<strlen(light);a++) { cls2[e] = light[a]; e++; if (light[a + 1] == ',') { cls2[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls3[e] = light[a]; e++; if (light[a + 1] == ',') { cls3[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls4[e] = light[a]; e++; if (light[a + 1] == ',') { cls4[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { cls6[e] = light[a]; e++; if (light[a + 1] == ',') { cls6[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { how[e] = light[a]; e++; if (light[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; thm6 = atof(how);
	for (0;a<strlen(light);a++) { how[e] = light[a]; e++; if (light[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; thm7 = atof(how);
	for (0;a<strlen(light);a++) { cls5[e] = light[a]; e++; if (light[a + 1] == ',') { cls5[e] = 0; break; } } a += 2; e = 0;
	for (0;a<strlen(light);a++) { how[e] = light[a]; e++; if (light[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; thm5 = atof(how);
	for (0;a<strlen(light);a++) { cls7[e] = light[a]; e++; if (light[a + 1] == ',') { cls7[e] = 0; break; } } a += 2; e = 0;
	
	}
				break;
			}
			if (light[a] == ';') { b++; }
		}
		hf = CreateFont(17, 8, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 35, 30-pres[hover1], wx - 12, wy); DrawText(hgc, how1, -1, &rc, NULL);
		DeleteObject(hf);
		//directional lamp
		if(cls1[0]=='1'){ typz=0;
		hf = CreateFont(15, 7, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 35, 80-pres[hover1], wx - 12, wy); DrawText(hgc, "Position", -1, &rc, NULL);
		SetRect(&rc, 35, 120-pres[hover1], wx - 12, wy); DrawText(hgc, "Rotation", -1, &rc, NULL); 
		DeleteObject(hf);

		hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 10, 50-pres[hover1], wx - 12, wy); DrawText(hgc, "Type: Directional Lamp", -1, &rc, NULL); 
		SetRect(&rc, 10, 100-pres[hover1], wx - 12, wy); DrawText(hgc, "Z", -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 10, 100-pres[hover1], wx - 12, wy); DrawText(hgc, "Y", -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 10, 100-pres[hover1], wx - 12, wy); DrawText(hgc, "X", -1, &rc, NULL);

		SetRect(&rc, 10, 140-pres[hover1], wx - 12, wy); DrawText(hgc, "X", -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 10, 140-pres[hover1], wx - 12, wy); DrawText(hgc, "Y", -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 10, 140-pres[hover1], wx - 12, wy); DrawText(hgc, "Z", -1, &rc, NULL);

		SetRect(&rc, 10, 170-pres[hover1], wx - 12, wy); DrawText(hgc, "Color", -1, &rc, NULL);
		SetRect(&rc, 10, 200-pres[hover1], wx - 12, wy); DrawText(hgc, "Strength", -1, &rc, NULL);
		SetRect(&rc, 30, 220-pres[hover1], wx - 12, wy); DrawText(hgc, "Shadow", -1, &rc, NULL);
		SetRect(&rc, 10, 240-pres[hover1], wx - 12, wy); DrawText(hgc, "Shadow Color", -1, &rc, NULL);
		SetRect(&rc, 10, 270-pres[hover1], wx - 12, wy); DrawText(hgc, "Ambience", -1, &rc, NULL);
		SetRect(&rc, 30, 290-pres[hover1], wx - 12, wy); DrawText(hgc, "Specular", -1, &rc, NULL);
		DeleteObject(hf);

		
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO61"); DrawIcon(hgc, 5, 30-pres[hover1], hiu); DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO35"); DrawIcon(hgc, 5, 76-pres[hover1], hiu);  DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO36"); DrawIcon(hgc, 5, 120-pres[hover1], hiu);  DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO68"); DrawIcon(hgc, wx-38, 317-pres[hover1], hiu);  DeleteObject(hiu);

		brush = CreateSolidBrush(RGB(80, 80, 80)); SelectObject(hgc, brush);
		hp = CreatePen(PS_SOLID, 1, RGB(10, 10, 10)); SelectObject(hgc, hp);
		Rectangle(hgc, 19, 99-pres[hover1], (wx / 3) - 7+2, 114-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3), 99-pres[hover1], (wx / 3 * 2) - 7+2, 114-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3 * 2), 99-pres[hover1], wx - 12, 114-pres[hover1]+2);

		Rectangle(hgc, 19, 139-pres[hover1], (wx / 3) - 7+2, 154-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3), 139-pres[hover1], (wx / 3 * 2) - 7+2, 154-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3 * 2), 139-pres[hover1], wx - 12, 154-pres[hover1]+2);

		MoveToEx(hgc, 0, 163-pres[hover1], NULL); LineTo(hgc, wx, 163-pres[hover1]);

		Rectangle(hgc, 70 , 198-pres[hover1], wx - 12, 217-pres[hover1]);
		Rectangle(hgc, 70, 268-pres[hover1], wx - 12, 287-pres[hover1]);
		

		Rectangle(hgc, 10, 222-pres[hover1], 20, 232-pres[hover1]);
		Rectangle(hgc, 10, 292-pres[hover1], 20, 302-pres[hover1]);

		//light attachment
		MoveToEx(hgc, 0, 312-pres[hover1], NULL); LineTo(hgc, wx, 312-pres[hover1]);
		Rectangle(hgc, 10, 317-pres[hover1], wx-42, 332-pres[hover1]);

		DeleteObject(brush);
		brush = CreateSolidBrush(RGB(thm5*255, thm6*255,thm7*255)); SelectObject(hgc, brush);
		Rectangle(hgc,50,168-pres[hover1],70,188-pres[hover1]);
		DeleteObject(brush);

		brush = CreateSolidBrush(RGB(thm3 * 255, thm8 * 255, thm9 * 255)); SelectObject(hgc, brush);
		Rectangle(hgc, 100, 238-pres[hover1], 120, 258-pres[hover1]);
		DeleteObject(brush);
		
		brush = CreateSolidBrush(RGB(255,255,255)); SelectObject(hgc, brush);
		if (cls9[0] == '1') {
			Rectangle(hgc, 12, 224-pres[hover1], 18, 230-pres[hover1]);
		}
		if (cls11[0]=='1') {
			Rectangle(hgc, 12, 294-pres[hover1], 18, 300-pres[hover1]);
		}
		DeleteObject(brush);
		DeleteObject(hp);


		hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 25, 100-pres[hover1], wx / 3 - 7, wy); DrawText(hgc, cls2, -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 25, 100-pres[hover1], wx / 3 * 2 - 7, wy); DrawText(hgc, cls3, -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 25, 100-pres[hover1], wx - 12, wy); DrawText(hgc, cls4, -1, &rc, NULL);

		SetRect(&rc, 25, 140-pres[hover1], wx / 3 - 7, wy); DrawText(hgc, cls5, -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 25, 140-pres[hover1], wx / 3 * 2 - 7, wy); DrawText(hgc, cls6, -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 25, 140-pres[hover1], wx - 12, wy); DrawText(hgc, cls7, -1, &rc, NULL);

		SetRect(&rc, 75, 200-pres[hover1], wx-14, wy); DrawText(hgc, cls8, -1, &rc, NULL);
		SetRect(&rc, 75, 270-pres[hover1], wx - 14, wy); DrawText(hgc, cls10, -1, &rc, NULL);
		if(lip[lkik].x>=0){
		if(lip[lkik].y<0){ SetTextColor(hgc,RGB(0,255,0));
		for(int a=0,b=0,c=0;a<strlen(tree);a++){
		if(tree[a]=='\n'){ a++;} if(tree[a]=='\r'){ a++;}
		how3[b]=tree[a]; b++;
		if(tree[a]==':'){ c++; }
		if(c>lip[lkik].x){ how3[b-1]=0; break; }
		if(tree[a]==':'){ b=0;}
		if(tree[a]==';'){ b=0;}
		}
		}
		else{ SetTextColor(hgc,RGB(0,255,255));
		for(int a=0,b=0,c=0;a<strlen(tree);a++){
		if(tree[a]=='\n'){ a++;} if(tree[a]=='\r'){ a++;}
		if(tree[a]==':'){ c++; }
		if(c>lip[lkik].x){ c=0;
		for(0;a<strlen(tree);a++){
		how3[b]=tree[a]; b++;
		if(tree[a]==';'){ c++; }
		if(c>lip[lkik].y){ how3[b-1]=0; break; }
		if(tree[a]==':'){ b=0;}
		if(tree[a]==';'){ b=0;}
		}
		break;}

		}
		}
		
		SetRect(&rc, 15, 317-pres[hover1], wx - 44, wy); DrawText(hgc, how3, -1, &rc, NULL);
		}else{ SetRect(&rc, 15, 317-pres[hover1], wx - 44, wy); DrawText(hgc, "Self Control", -1, &rc, NULL); }
		bu=290+20;
		DeleteObject(hf);
		}

		//flashlight
		if(cls1[0]=='2'){ typz=1;
		hf = CreateFont(15, 7, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 35, 80-pres[hover1], wx - 12, wy); DrawText(hgc, "Position", -1, &rc, NULL);
		SetRect(&rc, 35, 120-pres[hover1], wx - 12, wy); DrawText(hgc, "Rotation", -1, &rc, NULL); 
		DeleteObject(hf);

		hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 10, 50-pres[hover1], wx - 12, wy); DrawText(hgc, "Type: Flashlight", -1, &rc, NULL); 
		SetRect(&rc, 10, 100-pres[hover1], wx - 12, wy); DrawText(hgc, "Z", -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 10, 100-pres[hover1], wx - 12, wy); DrawText(hgc, "Y", -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 10, 100-pres[hover1], wx - 12, wy); DrawText(hgc, "X", -1, &rc, NULL);

		SetRect(&rc, 10, 140-pres[hover1], wx - 12, wy); DrawText(hgc, "X", -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 10, 140-pres[hover1], wx - 12, wy); DrawText(hgc, "Y", -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 10, 140-pres[hover1], wx - 12, wy); DrawText(hgc, "Z", -1, &rc, NULL);

		SetRect(&rc, 10, 170-pres[hover1], wx - 12, wy); DrawText(hgc, "Color", -1, &rc, NULL);
		SetRect(&rc, 10, 200-pres[hover1], wx - 12, wy); DrawText(hgc, "Strength", -1, &rc, NULL);
		SetRect(&rc, 30, 220-pres[hover1], wx - 12, wy); DrawText(hgc, "Shadow", -1, &rc, NULL);
		SetRect(&rc, 10, 240-pres[hover1], wx - 12, wy); DrawText(hgc, "Shadow Color", -1, &rc, NULL);
		SetRect(&rc, 10, 270-pres[hover1], wx - 12, wy); DrawText(hgc, "Distance", -1, &rc, NULL);
		SetRect(&rc, 10, 290-pres[hover1], wx - 12, wy); DrawText(hgc, "Ambience", -1, &rc, NULL);
		SetRect(&rc, 10, 310-pres[hover1], wx - 12, wy); DrawText(hgc, "Angle", -1, &rc, NULL);
		SetRect(&rc, 30, 330-pres[hover1], wx - 12, wy); DrawText(hgc, "Soft Edges", -1, &rc, NULL);
		SetRect(&rc, 30, 350-pres[hover1], wx - 12, wy); DrawText(hgc, "Specular", -1, &rc, NULL);
		DeleteObject(hf);


		hiu = LoadIcon(GetModuleHandle(NULL), "ICO63"); DrawIcon(hgc, 5, 30-pres[hover1], hiu); DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO35"); DrawIcon(hgc, 5, 76-pres[hover1], hiu);  DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO36"); DrawIcon(hgc, 5, 120-pres[hover1], hiu);  DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO68"); DrawIcon(hgc, wx-38, 377-pres[hover1], hiu);  DeleteObject(hiu);

		brush = CreateSolidBrush(RGB(80, 80, 80)); SelectObject(hgc, brush);
		hp = CreatePen(PS_SOLID, 1, RGB(10, 10, 10)); SelectObject(hgc, hp);
		Rectangle(hgc, 19, 99-pres[hover1], (wx / 3) - 7+2, 114-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3), 99-pres[hover1], (wx / 3 * 2) - 7+2, 114-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3 * 2), 99-pres[hover1], wx - 12, 114-pres[hover1]+2);

		Rectangle(hgc, 19, 139-pres[hover1], (wx / 3) - 7+2, 154-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3), 139-pres[hover1], (wx / 3 * 2) - 7+2, 154-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3 * 2), 139-pres[hover1], wx - 12, 154-pres[hover1]+2);

		MoveToEx(hgc, 0, 163-pres[hover1], NULL); LineTo(hgc, wx, 163-pres[hover1]);

		Rectangle(hgc, 70 , 198-pres[hover1], wx - 12, 217-pres[hover1]);
		Rectangle(hgc, 70, 268-pres[hover1], wx - 12, 287-pres[hover1]);
		Rectangle(hgc, 70, 288-pres[hover1], wx - 12, 307-pres[hover1]);
		Rectangle(hgc, 70, 308-pres[hover1], wx - 12, 327-pres[hover1]);

		Rectangle(hgc, 10, 222-pres[hover1], 20, 232-pres[hover1]);
		Rectangle(hgc, 10, 332-pres[hover1], 20, 342-pres[hover1]);
		Rectangle(hgc, 10, 352-pres[hover1], 20, 362-pres[hover1]);

		//light attachment
		MoveToEx(hgc, 0, 372-pres[hover1], NULL); LineTo(hgc, wx, 372-pres[hover1]);
		Rectangle(hgc, 10, 377-pres[hover1], wx-42, 392-pres[hover1]);

		DeleteObject(brush);
		brush = CreateSolidBrush(RGB(thm5*255, thm6*255,thm7*255)); SelectObject(hgc, brush);
		Rectangle(hgc,50,168-pres[hover1],70,188-pres[hover1]);
		DeleteObject(brush);

		brush = CreateSolidBrush(RGB(thm3 * 255, thm8 * 255, thm9 * 255)); SelectObject(hgc, brush);
		Rectangle(hgc, 100, 238-pres[hover1], 120, 258-pres[hover1]);
		DeleteObject(brush);

		if (cls9[0] == '1') {
			brush = CreateSolidBrush(RGB(255,255,255)); SelectObject(hgc, brush);
			Rectangle(hgc, 12, 224-pres[hover1], 18, 230-pres[hover1]);
			DeleteObject(brush);
		}
		brush = CreateSolidBrush(RGB(255, 255, 255)); SelectObject(hgc, brush);
		if (cls13[0] == '1') {
			Rectangle(hgc, 12, 334-pres[hover1], 18, 340-pres[hover1]);
		}
		if (free9==1) {
			Rectangle(hgc, 12, 354-pres[hover1], 18, 360-pres[hover1]);
		}
		DeleteObject(brush);
		DeleteObject(hp);


		hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 25, 100-pres[hover1], wx / 3 - 7, wy); DrawText(hgc, cls2, -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 25, 100-pres[hover1], wx / 3 * 2 - 7, wy); DrawText(hgc, cls3, -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 25, 100-pres[hover1], wx - 12, wy); DrawText(hgc, cls4, -1, &rc, NULL);

		SetRect(&rc, 25, 140-pres[hover1], wx / 3 - 7, wy); DrawText(hgc, cls5, -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 25, 140-pres[hover1], wx / 3 * 2 - 7, wy); DrawText(hgc, cls6, -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 25, 140-pres[hover1], wx - 12, wy); DrawText(hgc, cls7, -1, &rc, NULL);

		SetRect(&rc, 75, 200-pres[hover1], wx-14, wy); DrawText(hgc, cls8, -1, &rc, NULL);
		SetRect(&rc, 75, 270-pres[hover1], wx - 14, wy); DrawText(hgc, cls10, -1, &rc, NULL);
		SetRect(&rc, 75, 290-pres[hover1], wx - 14, wy); DrawText(hgc, cls11, -1, &rc, NULL);
		SetRect(&rc, 75, 310-pres[hover1], wx - 14, wy); DrawText(hgc, cls12, -1, &rc, NULL);
		if(lip[lkik].x>=0){
		if(lip[lkik].y<0){ SetTextColor(hgc,RGB(0,255,0));
		for(int a=0,b=0,c=0;a<strlen(tree);a++){
		if(tree[a]=='\n'){ a++;} if(tree[a]=='\r'){ a++;}
		how3[b]=tree[a]; b++;
		if(tree[a]==':'){ c++; }
		if(c>lip[lkik].x){ how3[b-1]=0; break; }
		if(tree[a]==':'){ b=0;}
		if(tree[a]==';'){ b=0;}
		}
		}
		else{ SetTextColor(hgc,RGB(0,255,255));
		for(int a=0,b=0,c=0;a<strlen(tree);a++){
		if(tree[a]=='\n'){ a++;} if(tree[a]=='\r'){ a++;}
		if(tree[a]==':'){ c++; }
		if(c>lip[lkik].x){ c=0;
		for(0;a<strlen(tree);a++){
		how3[b]=tree[a]; b++;
		if(tree[a]==';'){ c++; }
		if(c>lip[lkik].y){ how3[b-1]=0; break; }
		if(tree[a]==':'){ b=0;}
		if(tree[a]==';'){ b=0;}
		}
		break;}

		}
		}
		
		SetRect(&rc, 15, 377-pres[hover1], wx - 44, wy); DrawText(hgc, how3, -1, &rc, NULL);
		}else{ SetRect(&rc, 15, 377-pres[hover1], wx - 44, wy); DrawText(hgc, "Self Control", -1, &rc, NULL); }

		bu=350+20;
		DeleteObject(hf);
		}
//point
//point lamp
		if(cls1[0]=='3'){ typz=2;
		hf = CreateFont(15, 7, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 35, 80-pres[hover1], wx - 12, wy); DrawText(hgc, "Position", -1, &rc, NULL);
		DeleteObject(hf);

		hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 10, 50-pres[hover1], wx - 12, wy); DrawText(hgc, "Type: Point Lamp", -1, &rc, NULL); 
		SetRect(&rc, 10, 100-pres[hover1], wx - 12, wy); DrawText(hgc, "Z", -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 10, 100-pres[hover1], wx - 12, wy); DrawText(hgc, "Y", -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 10, 100-pres[hover1], wx - 12, wy); DrawText(hgc, "X", -1, &rc, NULL);

		SetRect(&rc, 10, 140-pres[hover1], wx - 12, wy); DrawText(hgc, "Color", -1, &rc, NULL);
		SetRect(&rc, 10, 170-pres[hover1], wx - 12, wy); DrawText(hgc, "Strength", -1, &rc, NULL);
		SetRect(&rc, 10, 190-pres[hover1], wx - 12, wy); DrawText(hgc, "Distance", -1, &rc, NULL);
		SetRect(&rc, 10, 210-pres[hover1], wx - 12, wy); DrawText(hgc, "Ambience", -1, &rc, NULL);
		DeleteObject(hf);

		hiu = LoadIcon(GetModuleHandle(NULL), "ICO62"); DrawIcon(hgc, 5, 30-pres[hover1], hiu); DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO35"); DrawIcon(hgc, 5, 76-pres[hover1], hiu);  DeleteObject(hiu);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO68"); DrawIcon(hgc, wx-38, 252-pres[hover1], hiu);  DeleteObject(hiu);

		brush = CreateSolidBrush(RGB(80, 80, 80)); SelectObject(hgc, brush);
		hp = CreatePen(PS_SOLID, 1, RGB(10, 10, 10)); SelectObject(hgc, hp);
		Rectangle(hgc, 19, 99-pres[hover1], (wx / 3) - 7+2, 114-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3), 99-pres[hover1], (wx / 3 * 2) - 7+2, 114-pres[hover1]+2);
		Rectangle(hgc, 19 + (wx / 3 * 2), 99-pres[hover1], wx - 12, 114-pres[hover1]+2);


		MoveToEx(hgc, 0, 130-pres[hover1], NULL); LineTo(hgc, wx, 130-pres[hover1]);

		Rectangle(hgc, 70 ,168-pres[hover1], wx - 12, 187-pres[hover1]);
		Rectangle(hgc, 70, 188-pres[hover1], wx - 12, 207-pres[hover1]);
		Rectangle(hgc, 70, 208-pres[hover1], wx - 12, 227-pres[hover1]);

		//light attachment
		MoveToEx(hgc, 0, 247-pres[hover1], NULL); LineTo(hgc, wx, 247-pres[hover1]);
		Rectangle(hgc, 10, 252-pres[hover1], wx-42, 267-pres[hover1]);

		DeleteObject(brush);
		brush = CreateSolidBrush(RGB(thm5*255, thm6*255,thm7*255)); SelectObject(hgc, brush);
		Rectangle(hgc,50,138-pres[hover1],70,158-pres[hover1]);
		DeleteObject(brush);

		DeleteObject(hp);


		hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		SetRect(&rc, 25, 100-pres[hover1], wx / 3 - 7, wy); DrawText(hgc, cls2, -1, &rc, NULL);
		SetRect(&rc, wx / 3 + 25, 100-pres[hover1], wx / 3 * 2 - 7, wy); DrawText(hgc, cls3, -1, &rc, NULL);
		SetRect(&rc, wx / 3 * 2 + 25, 100-pres[hover1], wx - 12, wy); DrawText(hgc, cls4, -1, &rc, NULL);

		SetRect(&rc, 75, 170-pres[hover1], wx-14, wy); DrawText(hgc, cls5, -1, &rc, NULL);
		SetRect(&rc, 75, 190-pres[hover1], wx - 14, wy); DrawText(hgc, cls6, -1, &rc, NULL);
		SetRect(&rc, 75, 210-pres[hover1], wx - 14, wy); DrawText(hgc, cls7, -1, &rc, NULL);
		if(lip[lkik].x>=0){
		if(lip[lkik].y<0){ SetTextColor(hgc,RGB(0,255,0));
		for(int a=0,b=0,c=0;a<strlen(tree);a++){
		if(tree[a]=='\n'){ a++;} if(tree[a]=='\r'){ a++;}
		how3[b]=tree[a]; b++;
		if(tree[a]==':'){ c++; }
		if(c>lip[lkik].x){ how3[b-1]=0; break; }
		if(tree[a]==':'){ b=0;}
		if(tree[a]==';'){ b=0;}
		}
		}
		else{ SetTextColor(hgc,RGB(0,255,255));
		for(int a=0,b=0,c=0;a<strlen(tree);a++){
		if(tree[a]=='\n'){ a++;} if(tree[a]=='\r'){ a++;}
		if(tree[a]==':'){ c++; }
		if(c>lip[lkik].x){ c=0;
		for(0;a<strlen(tree);a++){
		how3[b]=tree[a]; b++;
		if(tree[a]==';'){ c++; }
		if(c>lip[lkik].y){ how3[b-1]=0; break; }
		if(tree[a]==':'){ b=0;}
		if(tree[a]==';'){ b=0;}
		}
		break;}

		}
		}
		
		SetRect(&rc, 15, 252-pres[hover1], wx - 44, wy); DrawText(hgc, how3, -1, &rc, NULL);
		}else{ SetRect(&rc, 15, 252-pres[hover1], wx - 44, wy); DrawText(hgc, "Self Control", -1, &rc, NULL); }

		bu=230+20;
		DeleteObject(hf);
		}


	}
}