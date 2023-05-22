//10장-15-3.TwinThing.cpp [PRATA2005] 10.4.5 복잡한 template 사용
#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class TwinThing
{
private:
	T1 a;
	T2 b;
public:
	T1 & access_a();
	T2 & access_b();
	T1 access_a() const { return a; }
	T2 access_b() const { return b; }
	TwinThing(const T1 & p1, const T2 & p2) : a(p1), b(p2) { }
	TwinThing() {}
};
template<class T1, class T2>
T1 & TwinThing<T1, T2>::access_a()
{
	return a;
}
template<class T1, class T2>
T2 & TwinThing<T1, T2>::access_b()
{
	return b;
}
int main()
{
	TwinThing<char *, int> course[4] =
	{
	   TwinThing<char *, int>("programming", 1),
	   TwinThing<char *, int>("data structures", 2),
	   TwinThing<char *, int>("file structures", 3),
	   TwinThing<char *, int>("databases", 4)
	};
	for (int i = 0; i < 4; i++)
	   cout << "a = " <<course[i].access_a() << ", b = " <<course[i].access_b() << endl;
	course[2].access_a() = "C programming";
	course[2].access_b() = 2;
	cout << "course[2]::";
	cout << "a = " << course[2].access_a() << ", b = " << course[2].access_b() << endl;
	system("pause");
	return 0;
}