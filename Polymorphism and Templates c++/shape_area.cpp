
#include <iostream>
#include <iomanip>
using namespace std;

class Shape {
public:
    virtual void area() {
        cout << "Calculating area" << endl;
    }
};

class Circle : public Shape {
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    void area() override {
        cout << fixed << setprecision(2);
        cout << "Area of Circle = "
             << 3.14 * radius * radius << endl;
    }
};

class Rectangle : public Shape {
    double length, breadth;

public:
    Rectangle(double l, double b) {
        length = l;
        breadth = b;
    }

    void area() override {
        cout << "Area of Rectangle = "
             << length * breadth << endl;
    }
};

int main() {
    Shape* s;
    Circle c(5);
    Rectangle r(10, 5);

    s = &c;
    s->area();

    s = &r;
    s->area();

    return 0;
}
