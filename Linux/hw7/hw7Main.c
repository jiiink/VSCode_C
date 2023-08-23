#include <stdio.h>
#include "phone.h"
#include <string.h>

void registerPhoneData();
void print();
// print() invokes printArray()
void printArray(void *arr, int size);
void searchByName();
void deleteByName();
void sort();

// array of function pointers.
void (* pFuncs[5])()={registerPhoneData, print, searchByName, deleteByName,sort};

// function pointer declaration
typedef int (*cmp)(const void*, int, int);
typedef int (*swap)(void*, int, int);

// Sorting PhoneBook using bubble sort
// 3rd parameter cmp cfn: a pointer to function
// 4th parameter swap sfn: a pointer to function
void sortPhoneBook(void *A, int size, cmp cfn, swap sfn);

// Functions for sortPhoneBook
// Should implement these two fuction
int contactCmpr(const void*, int, int);
int contactSwap(void*, int, int);

static int count_service = 0;	// Total number of service requests

int main() {
	int service;		// a variable for storing user's request
	do
	{
        printf("============ Telephone Book Management ============");
        printf("\n <<<1. Register\t 2. Print All \t 3. Search by ID \t 4. Delete \t 5. Sort \t 6. Exit >>>\n");
        printf(" Please enter your service number (1-6)> ");
		scanf("%d", &service);
		if ( service > 0 && service <= 5 )
		{
			pFuncs[service-1]();
		}
		else if( service ==0 || service > 6)
		{
			printf("You choose a wrong service number\n");
		}
	} while (service != 6);	// if Exit is not entered, the loop continues
	return 0;
}

/*****************
** Your code..
** This function should be implemented in register.c
*************************/
void registerPhoneData()
{
    printf("Registration\n");
    char pw[] = "qwerty1234";
    char insertedPW[20];
    static int checkCount = 0; //암호를 3번 틀리면 더 이상 전화번호를 등록할 수 없도록 한다.

    while (checkCount < 3) {
        printf("Type Password\n");
        printf("Password : ");
        scanf("%s", insertedPW);
        if (strcmp(pw, insertedPW) == 0) {
            //match
            printf("New User Name : ");
            scanf("%s", PhoneBook[size].Name);
            printf("Phone Number : ");
            scanf("%s", PhoneBook[size].PhoneNumber);
            printf("Registered...\n");
            size++;
            break;
        } else {
            checkCount++;
            printf("Not Matched !!! %d\n", checkCount);
        }
    }
    
    if (checkCount == 3) printf("You are not allowed to access PhoneBook\n");
}

/*****************
** Your code..
** This function should be implemented in search.c
** Please modify this code with your vairables
*************************/
void print() {
    printf("Print all contants in the PhoneBook\n");
	// This code illustrate sample usage of printArray()
	// Please modify this
    printArray(PhoneBook, size);
}

/*****************
** Your code..
** This function should be implemented in search.c
*************************/
void searchByName()
{
    printf("Search by Name\n");
    char searchName[10];
    int searchCount = 0;

    printf("Enter a name to search : ");
    scanf("%s", searchName);
    for (int i=0; i<size; i++) {
        if (strcmp(PhoneBook[i].Name, searchName) == 0) {
            printf("%s\t%s", PhoneBook[i].Name, PhoneBook[i].PhoneNumber);
            printf("\n");
            searchCount++;
        }
    }
    if (searchCount == 0) {
        printf("Oops! %s is not in the PhoneBook.\n", searchName);
    }
}

/*****************
** Your code..
** This function should be implemented in delete.c
*************************/
void deleteByName()
{
    printf("Deletion is done\n");
    char deleteName[10];
    int searchCount = 0;

    printf("Enter a name to delete : ");
    scanf("%s", deleteName);

    for (int i=0; i<size; i++) {
        if (strcmp(PhoneBook[i].Name, deleteName) == 0) {
            printf("%s is deleted...\n", PhoneBook[i].Name);
            for (int j=i; j<MAX-1; j++) {
                PhoneBook[j] = PhoneBook[j+1];
            }
            size--;
            searchCount++;
            break;
        }
    }
    if (searchCount == 0) {
        printf("Oops! %s is not in the PhoneBook.\n", deleteName);
    }
}

/*****************
** Your code..
** This function should be implemented in sort.c
** Please modify some parts with your vairables
*************************/
void sort()
{
	printf("Sort fuction is called\n");
	// This is test codes
	// Please modify
	printf("Before sorting\n");
	printArray(PhoneBook, size);
	// calling actual bubble sort
	// modify this function with your arrays
	// if you implement contactCmpr() and contactSwap() well
	// this code works correctly
	sortPhoneBook(PhoneBook, size, contactCmpr, contactSwap);
	printf("After sorting\n");
	printArray(PhoneBook, size);
}


/*****************
*** Bubble sort code is provided
*** Do not modify this code
*************************/
void sortPhoneBook(void *A, int size, cmp cfn, swap sfn)
{
    int i, j;
    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-i-1; j++)
        {
            if(cfn(A, j,j+1)>0)
                sfn(A,j,j+1);
        }
    }
}

/*****************
** Your code..
** This function should be implemented in sort.c
*************************/
int contactCmpr(const void* arr, int i, int j)
{
    // if arr[i]> arr[j], return 1
    // else retrun 0
    
    if (strcmp(((Contact*)arr+i)->Name, ((Contact*)arr+j)->Name)) return 1;
    else return 0;

	// Calculate address for arr[i]:  ((Contact*)arr+i)
    // derefernce structure Contact: *((Contact*)arr+i)).Name
    // for stucture we use ->: ((Contact*)arr+i)->Name
}

/*****************
** Your code..
** This function should be implemented in sort.c
*************************/
int contactSwap(void* arr, int i, int j)
{
    // Goal: arr[i] <- arr[j], arr[j] <- arr[i]
    // calculate address for arr[i]:  ((int*)arr+i)
    // derefernce int: *((int*)arr+i))
    Contact temp;
    temp = *((Contact*)arr+i);
    *((Contact*)arr+i) = *((Contact*)arr+j);
    *((Contact*)arr+j) = temp;
    
    return 1;
}

/*****************
** for implementing above two functions
** please study this funciton well
** Students can use this function for testing your codes.
*************************/
void printArray(void* arr, int size) {
    void* vp;
    vp = arr;
    for (int i=0; i<size; i++) {
        // Calculate address for arr[i]:  ((Contact*)arr+i)
        // derefernce structure Contact: *((Contact*)arr+i)).Name
        // for stucture we use ->: ((Contact*)vp+i)->Name
        printf("Addr vp:%p\t", (Contact*)vp+i);
        printf("name:%s\t phone:%s\n", ((Contact*)vp+i)->Name, ((Contact*)vp+i)->PhoneNumber);
    }
    printf("\n");
}
