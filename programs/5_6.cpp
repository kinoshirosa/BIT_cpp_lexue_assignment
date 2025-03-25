#include <iostream>
const double PI = 3.1415926;
/* CLASS DEFINITIONS AND FUNCTION PROTOTYPES */
class Shape {
public:
	Shape() { std::cout << "Shape constructor" << std::endl; }
	virtual ~Shape() { std::cout << "Shape destructor" << std::endl; }
	virtual void calc_area() = 0;
	virtual void calc_volume() = 0;
	virtual void set_r(double r) = 0;
	virtual void set_a(double a) = 0;
	virtual void set_b(double b) = 0;
	virtual void set_c(double c) = 0;
	virtual void input() = 0;
	virtual void print_value() = 0;
};
class Circle :
	public Shape {
private:
	double _r;
	double _s;
public:
	Circle(double r = 0, double s = 0);
	~Circle();
	void calc_area();
	virtual void calc_volume() {};
	void set_r(double r = 0);
	virtual void set_a(double a) {};
	virtual void set_b(double b) {};
	virtual void set_c(double c) {};
	void input();
	void print_value();
};
class Rectangle :
	public Shape {
private:
	double _a;
	double _b;
	double _s;
public:
	Rectangle(double a = 0, double b = 0);
	~Rectangle();
	void calc_area();
	virtual void calc_volume() {};
	virtual void set_r(double r) {};
	void set_a(double a);
	void set_b(double b);
	void set_c(double c) {};
	void input();
	void print_value();
};
class Cuboid :
	public Shape {
private:
	double _a;
	double _b;
	double _c;
	double _s;
public:
	Cuboid(double a = 0, double b = 0, double c = 0);
	~Cuboid();
	virtual void calc_area() {}
	void calc_volume();
	virtual void set_r(double r) {}
	void set_a(double a);
	void set_b(double b);
	void set_c(double c);
	void input();
	void print_value();
};
/* MAIN FUNCTION */
int main() {
	int condition;
	Shape* pshape;
	std::cin >> condition;
	if (condition == 1) {
		pshape = new Circle;
		pshape->input();
		pshape->print_value();
		delete pshape;
	}
	else if (condition == 2) {
		pshape = new Rectangle;
		pshape->input();
		pshape->print_value();
		delete pshape;
	}
	else if (condition == 3) {
		pshape = new Cuboid;
		pshape->input();
		pshape->print_value();
		delete pshape;
	}
	return 0;
}
/* FUNCTION DEFINITIONS */
Circle::Circle(double r, double s) {
	std::cout << "Circle constructor" << std::endl;
	_r = r;
	_s = s;
	calc_area();
}
Circle::~Circle() { std::cout << "Circle destructor" << std::endl; }
void Circle::calc_area() {
	_s = PI * _r * _r;
}
void Circle::set_r(double r) {
	_r = r;
	calc_area();
}
void Circle::input() {
	double r;
	std::cin >> r;
	_r = r;
	calc_area();
}
void Circle::print_value() {
	std::cout << "Circle" << std::endl;
	std::cout << "r=" << _r << std::endl;
	std::cout << "s=" << _s << std::endl;
}
Rectangle::Rectangle(double a, double b) {
	std::cout << "Rectangle constructor" << std::endl;
	_a = a;
	_b = b;
	calc_area();
}
Rectangle::~Rectangle() { std::cout << "Rectangle destructor" << std::endl; }
void Rectangle::calc_area() {
	_s = _a * _b;
}
void Rectangle::set_a(double a) { _a = a; }
void Rectangle::set_b(double b) { _b = b; }
void Rectangle::input() {
	double a, b;
	std::cin >> a >> b;
	_a = a, _b = b;
	calc_area();
}
void Rectangle::print_value() {
	std::cout << "Rectangle" << std::endl;
	std::cout << "a=" << _a << std::endl;
	std::cout << "b=" << _b << std::endl;
	std::cout << "s=" << _s << std::endl;
}
Cuboid::Cuboid(double a, double b, double c) {
	std::cout << "Cuboid constructor" << std::endl;
	_a = a; _b = b; _c = c;
	calc_volume();
}
Cuboid::~Cuboid() { std::cout << "Cuboid destructor" << std::endl; }
void Cuboid::calc_volume() {
	_s = _a * _b * _c;
}
void Cuboid::set_a(double a) { _a = a; }
void Cuboid::set_b(double b) { _b = b; }
void Cuboid::set_c(double c) { _c = c; }
void Cuboid::input() {
	double a, b, c;
	std::cin >> a >> b >> c;
	set_a(a); set_b(b); set_c(c);
	calc_volume();
}
void Cuboid::print_value() {
	std::cout << "Cuboid" << std::endl;
	std::cout << "a=" << _a << std::endl;
	std::cout << "b=" << _b << std::endl;
	std::cout << "c=" << _c << std::endl;
	std::cout << "v=" << _s << std::endl;
}