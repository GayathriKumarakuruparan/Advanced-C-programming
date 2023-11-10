/*
Name: Gayathri.k
Date: 23/09/2023
Description: WAP to find negative fibonacci series
Sample Input: Enter the number: -3
Sample Output:0 1 -1 2 -3
*/
#include<stdio.h>
int main()
{

    int num, first = 0, second = 1;
    printf("Enter the number:");
    scanf("%d",&num);//to get output from the user
    int third_num = first - second;//to get third number in series eg:(0-1)=-1
 if(num<=0)//check iif the number is negative
 {
    printf("the fibonacci series is %d %d ",first,second);//to print the first ans second number constantly eg:0 1
    while(third_num >= num && third_num <= -num)//check whether it is greater and limited with the given number
    {
        printf("%d ",third_num);//to first print the 1st three numbers eg:0 1 -1
        first = second;//swaping to get next numbers eg:0=1, 1=-1, -1=1-(-1)=2
        second = third_num;//1=-1
        third_num = first - second;//-1=1-(-1), 2
    }
 }
 else//if it is positive
 {
     printf("error");
 }

}

