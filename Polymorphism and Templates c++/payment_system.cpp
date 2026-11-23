
#include <iostream>
using namespace std;

class Payment {
public:
    virtual void makePayment() {
        cout << "Processing Payment" << endl;
    }
};

class UPI : public Payment {
    double amount;

public:
    UPI(double a) {
        amount = a;
    }

    void makePayment() override {
        cout << "Payment Mode: UPI" << endl;
        cout << "Amount Paid = " << amount << endl;
        cout << "Payment Successful" << endl;
    }
};

class CreditCard : public Payment {
    double amount;

public:
    CreditCard(double a) {
        amount = a;
    }

    void makePayment() override {
        cout << "Payment Mode: Credit Card" << endl;
        cout << "Amount Paid = " << amount << endl;
        cout << "Payment Successful" << endl;
    }
};

class Cash : public Payment {
    double amount;

public:
    Cash(double a) {
        amount = a;
    }

    void makePayment() override {
        cout << "Payment Mode: Cash" << endl;
        cout << "Amount Paid = " << amount << endl;
        cout << "Payment Successful" << endl;
    }
};

int main() {
    Payment* p;

    UPI u(2500);
    CreditCard c(5000);
    Cash cash(1000);

    p = &u;
    p->makePayment();

    p = &c;
    p->makePayment();

    p = &cash;
    p->makePayment();

    return 0;
}
