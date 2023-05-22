// 8장-12.running.cpp   8.8 유도된 class의 상세화 
// 화면 주위에서 움직이는 동물들
#include <iostream> 
#include <stdlib.h>
#include "8장-9.animal.h"
#include "8장-11.cow_dog.h"
using namespace std;
// 동물에 대한 참조를 사용한 "polymorphic"  global 함수
void RunSpeaking (Animal& a, int nSteps){    
    for (int i = 0; i < nSteps; ++i){
        int x = rand()%5 - 2;
        int y = rand()%5 - 2;
        a.JumpBy(x, y);
        a.Speak ();
    }
}
// polymorphism적인 RunSpeaking 함수를 사용하는 main 함수 예
void main (){
    Cow cow (Point (20, 10));
    Dog dog (Point (10, 20));

    RunSpeaking (cow, 5);
    RunSpeaking (dog, 5);
	system("pause");
}