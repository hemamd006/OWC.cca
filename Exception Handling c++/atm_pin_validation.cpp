
#include <iostream>
#include <exception>
using namespace std;

class IncorrectPINException : public exception {
public:
    const char* what() const noexcept override {
        return "Incorrect PIN.";
    }
};

int main() {
    int correctPIN = 1234;
    int enteredPIN;
    int attempts = 3;

    while (attempts > 0) {
        cout << "Enter PIN: ";
        cin >> enteredPIN;

        try {
            if (enteredPIN != correctPIN) {
                throw IncorrectPINException();
            }

            cout << "PIN Verified Successfully" << endl;
            return 0;
        }
        catch (IncorrectPINException& e) {
            attempts--;

            cout << "Exception: " << e.what() << endl;

            if (attempts > 0) {
                cout << "Attempts Remaining: "
                     << attempts << endl;
            }
        }
    }

    cout << "ATM Card Blocked" << endl;

    return 0;
}
