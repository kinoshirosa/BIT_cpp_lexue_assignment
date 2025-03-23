#include <iostream>
#include <iomanip>

const double PI = 3.14159;
class Shape {
public:
	virtual double area() = 0;
};
class Circle : public Shape {
private:
	double _r;
public:
	void set(double r) { _r = r; }
	void input() {
		double r;
		std::cout << "请输入圆的半径" << std::endl;
		std::cin >> r;
		_r = r;
	}
	double area() {
		return PI * _r * _r;
	}
};
class Rect : public Shape {
private:
	double _a;
	double _b;
public:
	void set(double a, double b) {
		_a = a;
		_b = b;
	}
	void input() {
		double a, b;
		std::cout << "请输入矩形的长和宽" << std::endl;
		std::cin >> a >> b;
		_a = a;
		_b = b;
	}
	double area() {
		return _a * _b;
	}
};

int main() {
	Circle O1;
	Rect R1;
	O1.input();
	std::cout << "area of circle = " << O1.area() << std::endl;
	R1.input();
	
	std::cout << "area of rectangle = " << R1.area() << std::endl;
	return 0;
}