#include <stdlib.h>
#include <iostream>
#include <string.h>
/*
queue를 C++의 class를 사용 > 큐 데이터 멤버가 person 객체 > person의 name이 char* 문자열로 구현
*/
using namespace std;

class Person {
    friend class Queue; //Queue can access Person's member
    char* pid;
    char* pname;
    int age;
public:
    Person(const char* id, const char* name, int age) { //string literal is const. so the argument must be const too.
        this->pid = new char[strlen(id)+1];
        this->pname = new char[strlen(name)+1];
        strcpy(this->pid, id);
        strcpy(this->pname, name);
        this->age = age;
    }
    ~Person () {
        delete[]pid;
        delete[]pname;
    }
    void Print();
};

class Queue {
    int front, rear;
    Person* queue[100];
public:
    Queue() {
        for (int i=0; i<100; i++) {
            this->queue[i] = nullptr;
        }
    }
    void Show();
    void Add(Person&);
    Person& Delete();
};

void Queue::Show() {
    int index = 0;

    while (1) {
        if (this->queue[index] != NULL) {
            index += 1;
        } else {
            break;
        }
    }
    for (int i=0; i<index; i++) {
        cout << "pid : " << this->queue[i]->pid << " pname : " << this->queue[i]->pname << "\tage : " << this->queue[i]->age << endl; 
    }
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
void Queue::Add(Person& p) {
    int index = 0;

    while (1) {
        if (this->queue[index] != NULL) {
            index += 1;
        } else {
            break;
        }
    }
    
    this->queue[index] = new Person(p.pid, p.pname, p.age);
}

Person& Queue::Delete() {
    Person* p_0 = this->queue[0];
    int index = 0;
    while (1) {
        if (this->queue[index] != NULL) {
            index += 1;
        }
        else {
            break;
        }
    }
    for (int i=0; i < index; i++) {
        this->queue[i] = this->queue[i+1];
    }
    return *p_0;
}

void Person::Print() {
    cout << "pid : " << this->pid << " pname : " << this->pname << "\tage : " << this->age << endl;
}

int main() {
    Person* p[10];
    Queue q1, q2;
    while (1)
    {
        char sno[10];
        char sname[20];
        int year;
        int select;
        cout << "\nSelect command 1: AddBatch(), 2: AddOne(1개 객체를 화면 입력받아), 3. Delete, 4: Show, 5. quit => ";
        cin >> select;
        switch (select) {
        case 1://AddBatch
        {
            cout << endl << "10개 큐에 입력" << endl;
            Person p0("s1", "hong", 12);
            Person p1("s2", "kim", 22);
            Person p2("s3", "lee", 23);
            Person p3("s4", "park", 24);
            p[0] = &p0; p[1] = &p1; p[2] = &p2; p[3] = &p3;
            for (int i = 0; i < 4; i++) {
                q1.Add(*p[i]);
            }
            break;
        }
        case 2://AddOne
        {
            cout << endl << "1개 객체를 화면 입력받아" << endl;
            cin >> sno >> sname >> year;
            Person *px = new Person(sno, sname, year);
            q1.Add(*px);
            break;
        }
        case 3://Delete
        {
            cout << endl << "Delete" << endl;
            Person result = q1.Delete();
            cout << "삭제된 객체:";
            q2.Add(result);
            result.Print();
            break;
        }
        case 4://Show - 큐의 상태를 출력
        {
            //cout << endl << "front = " << endl;
            //cout << "rear = " << endl;
            //큐에 있는 객체들을 show()를 사용하여 출력
            q1.Show();
            cout << "삭제된 객체들을 저장한 q2의 객체들을 출력" << endl;
            q2.Show();
            break;
        }
        default:
            exit(0);
            break;
        }
    }
    system("pause");
    return 1;
}

