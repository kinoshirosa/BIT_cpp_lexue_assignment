#include <iostream>

char default_char[9] = "non name";
const int len = 30;

class Client {
private:
	char* _pname;
	int _age;
public:
	Client(char* pname = default_char, int age = 0);
	~Client();
	void disp();
	int age() { return _age; }
};

int main() {
	static char ch[30];
	char* p = ch;
	int a;
	std::cin >> ch >> a;
	Client client1(ch, a);
	client1.disp();
	return 0;
}

Client::Client(char* pname, int age) {
	_pname = new char[len];
	for (int i = 0; (i < len); i++) {
		_pname[i] = pname[i];
	}
	_age = age;
}

Client::~Client() {
	delete[] _pname;
}

void Client::disp() {
	int j = 0;
	std::cout << "Name:";
	for (; _pname[j] != '\0'; j++) {
		std::cout << _pname[j];
	}
	std::cout << '\n';
	std::cout << "Age:" << _age << std::endl;
}