// 10장-13.STACK4.H 10.4.2 template argument
// 구성요소 개수가 instance를 만들 때 결정되는
// stack을 정의하기 위한 template class의 interface
template <class T, int nEl = 50> class Stack{
    T data [nEl];
    int nElements;
public:
    Stack () : nElements (0) { }
    // stack에 요소를 추가한다.
    void Push (T elem);
    // stack으로부터 한 요소를 얻는다.
    T Pop ();
    // stack에 있는 실제 요소 개수
    int Number ();
    // stack이 비어있느냐?
    int Empty ();
    // stack이 차있느냐?
    int Full ();
} ;