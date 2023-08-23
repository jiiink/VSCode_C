// 10장-12.TYPE-ERR.CPP   10.4.1 타입 호환성 문제
// 타입 parameter에서의 error가 혼동을 주는 error 메시지를 어떻게 만드는 지를 보여주는 예제
// 순서 관련성을 정의하는 class로서 앞의 예제와 유사한 class를 정의한다.
#include <iostream>
using namespace std;
template <class T>
class OrdSingle{
    T data;
public:
    OrdSingle (int i = 0):data(i)  { }
    void Set (T el){
        data = el;
    }

    T Get (){
        return data;
    }

    bool operator > (int value){
		cout<<"OrdSingle::operator >() is called"<<endl;
        return (data > value);
    }
} ;
// 숫자 class를 정의한다.
class Number{
public:
    int num;
	Number(int a): num(a) {}
    //*
	bool operator > (int k) {//주석 처리시에 오류가 나는 code를 확인하는 실습 필요
		cout<<"Number::operator >() is called"<<endl;
		return (num > k);
    }
    //*/
};
int main (){
    // 두 개의 객체들을 만든다.
    OrdSingle <int> os1;
	Number n1(4);
    OrdSingle <Number> os2;
	os1.Set(10); 
	//Number n1(4);
	os2.Set(n1);
    if(os1 > 5)
        printf("\t os2 = %d\n",os1);
    if(os2 > 5)
        printf("\tos2 = %d\n",os2);

	system("pause");
    return 0;
}