void shadow(int count) {
	glViewport(0, 0, 1024, 1024);
	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO[count]);
	glClear(GL_DEPTH_BUFFER_BIT);
	
	can1 = cos(-(metion1+3.143)); san1 = sin(-(metion1 + 3.143));
	can2 = cos(metion2); san2 = sin(metion2);
	can3 = cos(metion3+3.143); san3 = sin(metion3+3.143 );

	loc = glGetUniformLocation(shaderProgram, "check"); glUniform1f(loc, 1.0f);
	sprintf_s(how1,"shatio[%d]",count);
	loc = glGetUniformLocation(shaderProgram, how1); glUniform3f(loc, metio1,metio2,metio3);
	sprintf_s(how1,"can[%d]",count);
	loc = glGetUniformLocation(shaderProgram, how1); glUniform3f(loc, can1, can2, can3);
	sprintf_s(how1,"san[%d]",count);
	loc = glGetUniformLocation(shaderProgram, how1); glUniform3f(loc, san1, san2, san3);
	
	loc = glGetUniformLocation(shaderProgram, "jik"); glUniform1i(loc, count);

	//real drawing
	if (objc > 0) {
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
				
					if (thm5 == 1 && wireframe[hover1] == 0) {
						loc = glGetUniformLocation(shaderProgram, "mall"); glUniform1f(loc, 1);
						glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
						glDrawArrays(GL_TRIANGLES, free3+free7, free2 - free3);
						glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
					}
					if (thm6 == 1 && wireframe[hover1] == 0) {
						loc = glGetUniformLocation(shaderProgram, "mall"); glUniform1f(loc, 1);
						glDrawArrays(GL_POINTS, free3+free7, free2 - free3);
					}
					
					loc = glGetUniformLocation(shaderProgram, "mall"); glUniform1f(loc, 0);
					if (thm4 == 0 && wireframe[hover1] == 0) {  glDrawArrays(GL_TRIANGLES, free3+free7, free2 - free3); }
					if (wireframe[hover1] == 1) { glDrawArrays(GL_TRIANGLES, free3+free7, free2 - free3); }
			xx = center[i][free6].y/10.0; yy = center[i][free6].z/10.0; zz = center[i][free6].x/10.0;
			loc = glGetUniformLocation(shaderProgram, "genter"); glUniform3f(loc, xx, yy, zz);
				} free4++;
			
				free3=free2; 
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
				a++; bu = fice[i][a];   
				{
					
					if (fice[i][a-1]>0) {
						
	if (thm5 == 1 && wireframe[hover1] == 0) {
		loc = glGetUniformLocation(shaderProgram, "mall"); glUniform1f(loc, 1);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawArrays(GL_TRIANGLES, free3+free7, free2 - free3);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	if (thm6 == 1 && wireframe[hover1] == 0) {
		loc = glGetUniformLocation(shaderProgram, "mall"); glUniform1f(loc, 1);
		glDrawArrays(GL_POINTS, free3+free7, free2 - free3);
	}
	
			loc = glGetUniformLocation(shaderProgram, "mall"); glUniform1f(loc, 0);
			if (thm4 == 0 && wireframe[hover1] == 0) { glDrawArrays(GL_TRIANGLES, free3+free7, free2 - free3); 
			
			}
			if (wireframe[hover1] == 1) { glDrawArrays(GL_TRIANGLES, free3+free7, free2 - free3); }
			
		
					}

			loc = glGetUniformLocation(shaderProgram, "seet"); glUniform1f(loc, matprop[i][bu].Tr);
			if(matprop[i][bu].Tr<=0.9){ thm7=1; }else{ thm7=0; }
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
				thm9 = bu;
				free3=free2;
			
			}
		

			if (a >= fcon[i] - 1 ) { 
				ou=free3;
				if(ou<(thm8 / 8.0) - 3){
					
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
					if (thm4 == 0 && wireframe[hover1] == 0) { glDrawArrays(GL_TRIANGLES, free3+free7, (thm8/8.0)-free3); }
					if (wireframe[hover1] == 1) { glDrawArrays(GL_TRIANGLES,free3+free7,(thm8/8.0)-free3); }
					
				}
			}

		}
		}
		free7+=obcc[i];
		//END OF LOOP
			}

	}


}




//get shadow
//lamp
void getshadow() {
	thm10=strlen(light);
	free5=0; free8=0;
for (int a = 0, b = 0;a < thm10;a++) {
if (light[a] == ':') { a++; free8++;
for (0;a < thm10;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm5 = atof(how); break; } } a += 2;
for (0;a < thm10;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm1 = atof(how); break; } } a += 2;
for (0;a < thm10;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm2 = atof(how); break; } } a += 2;
for (0;a < thm10;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm3 = atof(how); break; } } a += 2;

if(lip[free8-1].x>=0){ free9=lip[free8-1].x;
	if(lip[free8-1].y>=0){ free10=lip[free8-1].y; thm1=center[free9][free10].x/10+gauv[free9][free10].x+mauv[free9].x;
	thm2=center[free9][free10].y/10+gauv[free9][free10].y+mauv[free9].y; thm3=center[free9][free10].z/10+gauv[free9][free10].z+mauv[free9].z; }

	else{ handz[100]=0; handz[101]=0; handz[102]=0;
	for (free10 =0;free10 <=gcont[free9];free10++) {
	handz[100]+=center[free9][free10].x/10+gauv[free9][free10].x+mauv[free9].x; handz[101]+=center[free9][free10].y/10+gauv[free9][free10].y+mauv[free9].y; handz[102]+=center[free9][free10].z/10+gauv[free9][free10].z+mauv[free9].z;
	}
	handz[100]/=free10; handz[101]/=free10; handz[102]/=free10;
	thm1=handz[100]; thm2=handz[101]; thm3=handz[102];
	}
			
			}

//directional
if (thm5 == 1) { 
	for (0;a < thm10;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm6 = atof(how)*3.143 / 180.0; break; } } a += 2;
	for (0;a < thm10;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm7 = atof(how)*3.143 / 180.0; break; } } a += 2;
	for (0;a < thm10;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm8 = atof(how)*3.143 / 180.0; break; } } a += 2;
	for (int h=0;a < thm10;a++) {  if(h>=4){ break;} if(light[a]==','){ h++;} } 
	for (0;a < thm10;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[13] = atof(how); break; } } a += 2;
	
	if (handz[13] == 1 && free5<8) {
		metio1 = -1 * thm1; metio2 = -1 * thm2; metio3 = -1 * thm3;
		metion1 = thm6; metion2 = thm7; metion3 = thm8;
		loc = glGetUniformLocation(shaderProgram, "persp");  glUniform1f(loc, 1);
		shadow(free5);
		free5++;

	}

}
//flashlight
if (thm5 == 2) {
	for (0;a < thm10;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm6 = atof(how)*3.143 / 180.0; break; } } a += 2;
	for (0;a < thm10;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm7 = atof(how)*3.143 / 180.0; break; } } a += 2;
	for (0;a < thm10;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm8 = atof(how)*3.143 / 180.0; break; } } a += 2;
	for (int h = 0;a < thm10;a++) { if (h >= 4) { break; } if (light[a] == ',') { h++; } }
	for (0;a < thm10;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[13] = atof(how); break; } } a += 2;

	if (handz[13] == 1 && free5<8) {
		metio1 = -1 * thm1; metio2 = -1 * thm2; metio3 = -1 * thm3;
		metion1 = thm6; metion2 = thm7; metion3 = thm8;
		loc = glGetUniformLocation(shaderProgram, "persp");  glUniform1f(loc, 2);
		shadow(free5);
		free5++;
	

	}

}

//end
}
}

}
