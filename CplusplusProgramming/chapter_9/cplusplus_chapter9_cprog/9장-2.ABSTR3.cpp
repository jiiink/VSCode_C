// 9장-2.ABSTR3.CPP   9.4 추상 class
// 하나의 추상 class로부터 유도된 class로서 모든 pure virtual 함수를
// 재 정의하고 있지 않기 때문에 아직도 추상 class로 간주된다.
#include <iostream>
using namespace std;
class Printer {
public:
	Printer() { }
	virtual void Method(char* buffer) = 0;
	virtual int Dpi() = 0;
	//  ·
	//  ·
};

class LaserPrinter : public Printer {
public:
	LaserPrinter() { }
	int Dpi() {
		return 300;
	}
};

void main() {
	// class LaserPrinter는 아직도 추상 class이므로
	// 직접 사용될 수 없다, 그러나 pointer를 통해서만 사용된다.

	// 다음 두 개의 선언 중에서 첫 번째 것은 compile error를 낸다.
	// "Cannot create instance of abstract class 'LaserPrinter'"
	// 잘못되었다!!
	LaserPrinter lp1;  //Still Abstract class
	// 올바르나 아무런 의미가 없다   
	LaserPrinter* lp2;
	system("pause");
}