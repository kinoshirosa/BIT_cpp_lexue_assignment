#include <iostream>

class Building {
private:
	int _floor;
	int _room;
	double _area;
public:
	Building(int f = 0, int r = 0, double s = 0) {
		_floor = f;
		_room = r;
		_area = s;
	}
	void set(int f, int r, double s) {
		_floor = f;
		_room = r;
		_area = s;
	}
	void disp() {
		std::cout << "floor:" << _floor << std::endl;
		std::cout << "room:" << _room << std::endl;
		std::cout << "area:" << _area << std::endl;
	}
};
class House :
	public Building {
private:
	int _bedroom;
	int _bathroom;
public:
	House(int f = 0, int r = 0, double s = 0, int bedroom = 0, int bathroom = 0);
	House(Building building, int bedroom, int bathroom);
	void disp();
	void input();
};
class Office :
	public Building {
private:
	int _table;
	int _phone;
public:
	Office(int f = 0, int r = 0, double s = 0, int table = 0, int phone = 0);
	Office(Building building, int table = 0, int phone = 0);
	void disp();
	void input();
};

House::House(int f, int r, double s, int bedroom, int bathroom) :
	Building(f, r, s) {
	_bedroom = bedroom;
	_bathroom = bathroom;
}
House::House(Building building, int bedroom, int bathroom) : Building(building) {
	_bedroom = bedroom;
	_bathroom = bathroom;
}
void House::disp() {
	std::cout << "house_information" << std::endl;
	Building::disp();
	std::cout << "Bedrooms:" << _bedroom << std::endl;
	std::cout << "Bathrooms:" << _bathroom << std::endl;
}
void House::input() {
	int f, r, bedroom, bathroom; double s;
	std::cin >> f >> r >> s >> bedroom >> bathroom;
	Building::set(f, r, s);
	_bedroom = bedroom;
	_bathroom = bathroom;
}

Office::Office(int f, int r, double s, int table, int phone) : Building(f, r, s) {
	_table = table;
	_phone = phone;
}
Office::Office(Building building, int table, int phone) :Building(building) {
	_table = table;
	_phone = phone;
}
void Office::disp() {
	std::cout << "office_information" << std::endl;
	Building::disp();
	std::cout << "tables:" << _table << std::endl;
	std::cout << "Phones:" << _phone << std::endl;
}
void Office::input() {
	int f, r, bedroom, bathroom; double s;
	std::cin >> f >> r >> s >> bedroom >> bathroom;
	Building::set(f, r, s);
	_table = bedroom;
	_phone = bathroom;
}

int main() {
	House house;
	Office office;
	house.input();
	office.input();
	house.disp();
	office.disp();
	return 0;
}