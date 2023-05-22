// 8-3.PUREVIRTUAL.CPP    8.6 virtual 함수와 동적 binding의 사용 예
/*
실습예제 8.3
1)내용
 본 source code는 정적 binding과 동적 binding 사이의 차이를 이해하는 것이다.
2)방법
 가) 주석 1번을 해제하고 오류를 확인해보자.
 나) class Polygon의 Perimeter 함수를 class Rectangle에서 재정의하고 호출하여 실행 결과를 확인해보자.
 다) 주석 2번을 해제하고 pure virtual 함수가 모두 정의되었을 때와 그렇지 않을 때를 비교해보자.
 라) 오류를 주석 처리하고 출력 결과를 통해서 어느 class의 함수가 호출되는지 확인보자.
 마) 주석 3번을 해제하여 출력 결과를 통해서 함수가 호출되는 class를 다시 한번 확인해보자.
*/
#include <iostream>
using namespace std;
class Polygon{
public:
    int Creator(); // non-virtual(non-virtual) member 함수
    virtual void Moves(int delta_x, int delta_y); // virtual(virtual) member 함수    
    virtual int Perimeter()=0; // pure virtual(virtual) member 함수
    virtual int Color()=0; // pure virtual(virtual) member 함수

protected:
    int creator;
    int x_pos, y_pos;
};
//Creator()는 유도된 class에서 재정의 하지 않는다.
int Polygon::Creator(){
    cout << "Polygon의 Creator() : " << creator << endl;
    return creator;
}
//Polygon의 member 함수 Moves()는 다음과 같이 구현된다.
void Polygon::Moves(int delta_x, int delta_y){
    cout << "Polygon의 Moves()" << endl;
    cout << "실행 전 x_pos : " << x_pos << "  y_pos : " << y_pos << endl;
    x_pos += delta_x;
    y_pos += delta_y;
    cout << "실행 후 x_pos : " << x_pos << "  y_pos : " << y_pos << endl;
}
//class Rectangle : protected Polygon { //assign 동작하지 않음
class Rectangle : public Polygon{
public:
    ///* 주석 2
    int Perimeter(){//Rectangle에서 정의됨
        cout << "Rectangle의 Perimeter() : " << 2*(height+base) << endl;
        return 2*(height+base);
    }//*/
    int Color(){//Rectangle에서 정의됨
        cout << "Rectangle의 Color() : " << color << endl;
        return color;
    }
    int Base(){
        cout << "Rectangle의 Base() : " << base << endl;
        return base;
    }
    int Height(){
        cout << "Rectangle의 Height() : " << height << endl;
        return height;
    }
private:       // Rectangle에서 추가된 데이터 member들
    int base, height;
    int color;
};

class Square : public Rectangle {
public:
    ///* 주석 3
    int Perimeter(){
        cout << "Square의 Perimeter() : " << "0" << endl;
        return 0;
    }
    int Color(){
        cout << "Square의 Color() : " << color << endl;
        return color;
    }
    int Color(int c){

        color = c;
        cout << "Square의 Colorl(int c) : " << color << endl;
        return color;
    }//*/
	void Moves(int delta_x, int delta_y) {
		cout << "Square:: Moves() is called" << endl;
		Polygon::Moves(delta_x, delta_y);
	}
private:
    int color;
};

void main(){
    /*객체 생성시 error가 발생할 경우 pure virtual 함수와 연관지어서 생각해보자*/
    ///* 주석1
    //Polygon p1; //error!!
    //error!! 추상 class는 객체를 생성할 수 없음
    //Polygon *p1 = new Polygon(); 

    //Polygon의 pure virtual 함수를 모두 재정의하면 객체로 선언 가능하나 모두     //재정의하지 않으면 추상 class로 처리된다.
    Polygon *p2 = new Rectangle(); 
    cout << endl << "------ Polygon *p2 = new Rectangle() ------" << endl;
    p2->Creator();
    p2->Perimeter();
    p2->Color();
    p2->Moves(1, 2);
    //*/
    Polygon *p3 = new Square();
    cout << endl << "------ Polygon *p3 = new Square() ------"  << endl;
    p3->Creator();
    p3->Perimeter();
    p3->Color();
    //p3->Color(10);
    p3->Moves(10, 20);	
    //Polygon의 pure virtual 함수를 모두 재정의 하면 객체로 선언 가능	
    Rectangle *r1 = new Rectangle(); 
    cout << endl << "------ Rectangle *r1 = new Rectangle() ------" << endl;
    r1->Creator();
    r1->Perimeter();
    r1->Color();
    //r1->Color(10); 
    r1->Moves(10, 20);
    r1->Base();
    r1->Height();

    Rectangle *r2 = new Square();
    cout << endl << "------ Rectangle *r2 = new Square() ------" << endl;
    r2->Creator();
    r2->Perimeter();
    r2->Color();
    //r2->Color(10); 
    r2->Moves(10, 20);
    r2->Base();
    r2->Height();

    Square *s = new Square();
    cout << endl << "------ Square *s = new Square() ------" << endl;
    s->Creator();
    s->Perimeter();
    s->Color(); 
    s->Color(20);
    s->Moves(20, 30);
    s->Base();
    s->Height();
    system("pause");
}