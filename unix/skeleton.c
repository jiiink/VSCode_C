#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 10
#define MAX_NAME 100000

typedef struct {
	char name[MAX_NAME];
	int korean, math, english, computer;
	int total;
} STUDENT;


int is_num_right(int num_students); //check the number of students
void get_student_array(STUDENT students[], int num_students); //get student's info
void sort_students(STUDENT students[], int num_students); 
void swap(STUDENT students[], int index, int max_index); 
void print_students_array(STUDENT array[], int num);

int main() {
	STUDENT students[MAX_STUDENTS];
	int num_students;

	printf("Enter how many students> ");
	scanf("%d", &num_students);

	if (is_num_right(num_students)) {
		// Get info of students
		get_student_array(students, num_students);
		// Sort the array based on total scores
		sort_students(students, num_students);
		// Display all students information
		print_students_array(students, num_students);
	}

	return 0;
}

int is_num_right(int num_students) { //check the number of students
	if (num_students > MAX_STUDENTS) {
		printf("The number of students is over %d!\n", MAX_STUDENTS);
		return 0;
	} else if (num_students <= 0) {
		printf("The number of students is less than or equal to zero!\n");
		return 0;
	} else return 1;
}

void get_student_array(STUDENT students[], int num_students) {
	for (int index=0; index<num_students; index++) { //get student's info
		printf("\tStudent's name> ");
		scanf("%s", &students[index].name);

		printf("\t\tKorean> ");
		scanf("%d", &students[index].korean);

		printf("\t\tMath> ");
		scanf("%d", &students[index].math);

		printf("\t\tEnglish> ");
		scanf("%d", &students[index].english);

		printf("\t\tComputer> ");
		scanf("%d", &students[index].computer);

		students[index].total = students[index].korean + students[index].math  
							+ students[index].english + students[index].computer;
	}
}

void sort_students(STUDENT students[], int num_students) {
	STUDENT Temp;
	int max;
	int max_index;

	for (int top_index = 0; top_index < num_students - 1; top_index++) {
		max = 0;
		for (int j=top_index; j<num_students; j++) {
			if (students[j].total > max) {
				max = students[j].total;
				max_index = j;
			}
		}
		swap(students, top_index, max_index);
	}
}

void swap(STUDENT students[], int top_index, int max_index) {
	STUDENT Temp;

	Temp = students[top_index];
	students[top_index] = students[max_index];
	students[max_index] = Temp;
}

void print_students_array(STUDENT students[], int num_students) {
	printf("=====================================================\n");
	printf("Rank\tKor\tMath\tEng\tCom\tTotal\tName\n");
	for (int i=0; i<num_students; i++) {
		printf("%d\t", i+1);
		printf("%d\t", students[i].korean);
		printf("%d\t", students[i].math);
		printf("%d\t", students[i].english);
		printf("%d\t", students[i].computer);
		printf("%d\t", students[i].total);
		printf("%s\n", students[i].name);
	}
}
