void ship() {
	free5=0;
	proj=glm::perspective((float)45.0f,(float)(1500.0/1500.0),(float)0.1f,(float)1000.0f);
	loc = glGetUniformLocation(shaderProgram, "projection"); glUniformMatrix4fv(loc,1,GL_FALSE,glm::value_ptr(proj));
	glfwPollEvents();
	loc = glGetUniformLocation(shaderProgram, "mear"); glUniform1f(loc, 0.1);
	if(project[hover1]==0){ loc=glGetUniformLocation(shaderProgram,"drange"); glUniform1f(loc,1.0f);}
	else{  loc=glGetUniformLocation(shaderProgram,"drange"); glUniform1f(loc,0.0f); }
	if(bright[hover1]==0){ loc=glGetUniformLocation(shaderProgram,"bright"); glUniform1f(loc,10.0f);}
	else{ loc = glGetUniformLocation(shaderProgram, "bright"); glUniform1f(loc, environment); loc = glGetUniformLocation(shaderProgram, "bright1"); glUniform1f(loc, environment1);}
	loc = glGetUniformLocation(shaderProgram, "shad"); glUniform1f(loc, 0.0f);
	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
	glViewport(0, 0, wx - 2, wy - 21);
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	ratio = (wx - 2); ratio /= (wy - 21);

	if ((wx - 2) >(wy - 21)) { thm3=1; thm4=ratio; }
	else { thm3=1/ratio; thm4=1; }
	loc=glGetUniformLocation(shaderProgram,"ratio");
	glUniform2f(loc,thm3,thm4);

	can1 = cos(-ang1[hover1]); san1 = sin(-ang1[hover1]);
	can2 = cos(-ang2[hover1]); san2 = sin(-ang2[hover1]);
	can3 = cos(ang3[hover1]); san3 = sin(ang3[hover1]);

	glActiveTexture(GL_TEXTURE0);
if (box[hover1] == 2) {
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
		if ((wx - 2) >(wy - 21)) { yy1 *= ratio; }
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
	glClear( GL_DEPTH_BUFFER_BIT);
}

	loc = glGetUniformLocation(shaderProgram, "jade");
	glUniform1f(loc, 2.0f);
	if (box[hover1] == 1) {
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

		glBindTexture(GL_TEXTURE_2D, depthMap[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawArrays(GL_TRIANGLES, 2, 3);
		glClear(GL_DEPTH_BUFFER_BIT);
	}
	glEnable(GL_DEPTH_TEST);
	loc = glGetUniformLocation(shaderProgram, "mxh"); glUniform3f(loc,mx[hover1],my[hover1],mz[hover1]);
	loc = glGetUniformLocation(shaderProgram, "zoom"); glUniform1f(loc, zoom[hover1]);
	loc = glGetUniformLocation(shaderProgram, "chan"); glUniform3f(loc, can1, can2, can3);
	loc = glGetUniformLocation(shaderProgram, "shan"); glUniform3f(loc, san1, san2, san3);
	loc = glGetUniformLocation(shaderProgram, "find"); glUniform1i(loc, 2);
	cameras();
	lamp();
	
	loc = glGetUniformLocation(shaderProgram, "find"); glUniform1i(loc, 1);
	loc = glGetUniformLocation(shaderProgram, "scal"); glUniform3f(loc, 1, 1, 1);
	loc = glGetUniformLocation(shaderProgram, "scil"); glUniform3f(loc, 1, 1, 1);
	loc = glGetUniformLocation(shaderProgram, "gauv"); glUniform3f(loc, 0,0,0);
	loc = glGetUniformLocation(shaderProgram, "mauv"); glUniform3f(loc, 0, 0, 0);
	loc = glGetUniformLocation(shaderProgram, "rota"); glUniform3f(loc, 1, 1, 1);
	loc = glGetUniformLocation(shaderProgram, "rota1"); glUniform3f(loc, 0, 0, 0);
	loc = glGetUniformLocation(shaderProgram, "mota"); glUniform3f(loc, 1, 1, 1);
	loc = glGetUniformLocation(shaderProgram, "mota1"); glUniform3f(loc, 0, 0, 0);
	//tray
	for (int a = 0;a < 240;a++) {
		vertices[a]=tray[a]*5; vertices[a+1]=tray[a+2]*5; vertices[a+2]=tray[a+1]*5;
		a += 2;
	}
	glBufferData(GL_ARRAY_BUFFER, sizeof(tray), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	loc = glGetUniformLocation(shaderProgram, "check");
	glUniform1f(loc, 1.0f);
	glDrawArrays(GL_LINES, 0, 80);
	glDrawElements(GL_LINES,1, GL_UNSIGNED_INT, 0);

	glEnable(GL_BLEND);
	glEnable(GL_PROGRAM_POINT_SIZE);
	{ loc = glGetUniformLocation(shaderProgram, "jade"); glUniform1f(loc, 1.0f);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	loc = glGetUniformLocation(shaderProgram, "check");
	glUniform1f(loc, 1.0f);

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
	
	
	}
	//end depth
	}
	
	glActiveTexture(GL_TEXTURE13); 
	glBindTexture(GL_TEXTURE_CUBE_MAP,cubemap);
	glUniform1i(glGetUniformLocation(shaderProgram, "cubemap"), 13);

	xx=0; yy=0; zz=1;
	//x
	xx1 = xx; yy1 = (yy*can1) - (zz*san1); zz1 = (yy*san1) + (zz*can1);
	//y
	xx = (xx1*can2) + (zz1*san2); yy = yy1; zz = (xx1*-1 * san2) + (zz1*can2);
	//z
	xx1 = (xx*can3) - (yy*san3); yy1 = (xx*san3) + (yy*can3); zz1 = zz;
	loc = glGetUniformLocation(shaderProgram, "look");  glUniform3f(loc, 0,0,0.01);

		//real drawing
	if (wireframe[hover1] == 1) { glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); }
	else { glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); }
		if (objc > 0) {  
	
		glBufferData(GL_ARRAY_BUFFER, sizeof(float)*bued, bufary, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
		glEnableVertexAttribArray(2);
		
		
		if(bright[hover1]==0){ }
		else { 
		loc = glGetUniformLocation(shaderProgram, "jinside"); glUniform1i(loc, 1); 
		loc = glGetUniformLocation(shaderProgram, "shad"); glUniform1f(loc, 0.0f);
		getshadow(); 
		loc = glGetUniformLocation(shaderProgram, "shad"); glUniform1f(loc, 1.0f);
		}
		glViewport(0, 0, wx - 2, wy - 21);
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);

		
		loc = glGetUniformLocation(shaderProgram, "jinside"); glUniform1i(loc, -1);
		
		free7=0; free8=0; thm7=0; thm9=0;
		for(int i=0;i<objc;i++){
		if(showobj[i]==1){
		loc = glGetUniformLocation(shaderProgram, "check");
		glUniform1f(loc, 6.0f);
		loc = glGetUniformLocation(shaderProgram, "jade");
		glUniform1f(loc, 1.0f);
		loc = glGetUniformLocation(shaderProgram, "cade");
		glUniform1f(loc, 0.0f);
		loc = glGetUniformLocation(shaderProgram, "ecat");
		glUniform3f(loc, 0.8f, 0.8f, 0.8f);
		loc = glGetUniformLocation(shaderProgram, "seet");
		glUniform1f(loc, 1);

		thm8 = vers[i];
		loc = glGetUniformLocation(shaderProgram, "scal"); glUniform3f(loc, scil[i].x,scil[i].y,scil[i].z);
		loc = glGetUniformLocation(shaderProgram, "scil"); glUniform3f(loc, scal[i][0].x, scal[i][0].y,scal[i][0].z);
		loc = glGetUniformLocation(shaderProgram, "gauv"); glUniform3f(loc, gauv[i][0].x, gauv[i][0].y,gauv[i][0].z);
		loc = glGetUniformLocation(shaderProgram, "mauv"); glUniform3f(loc, mauv[i].x, mauv[i].y,mauv[i].z);
		obrot.x = cos(rita[i].x / 180.0*3.143); obrot1.x = sin(rita[i].x / 180.0*3.143);
		obrot.y = cos(rita[i].y / 180.0*3.143); obrot1.y = sin(rita[i].y / 180.0*3.143);
		obrot.z = cos(rita[i].z / 180.0*3.143); obrot1.z = sin(rita[i].z / 180.0*3.143);
		loc = glGetUniformLocation(shaderProgram, "rota"); glUniform3f(loc, obrot.x, obrot.y,obrot.z);
		loc = glGetUniformLocation(shaderProgram, "rota1"); glUniform3f(loc, obrot1.x, obrot1.y,obrot1.z);
		obrot.x = cos(rota[i][0].x / 180.0*3.143); obrot1.x = sin(rota[i][0].x / 180.0*3.143);
		obrot.y = cos(rota[i][0].y / 180.0*3.143); obrot1.y = sin(rota[i][0].y / 180.0*3.143);
		obrot.z = cos(rota[i][0].z / 180.0*3.143); obrot1.z = sin(rota[i][0].z / 180.0*3.143);
		loc = glGetUniformLocation(shaderProgram, "mota"); glUniform3f(loc, obrot.x, obrot.y, obrot.z);
		loc = glGetUniformLocation(shaderProgram, "mota1"); glUniform3f(loc, obrot1.x, obrot1.y, obrot1.z);
		//INDEX LOOP
		ou=0; thm4 = 0; thm5 = 0;  thm6 = 0; free1=0; free2=0; free3=0; free4=0; free6=0;
		for (int a = 0;a < fcon[i];a++) {
			if (fice[i][a] == -8) { thm5 = 0; }
			if (fice[i][a] == -9) { thm5 = 1; }
			if (fice[i][a] == -10) { thm6 = 0; }
			if (fice[i][a] == -11) { thm6 = 1; }
			if (fice[i][a] == -4) { thm4 = 0; }
			if (fice[i][a] == -5) { thm4 = 1; }
			
			if (fice[i][a] == -3) { a++; free2 = fice[i][a]; 
				if (fice[i][a]>0) {
					if (mlik == i&&fclick<0&&thm4==0) {
						loc = glGetUniformLocation(shaderProgram, "outline"); glUniform1f(loc, 1.0f);
						glDepthMask(GL_FALSE);
						if (wireframe[hover1] == 0) { glDrawArrays(GL_TRIANGLES, free3+free7, free2 - free3); }
						loc = glGetUniformLocation(shaderProgram, "outline"); glUniform1f(loc, 0.0f);
						glDepthMask(GL_TRUE);
					}
					else {
						if (mlik == i&&free4 == fclick + 1&&thm4==0) {
							loc = glGetUniformLocation(shaderProgram, "outline"); glUniform1f(loc, 1.0f);
							glDepthMask(GL_FALSE);
							if (wireframe[hover1] == 0) {glDrawArrays(GL_TRIANGLES, free3+free7, free2 - free3); }
							loc = glGetUniformLocation(shaderProgram, "outline"); glUniform1f(loc, 0.0f);
							glDepthMask(GL_TRUE);
						}
					if (mlik==i&&free4!=fclick+1&&thm4==0) { loc = glGetUniformLocation(shaderProgram, "outline"); glUniform1f(loc, 0.0f); }
					}
					if (mlik != i&&thm4==0) { loc = glGetUniformLocation(shaderProgram, "outline"); glUniform1f(loc, 0.0f); }

					
					if (thm5 == 1 && wireframe[hover1] == 0) {
						loc = glGetUniformLocation(shaderProgram, "mall"); glUniform1f(loc, 1);
						glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
						glDrawArrays(GL_TRIANGLES, free3+free7, free2 - free3);
						glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
					}
					if (thm6 == 1 && wireframe[hover1]==0) {
						loc = glGetUniformLocation(shaderProgram, "mall"); glUniform1f(loc, 1);
						glDrawArrays(GL_POINTS, free3+free7, free2 - free3);
					}
					
					loc = glGetUniformLocation(shaderProgram, "mall"); glUniform1f(loc, 0);
					if (thm4 == 0 && wireframe[hover1] == 0) { 
			if(thm7==1&&free8<10000){
			tran1[free8]=free3+free7; tran2[free8]=free2-free3; tran3[free8]=thm9; tran4[free8]=i; tran5[free8]=free6; free8++;
			}else{ glDrawArrays(GL_TRIANGLES, free3+free7, free2 - free3); 
			}
					}
					if (wireframe[hover1] == 1) { glDrawArrays(GL_TRIANGLES, free3+free7, free2 - free3); }
					
				} free4++;
				{
			xx = center[i][free6].y/10.0; yy = center[i][free6].z/10.0; zz = center[i][free6].x/10.0;
			loc = glGetUniformLocation(shaderProgram, "genter"); glUniform3f(loc, xx, yy, zz);
			xx += mx[hover1] + mauv[i].x + gauv[i][free6].x; yy += my[hover1] + mauv[i].y + gauv[i][free6].y; zz += mz[hover1] + mauv[i].z + gauv[i][free6].z;
			//x
			xx1 = xx; yy1 = (yy*can1) - (zz*san1); zz1 = (yy*san1) + (zz*can1);
			//y
			xx = (xx1*can2) + (zz1*san2); yy = yy1; zz = (xx1*-1 * san2) + (zz1*can2);
			//z
			xx1 = (xx*can3) - (yy*san3); yy1 = (xx*san3) + (yy*can3); zz1 = zz;
		loc = glGetUniformLocation(shaderProgram, "menter"); glUniform3f(loc, xx1, yy1, zz1);
				}
				free3=free2; 
				loc = glGetUniformLocation(shaderProgram, "wire");
				glUniform3f(loc, frame[i][free6].x, frame[i][free6].y, frame[i][free6].z);
				loc = glGetUniformLocation(shaderProgram, "scil"); glUniform3f(loc, scal[i][free6].x, scal[i][free6].y, scal[i][free6].z);
				loc = glGetUniformLocation(shaderProgram, "gauv"); glUniform3f(loc, gauv[i][free6].x, gauv[i][free6].y, gauv[i][free6].z);

				obrot.x = cos(rota[i][free6].x / 180.0*3.143); obrot1.x = sin(rota[i][free6].x / 180.0*3.143);
				obrot.y = cos(rota[i][free6].y / 180.0*3.143); obrot1.y = sin(rota[i][free6].y / 180.0*3.143);
				obrot.z = cos(rota[i][free6].z / 180.0*3.143); obrot1.z = sin(rota[i][free6].z / 180.0*3.143);
				loc = glGetUniformLocation(shaderProgram, "mota"); glUniform3f(loc, obrot.x, obrot.y, obrot.z);
				loc = glGetUniformLocation(shaderProgram, "mota1"); glUniform3f(loc, obrot1.x, obrot1.y, obrot1.z);
				free6++;
			}


			if (fice[i][a] == -2) { a++; free2=fice[i][a];
			if (mlik == i&&fclick<0 && thm4 == 0) {
				loc = glGetUniformLocation(shaderProgram, "outline"); glUniform1f(loc, 1.0f);
				glDepthMask(GL_FALSE);
				if (wireframe[hover1] == 0) { glDrawArrays(GL_TRIANGLES, free3+free7, free2 - free3); }
				loc = glGetUniformLocation(shaderProgram, "outline"); glUniform1f(loc, 0.0f);
				glDepthMask(GL_TRUE);
			}
			else {
				if (mlik == i&&free4 == fclick + 1 && thm4 == 0) {
					loc = glGetUniformLocation(shaderProgram, "outline"); glUniform1f(loc, 1.0f);
					glDepthMask(GL_FALSE);
					if (wireframe[hover1] == 0) { glDrawArrays(GL_TRIANGLES, free3+free7, free2 - free3); }
					loc = glGetUniformLocation(shaderProgram, "outline"); glUniform1f(loc, 0.0f);
					glDepthMask(GL_TRUE);
				}
				if (mlik == i&&free4 != fclick + 1 && thm4 == 0) { loc = glGetUniformLocation(shaderProgram, "outline"); glUniform1f(loc, 0.0f); }
			}
			if (mlik != i&&thm4 == 0) { loc = glGetUniformLocation(shaderProgram, "outline"); glUniform1f(loc, 0.0f); }

				a++; bu = fice[i][a];   
				{

					if (fice[i][a - 1] > 0) {

						if (thm5 == 1 && wireframe[hover1] == 0) {
							loc = glGetUniformLocation(shaderProgram, "mall"); glUniform1f(loc, 1);
							glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
							glDrawArrays(GL_TRIANGLES, free3 + free7, free2 - free3);
							glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
						}
						if (thm6 == 1 && wireframe[hover1] == 0) {
							loc = glGetUniformLocation(shaderProgram, "mall"); glUniform1f(loc, 1);
							glDrawArrays(GL_POINTS, free3 + free7, free2 - free3);
						}

						loc = glGetUniformLocation(shaderProgram, "mall"); glUniform1f(loc, 0);
						if (thm4 == 0 && wireframe[hover1] == 0) {
							if (thm7 == 1 && free8 < 10000) {
								tran1[free8] = free3 + free7; tran2[free8] = free2 - free3; tran3[free8] = thm9; tran4[free8] = i; tran5[free8] = free6; free8++;
							}
							else {
								glDrawArrays(GL_TRIANGLES, free3 + free7, free2 - free3);
							}
						}
						if (wireframe[hover1] == 1) { glDrawArrays(GL_TRIANGLES, free3 + free7, free2 - free3); }


					}
					//start of changing
				if(bu>=0){
					if (matprop[i][bu].shade == 1) { loc = glGetUniformLocation(shaderProgram, "cade"); glUniform1f(loc, 0.0f); }
					if (matprop[i][bu].shade == 0) { loc = glGetUniformLocation(shaderProgram, "cade"); glUniform1f(loc, 1.0f); }
					ou = matprop[i][bu].Kd;
					loc = glGetUniformLocation(shaderProgram, "ecat");
					glUniform3f(loc, colr[i][ou].z, colr[i][ou].y, colr[i][ou].x);
					if (wireframe[hover1] == 1) { glUniform3f(loc, 1.0, 0.3, 0.2); }

					loc = glGetUniformLocation(shaderProgram, "seet"); glUniform1f(loc, matprop[i][bu].Tr);
					if (matprop[i][bu].Tr <= 0.9) { thm7 = 1; }
					else { thm7 = 0; }
					if (wireframe[hover1] == 1) { glUniform1f(loc, 1.0); }
					glUniform1f(glGetUniformLocation(shaderProgram, "emit"), matprop[i][bu].emit);
					//normal specular strength
					glUniform4f(glGetUniformLocation(shaderProgram, "properties"), matprop[i][bu].NSI,matprop[i][bu].emr,matprop[i][bu].emg,matprop[i][bu].emb);
					//reflection 
					glUniform4f(glGetUniformLocation(shaderProgram, "properties2"), matprop[i][bu].rfls,matprop[i][bu].rfi,matprop[i][bu].rfk,matprop[i][bu].rfmap);

					//specular
					ou = matprop[i][bu].Ks;
					loc = glGetUniformLocation(shaderProgram, "specolor"); glUniform3f(loc, colr[i][ou].z, colr[i][ou].y, colr[i][ou].x);
					loc = glGetUniformLocation(shaderProgram, "specular"); glUniform2f(loc, matprop[i][bu].si, matprop[i][bu].ss);
					if (matprop[i][bu].sm == 1 && wireframe[hover1] == 0) {
						glActiveTexture(GL_TEXTURE15);
						ou = matprop[i][bu].spemap; glBindTexture(GL_TEXTURE_2D, diffuse[i][ou]);
						glUniform1i(glGetUniformLocation(shaderProgram, "specmap"), 15);
					}
					glUniform1f(glGetUniformLocation(shaderProgram, "bi"), matprop[i][bu].sm);

					//emission
					if (matprop[i][bu].emK == 1 && wireframe[hover1] == 0) {
						glActiveTexture(GL_TEXTURE16);
						ou = matprop[i][bu].emmap; glBindTexture(GL_TEXTURE_2D, diffuse[i][ou]);
						glUniform1i(glGetUniformLocation(shaderProgram, "emiss"), 16);
					}
					glUniform1f(glGetUniformLocation(shaderProgram, "gi"), matprop[i][bu].emK);
					//reflection map
					if (matprop[i][bu].rfk == 1 && wireframe[hover1] == 0) {
						glActiveTexture(GL_TEXTURE14);
						ou = matprop[i][bu].rfmap; glBindTexture(GL_TEXTURE_2D, diffuse[i][ou]);
						glUniform1i(glGetUniformLocation(shaderProgram, "reflectmap"), 14);
					}
					glUniform1f(glGetUniformLocation(shaderProgram, "ri"), matprop[i][bu].rfk);
			//emission map
			if(matprop[i][bu].emtmap<0&&matprop[i][bu].emt==3){
			glUniform4f(glGetUniformLocation(shaderProgram, "emty"), 1,matprop[i][bu].emr,matprop[i][bu].emg,matprop[i][bu].emb);
			}
			else{ glUniform4f(glGetUniformLocation(shaderProgram, "emty"), matprop[i][bu].emt,matprop[i][bu].emr,matprop[i][bu].emg,matprop[i][bu].emb); }

					if (matprop[i][bu].emtmap>=0&&matprop[i][bu].emt==3&&wireframe[hover1]==0) {
						glActiveTexture(GL_TEXTURE12);
						ou = matprop[i][bu].emtmap; glBindTexture(GL_TEXTURE_2D, diffuse[i][ou]);
						glUniform1i(glGetUniformLocation(shaderProgram, "emmap"), 12);
					}

					if (matprop[i][bu].bum == 1 && wireframe[hover1] == 0) {
						glActiveTexture(GL_TEXTURE1);
						ou = matprop[i][bu].bump; glBindTexture(GL_TEXTURE_2D, diffuse[i][ou]);
						glUniform1i(glGetUniformLocation(shaderProgram, "ourTexture2"), 1);
					}
					glUniform2f(glGetUniformLocation(shaderProgram, "hi"), matprop[i][bu].bum,matprop[i][bu].NORS);
					if (matprop[i][bu].text == 1 && wireframe[hover1] == 0) {
						glActiveTexture(GL_TEXTURE0);
						ou = matprop[i][bu].tex;  glBindTexture(GL_TEXTURE_2D, diffuse[i][ou]);

						glUniform1i(glGetUniformLocation(shaderProgram, "ourTexture"), 0);
						loc = glGetUniformLocation(shaderProgram, "check");
						glUniform1f(loc, 7.0f);
					}
					else {
						loc = glGetUniformLocation(shaderProgram, "check");
						glUniform1f(loc, 6.0f);
					}
				}
				else{
				loc = glGetUniformLocation(shaderProgram, "cade"); glUniform1f(loc, 0.0f);
				loc = glGetUniformLocation(shaderProgram, "ecat"); glUniform3f(loc, 0.5,0.5,0.5);
				if (wireframe[hover1] == 1) { glUniform3f(loc, 1.0, 0.3, 0.2); }
	loc = glGetUniformLocation(shaderProgram, "seet"); glUniform1f(loc, 1.0); 	
	glUniform2f(glGetUniformLocation(shaderProgram, "emit"), 0, 0);
	loc = glGetUniformLocation(shaderProgram, "specolor"); glUniform3f(loc, 0.5,0.5,0.5);
	loc = glGetUniformLocation(shaderProgram, "specular"); glUniform2f(loc, 0.5, 32);
	loc = glGetUniformLocation(shaderProgram, "check"); glUniform1f(loc, 6.0f);

				}
			//end of material changing
				}
				thm9 = bu;
				free3=free2;
			
			}
		

			if (a >= fcon[i] - 1 ) { 
				ou=free3;
				if(ou<(thm8 / 8.0) - 3){
					if (mlik == i&&fclick<0&&thm4==0) {
						loc = glGetUniformLocation(shaderProgram, "outline"); glUniform1f(loc, 1.0f);
						glDepthMask(GL_FALSE);
						if (wireframe[hover1] == 0) { glDrawArrays(GL_TRIANGLES,free3+free7,(thm8/8.0)-free3); }
						loc = glGetUniformLocation(shaderProgram, "outline"); glUniform1f(loc, 0.0f);
						glDepthMask(GL_TRUE);
					}
					else {
						if (mlik == i&&free4 == fclick + 1&&thm4==0) {
							loc = glGetUniformLocation(shaderProgram, "outline"); glUniform1f(loc, 1.0f);
							glDepthMask(GL_FALSE);
							if (wireframe[hover1] == 0) {glDrawArrays(GL_TRIANGLES,free3+free7,(thm8/8.0)-free3); }
							loc = glGetUniformLocation(shaderProgram, "outline"); glUniform1f(loc, 0.0f);
							glDepthMask(GL_TRUE);
						}
						if (mlik == i&&free4 != fclick + 1&&thm4==0) { loc = glGetUniformLocation(shaderProgram, "outline"); glUniform1f(loc, 0.0f); }
					}
					if (mlik != i&&thm4==0) { loc = glGetUniformLocation(shaderProgram, "outline"); glUniform1f(loc, 0.0f); }


					if (thm5 == 1 && wireframe[hover1] == 0) {
						loc = glGetUniformLocation(shaderProgram, "mall"); glUniform1f(loc, 1);
						glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
						glDrawArrays(GL_TRIANGLES,free3+free7,(thm8/8.0)-free3);
						glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
					}
					if (thm6 == 1 && wireframe[hover1] == 0) {
						loc = glGetUniformLocation(shaderProgram, "mall"); glUniform1f(loc, 1);
						glDrawArrays(GL_POINTS,free3+free7,(thm8/8.0)-free3);
					}
					loc = glGetUniformLocation(shaderProgram, "mall"); glUniform1f(loc, 0);
					if (thm4 == 0 && wireframe[hover1] == 0) {
			if(thm7==1&&free8<10000){
			tran1[free8]=free3+free7; tran2[free8]=(thm8/8.0)-free3; tran3[free8]=thm9; tran4[free8]=i; tran5[free8]=free6; free8++;
			}else{ glDrawArrays(GL_TRIANGLES, free3+free7, (thm8/8.0)-free3); }
					}
					if (wireframe[hover1] == 1) { glDrawArrays(GL_TRIANGLES,free3+free7,(thm8/8.0)-free3); }
					
				}
			}

		}

		}
		free7+=obcc[i];
		//END OF LOOP
		}
//transparency
loc = glGetUniformLocation(shaderProgram, "mall"); glUniform1f(loc, 0);
for(int a=0;a<free8;a++){
	bu=tran3[a]; free7=tran4[a];

	xx=center[free7][bu].y/10.0; yy=center[free7][bu].z/10.0; zz=center[free7][bu].x/10.0;
	loc=glGetUniformLocation(shaderProgram, "genter"); glUniform3f(loc, xx, yy, zz);
	xx+=mx[hover1]+mauv[free7].x+gauv[free7][bu].x; yy+=my[hover1]+mauv[free7].y+gauv[free7][bu].y; zz+=mz[hover1]+mauv[free7].z+gauv[free7][bu].z;
	//x
	xx1 = xx; yy1 = (yy*can1) - (zz*san1); zz1 = (yy*san1) + (zz*can1);
	//y
	xx = (xx1*can2) + (zz1*san2); yy = yy1; zz = (xx1*-1 * san2) + (zz1*can2);
	//z
	xx1 = (xx*can3) - (yy*san3); yy1 = (xx*san3) + (yy*can3); zz1 = zz;
	loc = glGetUniformLocation(shaderProgram, "menter"); glUniform3f(loc, xx1, yy1, zz1);

	if (matprop[free7][bu].shade == 1) { loc = glGetUniformLocation(shaderProgram, "cade"); glUniform1f(loc, 0.0f); }
	if (matprop[free7][bu].shade == 0) { loc = glGetUniformLocation(shaderProgram, "cade"); glUniform1f(loc, 1.0f); }
	ou = matprop[free7][bu].Kd;
	loc = glGetUniformLocation(shaderProgram, "ecat");
	glUniform3f(loc, colr[free7][ou].z, colr[free7][ou].y, colr[free7][ou].x);
	free9=tran5[a]-1;
	loc = glGetUniformLocation(shaderProgram, "scal"); glUniform3f(loc, scil[free7].x,scil[free7].y,scil[free7].z);
	loc = glGetUniformLocation(shaderProgram, "scil"); glUniform3f(loc, scal[free7][free9].x, scal[free7][free9].y,scal[free7][free9].z);
	loc = glGetUniformLocation(shaderProgram, "gauv"); glUniform3f(loc, gauv[free7][free9].x, gauv[free7][free9].y,gauv[free7][free9].z);
	loc = glGetUniformLocation(shaderProgram, "mauv"); glUniform3f(loc, mauv[free7].x, mauv[free7].y,mauv[free7].z);
	obrot.x = cos(rita[free7].x / 180.0*3.143); obrot1.x = sin(rita[free7].x / 180.0*3.143);
	obrot.y = cos(rita[free7].y / 180.0*3.143); obrot1.y = sin(rita[free7].y / 180.0*3.143);
	obrot.z = cos(rita[free7].z / 180.0*3.143); obrot1.z = sin(rita[free7].z / 180.0*3.143);
	loc = glGetUniformLocation(shaderProgram, "rota"); glUniform3f(loc, obrot.x, obrot.y,obrot.z);
	loc = glGetUniformLocation(shaderProgram, "rota1"); glUniform3f(loc, obrot1.x, obrot1.y,obrot1.z);
	obrot.x = cos(rota[free7][free9].x / 180.0*3.143); obrot1.x = sin(rota[free7][free9].x / 180.0*3.143);
	obrot.y = cos(rota[free7][free9].y / 180.0*3.143); obrot1.y = sin(rota[free7][free9].y / 180.0*3.143);
	obrot.z = cos(rota[free7][free9].z / 180.0*3.143); obrot1.z = sin(rota[free7][free9].z / 180.0*3.143);
	loc = glGetUniformLocation(shaderProgram, "mota"); glUniform3f(loc, obrot.x, obrot.y, obrot.z);
	loc = glGetUniformLocation(shaderProgram, "mota1"); glUniform3f(loc, obrot1.x, obrot1.y, obrot1.z);

	if (wireframe[hover1] == 1) { glUniform3f(loc, 1.0, 0.3, 0.2); }
	bu = tran3[a];
	glUniform1f(glGetUniformLocation(shaderProgram, "emit"),matprop[free7][bu].emit);
	
	//normal specular strength
	glUniform4f(glGetUniformLocation(shaderProgram, "properties"), matprop[free7][bu].NSI, matprop[free7][bu].emr, matprop[free7][bu].emg, matprop[free7][bu].emb);
	//reflection 
	glUniform4f(glGetUniformLocation(shaderProgram, "properties2"), matprop[free7][bu].rfls, matprop[free7][bu].rfi, matprop[free7][bu].rfk, matprop[free7][bu].rfmap);

	//specular
	ou = matprop[free7][bu].Ks;
	loc = glGetUniformLocation(shaderProgram, "specolor"); glUniform3f(loc, colr[free7][ou].z, colr[free7][ou].y, colr[free7][ou].x);
	loc = glGetUniformLocation(shaderProgram, "specular"); glUniform2f(loc, matprop[free7][bu].si, matprop[free7][bu].ss);
	if (matprop[free7][bu].sm == 1 && wireframe[hover1] == 0) {
		glActiveTexture(GL_TEXTURE15);
		ou = matprop[free7][bu].spemap; glBindTexture(GL_TEXTURE_2D, diffuse[free7][ou]);
		glUniform1i(glGetUniformLocation(shaderProgram, "specmap"), 15);
	}
	glUniform1f(glGetUniformLocation(shaderProgram, "bi"), matprop[free7][bu].sm);
	//emission
	if (matprop[free7][bu].emK == 1 && wireframe[hover1] == 0) {
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


	loc = glGetUniformLocation(shaderProgram, "seet");
	glUniform1f(loc, matprop[free7][bu].Tr);
	if (wireframe[hover1] == 1) { glUniform1f(loc, 1.0); }

	if (matprop[free7][bu].bum == 1 && wireframe[hover1] == 0) {
		glActiveTexture(GL_TEXTURE1);
		ou = matprop[free7][bu].bump; glBindTexture(GL_TEXTURE_2D, diffuse[free7][ou]);
		glUniform1i(glGetUniformLocation(shaderProgram, "ourTexture2"), 1);
	}
	glUniform1f(glGetUniformLocation(shaderProgram, "hi"), matprop[free7][bu].bum);
	if (matprop[free7][bu].text == 1 && wireframe[hover1] == 0) {
		glActiveTexture(GL_TEXTURE0);
		ou = matprop[free7][bu].tex;  glBindTexture(GL_TEXTURE_2D, diffuse[free7][ou]);

		glUniform1i(glGetUniformLocation(shaderProgram, "ourTexture"), 0);
		loc = glGetUniformLocation(shaderProgram, "check");
		glUniform1f(loc, 7.0f);
	}
	else {
		loc = glGetUniformLocation(shaderProgram, "check");
		glUniform1f(loc, 6.0f);
	}
if (wireframe[hover1] == 0) { glDrawArrays(GL_TRIANGLES,tran1[a],tran2[a]); }
}
//end of transparency

		}
		loc = glGetUniformLocation(shaderProgram, "genter"); glUniform3f(loc,0,0,0);
		loc = glGetUniformLocation(shaderProgram, "find"); glUniform1i(loc, 0);
		loc = glGetUniformLocation(shaderProgram, "mall"); glUniform1f(loc, 0.0f);
		loc = glGetUniformLocation(shaderProgram, "shad"); glUniform1f(loc, 0.0f);
		glDisable(GL_DEPTH_TEST);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		if(selet3>0&&curwin-1==hover1){ 
		if (mpo1 < ((wx - 2) / 2.0)+stx) { mp1 = mpo1 - stx;
		mp1 /= ((wx - 2) / 2); mp1 *= -1; mp1 = -1.0 - mp1;
		}
		if (mpo1 > ((wx - 2) / 2.0) + stx) {
			mp1 = mpo1 - stx- ((wx - 2) / 2);
			mp1 /= ((wx - 2) / 2); 
		}
		//y
		if (mpo2 < ((wy - 21) / 2.0) + sty+20) {
			mp2 = mpo2 - sty-20;
			mp2 /= ((wy - 20) / 2); mp2 *= -1; mp2 = -1.0 - mp2;
		}
		if (mpo2 > ((wy - 21) / 2.0) + sty + 20) {
			mp2 = mpo2 - sty - 20- ((wy - 20) / 2);
			mp2 /= ((wy - 20) / 2); 
		}
		//project
		if ((wx - 2) >(wy - 21)) { mp2 /= ratio; }
		else { mp1 *= ratio; }
		xx = mp1; yy = mp2;  zz = 0;
		//z
		xx1 = (xx*can3) - (yy*san3); yy1 = (xx*san3) + (yy*can3); zz1 = zz;
		//y
		xx = (xx1*can2) + (zz1*san2); yy = yy1; zz = (xx1*-1 * san2) + (zz1*can2);
		//x
		xx1 = xx; yy1 = (yy*can1) - (zz*san1); zz1 = (yy*san1) + (zz*can1);

		mmx = xx1*-1; mmy = yy1*-1; mmz = zz1;
		zmx = zoom[hover1];
		pan1= mx[hover1]; pan2= my[hover1]; pan3= mz[hover1];
	//focus
		for (int a = 0;a < 18;a++) {
			xx = stik[a + 2]+mmx; yy = stik[a + 1]+mmy;  zz = stik[a]+mmz;
			//x
			xx1 = xx; yy1 = (yy*can1) - (zz*san1); zz1 = (yy*san1) + (zz*can1);
			//y
			xx = (xx1*can2) + (zz1*san2); yy = yy1; zz = (xx1*-1 * san2) + (zz1*can2);
			//z
			xx1 = (xx*can3) - (yy*san3); yy1 = (xx*san3) + (yy*can3); zz1 = zz;
			if ((wx - 2) >(wy - 21)) { yy1 *= ratio; }
			else { xx1 /= ratio; }
			vertices[a] = xx1 ; vertices[a + 1] = yy1 ; vertices[a + 2] = 0.9;
			a += 2;
		}
		glBufferData(GL_ARRAY_BUFFER, sizeof(arrow), vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		loc = glGetUniformLocation(shaderProgram, "check");
		glUniform1f(loc, 3.0f);
		glDrawArrays(GL_LINES, 0, 2);
		glUniform1f(loc, 4.0f);
		glDrawArrays(GL_LINES, 2, 2);
		glUniform1f(loc, 5.0f);
		glDrawArrays(GL_LINES, 4, 2);
		}

	//arrow
	for (int a = 0;a < 18;a++) {
		xx = arrow[a + 2]; yy = arrow[a + 1];  zz = arrow[a];
		//x
		xx1 = xx; yy1 = (yy*can1) - (zz*san1); zz1 = (yy*san1) + (zz*can1);
		//y
		xx = (xx1*can2) + (zz1*san2); yy = yy1; zz = (xx1*-1 * san2) + (zz1*can2);
		//z
		xx1 = (xx*can3) - (yy*san3); yy1 = (xx*san3) + (yy*can3); zz1 = zz;
		if ((wx - 2) >(wy - 21)) { yy1 *= ratio; }
		else { xx1 /= ratio; }
		vertices[a] = xx1 - 0.8; vertices[a + 1] = yy1 + 0.8; vertices[a + 2] = 0.9;
		a +=2;
	}
	glBufferData(GL_ARRAY_BUFFER, sizeof(arrow), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	loc = glGetUniformLocation(shaderProgram, "check");
	glUniform1f(loc, 3.0f);
	glDrawArrays(GL_LINES, 0, 2);
	glUniform1f(loc, 4.0f);
	glDrawArrays(GL_LINES, 2, 2);
	glUniform1f(loc, 5.0f);
	glDrawArrays(GL_LINES, 4, 2);

	}
	
	if (bright[hover1] != 0) {
		glBindFramebuffer(GL_FRAMEBUFFER, hdr);
		//hdr rendering
		screen[8] = (wx - 2) / 1500.0;
		screen[13] = (wx - 2) / 1500.0; screen[14] = (wy - 21) / 1500.0;
		screen[19] = (wy - 21) / 1500.0;

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
	glReadPixels(0, 0, wx-2, wy-21, GL_RGBA, GL_UNSIGNED_BYTE, read);
}
