/*
Name: Gayathri.k
Date: july 9 2024
Description: swap the 2 bit from msb and add it in lsb
Sample input:0xF1234560
Sample output:0X31234563
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

