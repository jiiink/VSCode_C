//7장-5.RECT-USE.CPP 7.2.1 정사각형과 직사각형
//class Rectangle의 사용 예
#include "7장-4.RECTANG.h"
void main(){
    //하나의 직사각형 정의
    Rectangle rect (10, 18);
    cout << "This is the rectangle" << endl;
    cout << rect << endl;    
    //직사각형의 크기를 두배로 변경한다
    rect.Scale (2);
    cout << "
        The rectangle has doubled" << endl;
    cout << rect << endl;    
    //정사각형을 정의하는 예제
    Rectangle square (22, 22, 12, 35);
    cout << "Here is a square" << endl;
    cout << square << endl;
	system("pause");
}