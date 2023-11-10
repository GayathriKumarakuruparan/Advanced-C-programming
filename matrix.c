/*
Name: Gayathri.k
Date:
Description:
Sample Input:
Sample Output:
*/
#include<stdio.h>
#include<stdlib.h>
void matrix_mult(int **mat_a,int **mat_b,int r1,int r2,int c1,int c2,int row,int col,int **result){
    int i,j,k,sum=0;

    //product of matrix
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            for(k=0;k<c1;k++)
            {
                sum+=(mat_a[i][k]*mat_b[k][j]);
            }
            result[i][j]=sum;
            sum=0;
        }
    }
    //print the result of matrix
    printf("result:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        printf("%d ",result[i][j]);

        printf("\n");
    }
}
int main()
{   //normal declaration of two rows and two col for prod of matrix 
    int r1,r2,c1,c2,i,j,k,l;
    printf("enter the rows and col:");
    scanf("%d",&r1);
    scanf("%d",&c1);
    printf("enter the rows and col:");
    scanf("%d",&r2);
    scanf("%d",&c2);

    //multi pointers for memory allocation of both dynamic
    int **mat_a,**mat_b;

    //to check the col1 and row2 are same or not
    if(c1!=r2)
        //if not
        printf("error");

    //if same
    else
    {
    //creating the mem alocation for 1st matrix(row1,col1)
    mat_a = malloc(r1*sizeof(int *));
    
    for(i=0;i<r1;i++)
       mat_a[i] = malloc(c1*sizeof(int));

    //loop for read the 1st matrix
    for(j=0;j<r1;j++)
    {
        for(k=0;k<c2;k++)
        {
            scanf("%d",&mat_a[j][k]);
        }
        printf("\n");
    }

    //mem allocation for 2nd matrix(row2,col2)
    mat_b=malloc(r2*sizeof(int *));

    for(i=0;i<r2;i++)
        mat_b[i]=malloc(c2*sizeof(int));

    //loop for read the 2nd matrix
    for(int l=0;l<r2;l++)
    {
        for(int m=0;m<c2;m++)
        {
            scanf("%d",&mat_b[l][m]);
        }
    }

    //row and col for the product of matrix
    int row_res=r1;
    int col_res=c2;
    //allocatinf mem for the result
    int **result;

    result=malloc(row_res*sizeof(int *));

    for(i=0;i<row_res;i++)
    {
        result[i]=malloc(col_res*sizeof(int));
    }
    //call the function
    matrix_mult(mat_a,mat_b,r1,r2,c1,c2,row_res,col_res,result);
}          
}



