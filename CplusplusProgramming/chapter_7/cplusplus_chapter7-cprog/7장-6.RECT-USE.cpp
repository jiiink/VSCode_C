//7장-6.RECT-USE.CPP  7.2.1 정사각형과 직사각형
//class Rectangle의 사용 예
#include "7장-4.RECTANG.h"
//file SQUARE1.CPP                                   
//class Rectangle로부터 class Square를 유도
//(첫 번째 version)

class Square : public Rectangle{
	int n;
public:
    Square (int side, int x_pos = 0, int y_pos = 0) :
		Rectangle(side, side, x_pos, y_pos) {
		n = 999;
	}
	//friend ostream& operator <<(ostream& ost, Square& sqr);
	int ReadN() { return n; }
};
//*
ostream& operator << (ostream& ost, Square& sqr)
{
	ost << (Rectangle)sqr;
	ost << sqr.ReadN() << endl;
	return ost;
}
//*/
void main (){
	Rectangle *r = new Square(2,4,5);
	cout<<"*r = "<<*r;
    Square squ (8, 12, 18);
	cout<<"squ = "<<squ;
    cout << "Square perimeter is " << squ.Perimeter () << endl;
	system("pause");
}