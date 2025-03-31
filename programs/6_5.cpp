#include <iostream>
using namespace std;
template <class type>
class input {
private:
    type _min;
    type _max;
public:
    input(type min = 0, type max = 0) { _min = min; _max = max; }
    void output(type value) {
        if (_min <= value && _max >= value) {
            cout << value << endl;
        }
        else {
            cout << "数据不符合范围，请重新输入。" << endl;
        }
    }
};

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    char a, b, c;
    cin >> a >> b >> c;
    input< int> in1(x, y);
    in1.output(z);

    input < char> in2(a, b);
    in2.output(c);

}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */