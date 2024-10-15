#ifndef ASSET_H  // @Include guard to prevent multiple inclusions
#define ASSET_H

#include <string>    // @Provides std::string for asset names
#include <iostream>  // @Provides std::ostream for input/output operations

/**
 * @brief Base class representing a generic financial asset.
 * @details This class provides the common structure for various types 
 *          of financial assets such as stocks, bonds, and cryptocurrencies.
 */
class Asset {
protected:
    std::string name;         // @Name of the asset (e.g., "AAPL" for Apple stock)
    double price;             // @Current price of the asset per unit
    int quantity;             // @Number of units held for this asset
    double purchasePrice;     // @Initial price per unit when the asset was purchased

public:
    /**
     * @brief Constructor to initialize the asset with basic details.
     * @param name The name of the asset.
     * @param price The current price of the asset per unit.
     * @param quantity The number of units of the asset held.
     */
    Asset(std::string name, double price, int quantity);

    /**
     * @brief Pure virtual function for buying the asset.
     * @details This function must be implemented in derived classes.
     * @param q The quantity to buy.
     * @param p The price at which the asset is bought.
     */
    virtual void buy(int q, double p) = 0; 

    /**
     * @brief Pure virtual function for selling the asset.
     * @details This function must be implemented in derived classes.
     * @param q The quantity to sell.
     * @param p The price at which the asset is sold.
     * @return true if the sale is successful, false otherwise.
     */
    virtual bool sell(int q, double p) = 0;

    /**
     * @brief Calculates the total value of the asset.
     * @return The total value as (price * quantity).
     */
    virtual double getValue() const;

    /**
     * @brief Displays asset details to the console.
     * @details Calls another version of display to print to std::cout.
     */
    void display() const;

    /**
     * @brief Displays asset details to a specified output stream.
     * @param out The output stream (e.g., std::cout, file output).
     */
    void display(std::ostream& out) const;

    /**
     * @brief Getter for the name of the asset.
     * @return The name of the asset.
     */
    std::string getName() const;

    /**
     * @brief Getter for the quantity of the asset held.
     * @return The quantity of the asset.
     */
    int getQuantity() const;

    /**
     * @brief Getter for the current price of the asset.
     * @return The current price of the asset.
     */
    double getPrice() const;

    /**
     * @brief Virtual destructor for the Asset class.
     * @details Ensures proper cleanup when derived classes are used.
     */
    virtual ~Asset() {}
};

#endif  // @End of include guard
