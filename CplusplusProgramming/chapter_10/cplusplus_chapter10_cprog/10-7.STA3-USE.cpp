// 10-7.STA3-USE.CPP   10.4.3 template을 이용한 Container class 표현
#include "10-6.STACK3.CPP" ////Visual Studio는 template 사용시에 .cpp를 include하고 방법 사용-편법
//#include "10-6.STACK3.h" //Visual Studio는 template 사용시에 header file의  include시에 오류 발생하게 함
//Visual Studio는 template 사용시에 header file을 사용하지 않아야 link 에러가 해결
/*
실습 3
 1) 내용
  본 source code는 template를 이용하여 한 class에 대한 여러 데이터 타입의 객체를 다루는 방법을 알아보는 것이다.
 2) 방법
  가. class Stack의 선언과 각 함수의 구현을 확인해보자.
  나. 같은 구조의 stack에 각기 다른 class의 객체가 어떤 방식으로 저장되는지를 통해서 template의 개념에 대해 이해해보자.
  다. 같은 구조의 stack에서 각기 다른 class의 객체가 어떤 방식으로 출력되는지를 통해서 template의 개념에 대해 이해해보자.
*/
#include <iostream>
#include <string>
using namespace std;

void main(){
    //int형 stack의 정의
    Stack <int> intStack;
    //intStack.Push(n); 가능한지 확인? 가능하게 하려면 필요한 code는?
    intStack.Push(50);
    intStack.Push(19);
    intStack.Push(3);
    intStack.Push(10);
    intStack.Push('aa');//입력 가능
    //stack에서 하나씩 꺼내면서 값을 출력한다.
    cout<<"-----int type stack"<<endl;
    while(! intStack.Empty()){
        cout<< intStack.Pop() << endl;
    }
    //double stack의정의
    Stack <double> doubleStack;
    //stack에 값을 추가한다.
    doubleStack.Push(500.8);
    doubleStack.Push(1992.8);
    doubleStack.Push(33.8);
    doubleStack.Push(1024.8);
    //stack에서 하나씩 꺼내면서 값을 출력한다.
    cout<<"-----double type stack"<<endl;
    while(! doubleStack.Empty()){
        cout<< doubleStack.Pop() << endl;
    }
    //String stack의정의
    Stack <string> stringStack;

    stringStack.Push("500");
    stringStack.Push("1992");
    stringStack.Push("33");
    stringStack.Push("1024");
    stringStack.Push(50);//다른 타입에 대하여 push 실행 여부를 실습
    //stack에서 하나씩 꺼내면서 값을 출력한다.
    cout<<"-----string type stack"<<endl;
    while(! stringStack.Empty()){
        cout << stringStack.Pop() << endl;
    }
	system("pause");
}