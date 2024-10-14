#include "Asset.h"

Asset::Asset(string name, double price, int quantity) :
    name(name), price(price), quantity(quantity), purchasePrice(price) {}

void Asset::display() const {
    display(cout);
}

void Asset::display(ostream& out) const {
    out << name << " - Price: " << price 
        << ", Quantity: " << quantity 
        << ", Value: " << getValue() << endl;
}

string Asset::getName() {
    return name;
}

int Asset::getQuantity() {
    return quantity;
}

double Asset::calculateProfitLoss() const {
    return (quantity * price) - (quantity * purchasePrice);
}

double Asset::getPrice() const {
    return price;
}

