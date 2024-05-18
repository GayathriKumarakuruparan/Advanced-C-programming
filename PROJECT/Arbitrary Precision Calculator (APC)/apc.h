#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1

#define SMALL 0
#define LARGE 1
#define EQUAL -1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "colors.h"
typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */

//void print_list(Dlist *head);
int feed_number(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2); 

int parse(char *ch, int len, Dlist **head,Dlist **tail);

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR,int *key);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
Dlist *division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);


void print_list(Dlist *head);

int checksmall(Dlist *l1,Dlist *l2, Dlist *tail1, Dlist *tail2);


int find_length(Dlist **head);
void To_headR(Dlist **headR, Dlist **tailR, int data);
void create_new_list(Dlist **headR, Dlist **tailR, int n_nodes);


int sl_insert_first(Dlist **head,data_t data);
int dl_insert_last(Dlist **head, Dlist **tail, data_t data);
int dl_insert_first(Dlist **head,Dlist **tail, data_t data);
int dl_delete_list(Dlist **head, Dlist **tail);

#endif
