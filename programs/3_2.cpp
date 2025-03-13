#define _CRT_SECURE_NO_WARNING
#include <iostream>
#include <iomanip>

class Date {
private:
	int _year;
	int _month;
	int _day;
public:
	Date(int year = 0, int month = 0, int day = 0);
	~Date() {};

	friend void disp(Date);
	void set_date(int year = 0, int month = 0, int day = 0);
	void init_date() { set_date(); }
	void set_year(int year) { _year = year; }
	void set_month(int month) { _month = month; }
	void set_day(int day) { _day = day; }
	void input_date();
};
class Time {
private:
	int _hr;
	int _min;
	int _sec;
public:
	Time(int hr = 0, int min = 0, int sec = 0);
	~Time() {};

	friend void disp(Time);
	void set_time(int hr = 0, int min = 0, int sec = 0);
	void init_time() { set_time(); }
	void set_hour(int hr) { _hr = hr; }
	void set_minute(int min) { _min = min; }
	void set_second(int sec) { _sec = sec; }
	void input_time();
};

int main() {
	Time time1;
	Date date1;
	time1.input_time();
	date1.input_date();
	disp(time1);
	disp(date1);
	return 0;
}

/*
* --------DATE CLASS METHODS--------
*/
Date::Date(int year, int month, int day) {
	_year = year;
	_month = month;
	_day = day;
}
void Date::set_date(int year, int month, int day) {
	_year = year;
	_month = month;
	_day = day;
}
void Date::input_date() {
	int y, m, d;
	std::cout << "Please input date: ";
	std::cin >> y >> m >> d;
	set_date(y, m, d);
}
/*
* --------TIME CLASS METHODS--------
*/
Time::Time(int hr, int min, int sec) {
	_hr = hr;
	_min = min;
	_sec = sec;
}
void Time::set_time(int hr, int min, int sec) {
	_hr = hr;
	_min = min;
	_sec = sec;
}
void Time::input_time() {
	int h, m, s;
	std::cout << "Please input time: ";
	std::cin >> h >> m >> s;
	set_time(h, m, s);
}
/*
* --------DISP() OVERLOADING--------
*/
void disp(Date date) {
	std::cout << date._year << '/' << date._month << '/' << date._day << std::endl;
}
void disp(Time date) {
	std::cout << date._hr << ':' << date._min << ':' << date._sec << std::endl;
}