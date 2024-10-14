#include "Stock.h"  // Include the Stock class header

// Constructor: Initializes the stock with name, price, and quantity
// Calls the base class (Asset) constructor to set common attributes
Stock::Stock(std::string n, double p, int q) 
    : Asset(n, p, q) {}

// Buy function: Increases the quantity and updates the price
void Stock::buy(int q, double p) {
    quantity += q;  // Add to the existing quantity
    price = p;      // Update the stock's price
}

// Sell function: Decreases the quantity if enough is available and updates the price
bool Stock::sell(int quantity, double price) {
    if (this->quantity >= quantity) {  // Check if sufficient quantity is available
        this->quantity -= quantity;  // Subtract the sold quantity
        this->price = price;  // Update the price to the selling price
        return true;  // Sale successful
    } else {
        return false;  // Sale unsuccessful, not enough quantity
    }
}
