#ifndef STOCK_H  // Prevent multiple inclusions
#define STOCK_H

#include "Asset.h"  // Include the base Asset class

// Stock class inherits from the Asset class
class Stock : public Asset {
public:
    // Constructor to initialize the stock with name, price, and quantity
    Stock(std::string n, double p, int q);

    // Buy function to increase quantity and update price
    void buy(int q, double p) override;

    // Sell function to reduce quantity if available and update price
    bool sell(int quantity, double price) override;
    
    //Get value
    double getValue() const override;

    // Implement the calculateProfitLoss method
    double calculateProfitLoss() const override; // Pure virtual function

};

#endif  // End of include guard