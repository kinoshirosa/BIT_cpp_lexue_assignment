#include <iostream>
#include <iomanip>

const int num_len = 16;

class Quat {
private:
	char num[num_len];
	char sign;
	void num_set0();
public:
	Quat(int num = 0);
	~Quat() {};

	Quat operator+ (Quat quat2);
};

int main() {
	return 0;
}

Quat::Quat(int num) {
	int i;
	num_set0();
	if (num == 0) {
		return;
	}
	if (num > 0) {
		sign = '+';
		for (i = 0; i < num_len && num != 0; i++) {
			num[i] = '0' + num % 10;
			num /= 10;
		}
	}
	if (num < 0) {
		sign = '-';
		num = -num;
		for (i = 0; i < num_len && num != 0; i++) {
			num[i] = '0' + num % 10;
			num /= 10;
		}
	}
}
void Quat::num_set0() {
	for (int i = 0; i < num_len; i++) {
		num[i] = 0;
	}
}

Quat Quat::operator+ (Quat quat2) {

}
