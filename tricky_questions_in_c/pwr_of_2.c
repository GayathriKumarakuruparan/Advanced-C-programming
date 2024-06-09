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
    unsigned int x;
    int i=0;
    printf("Enter the number : \n");
    scanf("%d",&x);
    unsigned int temp=(x&(x-1));
    unsigned int temp1=temp;
    while(temp1!=0)
    {
	temp1=temp1>>1;
	i++;
    }
    //printf("%d\n",i);
    unsigned int mask=1<<(i-1);
    unsigned int result=((temp&mask)<<1);
    printf("the next power of 2 is %d\n",result);
}

