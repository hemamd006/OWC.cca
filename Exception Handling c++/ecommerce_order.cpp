
#include <iostream>
#include <exception>
using namespace std;

class InvalidQuantityException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid Quantity";
    }
};

class InsufficientStockException : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient Stock";
    }
};

class InvalidPriceException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid Product Price";
    }
};

int main() {
    double price;
    int quantity, stock;

    cout << "Enter product price: ";
    cin >> price;

    cout << "Enter quantity: ";
    cin >> quantity;

    cout << "Enter available stock: ";
    cin >> stock;

    try {
        if (price <= 0) {
            throw InvalidPriceException();
        }

        if (quantity <= 0) {
            throw InvalidQuantityException();
        }

        if (stock < 0) {
            throw InvalidQuantityException();
        }

        if (quantity > stock) {
            throw InsufficientStockException();
        }

        double total = price * quantity;
        int remainingStock = stock - quantity;

        cout << "Order Confirmed" << endl;
        cout << "Total Amount = " << total << endl;
        cout << "Remaining Stock = "
             << remainingStock << endl;
    }
    catch (InvalidPriceException& e) {
        cout << "Exception: " << e.what() << endl;
    }
    catch (InvalidQuantityException& e) {
        cout << "Exception: " << e.what() << endl;
    }
    catch (InsufficientStockException& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
