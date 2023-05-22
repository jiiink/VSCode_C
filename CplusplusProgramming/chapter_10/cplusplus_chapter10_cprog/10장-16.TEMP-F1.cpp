// 10장-16.TEMP-F1.CPP  10.5 template 함수
// template 함수의 선언과 사용 예
#include <iostream>
using namespace std;
template <class T> 
T min (T ele1, T ele2){
    if (ele1 < ele2)
        return ele1;
    else
        return ele2;
}

void main (){
    char c1 = 'W', c2 = 'h';
    int num1 = 23, num2 = 67;
    cout << "min(<char>, <char>) = " << min (c1, c2) << endl ;
    cout << "min(<int>, <int>) = " << min (num1, num2) << endl ;
	system("pause");
}