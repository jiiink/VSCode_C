#include <stdio.h>
#include "phone.h"
#include <string.h>


void sort()
{
	if (head == NULL || head->next == NULL) return;
	printf("Sort fuction is called\n");
	printf("Before sorting\n");
	printArray(head);
	sortPhoneBook(head, size);
	printf("After sorting\n");
	printArray(head);
}


void sortPhoneBook(Contact* head, int size)
{
	printf("size: %d\n", size);
	Contact* current = head;

	for (int i=0; i<size; i++) {
		if (current->next == NULL) break;
		for (int j=0; j<size-1-i; j++) {
			if (strcmp(current->Name, current->next->Name) > 0) {
				swapNodeData(current, current->next);
			}
			current = current->next;
		}
		current = head;
	}
}

void swapNodeData(Contact* contact1, Contact* contact2) {
	char tempName[20];
	char tempNumber[20];
	strcpy(tempName, contact1->Name);
	strcpy(contact1->Name, contact2->Name);	
	strcpy(contact2->Name, tempName);

	strcpy(tempNumber, contact1->PhoneNumber);
	strcpy(contact1->PhoneNumber, contact2->PhoneNumber);
	strcpy(contact2->PhoneNumber, tempNumber);
}
