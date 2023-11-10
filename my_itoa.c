/*
Name: Gayathri.k
Date:
Description:
Sample Input:
Sample Output:
*/
#include<stdio.h>
void my_itoa(int num,char *str)
{
    int i=0,j=0,k,flag=0,rem,count=0;
    char temp;
    //check if the num is positive or not
    if(num<0)
    {
    num=(-1)*num;
    count=1;
    while(num!=0)
    {
        rem=num%10;
        str[i++]=rem+48;
        num=num/10;
    }
    }
    //if the num is negative
    else
    {
    num=num;
    //loop to get the num in string as reverse
    while(num!=0)
    {
        //reversing the num and store it in string
        rem = num % 10;
        str[i++]=rem+48;//to convert int to string
        num = num/10;
    }
    }
    //loop for get th length of string
    while(str[j]!='\0')
    {
        flag++;//to get length
        j++;
    }
    //loop for swaping the string to reverse
    for(k=0;k<=(flag-1)/2;k++)
    {
        //swapping to get the orginal order in string
        temp=str[k];
        str[k]=str[flag-1-k];
        str[flag-1-k]=temp;
    }
    //if it is negative
    if(count==1){
    printf("the output is -%s\n",str);
    }
    //if it is positive
    else{
    printf("the output is %s\n",str);
    }
}
int main()
{
    int num=0;
    char str[100];
    printf("enter the number : ");
    scanf("%d",&num);
    //to check whether the entered input is interger or not
    if(num==0){
        printf("the output is %d\n",num);
    }
    else{
        my_itoa(num,str);
    }
}

