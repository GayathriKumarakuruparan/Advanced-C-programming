/*
Name: Gayathri.k
Date:
Description:
Sample Input:
Sample Output:
*/
#include<stdio.h>
#include<stdlib.h>
void magic(int **p,int n){
    int row,col,res=1,i,j;
    for(row=0,col=n/2;row,col<=(n*n);row--,col++){
        if(row<0)
            row=n;
        if(col==n)
            col=0;
        if(p[row][col]!=0)
            row--;
        p[row][col]=res++;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d",p[i][j]);
        }
    }
}
int main()
{
    int n,i;
    printf("enter the number:");
    scanf("%d",&n);
    int row,col=n;
    int **p;
    p=calloc(row,sizeof(int*));
    for(i=0;i<row;i++)
        p[i]=calloc(row,sizeof(int));
    magic(p,n);
}

