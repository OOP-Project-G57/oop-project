#include "Cryptocurrency.h"  // Include the header file for Cryptocurrency

// Constructor: Initializes the cryptocurrency with name, price, and quantity.
// Calls the base class (Asset) constructor to set common attributes.
Cryptocurrency::Cryptocurrency(std::string n, double p, int q) 
    : Asset(n, p, q) {}

// Implementation of the buy function:
// Increases the quantity of cryptocurrency and updates the price.
void Cryptocurrency::buy(int q, double p) {
    quantity += q;  // Add to the existing quantity
    price = p;       // Update the price to the new purchase price
}

// Implementation of the sell function:
// Decreases the quantity if enough is available and updates the price.
bool Cryptocurrency::sell(int quantity, double price) {
    if (this->quantity >= quantity) {  // Check if enough quantity is available
        this->quantity -= quantity;  // Subtract the sold quantity
        this->price = price;  // Update the price to the selling price
        return true;  // Sale successful
    } else {
        return false;  // Not enough quantity to sell
    }
}
