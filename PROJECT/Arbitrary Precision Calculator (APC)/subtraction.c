/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR,int *key)
{
	/* Definition goes here */
    int status, borrow=0, diff=0;
    Dlist *temp1,*temp2;
    temp1=*head1;
    temp2=*head2;

    if((status=checksmall(*head1,*head2,*tail1,*tail2))==LARGE)
    {
	temp1=*head1;
	temp2=*head2;
    }
    else if(status == SMALL)
    {
	temp1=*head2;
	temp2=*head1;
	*key=1;
	putchar('-');
    }
    else
    {
	dl_insert_first(headR,tailR,diff);
	return SUCCESS;
    }
    while(temp1 || temp2)
    {
	diff=(temp1 ? temp1->data :  0 ) - (temp2 ? temp2->data : 0 ) - borrow;
	if(diff<0)
	{
	    dl_insert_first(headR,tailR,diff+10000);
	} 	
	else if(diff>0)
	{
	    dl_insert_first(headR,tailR,diff);
	}
	else
	{
	    dl_insert_first(headR,tailR,diff);
	}
	
	if(diff>0)
	    diff=((-diff)+10000);
	borrow=diff/10000;
	if(temp1)
	    temp1=temp1->next;
	if(temp2)
	    temp2=temp2->next;

    }
    return SUCCESS;
}

int checksmall(Dlist *l1,Dlist *l2,Dlist *tail1,Dlist *tail2)
{
    int i,j;
    i=j=0;
    while(l1)
    {
	++i;
	l1=l1->next;
    }
    while(l2)
    {
	++j;
	l2=l2->next;
    }
    if(i<j)
	return SMALL;
    else if(i>j)
	return LARGE;
    else
    {
	Dlist *temp1, *temp2;
	temp1=tail1;
	temp2=tail2;
	while(temp1 && temp2)
	{
	    if((temp1)->data > (temp2)->data)
	    {
		return LARGE;
	    }
	    else if((temp1)->data < (temp2)->data)
	    {
		return SMALL;
	    }
	    else if(temp1->data == temp2->data)
	    {
		temp1=temp1->prev;
		temp2=temp2->prev;
	    }

	}
	return EQUAL;
    }
}
