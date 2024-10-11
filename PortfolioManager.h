#ifndef PORTFOLIOMANAGER_H
#define PORTFOLIOMANAGER_H

#include "Asset.h"
#include <map>
#include <string>
#include <iostream>

/**
 * @class PortfolioManager
 * @brief Manages a portfolio of assets, including adding, removing, and calculating the total value.
 */
class PortfolioManager {
private:
    std::map<std::string, Asset*> portfolio;  // Stores assets using raw pointers

public:
    /**
     * @brief Destructor to free dynamically allocated memory for assets.
     */
    ~PortfolioManager();

    /**
     * @brief Adds a new asset to the portfolio.
     * 
     * If the asset already exists, a message is displayed.
     * @param asset Pointer to the asset to be added.
     */
    void addAsset(Asset* asset);

    /**
     * @brief Removes an asset from the portfolio.
     * 
     * Frees the memory associated with the asset.
     * @param assetName Name of the asset to remove.
     */
    void removeAsset(std::string assetName);

    /**
     * @brief Gets the total value of all assets in the portfolio.
     * @return Total value of the portfolio.
     */
    double getTotalValue() const;

    /**
     * @brief Buys more of an existing asset.
     * 
     * Updates the quantity and price of the asset.
     * @param assetName Name of the asset.
     * @param quantity Number of units to buy.
     * @param price Price per unit.
     */
    void buyAsset(const std::string& assetName, int quantity, double price);

    /**
     * @brief Sells some quantity of an asset.
     * 
     * Updates the quantity of the asset. If the asset doesn't exist, an error message is displayed.
     * @param assetName Name of the asset.
     * @param quantity Number of units to sell.
     */
    void sellAsset(const std::string& assetName, int quantity);

    /**
     * @brief Displays the portfolio with asset details.
     * 
     * @param out Output stream for displaying the portfolio.
     */
    void displayPortfolio(std::ostream& out = std::cout) const;

    /**
     * @brief Calculates and displays profit/loss for each asset based on historical prices.
     * 
     * @param out Output stream for displaying profit/loss.
     */
    void calculateProfitLoss(std::ostream& out);
};

#endif // PORTFOLIOMANAGER_H
