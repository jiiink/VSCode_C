// 8장-1.TYPE1.CPP  8.1 타입 호환성 규칙 
// 이 file은 C++의 타입 호환성 규칙을 설명한다.
// typedef은 struct을 사용하여 타입을 정의하고, 
// 정의된 타입 이름으로 변수를 선언한다.
#include <iostream> 
using namespace std;
void main (){
    // twoChars (모든 데이터가 public인 struct) 타입을 정의한다.
    typedef struct{
        char  first;
        char  second;
    } twoChars;
    // 위의 타입으로 두 개의 변수를 정의한다.
    twoChars state1;
    twoChars state2;
    // state1에 값을 할당한다.
    state1.first = 'M';
    state1.second = 'N';
    // 두 변수가 같은 타입이다.
    state2 = state1;//type compatible
    // 이것은 struct를 조작할 수 있는 공개 데이터이므로
    // 그래서 변수 state2의 값은 다음 문장에 의해 변경 될 수 있다.
    state2.second ++;
    // 두 struct의 값들을 인쇄한다.
    cout << "Original structure: " << state1.first
          << state1.second << endl
          << "Changed structure: "  << state2.first
          << state2.second << endl;
	system("pause");
}