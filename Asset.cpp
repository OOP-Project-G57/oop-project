#include "Asset.h"

// Asset class constructor
Asset::Asset(string name, double price, int quantity) :
    name(name), price(price), quantity(quantity), purchasePrice(price) {
    // Initialize asset properties with provided values.
    // Store the initial purchase price for profit/loss calculations.
}

// Display asset information to the console
void Asset::display() const {
    // Call the overloaded display method with standard output stream
    display(cout);
}

// Display asset information to a specified output stream
void Asset::display(ostream& out) const {
    // Output asset details in a formatted manner
    out << name << " - Price: " << price
        << ", Quantity: " << quantity
        << ", Value: " << getValue() << endl;
}

// Get the asset's name
string Asset::getName() {
    // Return the asset's name
    return name;
}

// Get the asset's quantity
int Asset::getQuantity() {
    // Return the asset's quantity
    return quantity;
}

// Calculate the profit or loss for the asset
double Asset::calculateProfitLoss() const {
    // Calculate the total selling price and subtract the total purchase price
    return (quantity * price) - (quantity * purchasePrice);
}

// Get the current price of the asset
double Asset::getPrice() const {
    // Return the asset's current price
    return price;
}