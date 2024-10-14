#ifndef ASSET_H  // Prevents multiple inclusions of this header file
#define ASSET_H

#include <string>    // For std::string
#include <iostream>  // For input/output operations

// Base class representing a financial asset
class Asset {
protected:
    std::string name;         // Name of the asset
    double price;             // Current price of the asset
    int quantity;             // Quantity held
    double purchasePrice;     // Initial purchase price

public:
    // Constructor to initialize asset details
    Asset(std::string name, double price, int quantity);

    // Virtual functions to be implemented by derived classes
    virtual void buy(int q, double p) = 0;   // Buy asset
    virtual bool sell(int q, double p) = 0;  // Sell asset

    // Returns the total value of the asset (price * quantity)
    virtual double getValue() const;

    // Display asset details (prints to console)
    void display() const;
    void display(std::ostream& out) const;  // Display to a specific output stream

    // Getters for asset attributes
    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;

    // Virtual destructor for cleanup
    virtual ~Asset() {}
};

#endif  // End of include guard