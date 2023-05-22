// 10-26.HETERO.CPP   10.5.1 RunSpeaking 함수의 재검토
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <conio.h>
#include "10-24.COW_DOG.h"
//#include "10-12.animal.cpp" //현재 동작하지 않음
using namespace std;

/* 주석 1
void RunSpeaking(Animal& aml, int nSteps){
    srand((unsigned)time(NULL));
    for(int temp=0; temp < nSteps;++temp){
        int x_coord = (1 + rand() % 5) - 2;
        int y_coord = (1 + rand() % 5) - 2;

        aml.JumpBy(x_coord, y_coord);
        aml.Speak();
    }
}
*/

//* 주석 2
template <class T>
void RunSpeaking(T& ele, int nSteps){
    srand((unsigned)time(NULL));
    for(int temp=0; temp < nSteps;++temp){
        int x_coord = (1 + rand() % 5) - 2;
        int y_coord = (1 + rand() % 5) - 2;

        ele.JumpBy(x_coord, y_coord);
        ele.Speak();
    }
}
//*/

void main(){
    Animal* mixedFlock[10];

    mixedFlock[0] = new Cow();
    mixedFlock[1] = new Dog();
    mixedFlock[2] = new Dog(Point (12,24));
    mixedFlock[3] = new Dog(Point (2,12));
    mixedFlock[4] = new Dog(Point (22,24));
    mixedFlock[5] = new Cow(Point (7,7));
    mixedFlock[6] = new Cow(Point (7,11));
    mixedFlock[7] = new Cow(Point (11,13));
    mixedFlock[8] = new Animal(Point (1,1));
    mixedFlock[9] = new Dog(Point (7,19));

    for(int temp=0; temp< 10; temp++)
        RunSpeaking(*mixedFlock[temp], 1);
        system("pause");
}
