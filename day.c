/*
Name: Gayathri.k
Date: 26/09/2023
Description:
Sample Input:
Sample Output:
*/
#include<stdio.h>
int main()
{
    int  total,num,start_day,cond;
    printf("enter the n number: ");
    scanf("%d",&num); //get the no of days to cal from the user
    total = num + start_day;//to count the total days
    cond=((total-1)%7);//condition to print switch case
    if((num>0) && (num<=356))//the no of nth days should be in 0-365
    {
        printf("choose the day:\n1.sunday\n2.monday\n3.tuesday\n4.wednesday\n5.thursday\n6.friday\n7.saturday\n");//for menu purpose
        printf("enter the start day: ");
        scanf("%d",&start_day);//to get the starting day from the user
        if((start_day>0) && (start_day<=7))//the starting day should be in 0-7
        {
            switch(cond)//implement the condition in switch case
            {
                case 1:printf("sunday\n");//if 1 means sunday
                       break;
                case 2:printf("monday\n");//similar to previous statement
                       break;
                case 3:printf("tuesday\n");
                       break;
                case 4:printf("wednesday\n");
                       break;
                case 5:printf("thursday\n");
                       break;
                case 6:printf("friday\n");
                       break;
                case 0:printf("saturday\n");
                       break;
            }
        }
        else{//if not(0-7)
            printf("error!");
        }
    }
    else //if not(0-365)
    {
    printf("error");
    }    
}

