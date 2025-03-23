#include <iostream>

int main() {
	static char name[100];
	bool sex;
	int age;
	unsigned int salary;
	int leaving_day;
	std::cin >> name >> sex >> age >> salary >> leaving_day;
	std::cout << "name:" << name << std::endl;
	std::cout << "age:" << age << std::endl;
	if (sex) {
		std::cout << "sex:" << "ÄÐ" << std::endl;
	}
	else {
		std::cout << "sex:" << "Å®" << std::endl;
	}
	std::cout << "basicSalary:" << salary << std::endl;
	std::cout << "leavedays:" << leaving_day << std::endl;
	return 0;
}