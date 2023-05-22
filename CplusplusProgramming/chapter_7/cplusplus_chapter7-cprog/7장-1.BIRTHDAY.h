//7장-1.BIRTHDAY.h 
#include "7장-1-1.DATE3.h" 

class BirthDate : public Date{
    //새로운 private 데이터들은 이곳에서 선언될 수 있다
public:
    BirthDate (int m, int d, int y) :
    Date (m, d, y){}

    //현재 생일로부터 날짜 d 까지의 사람 나이를 return 한다
    //(즉, 현재로부터 태어난 해까지의 년 수)
    int Age (Date d);

    //d가 그 사람의 생일이라면 1(TRUE)을 return한다.
    int Birthday (Date d);

    // 날짜 d로부터 다음 생일까지의 날짜 수를 return 한다
    int DaysToBirthday (Date d);
};