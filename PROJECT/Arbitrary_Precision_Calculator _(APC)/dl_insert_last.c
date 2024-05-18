#include"apc.h"
int dl_insert_last(Dlist **head,Dlist **tail,data_t data)
{
    Dlist *new=(Dlist *)malloc(sizeof(Dlist));

    if(new==NULL)
    {
	return FAILURE;
    }
    new->data=data;
    new->prev=NULL;
    new->next=NULL;

    //if list is empty
    if(*tail==NULL)
    {
	*head=*tail=new;
	return SUCCESS;
    }

    //if not
    new->prev=*tail;
    (*tail)->next=new;
    *tail=new;
    return SUCCESS;

}

