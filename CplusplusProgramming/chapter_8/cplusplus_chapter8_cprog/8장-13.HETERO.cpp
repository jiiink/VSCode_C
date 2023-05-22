// 8장-13.HETERO.CPP   8.10 이질적인 데이터 구조 
// 이질적인 데이터 구조의 예
#include <iostream> 
#include <stdlib.h>
#include <conio.h>
#include "8장-9.animal.h"
#include "8장-11.cow_dog.h"
using namespace std;
void main(){
    //pointer의 배열
    Animal* mixedFlock[10];	  
    //pointer의 초기화
    mixedFlock[0] = new Cow("Tom");
    mixedFlock[1] = new Dog("Thomas");
    mixedFlock[2] = new Dog("Ashley");
    mixedFlock[3] = new Dog("Ryan");
    mixedFlock[4] = new Dog("Daniel");
    mixedFlock[5] = new Cow("Matthew");
    mixedFlock[6] = new Cow("Samuel");
    mixedFlock[7] = new Cow("William");
    mixedFlock[8] = new Animal("Sophie");// 추상 객체의 생성이 오류가 나지 않는다 - 해결 방법
    mixedFlock[9] = new Dog("Jessica");
    for(int i=0; i< 10;i++) mixedFlock[i]->Speak();
    system("pause");
}