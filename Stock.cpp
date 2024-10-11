#include "Stock.h"

Stock::Stock(std::string n, double p, int q) : Asset(n, p, q) {}

void Stock::buy(int q, double p) {
    quantity += q;
    price = p;
}

bool Stock::sell(int quantity, double price) {
    if (this->quantity >= quantity) {
        this->quantity -= quantity;
        this->price = price;
        return true;
    } else {
        return false;
    }
}
