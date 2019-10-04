void peloscope() {
	free5=0;
	loc = glGetUniformLocation(shaderProgram, "mear"); glUniform1f(loc, 0.1);
	
	if(bright[hover1]==0){ loc=glGetUniformLocation(shaderProgram,"bright"); glUniform1f(loc,10.0f);}
	else{ loc = glGetUniformLocation(shaderProgram, "bright"); glUniform1f(loc, environment); loc = glGetUniformLocation(shaderProgram, "bright1"); glUniform1f(loc, environment1);}


	loc = glGetUniformLocation(shaderProgram, "shad"); glUniform1f(loc, 0.0f);
	glViewport(0, 0, handy[1], handy[2]);
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	glClearColor(mcolor.x, mcolor.y, mcolor.z, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	ratio = handy[1]; ratio /= handy[2];
	if(handy[1]>handy[2]){ thm3=1; thm4=handy[2]/handy[1]; }
	else{ thm3=handy[1]/handy[2]; thm4=1; }
	loc=glGetUniformLocation(shaderProgram,"ratio");
	glUniform2f(loc,thm3,thm4);

	can1 = cos(3.143 -metion1+3.14); san1 = sin(3.143-metion1+3.14);
	can2 = cos(-metion2); san2 = sin(-metion2);
	can3 = cos(metion3+3.143); san3 = sin(metion3+3.143);

	glActiveTexture(GL_TEXTURE0);
	if (mox == 2) {
		//skybox
		for (int a = 0;a < 240;a++) {
			xx = ski[a + 2]; yy = ski[a + 1];  zz = ski[a];
			//x
			xx1 = xx; yy1 = (yy*can1) - (zz*san1); zz1 = (yy*san1) + (zz*can1);
			//y
			xx = (xx1*can2) + (zz1*san2); yy = yy1; zz = (xx1*-1 * san2) + (zz1*can2);
			//z
			xx1 = (xx*can3) - (yy*san3); yy1 = (xx*san3) + (yy*can3); zz1 = zz;
			if (zz1 < 0) { zz1 = 0; }
			if ((handy[1]) >handy[0]) { yy1 *= ratio; }
			else { xx1 /= ratio; }
			vertices[a] = xx1; vertices[a + 1] = yy1; vertices[a + 2] = zz1;
			vertices[a + 3] = ski[a + 6]; vertices[a + 4] = ski[a + 7]; vertices[a + 5] = ski[a + 5];
			vertices[a + 6] = ski[a + 3]; vertices[a + 7] = ski[a + 4];
			a += 7;
		}
		glBufferData(GL_ARRAY_BUFFER, sizeof(ski), vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
		glEnableVertexAttribArray(2);

		loc = glGetUniformLocation(shaderProgram, "check");
		glUniform1f(loc, 2.0f);
		loc = glGetUniformLocation(shaderProgram, "jade");
		glUniform1f(loc, 1.0f);

		glBindTexture(GL_TEXTURE_2D, sky1);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawArrays(GL_TRIANGLES, 2, 3);
		glBindTexture(GL_TEXTURE_2D, sky2);
		glDrawArrays(GL_TRIANGLES, 5, 3);
		glDrawArrays(GL_TRIANGLES, 7, 3);
		glBindTexture(GL_TEXTURE_2D, sky3);
		glDrawArrays(GL_TRIANGLES, 10, 3);
		glDrawArrays(GL_TRIANGLES, 12, 3);
		glBindTexture(GL_TEXTURE_2D, sky4);
		glDrawArrays(GL_TRIANGLES, 15, 3);
		glDrawArrays(GL_TRIANGLES, 17, 3);
		glBindTexture(GL_TEXTURE_2D, sky5);
		glDrawArrays(GL_TRIANGLES, 20, 3);
		glDrawArrays(GL_TRIANGLES, 22, 3);
		glBindTexture(GL_TEXTURE_2D, sky6);
		glDrawArrays(GL_TRIANGLES, 25, 3);
		glDrawArrays(GL_TRIANGLES, 27, 3);
		glClear(GL_DEPTH_BUFFER_BIT);
	}

	can1 = cos(-(metion1+3.143)); san1 = sin(-(metion1 + 3.143));
	can2 = cos(metion2); san2 = sin(metion2);
	can3 = cos(metion3+3.143); san3 = sin(metion3+3.143 );

	loc = glGetUniformLocation(shaderProgram, "jade");
	glUniform1f(loc, 2.0f);
	if (mox == 1) {
		//SPRITE
		glBufferData(GL_ARRAY_BUFFER, sizeof(spri), spri, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(2);

		loc = glGetUniformLocation(shaderProgram, "check");
		glUniform1f(loc, 2.0f);

		glBindTexture(GL_TEXTURE_2D, texture);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawArrays(GL_TRIANGLES, 2, 3);
		glClear(GL_DEPTH_BUFFER_BIT);
	}

	lamp1();

	//depthmap
{
	for(int a=0;a<free5;a++){
	if(a==0){ glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, depthMap[0]);
	glUniform1i(glGetUniformLocation(shaderProgram, "depth1"), 2);
	}
	if(a==1){ glActiveTexture(GL_TEXTURE3); 
	glBindTexture(GL_TEXTURE_2D, depthMap[1]);
	glUniform1i(glGetUniformLocation(shaderProgram, "depth2"), 3);
	}
	if(a==2){ glActiveTexture(GL_TEXTURE4); 
	glBindTexture(GL_TEXTURE_2D, depthMap[2]);
	glUniform1i(glGetUniformLocation(shaderProgram, "depth3"), 4);
	}
	if(a==3){ glActiveTexture(GL_TEXTURE5); 
	glBindTexture(GL_TEXTURE_2D, depthMap[3]);
	glUniform1i(glGetUniformLocation(shaderProgram, "depth4"), 5);
	}
	if(a==4){ glActiveTexture(GL_TEXTURE6); 
	glBindTexture(GL_TEXTURE_2D, depthMap[4]);
	glUniform1i(glGetUniformLocation(shaderProgram, "depth5"), 6);
	}
	if(a==5){ glActiveTexture(GL_TEXTURE7); 
	glBindTexture(GL_TEXTURE_2D, depthMap[5]);
	glUniform1i(glGetUniformLocation(shaderProgram, "depth6"), 7);
	}
	if(a==6){ glActiveTexture(GL_TEXTURE8); 
	glBindTexture(GL_TEXTURE_2D, depthMap[6]);
	glUniform1i(glGetUniformLocation(shaderProgram, "depth7"), 8);
	}
	if(a==7){ glActiveTexture(GL_TEXTURE9); 
	glBindTexture(GL_TEXTURE_2D, depthMap[7]);
	glUniform1i(glGetUniformLocation(shaderProgram, "depth8"), 9);
	}
	if(a==8){ glActiveTexture(GL_TEXTURE10); 
	glBindTexture(GL_TEXTURE_2D, depthMap[8]);
	glUniform1i(glGetUniformLocation(shaderProgram, "depth9"), 10);
	}
	if(a==9){ glActiveTexture(GL_TEXTURE11); 
	glBindTexture(GL_TEXTURE_2D, depthMap[9]);
	glUniform1i(glGetUniformLocation(shaderProgram, "depth10"), 11);
	}
	if(a==10){ glActiveTexture(GL_TEXTURE12); 
	glBindTexture(GL_TEXTURE_2D, depthMap[10]);
	glUniform1i(glGetUniformLocation(shaderProgram, "depth11"), 12);
	}
	if(a==11){ glActiveTexture(GL_TEXTURE13); 
	glBindTexture(GL_TEXTURE_2D, depthMap[11]);
	glUniform1i(glGetUniformLocation(shaderProgram, "depth12"), 13);
	}
	if(a==12){ glActiveTexture(GL_TEXTURE14); 
	glBindTexture(GL_TEXTURE_2D, depthMap[12]);
	glUniform1i(glGetUniformLocation(shaderProgram, "depth13"), 14);
	}
	}
	//end depth
	}

	loc = glGetUniformLocation(shaderProgram, "chan"); glUniform3f(loc, can1, can2, can3);
	loc = glGetUniformLocation(shaderProgram, "shan"); glUniform3f(loc, san1, san2, san3);
	

	glEnable(GL_BLEND);
	glEnable(GL_PROGRAM_POINT_SIZE);
	loc = glGetUniformLocation(shaderProgram, "jade"); glUniform1f(loc, 1.0f);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	loc = glGetUniformLocation(shaderProgram, "check");
	glUniform1f(loc, 1.0f);
	//real drawing
	if (wireframe[hover1] == 1) { glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); }
	else { glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); }

//object drawing postion

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDisable(GL_DEPTH_TEST);
		if (bright[hover1] != 0) {
		glBindFramebuffer(GL_FRAMEBUFFER, hdr);
		//hdr rendering
		screen[8] = (handy[1]) / 1500.0;
		screen[13] = (handy[1]) / 1500.0; screen[14] = (handy[2]) / 1500.0;
		screen[19] = (handy[2]) / 1500.0;

		glDisable(GL_BLEND);
		loc = glGetUniformLocation(shaderProgram, "jade");
		glUniform1f(loc, 2.0f);
		//SPRITE
		glBufferData(GL_ARRAY_BUFFER, sizeof(screen), screen, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);

		loc = glGetUniformLocation(shaderProgram, "check");
		glUniform1f(loc, 12.0f);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawArrays(GL_TRIANGLES, 2, 3);
	}
	
	glReadBuffer(GL_COLOR_ATTACHMENT0);
	glReadPixels(0, 0, handy[1], handy[2], GL_RGBA, GL_UNSIGNED_BYTE, read);
}

void telescope() {
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


	SetTextColor(hgc, RGB(255, 255, 255));
	SetBkMode(hgc, TRANSPARENT);

	hbc = CreateCompatibleDC(hdc);
	SelectObject(hbc, sefari);
	ou=2; bu=20;
	for (0;ou<wx-2;ou+=997){
	BitBlt(hgc, ou, bu, 997, 887, hbc, 0, 0, SRCCOPY);
	} bu+=997;
	for (0;bu<wy - 21;bu += 997) {
		BitBlt(hgc, ou, bu, 997, 887, hbc, 0, 0, SRCCOPY);
	}
	DeleteDC(hbc);

	if(jlik>=0){
		
		for (int a = 0, b = 0, e = 0;a < strlen(camera);a++) {
			if (b >= jlik) {
				for (0;a<strlen(camera);a++) { how1[e] = camera[a]; e++; if (camera[a + 1] == ':') { how1[e] = 0; break; } } a += 2; e = 0;
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

				for (0;a<strlen(camera);a++) { how[e] = camera[a]; e++; if (camera[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; thm5 = atof(how);
				for (0;a<strlen(camera);a++) { how[e] = camera[a]; e++; if (camera[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; metio5 = atof(how);
				for (0;a<strlen(camera);a++) { how[e] = camera[a]; e++; if (camera[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; thm7 = atof(how);

				for (0;a<strlen(camera);a++) { cls12[e] = camera[a]; e++; if (camera[a + 1] == ',') { cls12[e] = 0; break; } } a += 2; e = 0;
				for (0;a<strlen(camera);a++) { cls13[e] = camera[a]; e++; if (camera[a + 1] == ',') { cls13[e] = 0; break; } } a += 2; e = 0;

				for (0;a<strlen(camera);a++) { how[e] = camera[a]; e++; if (camera[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; mcolor.z = atof(how)/255.0;
				for (0;a<strlen(camera);a++) { how[e] = camera[a]; e++; if (camera[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; mcolor.y = atof(how)/255.0;
				for (0;a<strlen(camera);a++) { how[e] = camera[a]; e++; if (camera[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; mcolor.x = atof(how)/255.0;

				for (0;a<strlen(camera);a++) { how[e] = camera[a]; e++; if (camera[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; thm2 = atof(how);
				for (0;a<strlen(camera);a++) { how[e] = camera[a]; e++; if (camera[a + 1] == ',') { how[e] = 0; break; } } a += 2; e = 0; metio4 = atof(how);

				break;
			}
			if (camera[a] == ';') { b++; }
		}
		metio6=atof(cls11);
		mox = thm2; mefar = atof(cls7); menear=atof(cls8);
		metio1=-1*atof(cls1); metio2 = -1*atof(cls2); metio3 = -1*atof(cls3);
		metion1 = atof(cls4)/180.0*3.143; metion2 = atof(cls5)/180.0*3.143; metion3 = atof(cls6)/180.0*3.143;
		
		metio = atof(cls9);
		handy[0] =  atof(cls10);
		handy[3]=metio/handy[0];
		if(metio>handy[0]){ handy[1]=wx-2; handy[2]=(wx-2)/handy[3]; if(handy[2]>wy-21){ handy[2]=wy-21; handy[1]=(wy-21)*handy[3]; } }
		else{ handy[1]= (wy - 21)*handy[3]; handy[2]=(wy-21); if(handy[1]>wx-2){ handy[1]=wx-2; handy[2]=(wx-2)/handy[3]; } }
	peloscope();

	hbc = CreateCompatibleDC(hdc);
	hbm = CreateCompatibleBitmap(hdc, handy[1], handy[2]);
	SelectObject(hbc, hbm);
	SetBitmapBits(hbm, handy[1]*handy[2] * 4, &read);
	BitBlt(hgc, ((wx-1)/2-(handy[1]/2.0) )+1, ((wy-21)/2-(handy[2]/2.0) )+20, handy[1], handy[2], hbc, 0, 0, SRCCOPY);
	DeleteDC(hbc);
	DeleteObject(hbm);
	}
	else {
		hf = CreateFont(20, 9, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
		SelectObject(hgc, hf);
		hiu = LoadIcon(GetModuleHandle(NULL), "ICO42"); DrawIcon(hgc, wx/2-107, wy/2-9, hiu);  DeleteObject(hiu);
		TextOut(hgc, wx/2-77, wy/2-9, "No Active Camera", 17);
		DeleteObject(hf);
	}

	if (bright[hover1] == 1) {
		SetRect(&rc, 104, 1, 123, 19);
		brush = CreateSolidBrush(RGB(50, 50, 50));
		FillRect(hgc, &rc, brush);
		DeleteObject(brush);
	}

	SetRect(&rc, 0, 0, 20, 19);
	if (hover == hover1) { brush = CreateSolidBrush(RGB(100, 100, 200)); }
	else { brush = CreateSolidBrush(RGB(50, 50, 50)); }
	FillRect(hgc, &rc, brush);
	DeleteObject(brush);

	hiu = LoadIcon(GetModuleHandle(NULL), "ICO41");
	DrawIcon(hgc, 2, 3, hiu);  DeleteObject(hiu);
	hiu = LoadIcon(GetModuleHandle(NULL), "ICO64"); DrawIcon(hgc, 105, 1, hiu); DeleteObject(hiu);

	hf = CreateFont(14, 6, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, DEFAULT_GUI_FONT, "ARIAL");
	SelectObject(hgc, hf);
	
	TextOut(hgc, 30, 3, "Camera", 7);

	DeleteObject(hf);

	BitBlt(hdc, stx, sty, wx, wy, hgc, 0, 0, SRCCOPY);
	DeleteDC(hgc);
	DeleteObject(hgm);
	}
}