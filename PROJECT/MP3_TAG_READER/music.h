#include<stdio.h>
#include"type.h"

#define POS_SIZE 6
typedef struct music
{
    char *Filename;
    FILE *fp;

    char *Title;
    int Title_size;

    char *Album;
    int Album_size;

    char *Artist;
    int Artist_size;

    char *Year;
    int Year_size;

    char *Genre;
    int Genre_size;

    char *Comment;
    int Com_size;
    int pos[POS_SIZE];
}Music;


//check operation
Operation checkOperation(char **argv);

//to validate the file mp3 or not
Status readandvalidation(Music *music,char *arg);

//to view the information
Status viewInfo(Music *music);

//to open the file
Status openfile(Music *music);

//to check headers and version
Status checkheaderandversion(FILE *fname);

//to read the info
Status readInfo(Music *music);

tag tagreader(FILE *fname);

//to get the size of info
Status tagsizereader(FILE *fname,int *size);


//to read the info
Status readtaginfo(FILE *fname,char **name, int size);

//to print the info
Status printInfo(Music *music);

//to print info for help
void printHelp();

