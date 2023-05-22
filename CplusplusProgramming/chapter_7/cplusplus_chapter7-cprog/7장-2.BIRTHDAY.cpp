//7장-2.BIRTHDAY,cpp
//class BirthDate의 member함수 정의.
#include <iostream>
//#include <stdio.h>
using namespace std;
#include "7장-1.BIRTHDAY.h"
int Date :: LeapYear (){
    if ( year % 4 != 0) return 0;
    else 
        if ( year % 100 != 0 ) return 1;
        else if ( year % 400 != 0 ) return 0;
        else return 1;
}
int Date :: DaysInMonth (){
        switch (month) {
        case 2:
            if ( LeapYear () ) return 29;
            else return 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
		}
}
void Date :: IncreaseDate (){
    if ( day < DaysInMonth () )
        day ++;
    else 
        day = 1;
    if ( month != 12 ) month ++;
    else 
         month = 1;
         year ++;
}
void Date :: PrintDate (){
    cout << endl << "Date : " << month << "/" << day << "/"<< year;

}
void Date :: PrintLeap (){
    cout << endl << "Year " << year;
    if ( LeapYear() ) cout << " is a leap-year";
    else cout << " is not a leap-year";
}
int BirthDate :: Age (Date d){
    Date birthday (Month (), Day (), d.Year ()); 
    /*
    int newday = day;
    int newmonth = month;
    */
    int years = (d.Year () - Year ()); //현재의 생일로부터 d까지의 년 수
               //생일이 날짜 d 이후면, 나이는 두 날짜 간의 연도 차이보다 작다day
    if (birthday > d)
        years --;
    return years;
}

int BirthDate :: Birthday (Date d){
    //두 날짜와 달이 일치하면 생일이다.
    return ( (d.Day () == Day ())&& (d.Month () == Month ()) );
}

int BirthDate :: DaysToBirthday (Date d){
    int days = 0;
    //생일에 도달할 때까지 하루를 계속 더하여 생일까지 몇일 남았는지를 계산한다.
    while (!Birthday (d)){
        days ++;
        d.IncreaseDate ();
    }
	cout<<"days = "<<days;
    return days;
}
int Date :: operator > (Date d){
 	if (Year() == d.Year()) if (Month() == d.Month()) return Day() > d.Day();
							else return Month() > d.Month( );
	else return Year() > d.Year();
}