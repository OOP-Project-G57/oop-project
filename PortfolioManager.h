#ifndef PORTFOLIOMANAGER_H
#define PORTFOLIOMANAGER_H

#include <map>
#include <string>
#include "Asset.h"

/**
 * @brief Manages the portfolio of assets.
 *
 * PortfolioManager is responsible for managing assets in a portfolio.
 * It provides methods to add, remove, and manipulate assets, as well as display
 * information about the portfolio and calculate the total value of assets.
 */
class PortfolioManager {
private:
    std::map<std::string, Asset*> portfolio;  ///< Map of asset names to Asset pointers

public:
    /**
     * @brief Gets the portfolio map as a constant reference.
     * 
     * @return Constant reference to the portfolio map.
     */
    const std::map<std::string, Asset*>& getPortfolio() const;

    /**
     * @brief Destructor for the PortfolioManager.
     * Cleans up dynamically allocated assets in the portfolio.
     */
    ~PortfolioManager();

    /**
     * @brief Adds an asset to the portfolio.
     *
     * Adds a new asset if it doesn't already exist in the portfolio.
     * 
     * @param asset Pointer to the asset being added.
     */
    void addAsset(Asset* asset);

    /**
     * @brief Removes an asset from the portfolio.
     *
     * Deletes the asset from memory and removes it from the portfolio.
     * 
     * @param assetName Name of the asset to remove.
     */
    void removeAsset(std::string assetName);

    /**
     * @brief Gets the total value of all assets in the portfolio.
     *
     * @return Total value of the portfolio.
     */
    double getTotalValue() const;

    /**
     * @brief Buys more of a specified asset.
     *
     * Updates the asset with the new quantity and price.
     * 
     * @param assetName Name of the asset to buy.
     * @param quantity Number of units to buy.
     * @param price Price per unit of the asset.
     */
    void buyAsset(const std::string& assetName, int quantity, double price);

    /**
     * @brief Sells a specified quantity of an asset.
     *
     * Updates the asset with the new quantity and price if available.
     * 
     * @param assetName Name of the asset to sell.
     * @param quantity Number of units to sell.
     * @param price Price per unit of the asset.
     */
    void sellAsset(const std::string& assetName, int quantity, double price);

    /**
     * @brief Displays a bar graph of asset values in the portfolio.
     */
    void displayPortfolioGraph() const;

    /**
     * @brief Clears the portfolio, freeing all allocated memory.
     */
    void clearPortfolio();

    /**
     * @brief Gets the number of assets in the portfolio.
     *
     * @return Number of assets in the portfolio.
     */
    int getPortfolioSize() const;

    /**
     * @brief Displays all assets in the portfolio.
     *
     * @param out Output stream to display the portfolio.
     */
    void displayPortfolio(std::ostream& out) const;

    /**
     * @brief Displays the portfolio to standard output.
     */
    void displayPortfolio() const;

    /**
     * @brief Displays the profit/loss summary for the portfolio.
     *
     * @param out Output stream to display the profit/loss summary.
     */
    void displayProfitLossSummary(std::ostream& out) const;
};

#endif

