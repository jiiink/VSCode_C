// 10장-1 STACK1.H   10.2 macro로 genericity를 표현
// generic 객체들로 구성된 class Stack에 대한 객체는 전처리기에 의해 TYPE이 macro 선언 시 작성된 내용으로 치환된 후 생성된다.
#define TYPE int
class Stack {
    TYPE data[50];
    int nElements;
public:
    Stack() : nElements(0) { for (int i = 0; i < 50; i++) data[i] = 0; }
    // 한 요소를 stack에 추가
    void Push(TYPE elem);
    // stack으로부터 한 요소를 얻음
    TYPE Pop();
    // stack에 있는 실제 요소의 수
    int Number();
    // stack이 비었나?
    int Empty();
};