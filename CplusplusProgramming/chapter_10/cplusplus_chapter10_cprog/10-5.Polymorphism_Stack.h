// 10-5.Polymorphism_Stack.h  10.4.3 template을 이용한 Container class 표현
template <class T>
class Stack{
    T data[50];
    int nElements;
public:
    Stack(): nElements(0) {}
    //stack에 한 요소를 추가한다.   
    void Push(T elem);
    //stack으로부터 한 요소를 얻는다.
    T Pop();
    //stack에 저장되어 있는 요소 개수
    int Number();
    //stack이 비어있는가?
    int Empty();
};



