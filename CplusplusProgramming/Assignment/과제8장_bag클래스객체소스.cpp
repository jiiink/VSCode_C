//8 컨테이너 클래스 - 객체들 집합 
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
using namespace std;

class Person {
private:
    string pid;
    string pname;
public:
    Person() {}
    Person(string pid, string pname) : pid(pid), pname(pname) { }
    virtual void Show(); //pid, pname
    virtual bool operator==(Person&);
    string getPid() {return pid;}
};
bool Person::operator==(Person& p) {
    return (this->pid == p.pid && this->pname == p.pname);
}
void Person::Show() {
    cout << "pid : " << this->pid << " pname : " << this->pname; 
}

class Employee : public Person {
private:
    string eno;
    string role;
public:
    Employee() : Person() {}
    Employee(string pid, string pname, string eno, string role) : Person(pid, pname), eno(eno), role(role) { }
    bool operator==(Person&) override;
    void Show();
};
bool Employee::operator==(Person& p) {
    Employee& e = dynamic_cast<Employee&>(p);
    return (Person::operator==(p) && this->eno == e.eno && this->role == e.role);
}
void Employee::Show() {
    Person::Show();
    cout << " eno : " << this->eno << " role : " << this->role; //eno, role
}



class Coder : public Employee {
private:
    string language;
public:
    Coder() : Employee() {}
    Coder(string pid, string pname, string eno, string role, string language) : Employee(pid, pname, eno, role), language(language) {}
    void Print();
    bool operator==(Person&) override;
    void Show();
};
bool Coder::operator==(Person& p) {
    if (typeid(p) == typeid(Coder)) { //p가 Coder 객체를 가리키고 있는지 확인한다.
        Coder& c = dynamic_cast<Coder&>(p);
        return (this->Employee::operator==(p) && this->language == c.language);
    } else return false;
}
void Coder::Show() {
    Employee::Show();
    cout << " language : " << language << endl;
}
void Coder::Print() {
    cout << language;
}


class Student : public Person {//virtual은 Person() 생성자를 호출하지 않음
private:
    string sid;
    string major;
public:
    Student(string sid, string major, string pid, string pname) : Person(pid, pname), sid(sid), major(major) { }
    // int operator < (Student&);
    bool operator==(Person&) override;
    void Show();
};
bool Student::operator==(Person& p) {
    Student& s = dynamic_cast<Student&>(p);
    return (Person::operator==(p) && this->sid == s.sid && this->major == s.major);
}
void Student::Show() {
    Person::Show();
    cout << " sid : " << sid << " major : " << major;
}


class PartTimeStudent : public Student {
private:
    string workType;
public:
    PartTimeStudent(string workType, string sid, string major, string pid, string pname) :
        Student(sid, major, pid, pname), workType(workType) {}
    int operator < (PartTimeStudent&);
    bool operator==(Person&) override;
    void Show();
};
bool PartTimeStudent::operator==(Person& p) {
    PartTimeStudent& pt = dynamic_cast<PartTimeStudent&>(p);
    return (Student::operator==(pt) && this->workType == pt.workType);
}
void PartTimeStudent::Show() {
    Student::Show();
    cout << " workType : " << workType << endl;
}




#define DefaultSize 30
class Bag {//순서가 없다. 중복 가능
public:
    Bag() {//생성자
        MaxSize = DefaultSize;
        top = 0;
        for (int i=0; i<MaxSize; i++) {
            arr[i] = nullptr;
        }
    }
    ~Bag() {} // 소멸자
    virtual void Add(Person*); //정수 하나를 bag에 삽입. 중복 체크 안 하고 무조건 삽입
    Person* Delete(); //bag에서 정수 하나를 삭제 무작위로 삭제. 꺼내는 동작, 삭제하고 당기기.
    //랜덤으로 꺼낸다. 
    bool IsFull();
    // bag이 포화상태이면 true, 그렇지 않으면 false를 반환
    bool IsEmpty();
    // bag이 공백 상태이면 true, 그렇지 않으면 false를 반환
    int Top();
    Person* Find(string); //pid 를 통해 Person 을 찾는다.
    virtual void Print();
protected:
    void Full() {cout << "It is full." << endl;} // bag이 포화상태일 때의 조치
    void Empty() {cout << "It is empty." << endl;} // bag이 공백 상태일 때의 조치
    Person* arr[DefaultSize];
    int MaxSize; // 배열의 크기
    int top; // 배열에서 원소가 들어 있는 가장 높은 위치, 객체가 현재 몇 개 있는지
};
bool Bag::IsFull() {
    if (top == MaxSize) return true;
    else                return false;
}
bool Bag::IsEmpty() {
    if (top == 0) return true;
    else          return false;
}
void Bag::Add(Person* p) {
    if (IsFull()) Full();
    else {
        arr[top] = p;
        top++;
    }
}
void Bag::Print() {
    Person* p;
    for (int i=0; i < top; i++) {
        p = arr[i];
        p->Show();
    }
}
int Bag::Top() {
    int i=0;
        
    while (this->arr[i] != nullptr) {
        i++;
    }
    
    return i;
}
Person* Bag::Find(string id) {//입력한 pid 와 set 에 있는 pid 와 비교한다.
    for (int i=0; i<top; i++) {
        if (arr[i]->getPid() == id) {//set 에서 입력한 pid 를 찾았을 때
            return arr[i];
        }
    }
    cout << "Can't find that person" << endl;
    return nullptr;
}
Person* Bag::Delete() {
    srand(time(nullptr));    
    int i = rand() % 30; //0부터 29까지의 난수 생성

    Person* deleted = arr[i];
    arr[i] = nullptr;

    for (int j=i; j+1<top; j++) { 
        arr[j] = arr[j+1];
    }
    top--;
    return deleted;
}



class Set : public Bag {//순서가 없다. 중복 없음
public:
    Set() : Bag() {}
    ~Set() {}      // 소멸자
                 //Set 자료구조에 맞게 Add(), Delete() 함수 재정의
    void Add(Person*); //중복 체크하고, Bag::Add() 를 호출
    void Print() {Bag::Print();}
    bool IsDuplicate(Person*);
};
bool Set::IsDuplicate(Person* p) {
    for (int i=0; i<top; i++) {
        if (*arr[i] == *p) {
            cout << "It is duplicate top : " << top << " i : " << i << endl;
            return true;
        }
    }
    return false;
}
void Set::Add(Person* p) {
    if (IsEmpty()) Bag::Add(p); //처음에 아이템이 없을 때 바로 추가
    else if (IsFull()) cout << "It is full set" << endl;
    else if (!IsDuplicate(p)) {
        Bag::Add(p);
    }
}



void Show(Person* p[]) {//동적바인딩
    for (int i=0; i<DefaultSize && p[i] != nullptr; i++) {
        p[i]->Show();
    }
}



int main() {
    Person* members[30];//Person 선언으로 변경하는 문제 해결 필요 
    Set s;
    int select;
    string name;
    Person* p;

    while (1)
    {
        cout << "\n선택 1: member  객체 30개 입력, 2. set 출력, 3: set에서 객체 찾기,4. set에서 임의 객체 삭제, 5. members[] 배열의 show 함수, 6. 종료" << endl;
        cin >> select;

        switch (select) {
        case 1://1: Coder 객체 10개 입력과 출력
        {
            members[0] = new Coder("p1", "hong", "E1", "Coding", "C++"); //pid, pname, eno, role, language
            members[1] = new Coder("p2", "hong", "E2", "Coding", "C++");
            members[2] = new Coder("p3", "kim", "E3", "Test", "JAVA");
            members[3] = new Coder("p4", "lee", "E4", "Test", "C#");
            members[4] = new Coder("p5", "ko", "E5", "Design", "GO");
            members[5] = new Coder("p6", "choi", "E6", "Design", "GO");
            members[6] = new Coder("p7", "han", "E7", "Sales", "PYTHON");
            members[7] = new Coder("p8", "na", "E8", "Sales", "C");
            members[8] = new Coder("p9", "you", "E9", "Account", "C++");
            members[9] = new Coder("p10", "song", "E10", "Production", "C#");
            members[10] = new PartTimeStudent("coding", "s001", "computer", "23001", "hong"); //workType, sid, major, pid, pname
            members[11] = new PartTimeStudent("coding", "s002", "DB", "23002", "hong");
            members[12] = new PartTimeStudent("tester", "s003", "Java", "23003", "hong");
            members[13] = new PartTimeStudent("manager", "s004", "기계", "23004", "hong");
            members[14] = new PartTimeStudent("accountant", "s005", "전기", "23005", "hong");
            members[15] = new PartTimeStudent("salesman", "s006", "의류", "23006", "hong");
            members[16] = new PartTimeStudent("planner", "s007", "전자", "23007", "hong");
            members[17] = new PartTimeStudent("audit", "s008", "화공", "23008", "hong");
            members[18] = new PartTimeStudent("DBA", "s009", "화학", "23009", "hong");
            members[19] = new PartTimeStudent("DBA", "s010", "산업", "23010", "hong");
            members[20] = new PartTimeStudent("coder", "s011", "computer", "23011", "hong");
            members[21] = new PartTimeStudent("coder", "s012", "DB", "23012", "hong");
            members[22] = new PartTimeStudent("tester", "s013", "Java", "23013", "hong");
            members[23] = new PartTimeStudent("designer", "s014", "기계", "23014", "hong");
            members[24] = new PartTimeStudent("designer", "s015", "전기", "23015", "hong");
            members[25] = new PartTimeStudent("AS", "s016", "의류", "23016", "hong");
            members[26] = new PartTimeStudent("coder", "s017", "전자", "23017", "hong");
            members[27] = new PartTimeStudent("audit", "s018", "화공", "23018", "hong");
            members[28] = new PartTimeStudent("engineer", "s019", "화학", "23019", "hong");
            members[29] = new PartTimeStudent("designer", "s020", "산업", "23020", "hong");
        
            for (int i = 0; i < 30; i++) { 
                s.Add(members[i]);
            }
            break;
        }
        case 2:
            // set의 모든 객체 출력하기
            s.Print();
            break;
        case 3:
        {
            // set에서 객체 찾기
            cout << "Insert the pid : "; //찾고 싶은 사람의 pid 를 입력한다.
            cin >> name;
            p = s.Find(name);

            if (p == nullptr) break;
            else p->Show();
            break;
        }
        case 4:
            //set에서 임의 객체 삭제하기
            if (s.IsEmpty()) {
                cout << "It is empty set" << endl;
                break;
            } else {
                p = s.Delete();
                p->Show();
                break;
            }
        case 5:
            //members[]의  모든 객체들에 대한 show() 동작: polymorphic function 구현하기
            Show(members);
            break;
        default:
            exit(0);
        }
    }
    system("pause");
    return 1;
}