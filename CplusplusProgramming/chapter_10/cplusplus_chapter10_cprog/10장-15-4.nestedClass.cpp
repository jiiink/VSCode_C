//10장-15-4.nestedClass.cpp [PRATA2005] 10.4.5 복잡한 template 사용
#include <iostream>
using namespace std;
using std::endl;
template <typename T>
class outer
{
private:
	template <typename V> // nested template class member => V는 데이터 member 정의시에 전달됨
	class inner
	{
	private:
	   V data;
	public:
	   inner(V v = 0) : data(v) {}
	   void show() const { cout <<"inner::show() = "<<data<< endl; }
	   V accessData() const { return data; }
	};
	   inner<T> ix; // inner template object's instantiation => T가 V로 전달
	   inner<int> iy; // template object => int가 V로 전달
public:
	   outer( T t, int i) : ix(t), iy(i) {}
	   template<typename U> U display(U u, T t) //template function
             { return (iy.accessData() + ix.accessData()) * u / t; }
	   void ShowOuter() const {
		   cout<<"outer::ShowOuter():ix.show() and n.show() is called => ";
		   ix.show();
		   iy.show();
	   }
};
int main()
{
	outer<double> ox(3.5, 7);
	ox.ShowOuter();
	cout << ox.display(10, 2.3) << endl;
	cout <<"Done\n";
	system("pause");
	return 0;
}