/*
Name: Gayathri.k
Date: 19 May 2024
Description: lexical analyzer
*/
#include<stdio.h>
#include"type.h"
int main(int argc,char *argv[])
{
    Code code;
    char ch,str[25],seps[15]=" \t\n,;(){}[]#\"<>",oper[]="!%^&*-+=~|.<>/?";
    if(argc<=1)
    {
	printf("File name is not found!!!!!!!Please enter the file name\n");
    }
    else
    {
	if(readandvalidation(&code,argv[1])==SUCCESS)
	{
	    if(open_file(&code)==SUCCESS)
	    {
		printf("%s is opened successfully\n",argv[1]);

		printf("Parsing\t: %s :Started\n\n",argv[1]);

		lexi_anal(&code,argv[1]);

	    }
	}

    }
}

