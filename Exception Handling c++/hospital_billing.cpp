
#include <iostream>
#include <exception>
using namespace std;

class InvalidAgeException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid Patient Age";
    }
};

class InvalidQuantityException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid Quantity";
    }
};

class InvalidBillingException : public exception {
public:
    const char* what() const noexcept override {
        return "Negative Billing Amount";
    }
};

int main() {
    int age, quantity;
    double consultation, lab, medicine;

    cout << "Enter patient age: ";
    cin >> age;

    cout << "Enter consultation charges: ";
    cin >> consultation;

    cout << "Enter lab charges: ";
    cin >> lab;

    cout << "Enter medicine charges: ";
    cin >> medicine;

    cout << "Enter medicine quantity: ";
    cin >> quantity;

    try {
        if (age < 0 || age > 150) {
            throw InvalidAgeException();
        }

        if (quantity <= 0) {
            throw InvalidQuantityException();
        }

        if (consultation < 0 || lab < 0 ||
            medicine < 0) {
            throw InvalidBillingException();
        }

        double total = consultation + lab + medicine;

        cout << "Total Hospital Bill = "
             << total << endl;

        cout << "Bill Generated Successfully" << endl;
    }
    catch (InvalidAgeException& e) {
        cout << "Exception: " << e.what() << endl;
    }
    catch (InvalidQuantityException& e) {
        cout << "Exception: " << e.what() << endl;
    }
    catch (InvalidBillingException& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
