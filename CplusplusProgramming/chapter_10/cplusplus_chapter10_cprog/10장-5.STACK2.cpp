// 10장-5.STACK2.CPP 10.3 상속과 polymorphism을 사용하여 genericity 표현
// generic 객체들의 stack에 대한 member 함수 정의
#include "10장-4.STACK2.h"
void Stack :: Push (GenericObject * elem){
    data [nElements] = elem;
    nElements ++;
}

GenericObject * Stack :: Pop (){
    nElements --;
    return data [nElements];
}

int Stack :: Number (){
    return nElements;
}

int Stack :: Empty (){
    return (nElements == 0);
}