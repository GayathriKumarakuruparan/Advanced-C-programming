/*
Name: Gayathri.k
Date: 12/11/23
Description: Read n & n person names of maxlen 20. Sort and print the names
Sample Input:Enter the size: 5
                Enter the 5 names of length max 20 characters in each
                [0] -> Delhi
                [1] -> Agra
                [2] -> Kolkata
                [3] -> Bengaluru
                [4] -> Chennai


Sample Output: The sorted names are:
                Agra
                Bengaluru
                Chennai
                Delhi
                Kolkata
*/
#include<stdio.h>
#include<stdlib.h>
void name(char(*)[20],int);
int my_strcmp(char *,char *,int);
int my_strcpy(char *,char *ptr);
int main()
{
    int i,row;
    char (*ptr)[20];
   // printf("enter the n value:");
    scanf("%d",&row);
    
    //allocation of memory
    ptr=malloc(row*sizeof(char[20]));
    name(ptr,row);

}
//own string compareing function
int my_strcmp(char *string1,char *string2,int row){
    int i=0,j=0,temp;
   for(i=0; string1[i]!='\0'; i++){

        {
        
        if((string1[i] == string2[i]))
        {
            
        temp = 1;
        
        }
        else if((string1[i] < string2[i]))
        {
            temp=1;
            break;
        }
        else
        {
            
        temp = 0;
        break;
        
        }
        }
   }
        
        if(temp == 1)
        return 0;
        else
        return 1;
   
}

//own string copying function
int my_strcpy(char *temp,char *ptr){
    int i=0;
    while((ptr[i])!='\0'){
        temp[i]=ptr[i];
        i++;
    }
    temp[i]='\0';
    
}
    

void name(char (*ptr)[20],int row){
    int i,j,res;
    char temp[20];
    //read the name
    
    for(i=0;i<row;i++){
    scanf("%s",ptr[i]);
    }
    
    //sorting.....
   for(i=0;i<row-1;i++){
       for(j=i+1;j<row;j++){
           
           res=(my_strcmp(ptr[i],ptr[j],row));
          if(res>0){
             
              my_strcpy(temp,ptr[i]);
              my_strcpy(ptr[i],ptr[j]);
              my_strcpy(ptr[j],temp);
              
          }
          
       }
   }
  
  //output printing loop
   printf("The sorted names are:\n");
   for(j=0;j<row;j++){
       printf("%s\n",ptr[j]);
       continue;
   }
}
