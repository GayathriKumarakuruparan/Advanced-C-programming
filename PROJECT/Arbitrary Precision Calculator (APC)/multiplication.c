/*******************************************************************************************************************************************************************
 *NAME                  : GAYATHRI K
 *DATE                  : MAY 18 2024
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

/* multiplication: Multiply two large numbers in two linked lists and store the result in another linked list */
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
        Dlist *temp1 = *head1;
        Dlist *temp2 = *head2;

        /* create a new list of length as head1 */
        int n_nodes = find_length(head1);
        create_new_list(headR, tailR, n_nodes);

        int carry, Res;
        Dlist *tail = *tailR;
        Dlist *Rtail = *tailR;

#if 0
        printf("In multiplication: ");
        print_list(*head1);
        print_list(*head2);
        print_list(*headR);
#endif
        while (temp2)
        {
                temp1 = *head1;
                Res = 0;
                carry = 0;
                while (temp1)
                {
                        Res =  temp1->data * temp2->data;
#if 0
                        printf("\n<--" BOLDRED "%d * %d" RESET "--> %d\n", temp1->data, temp2->data, Res);
#endif
                        Res = Res + carry;
                        carry = Res / 10000;
#if 0
                        printf("carry : %d\n", carry);
                        printf("Res : %d\n", Res % 10000);
#endif
                        Res = Res % 10000;
                        To_headR(headR, &tail, Res);

                        temp1 = temp1->next;
                        if (tail)
                                tail = tail->prev;
                }
                if (carry)
                        To_headR(headR, &tail, carry);
#if 0
                putchar('\n');
#endif
                temp2 = temp2->next;

                Rtail = Rtail->prev;
                tail = Rtail;
#if 0
                print_list(*headR);
#endif
        }
}

void To_headR(Dlist **headR, Dlist **tailR, int data)
{
        if (*tailR == NULL)
        {
                Dlist *new = (Dlist *)malloc(sizeof(Dlist));
                if (new == NULL)
                        exit(FAILURE);
                new->data = data;
                new->prev = NULL;
                new->next = *headR;

                (*headR)->prev = new;
                *headR = new;
                return;
        }
#if 0
        printf("\t\t\t\t"BOLDRED "Node: " RESET "%d + %d: ", (*tailR)->data, data);
#endif
        int sum = (*tailR)->data + data;
        
        int carry = sum / 10000;
        (*tailR)->data = sum % 10000;
        
        if (carry)
        {
                if ((*tailR)->prev)
                        (*tailR)->prev->data += carry;
                else
                        To_headR(headR, &((*tailR)->prev), carry);
        }

#if 0
        printf("%d   ", (*tailR)->data);
#endif
}

void create_new_list(Dlist **headR, Dlist **tailR, int n_nodes)
{
        for (int i = 0; i < n_nodes; ++i)
                dl_insert_last(headR, tailR, 0);
}

int find_length(Dlist **head)
{
        int i = 0;
        Dlist *temp = *head;
        while (temp)
        {
                ++i;
                temp = temp->next;
        }
        return i;
}
