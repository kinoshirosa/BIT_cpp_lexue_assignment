#include <iostream>
using namespace std;
template <class type>
void outputArray(type*, int);

template<class type>
void outputArray(type* parray, int length) {
	int i = length - 1;
	for (; i >= 0; i--) {
		cout << parray[i] << " ";
	}
	cout << endl;
}

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

int main() {

	int A_COUNT, B_COUNT, C_COUNT;
	cout << "�������������顢���������顢�ַ�������ĳ��ȣ�" << endl;
	cin >> A_COUNT >> B_COUNT >> C_COUNT;

	int* arr_int = new int[A_COUNT];

	double* arr_double = new double[B_COUNT];

	char* arr_char = new char[C_COUNT];

	cout << "�����볤��Ϊ" << A_COUNT << "���������飺" << endl;
	for (int i = 0; i < A_COUNT; ++i)
		cin >> arr_int[i];

	cout << "�����볤��Ϊ" << B_COUNT << "�ĸ��������飺" << endl;
	for (int i = 0; i < B_COUNT; ++i)
		cin >> arr_double[i];

	cout << "�����볤��Ϊ" << C_COUNT << "���ַ������飺" << endl;
	for (int i = 0; i < C_COUNT; ++i)
		cin >> arr_char[i];


	cout << "��������������飺" << endl;

	outputArray(arr_int, A_COUNT);

	cout << "����������������飺" << endl;

	outputArray(arr_double, B_COUNT);

	cout << "��������ַ������飺" << endl;

	outputArray(arr_char, C_COUNT);
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
template<class type>
void outputArray(type* parray, int length) {
	int i = length - 1;
	for (; i >= 0; i--) {
		cout << parray[i] << " ";
	}
	cout << endl;
}