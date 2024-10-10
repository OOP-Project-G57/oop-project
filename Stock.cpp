#include "Stock.h"
#include <iostream>

double Stock::getValue() const {
    return price * quantity;
}

void Stock::buy(int q, double p) {
    quantity += q;
    price = p;
}

void Stock::sell(int q, double p) {
    if (q <= quantity) {
        quantity -= q;
        price = p;
    } else {
        std::cout << "Not enough stock to sell!\n";
    }
}

double Stock::calculateProfitLoss() const {
    return (price - purchasePrice) * quantity;
}
