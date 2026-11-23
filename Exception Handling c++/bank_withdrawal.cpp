
#include <iostream>
#include <exception>
using namespace std;

class InsufficientBalanceException : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient balance.";
    }
};

class BankAccount {
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientBalanceException();
        }

        balance -= amount;

        cout << "Withdrawal Successful" << endl;
        cout << "Remaining Balance = " << balance << endl;
    }
};

int main() {
    double balance, amount;

    cout << "Enter balance: ";
    cin >> balance;

    cout << "Enter withdrawal amount: ";
    cin >> amount;

    try {
        BankAccount account(balance);
        account.withdraw(amount);
    }
    catch (InsufficientBalanceException& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
