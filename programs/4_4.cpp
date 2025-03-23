#include <iostream>
#include <string>

class Book {
private:
	int _num;
	std::string _book_name;
	std::string _book_concern;
	double _price;
public:
	void set(int num, std::string book_name, std::string book_concern, double price) {
		_num = num;
		_book_name = book_name;
		_book_concern = book_concern;
		_price = price;
	}
	void disp() {
		std::cout << "Num:" << _num << std::endl;
		std::cout << "BookName:" << _book_name << std::endl;
		std::cout << "BookConcern:" << _book_concern << std::endl;
		std::cout << "Price:" << _price << std::endl;
	}
	void input() {
		int num;
		std::string book_name;
		std::string book_concern;
		double price;
		std::cin >> num >> book_name >> book_concern >> price;
		set(num, book_name, book_concern, price);
	}
};
class Author {
private:
	std::string _author_name;
	int _author_age;
	int _year;
	int _month;
	int _day;
public:
	void set(std::string author_name, int author_age, int year, int month, int day) {
		_author_name = author_name;
		_author_age = author_age;
		_year = year;
		_month = month;
		_day = day;
	}
	void disp() {
		std::cout << "AuthorName:" << _author_name << std::endl;
		std::cout << "AuthorAge:" << _author_age << std::endl;
		std::cout << "PrintTime:" << _year << '-' << _month << '-' << _day << std::endl;
	}
	void input() {
		std::string author_name;
		int author_age;
		int year, month, day;
		std::cin >> author_name >> author_age >> year >> month >> day;
		set(author_name, author_age, year, month, day);
	}
};
class Card :
	public Book,
	public Author {
private:
	std::string _sys_name;
public:
	void set(std::string sys_name,
		int num, std::string book_name, std::string book_concern, double price,
		std::string author_name, int author_age, int year, int month, int day) {
		_sys_name = sys_name;
		Book::set(num, book_name, book_concern, price);
		Author::set(author_name, author_age, year, month, day);
		_sys_name = sys_name;
	}
	void disp() {
		std::cout << "SysName:" << _sys_name << std::endl;
		Book::disp();
		Author::disp();
	}
	void input() {
		std::string sys_name;
		int num;
		std::string book_name;
		std::string book_concern;
		double price;
		std::string author_name;
		int author_age, year, month, day;
		std::cin >> sys_name;
		_sys_name = sys_name;
		Book::input();
		Author::input();
	}
};

int main() {
	Card card1;
	card1.input();
	card1.disp();
	return 0;
}