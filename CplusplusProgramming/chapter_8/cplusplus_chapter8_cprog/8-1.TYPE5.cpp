// 8-1. TYPE5.CPP   8.1 타입 호환성 규칙 
#include <iostream>
using namespace std;
/*
실습예제 8.1
1) 내용
본 source code는 class 관계에 따라 class에 대한 pointer를 서로 치환할 수 있는지 없는지를 보여주는 내용이다.
2) 방법
가. 주석 1에서 base class pointer 변수에 치환을 했을 때와 유도된 class pointer 변수에 치환을 했을 때의 차이를 확인해보자
*/
class TwoChars{
protected:
    char first;
    char second;
public:
    TwoChars(char f, char s):
    first(f),second(s)
    {}
    void print(){
        cout<<"\tTwoChars::first : "<<first<<", "<<"second : "<<second<<endl;
    }
};

class StateCode : public TwoChars{
public:
    StateCode(char f, char s):
    TwoChars(f, s)
    {}
    void print(){
        cout<<"\tStateCode::first : "<<first<<", "<<"second : "<<second<<endl;
    }
};

void main(){
    //두개의 pointer들을 정의한다.
    //StateCode*  pState1;
    //TwoChars*  pState2;
    StateCode pState1('C','A');
    TwoChars pState2('H','T');
    //pointer들의 할당과 초기화
    //pState1 = new StateCode('C','A');
    //pState2 = new TwoChars('H','T');
    //class pointer로 치환 전
    cout<<"--class pointer로 치환 전"<<endl;
   // pState1->print();
    //pState2->print();
    pState1.print();
    pState2.print();

    //주석 1
    //*
    //superclass pointer로 치환하는 것은 가능하다.
    pState2 = pState1;      

    cout<<"--superclass pointer로 치환 후"<<endl;
    //class pointer 치환 후
    //pState1->print();
    //pState2->print();
    pState1.print();
    pState2.print();
    //pState1 = pState2;       

    pState2 = *new TwoChars('X','Y');

    cout<<"--pState2에 새로 값을 할당 후"<<endl;
    //pState1->print();
    //pState2->print();
    pState1.print();
    pState2.print();
   //*/ 
	system("pause");
}
