/*
Name: Gayathri.k
Date:
Description:
Sample input:
Sample output:
*/
#include<stdio.h>
int main()
{
    unsigned int i=0xf4123460;
    
    unsigned int mask=i&0xC0000000;
    i=i^mask;
    mask=mask>>30;
    i=i^mask;
    printf("%x\n",i);

}

