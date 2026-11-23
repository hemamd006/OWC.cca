
#include <iostream>
#include <exception>
using namespace std;

class InvalidMarksException : public exception {
public:
    const char* what() const noexcept override {
        return "Marks must be between 0 and 100.";
    }
};

int main() {
    int n, marks, total = 0;
    double average;

    cout << "Enter number of subjects: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of subjects" << endl;
        return 0;
    }

    try {
        for (int i = 1; i <= n; i++) {
            cout << "Enter marks for subject "
                 << i << ": ";
            cin >> marks;

            if (marks < 0 || marks > 100) {
                throw InvalidMarksException();
            }

            total += marks;
        }

        average = (double)total / n;

        cout << "Total = " << total << endl;
        cout << "Average = " << average << endl;

        if (average >= 80)
            cout << "Grade = A" << endl;
        else if (average >= 70)
            cout << "Grade = B" << endl;
        else if (average >= 60)
            cout << "Grade = C" << endl;
        else if (average >= 50)
            cout << "Grade = D" << endl;
        else
            cout << "Grade = F" << endl;
    }
    catch (InvalidMarksException& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
