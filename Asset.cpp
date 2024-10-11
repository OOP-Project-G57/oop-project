#include "Asset.h"

Asset::Asset(std::string name, double price, int quantity) 
    : name(name), price(price), quantity(quantity), purchasePrice(price) {}

double Asset::getValue() const {
    return price * quantity;
}

void Asset::display() const {
    display(std::cout);
}

void Asset::display(std::ostream& out) const {
    out << name << " - Price: " << price 
        << ", Quantity: " << quantity 
        << ", Value: " << getValue() << std::endl;
}

std::string Asset::getName() const {
    return name;
}

int Asset::getQuantity() const {
    return quantity;
}

double Asset::getPrice() const {
    return price;
}
