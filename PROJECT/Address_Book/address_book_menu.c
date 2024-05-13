#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include"address_book_fops.h"
#include"address_book_menu.h"
#include"address_book.h"
//#include "abk_fileops.h"
//#include "abk_log.h"
//#include "abk_menus.h"
//#include "abk.h"

int get_option(int type, const char *msg)
{
	/*
	 * Mutilfuction user intractions like
	 * Just an enter key detection
	 * Read an number
	 * Read a charcter
	 */ 
    int option;
    char ch;
    switch(type)
    {
	case NONE:
	    printf("%s",msg);
	    break;
	case CHAR:
	    printf("%s",msg);
	    scanf(" %c",&ch);
	    return ch;
	case NUM:
	    printf("%s",msg);
	    scanf("%d",&option);
	    return option;

    }

	/* Fill the code to add above functionality */
}

Status save_prompt(AddressBook *address_book)
{
	char option;

	do
	{
		main_menu();

		option = get_option(CHAR, "\rEnter 'N' to Ignore and 'Y' to Save: ");

		if (option == 'Y')
		{
			save_file(address_book);
			printf("Exiting. Data saved in %s\n", DEFAULT_FILE);

			break;
		}
	} while (option != 'N');

	free(address_book->list);

	return e_success;
}

Status list_contacts(AddressBook *address_book)
{
	/* 
	 * Add code to list all the contacts availabe in address_book.csv file
	 * Should be menu based
	 * The menu provide navigation option if the entries increase the page size
	 */ 
    for(int i=0;i<address_book->count;i++)
    {
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("Name: %s Mobile: %s Email: %s\n",address_book->list[i].name,address_book->list[i].phone_numbers,address_book->list[i].email_addresses);
    }
    printf("\n");


	return e_success;
}

#if 0
void menu_header(const char *str)
{
	fflush(stdout);

	system("clear");

	printf("#######  Address Book  #######\n");
	if (*str != '\0')
	{
		printf("#######  %s\n", str);
	}
}
#endif

void main_menu(void)
{
	//menu_header("Features:\n");

	printf("0. Exit\n");
	printf("1. Add Contact\n");
	printf("2. Search Contact\n");
	printf("3. Edit Contact\n");
	printf("4. Delete Contact\n");
	printf("5. List Contacts\n");
	printf("6. Save\n");
	printf("\n");
	printf("Please select an option: ");
}

Status menu(AddressBook *address_book)
{
	ContactInfo backup;
	Status ret;
	int option;

	do
	{
		main_menu();

		option = get_option(NUM, "");

		if ((address_book-> count == 0) && (option != e_add_contact))
		{
			get_option(NONE, "No entries found!!. Would you like to add? Use Add Contacts");

			continue;
		}

		switch (option)
		{
			case e_add_contact:
				/* Add your implementation to call add_contacts function here */
			   add_contacts(address_book);
			   break;
			case e_search_contact:
				search_contact(address_book);
				break;
			case e_edit_contact:
			   edit_contact(address_book);
			   break;
			case e_delete_contact:
				delete_contact(address_book);
				break;
			case e_list_contacts:
				list_contacts(address_book);
				break;
				/* Add your implementation to call list_contacts function here */
			case e_save:
				save_file(address_book);
				break;
			case e_exit:
				break;
		}
	} while (option != e_exit);

	return e_success;
}
int contact_menu()
{
    printf("1.Name\n2.Mobile\n3.Email\n4.Exit\n");
    int ret=get_option(NUM,"please enter the choice:\n");
    return ret;


}


Status add_contacts(AddressBook *address_book)
{
	/* Add the functionality for adding contacts here */
    ContactInfo new={{'\0'},{'\0'},{'\0'}};
    int name_flag=0,mobile_flag=0,email_flag=0;
    int option;
    do{
	option=contact_menu();
	switch(option)
	{
	    case 1:
		name_flag=1;
		printf("Please enter the name:\n");
		scanf(" %s",new.name);
		break;
	    case 2:
		mobile_flag=1;
		printf("Please enter the mobile:\n");
		scanf(" %s",new.phone_numbers);
		break;
	    case 3:
		email_flag=1;
		printf("Please enter the email:\n");
		scanf(" %s",new.email_addresses);
		break;
	    case 4:
		if(name_flag && (email_flag || mobile_flag))
		    break;
		else
		{
		    printf("Please provide name and email or phone number");
		    option=0;
		    continue;
		}
	}
    }while(option!=4);
    address_book->count++;
    address_book->list=realloc(address_book->list,address_book->count*sizeof(ContactInfo));
    address_book->list[(address_book->count)-1]=new;
    return e_success;
}


Status list_mode_contacts(AddressBook *address_book,int *indexes,int count)
{
    for(int i=0;i<count;i++)
    {
	printf("---------------------------------------------------------------------------------------------\n");
	printf("Index: %d Name: %s Mobile: %s Email: %s\n",i+1,address_book->list[indexes[i]].name,address_book->list[indexes[i]].phone_numbers,address_book->list[indexes[i]].email_addresses);
    }
    printf("\n");
}



Status search(const char *str, AddressBook *address_book, int loop_count, int field, const char *msg, Modes mode)
{
	/* Add the functionality for adding contacts here */
    int *search_index=NULL;
    int list_count=0,ret;
    for(int i=0;i<address_book->count;i++)
    {
	switch(field)
	{
	    case 1:
		if(strstr(address_book->list[i].name,str)!=NULL)
		{
		    list_count++;
		    search_index=realloc(search_index,sizeof(int)*list_count);
		    search_index[list_count-1]=i;
		}
		break;
	    case 2:
		if(strstr(address_book->list[i].phone_numbers,str)!=NULL)
		{
		    list_count++;
		    search_index=realloc(search_index,sizeof(int)*list_count);
		    search_index[list_count-1]=i;
		}
		break;
	    case 3:
		if(strstr(address_book->list[i].email_addresses,str)!=NULL)
		{
		    list_count++;
		    search_index=realloc(search_index,sizeof(int)*list_count);
		    search_index[list_count-1]=i;
		}
		break;

	}
    }
    switch(mode)
    {
	case e_search:
	    list_mode_contacts(address_book,search_index,list_count);
	    break;
	case e_edit:
	    list_mode_contacts(address_book,search_index,list_count);
	    ret=get_option(NUM,"Enter the contact(index) to edit:\n");
	    return search_index[ret-1];
	case e_delete:
	    list_mode_contacts(address_book,search_index,list_count);
            ret=get_option(NUM,"Enter the contact(index) delete:\n");
            return search_index[ret-1];
	    
	case e_add:
	    break;
	case e_list:
	    break;
	default:
	    break;

    }
}

Status search_contact(AddressBook *address_book)
{
	/* Add the functionality for search contacts here */
    int ret=contact_menu();
    char str[20];
    printf("Enter the value to search: \n");
    scanf(" %s",str);
    search(str,address_book,0,ret,NULL,e_search);

}

Status edit_contact(AddressBook *address_book)
{
	/* Add the functionality for edit contacts here */
    int ret=contact_menu();
    char str[20];
    printf("Please enter the value to edit:\n");
    scanf(" %s",str);
    int index=search(str,address_book,0,ret,NULL,e_edit);
    ret=contact_menu();
    printf("Enter the new value to edit:\n");
    scanf(" %s",str);
    switch(ret)
    {
	case 1:
	    strcpy(address_book->list[index].name,str);
	    break;
	case 2:
	    strcpy(address_book->list[index].phone_numbers,str);
	    break;
	case 3:
	    strcpy(address_book->list[index].email_addresses,str);
	    break;
	default:
	    break;
    }
    //return e_success;
   printf("\nEdited successfully!!!!\n");

}

Status delete_contact(AddressBook *address_book)
{
	/* Add the functionality for delete contacts here */
     int ret=contact_menu();
     char str[20];
     printf("Please enter the value to delete:\n");
     scanf(" %s",str);
     int index=search(str,address_book,0,ret,NULL,e_delete);
     for(int i=index;i<(address_book->count-1);i++)
     {
	 address_book->list[i]=address_book->list[i+1];
     }
     address_book->count--;
     address_book->list=realloc(address_book->list,address_book->count*sizeof(ContactInfo));
     return e_success;

}
