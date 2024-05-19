#include<stdio.h>
#include<string.h>
//#include"file.c"
typedef enum
{
    SUCCESS,
    FAILURE
}Status;

typedef struct code
{
    char *Filename;
    FILE *fp;
}Code;

Status readandvalidation(Code *code,char *arg);

Status open_file(Code *code);

Status lexi_anal(Code *code,char *arg);

void findvar(char *s);

