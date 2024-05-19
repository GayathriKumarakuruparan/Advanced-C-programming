#include<stdio.h>
#include<ctype.h>
#include"type.h"



int i=0;

char keys[32][10]={"auto","break","case","char","const","continue","default",
"do","double","else","enum","extern","float","for","goto",
"if","int","long","register","return","short","signed",
"sizeof","static","struct","switch","typedef","union",
"unsigned","void","volatile","while"};


Status readandvalidation(Code *code,char *arg)
{
    if(strcmp(strstr(arg,"."),".c")==0)
    {
	code->Filename=arg;
	return SUCCESS;
    }
    else
    { 
	printf("\n..................................\n\n");
        printf("ERROR: C File Type only\n");
        printf("\n..................................\n\n");
    }

}
Status open_file(Code *code)
{
    code->fp=fopen(code->Filename,"r");
    if (code->fp == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", code->Filename);
        return FAILURE;
    }
    return SUCCESS;
}

Status lexi_anal(Code *code,char *arg)
{
     char ch,str[25],seps[15]=" \t\n,;(){}[]#\"<>",oper[]="!%^&*-+=~|.<>/?";
     int j;

    while((ch=fgetc(code->fp))!=EOF)
    {
	for(j=0 ; j<14 ; j++)
	{
	    if(ch==oper[j])
	    {
		printf("Operator\t: %c\n",ch);
		str[i]='\0';
		findvar(str);
	    }
	}
	for(j=0 ; j<14 ; j++)
	{
	    if(i==-1)
		break;
	    if(ch==seps[j])
	    {
		if(ch=='#')
		{
		    printf("Header file\t: ");
		    while(ch!='>')
		    {
			printf("%c",ch);
			ch=fgetc(code->fp);
		    }
		    printf("%c",ch);
		    printf("\n");
		    i=-1;
		    break;
		}
		if(ch=='"')
		{
		    printf("Literal\t: ");
		    do{
			ch=fgetc(code->fp);
			printf("%c",ch);
		    }
		    while(ch!='"');
		    printf("\n");
		    i=-1;
		    break;
		}
		str[i]='\0';
		findvar(str);
	    }
	}
	if(i!=-1)
	{
	    str[i]=ch;
	    i++;
	}
	else
	{
	    i=0;
	}

    }
    printf("\nParsing\t: %s : Done\n\n",arg);
}

void findvar(char *s)
{
    int k,flag=0;
    for(k=0;k<31;k++)
    {
	if(strcmp(keys[k],s)==0)
	{
	    printf("Keyword\t: %s\n",s);
	    flag=1;
	    break;
	}

    }
    if(flag==0)
    {
	if(isdigit(s[0]))
	{
	    printf("Literal\t: %s\n",s);
	}
	else
	{
	    if(s[0]!='\0')
	    {
		printf("Identifer\t: %s\n",s);
	    }
	}		
    }
    i=-1;
}
