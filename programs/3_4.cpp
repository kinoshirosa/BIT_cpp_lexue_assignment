#include <iostream>

class RMB {
private:
	int _yuan;
	int _jiao;
	int _fen;
public:
	RMB(int yuan = 0, int jiao = 0, int fen = 0);
	friend RMB operator+ (const RMB&, const RMB&);
	friend RMB operator- (const RMB&, const RMB&);
	friend bool operator> (const RMB&, const RMB&);
	friend bool operator< (const RMB&, const RMB&);
	friend bool operator== (const RMB&, const RMB&);
	friend std::ostream& operator<< (std::ostream& os, const RMB& rmb);
	void input();
};

RMB::RMB(int yuan, int jiao, int fen) {
	_yuan = yuan;
	_jiao = jiao;
	_fen = fen;
}
void RMB::input() {
	int yuan, jiao, fen;
	std::cout << "请输入元、角、分：" << std::endl;
	std::cin >> yuan >> jiao >> fen;
	_yuan = yuan;
	_jiao = jiao;
	_fen = fen;
}
RMB operator+ (const RMB& rmb1, const RMB& rmb2) {
	int result_yuan = rmb1._yuan + rmb2._yuan;
	int result_jiao = rmb1._jiao + rmb2._jiao;
	int result_fen = rmb1._fen + rmb2._fen;
	result_jiao = result_jiao + result_fen / 10;
	result_fen %= 10;
	result_yuan = result_yuan + result_jiao / 10;
	result_jiao %= 10;
	RMB result(result_yuan, result_jiao, result_fen);
	return result;
}
RMB operator- (const RMB& rmb1, const RMB& rmb2) {
	int result_yuan = 0, result_jiao = 0, result_fen = 0;
	if (rmb1 > rmb2 || rmb1 == rmb2) {
		if (rmb1._fen >= rmb2._fen) {
			result_fen = rmb1._fen - rmb2._fen;
		}
		else {
			result_fen = rmb1._fen + 10 - rmb2._fen;
			result_jiao--;
		}
		if (rmb1._jiao > rmb2._jiao || rmb1._jiao == rmb2._jiao) {
			result_jiao = result_jiao + rmb1._jiao - rmb2._jiao;
		}
		else {
			result_jiao = result_jiao + rmb1._jiao - rmb2._jiao + 10;
			result_yuan--;
		}
		result_yuan = result_yuan + rmb1._yuan - rmb2._yuan;
	}
	else {
		if (rmb2._fen >= rmb1._fen) {
			result_fen = rmb2._fen - rmb1._fen;
		}
		else {
			result_fen = rmb2._fen + 10 - rmb1._fen;
			result_jiao--;
		}
		if (rmb2._jiao > rmb1._jiao || rmb2._jiao == rmb1._jiao) {
			result_jiao = result_jiao + rmb2._jiao - rmb1._jiao;
		}
		else {
			result_jiao = result_jiao + rmb2._jiao - rmb1._jiao + 10;
			result_yuan--;
		}
		result_yuan = result_yuan + rmb2._yuan - rmb1._yuan;
		result_yuan = -result_yuan;
	}
	RMB result(result_yuan, result_jiao, result_fen);
	return result;
}
bool operator== (const RMB& rmb1, const RMB& rmb2) {
	if (rmb1._yuan == rmb2._yuan && rmb1._jiao == rmb2._jiao && rmb1._fen == rmb2._fen) {
		return true;
	}
	return false;
}
bool operator> (const RMB& rmb1, const RMB& rmb2) {
	if (rmb1._yuan > rmb2._yuan) {
		return true;
	}
	else if (rmb2._yuan > rmb1._yuan) {
		return false;
	}
	else if (rmb1._yuan == rmb2._yuan) {
		if (rmb1._jiao > rmb2._jiao) {
			return true;
		}
		else if (rmb1._jiao < rmb2._jiao) {
			return false;
		}
		else {
			if (rmb1._fen > rmb2._fen) {
				return true;
			}
			else
				return false;
		}
	}
}
bool operator< (const RMB& rmb1, const RMB& rmb2) {
	if (rmb1 == rmb2 || rmb1 > rmb2) {
		return false;
	}
	return true;
}
std::ostream& operator<< (std::ostream& os, const RMB& rmb) {
	std::cout << rmb._yuan << "元" << rmb._jiao << "角" << rmb._fen << "分";
	return os;
}

int main() {
	RMB rmb1, rmb2;
	rmb1.input();
	rmb2.input();
	std::cout << "和：" << rmb1 + rmb2 << std::endl;
	std::cout << "差：" << rmb1 - rmb2 << std::endl;
	return 0;
}
