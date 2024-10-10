#include "Cryptocurrency.h"
#include <iostream>

double Cryptocurrency::getValue() const {
    return price * quantity;
}

void Cryptocurrency::buy(int q, double p) {
    quantity += q;
    price = p;
}

void Cryptocurrency::sell(int q, double p) {
    if (q <= quantity) {
        quantity -= q;
        price = p;
    } else {
        std::cout << "Not enough cryptocurrency to sell!\n";
    }
}

double Cryptocurrency::calculateProfitLoss() const {
    return (price - purchasePrice) * quantity;
}
