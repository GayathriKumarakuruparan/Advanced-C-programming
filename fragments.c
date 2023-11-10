/*
Name: Gayathri.k
Date:
Description:
Sample Input:
Sample Output:
*/
#include<stdio.h>
#include<stdlib.h>
void frag(float **p,int row,int *col){
    int i,j;
    float avg=0;
    float arr[row];
    for(i=0;i<row;i++){
        float sum=0;
        for(j=0;j<col[i];j++){
            sum+=p[i][j];
        }
        avg=sum/j;
        p[i][j]=avg;
    }

    //print the output before sorting
    printf("Before sorting:\n");
    for(i=0;i<row;i++){
        for(j=0;j<=col[i];j++){
            printf("%f\t",p[i][j]);
        }
        printf("\n");
    }

    //sorting...
    for(i=0;i<row-1;i++)
    {
        for(j=0;j<(row-i-1);j++)
        {
            if((p[i][col[i]])<(p[j][col[j]]))
            {
                float *temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                int temp2=col[j];
                col[j]=col[j+1];
                col[j+1]=temp2;
            }
        }
    }

    //after swapping
    printf("after swapping\n");
    for(i=0;i<row;i++){
        for(j=0;j<=col[i];j++){
            printf("%f\t",p[i][j]);
        }
        printf("\n");
    }


}



int main()
{
    int row,i,j,k,l;
    printf("enter the row:");
    scanf("%d",&row);
    float *ptr[row];
    int col[row];

    //read the col
    printf("enter the col array:");
    for(i=0;i<row;i++)
    {
        scanf("%d",&col[i]);
    }

    //memory allocation
    for(j=0;j<row;j++)
    {
        ptr[j]=malloc((col[j]+1)*sizeof(float));
    }

    //read the array element
    printf("enter the arrays:");
    for(k=0;k<row;k++)
    {
        for(l=0;l<col[k];l++)
        {
            scanf("%f",&ptr[k][l]);
        }
        printf("\n");
    }
    frag(ptr,row,col);
}


