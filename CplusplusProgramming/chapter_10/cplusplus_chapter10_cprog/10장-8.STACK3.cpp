// 10장-8.STACK3.CPP   10.4 template class
#include "10장-7.STACK3.h"
// template를 위한 외부 member 함수 정의의 특이한 구문에 주목한다
template <class T>
void Stack <T> :: Push (T elem){
    data [nElements] = elem;
    nElements ++;
}

template <class T>
T Stack <T> :: Pop (){
    nElements --;
    return data [nElements];
}

template <class T>
int Stack <T> :: Number (){
    return nElements;
}

template <class T>
int Stack <T> :: Empty (){
    return (nElements == 0);
}