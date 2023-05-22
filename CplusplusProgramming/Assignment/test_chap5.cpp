#include <iostream>
#include <string.h>
using namespace std;


class Student {
    //char* name; //diff of char name[10];, char* dept;
    char* name;
    //char name[20];
    int year;
    //char* dept;
    char* dept;
    //char dept[20];
public:
    Student(const char* name, int year, const char* dept) : year(year) {
        //this->name = name; 
        //this->dept = dept;
        this->name = new char[sizeof(name)];
        this->dept = new char[sizeof(dept)];
        strcpy(this->name, name);
        strcpy(this->dept, dept);
    }
    ~Student() {
        delete[]name;
        delete[]dept;                                            
    }
    void print();
};

void Student::print() {
    cout << this->name << " " << this->dept << " " << this->year << endl;
}


int main() {
    char sname[20];
    //char* sname;
    int syear;
    char sdept[20];
    Student p1("kim", 20, "cse");
    p1.print();
    //cin >> sname >> syear >> sdept;
    //Student p1(sname, syear, sdept);
    //cout << "sname is " << sname << ", syear is " << syear << ", sdept is " << sdept << endl; 
    //system("paused");
    return 1;
}