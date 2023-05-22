#pragma once
// 10-5.Polymorphism_Stack.h  10.4.3 template을 이용한 Container class 표현
template <class T>
class Stack {
	T data[50];
	int nElements;
public:
	Stack() :
		nElements(0)
	{}

	void Push(T elem);
	T Pop();
	int Number();
	int Empty();
};



