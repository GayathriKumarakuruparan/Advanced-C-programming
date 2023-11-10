/*
Name: Gayathri.k
Date: 23/09/203
Description: find the number is perfect or not
Sample Input: enter the number: 6
Sample Output:6 is perfect number
*/
#include<stdio.h>
int main()
{
    int factor, num, sum = 0, i; 
    printf("enter the number: ");
    scanf("%d",&num); //to get the number from the user
    if(num>=0) //to check whether positive or not
    {
        for(i=1;i<num;i++) //looping for repeat
        {
            factor = num%i //to get the factor values
            if(factor==0) //if it rem is 0
            {
                sum = sum + i; //adding the numbers
            }
        }
        if(num==sum)//check if the given number and result of sum is equal
        {
            printf("%d is perfect number\n",num); //then it is perfect
        }
        else //if not equal 
        {
            printf("%d is not perfect number\n",num); //then it is not perfect
        }
    }
    else //if negative
    {
        printf("error");
    }
}

