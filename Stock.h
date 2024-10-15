#ifndef STOCK_H  // @Prevent multiple inclusions of this header file
#define STOCK_H

#include "Asset.h"  // @Include the base Asset class for inheritance

/**
 * @brief Represents a stock asset.
 * @details This class inherits from the Asset class and implements 
 *          specific behavior for buying and selling stocks.
 */
class Stock : public Asset {
public:
    /**
     * @brief Constructor to initialize the stock.
     * @param n The name of the stock (e.g., "AAPL").
     * @param p The current price of the stock per unit.
     * @param q The quantity of the stock held.
     */
    Stock(std::string n, double p, int q);

    /**
     * @brief Buy function to increase stock quantity and update price.
     * @details Adds the specified quantity and sets the new price.
     * @param q The quantity to be purchased.
     * @param p The price at which the stock is purchased.
     */
    void buy(int q, double p) override;

    /**
     * @brief Sell function to reduce stock quantity and update price.
     * @details Decreases the quantity if sufficient stock is available 
     *          and updates the price.
     * @param quantity The quantity to be sold.
     * @param price The price at which the stock is sold.
     * @return true if the sale is successful, false if there is insufficient quantity.
     */
    bool sell(int quantity, double price) override;
};

#endif  // @End of STOCK_H include guard
