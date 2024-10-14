#ifndef CRYPTOCURRENCY_H  // Prevent multiple inclusions
#define CRYPTOCURRENCY_H

#include "Asset.h"  // Include the base Asset class

// Represents a cryptocurrency, inheriting from Asset
class Cryptocurrency : public Asset {
public:
    // Constructor to initialize the cryptocurrency
    Cryptocurrency(std::string n, double p, int q);

    // Adds quantity and updates the price when buying
    void buy(int q, double p) override;

    // Sells quantity if available and updates the price
    bool sell(int quantity, double price) override;
};

#endif  // End of include guard
