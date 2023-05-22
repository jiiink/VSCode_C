//9장-1.ABSTR1.CPP   9.4 추상 class
//추상 class 정의의 예:
//생성자 호출은 compile error를 만든다.
#include <iostream>
using namespace std;
class Printer{
public:
    Printer ()
    { }
    virtual void Method (char * buffer) = 0;
    virtual int Dpi () = 0;
};
void main (){
    //만일 다음의 문장을 주석 문장으로 만들지 않으면 compiler는
    //"Cannot create instance of abstract class 'Printer'“    
    //메시지를 내보낼 것이다.
    // Printer pri; 
    //다음 정의는 올바르다
    Printer * pPri;
    //만일 다음문장이 주석 문이 아니면 compiler는 같은 error
    //메시지를 내보낼 것이다
    //pPri = new Printer ();//Abstract class
	system("pause");
}