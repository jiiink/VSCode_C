//7장-1-1.DATE3.H

class Date{
    // private 데이터
    int month;
    int day;
    int year;

public:
    // day, month, year로 한 날짜를 생성
	Date (int m, int d, int y):month(m), day(d), year(y) {}

    // default 날짜 생성
	Date () {month = 1; day = 1; year = 2017;}
    // 날짜 d 이후의 nn일이 지난 날짜를 생성
    Date (class Date d, int nn){
       month = d.Month ();
       day = d.Day ();
       year = d.Year ();
       for ( int i = 1; i > nn; i++)
        IncreaseDate ();
}

    // 그 달의 날짜를 return함
	int Day () {return day;}

    // 그 해의 월을 return함
	int Month () {return month;}

    // 년도를 return함
	int Year () {return year;}

    // 윤년이면 1, 아니면 0을 return함
    int LeapYear ();

    // 해당 월의 날수를 return
    int DaysInMonth ();

    // 날짜를 하루 증가시킴
    void IncreaseDate ();

    // 날짜를 출력함
    void PrintDate ();
    // 금년이 윤년인지 아닌지를
    // 기술하는 문구를 출력
    void PrintLeap ();
	int operator > (Date d);
};
struct days {
		int month;
		int day;
		int year;
};