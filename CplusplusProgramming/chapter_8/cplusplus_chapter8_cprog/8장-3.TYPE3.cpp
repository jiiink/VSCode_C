// 8장-3.TYPE3.CPP  8.1 타입 호환성 규칙 
// 이 file은 C++의 타입 호환성 규칙을 설명한다.
// 같은 문장으로 두 개의 변수를 선언하여,
// 그 변수들이 같은 타입을 가지도록 한다.(하지만, 이러한 변칙을 // 남용하면 안 된다)
#include <iostream>
using namespace std;
void main() {
	struct {
		char first;
		char second;
	} state1, state2;
	state1.first = 'M';
	state1.second = 'N';
	// OK: 두 개의 변수가 같은 타입이다.  
	state2 = state1;
	state2.second++;
	cout << "Original structure: " << state1.first
		<< state1.second << endl
		<< "Changed structure: " << state2.first
		<< state2.second << endl;
	system("pause");
}