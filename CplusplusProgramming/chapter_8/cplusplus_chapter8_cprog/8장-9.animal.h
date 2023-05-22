// 8장-9.animal.h   8.8 유도된 class의 상세화 
#include "8장-8.point.h"
class Animal{
public:
    Animal (Point p = Point ());
	Animal(char*) {}
    // 함수 "speak"는 각 유도된 class에 의해 재정의된다
    virtual void Speak ();
    void JumpBy (int x, int y);
    void MoveTo (Point newPosition);

protected:
    // 동물의 현재 위치
    Point position;
    // 다음 출력 연산을 위해 위치를 선택한다
    void MoveOutput ();
};