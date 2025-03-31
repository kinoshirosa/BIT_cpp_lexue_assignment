#include <iostream>
using namespace std;

template <class type>
class Store;

template <class type>
class Store {
private:
	type _value;
public:
	Store<type>(type value = 0) { _value = value; }
	void putElem(type value) { _value = value; }
	type getElem(void) { return _value; }
};

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

int main() {

	int a;
	double b;
	cout << "请输入整变量a，以及浮点型变量b：" << endl;
	cin >> a >> b;

	Store<int> s1;
	Store<double> s2;
	s1.putElem(a);
	s2.putElem(b);
	cout << "s1.getElem() = " << s1.getElem() << "  " << "s2.getElem() = " << s2.getElem() << endl;

	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */