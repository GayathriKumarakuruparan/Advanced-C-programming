/*
Name: Gayathri.k
Date: 14/05/2024
Description: MP3 tag reader and editor for ID3v2
*/
#include<stdio.h>
//#include"music.h"
#include"edit.h"
int main(int argc,char *argv[])
{
    Music music;

    if(argc>1)
    {
	if(checkOperation(argv)==Edit)
	{
	    if(argc>4)
	    {
		if(readandvalidation(&music,argv[4])==SUCCESS)
		{
		    editInfo(&music,argv[2],argv[3]);
		}
	    }
	    else
	    {
		printf("\n--------------------------------------\n");
		printf("\n      Please enter correct argument  \n");
		printf("\n--------------------------------------\n");
	    }

	}

	else if(checkOperation(argv)==View)
	{

	    if(readandvalidation(&music,argv[2])==SUCCESS)
	    {
		
		viewInfo(&music);
	    }
	    
	}

	else
	{
	    printHelp();
	}
    }


    else
    {

	printf("-----------------------------------------------------------\n\n");
	printf("ERROR: ./a.out : Invalid Arguments\n");
	printf("USAGE :\n");
	printf("To view use : ./a.out -v <mp3filename>\n");
	printf("To edit use : ./a.out -e -t/-a/-A/-m/-y/-c <editorname> <mp3filename>\n");
	printf("To get help use : ./a.out --help\n");
	printf("\n-----------------------------------------------------------\n");

    }
}

