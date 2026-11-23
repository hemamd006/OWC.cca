
#include <iostream>
using namespace std;

class Payment {
public:
    virtual void processPayment() {
        cout << "Processing Payment" << endl;
    }
};

class UPIPayment : public Payment {
    double amount;

public:
    UPIPayment(double a) {
        amount = a;
    }

    void processPayment() override {
        double charge = amount * 0 / 100;

        cout << "Transaction Charge = " << charge << endl;
        cout << "Total Amount = " << amount + charge << endl;
        cout << "Payment Status = Successful" << endl;
    }
};

class CardPayment : public Payment {
    double amount;

public:
    CardPayment(double a) {
        amount = a;
    }

    void processPayment() override {
        double charge = amount * 2 / 100;

        cout << "Transaction Charge = " << charge << endl;
        cout << "Total Amount = " << amount + charge << endl;
        cout << "Payment Status = Successful" << endl;
    }
};

class NetBankingPayment : public Payment {
    double amount;

public:
    NetBankingPayment(double a) {
        amount = a;
    }

    void processPayment() override {
        double charge = amount * 1 / 100;

        cout << "Transaction Charge = " << charge << endl;
        cout << "Total Amount = " << amount + charge << endl;
        cout << "Payment Status = Successful" << endl;
    }
};

int main() {
    Payment* p;

    UPIPayment u(10000);
    CardPayment c(10000);
    NetBankingPayment n(10000);

    p = &u;
    p->processPayment();

    cout << endl;

    p = &c;
    p->processPayment();

    cout << endl;

    p = &n;
    p->processPayment();

    return 0;
}
