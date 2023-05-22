// 10-6.STACK3.CPP  10.4.3 template을 이용한 Container class 표현
#include "10-5.Polymorphism_Stack.h"
//template를 위한 외부 member 함수 정의시에 parameter T를 기술하는 것을 빠트리면 안된다.
template <class T>
void Stack <T>::Push(T elem){
    //if(T == int){}
    data[nElements] = elem;
    nElements++;
}

template <class T>
T Stack <T>::Pop(){
    nElements--;
    return data[nElements];
}

template <class T>
int Stack <T>::Number(){
    return nElements;
}

template <class T>
int Stack <T>::Empty(){
    return (nElements==0);
}
