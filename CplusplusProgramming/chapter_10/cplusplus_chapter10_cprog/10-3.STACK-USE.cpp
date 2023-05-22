// 10-3.STA1-USE.CPP   10.2 macro로 genericity를 표현
// class Stack의 instance 예제
#include <iostream>
#include "10-1.STACK1.h" //macro 사용
using namespace std;
// 정수 stack 정의
void main (){
    // main()에서 두 개의 stack을 동시에 만들고자 하는 실습
    Stack intStack;
    // 값을 stack에 넣는다.
    intStack.Push (500);
    intStack.Push (1992);
    intStack.Push (33);
    intStack.Push (1024);
	cout<<"Number of stack = "<<intStack.Number()<<endl;
    // stack을 비우면서 요소를 출력
    // /*
    while (! intStack.Empty ())
        cout << intStack.Pop () << endl;
       // */
	if (intStack.Empty()) cout<<"Stack is Empty"<<endl;

    //정수 stack이므로 실수 저장하여도 Pop()에서 정수로 변환되는 문제가 있다
    Stack floatStack;
    //#define Type float 사용시 오류 확인
    floatStack.Push(5.00);
    floatStack.Push(19.92);
    floatStack.Push(3.3);
    floatStack.Push(10.24);//입력 가능?  이유 확인 필요
    cout << "Number of intstack = " << intStack.Number() << endl;
    cout << "Number of floatstack = " << floatStack.Number() << endl;
    // stack을 비우면서 요소를 출력
    while (!floatStack.Empty())
        cout << floatStack.Pop() << endl; //int로 출력된다 
    if (floatStack.Empty()) cout << "Stack is Empty" << endl;
	system("pause");
} 