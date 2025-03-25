#include <iostream>

class CPU {
public:
	virtual void disp() { std::cout << "CPU��ʼ������" << std::endl; }
};
class GPU {
public:
	virtual void disp() { std::cout << "�Կ���ʼ��ʾ��" << std::endl; }
};
class RAM {
public:
	virtual void disp() { std::cout << "�ڴ�����ʼ�洢��" << std::endl; }
};
class intel_CPU : public CPU {
public:
	void disp() {
		std::cout << "Intel��";
		CPU::disp();
	}
};
class lenovo_CPU : public CPU {
public:
	void disp() {
		std::cout << "Lenovo��";
		CPU::disp();
	}
};
class intel_GPU : public GPU {
public:
	void disp() {
		std::cout << "Intel��";
		GPU::disp();
	}
};
class lenovo_GPU : public GPU {
public:
	void disp() {
		std::cout << "Lenovo��";
		GPU::disp();
	}
};
class intel_RAM : public RAM {
public:
	void disp() {
		std::cout << "Intel��";
		RAM::disp();
	}
};
class lenovo_RAM : public RAM {
public:
	void disp() {
		std::cout << "Lenovo��";
		RAM::disp();
	}
};
int main() {
	intel_CPU intelcpu;
	lenovo_CPU lenovocpu;
	intel_GPU intelgpu;
	lenovo_GPU lenovogpu;
	intel_RAM intelram;
	lenovo_RAM lenovoram;
	int a, b, c;
	std::cin >> a >> b >> c;
	if (a == 1)
		intelcpu.disp();
	else
		lenovocpu.disp();
	if (b == 1)
		intelgpu.disp();
	else
		lenovogpu.disp();
	if (c == 1)
		intelram.disp();
	else
		lenovoram.disp();
	return 0;
}