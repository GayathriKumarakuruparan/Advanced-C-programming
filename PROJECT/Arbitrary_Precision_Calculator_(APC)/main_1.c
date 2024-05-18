/**************************************************************************************************************************************************************
*NAME           : GAYATHRI K
*DATE           : 18 MAY 2024
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "apc.h"
#include "apc.h"

int main(void)
{
        Dlist *head1, *tail1;
        Dlist *head2, *tail2;
        Dlist *headR, *tailR;
        int key;
	char option;
        do
        {
                head1 = tail1 = NULL;
                head2 = tail2 = NULL;
                headR = tailR = NULL;
                /* read the large integers */
                switch (feed_number(&head1, &tail1, &head2, &tail2))
                {
                        case '+':       /* addition */
                                addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                                break;

                        case '-':       /* subtraction */
                                subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR, &key);
                                break;

                        case '*':       /* multiplication */                               
			        multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                                break;
#if 1
                        case '/':       /* division */
                                print_list(division(&head1, &tail1, &head2, &tail2, &headR, &tailR));
                                printf("Reminder: ");
			
                                break;
#endif
                        default:
                                printf("Invalid Operator\n");
                                break;
                }
                
                print_list(headR);

                dl_delete_list(&head1, &tail1);
                dl_delete_list(&head2, &tail2);
                dl_delete_list(&headR, &tailR);

                printf("Want to continue? Press [yY | nN]: ");
		scanf("\n%c", &option);
	}while (option == 'y' || option == 'Y');
}

/* parse: parses the large integer into 4 digits and store them in a linked list */
int parse(char *a, int len, Dlist **temp1, Dlist **temp2)
{
        int i = 0;
        while (len > 0)
        {
                if (i == 4)
                {
                        dl_insert_last(temp1, temp2, atoi(&a[len]));
                        a[len] = '\0';
                        i = 0;
                        continue;
                        
                }
                --len;
                ++i;
        }
        dl_insert_last(temp1, temp2, atoi(a));
}

/* feed_numbers: read the two large numbers and return the operator */
int feed_number(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
        #define MAXLEN 100
        char ch[MAXLEN] = {'\0'};

        int operator;
        int i = 0;
        int c;
        Dlist *temp1 = *head1;
        Dlist *temp2 = *tail1;
        while ((c = getchar()) != '\n')
        {
                if (c >= '0' && c <= '9')
                {
                        ch[i++] = c;
                }
                else if (c == '+' || c == '-' || c == '*' || c == '/' )
                {
                        if (ch[0] == '\0')
                        {
                                printf("Invalid expression\n");
                                return(FAILURE);
                        }
                        operator = c;
                        ch[i] = '\0';
                        parse(ch, i, &temp1, &temp2);
                        *head1 = temp1;
                        *tail1 = temp2;
                        i = 0;
                        ch[i] = '\0';
                        temp1 = *head2;
                        temp2 = *tail2;
                }
        }
                        if (ch[0] == '\0')
                        {
                                printf("Invalid expression\n");
                                return(FAILURE);
                        }
        ch[i] = '\0';
        parse(ch, i, &temp1, &temp2);
        *head2 = temp1;
        *tail2 = temp2;
#if 0
        print_list(*head1);
        print_list(*head2);
#endif
        printf(BOLDRED "Ans: " RESET);
        return operator;
}
