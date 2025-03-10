#include <iostream>

#define PI		3.14

template<class type>
class pillar {
private:
	type _height;
	type _radius;
public:
	pillar(type, type);
	~pillar() {};

	double volume();
};

template<class type>
pillar<type>::pillar(type r, type h) {
	_height = h;
	_radius = r;
}

template<class type>
double pillar<type>::volume() {
	return _height * _radius * _radius * PI;
}

int main() {
	double r, h;
	std::cin >> r >> h;
	pillar<double> V1{ r, h };
	std::cout << "v=" << V1.volume() << std::endl;
	return 0;
}