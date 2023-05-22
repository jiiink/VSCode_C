//7장-10.RECTCOL2.H의 일부
#include "7장-4.RECTANG.h"
class ColorRect : public Rectangle{
    //전과 같음
    int color;   //int는 color 번호를 나타낸다.
    void IncreaseAll (){
        ++ color; 
        //++ base;//Rectangle의 private이므로 접근 못한다.
        //++ height;//Rectangle의 private이므로 접근 못한다.
        Moves(1, 1);
    }
};