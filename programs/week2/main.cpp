#include <iostream>
#include <iomanip>
#define pi 3.14159

class Pool {
private:
	double radius;
public:
	Pool(double r = 0) { radius = r; };
	~Pool() {};
	double fence_cost() { return 35 * 2 * pi * (radius + 3); }
	double concrete_cost() { return 20 * pi * ((radius + 3) * (radius + 3) - radius * radius); }
};

int main() {
	double r;
	std::cout << "Enter the radius of the pool:";
	std::cin >> r;
	Pool pool(r);
	std::cout << std::fixed << std::setprecision(0) << r << std::endl;
	std::cout << "Fencing Cost is " << std::fixed << std::setprecision(2) << pool.fence_cost() << std::endl;
	std::cout << "Concrete Cost is " << std::fixed << std::setprecision(2) << pool.concrete_cost() << std::endl;
	return 0;
}