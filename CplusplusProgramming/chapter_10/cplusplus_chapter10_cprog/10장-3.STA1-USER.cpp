// 10장-3.STA1-USE.CPP   10.2 macro로 genericity를 표현
// generic class Stack의 member 함수 정의
#include <iostream>
#include "10장-1.STACK1.h"
using namespace std;
void main (){
    Stack intStack;
    intStack.Push (500);
    intStack.Push (1992);
    intStack.Push (33);
    intStack.Push (1024);

    while (! intStack.Empty ())
        cout << intStack.Pop () << endl;
	system("pause");
} 