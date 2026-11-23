
#include <iostream>
using namespace std;

class Account {
protected:
    double balance, rate;

public:
    Account(double b, double r) {
        balance = b;
        rate = r;
    }

    virtual void calculateInterest() {
        cout << "Calculating Interest" << endl;
    }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(double b, double r) : Account(b, r) {}

    void calculateInterest() override {
        double interest = balance * rate / 100;

        cout << "Interest = " << interest << endl;
        cout << "Final Balance = "
             << balance + interest << endl;
    }
};

class CurrentAccount : public Account {
public:
    CurrentAccount(double b, double r) : Account(b, r) {}

    void calculateInterest() override {
        double interest = 0;

        cout << "Interest = " << interest << endl;
        cout << "Final Balance = "
             << balance + interest << endl;
    }
};

class FixedDepositAccount : public Account {
public:
    FixedDepositAccount(double b, double r)
        : Account(b, r) {}

    void calculateInterest() override {
        double interest = balance * rate / 100;

        cout << "Interest = " << interest << endl;
        cout << "Final Balance = "
             << balance + interest << endl;
    }
};

int main() {
    Account* a;

    SavingsAccount s(50000, 6);
    CurrentAccount c(50000, 0);
    FixedDepositAccount f(50000, 8);

    a = &s;
    a->calculateInterest();

    cout << endl;

    a = &c;
    a->calculateInterest();

    cout << endl;

    a = &f;
    a->calculateInterest();

    return 0;
}
