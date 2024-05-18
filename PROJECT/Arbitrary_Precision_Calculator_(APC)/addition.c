/*******************************************************************************************************************************************************************
*Name                   : GAYATHRI K
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */
    int sum,carry=0;
    Dlist *temp1=*head1;
    Dlist *temp2=*head2;

    while(temp1  || temp2 )
    {
	sum = carry + (temp1 ? temp1->data : 0) + (temp2 ? temp2->data : 0 ); 

	carry = sum / 10000;
	sum = sum % 10000;

	//printf("the carry is %d \nthe sum is %d\n",carry,sum);

	dl_insert_first(headR,tailR,sum);

	if(temp1)
	    temp1=temp1->next;
	if(temp2)
	    temp2=temp2->next;
    }
    return SUCCESS;
}
