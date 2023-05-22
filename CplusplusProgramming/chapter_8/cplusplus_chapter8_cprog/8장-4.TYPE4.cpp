// 8장-4.TYPE4.CPP  8.1 타입 호환성 규칙 
// 이 file은 class들에 대한 변수가 선언될 때 C++의 타입 호환성 규칙을 보여준다
// 두 변수의 값인 객체들의 데이터 member는 같지만,
// 선언된 class가 다르므로, 서로 다른 타입으로 간주한다.
// 주의 : 이 program은 고의적인 error를 가지고 있다.
#include <iostream>
using namespace std;
class TwoChars {
	char first;
	char second;
public:
	TwoChars(char f, char s) : first(f), second(s)
	{ }
	TwoChars() {
		first = 0; second = 0;
	}
};

class StateCode {
	char first;
	char second;
public:
	StateCode(char f, char s) : first(f), second(s)
	{ }
	StateCode() {
		first = 0; second = 0;
	}
};

void main() {
	// 두 개의 pointer를 정의한다.
	StateCode* pState1;
	TwoChars* pState2;
	StateCode s;
	TwoChars t = s;
	s = t;
	// pointer들의 할당과 초기화
	pState1 = new StateCode('C', 'A');
	pState2 = new TwoChars('H', 'I');
	TwoChars* tx = pState1;
	// 변수들 간의 치환은 불가능하다.
	pState2 = pState1; // error !
	pState1 = pState2; // error !
	system("pause");
}