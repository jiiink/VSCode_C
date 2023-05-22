// 8-4.BAG_SET.CPP  8.9 상속과 virtual을 사용한 container class의 정의
//[Howowitz, Sahni, Mehta, 2007]
#include <iostream>
#include "bagset.h"
using namespace std;
/*
실습예제 8.4
1) 내용
본 source code는 << overloading을 통하여 cout<<b(객체 출력)에 대해 알아보는 내용이다.
2) 방법
가. 중복을 허용하는 class Bag의 add 함수와 중복을 허용하지 않는 class Set의 add함수의 code를 확인하여 둘의 차이를 확인해보자.
나. program을 실행하여 왜 오류가 나는지를 생각해보고, 주석 1을 해제하여 << overloading을 한 경우와 하지 않은 경우의 차이를 확인해보자.
*/
Bag::Bag (int MaxBagSize): MaxSize (MaxBagSize){
    arr = new int[MaxSize];
    top = 0;
}

Bag::~Bag(){
}

bool Bag::IsFull(){
    if (top == MaxSize-1)
        return true;
    else
        return false;
}

bool Bag::IsEmpty(){
    if (top == 0)
        return true;
    else
        return false;
}

void Bag::Full(){
    cout<<"Data structure is full"<<endl;
}

void Bag::Empty(){
    cout<<"Data structure is empty"<<endl;
}

void Bag::Add(int x){
    //가득 찼는지 안 찼는지를 Full() member 함수를 사용 배열 끝에 삽입
    if( IsFull())
        Full(); 
    else{
        arr[top] = x;
        cout<<"BAG에 "<<arr[top]<<"이 추가되었습니다"<<endl;
        top++;
    }
}

int* Bag::Delete(int& x){
    //비었는지, 안 비었는지를 Empty() member 함수를 사용
    //비었으면 0을 리턴

    //임의의 원소를 삭제, 임의 원소 선정은 구현 algorithm에 따라 다르다
    if( IsEmpty()){
          Empty();
          return 0;
    }
    int deletePos = top/2; 
    x = arr[deletePos];
    for ( int index = deletePos; index<top; index++)
        arr[index] = arr[index+1]; 
    top--;
    return &x; 
}

int Bag::Top(){
    return top;
}
//주석 1
//
ostream& operator<<(ostream& stream, Bag b){
	cout << "ostream& operator<<(ostream& stream, Bag b) " << endl;
    for(int i=0; i<b.Top(); i++){
        stream<<b.arr[i]<<endl;
    }
    return stream;
}
//

Set::Set (int MaxBagSize): Bag(MaxBagSize){}

Set::~Set(){
}

void Set::Add(int x){
    //Bag::Add()를 재사용하여 coding하는 실습
    if(IsFull())
        Full(); 
    else{
        for(int i=0; i<MaxSize; i++){
            if(arr[i] != x){
                arr[top] = x;
                cout<<"SET에 "<<arr[top]<<"이 추가되었습니다"<<endl;
                top++;
                return;
            }
            else{
                cout<<"중복된 값 입니다"<<endl;
                return;
            }
        }
    }
}

int* Set::Delete(int& x){
    if( IsEmpty()){
          Empty();
          return 0;
    }
    int deletePos = top/2; 
    x = arr[deletePos];
    for ( int index = deletePos; index<top; index++)
        arr[index] = arr[index+1]; 
    top--;
    return &x; 
}
//주석 1
//
ostream& operator<<(ostream& stream, Set s){
	cout << "ostream& operator<<(ostream& stream, Set s) " << endl;
	Bag b = (Bag)s;
	stream << b;//code reuse 19.5.23
	/*
    for(int i=0; i<s.Top(); i++){
        stream<<s.arr[i]<<endl;
    }
	*/
    return stream;
}
//

void main(){
    int x; 

    Bag b;
    b.Add(20);
    b.Add(30);
    b.Add(40);
    b.Add(50);
    cout<<endl<<"ADD 후 객체 b 출력"<<endl;
    cout<<b<<endl;
    b.Delete(x);
    cout<<"DELETE 후 객체 b 출력"<<endl;
    cout<<b<<endl;

    Set s;
    s.Add(20);
    s.Add(20);//check the duplicate
    s.Add(30);
    cout<<endl<<"ADD 후 객체 s 출력"<<endl;
    cout<<s<<endl;
    s.Delete(x);
    cout<<"DELETE 후 객체 s 출력"<<endl;
	cout<<s<<endl;
	system("pause");
}