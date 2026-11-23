
#include <iostream>
using namespace std;

template <class T>
class Calculator {
    T a, b;

public:
    Calculator(T x, T y) {
        a = x;
        b = y;
    }

    void calculate() {
        cout << "Addition = " << a + b << endl;
        cout << "Subtraction = " << a - b << endl;
        cout << "Multiplication = " << a * b << endl;

        if (b != 0) {
            cout << "Division = "
                 << static_cast<double>(a) / b << endl;
        }
        else {
            cout << "Division by zero is not allowed"
                 << endl;
        }
    }
};

int main() {
    Calculator<int> c(10, 5);
    c.calculate();

    return 0;
}
