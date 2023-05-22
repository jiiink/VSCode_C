//7장-13-2.CIRCLEC.H
//class Circle과 Color로 상속된 (다중 상속)
//class ColorCircle의 정의
#include<iostream>
using namespace std;
#include "7장-13.CIRCLE.h"
#include "7장_13-1.COLOR.h"
class ColorCircle: public Circle, Color{
public:
    ColorCircle (int x, int y, int r = 20, int c = Color::RED) :
    Circle (x, y, r), Color (c){ 
        cout << endl << "ColorCircle:: constructor is called" << endl;
    }
    void Paint ( ){
        Circle :: Paint ( ) ;
        cout << ", the color number is " << Color::Col ( ) ;
    }
    void operator ++ ( ){
        Color :: operator++ ( ) ;
        Circle :: operator++ ( ) ;
    }
};