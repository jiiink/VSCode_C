// 9-1. ABSTR2.CPP  9.4 추상 class
#include <iostream>
using namespace std;
/*
실습 1
 1)내용
  본 source code는 추상 class로부터 concrete class를 유도하는 예제이다. subclass의 주석을 해제하기 전과 해제 한 후의 실행 결과 차이를 확인하는 것이 필요하다.
 2)방법
  가. class Printer에 정의된 pure virtual 함수와 class DotMatrixPrinter에 구현된 pure virtual 함수를 살펴보고 concrete class에 대한 의미를 이해해보자.
  나. main 문에 객체들이 어떻게 정의되어있는지 살펴보고, program을 실행시켜 결과 값을 확인해보자.
*/
class Printer{
public:
    Printer (){ }
    virtual void Method (char * buffer) = 0;
    virtual int Dpi () = 0;
};

class DotMatrixPrinter : public Printer{
    int nDots;
public:
    DotMatrixPrinter (int n) :
        nDots (n)
        { }
	//*
    void Method (char * buffer){
        sprintf (buffer, "Dot matrix printer with %d pins", nDots);
    }
	//*/
    int Dpi (){
        switch (nDots){
            // 거의 임의 값
            case 8: return 150;
            case 9: return 160;
            case 24: return 300;
            default: return 100;
        }
    }
} ;

void main(){
    char description [40];
    // DotMatrix 객체의 정의
    DotMatrixPrinter dmp (24);
    dmp.Method (description);
    cout << description << endl << "DPI: " << dmp.Dpi () << endl <<endl;
    // generic printer에 대한 pointer를 정의
    Printer * pPri;
    pPri = new DotMatrixPrinter (9);
    pPri -> Method (description);
    cout << description << endl << "DPI: " << pPri -> Dpi ()<< endl <<endl;
	delete pPri;
	system("pause");
}