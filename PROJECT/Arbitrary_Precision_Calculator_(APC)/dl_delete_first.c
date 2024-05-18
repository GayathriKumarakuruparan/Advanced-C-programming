/*
Name: Gayathri.k
Date:
Description:
Sample input:
Sample output:
*/
#include"apc.h"
int dl_delete_list(Dlist **head,Dlist **tail)	
{
    if(*head==NULL || *tail==NULL)
    {
	return FAILURE;
    }
    while((*head))
    {
	*head=(*head)->next;
	free(*head);
    }
    *head=NULL;
    *tail=NULL;
    return SUCCESS;
}

