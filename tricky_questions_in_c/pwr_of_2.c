/*
Name: Gayathri.k
Date: july 9 2024
Description: wap to round the number to the next power of 2
Sample input: num =17
Sample output: the next power of 2 is 32
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

