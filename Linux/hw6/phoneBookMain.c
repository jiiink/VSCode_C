#include <stdio.h>
#include "phone.h"

void registerPhoneData();
void printAll();
void searchByName();
void deleteByName();

static int count_service = 0;	// Total number of service requests


int main()
{
	int service;		// a variable for storing user's request
	do
	{
        printf("============ Telephone Book Management ============");
        printf("\n <<<1. Register\t 2. Print All \t 3. Search by ID \t 4. Delete \t 5. Exit >>>\n");
        printf(" Please enter your service number (1-5)> ");
		scanf("%d", &service);

		switch(service)
		{
			case 1: registerPhoneData(); break;	// invoke find_ID
			case 2: printAll(); break;
            case 3: searchByName(); break;
            case 4: deleteByName(); break;
		}
	} while (service != 5);	// if Exit is not entered, the loop continues
	return 0;
}

/*****************
** Your code..
** This function should be implemented in register.c
*************************/
void registerPhoneData()
{
    printf("Registration\n");
}

/*****************
** Your code..
** This function should be implemented in search.c
*************************/
void printAll()
{
    printf("Print all contants in the PhoneBook\n");
}

/*****************
** Your code..
** This function should be implemented in search.c
*************************/
void searchByName()
{
    printf("Search by Name\n");
}

/*****************
** Your code..
** This function should be implemented in delete.c
*************************/
void deleteByName()
{
    printf("Deletion is done\n");
}
