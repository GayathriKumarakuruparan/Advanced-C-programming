/*
Name: Gayathri.k
Date: 24/09/2023
Description:
Sample Input:
Sample Output:
*/
#include<stdio.h>
int main()
{
    int i,A,R,N,AP,GP;
    printf("enter the A: ");
    scanf("%d",&A);
    printf("enter the R: ");
    scanf("%d",&R);
    printf("enter the N: ");
    scanf("%d",&N);
  if(N>0)
  {
    AP=A;
    printf("AP = ");
    for(i=1;i<=N;i++)
    {
        printf("%d ",AP);
        //sum+=R;
        AP=AP+R;
    }
    GP=A;
    printf("\nGP is: ");
    for(i=1;i<=N;i++)
    {
          printf("%d ",GP);
         // sum+=R;
          GP=GP*R;
    }
    int HP=A;
    float sum,s=1/(float)A;
      printf("\nHP is: ");
      printf("%f ",s);
      for(i=2;i<=N;i++)
      {
            HP=(HP+R);
            sum=1/(float)HP;
            printf("%f ",sum);
      }

  }
  else
  {
     printf("error");
  } 
}

