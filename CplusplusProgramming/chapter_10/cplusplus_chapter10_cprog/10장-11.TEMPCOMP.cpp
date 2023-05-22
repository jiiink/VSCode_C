// 10장-11.TEMPCOMP.CPP   10.4.1 타입 호환성 문제
// template 호환성 규칙을 보여주는 program
// 하나의 요소만 포함하는 단순 template class의 정의
#include <iostream>
using namespace std;
template <class T> class Single{
    T data;

public:
    Single ()
    { }

    void Set (T el){
        data = el;
    }
    T Get (){
        return data;
    }
} ;

void main(){
    // 어떤 template class의 instance 타입을 정의
    Single <int> oneInt;
    oneInt.Set (5);
    Single <float> oneFloat;
    oneFloat.Set (4.9);
    Single <int> secondInt;
    secondInt.Set (8);
    // template class의 instance들 간의 치환은 타입 호환이면 가능하다
    // 올바르다
    oneInt = secondInt;
    // 틀리다
    //oneInt = oneFloat; //다른 type
	system("pause");
}