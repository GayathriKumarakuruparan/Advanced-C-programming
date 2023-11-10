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
    int i,j,k,l,len,len2,sum1,add,add2,sum2,arr[100],arr2[100],temp;//variables 
    double flag1=0,flag2=0,flag3=0,flag4=0;//additional varialbes to add the result of the program
    printf("array 1': ");
    scanf("%d",&len);//to read the amount of array1
    printf("array 2: ");
    scanf("%d",&len2);//to read the amount of array2
    //printf("Enter the N: ");
    sum1=len/2;//to get the median of odd no of array1
    add=len2/2;//to get the median of odd no of array2
    sum2=sum1-1;//to get the median of even no of array1
    add2=add-1;//to get the median of even no of array2
    printf("the array 1 is:");
    for (i=0;i<len;i++){//to store the array1 in i
        scanf("%d",&arr[i]);
    }
    printf("\n");
    printf("the array 2 is");
    for (k=0;k<len2;k++){//to store the array2 in k
        scanf("%d",&arr2[k]);
    }
    printf("\n");
    //BUBBLE SORTING METHOD-1(for array 1)
        for (i=0;i<=len-2;i++)
        {
            for(j=0;j<len-i-1;j++)
            {
                   if(arr[j]>arr[j+1]) 
                   {
                           temp=arr[j];//swapping to arrang the num in order
                           arr[j]=arr[j+1];
                           arr[j+1]=temp;
                   }
            }
        }
        //BUBBLE SORTING METHOD-2(for array2)
        for (k=0;k<=len2-2;k++)
        {
            for(l=0;l<len2-k-1;l++)
            {
                   if(arr2[l]>arr2[l+1])
                   {
                           temp=arr2[l];//swapping yo arrange the num in order
                           arr2[l]=arr2[l+1];
                           arr2[l+1]=temp;
                   }
             }      
        }   
/*for(i=0;i<len;i++){
printf("%d ",arr[i]);
}
printf("\n");
for (k=0;k<len2;k++)
{
    printf("%d ",arr2[k]);
}*/
    if(len%2!=0)//if the array1 amount of number is odd/not even
    {
        printf("median is %d\n",arr[sum1]);
        flag1=arr[sum1];

       // printf("median is %d",arr[Sum1]);
    }
    else//if even
    {
        double res=(double)(arr[sum1]+arr[sum2])/2;//using double to get accurate result
        //double res2=(double)(arr[Sum1]+arr[Sum2])/2;
        printf("The median is%g\n",res);
        flag2=res;
        //printf("%g",res2);
    }
       if(len2%2!=0)
      {
          //printf("median is %d",arr[sum1]);
          printf("median is %d\n",arr2[add]);
          flag3=arr2[add];
      }
      else
      {
          //double res=(double)(arr[sum1]+arr[sum2])/2;
          double res2=(double)(arr2[add]+arr2[add2])/2;
          //printf("%g",res);
          printf("the meadian is %g\n",res2);
          flag4=res2;
     }
double result=(flag1+flag2+flag3+flag4)/2;//this result is to get the median of two array
printf("the result is %g",result);
}


