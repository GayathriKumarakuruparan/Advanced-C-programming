/*
Name: Gayathri.k
Date: 23/09/2023
Description: WAP for fibonoacci series
Sample Input:Enter the number:3
Sample Output:0 1 1 2 3
*/
#include<stdio.h>
int main()
{
    int num,first = 0,second = 1; //for the first and second number for fibonacci series 0 1
    printf("Enter the number: ");
    scanf("%d",&num); // to read the number from the useri
    int third_num = first + second; //to get the output for third number
    if(num>0) //to check whether the fiven number is +ve or -ve
    {
        printf("the fibonoci series is %d %d ",first,second); //to print the first two numbers in output
        while(third_num<=num) //loop to add the numbers until th econd is false
        {
            printf("%d ",third_num); //print the third output first for print 0 1 1
            first = second; //swapping to get next number eg:0=1 1=1(0+1)
            second = third_num;//1=(0+1)1
            third_num = first + second;//1=(1+1)2
        }
    }
    else//if negative
    {
        printf("error");
    }

}

