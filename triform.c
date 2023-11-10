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
    int row,col,num,sum,count=1,total;
    printf("enter the number: ");
    scanf("%d",&num);
    for(row=1;row<=num;row++)
    {
        for(col=1;col<=num;col++)
        {
            sum = row  + col;
            total = num + 1;
            if((row==1) || (col==1) || (sum==total))
            {
                printf("%d",count);
                count++;
                //printf("%d ",count);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

}

