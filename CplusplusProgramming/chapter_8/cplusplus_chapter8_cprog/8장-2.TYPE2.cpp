// 8장-2.TYPE2.CPP  8.1 타입 호환성 규칙 
// 이 file은 C++의 타입 호환성 규칙을 설명하기 위하여 error가 있는 // program이다.
// struct의 구성 요소는 같지만, 두 변수가 다른 struct들에 대해 정의됨.
// 이 경우는 struct에 대하여 compiler에 의해 임시 타입명이 정의되었다고 보아야     한다.

//주의: 이 program은 고의적인 error를 포함하고 있다.
#include <iostream>
using namespace std;

void main(){
    struct{
        char  first ;
        char  second ;
    } state1 ;
    
    struct{
        char  first ;
        char  second ;
    } state2 ;
    state1.first = 'M' ;
    state1.second = 'N' ;
    // error!  두 변수가 같은 타입이 아니다.
	state2.first = 'S';
	state2.second = 'T';
    state2 = state1 ;
    state2.second ++ ;
    cout << "Original structure: "           << state1.first
          << state1.second << endl
          << "Changed structure: "                 << state2.first
          << state2.second << endl ;
	system("pause");
}