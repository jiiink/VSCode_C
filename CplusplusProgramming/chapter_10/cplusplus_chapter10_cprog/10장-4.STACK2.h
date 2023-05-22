// 10장-4.STACK2.H 10.3 상속과 polymorphism을 사용하여 genericity 표현
// class GenericObject 객체들의 generic stack의 interface
// stack은 50개의 pointer 배열로 이루어짐
// generic 객체들을 위한 class를 정의한다.
class GenericObject
{ } ;

class Stack{
    GenericObject * data [50];
    int nElements;
public:
    Stack () :
    nElements (0)
    { }
    // stack에 한 요소를 추가
    void Push (GenericObject * elem);
    // stack으로부터 한 요소를 얻음
    GenericObject * Pop ();
    // stack에 실제로 저장된 요소 개수
    int Number ();
    // stack이 비었나?
    int Empty ();
 };