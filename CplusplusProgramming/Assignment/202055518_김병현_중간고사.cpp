//학번 : 202055518 
//이름 : 김병현
//인증번호 : 209404059
#include <iostream>
#include <string.h>
using namespace std;

class Dept {
private : 
    string dname;
    char* city;
public : 
    Dept();
    Dept(string dname, const char* city) {
        this->city = new char[strlen(city) + 1];
        strcpy(this->city, city);
        //this->dname = new string[strlen(dname) + 1];
        strcpy(this->dname, dname);
    }
    ~Dept() {
        delete[]city;
    }
    friend ostream& operator<<(ostream&, Dept&);
    friend istream& operator>>(istream&, Dept&);    
};

ostream& operator<<(ostream&os, Dept& d) {
    os << "dname : " << d.dname << " city : " << d.city << endl;
    return os;
}
istream& operator>>(istream& is, Dept& d) {
    d.dname = is;
    return is;
}

class Emp {
private : 
    string* ename;
    Dept* dept;
public : 
    Emp(string* ename, Dept* dept) {
        this->ename = ename;
        this->dept = dept;
    }
    Emp() {
        this->dept = nullptr;
        this->ename = NULL;
    }
    ~Emp() {

    }
    
    friend Emp& changeName(Emp&);
    friend ostream& operator<<(ostream&, Emp&);
    friend istream& operator>>(istream&, Emp&);
};

istream& operator>>(istream& is, Emp& d) {
    d.ename = 
}

class Stack {
private : 
    Emp* items[20];
    int top;
public:
    Stack() {
        for (int i=0; i<20; i++) {
            this->items[i] = nullptr;
        }
    }
    ~Stack() {
        for (int i=0; i<20; i++) {
            delete items[i];
        }
    }

    void Show();
    void operator=(Stack&);
    void push(Emp&);
    Emp& pop();
};

Emp& Stack::pop() {
    Emp* temp;

    int index = 0;

    while (1) {
        if (this->items[index] != NULL) {
            index++;
        } else break;
    }

    temp = this->items[index-1];
    this->items[index-1] = nullptr;

    return *temp;
}

void Stack::push(Emp& e) {
    int index = 0;

    while (1) {
        if (this->items[index] != NULL) {
            index += 1;
        } else {
            break;
        }    
    }

    this->items[index] = new Emp(e.ename, e.dept);
}

void Stack::Show() {
    int index = 0;

    while (1) {
        if (this->items[index] != NULL) {
            index += 1;
        } else {
            break;
        }    
    }
    for (int i=0; i<index; i++) {
        cout << "name : " << this->items[i]->ename << "\t dept : " << this->items[i]->dept << endl;
    }
}

Emp& changeName(Emp& e) {
    //e.ename 을 변경한다.
    //e.ename = "lee";
    strcpy(e.ename, "lee");
    return e;
}

int main () {
    while (1) {
        Stack s2;

        int select;
        cout << "\n선택 1: Push, 2. Pop, 3: 스택 모든 객체 출력, 4. Pop한 객체의 이름 변경, 5. 종료" << endl;

        cin >> select;
        switch (select) {
            case 1:
            {
                string name, dept;
                //화면에서 입력받는데 operator>>()를 사용
                for (int i=0; i<3; i++) {
                    //Emp* e = new Emp();
                    // cin >> e;
                    cin >> name >> dept;
                    Emp* e(name, dept);
                    s2.push(&e);
                }
                //Emp e("kim", "cse");
                //s2.push();
                break;
            }
            case 2:
            {
                for () {
                    Emp e2 = s2.pop();
                    cout << e2;//Emp 출력은 Dept 출력까지 처리해야 한다.
                }
                break;
            }
            case 3:
            {
                cout << s2;
                break;
            }
            case 4:
            {
                Emp e3 = s2.pop();
                Emp e4;
                e4 = changeName(e3);
                break;
            }
            default :
                exit(0);
                break;
        }
    }
    system("pause");
    return 1;
}
