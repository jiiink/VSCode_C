//10장-15-7.GoodsFriend.cpp [PRATA2005] 10.4.5 복잡한 template 사용
#include <iostream>
using namespace std;

template <typename T> void showCounter();
template <typename T> void display(T &);

template <typename TT>
class Goods
{
private:
	TT item;
	static int counter;
public:
	Goods(const TT & i) : item(i) {counter++;}
	~Goods() { counter--; }
	friend void showCounter<TT>();//<TT>가 specialization을 나타냄
	friend void display<>(Goods<TT> &);//<>은 argument에 <TT>를 사용하였기 때문임
};

template <typename T>
int Goods<T>::counter = 0;

template <typename T>
void showCounter()
{
	cout <<"showCounter()::template showCounter():counter = " << Goods<T>::counter << endl;
}

template <typename T>
void display(T & x)
{
	cout << "display()::Goods<T>: T item = "<< x.item << endl;
}

int main()
{
	int n = 10;
	showCounter<int>();
	//display(n);//Goods<T>가 instance가 만들어지지 않아 사용안됨
	Goods<int> gint1(33);
	Goods<int> gint2(99);
	Goods<double> gdbl(11.1);
	display(gint1); //template instance에 대하여 bound됨
	display(gint2); //template instance에 대하여 bound됨
	display(gdbl);//template instance에 대하여 bound됨
	showCounter<int>();//template instance에 대하여 bound됨
	showCounter<double>();//template instance에 대하여 bound됨
	showCounter<float>();//template instance에 대하여 bound됨
	system("pause");
	return 0;
}