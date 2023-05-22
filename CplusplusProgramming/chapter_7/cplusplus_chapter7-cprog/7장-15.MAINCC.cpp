//7장-15.MAINCC.CPP
//ColorCircle 예제의 main 함수 - multiple inheritance
#include <iostream>
using namespace std;
#include "7장-13-2.CIRCLEC.h"
//#include "7장-13.CIRCLE.h"
//#include "7장_13-1.COLOR.h"

int main(){
    int nRad1, nRad2 ;
    cout << "Input starting and final radius: " ;
    cin >> nRad1 >> nRad2 ;// 8 20을 입력
	//class ColorCircle: public Circle, Color
    for (ColorCircle cc(30, 30, nRad1, Color::RED); cc.Radius ( ) < nRad2; ++cc){
        cc.Paint ( ) ;
        cout << endl ;
    }
	system("pause");
	return 1;
}