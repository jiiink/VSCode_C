// 10-9.RunSpeaking.cpp  10.5.1 RunSpeaking 함수의 재검토
#include <iostream>
#include <stdlib.h>
#include "time.h"
using namespace std;
/*
실습 5
 1) 내용
  본 source code는 template을 이용하여 다양한 데이터 타입의 객체들을 다루는 방법을 알아보는 것이다.
 2) 방법
  가. 주석 1의 RunSpeaking()과 주석 2의 RunSpeaking()의 source code를 비교하고 차이점을 알아보자.
  나. 주석 1과 2를 하나씩 주석 해제하고 실행해보고 template의 개념을 이해해보자.
  다. Animal class를 제거한 후에 template 함수가 동작하도록 수정하는 실습을 해보자.
*/
// 10-10.POINT.H  10.5.1 RunSpeaking 함수의 재검토
//class Point의 interface는 inline 함수로 정의된다.
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

class Animal{
public:
Animal(Point p = Point());
//생성자를 protected로 변경하면 됨(main에서 언급한 error 방지)
    //virtual ~Animal();
   //함수"speak"는 각 유도된 class에 의해 재정의 된다.
    virtual void Speak();
    //virtual void Speak() = 0;
    //두 가지 다른"moving" 함수
    void JumpBy(int x_coord, int y_coord);
    void MoveTo(Point newPosition);

protected:
    //동물의 현재위치
    Point position;
    //다음 출력 연산을 위해 위치를 선택 한다
    void MoveOutput();
   };

Animal::Animal(Point p):
position(p)
{}

void Animal::Speak(){
    cout<<"Animal::Speak() -> The animal is making his verse"<<endl;
}

void Animal::JumpBy(int x_coord, int y_coord){
    position += Point(x_coord, y_coord);
}

void Animal::MoveTo(Point newPosition){
    position = newPosition;
}

void Animal::MoveOutput(){
    cout<<"Animal::MoveOutPut()-> x = " << position.x_Coor()<<", y = "<<position.y_Coor()<<"  ";
}


class Cow : public Animal{
public:
    Cow(Point p = Point(10, 10));
    void Speak();
};

class Dog : public Animal{
public:
    Dog(Point p = Point(20, 20));
    void Speak();
};


Cow::Cow(Point p):
Animal(p){}

void Cow::Speak(){
    MoveOutput();
    cout<<"Cow::Speak() ->moo"<<endl;
}

Dog::Dog(Point p):
Animal(p){}

void Dog::Speak(){
    MoveOutput();
    cout<<"Dog::Speak()->arf"<<endl;
}

//* 주석 1
void RunSpeaking(Animal& aml, int nSteps){
    srand((unsigned)time(NULL));
    for(int temp=0; temp < nSteps;++temp){
        int x_coord = (1 + rand() % 5) - 2;
        int y_coord = (1 + rand() % 5) - 2;

        aml.JumpBy(x_coord, y_coord);
        aml.Speak();
    }
}
//*/

/* 주석 2
template <class T>
void RunSpeaking(T& data, int nSteps){
    srand((unsigned)time(NULL));
    for(int temp=0; temp < nSteps;++temp){
        int x_coord = (1 + rand() % 5) - 2;
        int y_coord = (1 + rand() % 5) - 2;

        data.JumpBy(x_coord, y_coord);
        data.Speak();
    }
}
*/

void main(){
    //pointer의 배열
    Animal* mixedFlock[10];
    //pointer의초기화
    mixedFlock[0] = new Cow();
    mixedFlock[1] = new Dog();
    mixedFlock[2] = new Dog(Point (12,24));
    mixedFlock[3] = new Dog(Point (2,12));
    mixedFlock[4] = new Dog(Point (22,24));
    mixedFlock[5] = new Cow(Point (7,7));
    mixedFlock[6] = new Cow(Point (7,11));
    mixedFlock[7] = new Cow(Point (11,13));
    mixedFlock[8] = new Animal(Point (1,1));//생성자 호출을 막는 coding 실습
    mixedFlock[9] = new Dog(Point (7,19));

    for(int temp=0; temp< 10; temp++)
        RunSpeaking(*mixedFlock[temp], 1);
        system("pause");
}
