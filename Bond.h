#ifndef BOND_H  // Prevent multiple inclusions of this header file
#define BOND_H

#include "Asset.h"  // Include the Asset base class

// Bond class inherits from the Asset class
class Bond : public Asset {
protected:
    double interestRate;  // Interest rate specific to the bond

public:
    // Constructor to initialize bond with name, price, quantity, and interest rate
    Bond(std::string n, double p, int q, double ir);

    // Overrides the buy function to add quantity and update the price
    void buy(int q, double p) override;

    // Overrides the sell function to decrease quantity and update the price
    bool sell(int quantity, double price) override;

    // Friend function to overload the << operator for printing bond details
    friend std::ostream& operator<<(std::ostream& os, const Bond& bond);
};

#endif  // End of BOND_H
