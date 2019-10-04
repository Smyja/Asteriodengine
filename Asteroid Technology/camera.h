void cameras() {
	//camera
	bu = strlen(camera);
	ou = 0; thm9 = 0;
	for (int a = 0, b = 0;a < bu;a++) {
		if (camera[a] == ':') {
			a++;
			for (0;a < bu;a++) { how[b] = camera[a]; b++; if (camera[a + 1] == ',') { how[b] = 0; b = 0; thm1 = atof(how); break; } } a += 2;
			for (0;a < bu;a++) { how[b] = camera[a]; b++; if (camera[a + 1] == ',') { how[b] = 0; b = 0; thm2 = atof(how); break; } } a += 2;
			for (0;a < bu;a++) { how[b] = camera[a]; b++; if (camera[a + 1] == ',') { how[b] = 0; b = 0; thm3 = atof(how); break; } } a += 2;

			for (0;a < bu;a++) { how[b] = camera[a]; b++; if (camera[a + 1] == ',') { how[b] = 0; b = 0; thm7 = atof(how) / 180.0*3.143; break; } } a += 2;
			for (0;a < bu;a++) { how[b] = camera[a]; b++; if (camera[a + 1] == ',') { how[b] = 0; b = 0; thm8 = atof(how) / 180.0*3.143; break; } } a += 2;
			for (0;a < bu;a++) { how[b] = camera[a]; b++; if (camera[a + 1] == ',') { how[b] = 0; b = 0; thm4 = atof(how) / 180.0*3.143; break; } } a += 2;

			for (0;a < bu;a++) { how[b] = camera[a]; b++; if (camera[a + 1] == ',') { break; } } a += 2;
			for (0;a < bu;a++) { how[b] = camera[a]; b++; if (camera[a + 1] == ',') { break; } } a += 2;
			b = 0;
			for (0;a < bu;a++) { how[b] = camera[a]; b++; if (camera[a + 1] == ',') { how[b] = 0; b = 0; handy[0] = atof(how); break; } } a += 2;
			for (0;a < bu;a++) { how[b] = camera[a]; b++; if (camera[a + 1] == ',') { how[b] = 0; b = 0; handy[1] = atof(how); break; } } a += 2;
			handy[2] = handy[0] / handy[1];

			if (handy[1]>handy[0]) { metio = 0.2; metio1 = 0.2 / handy[2]; }
			else { metio1 = 0.2; metio = 0.2 / handy[2]; }
			rot1 = cos(thm7); mot1 = sin(thm7);
			rot2 = cos(thm8); mot2 = sin(thm8);
			rot3 = cos(thm4); mot3 = sin(thm4);


			xx = thm1; yy = thm2;  zz = thm3;
			xx += mx[hover1]; yy += my[hover1]; zz += mz[hover1];
			//x
			xx1 = xx; yy1 = (yy*can1) - (zz*san1); zz1 = (yy*san1) + (zz*can1);
			//y
			xx = (xx1*can2) + (zz1*san2); yy = yy1; zz = (xx1*-1 * san2) + (zz1*can2);
			//z
			xx1 = (xx*can3) - (yy*san3); yy1 = (xx*san3) + (yy*can3); zz1 = zz;
			
			vertices[ou] = xx1; vertices[ou + 1] = yy1; vertices[ou + 2] = zz1;
			vertices[ou + 30] = xx1; vertices[ou + 31] = yy1; vertices[ou + 32] = zz1;
			vertices[ou + 36] = xx1; vertices[ou + 37] = yy1; vertices[ou + 38] = zz1;
			vertices[ou + 42] = xx1; vertices[ou + 43] = yy1; vertices[ou + 44] = zz1;


			xx = thm1 - metio1; yy = thm2 - metio;  zz = thm3 - 0.2;
			xx -= thm1; yy -= thm2; zz -= thm3;
			//z
			xx1 = (xx*rot3) - (yy*mot3); yy1 = (xx*mot3) + (yy*rot3); zz1 = zz;
			//y
			xx = (xx1*rot2) + (zz1*mot2); yy = yy1; zz = (xx1*-1 * mot2) + (zz1*rot2);
			//x
			xx1 = xx; yy1 = (yy*rot1) - (zz*mot1); zz1 = (yy*mot1) + (zz*rot1);

			xx = xx1 + thm1; yy = yy1 + thm2; zz = zz1 + thm3;

			xx += mx[hover1]; yy += my[hover1]; zz += mz[hover1];
			//x
			xx1 = xx; yy1 = (yy*can1) - (zz*san1); zz1 = (yy*san1) + (zz*can1);
			//y
			xx = (xx1*can2) + (zz1*san2); yy = yy1; zz = (xx1*-1 * san2) + (zz1*can2);
			//z
			xx1 = (xx*can3) - (yy*san3); yy1 = (xx*san3) + (yy*can3); zz1 = zz;
			
			vertices[ou + 3] = xx1; vertices[ou + 4] = yy1; vertices[ou + 5] = zz1;
			vertices[ou + 6] = xx1; vertices[ou + 7] = yy1; vertices[ou + 8] = zz1;
			vertices[ou + 27] = xx1; vertices[ou + 28] = yy1; vertices[ou + 29] = zz1;

			xx = thm1 + metio1; yy = thm2 - metio;  zz = thm3 - 0.2;
			xx -= thm1; yy -= thm2; zz -= thm3;
			//z
			xx1 = (xx*rot3) - (yy*mot3); yy1 = (xx*mot3) + (yy*rot3); zz1 = zz;
			//y
			xx = (xx1*rot2) + (zz1*mot2); yy = yy1; zz = (xx1*-1 * mot2) + (zz1*rot2);
			//x
			xx1 = xx; yy1 = (yy*rot1) - (zz*mot1); zz1 = (yy*mot1) + (zz*rot1);
			xx = xx1 + thm1; yy = yy1 + thm2; zz = zz1 + thm3;

			xx += mx[hover1]; yy += my[hover1]; zz += mz[hover1];
			//x
			xx1 = xx; yy1 = (yy*can1) - (zz*san1); zz1 = (yy*san1) + (zz*can1);
			//y
			xx = (xx1*can2) + (zz1*san2); yy = yy1; zz = (xx1*-1 * san2) + (zz1*can2);
			//z
			xx1 = (xx*can3) - (yy*san3); yy1 = (xx*san3) + (yy*can3); zz1 = zz;
			vertices[ou + 9] = xx1; vertices[ou + 10] = yy1; vertices[ou + 11] = zz1;
			vertices[ou + 12] = xx1; vertices[ou + 13] = yy1; vertices[ou + 14] = zz1;
			vertices[ou + 33] = xx1; vertices[ou + 34] = yy1; vertices[ou + 35] = zz1;


			xx = thm1 + metio1; yy = thm2 + metio;  zz = thm3 - 0.2;
			xx -= thm1; yy -= thm2; zz -= thm3;
			//z
			xx1 = (xx*rot3) - (yy*mot3); yy1 = (xx*mot3) + (yy*rot3); zz1 = zz;
			//y
			xx = (xx1*rot2) + (zz1*mot2); yy = yy1; zz = (xx1*-1 * mot2) + (zz1*rot2);
			//x
			xx1 = xx; yy1 = (yy*rot1) - (zz*mot1); zz1 = (yy*mot1) + (zz*rot1);
			xx = xx1 + thm1; yy = yy1 + thm2; zz = zz1 + thm3;

			xx += mx[hover1]; yy += my[hover1]; zz += mz[hover1];
			//x
			xx1 = xx; yy1 = (yy*can1) - (zz*san1); zz1 = (yy*san1) + (zz*can1);
			//y
			xx = (xx1*can2) + (zz1*san2); yy = yy1; zz = (xx1*-1 * san2) + (zz1*can2);
			//z
			xx1 = (xx*can3) - (yy*san3); yy1 = (xx*san3) + (yy*can3); zz1 = zz;
			vertices[ou + 15] = xx1; vertices[ou + 16] = yy1; vertices[ou + 17] = zz1;
			vertices[ou + 18] = xx1; vertices[ou + 19] = yy1; vertices[ou + 20] = zz1;
			vertices[ou + 39] = xx1; vertices[ou + 40] = yy1; vertices[ou + 41] = zz1;

			xx = thm1 - metio1; yy = thm2 + metio;  zz = thm3 - 0.2;
			xx -= thm1; yy -= thm2; zz -= thm3;
			//z
			xx1 = (xx*rot3) - (yy*mot3); yy1 = (xx*mot3) + (yy*rot3); zz1 = zz;
			//y
			xx = (xx1*rot2) + (zz1*mot2); yy = yy1; zz = (xx1*-1 * mot2) + (zz1*rot2);
			//x
			xx1 = xx; yy1 = (yy*rot1) - (zz*mot1); zz1 = (yy*mot1) + (zz*rot1);
			xx = xx1 + thm1; yy = yy1 + thm2; zz = zz1 + thm3;

			xx += mx[hover1]; yy += my[hover1]; zz += mz[hover1];
			//x
			xx1 = xx; yy1 = (yy*can1) - (zz*san1); zz1 = (yy*san1) + (zz*can1);
			//y
			xx = (xx1*can2) + (zz1*san2); yy = yy1; zz = (xx1*-1 * san2) + (zz1*can2);
			//z
			xx1 = (xx*can3) - (yy*san3); yy1 = (xx*san3) + (yy*can3); zz1 = zz;
			vertices[ou + 21] = xx1; vertices[ou + 22] = yy1; vertices[ou + 23] = zz1;
			vertices[ou + 24] = xx1; vertices[ou + 25] = yy1; vertices[ou + 26] = zz1;
			vertices[ou + 45] = xx1; vertices[ou + 46] = yy1; vertices[ou + 47] = zz1;


			ou += 48; thm9 += 16;
		}
	}

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	loc = glGetUniformLocation(shaderProgram, "check");
	glUniform1f(loc, 8.0f);
	glDrawArrays(GL_LINES, 0, thm9);
	//end of camera
}
//lamp
void lamp() {
	vertices[0] = 0; vertices[1] = 0; vertices[2] = 0;
	for (int a = 0, b = 3;a<360;a += 45, b += 3) {
		vertices[b] = 0.05*cos(a*3.143 / 180); vertices[b + 1] = 0.05*sin(a*3.143 / 180); vertices[b + 2] = 0;
		if ((wx - 2) >(wy - 21)) { vertices[b + 1] *= ratio; }
		else { vertices[b] /= ratio; }

	}
	glBufferData(GL_ARRAY_BUFFER, sizeof(int)*30, vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);


	bu = strlen(light);
	ou = 0; free1 = 0; free2 = 0; free3 = 0; free4 = 0; free5 = 0; free6 = 0; free7 = 0; free8=0;
	for (int a = 0, b = 0;a < bu;a++) {
	if (light[a] == ':') { free8++;
	a++;
	for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm5 = atof(how); break; } } a += 2;
	for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm1 = atof(how); break; } } a += 2;
	for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm2 = atof(how); break; } } a += 2;
	for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm3 = atof(how); break; } } a += 2;
	
	if(lip[free8-1].x>=0){ free9=lip[free8-1].x;
	if(lip[free8-1].y>=0){ free10=lip[free8-1].y; thm1=center[free9][free10].x/10+gauv[free9][free10].x+mauv[free9].x;
	thm2=center[free9][free10].y/10+gauv[free9][free10].y+mauv[free9].y; thm3=center[free9][free10].z/10+gauv[free9][free10].z+mauv[free9].z; 
	}

	else{ handz[100]=0; handz[101]=0; handz[102]=0;
	for (free10 =0;free10 <=gcont[free9];free10++) {
	handz[100]+=center[free9][free10].x/10+gauv[free9][free10].x+mauv[free9].x; handz[101]+=center[free9][free10].y/10+gauv[free9][free10].y+mauv[free9].y; handz[102]+=center[free9][free10].z/10+gauv[free9][free10].z+mauv[free9].z;
	}
	handz[100]/=free10; handz[101]/=free10; handz[102]/=free10;
	thm1=handz[100]; thm2=handz[101]; thm3=handz[102];
	}
			
			}
			handx[0] = thm1; handy[0] = thm2; handz[0] = thm3;

			thm1 += mx[hover1]; thm2 += my[hover1]; thm3 += mz[hover1];
			thm1*=zoom[hover1]; thm2*=zoom[hover1]; thm3*=zoom[hover1]; 
			//x
			xx1 = thm1; yy1 = (thm2*can1) - (thm3*san1); zz1 = (thm2*san1) + (thm3*can1);
			//y
			xx = (xx1*can2) + (zz1*san2); yy = yy1; zz = (xx1*-1 * san2) + (zz1*can2);
			//z
			xx1 = (xx*can3) - (yy*san3); yy1 = (xx*san3) + (yy*can3); zz1 = zz;
			
			thm1 = handx[0]; thm2 = handy[0]; thm3 = handz[0];
			if (thm5 == 1) { loc = glGetUniformLocation(shaderProgram, "check"); glUniform1f(loc, 9.0f); }
			if (thm5 == 2) { loc = glGetUniformLocation(shaderProgram, "check"); glUniform1f(loc, 10.0f); }
			if (thm5 == 3) { loc = glGetUniformLocation(shaderProgram, "check"); glUniform1f(loc, 11.0f); }
			if(project[hover1]==0){ loc = glGetUniformLocation(shaderProgram, "oft"); glUniform3f(loc, xx1, yy1,((zz1/2)) ); }
			else{  loc = glGetUniformLocation(shaderProgram, "oft"); glUniform3f(loc, xx1, yy1,(zz1/-5) ); }
			loc = glGetUniformLocation(shaderProgram, "oft"); glUniform3f(loc,thm1,thm2,thm3);
			glDrawArrays(GL_POINTS, 0, 9);
			//point light
			if (thm5 == 3&&free1<=300) {
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm4 = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm6 = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm7 = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm8 = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm9 = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm10 = atof(how); break; } } a += 2;
				sprintf(how1, "poinx[%d]", free1);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform3f(loc, handx[0], handy[0], handz[0]);
				sprintf(how1, "poinc[%d]", free1);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform3f(loc, thm9, thm6, thm7);
				sprintf(how1, "pox[%d]", free1);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform3f(loc, thm8, thm4 / 10.0, thm10);

				free1++;
			}
			//flashlight
			if (thm5 == 2&&free2<=300) {
				sprintf(how1, "fpo[%d]", free2);
				loc = glGetUniformLocation(shaderProgram, how1);  

				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm6 = atof(how)*3.143 / 180.0; break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm7 = atof(how)*3.143 / 180.0; break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm8 = atof(how)*3.143 / 180.0; break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm9 = atof(how); break; } } a += 2;

				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[10] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[11] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[12] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[13] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[14] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[15] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[16] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[17] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[18] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[19] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[20] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[21] = atof(how); break; } } a += 2;
				glUniform4f(loc, handx[0], handy[0], handz[0],handz[21]);
				if (handz[13] == 1 && free5<8) {
					sprintf(how1, "flash[%d]", free6);
					loc = glGetUniformLocation(shaderProgram, how1);  glUniform1i(loc, free5); free6++; free5++;
					sprintf(how1, "fscol[%d]", free2);
					loc = glGetUniformLocation(shaderProgram, how1);  glUniform3f(loc, handz[14], handz[15], handz[16]);
				}
				else {
					sprintf(how1, "flash[%d]", free6);
					loc = glGetUniformLocation(shaderProgram, how1);  glUniform1i(loc, -10); free6++;
				}
				sprintf(how1, "fcol[%d]", free2);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform4f(loc, handz[17], handz[10], handz[11], handz[20]);

				sprintf(how1, "foth[%d]", free2);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform4f(loc, thm9, handz[12], handz[18], handz[19]);

				verr[ou] = xx1; verr[ou + 1] = yy1; verr[ou + 2] = zz1;

				rot1 = cos(thm6); mot1 = sin(thm6);
				rot2 = cos(thm7); mot2 = sin(thm7);
				rot3 = cos(thm8); mot3 = sin(thm8);
				thm1 = handx[0]; thm2 = handy[0]; thm3 = handz[0];

				xx = thm1; yy = thm2;  zz = thm3 - (thm9 / 10);
				xx -= thm1; yy -= thm2; zz -= thm3;
				//z
				xx1 = (xx*rot3) - (yy*mot3); yy1 = (xx*mot3) + (yy*rot3); zz1 = zz;
				//y
				xx = (xx1*rot2) + (zz1*mot2); yy = yy1; zz = (xx1*-1 * mot2) + (zz1*rot2);
				//x
				xx1 = xx; yy1 = (yy*rot1) - (zz*mot1); zz1 = (yy*mot1) + (zz*rot1);
				xx1 += thm1; yy1 += thm2; zz1 += thm3;
				sprintf(how1, "fdir[%d]", free2);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform3f(loc, xx1, yy1, zz1);

				xx = xx1 + mx[hover1]; yy = yy1 + my[hover1]; zz = zz1 + mz[hover1];
				//x
				xx1 = xx; yy1 = (yy*can1) - (zz*san1); zz1 = (yy*san1) + (zz*can1);
				//y
				xx = (xx1*can2) + (zz1*san2); yy = yy1; zz = (xx1*-1 * san2) + (zz1*can2);
				//z
				xx1 = (xx*can3) - (yy*san3); yy1 = (xx*san3) + (yy*can3); zz1 = zz;

				verr[ou + 3] = xx1; verr[ou + 4] = yy1; verr[ou + 5] = zz1;
				ou += 6;

				free2++;
			}

			//directional
			if (thm5 == 1&&free3<=300) { 
				sprintf(how1, "dipo[%d]", free3);
				loc = glGetUniformLocation(shaderProgram, how1);  

				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm6 = atof(how)*3.143 / 180.0; break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm7 = atof(how)*3.143 / 180.0; break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm8 = atof(how)*3.143 / 180.0; break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm9 = atof(how); break; } } a += 2;

				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[10] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[11] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[12] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[13] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[14] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[15] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[16] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[17] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[18] = atof(how); break; } } a += 2;
				glUniform4f(loc, handx[0], handy[0], handz[0],handz[18]);
				if (handz[13] == 1 && free5<8) {
					sprintf(how1, "sun[%d]", free4);
					loc = glGetUniformLocation(shaderProgram, how1);  glUniform1i(loc, free5); free4++; free5++;
				}
				else {
					sprintf(how1, "sun[%d]", free4);
					loc = glGetUniformLocation(shaderProgram, how1);  glUniform1i(loc, -10); free4++;
				}

				sprintf(how1, "dico[%d]", free3);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform4f(loc, handz[11], handz[10], handz[17], handz[12]);

				sprintf(how1, "diter[%d]", free3);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform4f(loc, thm9, handz[14], handz[15], handz[16]);
				verr[ou] = xx1; verr[ou + 1] = yy1; verr[ou + 2] = zz1;

				rot1 = cos(thm6); mot1 = sin(thm6);
				rot2 = cos(thm7); mot2 = sin(thm7);
				rot3 = cos(thm8); mot3 = sin(thm8);

				xx = thm1; yy = thm2;  zz = thm3 - 0.5;
				xx -= thm1; yy -= thm2; zz -= thm3;
				//z
				xx1 = (xx*rot3) - (yy*mot3); yy1 = (xx*mot3) + (yy*rot3); zz1 = zz;
				//y
				xx = (xx1*rot2) + (zz1*mot2); yy = yy1; zz = (xx1*-1 * mot2) + (zz1*rot2);
				//x
				xx1 = xx; yy1 = (yy*rot1) - (zz*mot1); zz1 = (yy*mot1) + (zz*rot1);
				xx1 += thm1; yy1 += thm2; zz1 += thm3;
				sprintf(how1, "diot[%d]", free3);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform3f(loc, xx1, yy1, zz1);
				xx = xx1 + mx[hover1]; yy = yy1 + my[hover1]; zz = zz1 + mz[hover1];
				//x
				xx1 = xx; yy1 = (yy*can1) - (zz*san1); zz1 = (yy*san1) + (zz*can1);
				//y
				xx = (xx1*can2) + (zz1*san2); yy = yy1; zz = (xx1*-1 * san2) + (zz1*can2);
				//z
				xx1 = (xx*can3) - (yy*san3); yy1 = (xx*san3) + (yy*can3); zz1 = zz;

				verr[ou + 3] = xx1; verr[ou + 4] = yy1; verr[ou + 5] = zz1;
				ou += 6;

				free3++;
			}
		}
	}
	loc = glGetUniformLocation(shaderProgram, "index"); glUniform1f(loc, free1);
	loc = glGetUniformLocation(shaderProgram, "findex"); glUniform1f(loc, free2);
	loc = glGetUniformLocation(shaderProgram, "dindex"); glUniform1f(loc, free3);

	loc = glGetUniformLocation(shaderProgram, "check"); glUniform1f(loc, 4.0f);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*ou, verr, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_LINES, 0, ou / 3);
}






//lamp
void lamp1() {
	bu = strlen(light);
	ou = 0; free1 = 0; free2 = 0; free3 = 0; free4 = 0; free5 = 0; free6 = 0; free7 = 0;
	for (int a = 0, b = 0;a < bu;a++) {
		if (light[a] == ':') {
			a++;
			for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm5 = atof(how); break; } } a += 2;
			for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm1 = atof(how); break; } } a += 2;
			for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm2 = atof(how); break; } } a += 2;
			for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm3 = atof(how); break; } } a += 2;
			handx[0] = thm1; handy[0] = thm2; handz[0] = thm3;

			thm1 = handx[0]; thm2 = handy[0]; thm3 = handz[0];
			//point light
			if (thm5 == 3) {
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm4 = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm6 = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm7 = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm8 = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm9 = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm10 = atof(how); break; } } a += 2;
				sprintf(how1, "poinx[%d]", free1);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform3f(loc, handx[0], handy[0], handz[0]);
				sprintf(how1, "poinc[%d]", free1);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform3f(loc, thm9, thm6, thm7);
				sprintf(how1, "pox[%d]", free1);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform3f(loc, thm8, thm4 / 10.0, thm10);

				free1++;
			}
			//flashlight
			if (thm5 == 2) {
				sprintf(how1, "fpo[%d]", free2);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform3f(loc, handx[0], handy[0], handz[0]);

				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm6 = atof(how)*3.143 / 180.0; break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm7 = atof(how)*3.143 / 180.0; break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm8 = atof(how)*3.143 / 180.0; break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm9 = atof(how); break; } } a += 2;

				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[10] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[11] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[12] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[13] = atoi(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[14] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[15] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[16] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[17] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[18] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[19] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[20] = atof(how); break; } } a += 2;

				if (handz[13] == 1 && free5<13) {
					sprintf(how1, "flash[%d]", free6);
					loc = glGetUniformLocation(shaderProgram, how1);  glUniform1i(loc, free5); free6++; free5++;
					sprintf(how1, "fscol[%d]", free2);
					loc = glGetUniformLocation(shaderProgram, how1);  glUniform3f(loc, handz[14], handz[15], handz[16]);
				}
				else {
					sprintf(how1, "flash[%d]", free6);
					loc = glGetUniformLocation(shaderProgram, how1);  glUniform1i(loc, -10); free6++;
				}
				sprintf(how1, "fcol[%d]", free2);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform4f(loc, handz[17], handz[10], handz[11], handz[20]);

				sprintf(how1, "foth[%d]", free2);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform4f(loc, thm9, handz[12], handz[18], handz[19]);

				verr[ou] = xx1*zoom[hover1]; verr[ou + 1] = yy1*zoom[hover1]; verr[ou + 2] = zz1 / 10;

				rot1 = cos(thm6); mot1 = sin(thm6);
				rot2 = cos(thm7); mot2 = sin(thm7);
				rot3 = cos(thm8); mot3 = sin(thm8);
				thm1 = handx[0]; thm2 = handy[0]; thm3 = handz[0];

				xx = thm1; yy = thm2;  zz = thm3 - (thm9 / 10);
				xx -= thm1; yy -= thm2; zz -= thm3;
				//z
				xx1 = (xx*rot3) - (yy*mot3); yy1 = (xx*mot3) + (yy*rot3); zz1 = zz;
				//y
				xx = (xx1*rot2) + (zz1*mot2); yy = yy1; zz = (xx1*-1 * mot2) + (zz1*rot2);
				//x
				xx1 = xx; yy1 = (yy*rot1) - (zz*mot1); zz1 = (yy*mot1) + (zz*rot1);
				xx1 += thm1; yy1 += thm2; zz1 += thm3;
				sprintf(how1, "fdir[%d]", free2);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform3f(loc, xx1, yy1, zz1);

				free2++;
			}

			//directional
			if (thm5 == 1) {
				sprintf(how1, "dipo[%d]", free3);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform3f(loc, handx[0], handy[0], handz[0]);

				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm6 = atof(how)*3.143 / 180.0; break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm7 = atof(how)*3.143 / 180.0; break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm8 = atof(how)*3.143 / 180.0; break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; thm9 = atof(how); break; } } a += 2;

				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[10] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[11] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[12] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[13] = atoi(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[14] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[15] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[16] = atof(how); break; } } a += 2;
				for (0;a < bu;a++) { how[b] = light[a]; b++; if (light[a + 1] == ',') { how[b] = 0; b = 0; handz[17] = atof(how); break; } } a += 2;

				if (handz[13] == 1 && free5<13) {
					sprintf(how1, "sun[%d]", free4);
					loc = glGetUniformLocation(shaderProgram, how1);  glUniform1i(loc, free5); free4++; free5++;
				}
				else {
					sprintf(how1, "sun[%d]", free4);
					loc = glGetUniformLocation(shaderProgram, how1);  glUniform1i(loc, -10); free4++;
				}
				
				sprintf(how1, "dico[%d]", free3);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform4f(loc, handz[11], handz[10], handz[17], handz[12]);

				sprintf(how1, "diter[%d]", free3);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform4f(loc, thm9, handz[14], handz[15], handz[16]);
				verr[ou] = xx1*zoom[hover1]; verr[ou + 1] = yy1*zoom[hover1]; verr[ou + 2] = zz1 / 10;

				rot1 = cos(thm6); mot1 = sin(thm6);
				rot2 = cos(thm7); mot2 = sin(thm7);
				rot3 = cos(thm8); mot3 = sin(thm8);

				xx = thm1; yy = thm2;  zz = thm3 - 0.5;
				xx -= thm1; yy -= thm2; zz -= thm3;
				//z
				xx1 = (xx*rot3) - (yy*mot3); yy1 = (xx*mot3) + (yy*rot3); zz1 = zz;
				//y
				xx = (xx1*rot2) + (zz1*mot2); yy = yy1; zz = (xx1*-1 * mot2) + (zz1*rot2);
				//x
				xx1 = xx; yy1 = (yy*rot1) - (zz*mot1); zz1 = (yy*mot1) + (zz*rot1);
				xx1 += thm1; yy1 += thm2; zz1 += thm3;
				sprintf(how1, "diot[%d]", free3);
				loc = glGetUniformLocation(shaderProgram, how1);  glUniform3f(loc, xx1, yy1, zz1);

				free3++;
			}
		}
	}
	loc = glGetUniformLocation(shaderProgram, "index"); glUniform1f(loc, free1);
	loc = glGetUniformLocation(shaderProgram, "findex"); glUniform1f(loc, free2);
	loc = glGetUniformLocation(shaderProgram, "dindex"); glUniform1f(loc, free3);
}