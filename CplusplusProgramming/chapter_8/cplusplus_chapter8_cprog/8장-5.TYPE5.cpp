// 8장-5.TYPE5.CPP  8.1 타입 호환성 규칙  
// class들에 대한 pointer 변수들을 위한 C++의 타입 호환성 규칙을 보여 준다.
// 유도된 class에 대한 pointer 변수는 base class에 대한 pointer 변수에 
// 치환될 수 있지만, 그 역을 성립하지 않는다.
// 주의 : 이 program은 고의적인 error를 가지고 있다.
#include <iostream>
using namespace std;

class TwoChars {
    char first;
    char second;
public:
    TwoChars (char f, char s) : first (f),  second (s)
    { }
};
class StateCode : public TwoChars { 
//class StateCode : protected TwoChars {//assign 문 오류 발생
public:
    StateCode (char f, char s) : TwoChars (f, s)
    { }
    int show() {};
} ;
void main(){
    // 두 개의 pointer들을 정의한다.
    StateCode * pState1;
    TwoChars * pState2;
    // pointer들의 할당과 초기화
    pState1 = new StateCode ('C', 'A');
    pState2 = new TwoChars ('H', 'I');
    pState2->show();
    pState1->show();
    // superclass pointer로 치환하는 것은 가능하다.
    pState2 = pState1;
    // 그 반대는 틀리다
    //pState1 = pState2; 
        // 다른 타입의 새로운 값을 치환하는 것도 가능하다.
    pState2 = new StateCode ('A', 'R');
	system("pause");
}