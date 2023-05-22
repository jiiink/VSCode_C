//7장_13-1.COLOR.H                       07/CIRCLE
//class Color의 정의
#include<iostream>
using namespace std;
class Color{
    int color;
public:
    //color를 위한 어떤 local 상수를 정의한다.
    enum {BLACK, RED, BLUE, GREEN, YELLOW, WHITE};
    Color (int c = BLACK) : color (c) { 
        cout << endl << "Color ::constructor: color = " << color << endl;
    }

    //private 데이터를 읽거나 수정하는 함수
    int Col (){
        return color ;
    }
    void Col (int c){
        color = c ;
    }

    //증가 연산자(나머지 연산자를 사용한다)
    int operator++ (){
        color = (color + 1) % (WHITE + 1);
        return color;
    }
};