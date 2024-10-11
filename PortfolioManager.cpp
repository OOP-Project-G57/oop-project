#include "PortfolioManager.h"
#include <fstream>
#include <sstream>

/**
 * @brief Destructor to free memory for assets in the portfolio.
 */
PortfolioManager::~PortfolioManager() {
    for (auto& pair : portfolio) {
        delete pair.second;  // Free dynamically allocated memory
    }
}

/**
 * @brief Adds a new asset to the portfolio.
 */
void PortfolioManager::addAsset(Asset* asset) {
    if (portfolio.find(asset->getName()) == portfolio.end()) {
        portfolio[asset->getName()] = asset;  // Store raw pointer
    } else {
        std::cout << "Asset already exists in the portfolio!" << std::endl;
    }
}

/**
 * @brief Removes an asset from the portfolio.
 */
void PortfolioManager::removeAsset(std::string assetName) {
    if (portfolio.find(assetName) != portfolio.end()) {
        delete portfolio[assetName];  // Free memory of the asset being removed
        portfolio.erase(assetName);   // Erase the asset from the portfolio
        std::cout << "Asset removed from portfolio." << std::endl;
    } else {
        std::cout << "Asset not found in portfolio." << std::endl;
    }
}

/**
 * @brief Gets the total value of the portfolio.
 */
double PortfolioManager::getTotalValue() const {
    double totalValue = 0;
    for (const auto& pair : portfolio) {
        totalValue += pair.second->getValue();  // Sum the value of all assets
    }
    return totalValue;
}

/**
 * @brief Buys more units of an existing asset.
 */
void PortfolioManager::buyAsset(const std::string& assetName, int quantity, double price) {
    auto it = portfolio.find(assetName);
    if (it != portfolio.end()) {
        it->second->buy(quantity, price);  // Update the quantity and price of the asset
        std::cout << "Bought " << quantity << " units of " << assetName << std::endl;
    } else {
        std::cout << "Asset not found in portfolio!" << std::endl;
    }
}

/**
 * @brief Sells some quantity of an asset.
 */
void PortfolioManager::sellAsset(const std::string& assetName, int quantity) {
    auto it = portfolio.find(assetName);
    if (it != portfolio.end()) {
        it->second->sell(quantity);  // Update the quantity of the asset
        std::cout << "Sold " << quantity << " units of " << assetName << std::endl;
    } else {
        std::cout << "Asset not found in portfolio!" << std::endl;
    }
}

/**
 * @brief Displays the portfolio to an output stream.
 */
void PortfolioManager::displayPortfolio(std::ostream& out) const {
    for (const auto& pair : portfolio) {
        out << "Asset: " << pair.first << ", Quantity: " << pair.second->getQuantity()
            << ", Price: " << pair.second->getPrice() << ", Value: " << pair.second->getValue() << std::endl;
    }
}

/**
 * @brief Calculates profit or loss for each asset based on historical prices.
 */
void PortfolioManager::calculateProfitLoss(std::ostream& out) {
    std::ifstream file("historical_prices.txt");
    if (!file.is_open()) {
        out << "Error opening historical prices file!" << std::endl;
        return;
    }

    std::map<std::string, double> historicalPrices;
    std::string line, assetName;
    double historicalPrice;

    // Read historical prices from the file
    while (getline(file, line)) {
        std::istringstream iss(line);
        if (iss >> assetName >> historicalPrice) {
            historicalPrices[assetName] = historicalPrice;
        }
    }
    file.close();

    // Calculate and display profit/loss for each asset
    for (const auto& pair : portfolio) {
        assetName = pair.first;
        Asset* asset = pair.second;
        double currentPrice = asset->getPrice();

        if (historicalPrices.find(assetName) != historicalPrices.end()) {
            double historicalPrice = historicalPrices[assetName];
            double profitOrLoss = (currentPrice - historicalPrice) * asset->getQuantity();
            out << "Asset: " << assetName << ", Historical Price: " << historicalPrice
                << ", Current Price: " << currentPrice << ", Profit/Loss: " << profitOrLoss << std::endl;
        } else {
            out << "Asset: " << assetName << " has no historical data available." << std::endl;
        }
    }
}