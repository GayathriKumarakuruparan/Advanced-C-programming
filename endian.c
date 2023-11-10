/*
Name: Gayathri.k
Date:
Description:
Sample Input:
Sample Output:
*/
#include<stdio.h>
int main()
{
    int size;
    short int num;
    char temp;
    printf("enter the size:");
    scanf("%d",&size);
    printf("enter the number");
    scanf("%hx",&num);
    char *ptr=&num;
    for(int i=0;i<(size/2);i++){
    temp=ptr[i];
    ptr[i]=ptr[size-i-1];
    ptr[size-i-1]=temp;

    }
    printf("%hX",num);

}

