/*
Name: Gayathri.k
Date: 18/11/2023
Description: Provide a menu to manipulate or display the value of variable of type t
Sample Input/Output: Menu :
                    1. Add element
                    2. Remove element
                    3. Display element
                    4. Exit from the program
                    
                    Choice ---> 1
                    Enter the type you have to insert:
                    1. int
                    2. char
                    3. float
                    4. double
                    Choice ---> 2
                    Enter the char : k
                    1. Add element
                    2. Remove element
                    3. Display element
                    4. Exit from the program
                    Choice ---> 3
                    -------------------------
                    0 -> k
                    -------------------------
                    1. Add element
                    2. Remove element
                    3. Display element
                    4. Exit from the program
                    Choice ---> 1
                    Enter the type you have to insert:
                    1. int
                    2. char
                    3. float
                    4. double
                    Choice ---> 1
                    Enter the int : 10
                    1. Add element
                    2. Remove element
                    3. Display element
                    4. Exit from the program
                    Choice ---> 3
                    ------------------------
                    0 -> k (char)
                    1 -> 10 (int)
                    ------------------------
                    1. Add element
                    2. Remove element
                    3. Display element
                    4. Exit from the program
                    
                    Choice ---> 2
                    0 -> k
                    1 -> 10
                    Enter the index value to be deleted : 0
                    index 0 successfully deleted.
                    1. Add element
                    2. Remove element
                    3. Display element
                    4. Exit from the program
                    Choice ---> 4
                    

*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int ch1_flag=0, ch2_flag=0, int_flag=0, float_flag=0, double_flag=0, short_flag=0,opt1,index,opt2;
    int ON=1;
    
    //memory allocation
    void *ptr=malloc(8);
    
    //program started
    while( ON ==1 )                           //while condition to exit the program
    {
        
    //first menu display
    printf("DISPLAY THE MENU : \n1. Add element\n2. Remove element\n3. Display element\n4. Exit from the program\n");
    printf("Choice---> ");
    scanf("%d",&opt1);
    switch(opt1)
    {
        //to add element
        case 1:
            printf("\nEnter the type you have to insert:\n1. int\n2. char\n3. float\n4. double\n5. short\n");
            printf("Choice---> ");
            scanf("%d",&opt2);
            switch(opt2)
            {
                //to get elements according to user choice
                case 1:
                     if((int_flag == 0) && (float_flag == 0) && (double_flag == 0))
                     {
                         printf("\nEnter the int : ");
                         scanf("%d",(int *)ptr+1);
                         printf("\n");
                         int_flag=1;
                     }
                     else
                     {
                         printf("/*------SPACE IS NOT AVAILABLE-------*/\n");
                         printf("\n");
                     }
                     break;
                     
                case 2:
                     if((ch1_flag == 0) && (double_flag == 0))
                     {
                         printf("\nEnter the char : ");
                         scanf(" %c",(char *)ptr);
                         printf("\n");
                         ch1_flag=1;
                     }
                     else if((ch2_flag == 0) && (double_flag == 0))
                     {
                         printf("\nEnter the char : ");
                         scanf(" %c",(char *)ptr+1);
                         printf("\n");
                         ch2_flag=1;
                     }
                     else
                     {
                         printf("/*------SPACE IS NOT AVAILABLE-------*/\n");
                         printf("\n");
                     }
                     break;
                     
                case 3:
                     if((int_flag == 0) && (float_flag == 0) && (double_flag == 0))
                     {
                         printf("\nEnter the float : ");
                         scanf("%f",(float *)ptr+1);
                         printf("\n");
                         float_flag=1;
                     }
                     else
                     {
                         printf("/*------SPACE IS NOT AVAILABLE-------*/\n");
                         printf("\n");
                     }
                     break;
                     
                case 4:
                     if((int_flag == 0) && (float_flag == 0) && (short_flag == 0) && (ch1_flag == 0) && (ch2_flag == 0) && (double_flag == 0))
                     {
                         printf("\nEnter the double : ");
                         scanf("%lg",(double *)ptr);
                         printf("\n");
                         double_flag=1;
                     }
                     else
                     {
                         printf("/*------SPACE IS NOT AVAILABLE-------*/\n");
                         printf("\n");
                     }
                     break;
                     
                case 5:
                      if((short_flag == 0) && (double_flag == 0))
                     {
                         printf("\nEnter the short : ");
                         scanf("%hd",(short *)ptr+1);
                         printf("\n");
                         short_flag=1;
                     }
                     else
                     {
                         printf("/*------SPACE IS NOT AVAILABLE-------*/\n");
                         printf("\n");
                         
                     }
                     
                     break;
                     
            }
            break;
        
        //to remove element
        case 2:
            printf("Enter the index value to be deleted : ");
            scanf("%d",&index);
            if(index == 0)
            {
                if(ch1_flag == 1)
                {
                    ch1_flag = 0;
                    printf("index %d successfully deleted.\n",index);
                    printf("\n");
                }
                else
                {
                    double_flag = 0;
                    printf("index %d successfully deleted.\n",index);
                    printf("\n");
                }
            }
            if(index == 1)
            {
                if(ch2_flag ==1)
                {
                    ch2_flag = 0;
                    printf("index %d successfully deleted.\n",index);
                    printf("\n");
                }
                else
                {
                    double_flag = 0;
                    printf("index %d successfully deleted.\n",index);
                    printf("\n");
                }
            }
            if(index == 2)
            {
                if(short_flag == 1)
                {
                    short_flag = 0;
                    printf("index %d successfully deleted.",index);
                    printf("\n");
                }
                else
                {
                    double_flag = 0;
                    printf("index %d successfully deleted.\n",index);
                    printf("\n");
                }
            }
            if(index == 4)
            {
                if(int_flag==1)
                {
                    int_flag = 0;
                    printf("index %d successfully deleted.\n",index);
                    printf("\n");
                }
                else if(float_flag==1)
                {
                    float_flag = 0;
                    printf("index %d successfully deleted.\n",index);
                    printf("\n");
                }
                else
                {
                    double_flag = 0;
                    printf("index %d successfully deleted.\n",index);
                    printf("\n");
                }
            }
            break;
            
        //to display the entered elements
        case 3:
        printf("/*----------------------------------------------------------------*/\n");
            if(int_flag==1)
            {
                printf("0 -> %d (int)\n",*((int *)ptr+1));
            }
            if(ch1_flag==1)
            {
                printf("1 -> %c (char)\n",*((char *)ptr));
            }
            if(ch2_flag==1)
            {
                printf("2 -> %c (char)\n",*((char *)ptr+1));
            }
            if(float_flag==1)
            {
                printf("3 -> %f (float)\n",*((float *)ptr+1));
            }
            if(double_flag==1)
            {
                printf("4 -> %lg (double)\n",*((double *)ptr));
            }
            if(short_flag==1)
            {
                printf("5 -> %hd (short)\n",*((short *)ptr+1));
            }
            if((int_flag == 0) && (float_flag == 0) && (short_flag == 0) && (ch1_flag == 0) && (ch2_flag == 0) && (double_flag == 0))
            {
                printf("**--------PLEASE ENTER SOME ELEMENT---------**");
                printf("\n");
            }
            printf("/*----------------------------------------------------------------*/\n");
            printf("\n");
            break;
            
        //to exit the program
        case 4:
              ON=0;
              break;
              
            }
            
    }
}
