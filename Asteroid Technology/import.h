void import(char* how) {
	realloc(diffuse, sizeof(GLuint**)*(objc + 3));
	
	diffuse[objc] = (GLuint*)malloc(sizeof(GLuint*)*500000);
	realloc(texturename, sizeof(char**)*(objc + 3));
	sprintf_s(bit, "");

	hfile = CreateFile(how, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	dwFileSize = GetFileSize(hfile, NULL);
	objs = (LPSTR)GlobalAlloc(GPTR, dwFileSize + 1);
	if (objs != NULL) {
		if (ReadFile(hfile, objs, dwFileSize, &dwRead, NULL)) {
	objs[dwFileSize] = 0;
	sprintf_s(tree, "%s%s:", tree, stantent[selet4]);
	free10=0;
	int b = dwFileSize, d = 0, m = 0, n = 0, o = 0, w = 0,z=0,y=0,qt=0,nin=0,onmat=0;
	
	for (int a = 0;a < b;a++) {
		if (objs[a] == 'm'&&objs[a + 1] == 't'&&objs[a + 2] == 'l'&&objs[a + 3] == 'l'&&objs[a + 4] == 'i'&&objs[a + 5] == 'b'&&objs[a + 6] == ' ') {
			a += 6;
			for (0;a < b;a++) { if (objs[a] != ' '&&objs[a] != '	'&&objs[a] != '\r'&&objs[a] != '\n') { break; } }
			for (int c = 0;a < b;a++) {
				how1[c] = objs[a]; c++; if (objs[a + 1] == '\n' || objs[a + 1] == '\r') {
							how1[c] = 0;
	sprintf_s(how2, "%s\\%s", path, how1);
	CloseHandle(hfile);
	hfile = CreateFile(how2, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	dwFileSize = GetFileSize(hfile, NULL);
	objsm = (LPSTR)GlobalAlloc(GPTR, dwFileSize + 1);
	if (ReadFile(hfile, objsm, dwFileSize, &dwRead, NULL)) {
		objsm[dwFileSize] = 0;
		sprintf_s(matie, "");
		n = strlen(objsm); o = 0;
		for (int q = 0;q < n;q++) {
			if (objsm[q] == 'n'&&objsm[q + 1] == 'e'&&objsm[q + 2] == 'w'&&objsm[q + 3] == 'm'&&objsm[q + 4] == 't'&&objsm[q + 5] == 'l') {
				q += 6;
				for (0;q < n;q++) { if (objsm[q] != ' '&&objsm[q] != '	'&&objsm[q] != '\r'&&objsm[q] != '\n') { break; } }
				for (int c = 0;q < n;q++) { how1[c] = objsm[q]; c++; if (objsm[q + 1] == '\n' || objsm[q + 1] == '\r' || objsm[q + 1] == '	' || objsm[q + 1] == ' ') { how1[c] = 0; break; } }
				sprintf_s(matie, "%s%s;", matie, how1);
				o++;
				prop[o - 1].text = -1; prop[o - 1].Tr = 1; prop[o - 1].bum = -1; prop[o-1].bump=-1; prop[o-1].tex=-1; prop[o-1].shade=1;
				prop[o-1].emK=-1; prop[o-1].emmap=-1; prop[o-1].spemap= -1; prop[o-1].ss=0.5; prop[o-1].si=50; prop[o-1].sm=-1; prop[o-1].Kd=0; prop[o-1].Ks=0; prop[o-1].emit=0.0;
				prop[o-1].NORS=1; prop[o-1].NSI=0; prop[o-1].rfls=0; prop[o-1].rfi=0; prop[o-1].emt=1; prop[o-1].emtmap=-1; prop[o-1].emr=1; prop[o-1].emg=1; prop[o-1].emb=1; prop[o-1].rfk=-1; prop[o-1].rfmap=-1;
			}
if (objsm[q] == 'm'&&objsm[q + 1] == 'a'&&objsm[q + 2] == 'p'&&objsm[q + 3] == '_'&&objsm[q + 4] == 'B'&&objsm[q + 5] == 'u'&&objsm[q + 6] == 'm'&&objsm[q + 7] == 'p'&&objsm[q + 8] == ' '&&qt<4999995) {
		q += 8;
		for (0;q < n;q++) { if (objsm[q] != ' '&&objsm[q] != '	'&&objsm[q] != '\r'&&objsm[q] != '\n') { break; } }
		for (int c = 0;q < n;q++) { how1[c] = objsm[q]; c++; if (objsm[q + 1] == '\n' || objsm[q + 1] == '\r') { how1[c] = 0; color[w].x = atof(how1); break; } } q++;
		int e = 0;
		for (int f = 0;f < strlen(how1);f++) { if (how1[f] == ':') { e = 1; break; } }
		if (e == 0) { sprintf_s(how2, "%s\\%s", path, how1); }
		else { sprintf_s(how2, "%s", how1); }
		realloc(diffuse[objc], sizeof(GLuint*)*(qt+3));
		sprintf_s(bit, "%s%s;", bit, how2);
		image = SOIL_load_image(how2, &width, &height, 0, SOIL_LOAD_RGBA);
		if(image){
		glGenTextures(1, &diffuse[objc][qt]);
		glBindTexture(GL_TEXTURE_2D, diffuse[objc][qt]);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);
		SOIL_free_image_data(image);
		glBindTexture(GL_TEXTURE_2D, 0);
		prop[o - 1].bump = qt;
		prop[o - 1].bum = 1;
		qt++;
		}
	}

if (objsm[q - 1] != '_'&&objsm[q] == 'b'&&objsm[q + 1] == 'u'&&objsm[q + 2] == 'm'&&objsm[q + 3] == 'p'&&objsm[q + 4] == ' '&&qt < 4999995) {
	q += 4;
	for (0;q < n;q++) { if (objsm[q] != ' '&&objsm[q] != '	'&&objsm[q] != '\r'&&objsm[q] != '\n') { break; } }
	for (int c = 0;q < n;q++) { how1[c] = objsm[q]; c++; if (objsm[q + 1] == '\n' || objsm[q + 1] == '\r') { how1[c] = 0; color[w].x = atof(how1); break; } } q++;
	int e = 0;
	for (int f = 0;f < strlen(how1);f++) { if (how1[f] == ':') { e = 1; break; } }
	if (e == 0) { sprintf_s(how2, "%s\\%s", path, how1); }
	else { sprintf_s(how2, "%s", how1); }
	realloc(diffuse[objc], sizeof(GLuint*)*(qt + 3));
	sprintf_s(bit, "%s%s;", bit, how2);

	image = SOIL_load_image(how2, &width, &height, 0, SOIL_LOAD_RGBA);
	if (image) {
	glGenTextures(1, &diffuse[objc][qt]);
	glBindTexture(GL_TEXTURE_2D, diffuse[objc][qt]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
	prop[o - 1].bump = qt;
	prop[o - 1].bum = 1;
	qt++;
}
	}
//Reflection
//specular
if (objsm[q] == 'm'&&objsm[q + 1] == 'a'&&objsm[q + 2] == 'p'&&objsm[q + 3] == '_'&&objsm[q + 4] == 'N'&&objsm[q + 5] == 's'&&qt<4999995) { q += 6;
for (0;q < n;q++) { if (objsm[q] != ' '&&objsm[q] != '	'&&objsm[q] != '\r'&&objsm[q] != '\n') { break; } }
for (int c = 0;q < n;q++) { how1[c] = objsm[q]; c++; if (objsm[q + 1] == '\n' || objsm[q + 1] == '\r') { how1[c] = 0; color[w].x = atof(how1); break; } } q++;
int e = 0;
for (int f = 0;f < strlen(how1);f++) { if (how1[f] == ':') { e = 1; break; } }
if (e == 0) { sprintf_s(how2, "%s\\%s", path, how1); }else{ sprintf_s(how2,"%s",how1); }
realloc(diffuse[objc], sizeof(GLuint*)*(qt + 3));
sprintf_s(bit, "%s%s;", bit, how2);
image = SOIL_load_image(how2, &width, &height, 0,SOIL_LOAD_RGBA);
if (image) {
	glGenTextures(1, &diffuse[objc][qt]);
	glBindTexture(GL_TEXTURE_2D, diffuse[objc][qt]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
	prop[o - 1].rfmap= qt;
	prop[o - 1].rfk= 1;
	qt++;
}
}

//specular
if (objsm[q] == 'm'&&objsm[q + 1] == 'a'&&objsm[q + 2] == 'p'&&objsm[q + 3] == '_'&&objsm[q + 4] == 'K'&&objsm[q + 5] == 's'&&qt<4999995) { q += 6;
for (0;q < n;q++) { if (objsm[q] != ' '&&objsm[q] != '	'&&objsm[q] != '\r'&&objsm[q] != '\n') { break; } }
for (int c = 0;q < n;q++) { how1[c] = objsm[q]; c++; if (objsm[q + 1] == '\n' || objsm[q + 1] == '\r') { how1[c] = 0; color[w].x = atof(how1); break; } } q++;
int e = 0;
for (int f = 0;f < strlen(how1);f++) { if (how1[f] == ':') { e = 1; break; } }
if (e == 0) { sprintf_s(how2, "%s\\%s", path, how1); }else{ sprintf_s(how2,"%s",how1); }
realloc(diffuse[objc], sizeof(GLuint*)*(qt + 3));
sprintf_s(bit, "%s%s;", bit, how2);
image = SOIL_load_image(how2, &width, &height, 0,SOIL_LOAD_RGBA);
if (image) {
	glGenTextures(1, &diffuse[objc][qt]);
	glBindTexture(GL_TEXTURE_2D, diffuse[objc][qt]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
	prop[o - 1].spemap = qt;
	prop[o - 1].sm = 1;
	qt++;
}
}

if (objsm[q] == 'm'&&objsm[q + 1] == 'a'&&objsm[q + 2] == 'p'&&objsm[q + 3] == '_'&&objsm[q + 4] == 'K'&&objsm[q + 5] == 'd'&&qt<4999995) { q += 6;
for (0;q < n;q++) { if (objsm[q] != ' '&&objsm[q] != '	'&&objsm[q] != '\r'&&objsm[q] != '\n') { break; } }
for (int c = 0;q < n;q++) { how1[c] = objsm[q]; c++; if (objsm[q + 1] == '\n' || objsm[q + 1] == '\r') { how1[c] = 0; color[w].x = atof(how1); break; } } q++;
int e = 0;
for (int f = 0;f < strlen(how1);f++) { if (how1[f] == ':') { e = 1; break; } }
if (e == 0) { sprintf_s(how2, "%s\\%s", path, how1); }else{ sprintf_s(how2,"%s",how1); }
realloc(diffuse[objc], sizeof(GLuint*)*(qt + 3));
sprintf_s(bit, "%s%s;", bit, how2);
image = SOIL_load_image(how2, &width, &height, 0,SOIL_LOAD_RGBA);
if (image) {
	glGenTextures(1, &diffuse[objc][qt]);
	glBindTexture(GL_TEXTURE_2D, diffuse[objc][qt]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
	prop[o - 1].tex = qt;
	prop[o - 1].text = 1;
	qt++;
}
}

if (objsm[q - 1] != '_'&&objsm[q] == 'N'&&objsm[q + 1] == 's') {
	q += 2;
	for (0;q < n;q++) { if (objsm[q] != ' '&&objsm[q] != '	'&&objsm[q] != '\r'&&objsm[q] != '\n') { break; } }
	for (int c = 0;q < n;q++) { how1[c] = objsm[q]; c++; if (objsm[q + 1] == '\n' || objsm[q + 1] == '\r' || objsm[q + 1] == '	' || objsm[q + 1] == ' ') { how1[c] = 0;  break; } } q++;
	prop[o - 1].si = atof(how1)-18;
	if(prop[o-1].si<1){ prop[o-1].si=1; }
}
if (objsm[q - 1] != '_'&&objsm[q] == 'N'&&objsm[q + 1] == 'i') {
	q += 2;
	for (0;q < n;q++) { if (objsm[q] != ' '&&objsm[q] != '	'&&objsm[q] != '\r'&&objsm[q] != '\n') { break; } }
	for (int c = 0;q < n;q++) { how1[c] = objsm[q]; c++; if (objsm[q + 1] == '\n' || objsm[q + 1] == '\r' || objsm[q + 1] == '	' || objsm[q + 1] == ' ') { how1[c] = 0;  break; } } q++;
	prop[o - 1].rfls= 1.0-atof(how1); if(prop[o-1].rfls<0){ prop[0-1].rfls=0; }
}

if (objsm[q - 1] != '_'&&objsm[q] == 'K'&&objsm[q + 1] == 's'&&w<1000000) {
	q += 2;
	for (0;q < n;q++) { if (objsm[q] != ' '&&objsm[q] != '	'&&objsm[q] != '\r'&&objsm[q] != '\n') { break; } }
	for (int c = 0;q < n;q++) { how1[c] = objsm[q]; c++; if (objsm[q + 1] == '\n' || objsm[q + 1] == '\r' || objsm[q + 1] == '	' || objsm[q + 1] == ' ') { how1[c] = 0; color[w].x = atof(how1); break; } } q++;
	for (0;q < n;q++) { if (objsm[q] != ' '&&objsm[q] != '	'&&objsm[q] != '\r'&&objsm[q] != '\n') { break; } }
	for (int c = 0;q < n;q++) { how1[c] = objsm[q]; c++; if (objsm[q + 1] == '\n' || objsm[q + 1] == '\r' || objsm[q + 1] == '	' || objsm[q + 1] == ' ') { how1[c] = 0; color[w].y = atof(how1); break; } } q++;
	for (0;q < n;q++) { if (objsm[q] != ' '&&objsm[q] != '	'&&objsm[q] != '\r'&&objsm[q] != '\n') { break; } }
	for (int c = 0;q < n;q++) { how1[c] = objsm[q]; c++; if (objsm[q + 1] == '\n' || objsm[q + 1] == '\r' || objsm[q + 1] == '	' || objsm[q + 1] == ' ') { how1[c] = 0; color[w].z = atof(how1); break; } } q++;
	prop[o - 1].Ks=w;
	w++;
}
	if (objsm[q-1]!='_'&&objsm[q] == 'K'&&objsm[q + 1] == 'd'&&w<1000000) {
			q += 2;
	for (0;q < n;q++) { if (objsm[q] != ' '&&objsm[q] != '	'&&objsm[q] != '\r'&&objsm[q] != '\n') { break; } }
	for (int c = 0;q < n;q++) { how1[c] = objsm[q]; c++; if (objsm[q + 1] == '\n' || objsm[q + 1] == '\r' || objsm[q + 1] == '	' || objsm[q + 1] == ' ') { how1[c] = 0; color[w].x = atof(how1); break; } } q++;
	for (0;q < n;q++) { if (objsm[q] != ' '&&objsm[q] != '	'&&objsm[q] != '\r'&&objsm[q] != '\n') { break; } }
	for (int c = 0;q < n;q++) { how1[c] = objsm[q]; c++; if (objsm[q + 1] == '\n' || objsm[q + 1] == '\r' || objsm[q + 1] == '	' || objsm[q + 1] == ' ') { how1[c] = 0; color[w].y = atof(how1); break; } } q++;
	for (0;q < n;q++) { if (objsm[q] != ' '&&objsm[q] != '	'&&objsm[q] != '\r'&&objsm[q] != '\n') { break; } }
	for (int c = 0;q < n;q++) { how1[c] = objsm[q]; c++; if (objsm[q + 1] == '\n' || objsm[q + 1] == '\r' || objsm[q + 1] == '	' || objsm[q + 1] == ' ') { how1[c] = 0; color[w].z = atof(how1); break; } } q++;
			prop[o-1].Kd = w;
			w++;
		}

	//transparency
	if (objsm[q] == 'd'&&objsm[q + 1] == ' ') {
		q++;
		for (0;q < n;q++) { if (objsm[q] != ' '&&objsm[q] != '	'&&objsm[q] != '\r'&&objsm[q] != '\n') { break; } }
		for (int c = 0;q < n;q++) { how1[c] = objsm[q]; c++; if (objsm[q + 1] == '\n' || objsm[q + 1] == '\r' || objsm[q + 1] == '	' || objsm[q + 1] == ' ') { how1[c] = 0;  break; } } q++;
		prop[o - 1].Tr = atof(how1);
	}

	}

				}
				else { report1 = 1; sprintf_s(report, "Error: Could not load material library"); }
				break;
			}
		} a++;
		CloseHandle(hfile);
	}
	//usemtl
	if (objs[a] == 'u'&&objs[a + 1] == 's'&&objs[a + 2] == 'e'&&objs[a + 3] == 'm'&&objs[a + 4] == 't'&&objs[a + 5] == 'l'&&m<1000000) {
		if (onmat == 0) {
			sprintf_s(tree, "%sDefault;", tree);
			fnice[m] = -3;  m++; fnice[m] = -4;  m++;  fnice[m] = -8;  m++; fnice[m] = -10; m++; nin++;
			onmat = 1;
		}
		a += 6; int c = 0;
		for (0;a < b;a++) { if (objs[a] != ' '&&objs[a] != '	'&&objs[a] != '\r'&&objs[a] != '\n') { break; } }
		for (0;a < b;a++) { how1[c] = objs[a]; c++; if (objs[a + 1] == '\n' || objs[a + 1] == '\r') { break; } }
		int tim = 0,k=0; how1[c] = 0;
		for (int y = 0;y < strlen(matie);y++) {
			if (matie[y] == how1[k]) { k++; }
			else { k = 0; }
			if (k >= strlen(how1) && matie[y + 1] == ';') { fnice[m] = -2; m++;  fnice[m] = tim; m++; break; }
			if (matie[y] == ';') { tim++; }
		}
		if(k<strlen(how1)){
		fnice[m] = -2; m++;  fnice[m] = -10; m++;
		}
		

	}
	//grouping
	if (objs[a] == 'g'&&objs[a + 1] == ' ') {
		if (objs[a - 1] == ' ' || objs[a - 1] == '	' || objs[a - 1] == '\r' || objs[a - 1] == '\n') {
			a++;
			for (0;a < b;a++) { if (objs[a] != ' '&&objs[a] != '	'&&objs[a] != '\r'&&objs[a] != '\n') { break; } }
			for (int c = 0;a < b;a++) { how1[c] = objs[a]; c++; if (objs[a + 1] == '\n' || objs[a + 1] == '\r' || objs[a + 1] == '	' || objs[a + 1] == ' ') { how1[c] = 0; break; } }
			sprintf_s(tree, "%s%s;", tree, how1);
			fnice[m] = -3;  m++; fnice[m] = -4;  m++;  fnice[m] = -8;  m++; fnice[m] = -10; m++; nin++;
			onmat = 1;
		}
	vertices[free10]=d; free10++;
	}
	if (objs[a] == 'o'&&objs[a + 1] == ' ') {
		if (objs[a-1] == ' ' || objs[a-1] == '	' || objs[a-1] == '\r' || objs[a-1] == '\n') {
		a++;
		for (0;a < b;a++) { if (objs[a] != ' '&&objs[a] != '	'&&objs[a] != '\r'&&objs[a] != '\n') { break; } }
		for (int c = 0;a < b;a++) { how1[c] = objs[a]; c++; if (objs[a + 1] == '\n' || objs[a + 1] == '\r' || objs[a + 1] == '	' || objs[a + 1] == ' ') { how1[c] = 0; break; } }
		sprintf_s(tree, "%s%s;", tree, how1);
		fnice[m] = -3;  m++; fnice[m] = -4;  m++;  fnice[m] = -8;  m++; fnice[m] = -10; m++; nin++;
		onmat = 1;
		}
		vertices[free10]=d; free10++;
	}
	//faces
	if (objs[a] == 'f'&&objs[a + 1] == ' '&& m<1000000) {
		if (onmat == 0) {
			sprintf_s(tree, "%sDefault;", tree);
			fnice[m] = -3;  m++; fnice[m] = -4;  m++;  fnice[m] = -8;  m++; fnice[m] = -10; m++; nin++;
			onmat = 1;
		}

		a += 1; fnice[m] = -1; m++; int r = 0;
		for (0;a < b;a++) {
			for (0;a < b;a++) { if (objs[a] != ' '&&objs[a] != '	'&&objs[a] != '\r'&&objs[a] != '\n') { break; } }
			for (int c = 0;a < b;a++) { how1[c] = objs[a]; c++; if (objs[a + 1] == '\n' || objs[a + 1] == '\r' || objs[a + 1] == '	' || objs[a + 1] == ' ') { how1[c] = 0; fnice[m] = atoi(how1);  break; } }
			
			sprintf_s(how2, ""); r = 0;
			for (int h = strlen(how1);h > 0;h--) { if (how1[h] == '/') { h++; for (0;h < strlen(how1);h++) { how2[r] = how1[h]; r++; } break; } }
			fnom[m] = atoi(how2);
			
			sprintf_s(how2, "");  r = 0;
			for (int x = 0, l = 0;x < strlen(how1);x++) { 
			if(l==1){ how2[r]=how1[x]; r++; }
			if (how1[x] == '/'&&how1[x + 1] != '/'&&how1[x - 1] != '/') { l = 1; }
			}
			how2[r] = 0;
			fcice[m] = atoi(how2);
			m++;
			if (objs[a + 1] == '\n' || objs[a + 1] == '\r') { break; }
		}

	}
	//vertices
	if (objs[a] == 'v'&&objs[a + 1] == ' '&&d<1000000) {
		a += 1;
		for (0;a < b;a++) { if (objs[a] != ' '&&objs[a] != '	'&&objs[a] != '\r'&&objs[a] != '\n') { break; } }
		for (int c = 0;a < b;a++) { how1[c] = objs[a]; c++; if (objs[a + 1] == '\n' || objs[a + 1] == '\r' || objs[a + 1] == '	' || objs[a + 1] == ' ') { how1[c] = 0; handx[d] = atof(how1); break; } } a++;

		for (0;a < b;a++) { if (objs[a] != ' '&&objs[a] != '	'&&objs[a] != '\r'&&objs[a] != '\n') { break; } }
		for (int c = 0;a < b;a++) { how1[c] = objs[a]; c++; if (objs[a + 1] == '\n' || objs[a + 1] == '\r' || objs[a + 1] == '	' || objs[a + 1] == ' ') { how1[c] = 0; handy[d] = atof(how1); break; } } a++;

		for (0;a < b;a++) { if (objs[a] != ' '&&objs[a] != '	'&&objs[a] != '\r'&&objs[a] != '\n') { break; } }
		for (int c = 0;a < b;a++) { how1[c] = objs[a]; c++; if (objs[a + 1] == '\n' || objs[a + 1] == '\r' || objs[a + 1] == '	' || objs[a + 1] == ' ') { how1[c] = 0; handz[d] = atof(how1); break; } } a++;


		d++;
				}
	//texture
	if (objs[a] == 'v'&&objs[a + 1] == 't'&&objs[a + 2] == ' '&&z<1000000) {
		a += 2; 
		for (0;a < b;a++) { if (objs[a] != ' '&&objs[a] != '	'&&objs[a] != '\r'&&objs[a] != '\n') { break; } }
		for (int c = 0;a < b;a++) { how1[c] = objs[a]; c++; if (objs[a + 1] == '\n' || objs[a + 1] == '\r' || objs[a + 1] == '	' || objs[a + 1] == ' ') { how1[c] = 0; mext[z].x = atof(how1); break; } } a++;
		for (0;a < b;a++) { if (objs[a] != ' '&&objs[a] != '	'&&objs[a] != '\r'&&objs[a] != '\n') { break; } }
		for (int c = 0;a < b;a++) { how1[c] = objs[a]; c++; if (objs[a + 1] == '\n' || objs[a + 1] == '\r' || objs[a + 1] == '	' || objs[a + 1] == ' ') { how1[c] = 0; mext[z].y = atof(how1); break; } } a++;
		z++;
	}
	//norm
	if (objs[a] == 'v'&&objs[a + 1] == 'n'&&objs[a + 2] == ' '&&y<1000000) {
		a += 2;
		for (0;a < b;a++) { if (objs[a] != ' '&&objs[a] != '	'&&objs[a] != '\r'&&objs[a] != '\n') { break; } }
		for (int c = 0;a < b;a++) { how1[c] = objs[a]; c++; if (objs[a + 1] == '\n' || objs[a + 1] == '\r' || objs[a + 1] == '	' || objs[a + 1] == ' ') { how1[c] = 0; betxx[y].x = atof(how1); break; } } a++;

		for (0;a < b;a++) { if (objs[a] != ' '&&objs[a] != '	'&&objs[a] != '\r'&&objs[a] != '\n') { break; } }
		for (int c = 0;a < b;a++) { how1[c] = objs[a]; c++; if (objs[a + 1] == '\n' || objs[a + 1] == '\r' || objs[a + 1] == '	' || objs[a + 1] == ' ') { how1[c] = 0; betxx[y].y = atof(how1); break; } } a++;

		for (0;a < b;a++) { if (objs[a] != ' '&&objs[a] != '	'&&objs[a] != '\r'&&objs[a] != '\n') { break; } }
		for (int c = 0;a < b;a++) { how1[c] = objs[a]; c++; if (objs[a + 1] == '\n' || objs[a + 1] == '\r' || objs[a + 1] == '	' || objs[a + 1] == ' ') { how1[c] = 0; betxx[y].z = atof(how1); break; } } a++;
		y++;
	}

	}
	
	b = objc;
	vertices[free10]=d; free10++;
	texturename[b] = (char*)malloc(strlen(bit) * sizeof(char*));
	sprintf(texturename[b], "%s",bit);
	
	realloc(showobj,sizeof(int*)*(b+3));
	showobj[b]=1;

	realloc(fice, sizeof(int**)*(b + 3));
	realloc(grup, sizeof(int**)*(b + 3));
	realloc(subg, sizeof(int*)*(b + 3));
	realloc(matcount, sizeof(int*)*(b + 3));
	matcount[b]=qt;

	realloc(vers, sizeof(int*)*(b + 3));
	realloc(fcon, sizeof(int*)*(b + 3));
	realloc(materil, sizeof(char**)*(b + 3));
	realloc(colr, sizeof(vectz**)*(b + 3));
	realloc(mauv, sizeof(vectz*)*((b + 3)*3));
	realloc(gcont, sizeof(int*)*(b + 3));
	realloc(scil, sizeof(vectz*)*((b + 3)*3));
	realloc(rita, sizeof(vectz*)*((b + 3)*3));
	realloc(gauv, sizeof(vectz**)*(b + 3));
	realloc(rota, sizeof(vectz**)*(b + 3));
	realloc(scal, sizeof(vectz**)*(b + 3));
	gauv[b] = (vectz*)malloc(sizeof(vectz*) * (free10*3));
	scal[b] = (vectz*)malloc(sizeof(vectz*) * (free10*3));
	rota[b] = (vectz*)malloc(sizeof(vectz*) * (free10*3));
	realloc(frame, sizeof(vectz**)*(b + 3));
	frame[b] = (vectz*)malloc(sizeof(vectz*) * (nin * 3));
	realloc(mtc, sizeof(int*)*(b + 3));
	materil[b] = (char*)malloc(sizeof(char*) * (strlen(matie) + 3));
	colr[b] = (vectz*)malloc(sizeof(vectz*) * (w * 3));
	realloc(matprop, sizeof(mantel**)*(b + 3));
	matprop[b] = (mantel*)malloc(sizeof(mantel*) * (o*26));
	realloc(center, sizeof(vectz**)*(b + 3));

	fice[b] = (int*)malloc(sizeof(int*) * (m + 3));
	fcon[b] = m;
	
	mauv[b].x = mmx/zmx; mauv[b].y = mmy/zmx; mauv[b].z = mmz/zmx;
	mauv[b].x -= pan1; mauv[b].y -= pan2; mauv[b].z -= pan3;
	mtc[b] = o;
	scil[b].x=1; scil[b].y=1; scil[b].z=1;
	rita[b].x=0; rita[b].y=0; rita[b].z=0;


	for (int a = 0;a < w;a++) {
		colr[b][a].x = color[a].x;
		colr[b][a].y = color[a].y;
		colr[b][a].z = color[a].z;
	}
	for (int a = 0;a < o;a++) { matprop[b][a] = prop[a]; }
	
	//centroid
	center[b] = (vectz*)malloc(sizeof(vectz*) * ((free10) * 3));
	for(int a=1,c=0;a<free10;a++){ 
	thm1=0;  thm2=0;  thm3=0; 
	for(c=vertices[a-1];c<vertices[a];c++){
	thm1+=handx[c]; thm2+=handy[c]; thm3+=handz[c];
	}
	if((vertices[a]-vertices[a-1])>0){
	thm1/=(vertices[a]-vertices[a-1]);
	thm2/=(vertices[a]-vertices[a-1]);
	thm3/=(vertices[a]-vertices[a-1]);

	}
	center[b][a-1].x=thm1; center[b][a-1].y=thm2; center[b][a-1].z=thm3;
	}
	//end centroid

	free1 = 0; ou = 0; free5 = 0; 
	for (int a = 0;a < m;a++) {
if(ou==1&&fnice[a]>=0){  a++;
for (0;a < m;a++) {
if(fnice[a+1]<0 ||a+1>=m ){ break;}
	
	free1+=3;
}
}
if(fnice[a]==-2){ indices[free5]=free1; free5++; }
if(fnice[a]==-3){ indices[free5]=free1; free5++; }
if(fnice[a]<0){ ou=0;}
if(fnice[a]==-1){ ou=1; }
	}
	
	//bufary begins
	vers[b] = ((free1+1 ) * 8);
	verco+=free1+1;
	realloc(obcc, sizeof(int*)*(b + 3));
	obcg++;
	//second triangulation
	ou = 0; bu = 0;
	for (int a = 0;a <= m;a++) {

if(ou==1&&fnice[a]>=0){ free1=fnice[a]-1; free3=fcice[a]-1; free4=fnom[a]-1; a++;
for (0;a <= m;a++) {
if(fnice[a+1]<0 ||a+1>=m ){ break;}

bufary[bu+bued] = handx[free1]; bufary[bu + 1+bued] = handy[free1]; bufary[bu + 2+bued] = handz[free1];
bufary[bu+bued + 3] = mext[free3].x; bufary[bu + 4+bued] = mext[free3].y;
bufary[bu + 5+bued] = betxx[free4].x; bufary[bu + 6+bued] = betxx[free4].y; bufary[bu + 7+bued] = betxx[free4].z;
bu += 8;

free2=fnice[a]-1;
bufary[bu+bued] = handx[free2]; bufary[bu + 1+bued] = handy[free2]; bufary[bu + 2+bued] = handz[free2];
free2 = fcice[a] - 1;
bufary[bu+bued + 3] = mext[free2].x; bufary[bu + 4+bued] = mext[free2].y;
free2 = fnom[a] - 1; 
bufary[bu + 5+bued] = betxx[free2].x; bufary[bu + 6+bued] = betxx[free2].y; bufary[bu + 7+bued] = betxx[free2].z;
bu += 8;

free2 = fnice[a+1]-1;
bufary[bu+bued] = handx[free2]; bufary[bu + 1+bued] = handy[free2]; bufary[bu + 2+bued] = handz[free2];
free2 = fcice[a+1] - 1;
bufary[bu+bued + 3] = mext[free2].x; bufary[bu + 4+bued] = mext[free2].y;
free2 = fnom[a+1] - 1; 
bufary[bu + 5+bued] = betxx[free2].x; bufary[bu + 6+bued] = betxx[free2].y; bufary[bu + 7+bued] = betxx[free2].z;
bu += 8;
}
}


if(fnice[a]<0){ ou=0;}
if(fnice[a]==-1){ ou=1; }
	}
free5=bued;	bued+=bu; obcc[b]=bu*1.0/8.0;
	
	//bufary ends
	gcont[b]=free10-2;

	for (int a = 0;a <free10-1;a++) {
	gauv[b][a].x =0; gauv[b][a].y = 0; gauv[b][a].z = 0; 
	scal[b][a].x =1; scal[b][a].y = 1; scal[b][a].z = 1;
	rota[b][a].x =0; rota[b][a].y = 0; rota[b][a].z = 0;
		frame[b][a].x = 0; frame[b][a].y = 0; frame[b][a].z = 0;
	}

	
	for (ou = 0;ou < strlen(matie);ou++) {
		materil[b][ou] = matie[ou];
	}
	materil[b][ou] = 0;
	
	ou = 0; bu = 0;
	for (int a = 0,ju=0;a < m;a++) {
	if(fnice[a]<0){ ju=0; }
	if(fnice[a]==-1){ ju=1;}
	
	if(ju==0&&fnice[a]!=-3&&fnice[a]!=-2){ handx[ou] = fnice[a]; ou++; 
	
	}
	if (ju == 0 && fnice[a] == -2) {
		handx[ou] = fnice[a]; ou++; handx[ou] = indices[bu]; ou++;
		bu++;
	}
	if (ju == 0 && fnice[a] == -3) {
		handx[ou] = fnice[a]; ou++; handx[ou] = indices[bu]; ou++;
		bu++;
	}
	}

	fice[b] = (int*)malloc(sizeof(int*) * (ou + 3));
	fcon[b] = ou;
	for(int a=0;a<ou;a++){ fice[b][a]=handx[a];  }

	//group position
	int dis = 0;
	for (int a = 0;a < ou;a++) {
		if (fice[b][a] == -3&&dis<50000) { grop[dis] = fice[b][a + 1]; dis++; }
	}

	grup[b] = (int*)malloc(sizeof(int*)*dis);
	subg[b] = dis - 1;
	for (int a = 0;a < dis;a++) { grup[b][a] = grop[a]; }

	sprintf_s(tree, "%s\n", tree);

	SetRect(&rc, 0, csize2 - 25, csize, csize2);
	ValidateRect(hwnd, &rc); InvalidateRect(hwnd, &rc, TRUE);
	objc++;
		}
	}
	else { sprintf_s(report, "Error loading Object"); report1 = 1; SetTimer(hwnd, 1, 3000, NULL); }
	


}
