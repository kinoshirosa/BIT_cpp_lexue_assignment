#include <iostream>

int& select_max(int&, int&);

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	std::cout << "Maximum:" << select_max(select_max(a, b), c) << std::endl;
	return 0;
}

int& select_max(int& a, int& b) {
	return (a > b) ? a : b;
}
