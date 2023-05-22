// 10장-15.STA4-USE.CPP  10.4.2 template argument
// default 크기를 갖는 template class Stack의  instance 예
//#include "10장-13.STACK4.h" //vosual stuio 지원 문제
#include "10장-14.STACK4.cpp" //header file 사용시에 cpp를 include한다
#include <iostream>
using namespace std;
void main (){
	// 정수 stack의 정의(default된 크기를 가짐)
    Stack <int> intStack;
	// double 정수들의 작은 stack을 정의
    Stack <double, 4> miniStack;
	intStack.Push(10);
	miniStack.Push(1.234);
	intStack.Pop();
	miniStack.Pop();
	system("pause");
}