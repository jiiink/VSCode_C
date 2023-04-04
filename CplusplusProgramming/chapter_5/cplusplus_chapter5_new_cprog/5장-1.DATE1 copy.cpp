#include <iostream>
#include <string.h>
using namespace std;

class Student {
	string sid;
	string sname;
	int age;
public:
	Student(string sid, string sname, int age) : age(age) {
		//this->sid = sid;
		//this->sname = sname;
		this->sid = new char[sizeof(sid)];
		this->sname = new char[sizeof(sname)];
		strcpy(this->sid, sid);
		strcpy(this->sname, sname);
	}
	~Student() {
		delete [] sid;
		delete [] sname;
	}
	friend ostream& operator<<(ostream&, Student& s);
};

ostream& operator<<(ostream& os, Student& s) {
	os<<"student::"<<s.sid<<" "<<s.sname<<" "<<s.age<<endl;
	return os;
}

int main() {
	cout << "This is a test program" << endl;
	Student s1("cse001", "kim", 23); //"cse001", "kim" is stored in data(memory) by constant
	cout << s1 << endl;;
	system("pause");
	return 1;
}

