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
    int num,N,M,mask1,mask2,result,clear;
    printf("enter the number: ");
    scanf("%d",&num);//to get the number from the user
    printf("Enter N = ");
    scanf("%d",&N);//to get the position of the num
    printf("Enter M = ");
    scanf("%d",&M);//to get the num to clear
    mask1=1<<N;//mask1 for getting the set number
    result=num&mask1;//for check whether the num is set or not
    if(result!=0)//if the result is greater than 0 or not equal to 0
    {
        mask2=~(1<<M);//make2 to get the clear number 
        clear=num&mask2; //to clear the number
        printf("value : %d\n",clear);//print the updated number
    }
    else
    {
        printf("%d\n",num);//if it is equal to 0 no need to update
    }
   
}

