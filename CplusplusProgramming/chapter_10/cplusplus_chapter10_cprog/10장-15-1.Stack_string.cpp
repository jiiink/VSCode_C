//10장-15-1.Stack_string.cpp [PRATA2005] 10.4.3 template을 이용한 Container class 표현
/*
header file을 사용하지 않고 하나의 file로 저장시에 link error 없음
*/
#include <iostream>
#include <stdlib.h>
using namespace std;
#define Num 10
#define SIZE 100
template <class T>
class Stack
{
private:
	int nElements;
	T * data;
	int top; 
public:
	Stack(int s = SIZE);
	~Stack() { delete[] data; }
	bool Empty() { return top == 0; }
	bool Full() { return top == nElements; }
	bool push(const T & item);
	bool pop(T & item); 
};
template <class T>
Stack<T>::Stack(int s = SIZE) : nElements(s), top(0)
{
	data = new T[nElements];
}

template <class T>
bool Stack<T>::push(const T & item)
{
	if (top < nElements)
	{
	   cout << "Stack::push() = " << item << endl;
	   data[top++] = item;
	   return true;
	}
	else
	   return false;
}
 
template <class T>
bool Stack<T>::pop(T & item)
{
	if (top > 0)
	{
	   item = data[--top];
	   return true;
	}
	else
	   return false;
}


int main()
{
	cout << "Please enter stack size: ";
	int n;
	cin >> n;

	Stack<const char *> st(n);

	const char * fish[Num] = {
	"Cod", "Tuna", "squid", "octopus", "mackeral", "eel",
	"salmon", "carp", "sea bass", "trout"
	};
	const char * food[Num];
	int i = 0;
	int j = 0;
	while (i < Num)
	{
	   if (st.Empty())
	      st.push(fish[j++]);
	   else if (st.Full())
	      st.pop(food[i++]);
	   else if (j < Num)
	      st.push(fish[j++]);
	   else
	      st.pop(food[i++]);
	}
	for (int i = 0; i < Num; i++)
	   std::cout << food[i] << std::endl;
	cout << "Bye\n";
	system("pause");
	return 0;
}