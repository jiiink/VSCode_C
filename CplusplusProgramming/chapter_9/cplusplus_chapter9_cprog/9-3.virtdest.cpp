// 9-3.VIRTDEST.CPP   9.6 virtual 소멸자
/*
실습 3
 1) 내용
  본 source code는 상속 관계에서 virtual 소멸자를 상속받는 경우에 대해서 알아보는 것이다.
 2) 방법
  가. BaseClass의 소멸자에 virtual keyword를 두고 실행하여 출력 결과를 통해서 어느 class의 소멸자가 호출되는지 확인해보자.
  나. BaseClass의 소멸자에 virtual keyword를 두지 않고 실행하여 출력 결과를 통해서 어느 class의 소멸자가 호출되는지 확인해보자.
*/
#include <iostream>
using namespace std;
class BaseClass{
public:
    BaseClass(){
        cout<< "Base class 생성자 호출"<< endl;
    }
	/*
    virtual ~BaseClass(){ 
        cout<< "Base class 소멸자 호출"<< endl;
    }
	*/
	~BaseClass() {
		cout << "Base class 소멸자 호출" << endl;
	}
};

class Derived : public BaseClass{
public:
    Derived(){
        cout<< "Derived class 생성자 호출"<< endl;
    }
    ~Derived(){
        cout<< "Derived class 소멸자 호출"<< endl;
    }
};

void main(){
    cout<<"----BaseClass와 Derived class의 경우"<<endl;
    //BaseClass pointer 변수 선언  
    BaseClass* pbase;
    //pointer 변수 할당(BaseClass 객체)      
    pbase = new BaseClass;
    //자원 해제  
    delete pbase;                
    cout << endl;
    //pointer 변수 할당(Derived 객체)
    pbase = new Derived;  
    //자원 해제     
    delete pbase; //virual이 없을 때 destructor가 호출되는지를 확인하는 실습               
    cout << endl;
    Derived* d = new Derived;
    delete d;
    system("pause");
}