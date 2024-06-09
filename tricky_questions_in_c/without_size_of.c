/*
Name: Gayathri.k
Date:
Description:
Sample input:
Sample output:
*/
#include<stdio.h>
#define size_of(x) ((char*)(&x+1)-(char*)(&x))
int main()
{
    short int x;
    printf("the size of the variable x is :%d\n",size_of(x));

}

