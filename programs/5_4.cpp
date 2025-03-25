#include <iostream>
#include <string>
std::string default_name = "default_name";
std::string default_gender = "default_gender";

class Professor {
private:
	std::string _name;
	std::string _gender; // 0 is female and 1 is male
	unsigned int _id;
	unsigned int _hour;
public:
	Professor(std::string name = default_name, std::string gender = default_gender, unsigned int id = 0, unsigned int hour = 0) :
		_name(name), _gender(gender), _id(id), _hour(hour) {}
	void set_name(std::string name) { _name = name; }
	void set_gender(std::string gender) { _gender = gender; }
	void set_id(unsigned int id) { _id = id; }
	void set_hour(unsigned int hour) { _hour = hour; }
	unsigned int get_hour() { return _hour; }
	void input() {
		std::string name;
		std::string gender;
		unsigned int id;
		unsigned int hour;
		std::cin >> name >> gender >> id >> hour;
		_name = name;
		_gender = gender;
		_id = id;
		_hour = hour;
	}
	void disp() {
		std::cout << "姓名：" << _name << std::endl;
		std::cout << "性别：" << _gender << std::endl;
		std::cout << "工号：" << _id << std::endl;
		std::cout << "课时数：" << _hour << std::endl;
	}
	virtual int pay() = 0;
};
class FullProfessor :
	public Professor {
private:
	int basic_salary;
	int class_appliance;
public:
	FullProfessor(std::string name = default_name, std::string gender = default_gender,
		unsigned int id = 0, unsigned int hour = 0,
		int bs = 2e4, int ca = 50) :
		Professor(name, gender, id, hour), basic_salary(bs), class_appliance(ca) {}
	int pay() {
		return basic_salary + class_appliance * Professor::get_hour();
	}
	void disp() {
		std::cout << "职称：教授" << std::endl;
		Professor::disp();
		std::cout << "本月工资：" << pay() << std::endl;
	}
};
class AssistantProfessor :
	public Professor {
private:
	int basic_salary;
	int class_appliance;
public:
	AssistantProfessor(std::string name = default_name, std::string gender = default_gender,
		unsigned int id = 0, unsigned int hour = 0,
		int bs = 1.5e4, int ca = 30) :
		Professor(name, gender, id, hour), basic_salary(bs), class_appliance(ca) {
	}
	int pay() {
		return basic_salary + class_appliance * Professor::get_hour();
	}
	void disp() {
		std::cout << "职称：副教授" << std::endl;
		Professor::disp();
		std::cout << "本月工资：" << pay() << std::endl;
	}
};
class LectureProfessor :
	public Professor {
private:
	int basic_salary;
	int class_appliance;
public:
	LectureProfessor(std::string name = default_name, std::string gender = default_gender,
		unsigned int id = 0, unsigned int hour = 0,
		int bs = 1e4, int ca = 20) :
		Professor(name, gender, id, hour), basic_salary(bs), class_appliance(ca) {
	}
	int pay() {
		return basic_salary + class_appliance * Professor::get_hour();
	}
	void disp() {
		std::cout << "职称：讲师" << std::endl;
		Professor::disp();
		std::cout << "本月工资：" << pay() << std::endl;
	}
};
int main() {
	FullProfessor fp1;
	AssistantProfessor ap1;
	LectureProfessor lp1;
	int condition;
	std::cin >> condition;
	if (condition == 1) {
		fp1.input();
		fp1.disp();
	}
	else if (condition == 2) {
		ap1.input();
		ap1.disp();
	}
	else {
		lp1.input();
		lp1.disp();
	}
	return 0;
}