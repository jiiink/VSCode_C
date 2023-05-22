//7장-3.BD-USE.CPP
//class BirthDate의 사용 예
//class BirthDate와 class Date의 정의를 포함한다
#include <iostream>
//#include "7장-1-1.DATE3.h"
#include "7장-1.BIRTHDAY.h"
using namespace std;
void main(){
    int m, d, y;
    struct days  dx;
	cout<<"Enter days(month, day, year): "<<endl;
    cin>>dx.month>>dx.day>>dx.year;
    Date today (dx.month, dx.day, dx.year);

    //태어난 생일을 정의하고 입력한다.
    cout << endl;
    cout << "Input your birthdate:" << endl;
    cout << "Month (number): ";
    cin >> m;
    cout << "Day: ";
    cin >> d;
    cout << "Year: ";
    cin >> y;
    BirthDate birth(m, d, y);

    //몇 가지 정보를 출력한다. 나이와 다음 생일까지의 남은 날 수
    cout << endl;
    cout << "You are " << (birth.Age (today)) << " years old"  << endl;
	birth.PrintDate();
	
    if (birth.Birthday (today))
        cout << "Today is your birthday. Congratulations!"  << endl;
  	system("pause");
} 