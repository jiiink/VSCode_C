#pragma once
// 10-24.COW_DOG.H  10.5.1 RunSpeaking 함수의 재검토
#include "10-11.ANIMAL.h"

class Cow : public Animal {
public:
	Cow(Point p = Point(10, 10));
	void Speak();
};

class Dog : public Animal {
public:
	Dog(Point p = Point(20, 20));
	void Speak();
};