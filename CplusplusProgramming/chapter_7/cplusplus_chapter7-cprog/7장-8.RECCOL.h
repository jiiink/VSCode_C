//7장-8.RECTCOL.H
//class Rectangle로부터 color 사각형 class를 유도한다.
#include "7장-4.RECTANG.h"
class ColorRect : public Rectangle{
    int color;   //int는 color 번호를 나타낸다.
public:
    ColorRect (int b, int a, int c = 4, int x = 0, int y = 0) : 
    Rectangle (b, a, x, y), color (c) { }
    void Color (int c){
        color = c;
    }
    int Color () {
        return color;
    }
};
ostream& operator << (ostream& s, ColorRect cr){
    //Rectangle의 operator<<()을 호출한다
    s << (Rectangle) cr;

    //특정 데이터(color)를 출력
    s << "\tColor = " << cr.Color () << endl;
    return s;
}