#include "Cryptocurrency.h"

Cryptocurrency::Cryptocurrency(std::string n, double p, int q) : Asset(n, p, q) {}

void Cryptocurrency::buy(int q, double p) {
    quantity += q;
    price = p;
}

bool Cryptocurrency::sell(int quantity, double price) {
    if (this->quantity >= quantity) {
        this->quantity -= quantity;
        this->price = price;
        return true;
    } else {
        return false;
    }
}
