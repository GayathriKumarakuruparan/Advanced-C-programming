/*
Name: Gayathri.k
Date: july 9 2024
Description: WAP to swap quardrant on array
Sample input: 1 2
              3 4
Sample output:4 3
              1 2
*/
#include<stdio.h>
#include<stdlib.h>
void print_arr(int ,int,int**);
void swap_(int **arr,int startx_X,int starty_X,int startx_Y,int starty_Y,int r,int c)
{
    int row=0,col=0;
    for(int i=startx_X;;i++)
    {
	col=0;
	for(int j=starty_X;;j++)
	{
	    int temp=arr[i][j];
	    arr[i][j]=arr[startx_Y+row][starty_Y+col];
	    arr[startx_Y+row][starty_Y+col]=temp;
	    col++;
	    if(col>=c/2)
		break;
	}
	row++;
	if(row>=r/2)
	    break;
    }

}

void quarter_array(int row,int col,int **arr,int x,int y)
{
    if(x==1 && y==2)
    {
	swap_(arr,0,0,0,col/2,row,col);
    }
    else if(x==1 && y==3)
    {
	swap_(arr,0,0,row/2,0,row,col);
    }
    else if(x==1 && y==4)
    {
	swap_(arr,0,0,row/2,col/2,row,col);
    }
    else if(x==2 && y==3)
    {
	swap_(arr,0,col/2,row/2,0,row,col);
    }
    else if(x==2 && y==4)
    {
	swap_(arr,0,col/2,row/2,col/2,row,col);
    }
    else if(x==3 && y==4)
    {
	swap_(arr,row/2,0,row/2,col/2,row,col);
    }
    //printf("after swap:\n");
    //print_arr(row,col,arr);
}


void print_arr(int row,int col,int **arr)
{
    int i,j;
    for(i=0;i<row;i++)
    {
	for(j=0;j<col;j++)
	{
	    printf("%d ",arr[i][j]);
	}
	printf("\n");
    }
}
int main()
{
    int row,col;
    printf("Enter the row:\n");
    scanf("%d",&row);
    printf("Enter the col:\n");
    scanf("%d",&col);
    int **arr=malloc(row*sizeof(int*));
    int i,j,x,y;
    for(i=0;i<row;i++)
    {
	arr[i]=malloc(col*sizeof(int));
    }
    printf("enter the elements:");
    for(int i=0;i<row;i++)
    {
	for(int j=0;j<col;j++)
	{
	    scanf("%d",&arr[i][j]);
	}
    }

    /*printf("enter the quarters you need to swap:\nx:");
    scanf("%d",&x);
    printf("\ny:");
    scanf("%d",&y);*/
    x=1;y=4;
    printf("before swap:\n");
    print_arr(row,col,arr);

    quarter_array(row,col,arr,x,y);
    x=2;y=3;
    quarter_array(row,col,arr,x,y);
    printf("After swap:\n");
    print_arr(row,col,arr);

}

