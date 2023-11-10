/*
Name: Gayathri.k
Date: 10/11/23
Description: SWAP using macro in  pre-processing 
Sample Input: num1=20 num2=10
Sample Output: num1=10 num2=20
*/
#include<stdio.h>
#define SWAP(t,x,y)\
{  t temp = x ;  \
    x = y;       \
    y= temp ;     \
}                  
int main()
{
    int num1,num2,opt;
    char ch1,ch2;
    char str1[20],str2[20];
    float n1,n2;
    short s1,s2;
    char *ptr1,*ptr2;
    //menu to display
    printf("1.int\n2.char\n3.short\n4.float\n5.double\n6.string\n");
    printf("enter the option:");
    scanf("%d",&opt);
    //using switch case to choose from menu
    switch(opt){

        //if int
    case 1:
          printf("Enter the num1 and num2\n");
          scanf("%d %d",&num1,&num2);
          SWAP(int,num1,num2);
          printf("num1=%d\nnum2=%d",num1,num2);
          break;

          //if char
    case 2:
          printf("Enter the ch1 and ch2\n");
          scanf(" %c %c",&ch1,&ch2);
          SWAP(char,ch1,ch2);
          printf("ch1=%c\nch2=%c",ch1,ch2);
          break;

          //if short
    case 3:
          printf("Enter the s1 and s2\n");
          scanf("%d %d",&s1,&s2);
          SWAP(short,s1,s2);
          printf("s1=%d\ns2=%d",s1,s2);
          break;
         //if float
    case 4:
         printf("Enter the n1 and n2\n");
         scanf("%f %f",&n1,&n2);
         SWAP(float,n1,n2);
         printf("n1=%f\nn2=%f",n1,n2);
         break;

           //if double
    case 5:
         printf("Enter the n1 and n2\n");
         scanf("%g %g",&n1,&n2);
         SWAP(double,n1,n2);
         printf("n1=%g\nn2=%g",n1,n2);
         break;

          //if string
    case 6:
          printf("Enter the str1 and str2\n");
          scanf("%s %s",&str1,&str2);
          ptr1=str1;
          ptr2=str2;
          //using pointer to store the address of string to swapping.
          SWAP(char *,ptr1,ptr2);
          printf("str1=%s\nstr2=%s",ptr1,ptr2);
          break;
    }

}

