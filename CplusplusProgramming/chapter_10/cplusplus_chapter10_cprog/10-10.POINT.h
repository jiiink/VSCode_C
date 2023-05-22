// 10-10.POINT.H  10.5.1 RunSpeaking 함수의 재검토
#include <iostream>
class Point{
public:
    Point(int xp=0, int yp = 0):
    xPos(xp), yPos(yp)
    {}

     int x_Coor()
    {return xPos;}

    int y_Coor()
    {return yPos;}

    void x_Coor(int px)
    {xPos = px;}

    void y_Coor(int py)
    {yPos = py;}

    void operator += (Point p){
        xPos += p.xPos;
        yPos += p.yPos;
    }
private:
      int xPos, yPos;
};
