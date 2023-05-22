
//7장-12 baseDerived.cpp
#include <iostream>
using namespace std;
class Base{
public:
    int first;
    int second;
	//int GetFourth() { return fourth; }
protected:
    int third;
private:
    int fourth;
};
	
class Derived : protected Base{
private:
    int fifth;
public:
	void show() {
		cout << third;
		//cout << fourth;//Base::fourth는 접근 못함-해결 방법은?
		//cout << GetFourth();
	}
};
void main() {
    cout<<"Size of Base : "<<sizeof(Base)<<endl;
    cout<<"Size of Derived : "<<sizeof(Derived)<<endl;
	Derived d;
	//cout << d.first;//first가 protected로 변경됨
	system("pause");
}