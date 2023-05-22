//7장-4.RECTANG.H 7.2.1 정사각형과 직사각형
//class Rectangle의 정의
#include <iostream>
using namespace std;
class Rectangle {
private:
	//밑변, 높이 그리고 좌측 하단 모서리의 위치 
	int base, height;
	int x_pos, y_pos;

public:
	//생성자
	Rectangle (int b, int h, int x = 0, int y = 0){
		base = b;
		height = h;
		x_pos = x;
		y_pos = y;
	}

	int Base (){
		return base;
	}
	int Height (){
		return height;
	}
	int Perimeter (){
		return ((base + height) * 2);
	}
	int Area (){
		return (base * height);
	}

	//직사각형의 이동
	void Moves (int delta_x, int delta_y){
		x_pos += delta_x;
		y_pos += delta_y;
	}

	//축척을 변경한다
	void Scale (float scale){
		base *= scale;
		height *= scale;
	}
};
ostream& operator << (ostream& s, Rectangle r){
	//Base() 등의 함수가 없으면  friend로 선언하는 것이 필요하다.
	s << "Rectangle: Base = " << r.Base () << ", Height = " 
		<< r.Height () << endl;
	s << "\tArea = " << r.Area () << ", Perimeter = " << r.Perimeter () << endl;
	return s;
}