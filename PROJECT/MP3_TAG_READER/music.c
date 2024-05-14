#include<stdio.h>
#include"music.h"
//#include"type.h"
#include<string.h>
#include<stdlib.h>
Operation checkOperation(char **argv)
{
    if(strcmp(argv[1],"-e")==0)
	return Edit;
    else if(strcmp(argv[1],"-v")==0)
	return View;
    else
	return Help;
}


//to validation
Status readandvalidation(Music *music,char *arg)
{
    if(strcmp(strstr(arg,"."),".mp3")==0)
    {
	music->Filename=arg;
	return SUCCESS;
    }
    else
    {
	printf("\n---------------------------------------------\n\n");
	printf("ERROR: Mp3 file Type only\n");
	printf("\n---------------------------------------------\n");
    }
}


//print the help menu
void printHelp()
{
    printf("\n.............Help Menu.....................\n\n");
    printf("1. -v -> to view mp3 file contents\n");
    printf("2. -e -> to edit mp3 file contents\n");
    printf("	2.1. -t -> to edit song title\n");
    printf("	2.2. -a -> to edit artist name\n");
    printf("	2.3. -A -> to edit album name\n");
    printf("	2.4. -y -> to edit song year\n");
    printf("	2.5. -m -> to edit song content\n");
    printf("	2.6. -c -> to edit song comment\n");
    printf("\n............................................\n\n");
}




//to open a file
Status openfile(Music *music)
{
    music->fp=fopen(music->Filename,"rb+");
    if(music->fp == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n",music->Filename);
	return FAILURE;
    }
    return SUCCESS;
}



//to check header and version of file
Status checkheaderandversion(FILE *fname)
{
    char head[4];
    char ver[2];
    fread(head,3,1,fname);
    head[3]='\0';
    fread(ver,2,1,fname);
    if(strcmp(head,"ID3")==0 && ver[0]==0x03 && ver[1]==0x00)
    {
	return SUCCESS;
    }
    else
    {
	return FAILURE;
    }

}


//to read the file info
Status readInfo(Music *music)
{
    rewind(music->fp);
    fseek(music->fp,10,SEEK_CUR);
    for(int i=0;i<6;i++)
    {
	tag t=tagreader(music->fp);
	switch(t)
	{
	    case m_title:/*to read the title*/

		music->pos[m_title]=ftell(music->fp);
		tagsizereader(music->fp,&music->Title_size);
		fseek(music->fp,3,SEEK_CUR);
		readtaginfo(music->fp,&music->Title,music->Title_size);
		break;

	    case m_album:/*to read the album_name*/

		music->pos[m_album]=ftell(music->fp);
                tagsizereader(music->fp,&music->Album_size);
                fseek(music->fp,3,SEEK_CUR);
                readtaginfo(music->fp,&music->Album,music->Album_size);

		break;
	    case m_artist:/*to read the artist name*/

		music->pos[m_artist]=ftell(music->fp);
		tagsizereader(music->fp,&music->Artist_size);
		fseek(music->fp,3,SEEK_CUR);
		readtaginfo(music->fp,&music->Artist,music->Artist_size);
		break;

	    case m_year:/*to read the year*/

	      	music->pos[m_year]=ftell(music->fp);
		tagsizereader(music->fp,&music->Year_size);
		fseek(music->fp,3,SEEK_CUR);
		readtaginfo(music->fp,&music->Year,music->Year_size);
		break;

	    case m_genre:/*to read the genre*/

		music->pos[m_genre]=ftell(music->fp);
		tagsizereader(music->fp,&music->Genre_size);
		fseek(music->fp,3,SEEK_CUR);
		readtaginfo(music->fp,&music->Genre,music->Genre_size);
		break;

	    case m_comment:/*to read the comment*/

		music->pos[m_comment]=ftell(music->fp);
		tagsizereader(music->fp,&music->Com_size);
		fseek(music->fp,3,SEEK_CUR);
		readtaginfo(music->fp,&music->Comment,music->Com_size);
		break;
	    default:
		break;
	}
    }
    return SUCCESS;
}



Status tagsizereader(FILE *fname,int *size)
{
    char ch;
    *size=0;

    for(int i=0;i<4;i++)
    {
	fread(&ch,1,1,fname);
	*size = *size << i*8 | ch;
    }

    *size=*size-1;
}



tag tagreader(FILE *fname)
{
    char tag[4+1];

    fread(tag,4,1,fname);
    tag[4]='\0';


    if(strcmp(tag,"TIT2")==0)
	return m_title;
    else if(strcmp(tag,"TALB")==0)
	return m_album;
    else if(strcmp(tag,"TPE1")==0)
	return m_artist;
    else if(strcmp(tag,"TYER")==0)
	return m_year;
    else if(strcmp(tag,"TCON")==0)
	return m_genre;
    else if(strcmp(tag,"COMM")==0)
	return m_comment;
 }



Status readtaginfo(FILE *fname,char **name,int size)
{
    char *buffer=malloc(size +1);

    fread(buffer,size,1,fname);

    buffer[size]='\0';

    *name=malloc(size+1);
    strcpy(*name,buffer);

    free(buffer);
}


//to print view menu
Status printInfo(Music *music)
{
    printf("\n------------------------------Selected View Details----------------------------------\n");
    printf("\n-------------------------------------------------------------------------------------\n");
    printf("\n                         MP3 TAG READER AND EDITOR FOR ID3v2                         \n");
    printf("\n-------------------------------------------------------------------------------------\n");
    printf("TITLE          : %s \n", music->Title);
    printf("ARTIST         : %s \n", music->Artist);
    printf("ALBUM          : %s \n", music->Album);
    printf("YEAR           : %s \n", music->Year);
    printf("MUSIC          : %s \n", music->Genre);
    printf("COMMENT        : %s \n", music->Comment);
    printf("\n-------------------------------------------------------------------------------------\n\n");
    return SUCCESS;


}




Status viewInfo(Music *music)
{
    //OPEN THE FILE
    if(openfile(music)==SUCCESS)
    {

	//Check the header and version of file
	if(checkheaderandversion(music->fp)==SUCCESS)
	{

	    //read the info
	    if(readInfo(music)==SUCCESS)
	    {
		//print the info
		printInfo(music);
	    }
	}
    }
}
