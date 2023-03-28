#include <iostream> //<stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Student {
    private:
        int sno;
        char* name;
        char dept[12]; //in stack
    public:
        void show();
        //string constant  can be passed to ` char const* `
        Student(int, char const*, char const*); //declare conctructor
        ~Student() { //destructor //in C calloc -> free //in C++ new -> delete
            delete[]name;
            //dept is in stack, so will be removed automatically, when the program is ended.
        }
};
void Student::show() {
    cout<<"sno = "<<sno<<" name = "<<name<<" dept = "<<dept<<endl;
    //cout is a print_object
    //printf("snp = ");
    //cout<<"sno = ";
    //cout is defined is "std"
}
Student::Student(int sno, char const* name, char const* dept) { //define constructor
            this->sno = sno;   //'this' is a pointer
            int len = strlen(name);
            this->name = new char[len+1]; //'new' allocate in heap
            strcpy(this->name, name);
            //this->dept = dept;
            strcpy(this->dept, dept);
        }

int main() {
    Student s1(11, "kim", "cse"); //s1 is variable //call the constructor Student()
    s1.show();

    system("pause");
    return 0;
}