/*
Name: Gayathri.k
Date: may 18 2024
*/
#include"apc.h"
void print_list(Dlist *head)
{
    if(head==NULL)
    {
	printf("!!!!!!!!LIST IS EMPTY!!!!!!!");
    }
    else
    {
	while(head)
	{
	if(head->data <10)
	    printf("000");
	else if(head->data > 9 && head->data <100)
	    printf("00");
	else if(head->data >99 && head->data < 1000)
	    printf("0");
	printf("%d",head->data);
	head=head->next;
	}
	//return SUCCESS;
	putchar('\n');
    }
}

