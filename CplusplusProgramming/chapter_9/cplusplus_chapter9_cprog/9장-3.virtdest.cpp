// 9장-3.virtdest.cpp   9.6 virtual 소멸자
/*
1. BASECLASS 생성자 호출 -> Derived Class의 생성자 호출
2. Derived Class의 소멸자 호출 -> BASECLASS의 소멸자 호출
*/
#include <iostream>
using namespace std;
class BaseClass{
public:
    BaseClass (){
        cout << "Base class constructor called" << endl;
    }
    virtual ~BaseClass (){ //virtual destructor
        cout << "Base class destructor called" << endl;
    }
};
class Derived : public BaseClass{
public:
    Derived (){
        cout << "Derived class constructor called" << endl;
    }
    ~Derived (){
        cout << "Derived class destructor called" << endl;
    }
};
void main (){
    BaseClass * pbase;
    cout << "Building a new BaseClass object..." << endl;
    pbase = new BaseClass;
    // pbase pointer 사용
    cout << "Deleting the object..." << endl;
    delete pbase;
    cout << endl << "Building a new Derived class object..."     << endl;
    pbase = new Derived;
	Derived *d;
	d = new Derived;
	delete d;//Derived 소멸자 호출후 BaseClass 소멸자 호출
        // 새로운 pbase pointer 사용
    cout << "Deleting the object..." << endl;
    delete pbase;//소멸자의 동적 바인딩
	system("pause");
}