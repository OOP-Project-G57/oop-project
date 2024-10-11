#include "Bond.h"

Bond::Bond(std::string n, double p, int q, double ir) : Asset(n, p, q), interestRate(ir) {}

void Bond::buy(int q, double p) {
    quantity += q;
    price = p;
}

bool Bond::sell(int quantity, double price) {
    if (this->quantity >= quantity) {
        this->quantity -= quantity;
        this->price = price;
        return true;
    } else {
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const Bond& bond) {
    os << bond.name << " - Price: " << bond.price << ", Quantity: " << bond.quantity 
       << ", Interest Rate: " << bond.interestRate << "%";
    return os;
}
