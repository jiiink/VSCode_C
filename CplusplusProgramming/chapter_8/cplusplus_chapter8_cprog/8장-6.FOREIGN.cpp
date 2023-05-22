// 8장-6.FOREIGN.CPP   8.2 동적 Binding의 소개   
// 유도된 class의 polymorphism 예제 
#include <iostream>
using namespace std;
class Person{
protected:
    string name;
public:
    Person (string n) : name (n)
    { }
    void show() {
        cout << "Person::show()" << name<<endl;

    }
    // 동적 binding을 사용하는 virtual 함수
    virtual void Print (){
	//void Print() {
        cout << "Person::내 이름은 " << name << endl;
    }
};

class Foreigner : public Person{
public:
    Foreigner (char* n) : Person (n)
    { }    
    void show() {
        cout << "Person::show()" << name << endl;

    }
    void Print (){
        // Foreigner을 위한 이름은 ...
        cout << "Foreigner::My name is " << name << endl;
    }
} ;
void main(){
    Person * man;
    Person * woman;
    // 초기화
    man = new Person ("John");
    woman = new Foreigner ("Paola");
    // 이름들을 인쇄한다.   
    cout << "Prints the name of the man:";
    man -> Print ();
    cout << "Prints the name of the woman (a foreigner):" ;
    woman -> Print ();
    man->show();
    woman->show();
    woman->Person::show();
    // 변수 man에 class Person에서 유도된 class Foreigner의
    // 한 객체에 대한 pointer를 치환하는 것은 가능하다.
    man = new Foreigner ("Mario");

    cout << endl;
    cout << "Re-prints the name of the man after the new assignment:";
    man -> Print ();
    man->show();
    woman->show();
    woman->Person::show();
	system("pause");
}