//10장-15-2.Conatiner.cpp [PRATA2005] 10.4.3 template을 이용한 Container class 표현
#include <iostream>
#include <cstdlib>
using namespace std;
template <class T, int n>
class Container
{
private:
	T data[n];
public:
	Container() {};
	explicit Container(const T & v);
	virtual T & operator[](int i);
	virtual T operator[](int i) const;
};

template <class T, int n>
class Set : public Container<T, n>
{
private:
	T data[n];
public:
	Set() {};
	explicit Set(const T & v);
	virtual T & operator[](int i);
	virtual T operator[](int i) const;
};
template <class T, int n>
Container<T, n>::Container(const T & v)
{
	for (int i = 0; i < n; i++)
	   data[i] = v;
}

template <class T, int n>
T & Container<T, n>::operator[](int i)
{
	if (i < 0 || i >= n)
	   std::cout << "Out of Boundary";
	return data[i];
}

template <class T, int n>
T Container<T, n>::operator[](int i) const
{
	if (i < 0 || i >= n)
	   std::cout << "Out of Boundary";
	return data[i];
}
template <class T, int n>
Set<T, n>::Set(const T & v)
{
	for (int i = 0; i < n; i++)
		data[i] = v;
}

template <class T, int n>
T & Set<T, n>::operator[](int i)
{
	if (i < 0 || i >= n)
		std::cout << "Set<T,n>:: operator[] -> Out of Boundary" << endl;
	return data[i];
}

template <class T, int n>
T Set<T, n>::operator[](int i) const
{
	if (i < 0 || i >= n)
		std::cout << "Set<T, n>:: operator[]->Out of Boundary"<<endl;
	return data[i];
}
int main(void)
{
	using std::cout;
	using std::endl;
	Container<int, 10> intArray;
	Container<double, 10> doubleArray;
	Container< Container<int, 5>, 10> ContainerArray;//2차원 배열 처리

	int i, j;
	for (i = 0; i < 10; i++)
	{
	   intArray[i] = i;
	   doubleArray[i] = (double)i / 12.34;
	   for (j = 0; j < 5; j++)
	     ContainerArray[i][j] = i * j;
	}
	Set<int, 10> intSet;
	Set<double, 10> doubleSet;
	Set< Set<int, 5>, 10> ContainerSet;
	for (i = 0; i < 10; i++)
	{
		intSet[i] = i;
		doubleSet[i] = (double)i / 12.34;
		for (j = 0; j < 5; j++)
			ContainerSet[i][j] = i * j;
	}
	system("pause");
	return 0;
}