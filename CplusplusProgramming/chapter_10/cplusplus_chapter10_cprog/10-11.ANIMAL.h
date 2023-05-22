// 10-11.ANIMAL.H  10.5.1 RunSpeaking 함수의 재검토
#include "10-10.POINT.h"

class Animal{
public:
	Animal(Point p = Point());
    //virtual ~Animal();
    virtual void Speak();
    //virtual void Speak() = 0;

    void JumpBy(int x_coord, int y_coord);
    void MoveTo(Point newPosition);

protected:
    Point position;
    void MoveOutput();
   };

