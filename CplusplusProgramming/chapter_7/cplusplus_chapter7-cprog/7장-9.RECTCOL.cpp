//7장-9.RECTCOL.CPP
//class ColorRect의 사용 예
#include "7장-8.RECCOL.h"
void main(){
    //color 직사각형의 정의
    ColorRect cr (10, 15, 5);
    cout << "This rectangle has color" << endl;
    cout << cr << endl;
    
    //color를 변경한다
    cr.Color (8);
    cout << "The color has changed" << endl;
    cout << cr << endl;
	system("pause");
}