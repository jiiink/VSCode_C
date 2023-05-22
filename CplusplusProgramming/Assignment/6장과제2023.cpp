#include <stdlib.h>
#include <iostream>
#include <string.h>
/*

*/
using namespace std;

// class String {
//     char* data;
// };

class Person {
private:
    friend class Stack;
    //String *pname;
    char* pname;
    int age;
public:
    Person ();
    Person(const char* name, int age) : age(age) {
        this->pname = new char[strlen(name) + 1];
        strcpy(this->pname, name);
        //this->pname = name;
    }
    Person(const Person&);
    Person(Person&&) noexcept;
    ~Person () {
        delete[]pname;
    }
    void print() {
        cout << endl;
        cout << "age : " << this->age << "\tname : " << this->pname << endl;
    }
    bool operator>(Person&) const;
    void operator=(Person&);
};

Person::Person(const Person& other) : age(other.age) {
    this->pname = new char[strlen(other.pname) + 1];
    strcpy(this->pname, other.pname);
}

Person::Person(Person&& other) noexcept : pname(other.pname), age(other.age) {
    other.pname = nullptr;
    other.age = 0;
}

void Person::operator=(Person& p) {
    strcpy(this->pname, p.pname);
    this->age = p.age;
}

bool Person::operator>(Person& p) const {
    return strcmp(this->pname, p.pname) > 0;
}

class Stack { 
private:
    int top;
    Person* items[100];
public:
    Stack() {
        for (int i=0; i<100; i++) {
            this->items[i] = nullptr;
        }
    }
    ~Stack() {
        for (int i=0; i<100; i++) {
            delete items[i];
        }
    }

    void Push(Person&);
    Person& Pop();
    void Show();
    void operator=(Stack&);
};

void Stack::operator=(Stack& s) {
    int index = 0;

    while (1) {
        if (s.items[index] != NULL) {
            index++;
        } else break;
    }
    cout << "index : " << index << endl;
    for (int i=0; i < index; i++) {
        this->Push(*(s.items[i]));
    }
}

Person& Stack::Pop() {
    Person* temp;

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

void Stack::Push(Person& p) {
    int index = 0;

    while (1) {
        if (this->items[index] != NULL) {
            index += 1;
        } else {
            break;
        }    
    }

    this->items[index] = new Person(p.pname, p.age);
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
        cout << "name : " << this->items[i]->pname << "\tage : " << this->items[i]->age << endl;
    }
}

int main() {
    Stack s1;
    Stack s2;
    Person* p[10];
    while (1)
    {

        int select;
        
        cout << "\n선택 1: Stack 입력(Batch), 2: Push(화면 입력), 3. PoP 한 객체를 출력, 4: 스택 모든 객체 출력," << endl;
        cout <<"5. 스택의 모든 객체를 pop하여 Person 객체 배열에 저장 후 정렬하기, 6. 스택의 치환(s1 = s2;), 7.quit = > ";
        cin >> select;
        switch (select) {
        case 1://AddBatch
        {
            cout << endl << "10개 큐에 입력" << endl;
            Person p0("kang", 30);
            Person p1("lee",  23);
            Person p2("kim",  20);
            Person p3("park", 24);

            p[0] = &p0; p[1] = &p1; p[2] = &p2; p[3] = &p3; 
         
            for (int i = 0; i < 4; i++) {
                s2.Push(*p[i]);
            }
            break;
        }
        case 2://AddOne
        {
            char sname[10];
            int year;
            cout << endl << "1개 객체를 화면 입력받아" << endl;
            cin >> sname >> year;
            Person px(sname, year);
            s2.Push(px);
            break;
        }
        case 3://Delete
        {
            cout << endl << "Delete" << endl;
            Person result = s2.Pop();
            cout << "삭제된 객체:";
        
            result.print();
            break;
        }
        case 4://Stack에 있는 모든 객체를 출력
            s2.Show();
            break;
        case 5: //stack에 있는 모든 객체를 pop하여 정렬하기
        {
            Person * arry[50];
            for (int i=0; i<50; i++) {
                arry[i] = &(s2.Pop());
            }
            
            int index = 0;
            while (1) {
                if (arry[index] != NULL) {
                    index++;
                }
                else break;
            }

            for (int i=0; i<index-2; i++) {
                
                for (int j=i+1; j<index-1; j++) {
                    
                    if ( *(arry[i]) > *(arry[j]) ) {
                        // swap
                        Person temp(*(arry[i]));
                        
                        *(arry[i]) = *(arry[j]);
                        *(arry[j]) = temp;
                        
                    }
                }
                
            }
            
            for (int i=0; i < index-1; i++) {
                
                s2.Push(*arry[i]);
            }
            s2.Show();

            
            break;
        }
        case 6:
            s1 = s2;
            s1.Show();
            break;
        default:
            exit(0);
            break;
        }
    }
    system("pause");
    return 1;
    //프로그램 종료시에 run-time이 없도록 소멸자 구현과 delete 호출 사용
}


