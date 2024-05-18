/*
Name: Gayathri K
*/
#include"apc.h"
int dl_insert_first(Dlist **head,Dlist **tail,data_t data)
{
    Dlist *new=(Dlist *)malloc(sizeof(Dlist));

    if(new==NULL)
    {
	return FAILURE;
    }
    new->data=data;
    new->prev=NULL;
    new->next=NULL;
    if((*head)==NULL)
    {
	*head=*tail=new;
	return SUCCESS;
    }
    new->next=*head;
    (*head)->prev-new;
    *head=new;
    
    return SUCCESS;


}

int sl_insert_first(Dlist **head, data_t data)
{
    Dlist *new=(Dlist *)malloc(sizeof(Dlist));
    if(new==NULL)
	return FAILURE;
    new->data=data;
    new->next=NULL;
    if(*head ==NULL)
    {
	*head=new;
	return SUCCESS;
    }
    new->next=(*head);
    *head = new;
    return SUCCESS;
}
