#pragma once

#include <iostream>
#include <string>

using namespace std;

// Asset class declaration
class Asset {
protected:
    // Private member variables
    string name;
    double price;
    int quantity;
    double purchasePrice;

public:
    // Constructor
    Asset(string name, double price, int quantity);

    // Virtual methods for buying and selling assets
    virtual void buy(int q, double p) = 0;
    virtual void sell(int q, double p) = 0;

    // Calculate the current value of the asset
    virtual double getValue() const;

    // Display asset information
    void display() const;
    void display(ostream& out) const;

    // Getters for name and quantity
    string getName();
    int getQuantity();

    // Calculate profit or loss
    virtual double calculateProfitLoss() const;

    // Get the current price
    double getPrice() const;

    // Destructor
    virtual ~Asset();
};