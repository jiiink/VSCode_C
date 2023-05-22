#include <iostream>
#include <string.h>
using namespace std;

class Student {
private:
    int sid;
    char* sname;
public:
    Student() {
        this->sid = 0;
        strcpy(this->sname, "no");
    }
    Student(int sid, const char* sname) : sid(sid) {
        this->sname = new char[strlen(sname) + 1];
        strcpy(this->sname, sname);
    }
    // ~Student {
    //     delete[]
    // }
    friend ostream& operator<<(ostream&, const Student&);
    int operator>(const Student&); //operator overloading
};

ostream& operator<<(ostream& os, const Student& s) { //ostream how to??????? infix
    os << "pid = " << s.sid << " sname = " << s.sname << endl;
    return os;
}

int Student::operator>(const Student& other) {
    if (this->sid > other.sid) return 1;
    else return -1;
}

int main() {
    Student s1, s2(10, "hong");
    cout << s1 << endl;
    s1 = s2; // compiler default serves
    int n1 = 10, n2 = 20;

    if (s1 > s2) {
        cout << "s1 > s2" << endl;
    }
    //system("pause");
    return 1;
}