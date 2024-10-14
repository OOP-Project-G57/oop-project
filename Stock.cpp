#include "Stock.h"

// Constructor
Stock::Stock(std::string n, double p, int q) : Asset(n, p, q) {}

// Calculate profit or loss for stock
double Stock::calculateProfitLoss() const {
    return (price - purchasePrice) * quantity; // Calculate profit/loss based on current and purchase price
}

// Implementation of other methods
double Stock::getValue() const {
    return price * quantity;
}

void Stock::buy(int q, double p) {
    quantity += q;
    price = p; // Update price to the latest purchase price
}

bool Stock::sell(int q, double p) {
    if (q <= quantity) {
        quantity -= q;
        price = p; // Update price to the latest sale price
        return true; // Successful sale
    } else {
        std::cout << "Not enough stock to sell!\n";
        return false; // Failed sale
    }
}
