#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <ctype.h>

#include "address_book.h"
Status load_contacts(AddressBook *address_book)
{
    char buffer[100];
    for(int i=0;i<address_book->count;i++)
    {
	fgetc(address_book->fp);
	fscanf(address_book->fp,"%[^\n]",buffer);
	//printf("%s\n",buffer);
	char *token=strtok(buffer,",");
	strcpy(address_book->list[i].name,token);
	if(token)
	token=strtok(NULL,",");
	strcpy(address_book->list[i].phone_numbers,token);
	if(token)
	token=strtok(NULL,",");
	strcpy(address_book->list[i].email_addresses,token);


    }
}
Status load_file(AddressBook *address_book)
{
	int ret;
	char buffer[100];
	/* 
	 * Check for file existance
	 */
	address_book->fp=fopen("contacts.csv","r");


	if (address_book->fp != NULL)
	{
		/* 
		 * Do the neccessary step to open the file
		 * Do error handling
		 */ 
	    fscanf(address_book->fp,"%[^\n]",buffer);
	    printf("%s\n",buffer);
	    address_book->count=atoi(buffer+1);
	    address_book->list=malloc(address_book->count*sizeof(ContactInfo));
	    load_contacts(address_book);
	}
	else
	{
		/* Create a file for adding entries */
	}
	fclose(address_book->fp);

	return e_success;
}

Status save_file(AddressBook *address_book)
{
	/*
	 * Write contacts back to file.
	 * Re write the complete file currently
	 */ 
	address_book->fp = fopen(DEFAULT_FILE, "w");

	if (address_book->fp == NULL)
	{
		return e_fail;
	}

	/* 
	 * Add the logic to save the file
	 * Make sure to do error handling
	 */ 
	fprintf(address_book->fp,"#%d#",address_book->count);

	for(int i=0;i<address_book->count;i++)
	{
	    fprintf(address_book->fp,"%s %s %s\n",address_book->list[i].name,address_book->list[i].phone_numbers,address_book->list[i].email_addresses);
	}
	printf("Saved succesfully!!!!!\n");

	fclose(address_book->fp);

	return e_success;
}
