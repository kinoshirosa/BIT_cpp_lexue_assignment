#include <iostream>
using namespace std;
template <class type>
type getSum(type*, int);

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

int main()
{
	int n, m;
	cin >> n >> m;
	int* arr_int = new int[n];
	double* arr_double = new double[m];
	for (int i = 0; i < n; ++i)
		cin >> arr_int[i];
	for (int i = 0; i < m; ++i)
		cin >> arr_double[i];
	cout << getSum(arr_int, n) << endl;
	cout << getSum(arr_double, m) << endl;
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

template <class type>
type getSum(type* parray, int length) {
	int i = 0;
	type result = 0;
	for (i = 0; i < length; i++) {
		result = result + parray[i];
	}
	return result;
}