#include "PortfolioManager.h"

// Destructor to free memory
PortfolioManager::~PortfolioManager() {
    for (auto& pair : portfolio) {
        delete pair.second;  // Free dynamically allocated memory
    }
}

// Add a new asset to the portfolio
void PortfolioManager::addAsset(Asset* asset) {
    if (portfolio.find(asset->getName()) == portfolio.end()) {
        portfolio[asset->getName()] = asset;  // Store raw pointer
    } else {
        cout << "Asset already exists in the portfolio!" << endl;
    }
}

// Remove an asset from the portfolio
void PortfolioManager::removeAsset(string assetName) {
    if (portfolio.find(assetName) != portfolio.end()) {
        delete portfolio[assetName];  // Free memory of the asset being removed
        portfolio.erase(assetName);   // Erase the asset from the portfolio
        cout << "Asset removed from portfolio." << endl;
    } else {
        cout << "Asset not found in portfolio." << endl;
    }
}

// Calculate the total value of the portfolio
double PortfolioManager::getTotalValue() const {
    double totalValue = 0;
    for (const auto& pair : portfolio) {
        totalValue += pair.second->getValue();  // Sum the value of all assets
    }
    return totalValue;
}

// Buy additional units of an asset
void PortfolioManager::buyAsset(const std::string& assetName, int quantity, double price) {
    auto it = portfolio.find(assetName);
    if (it != portfolio.end()) {
        // Asset found in portfolio, proceed with buying
        it->second->buy(quantity, price);  // Update the quantity and price of the asset
        cout << "Bought " << quantity << " units of " << assetName << " at $" << price << endl;
    } else {
        // Asset not found in the portfolio
        cout << "Asset not found in portfolio. Cannot buy more units." << endl;
    }
}

// Sell units of an asset
void PortfolioManager::sellAsset(const std::string& assetName, int quantity, double price) {
    auto it = portfolio.find(assetName);
    if (it != portfolio.end()) {
        // Asset found in portfolio, proceed with selling
        if (it->second->sell(quantity, price)) {  // Update the quantity and price of the asset
            cout << "Sold " << quantity << " units of " << assetName << " at $" << price << endl;
        } else {
            cout << "Insufficient quantity to sell." << endl;
        }
    } else {
        // Asset not found in the portfolio
        cout << "Asset not found in portfolio. Cannot sell units." << endl;
    }
}

// Display a bar graph representing asset distribution
void PortfolioManager::displayPortfolioGraph() const {
    double totalValue = getTotalValue();
    if (totalValue == 0) {
        cout << "Portfolio is empty." << endl;
        return;
    }

    cout << "\n--- Portfolio Graph ---\n";
    for (const auto& pair : portfolio) {
        double assetValue = pair.second->getValue();
        int barLength = static_cast<int>((assetValue / totalValue) * 50);  // Scale the graph to 50 units
        cout << pair.first << " | ";  // Asset name
        for (int i = 0; i < barLength; ++i) {
            cout << "=";  // Bar graph
        }
        cout << " $" << assetValue << endl;
    }
    cout << "----------------------\n";
}

// Display all assets in the portfolio
void PortfolioManager::displayPortfolio() const {
    displayPortfolio(cout);  // Calls the overloaded function with cout as the default
}

// Overloaded function that writes to a given ostream
void PortfolioManager::displayPortfolio(ostream& out) const {
    out << "Portfolio Assets:\n";
    double totalProfitLoss = 0;  // To accumulate total portfolio profit/loss

    for (const auto& pair : portfolio) {
        pair.second->display(out);  // Display asset info
        double profitLoss = pair.second->calculateProfitLoss();  // Calculate profit/loss for each asset
        out << "Profit/Loss: $" << profitLoss << endl;  // Display profit/loss
        totalProfitLoss += profitLoss;  // Add to total portfolio profit/loss
    }

    out << "Total Portfolio Value: $" << getTotalValue() << endl;
    out << "Total Portfolio Profit/Loss: $" << totalProfitLoss << endl;  // Display total profit/loss
}