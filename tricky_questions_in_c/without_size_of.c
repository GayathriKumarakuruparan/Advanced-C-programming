/*
Name: Gayathri.k
Date: july 9 2024
Description: wap to find the size of variable withour using sizeof

*/
#include<stdio.h>
#define size_of(x) ((char*)(&x+1)-(char*)(&x))
int main()
{
    short int x;
    printf("the size of the variable x is :%d\n",size_of(x));

}

