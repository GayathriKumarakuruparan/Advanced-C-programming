/*
Name: Gayathri.k
Date: 22/09/2023
Description: wap to find the number is odd or even, and mention its sign
Sample Input: enter th enumber:-7
Sample Output: -7 is negative odd number
*/
#include<stdio.h>
int main() 
{
    int num;
    printf("enter the number:"); 
    scanf("%d",&num); //read the number from user
    if(num==0) //check the number is 0 or not
    {
        printf("neither odd nor even\n");
    }
    else //if not 0
    {
        if(num%2==0) //check whether the number is odd or even, if even
        {
            if(num>0) //to check whether the number is positive or negative
            {
                printf("%d is positive even number\n",num); //if positive
            }
            else //if negative
            {
                printf("%d is negative even number\n",num);
            }
        }
        else //if odd
        {
            if(num>0) // to check whether the number is positive or negative
            {
                printf("%d is positive odd number\n",num); //if positive
            }
            else //if negative
            {
                printf("%d is negative odd number\n",num); 
            }
        }
    }
}

