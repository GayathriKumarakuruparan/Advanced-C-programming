/*
Name: Gayathri.k
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

