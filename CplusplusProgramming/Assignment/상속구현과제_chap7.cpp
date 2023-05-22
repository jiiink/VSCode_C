//7장 클래스 상속 과제
#include <iostream>
#include <string>
using namespace std;

class Dept {
	string dname;
	string city;
	friend ostream& operator<<(ostream&, Dept&);
public:
    Dept(string dname, string city) : dname(dname), city(city) {}
    string get_dname();
    string get_city();
};
ostream& operator<<(ostream& os, Dept& d) {
    os << ", dname : " << d.dname << ", city : " << d.city;
    return os;
}
string Dept::get_dname() {
    return dname;
}
string Dept::get_city() {
    return city;
}


 

class Person {
private:
	string pid;
	string pname;
	friend ostream& operator<<(ostream&, Person&);
public:
    Person(string pid, string pname) : pid(pid), pname(pname) {}
};
ostream& operator<<(ostream& os, Person& p) {
    os << ", pid : " << p.pid << ", pname : " << p.pname;
    return os;
}




class Employee : protected Person {
private:
	string eno;
	Dept* dname;
	friend ostream& operator<<(ostream&, Employee&);
public:
    Employee(string eno, string dname, string city, string pid, string pname) : Person(pid, pname) {
        this->eno = eno;
        this->dname = new Dept(dname, city);
    }
    string get_dname();
    string get_city();
    string get_eno();
};
ostream& operator<<(ostream& os, Employee& e) {
    os << ", eno : " << e.eno;
    os << *(e.dname);
    os << (Person&)e;
    return os;
}
string Employee::get_dname() {
    return dname->get_dname();
}
string Employee::get_city() {
    return dname->get_city();
}
string Employee::get_eno() {
    return this->eno;
}




class Student : private Person {
private: 
    string sid;
    Dept* dname;
    friend ostream& operator<<(ostream&, Student&);
public:
    Student(string sid, string dname, string city, string pid, string pname) : sid(sid), Person(pid, pname){
        this->dname = new Dept(dname, city);
    }
    string get_sid();
};
ostream& operator<<(ostream& os, Student& s) {
    os << ", sid : " << s.sid;
    return os;
}
string Student::get_sid() {
    return this->sid;
}





class Coder : private Employee {
private:
	string language;
	double workYears;
public:
	Coder(string language, double workYears, string eno, string dname, string city, string pid, string pname) : Employee(eno, dname, city, pid, pname) {
        this->language = language;
        this->workYears = workYears;
    }
	int operator < (Coder&);
	friend ostream& operator<<(ostream&, Coder&);
    void swap(Coder* [10], int, int);
};
ostream& operator<<(ostream& os, Coder& c) {
    os << "language : " << c.language << ", workYears : " << c.workYears;
    os << (Student&)c;
    os << (Employee&)c;
    return os;
}
int Coder::operator < (Coder& c) {//Coder객체 정렬(Dept 이름과 도시) dname, city
    if (this->get_dname() < c.get_dname()) return 1;
    else if (this->get_dname() > c.get_dname()) return 0;
    else if (this->get_city() < c.get_city()) return 1;
    else if (this->get_city() > c.get_city()) return 0;
    else return 0;
}
void Coder::swap(Coder* c[10], int i, int j) {
    Coder* temp = c[i];
    c[i] = c[j];
    c[j] = temp;
}




class PartTimeStudent : private Employee, private Student {
private:
    double salary;
    double grade;
    friend ostream& operator<<(ostream&, PartTimeStudent&);
public:
    PartTimeStudent(double salary, double grade, string eno, string dname, string city, string sid, string pid, string pname) : Employee(eno, dname, city, pid, pname), Student(sid, dname, city, pid, pname) {
        this->salary = salary;
        this->grade = grade;
    }
    int operator < (PartTimeStudent&);
    void swap(PartTimeStudent* [10], int, int);
};
ostream& operator<<(ostream& os, PartTimeStudent& p) {
    os << "salary : " << p.salary << ", grade : " << p.grade;
    os << (Employee&)p;
    os << (Student&)p;
    return os;
}
int PartTimeStudent::operator < (PartTimeStudent& p) {//객체 정렬(eno > sid) 
    if (this->get_eno() < p.get_eno()) return 1;
    else if (this->get_eno() > p.get_eno()) return 0;
    else if (this->get_sid() < p.get_sid()) return 1;
    else if (this->get_sid() > p.get_sid()) return 0;
    else return 0;
}
void PartTimeStudent::swap(PartTimeStudent* p[10], int i, int j) {
    PartTimeStudent* temp = p[i];
    p[i] = p[j];
    p[j] = temp;
}



int main() {
    while (1)
    {
        Coder *codings[10];
        PartTimeStudent* workStudents[10];

        int select;
        //생성자 사용에 의한 입력은 new Coder("이름", ...)으로 값을 지정하여 입력
        //객체 출력은 cout<<*codings[i]만을 사용한다.
        cout << "\n선택 1: Coder 객체 10개 입력과 출력, 2. PartTimeStudent 객체 10개 입력과 출력, 3: Coder객체 정렬(Dept 이름> 도시 순서로 정렬)과 출력,4. partTimeStudents 객체 정렬(eno > sid 순서로 정렬)과 출력, 5. 종료" << endl;

        cin >> select;
        switch (select) {
        case 1://1: Coder 객체 10개 입력과 출력
            codings[0] = new Coder("a", 0, "0", "nnn", "aaaaa", "2020", "kim"); //copy paste
            codings[1] = new Coder("b", 1, "1", "aaa", "bbbbb", "2020", "kim");
            codings[2] = new Coder("c", 2, "2", "tre", "trewu", "2020", "kim");
            codings[3] = new Coder("d", 3, "3", "aaa", "fffff", "2020", "kim");
            codings[4] = new Coder("e", 4, "4", "agf", "ffhjj", "2020", "kim");
            codings[5] = new Coder("f", 5, "5", "tyk", "effyh", "2020", "kim");
            codings[6] = new Coder("g", 6, "6", "xdn", "qwfdh", "2020", "kim");
            codings[7] = new Coder("h", 7, "7", "dgh", "cgyje", "2020", "kim");
            codings[8] = new Coder("i", 8, "8", "cgr", "srfgt", "2020", "kim");
            codings[9] = new Coder("j", 9, "9", "xbh", "dsfty", "2020", "kim");

            for (int i=0; i<10; i++) {
                cout << *codings[i];
                cout << endl;
            }
            break;
        case 2://2. PartTimeStudent 객체 10개 입력과 출력
            workStudents[0] = new PartTimeStudent(0, 0, "4", "cse", "pusan", "8535", "1010", "kim");
            workStudents[1] = new PartTimeStudent(1, 1, "1", "cse", "pusan", "1214", "1010", "kim");
            workStudents[2] = new PartTimeStudent(2, 2, "8", "cse", "pusan", "7777", "1010", "kim");
            workStudents[3] = new PartTimeStudent(3, 3, "3", "cse", "pusan", "3256", "1010", "kim");
            workStudents[4] = new PartTimeStudent(4, 4, "4", "cse", "pusan", "1568", "1010", "kim");
            workStudents[5] = new PartTimeStudent(5, 5, "5", "cse", "pusan", "7966", "1010", "kim");
            workStudents[6] = new PartTimeStudent(6, 6, "6", "cse", "pusan", "2348", "1010", "kim");
            workStudents[7] = new PartTimeStudent(7, 7, "1", "cse", "pusan", "1355", "1010", "kim");
            workStudents[8] = new PartTimeStudent(8, 8, "8", "cse", "pusan", "4566", "1010", "kim");
            workStudents[9] = new PartTimeStudent(9, 9, "9", "cse", "pusan", "1256", "1010", "kim");

            for (int i=0; i<10; i++) {
                cout << *workStudents[i];
                cout << endl;
            }
            break;

        case 3://3: Coder객체 정렬(Dept 이름과 도시)과 출력 dname의 문자순서대로 정렬, dname이 같으면 city의 문자순서대로 정렬
            for (int i=0; i<10; i++) {
                for (int j=i+1; j<10; j++) {
                    if (!(*codings[i] < *codings[j])) {
                        (*codings[i]).swap(codings, i, j);
                    }
                }
            }

            for (int i=0; i<10; i++) {
                cout << *codings[i];
                cout << endl;
            }
            // if (*codings[0] < *codings[1]) cout << "codings[0] < codings[1]" << endl;
            // else cout << "codings[0] > codings[1]" << endl;
            break;
        case 4://4. partTimeStudents 객체 정렬(eno > sid)과 출력 string eno 의 문자순서대로 eno이 같으면 sid의 문자순서대로 정렬
            for (int i=0; i<10; i++) {
                for (int j=i+1; j<10; j++) {
                    if (!(*workStudents[i] < *workStudents[j])) {
                        (*workStudents[i]).swap(workStudents, i, j);
                    }
                }
            }

            for (int i=0; i<10; i++) {
                cout << *workStudents[i];
                cout << endl;
            }
            break;

        default:
            exit(0);
            break;
        }
    }
    system("pause");
    return 1;
}