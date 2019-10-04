#include<stdio.h>
#include<windows.h>
struct vector{
	int x;
	int y;
	int z;
};
vector track[10000],brack[10000],mrack[10000],urack[10000];
FILE *fi;
char text[1000000],how[1000000],how1[1000000];
int seek,face[10000],fnorm[10000],fvet[10000];
main(){
	fi=fopen("box.obj","r");
	fseek(fi,0,SEEK_END);
	seek=ftell(fi);
	fseek(fi,0,SEEK_SET);
	int a,c=0,b,d;
	for(a=0;a<seek;a++){
		text[a]=fgetc(fi);
	}
	fclose(fi);
	text[a]=0;
a=0; d=0;
int r=0,u=0,z=0,x=0;
for(b=0,c=0;a<seek;a++){
	if(text[a]=='v'&&text[a+1]==' '){ a+=2;
		for(0;a<seek;a++){ how[b]=text[a]; b++; if(text[a]==' '){ how[b]=0; b=0; track[c].x=atof(how)*10.0; break;}  } a++;
		for(0;a<seek;a++){ how[b]=text[a]; b++; if(text[a]==' '){ how[b]=0; b=0; track[c].y=atof(how)*10.0; break;}  } a++;
		for(0;a<seek;a++){ how[b]=text[a]; b++; if(text[a]=='\n'){ how[b]=0; b=0; track[c].z=atof(how)*10.0; break;}  } 
c++;
	}
	if(text[a]=='v'&&text[a+1]=='n'&&text[a+2]==' '){ a+=3;
		for(0;a<seek;a++){ how[b]=text[a]; b++; if(text[a]==' '){ how[b]=0; b=0; mrack[z].x=atof(how)*10.0; break;}  } a++;
		for(0;a<seek;a++){ how[b]=text[a]; b++; if(text[a]==' '){ how[b]=0; b=0; mrack[z].y=atof(how)*10.0; break;}  } a++;
		for(0;a<seek;a++){ how[b]=text[a]; b++; if(text[a]=='\n'){ how[b]=0; b=0; mrack[z].z=atof(how)*10.0; break;}  } 
z++;
	}
	if(text[a]=='v'&&text[a+1]=='t'&&text[a+2]==' '){ a+=3;
		for(0;a<seek;a++){ how[b]=text[a]; b++; if(text[a]==' '){ how[b]=0; b=0; urack[x].x=atof(how)*10.0; break;}  } a++;
		for(0;a<seek;a++){ how[b]=text[a]; b++; if(text[a]=='\n'){ how[b]=0; b=0; urack[x].y=atof(how)*10.0; break;}  } 
x++;
	}
	if(text[a]=='f'&&text[a+1]==' '){ a+=2; face[d]=-1;  fvet[d]=-1;  fnorm[d]=-1; d++;
		for(0;a<seek;a++){ how[b]=text[a]; b++; 
		if(text[a]==' '){ how[b]=0; b=0; face[d]=atoi(how)-1;  
		for(int y=0,ko=0;y<strlen(how);y++){
			if(how[y]=='/'){ ko=0; y++;
			for(0;y<strlen(how);y++){  how1[ko]=how[y]; ko++; if(how[y]=='/'){ how1[ko]=0; ko=0; fvet[d]=atoi(how1)-1; break;} } y++;
			for(0;y<strlen(how);y++){  how1[ko]=how[y]; ko++; if(how[y]==' '||how[y]=='\n'){ how1[ko]=0; ko=0; fnorm[d]=atoi(how1)-1; break;} }
			}
		} d++;
		    } 
		if(text[a]=='\n'){ how[b]=0; b=0; face[d]=atoi(how)-1; 
		for(int y=0,ko=0;y<strlen(how);y++){
			if(how[y]=='/'){ ko=0; y++;
			for(0;y<strlen(how);y++){  how1[ko]=how[y]; ko++; if(how[y]=='/'){ how1[ko]=0; ko=0; fvet[d]=atoi(how1)-1; break;} } y++;
			for(0;y<strlen(how);y++){  how1[ko]=how[y]; ko++; if(how[y]==' '||how[y]=='\n'){ how1[ko]=0; ko=0; fnorm[d]=atoi(how1)-1; break;} }
			}
		}
		d++;  break; }
		  } 
		
	}
}

printf("\n\n\n");
int ou=0,bu=0,qe=0,ki=0,mo=0,jk,lk,milk,molk,mklo;
for (a = 0;a < d;a++) {
	if(face[a+1]==-1){ ou=1; }
	
		if (ou == 1 && face[a]>=0) {
	brack[qe] = track[ki]; qe++; 
	brack[qe] = urack[jk]; qe++; printf("%d  %d  %d   ",brack[qe-1].x,brack[qe-1].y,brack[qe-1].z);
	brack[qe] = mrack[lk]; qe++; 
	
	 brack[qe] = track[milk]; qe++; 
	 brack[qe] = urack[molk]; qe++; printf("%d  %d  %d   ",brack[qe-1].x,brack[qe-1].y,brack[qe-1].z);
	 brack[qe] = mrack[mklo]; qe++;
	
	
	bu=face[a]; brack[qe]=track[bu]; qe++; milk=bu; 
	bu=fvet[a]; brack[qe]=urack[bu]; qe++;  molk=bu; printf("%d  %d  %d   ",brack[qe-1].x,brack[qe-1].y,brack[qe-1].z);
	bu=fnorm[a]; brack[qe]=mrack[bu]; qe++;  mklo=bu; 
	
		}
		if (face[a] < 0) { ou = 0; }
		if (face[a] == -1) { ou = 1;
		ki=face[a+1]; jk=fvet[a+1]; lk=fnorm[a+1]; a++;
		milk=face[a+1]; molk=fvet[a+1]; mklo=fnorm[a+1]; a++;
		 }
		
	}
	
sprintf(text,"");
for(a=0,c=0;a<qe;a++){
	
	text[c]=brack[a].z+100; c++;
	text[c]=brack[a].x+100; c++;
	text[c]=brack[a].y+100; c++;
}
text[c]=0;

printf("                                       ");
printf("%s",text);
fi=fopen("plane.bin","w");
fprintf(fi,text);
fclose(fi);
getchar();
return 0;	
}
