/*
Name: Gayathri.k
Date: 24/09/2023
Description: pattern of X form
Sample Input: enter the number:3
Sample Output:1 1
               2
              3 3
*/ 
#include<stdio.h>
int main()
{
    int num,row,column,sum,count;
    printf("Enter the number: "); 
    scanf("%d",&num); //read the number from the user
    for(row=1;row<=num;row++) // to get the row range
    {
        for(column=1;column<=num;column++) //to get the column range
        {
            sum = row+column; //sum of row and coloumn to get x form
            count = num + 1;//for check the whether the count and sum is equal
            if((row==column) || (sum==count)) //check condition to get correct col and row
            {
                printf("%d",row); //to print output
            }
            else
            {
                printf(" "); //to print blank space
            }
        }
        printf("\n"); //to print in next line
    }
}

