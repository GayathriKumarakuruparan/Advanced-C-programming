/*
Name: Gayathri.k
Date: july 9 2024
Description: fastest way to swap

*/
#include<stdio.h>
int main()
{
    int a=10;
    int b=20;
    a^=b^=a^=b;
    printf("a: %d\nb:%d\n",a,b);

}

