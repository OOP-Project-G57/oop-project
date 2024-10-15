#include "PortfolioManager.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <map>
#include "colors.h"
#include "debug.h"

using namespace std;

// Destructor to clean up dynamically allocated assets
PortfolioManager::~PortfolioManager() {
    for (auto& pair : portfolio) {
        delete pair.second;
    }
}

// Adds an asset to the portfolio if it doesn't already exist
void PortfolioManager::addAsset(Asset* asset) {
    if (portfolio.find(asset->getName()) == portfolio.end()) {
        portfolio[asset->getName()] = asset;  // Store the asset in the map
    } else {
        cout << "Asset already exists in the portfolio!" << endl;
    }
}

// Removes an asset from the portfolio
void PortfolioManager::removeAsset(string assetName) {
    auto it = portfolio.find(assetName);
    if (it != portfolio.end()) {
        delete it->second;  // Free the memory
        portfolio.erase(it); // Remove from the map
        cout << "Asset removed from portfolio." << endl;
    } else {
        cout << "Asset not found in portfolio." << endl;
    }
}

// Gets the total value of all assets in the portfolio
double PortfolioManager::getTotalValue() const {
    double totalValue = 0;
    for (const auto& pair : portfolio) {
        totalValue += pair.second->getValue();  // Sum the value of all assets
    }
    return totalValue;
}

// Buys more of a specific asset and updates its quantity and price
void PortfolioManager::buyAsset(const std::string& assetName, int quantity, double price) {
    auto it = portfolio.find(assetName);
    if (it != portfolio.end()) {
        it->second->buy(quantity, price);  // Update the asset
        cout << "Bought " << quantity << " units of " << assetName << " at $" << price << endl;
    } else {
        cout << "Asset not found in portfolio. Cannot buy units." << endl;
    }
}

// Sells a specific quantity of an asset
void PortfolioManager::sellAsset(const std::string& assetName, int quantity, double price) {
    auto it = portfolio.find(assetName);
    if (it != portfolio.end()) {
        if (it->second->sell(quantity, price)) {  // Check if sufficient quantity is available
            cout << "Sold " << quantity << " units of " << assetName << " at $" << price << endl;
        } else {
            cout << "Insufficient quantity to sell." << endl;
        }
    } else {
        cout << "Asset not found in portfolio. Cannot sell units." << endl;
    }
}

// Displays a bar graph representation of asset values
void PortfolioManager::displayPortfolioGraph() const {
    double totalValue = getTotalValue();
    if (totalValue == 0) {
        cout << RED << "No assets in the portfolio to display graph.\n" << RESET;
        return;
    }

    cout << CYAN << "\n--- Portfolio Graph ---\n" << RESET;
    for (const auto& pair : portfolio) {
        double assetValue = pair.second->getValue();
        int barLength = static_cast<int>((assetValue / totalValue) * 50);
        cout << pair.first << " | ";
        for (int i = 0; i < barLength; ++i) {
            cout << GREEN << "=" << RESET;
        }
        cout << " $" << assetValue << endl;
    }
    cout << CYAN << "----------------------\n" << RESET;
}

// Clears all assets in the portfolio
void PortfolioManager::clearPortfolio() {
    for (auto& pair : portfolio) {
        delete pair.second;  // Free dynamically allocated memory
    }
    portfolio.clear();  // Clear the map
}

// Gets the number of assets in the portfolio
int PortfolioManager::getPortfolioSize() const {
    return portfolio.size();
}

// Displays all assets in the portfolio
void PortfolioManager::displayPortfolio(ostream& out) const {
    out << CYAN << "╔═══════════════════════════════════════╗\n";
    out << CYAN << "║            Portfolio Assets           ║\n";
    out << CYAN << "╚═══════════════════════════════════════╝\n" << RESET;

    out << std::left << std::setw(15) << "Asset" 
        << std::setw(10) << "Price" 
        << std::setw(10) << "Quantity" 
        << std::setw(10) << "Value" << std::endl;

    for (const auto& pair : portfolio) {
        out << std::left << std::setw(15) << pair.first
            << std::setw(10) << pair.second->getPrice()
            << std::setw(10) << pair.second->getQuantity()
            << std::setw(10) << pair.second->getValue() << std::endl;
    }

    // Display profit/loss summary
    const_cast<PortfolioManager*>(this)->displayProfitLossSummary(out);
}

// Overloaded version of displayPortfolio that uses cout
void PortfolioManager::displayPortfolio() const {
    displayPortfolio(cout);
}

// Displays the profit/loss summary for each asset
void PortfolioManager::displayProfitLossSummary(ostream& out) const {
    ifstream file("historical_prices.txt");
    if (!file.is_open()) {
        out << RED << "Error: Could not open historical prices file!" << RESET << endl;
        return;
    }

    map<string, double> historicalPrices;
    string line, assetName;
    double historicalPrice;
    
    // Load historical prices from the file
    while (getline(file, line)) {
        istringstream iss(line);
        if (iss >> assetName >> historicalPrice) {
            historicalPrices[assetName] = historicalPrice;
        }
    }
    file.close();

    out << YELLOW << "╔═══════════════════════════════════════════════════════════╗\n";
    out << YELLOW << "║                   Profit/Loss Summary                     ║\n";
    out << YELLOW << "╚═══════════════════════════════════════════════════════════╝\n" << RESET;

    out << std::left << std::setw(15) << "Asset" 
        << std::setw(15) << "Historical Price" 
        << std::setw(15) << "Current Price" 
        << std::setw(15) << "Profit/Loss\n" << RESET;

    for (const auto& pair : portfolio) {
        string currentAsset = pair.first;
        Asset* asset = pair.second;
        double currentPrice = asset->getPrice();
        
        if (historicalPrices.find(currentAsset) != historicalPrices.end()) {
            double historicalPrice = historicalPrices[currentAsset];
            double profitOrLoss = (currentPrice - historicalPrice) * asset->getQuantity();
            
            out << std::left << std::setw(15) << currentAsset
                << std::setw(15) << historicalPrice
                << std::setw(15) << currentPrice;

            // Display profit/loss in colored format
            if (profitOrLoss >= 0) {
                out << GREEN << std::setw(15) << "+" + std::to_string(profitOrLoss) << RESET << std::endl;
            } else {
                out << RED << std::setw(15) << std::to_string(profitOrLoss) << RESET << std::endl;
            }
        } else {
            out << currentAsset << " - Historical data not available." << std::endl;
        }
    }
}
