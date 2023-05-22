//9-2.ABSTR3.CPP   9.4 추상 class
#include <iostream>
using namespace std;
/*
실습 2
 1)내용
  본 source code는 추상 class를 상속하고 동일한 member 변수를 추가로 선언할 때 어떤 문제가 있는지 확인하는 것이다.

 2)방법
  가. program을 실행하여 보고, error가 난다면 error 이유를 생각해보자.
  나. LaserPrinter class의 주석 1을 해제하여 가)에서 error가 난 경우와 비교하여 결과의 차이를 확인해보자.
  다. FaxPrinter class의 주석 2를 살펴보고, 주석이 되어있는 상태에서 fp->Method("man2")를 하였을 때 어떤 class의 Method()가 호출되는지 확인해보자.
  라. 다.에서와 반대로 주석을 해제하여보고 Method() 호출 결과를 확인해보자.
*/
class Printer{
	private:
		int a;
	public:
		Printer()
		{}
		virtual void Method(char* buffer) = 0;
		virtual int Cpi() = 0;
		void D(){
			cout << "Printer_D()" << endl;
		}
};



class LaserPrinter : public Printer {
private:
	int cpi;
public:
	LaserPrinter()
	{
		cpi = 20;
		//a = 2;
	}
	//주석 1
	//*
	int Cpi() {
		cout << "LaserPrinter Cpi() : " << cpi << endl;
		return cpi;
	}
	//*/
	void Method(char* buffer) {
		cout << "LaserPrinter Method() : " << buffer << endl;
	}
	void D() {
		cout << "LaserPrinter_D()" << endl;
	}
	//virtual void Show() = 0;//still Abstract class
};

class InkJetLaser : public LaserPrinter{
	private:
		int cpi;
	public:
		InkJetLaser()
		{
			cpi = 30;
		}
		int Cpi(){
			cout<<"InkJetLaser Cpi() : "<< cpi << endl;
			return cpi;
		}
	
		void Method(char* buffer){
			cout<<"InkJetLaser Method() : "<< buffer << endl;
		}
		void D(){
			cout << "InkJetLaser_D()" << endl;
		}
		void Show() 
		{
			cout << "InkJetLaser::Show()-> cpi = " << cpi << endl;
		}
};

class FaxPrinter : public InkJetLaser{
	private:
		int cpi;
	public:
		FaxPrinter(){
			cpi = 40;
		}
		int Cpi(){
			cout<<"FaxPrinter Cpi() : "<< cpi << endl;
			return cpi;
		}
		//주석 2
		//*
		void Method(char* buffer){
			cout<<"FaxPrinter Method() : "<< buffer << endl;
		}
		//*/
};

void main(){
    //Printer *p = new Printer();

    LaserPrinter *laser = new LaserPrinter();
    laser->Cpi();
    laser->Method("woman");

    InkJetLaser *inkjet = new InkJetLaser();
    inkjet->Cpi();
    inkjet->Method("woman2");

    Printer *lp = new LaserPrinter();
    lp->Cpi();
    lp->Method("man1");

    Printer *fp = new FaxPrinter();
    fp->Cpi();
    fp->Method("man2");

    FaxPrinter *fp2 = new FaxPrinter();
    fp2->D();
	system("pause");
}