#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
const int name_len = 30;
const int grade_len = 100;
const int stu_len = 100;
const char over_name[3] = {'n', 'o', '\0'};

class Student {
private:
	char* _pname;
	double _credit[grade_len];
	double _score[grade_len];
	int grade_number;

	void _pname_setNULL();
	void _credit_set0();
	void _score_set0();
public:
	Student();
	Student(char* pname);
	~Student();

	bool set_name();
	bool set_name(char*);
	void _pname_set0();
	void add_grade(double credit, double score);
	void input_grade();
	double average() const;
	void grade_set0();
	char* name();
	double* credits();
	double* scores();

};

int main() {
	Student stu;
	while (stu.set_name()) {
		if (!(strcmp(stu.name(), over_name)))
			break;
		stu.input_grade();
		std::cout << stu.average() << std::endl;

	}
	return 0;
}

/*
*	METHODS OF STUDENT
* ----------------------
*/
Student::Student() {
	_pname = new char[name_len];
	_pname_set0();
	grade_set0();
}
Student::Student(char* pname) {
	_pname = new char[name_len];
	_pname_set0();
	strcpy(_pname, pname);
	grade_set0();
}
Student::~Student() {
	delete[] _pname;
}

void Student::_pname_set0() {
	int i = 0;
	for (; i < name_len; i++) {
		_pname[i] = '\0';
	}
}
void Student::_pname_setNULL() {
	_pname = nullptr;
}
void Student::_credit_set0() {
	int i = 0;
	for (; i < grade_len; i++) {
		_credit[i] = 0;
	}
}
void Student::_score_set0() {
	int i = 0;
	for (; i < grade_len; i++) {
		_score[i] = 0;
	}
}
void Student::grade_set0() {
	_credit_set0();
	_score_set0();
	grade_number = 0;
}

bool Student::set_name() {
	char* pname = new char[name_len];
	bool result;
	std::cin >> pname;
	strcpy(_pname, pname);
	if (_pname != nullptr) {
		result = !strcmp(pname, _pname);
		delete[] pname;
		return result;
	}
	return false;
}
bool Student::set_name(char* pname) {
	strcpy(_pname, _pname);
	if (_pname != nullptr)
		return !(strcmp(_pname, pname));
	return false;
}
void Student::add_grade(double credit, double score) {
	_credit[grade_number] = credit;
	_score[grade_number++] = score;
}
void Student::input_grade() {
	double credit, score;
	while (std::cin >> credit) {
		if (credit == -1) {
			return;
		}
		if (grade_number == grade_len) {
			std::cout << "[ERROR]@input_grade() too many input parameters" << std::endl;
		}
		std::cin >> score;
		add_grade(credit, score);
	}
}
double Student::average() const {
	int i;
	double total_grade = 0, total_credit = 0;
	double average_grade;
	for (i = 0; i < grade_len && _credit[i] != -1; i++) {
		total_credit = total_credit + _credit[i];
		total_grade = total_grade + _credit[i] * _score[i];
	}
	average_grade = total_grade / total_credit;
	return average_grade;
}

char* Student::name() { return _pname; }
double* Student::credits() { return _credit; }
double* Student::scores() { return _score; }
