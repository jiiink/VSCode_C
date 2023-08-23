#include <stdio.h>
#include <string.h>
# define MAX 50

void registerPhoneData();
void printAll();
void searchByName();
void deleteByName();

struct Contact {
    char Name[10];
    char PhoneNumber[15];
};

struct Contact PhoneBook[MAX];

static int size = 0;  // store the actual numbers of PhoneBook


int main() {
    int select;

    while(1) {
        printf("=================== Telephone Book Management ===================\n");
        printf("<<< 1. Register\t2. Print All\t3. Search\t4. Delete\t5. Exit >>>\n");
        printf("Please enter your service number (1~5)> ");
        scanf("%d", &select);

        switch (select) {
        case 1:
            //Register
            registerPhoneData();
            break;
        case 2:
            //Print All
            printAll();
            break;
        case 3:
            //Search
            searchByName();
            break;
        case 4:
            //Delete
            deleteByName();
            break;
        default:
            return 0;
        }
    }
    return 0;
}


void registerPhoneData() {
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
void printAll() {
    printf("Display all contacts on the PhoneBook\n");
    for (int i=0; i<size; i++) {
        printf("%s\t%s", PhoneBook[i].Name, PhoneBook[i].PhoneNumber);
        printf("\n");
    }
}
void searchByName() {
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
void deleteByName() {
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




