#ifndef BOND_H  // @Prevent multiple inclusions of this header file
#define BOND_H

#include "Asset.h"  // @Include the Asset base class for inheritance

/**
 * @brief Bond class representing a financial bond.
 * @details This class inherits from the Asset class and adds bond-specific attributes 
 *          like the interest rate. It provides implementations for buying and selling bonds.
 */
class Bond : public Asset {
protected:
    double interestRate;  // @Interest rate associated with the bond

public:
    /**
     * @brief Constructor to initialize a bond with details.
     * @param n The name of the bond (e.g., "Gov Bond").
     * @param p The current price of the bond.
     * @param q The quantity of the bond held.
     * @param ir The interest rate of the bond.
     */
    Bond(std::string n, double p, int q, double ir);

    /**
     * @brief Override of the buy function to purchase bonds.
     * @details Increases the bond quantity and updates the price.
     * @param q The quantity to be purchased.
     * @param p The price at which the bond is purchased.
     */
    void buy(int q, double p) override;

    /**
     * @brief Override of the sell function to sell bonds.
     * @details Decreases the bond quantity and updates the price if the sale is successful.
     * @param quantity The quantity to be sold.
     * @param price The price at which the bond is sold.
     * @return true if the sale was successful, false if insufficient quantity.
     */
    bool sell(int quantity, double price) override;

    /**
     * @brief Overloads the << operator to print bond details.
     * @details Allows printing of bond information using std::cout or other streams.
     * @param os The output stream to print to.
     * @param bond The bond object to print.
     * @return The output stream with bond details.
     */
    friend std::ostream& operator<<(std::ostream& os, const Bond& bond);
};

#endif  // @End of BOND_H
