// 8장-7.BINDING.CPP  8.5 virtual 함수
// 정적 binding과 동적 binding 사이의 차이에 대한,
// 예제로서 단순 참조용으로 위해 만든 것이다 
#include <iostream>
using namespace std;
// class 이름을 출력하는 두 개의 함수를 가진 class A를 정의 한다 
class A {
public:
    A ( ) { }
    virtual void Dynamic (){
        cout << "A::Dynamic function of class A" << endl;       
    }
    void Static (){
        cout << "A::Static function of class A" << endl;
    }
} ;
// class A로부터 유도된, class B를 정의하는 데 두 개의 함수를 재정의한다.
class B : public A {
public:
    B ( ) { }
    void Dynamic () {
		//A::Dynamic();
        cout << "B::Dynamic function of class B" << endl;   
    }
    void Static () {
        cout << "B::Static function of class B" << endl;
    }
} ;

void main(){
    // 두개의 변수를 pointer 변수로 정의하고 있다
    A * a;
    B * b;
    // 초기화
    a = new A ();
    b = new B ();
    cout << "Functions of object a of class A" << endl;
    a -> Dynamic ();
    a -> Static ();
    cout << endl;
    cout << "Functions of object b of class B" << endl;
    b -> Dynamic ();
    b -> Static ();
    cout << endl;
    /* polymorphism 때문에, 변수 a는 class B의 객체를 가리키는     pointer를 값으로 가질 수 있다.*/
    a = b;

    cout << "Functions of the object a of class A" << endl
          << "to which has been assigned a value of class B"<< endl;
    // B class의 virtual 함수를 호출
    a -> Dynamic ();
    // A class의 non-virtual 함수를 호출
    a -> Static ();
	system("pause");
}