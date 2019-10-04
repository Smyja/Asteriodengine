void shading() {
	glfwPollEvents();
	glViewport(0, 0, wx-4, 150);
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	bu = matprop[mlik][manon].Kd;
	glClearColor(0.2, 0.2, 0.2, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);
	loc=glGetUniformLocation(shaderProgram,"bright"); glUniform1f(loc,10.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	ratio = wx-4; ratio /= 150;

	quadri[14]=(wx-4)/997.0; quadri[22] = (wx - 4)/997.0;
	//SPRITE
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadri), quadri, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	loc = glGetUniformLocation(shaderProgram, "check");
	glUniform1f(loc, 2.0f);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, black);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawArrays(GL_TRIANGLES, 2, 3);

	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);
	can1 = cos(mng1[hover1]); san1 = sin(mng1[hover1]);
	can2 = cos(mng2[hover1]); san2 = sin(mng2[hover1]);
	can3 = cos(mng3[hover1]); san3 = sin(mng3[hover1]);

	loc = glGetUniformLocation(shaderProgram, "chan"); glUniform3f(loc, can1, can2, can3);
	loc = glGetUniformLocation(shaderProgram, "shan"); glUniform3f(loc, san1, san2, san3);

	for (int a = 0,b=0;a < bull;a++,b++) { 
		xx = square[a + 2]; yy = square[a + 1];  zz = square[a];
		
		//x
		xx1 = xx; yy1 = (yy*can1) - (zz*san1); zz1 = (yy*san1) + (zz*can1);
		//y
		xx = (xx1*can2) + (zz1*san2); yy = yy1; zz = (xx1*-1 * san2) + (zz1*can2);
		//z
		xx1 = (xx*can3) - (yy*san3); yy1 = (xx*san3) + (yy*can3); zz1 = zz;
		{ xx1 /= ratio; }
		vertices[b] = xx1; vertices[b + 1] = yy1; vertices[b + 2] = zz1 / 10;
		
		vertices[b + 3] = square[a + 4]; vertices[b + 4] = square[a + 5];

		//normals
		xx = square[a + 8]; yy = square[a + 7];  zz = square[a + 6];
		//x
		xx1 = xx; yy1 = (yy*can1) - (zz*san1); zz1 = (yy*san1) + (zz*can1);
		//y
		xx = (xx1*can2) + (zz1*san2); yy = yy1; zz = (xx1*-1 * san2) + (zz1*can2);
		//z
		xx1 = (xx*can3) - (yy*san3); yy1 = (xx*san3) + (yy*can3); zz1 = zz;

		{ xx1 /= ratio; }

		vertices[b + 5] = xx1; vertices[b + 6] = yy1; vertices[b + 7] = zz1;
		
		b += 7; a += 8;
	}
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	
	
	if (matprop[mlik][manon].shade==1) { loc = glGetUniformLocation(shaderProgram, "cade"); glUniform1f(loc, 0.0f); }
	else{ loc = glGetUniformLocation(shaderProgram, "cade"); glUniform1f(loc, 1.0f); }

	loc = glGetUniformLocation(shaderProgram, "seet");
	glUniform1f(loc, matprop[mlik][manon].Tr);
	loc = glGetUniformLocation(shaderProgram, "ecat");
	glUniform3f(loc, colr[mlik][bu].z, colr[mlik][bu].y, colr[mlik][bu].x);
	glUniform2f(glGetUniformLocation(shaderProgram, "emit"), matprop[mlik][manon].emit, 0);
	free7=mlik;
	bu=manon;
	//normal specular strength
	glUniform4f(glGetUniformLocation(shaderProgram, "properties"), matprop[free7][bu].NSI, matprop[free7][bu].emr, matprop[free7][bu].emg, matprop[free7][bu].emb);
	//reflection 
	glUniform4f(glGetUniformLocation(shaderProgram, "properties2"), matprop[free7][bu].rfls, matprop[free7][bu].rfi, matprop[free7][bu].rfk, matprop[free7][bu].rfmap);

	//emission
	if (matprop[free7][bu].emK == 1) {
		glActiveTexture(GL_TEXTURE16);
		ou = matprop[free7][bu].emmap; glBindTexture(GL_TEXTURE_2D, diffuse[free7][ou]);
		glUniform1i(glGetUniformLocation(shaderProgram, "emiss"), 16);
	}
	glUniform1f(glGetUniformLocation(shaderProgram, "gi"), matprop[free7][bu].emK);

	//reflection map
	if (matprop[free7][bu].rfk == 1 && wireframe[hover1] == 0) {
		glActiveTexture(GL_TEXTURE14);
		ou = matprop[free7][bu].rfmap; glBindTexture(GL_TEXTURE_2D, diffuse[free7][ou]);
		glUniform1i(glGetUniformLocation(shaderProgram, "reflection"), 16);
	}
	glUniform1f(glGetUniformLocation(shaderProgram, "ri"), matprop[free7][bu].rfk);
	//emission map
	if (matprop[free7][bu].emmap<0 && matprop[free7][bu].emt == 3) {
		glUniform4f(glGetUniformLocation(shaderProgram, "emty"), 1, matprop[free7][bu].emr, matprop[free7][bu].emg, matprop[free7][bu].emb);
	}
	else { glUniform4f(glGetUniformLocation(shaderProgram, "emty"), matprop[free7][bu].emt, matprop[free7][bu].emr, matprop[free7][bu].emg, matprop[free7][bu].emb); }

	if (matprop[free7][bu].emmap >= 0 && matprop[free7][bu].emt == 3 && wireframe[hover1] == 0) {
		glActiveTexture(GL_TEXTURE12);
		ou = matprop[free7][bu].emmap; glBindTexture(GL_TEXTURE_2D, diffuse[free7][ou]);
		glUniform1i(glGetUniformLocation(shaderProgram, "emmap"), 12);
	}

	if (matprop[mlik][manon].bum == 1 ) {
		glActiveTexture(GL_TEXTURE1);
		ou = matprop[mlik][manon].bump; glBindTexture(GL_TEXTURE_2D, diffuse[mlik][ou]);
		glUniform1i(glGetUniformLocation(shaderProgram, "ourTexture2"), 1);
	}
	glUniform2f(glGetUniformLocation(shaderProgram, "hi"), matprop[mlik][manon].bum,matprop[mlik][manon].NORS);
	
	if (matprop[mlik][manon].text == 1) {
		glActiveTexture(GL_TEXTURE0);
		ou = matprop[mlik][manon].tex;  glBindTexture(GL_TEXTURE_2D, diffuse[mlik][ou]);
		glUniform1i(glGetUniformLocation(shaderProgram, "ourTexture"), 0);
		loc = glGetUniformLocation(shaderProgram, "check");
		glUniform1f(loc, 7.0f);
	}
	else {
		loc = glGetUniformLocation(shaderProgram, "check");
		glUniform1f(loc, 6.0f);
	}

	glDrawArrays(GL_TRIANGLES, 0, (bull/9.0));

	glReadBuffer(GL_COLOR_ATTACHMENT0);
	glReadPixels(0, 0, wx-4, 150, GL_RGBA, GL_UNSIGNED_BYTE, read);
}


void edicek(){
thm1=atof(how3);
if(editcrea==1){
if(mlik>=0&&fclick<0){ mauv[mlik].x=thm1-px; } 
if(mlik>=0&&fclick>=0){ gauv[fclick][mlik].x=thm1-px-mauv[mlik].x; } 
}
if(editcrea==2){
if(mlik>=0&&fclick<0){ mauv[mlik].y=thm1-py; } 
if(mlik>=0&&fclick>=0){ gauv[fclick][mlik].y=thm1-py-mauv[mlik].y; } 
}
if(editcrea==3){
if(mlik>=0&&fclick<0){ mauv[mlik].z=thm1-pz; } 
if(mlik>=0&&fclick>=0){ gauv[fclick][mlik].z=thm1-pz-mauv[mlik].z; } 
}
//rotation
if(editcrea==4){
if(mlik>=0&&fclick<0){ rita[mlik].x=thm1; } 
if(mlik>=0&&fclick>=0){ rota[fclick][mlik].x=thm1; } 
}
if(editcrea==5){
if(mlik>=0&&fclick<0){ rita[mlik].y=thm1; } 
if(mlik>=0&&fclick>=0){ rota[fclick][mlik].y=thm1; } 
}
if(editcrea==6){
if(mlik>=0&&fclick<0){ rita[mlik].z=thm1; } 
if(mlik>=0&&fclick>=0){ rota[fclick][mlik].z=thm1; } 
}
//scale
if(editcrea==7){
if(mlik>=0&&fclick<0){ scil[mlik].x=thm1; } 
if(mlik>=0&&fclick>=0){ scal[fclick][mlik].x=thm1; }
}
if(editcrea==8){
if(mlik>=0&&fclick<0){ scil[mlik].y=thm1; }
if(mlik>=0&&fclick>=0){ scal[fclick][mlik].y=thm1; }
}
if(editcrea==9){
if(mlik>=0&&fclick<0){ scil[mlik].z=thm1; }
if(mlik>=0&&fclick>=0){ scal[fclick][mlik].z=thm1; }
}

if(lkik>=0){
int a=0,b=0; 
for(a=0;a<hstp;a++){ bit[a]=light[a]; }
bit[a]=0; b=hcnp;
sprintf(bit,"%s%s,",bit,how3);
for(a=strlen(bit);b<strlen(light);0){ bit[a]=light[b]; b++; a++; }
bit[a]=0;
b=strlen(bit);
for(a=0;a<strlen(bit);a++){ light[a]=bit[a]; }
light[a]=0;
}
//camera
if(jlik>=0){
int a=0,b=0; 
for(a=0;a<hstp;a++){ bit[a]=camera[a]; }
bit[a]=0; b=hcnp;
sprintf(bit,"%s%s,",bit,how3);
for(a=strlen(bit);b<strlen(camera);0){ bit[a]= camera[b]; b++; a++; }
bit[a]=0;
b=strlen(bit);
for(a=0;a<strlen(bit);a++){ camera[a]=bit[a]; }
camera[a]=0;
}

if(layout==1){ thm1=5;} if(layout==2){ thm1=6;} if(layout==3){ thm1=2;} if(layout==4){ thm1=2;} if(layout==5){ thm1=3;} if(layout==6){ thm1=3;}
if(layout==7){ thm1=3;} if(layout==8){ thm1=4;} if(layout==9){ thm1=3;} if(layout==10){ thm1=4;} if(layout==11){ thm1=3;} if(layout==12){ thm1=4;} if(layout==13){ thm1=5;}
for(int a=0;a<thm1;a++){
if (layout != 10&&layout!=12) { if (a == 1) { ou = scrn1; }if (a == 2) { ou = scrn2; }if (a == 3) { ou = scrn3; }if (a == 4) { ou = scrn4; }if (a == 5) { ou = scrn5; }if (a == 6) { ou = scrn6; } }
if(layout==10){ if (a == 4) { ou = scrn1; }if (a ==1) { ou = scrn2; }if (a == 2) { ou = scrn3; }if (a == 3) { ou = scrn4; } }
if (layout == 12) { if (a == 2) { ou = scrn1; }if (a == 3) { ou = scrn2; }if (a == 4) { ou = scrn3; }if (a == 1) { ou = scrn4; } }

if(ou==2||ou==6){
SetRect(&rc,winx[a],winy[a],winx[a]+winwx[a],winy[a]+winwy[a]);
ValidateRect(hwnd,&rc); InvalidateRect(hwnd,&rc,TRUE);
}
}



}