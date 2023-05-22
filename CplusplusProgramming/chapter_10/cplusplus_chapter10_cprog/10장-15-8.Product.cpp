//10장-15-8.Product.cpp [PRATA2005] 10.4.5 복잡한 template 사용
#include <iostream>
using namespace std;

template <typename T>
class product
{
private:
	T item;
public:
	product(const T & i) : item(i) {}
	template <typename C, typename D> friend void show(C &, D &);//class 내부에서 template 선언
};
template <typename C, typename D> void show(C & c, D & d)
{
	cout << "show()::product<T>: T item = "<< c.item << ", " << "product<T>: T item = "<< d.item << endl;
}

int main()
{
	product<int> p1(10);

	product<int> p2(20);
	product<double> pd(10.5);
	cout << "p1, p2 =>> ";
	show(p1, p2);//모든 function specialization이 template class instance에 대하여 적용됨
	cout << "p2, pd =>> ";
	show(p2, pd);
	cout << "pd, p1 =>> ";
	show(pd, p1);
	cout << "pd, p2 =>> ";
	show(pd, p2);
	system("pause");
	return 0;
}