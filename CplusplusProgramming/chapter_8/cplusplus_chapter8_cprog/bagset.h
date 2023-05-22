#pragma once
// 8-16.BAG_SET.H
#define DefaultSize 10
#include <iostream>
using namespace std;
class Bag {
public:
	// 최대 크기의 빈 bag을 만든다
	Bag(int MaxSize = DefaultSize); //생성자
	~Bag(); // 소멸자
	virtual void Add(int); // 정수 하나를 bag에 삽입
	virtual int *Delete(int&); //bag에서 정수 하나를 삭제
	bool IsFull();
	// bag이 포화상태이면 true, 그렇지 않으면 false를 반환
	bool IsEmpty();
	// bag이 공백 상태이면 true, 그렇지 않으면 false를 반환
	int Top();
	friend ostream& operator<< (ostream& stream, Bag b);
protected:
	void Full(); // bag이 포화상태일 때의 조치
	void Empty(); // bag이 공백 상태일 때의 조치
	int *arr;
	int MaxSize; // 배열의 크기
	int top; // 배열에서 원소가 들어 있는 가장 높은 위치
};

class Set : public Bag {
public:
	Set(int MaxSize = DefaultSize);      //생성자
	~Set();      // 소멸자
				 //Set 자료구조에 맞게 Add(), Delete() 함수 재정의
	void Add(int);
	int *Delete(int&);
	friend ostream& operator<< (ostream& stream, Set s);
};