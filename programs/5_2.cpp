#include <iostream>

class Felid {
public:
	Felid() { std::cout << "Felid constructor" << std::endl; }
	virtual ~Felid() { std::cout << "Felid destructor" << std::endl; }
	virtual void sound() = 0;
};
class Leopard :
	public Felid {
public:
	Leopard() { std::cout << "Leopard constructor" << std::endl; }
	~Leopard() { std::cout << "Leopard destructor" << std::endl; }
	virtual void sound() { std::cout << "Howl !" << std::endl; };
};
class Cat :
	public Felid {
public:
	Cat() { std::cout << "Cat constructor" << std::endl; }
	~Cat() { std::cout << "Cat destructor" << std::endl; }
	virtual void sound() { std::cout << "Miaow !" << std::endl; };
};

int main() {
	Felid* pfelid;
	pfelid = new Cat;
	pfelid->sound();
	delete pfelid;
	pfelid = new Leopard;
	pfelid->sound();
	delete pfelid;
	return 0;
}
/*
* only when the destructor is virtual can it be called when
* the descendents are deleted
* try to delete the virtual keywords before ~Felid()
* and seek for the output
*/