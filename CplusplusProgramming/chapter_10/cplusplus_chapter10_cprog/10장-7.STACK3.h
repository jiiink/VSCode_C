// 10장-7.STACK3.H  10.4 template class
// stack을 정의하는 template class의 interface
// 예제 code는 앞에서 작성한 macro version과 상속을 이용한 version과 유사하다
template <class T>
class Stack{
    T data [50];
    int nElements;
public:
    Stack () : nElements (0)  { }
    // stack에 한 요소를 추가한다.
    void Push (T elem);
    // stack으로부터 한 요소를 얻는다.
    T Pop ();
    // stack에 저장되어 있는 요소 개수
    int Number ();
    // stack이 비어있는가?
    int Empty ();
};