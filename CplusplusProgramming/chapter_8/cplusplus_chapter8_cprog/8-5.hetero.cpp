//8-5.HETERO.cpp   8.10 이질적인 데이터 구조 
#include <iostream>
using namespace std;
/*
실습예제 8.5
1) 내용
본 source code는 C++의 polymorphism를 이용하여 이질적인 데이터들의 집합에 대해 이해해보는 것이다.
2) 방법
가) class Animal, Cow, Dog의 member변수, member함수, 상속관계를 확인해보자.
나) 배열의 원소들에 대한 동적 binding을 확인해보자.
다) Animal 객체를 한 배열에 저장할 때 class Animal의 객체를 생성하지 못하게 하는 방법을 생각하자.
라) subclass가 다르지만 같은 명령문으로 Speak()를 실행할 수 있는 이유를 생각해보자.
*/
class Animal
{
public:
    Animal(){
        name = " ";
	}
    //*
	Animal(char* a){
        name = a;
    }
    //*/
    //virtual ~Animal();
    //함수"speak"는 각 유도된 class에 의해 재정의 된다.
    virtual void Speak();
protected:
	char* name;
    /*
    Animal(char* a) {
        name = a;
    }
    */
};


void Animal::Speak(){
    cout<<"Animal::The animal is making his verse"<<endl;
}


class Cow : public Animal{
public:
    Cow(char* a);
    void Speak();
};

class Dog : public Animal{
public:
    Dog(char* a);
    void Speak();
};

Cow::Cow(char* a):
Animal(a){}

void Cow::Speak(){
    cout <<"Cow::"<< name << " says moo" << endl;
}

Dog::Dog(char* a):
Animal(a){}

void Dog::Speak(){
    cout<<"Dog::"<< name << " says arf" <<endl;
}


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
    mixedFlock[8] = new Animal("Sophie");//Animal 객체는 논리적으로 틀림
    mixedFlock[9] = new Dog("Jessica");

    for(int i=0; i< 10;i++)
        mixedFlock[i]->Speak();
    system("pause");
}