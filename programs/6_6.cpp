#include <iostream>
#include <string>

typedef enum TYPEMODE {
	NONE = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3,
	STRING = 4
}TypeMode;

template <class type>
class Count {
private:
	type* _parr;
	int _length;
public:
	Count();
	~Count();
	Count(int length);
	Count(const Count<type>& count);
	void operator= (const Count<type>& count);

	int Find(const type& find_value) const;
	void SetLength(int length);
	void InputArr();
};

int main() {
	TypeMode typemode = NONE;
	int mode;
	int length = 0;

	int intvalue;
	float floatvalue;
	double doublevalue;
	std::string stringvalue;
	std::cin >> mode;
	switch (mode) {
	case 1: 
		typemode = INT;
		break;
	case 2: 
		typemode = FLOAT;
		break;
	case 3: 
		typemode = DOUBLE;
		break;
	case 4: 
		typemode = STRING;
		break;
	default: 
		typemode = NONE;
		break;
	}
	std::cin >> length;
	if (typemode == INT) {
		Count<int> count(length);
		count.InputArr();
		std::cin >> intvalue;
		std::cout << count.Find(intvalue) << std::endl;
	}
	if (typemode == FLOAT) {
		Count<float> count(length);
		count.InputArr();
		std::cin >> floatvalue;
		std::cout << count.Find(floatvalue) << std::endl;
	}
	if (typemode == DOUBLE) {
		Count<int> count(length);
		count.InputArr();
		std::cin >> doublevalue;
		std::cout << count.Find(doublevalue) << std::endl;
	}
	if (typemode == STRING) {
		Count<std::string> count(length);
		count.InputArr();
		std::cin >> stringvalue;
		std::cout << count.Find(stringvalue) << std::endl;
	}

	return 0;
}

template <class type>
Count<type>::Count() {
	_parr = nullptr;
	_length = 0;
}

template <class type>
Count<type>::Count(int length) {
	_parr = new type[length];
	_length = length;
}

template <class type>
Count<type>::Count(const Count<type>& count) {
	_length = count._length;
	if (_length <= 0) {
		_parr = nullptr;
		return;
	}
	_parr = new type[_length];
	int i = 0;
	for (i = 0; i < _length; i++) {
		_parr[i] = count._parr[i];
	}
	return;
}

template <class type>
void Count<type>::operator= (const Count<type>& count) {
	_length = count._length;
	if (_length <= 0) {
		_parr = nullptr;
		return;
	}
	delete[] _parr;
	_parr = new type[_length];
	int i = 0;
	for (i = 0; i < _length; i++) {
		_parr[i] = count._parr[i];
	}
	return;
}

template <class type>
Count<type>::~Count() {
	delete[] _parr;
}

template <class type>
void Count<type>::SetLength(int length) {
	_length = length;
	delete[] _parr;
	_parr = new type[_length];
}

template <class type>
void Count<type>::InputArr() {
	int i = 0;
	if (_parr == nullptr) {
		return;
	}
	for (i = 0; i < _length; i++) {
		std::cin >> _parr[i];
	}
}

template <class type>
int Count<type>::Find(const type& value) const {
	int counter = 0;
	if (_parr == nullptr) {
		return 0;
	}
	for (int i = 0; i < _length; i++) {
		if (_parr[i] == value) {
			counter++;
		}
	}
	return counter;
}