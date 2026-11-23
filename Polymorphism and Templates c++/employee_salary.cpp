
#include <iostream>
using namespace std;

class Employee {
public:
    virtual void calculateSalary() {
        cout << "Calculating Salary" << endl;
    }
};

class Developer : public Employee {
    int basicSalary, bonus;

public:
    Developer(int b, int bo) {
        basicSalary = b;
        bonus = bo;
    }

    void calculateSalary() override {
        cout << "Total Salary = "
             << basicSalary + bonus << endl;
    }
};

class Manager : public Employee {
    int basicSalary, allowance;

public:
    Manager(int b, int a) {
        basicSalary = b;
        allowance = a;
    }

    void calculateSalary() override {
        cout << "Total Salary = "
             << basicSalary + allowance << endl;
    }
};

int main() {
    Employee* e;

    Developer d(30000, 5000);
    Manager m(50000, 10000);

    e = &d;
    e->calculateSalary();

    e = &m;
    e->calculateSalary();

    return 0;
}
