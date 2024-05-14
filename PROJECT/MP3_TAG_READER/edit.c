#include"edit.h"
#include<string.h>

Status editInfo(Music *music,char *ch,char *name)
{
    if(openfile(music)==SUCCESS)
    {
	FILE *fptr_des=fopen("sample1.mp3","wb+");

	if(fptr_des == NULL)
	{
	    perror("fopen");
	    fprintf(stderr,"Unable to open the file %s\n","sample1.mp3");
	    return FAILURE;
	}

	if(checkheaderandversion(music->fp)==SUCCESS)
	{

	    if(readInfo(music)==SUCCESS)
	    {

		renametag(music, ch, name,fptr_des);
		copytooriginal(music->fp, fptr_des);
	    }
	}

    }
}


Status renametag(Music *music,char *ch,char *name,FILE *fptr_des)
{
    if(copyheader(music->fp,fptr_des)==SUCCESS)
    {
	switch(checkit(ch))
	{
	    case t:
		copyContent(music->fp, music->pos[m_title], fptr_des);
		copyNewContent(music->fp, name,fptr_des);
		copyremaining(music->fp, music->Title_size, fptr_des);
		break;

	    case a:
		copyContent(music->fp, music->pos[m_album], fptr_des);
		copyNewContent(music->fp, name, fptr_des);
                copyremaining(music->fp, music->Album_size, fptr_des);
		break;

	    case A:
		copyContent(music->fp, music->pos[m_artist], fptr_des);
		copyNewContent(music->fp, name,fptr_des);
		copyremaining(music->fp, music->Artist_size, fptr_des);
		break;

	    case y:
		copyContent(music->fp, music->pos[m_year], fptr_des);
		copyNewContent(music->fp, name, fptr_des);
		copyremaining(music->fp,music->Year_size,fptr_des);
		break;

	    case m:
		copyContent(music->fp, music->pos[m_genre], fptr_des);
		copyNewContent(music->fp, name, fptr_des);
		copyremaining(music->fp, music->Genre_size, fptr_des);
		break;

	    case c:
		copyContent(music->fp, music->pos[m_comment], fptr_des);
		copyNewContent(music->fp, name, fptr_des);
		copyremaining(music->fp, music->Com_size, fptr_des);
		break;

	    default:
		break;
	}
    }
}



Status copyContent(FILE *fname,int pos,FILE *fptr_des)
{
    char ch;
    for(int i=10;i<pos;i++)
    {
	fread(&ch,1,1,fname);
	fwrite(&ch,1,1,fptr_des);
    }
}



Status copyNewContent(FILE *fp,char *name,FILE *fptr_des)
{
    int len=strlen(name)-1;
    char bytes[4];


    for(int i=0;i<4;i++)
    {
	bytes[3-i]=((len>>8*i) & 0xFF);
    }

    fwrite(bytes,4,1,fptr_des);
    fseek(fp,4,SEEK_CUR);

    char buf[3];
    fread(buf,3,1,fp);
    fwrite(buf,3,1,fptr_des);
    fwrite(name,(len-1),1,fptr_des);

    return SUCCESS;
}


Status copyremaining(FILE *fname,int size,FILE *fptr_des)
{
    fseek(fname,size,SEEK_CUR);
    char ch;

    while(fread(&ch,1,1,fname))
    {
	fwrite(&ch,1,1,fptr_des);
    }

    return SUCCESS;
}



Status copyheader(FILE *fp,FILE *fptr_des )
{
    rewind(fp);

    char buffer[10];
    fread(buffer,10,1,fp);
    fwrite(buffer,10,1,fptr_des);

    return SUCCESS;
}


edittag checkit(char *ch)
{
    if(!strcmp(ch, "-t"))
	return t;
    else if(!strcmp(ch, "-a"))
	return a;
    else if(!strcmp(ch, "-A"))
	return A;
    else if(!strcmp(ch, "-y"))
	return y;
    else if(!strcmp(ch, "-m"))
	return m;
    else if(!strcmp(ch, "-c"))
	return c;
}

Status copytooriginal(FILE *fname,FILE *fptr_des)
{
    rewind(fname);
    rewind(fptr_des);

    char ch;

    while(fread(&ch,1,1,fptr_des)>0)
    {
	fwrite(&ch,1,1,fname);
    }

    fclose(fptr_des);
    remove("sample1.mp3");

    return SUCCESS;
}
