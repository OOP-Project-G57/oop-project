#ifndef CRYPTOCURRENCY_H  // @Prevent multiple inclusions of this header file
#define CRYPTOCURRENCY_H

#include "Asset.h"  // @Include the base Asset class for inheritance

/**
 * @brief Represents a cryptocurrency asset.
 * @details This class inherits from the Asset class and provides 
 *          specific implementations for buying and selling cryptocurrency.
 */
class Cryptocurrency : public Asset {
public:
    /**
     * @brief Constructor to initialize the cryptocurrency.
     * @param n The name of the cryptocurrency (e.g., "Bitcoin").
     * @param p The current price of the cryptocurrency.
     * @param q The quantity of the cryptocurrency held.
     */
    Cryptocurrency(std::string n, double p, int q);

    /**
     * @brief Override of the buy function to purchase cryptocurrency.
     * @details Adds the specified quantity and updates the price.
     * @param q The quantity to be purchased.
     * @param p The price at which the cryptocurrency is purchased.
     */
    void buy(int q, double p) override;

    /**
     * @brief Override of the sell function to sell cryptocurrency.
     * @details Decreases the quantity if sufficient amount is available and updates the price.
     * @param quantity The quantity to be sold.
     * @param price The price at which the cryptocurrency is sold.
     * @return true if the sale is successful, false if there is insufficient quantity.
     */
    bool sell(int quantity, double price) override;
};

#endif  // @End of CRYPTOCURRENCY_H include guard
