#include <iostream>
int main() {
	int hour;
	int sales;
	int total_sales;
	std::cin >> hour >> total_sales >> sales;
	std::cout << "Tom���¹���8000" << std::endl;
	std::cout << "John���¹���" << 100 * hour << std::endl;
	std::cout << "Antony���¹���" << 5000 + total_sales / 200 << std::endl;
	std::cout << "Jane���¹���" << sales / 25 << std::endl;
	return 0;
}