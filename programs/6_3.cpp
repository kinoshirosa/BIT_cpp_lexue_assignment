#include <iostream>
using namespace std;

template <class type>
void Sort(type*, int);

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include<iostream>
using namespace std;

int main()
{
	int data1[100];
	//= { 1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20 };
	char data2[100];
	int len_int;
	int len_char;
	int i = 0;
	int j = 0;

	cout << "请输入int型数组的长度" << endl;
	cin >> len_int;
	for (i = 0; i < len_int; i++)
		cin >> data1[i];

	cout << "请输入char类型数组的长度" << endl;
	cin >> len_char;
	for (j = 0; j < len_char; j++)
		cin >> data2[j];

	Sort(data1, len_int);//编写排序函数，data1是数组，len_int是数组长度
	Sort(data2, len_char);

	cout << "int型数组排序后：" << endl;
	for (i = 0; i < len_int; i++)
		cout << data1[i] << " ";
	cout << endl;

	cout << "char型数组排序后：" << endl;
	for (j = 0; j < len_char; j++)
		cout << data2[j] << " ";
	cout << endl;

	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

template <class type>
void Sort(type* parray, int length) {
	int i = 0, j = 0;
	type tmp;
	for (i = 0; i < length - 1; i++) {
		for (j = i + 1; j < length; j++) {
			if (parray[j] < parray[i]) {
				tmp = parray[i];
				parray[i] = parray[j];
				parray[j] = tmp;
			}
		}
	}
}