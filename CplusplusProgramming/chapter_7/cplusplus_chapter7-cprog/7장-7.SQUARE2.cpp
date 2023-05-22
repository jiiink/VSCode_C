//7장-7.SQUARE2.CPP
//class Rectangle로부터 class Square의 유도
//(두 번째 version)
#include "7장-4.RECTANG.h"
class Square : public Rectangle{
public:
	Square (int side, int x_pos = 0, int y_pos = 0) :      Rectangle (side, side, x_pos, y_pos){ }

	//효율성을 위해 재정의된 함수
	//Rectangle을 위한 둘레 길이는 (base+height)*2로 계산되었다.
	int Perimeter (){
		return (Base() * 4) ;
	}

	//추가된 함수(이것은 정사각형의 전형적인 계산이다.)
	float Diagonal (){
		return Base () * 1.4142 ;
	}
} ;
ostream& operator << (ostream& s, Square sq){
	//class Rectangle의 member 함수를 사용하는 문장
	s << "Square: Side = " << sq.Base () << endl ;
	//class Square의 member 함수를 사용하는 문장 
	s << "\tDiagonal = " << sq.Diagonal () << endl ;
	//class Rectangle의 member 함수를 사용하는 문장 
	s << "\tArea = " << sq.Area () << endl ;
	//class Square에서 재정의된
	//class Rectangle의 member 함수를 사용하는 문장 
	s << "\tPerimeter = " << sq.Perimeter () << endl ;
	return s ;
}
void main(){
	int side ;
	cout << "Input the value of the side (or 0 to end): ";
	cin >> side;
	cout << endl;
	while (side != 0){
		Square sq (side);
		cout << sq << endl;
		//새로운 값을 요청한다
		cout << "Input the value of the side (or 0 to end): ";          
		cin >> side;
		cout << endl;
	}
	system("pause");
}