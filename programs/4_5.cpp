#include<iostream>  
#include<string>  
using namespace std;

class People {
protected:
	string name;
	string sex;
	int age;
public:
	People(int age_, string name_, string sex_) :age(age_), name(name_), sex(sex_) {}

	void out() {
		cout << "Name: " << name << endl;
		cout << "Sex: " << sex << endl;
		cout << "Age: " << age << endl;
	}
};

class student :virtual public People {
protected:
	int no;
	int score;
public:
	student(int no_, int score_, int age_, string name_, string sex_) :People(age_, name_, sex_) {
		no = no_;
		score = score_;
	}
	void out() {
		People::out();
		cout << "No.: " << no << endl;
		cout << "Score: " << score << endl;
	}

};

class teacher :virtual public People {
protected:
	string positation;
	string depatrment;
public:
	teacher(string po, string de, int age_, string name_, string sex_) :People(age_, name_, sex_), positation(po), depatrment(de) {}
	void out() {
		People::out();
		cout << "Position: " << positation << endl;
		cout << "Department: " << depatrment << endl;
	}
};

class GradOnWork :public student, public teacher {
	string Direction;
	string tutor;
public:
	GradOnWork(string di, string tu, int no_, int score_, int age_, string name_, string sex_, string po, string de) :People(age_, name_, sex_), student(no_, score_, age_, name_, sex_), teacher(po, de, age_, name_, sex_), Direction(di), tutor(tu) {}
	void out() {
		cout << "Name: " << name << endl;
		cout << "Sex: " << sex << endl;
		cout << "Age: " << age << endl;
		cout << "No.: " << no << endl;
		cout << "Score: " << score << endl;
		cout << "Position: " << positation << endl;
		cout << "Department: " << depatrment << endl;
		cout << "Direction: " << Direction << endl;
		cout << "Tutor: " << tutor << endl;

	}
};
int main() {
	char name[20], sex[20];
	int age, no, score;
	char job[20], Department[20], direction[20], tutor[20];
	cin >> name >> sex >> age;
	cin >> no >> score;
	cin >> job >> Department;
	cin >> direction >> tutor;
	People m1(age, name, sex);
	student m2(no, score, age, name, sex);
	teacher m3(job, Department, age, name, sex);
	GradOnWork m4(direction, tutor, no, score, age, name, sex, job, Department);
	cout << "People:" << endl;
	m1.out();
	cout << endl;

	cout << "Student:" << endl;
	m2.out();
	cout << endl;

	cout << "Teacher:" << endl;
	m3.out();
	cout << endl;

	cout << "GardOnWork:" << endl;
	m4.out();
	return 0;
}
