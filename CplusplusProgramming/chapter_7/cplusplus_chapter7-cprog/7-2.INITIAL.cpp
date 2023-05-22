//7-2.INITIAL.CPP

#include <iostream>
using namespace std;

class A{
public:
    int data;
    A(){
        cout<<"Constructor of class A"<<endl;
        data = 0;
    }
    ~A(){
        //cout<<"Destructor of class A"<<endl;
    }
};

class B : virtual public A{//virtual 추가해보기
public:
    B(){
        cout<<"Constructor of class B, derived from A"<<endl;
        data = 100;
    }
    ~B(){
        //cout<<"Destructor of class B"<<endl;
    }
};

class C : virtual public A{//virtual 추가해보기
public:
    C(){
        cout<<"Constructor of class C, derived from A"<<endl;
        data = 200;
    }
    ~C(){
        //cout<<"Destructor of class C"<<endl;
    }
};

class D : public C, public B{
public:
    D(){
        cout<<"Constructor of class D, derived from B and C"<<endl;
    }
    ~D(){
        //cout<<"Destructor of class D"<<endl;
    }
};

void main()
{
        cout << "Defining an object of class A" << endl;
        A aa;
        cout << endl;

        cout << "Defining an object of class B" << endl;
        B bb;//A의 constructor 가 먼저 호출되는 이유: 상속되는 A의 데이터 멤버는 A의 constructor 로 생성
        cout << endl;

        cout << "Defining an object of class C" << endl;
        C cc;
        cout << endl;

        cout << "Defining an object of class D" << endl;
        D dd;
        //class B,class C에 virtual이 있으면 정상, 없으면 어느 class의 
        //data인지 모호하기 때문에 error가 발생한다.
        //cout << "dd.data = " << dd.data << endl;
        //B와 C가 A를 virtual로 상속받고 D를 반복상속하면 상속 선언 시 먼저     //선언된 class의 데이터만 접근가능하다.
        cout << "dd.B::data = " << dd.B::data << endl;
        cout << "dd.C::data = " << dd.C::data << endl;
    system("pause");
}