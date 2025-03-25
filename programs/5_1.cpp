#include <iostream>
#include <string>

const double PI = 3.14;

class Shape {
public:
	virtual double surface_area() = 0;
	virtual double volume() = 0;
};
class Cube :
	public Shape {
private:
	double length;
public:
	Cube(double l = 0) : length(l) {}
	double surface_area() { return length * length * 6; }
	double volume() { return length * length * length; }
	void set(double l) {
		length = l;
	}
	void input() {
		double l;
		std::cin >> l;
		length = l;
	}
	void disp() {
		std::cout << "Shape：正方体" << std::endl;
		std::cout << " 面积、体积：" << surface_area() << ' ' << volume() << std::endl;
	}
};
class Sphere :
	public Shape {
private:
	double _r;
public:
	Sphere(double r = 0) : _r(r) {}
	double surface_area() { return 4 * PI * _r * _r; }
	double volume() { return 4 * PI * _r * _r * _r / 3; }
	void set(double l) {
		_r = l;
	}
	void input() {
		double l;
		std::cin >> l;
		_r = l;
	}
	void disp() {
		std::cout << "Shape：球体" << std::endl;
		std::cout << " 面积、体积：" << surface_area() << ' ' << volume() << std::endl;
	}
};
class Cylinder :
	public Shape {
private:
	double _r;
	double _h;
public:
	Cylinder(double r = 0, double h = 0) :_r(r), _h(h) {}
	double surface_area() {
		return 2 * PI * _r * _r + 2 * PI * _r * _h;
	}
	double volume() {
		return PI * _r * _r * _h;
	}
	void set(double r, double h) {
		_r = r;
		_h = h;
	}
	void input() {
		double r, h;
		std::cin >> r >> h;
		set(r, h);
	}
	void disp() {
		std::cout << "Shape：圆柱体" << std::endl;
		std::cout << " 面积、体积：" << surface_area() << ' ' << volume() << std::endl;
	}
};

int main() {
	Cube cube1;
	Sphere ball1;
	Cylinder pillar1;
	cube1.input();
	ball1.input();
	pillar1.input();
	cube1.disp();
	ball1.disp();
	pillar1.disp();

	return 0;
}