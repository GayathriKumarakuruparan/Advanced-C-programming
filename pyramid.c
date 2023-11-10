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
    int row,col,num;
    printf("Enter the number: ");
    scanf("%d",&num);//read the number from the user
    for(row=num;row>0;row--) //for the first half row of the pyramid
    {
        for(col=row;col<=num;col++)//for the first half col of the pyramid
        {
            printf("%d",col);//to print first half of pyramid
        }
        printf("\n");
    }
    for(row=1;row<=num;row++)//for the second half of row of the pyramid
    {
        for(col=row+1;col<=num;col++)//for the second half of col of the pyramid
        {
            printf("%d",col);//to print second half of pyramid
        }
        printf("\n");
    }
}











