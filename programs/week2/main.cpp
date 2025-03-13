#include <iostream>

class Counter {
private:
	int number;
public:
	Counter(int n = 0) { number = n; }
	~Counter() {}
	void countup(int n = 1) { number += n; }
	friend std::ostream& operator<< (std::ostream& os, Counter ct);
	void operator++(int n);
	int show_number() { return number; }
};

std::ostream& operator<< (std::ostream& os, Counter ct) {
	std::cout << ct.number;
	return os;
}

void Counter::operator++(int) {
		this->number++;
}

int main() {
	char ch;
	Counter ct;
	while (ch = std::cin.get()) {
		if (ch == ' ') {
			ct++;
		}
		if (ch == '\n') {
			if (ct.show_number() != 0) {
				ct++;
			}
			break;
		}
	}
	std::cout << "Word=" << ct.show_number() << std::endl;
	return 0;
}