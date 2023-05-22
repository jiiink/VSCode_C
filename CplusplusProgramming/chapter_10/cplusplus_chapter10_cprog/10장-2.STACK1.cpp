// 10장-2.STACK1.CPP  10.2 macro로 genericity를 표현
#include "10장-1.STACK1.h"
void Stack :: Push (TYPE elem){
    data [nElements] = elem;
    nElements ++;
}

TYPE Stack :: Pop (){
    nElements --;
    return data [nElements];
}

int Stack :: Number (){
    return nElements;
}

int Stack :: Empty (){
    return (nElements == 0);
} 