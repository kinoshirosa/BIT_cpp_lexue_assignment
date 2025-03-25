#include <iostream>
int main() {
	int hour;
	int sales;
	int total_sales;
	std::cin >> hour >> total_sales >> sales;
	std::cout << "Tom本月工资8000" << std::endl;
	std::cout << "John本月工资" << 100 * hour << std::endl;
	std::cout << "Antony本月工资" << 5000 + total_sales / 200 << std::endl;
	std::cout << "Jane本月工资" << sales / 25 << std::endl;
	return 0;
}