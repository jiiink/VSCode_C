// 10장-9.STA3-USE.CPP  10.4 template class
// Stack class의 한 사례를 만든 예제
#include <iostream>
//#include "10장-7.Stack3.h"
#include "10장-8.STACK3.CPP" // Visual Studio에서 template 사용시에 cpp를 먼저 include, header를 사용하지 않아야 함
using namespace std;

void main(){
    // 정수 stack의 정의
    Stack <int> intStack;
    intStack.Push (500);
    intStack.Push (1992);
    intStack.Push (33);
    intStack.Push (1024);
    Stack<float> fstack;
    // stack에서 하나씩 꺼내면서 값을 출력한다.
    while (! intStack.Empty ()){
            cout << intStack.Pop () << endl;
	}
	system("pause");
}