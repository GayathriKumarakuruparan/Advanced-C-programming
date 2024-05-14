#include<stdio.h>
#include"music.h"

//Edit info
Status editInfo(Music *music,char *ch,char *name);

//rename info
Status renametag(Music *music,char *ch,char *name,FILE *fptr_des);

//copying the header
Status copyheader(FILE *fp,FILE *fptr_des);

//to check the option
edittag checkit(char *ch);

//to copy content
Status copyContent(FILE *fname,int pos,FILE *fptr_des);

//to copy new content
Status copyNewContent(FILE *fp,char *name,FILE *fptr_des);

//to copy remaining data

Status copyremaining(FILE *fname,int size,FILE *fptr_des);

//to copy all content in original
Status copytooriginal(FILE *fname,FILE *fptr_des);
