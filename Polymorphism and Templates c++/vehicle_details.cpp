
#include <iostream>
#include <string>
using namespace std;

class Vehicle {
public:
    virtual void displayDetails() {
        cout << "Vehicle Details" << endl;
    }
};

class Bike : public Vehicle {
    string brand, model;

public:
    Bike(string b, string m) {
        brand = b;
        model = m;
    }

    void displayDetails() override {
        cout << "Vehicle: Bike" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
    }
};

class Car : public Vehicle {
    string brand, model;

public:
    Car(string b, string m) {
        brand = b;
        model = m;
    }

    void displayDetails() override {
        cout << "Vehicle: Car" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
    }
};

class Bus : public Vehicle {
    string brand, model;

public:
    Bus(string b, string m) {
        brand = b;
        model = m;
    }

    void displayDetails() override {
        cout << "Vehicle: Bus" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
    }
};

int main() {
    Vehicle* v;

    Bike b("Honda", "Shine");
    Car c("Hyundai", "Creta");
    Bus bus("Volvo", "9400");

    v = &b;
    v->displayDetails();

    v = &c;
    v->displayDetails();

    v = &bus;
    v->displayDetails();

    return 0;
}
