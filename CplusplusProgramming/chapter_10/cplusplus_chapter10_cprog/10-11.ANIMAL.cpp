// 10-12.ANIMAL.CPP  10.5.1 RunSpeaking 함수의 재검토
#include <conio.h>
#include "10-11.ANIMAL.h"
#include <iostream>
#include <Windows.h>
using namespace std;

Animal::Animal(Point p) :
	position(p)
{}

void Animal::Speak() {
	cout << "Animal::Speak()->The animal is making his verse" << endl;
}

void Animal::JumpBy(int x_coord, int y_coord) {
	position += Point(x_coord, y_coord);
}

void Animal::MoveTo(Point newPosition) {
	position = newPosition;
}

void Animal::MoveOutput() {
	cout << "Animal::MoveOutput()-> x =  " << position.x_Coor() << ", y = " << position.y_Coor() << endl;
}