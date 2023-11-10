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
    int num,i,mask=1,shift,count=0,result;
    int module;
    printf("Enter the number : ");
    scanf("%d",&num);//to get the number from the user
    for(i=0;i<=31;i++)//range between 1 byte(0-31 bites)
    {
        shift=mask<<i;//to store the mask value
        result=num&shift;//to store the set value
        if(result!=0)//if the set value is 1 or more than 0
        {
            ++count;//count inc by 1
            module=count&1;//to check whether is odd or even using bitwise operator
        }
    }
        printf("Number of set bits = %d\n",count);//to print the set count
        if(module==0)//if the module 0 then it is even
           {
                printf("Bit parity is Even\n");
            }
            else//otherwise it is odd
            {
                printf("Bit parity is Odd\n");
            }
}

