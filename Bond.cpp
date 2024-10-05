#include "Bond.h"
#include <iostream>

double Bond::getValue() const {
    return price * quantity;
}

void Bond::buy(int q, double p) {
    quantity += q;
    price = p;
}

void Bond::sell(int q, double p) {
    if (q <= quantity) {
        quantity -= q;
        price = p;
    } else {
        std::cout << "Not enough bonds to sell!\n";
    }
}

double Bond::calculateProfitLoss() const {
    return (price - purchasePrice) * quantity + (interestRate * quantity);
}
