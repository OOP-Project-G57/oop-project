#pragma once

#include "Asset.h"
#include <map>
#include <iostream>
#include <iomanip>
using namespace std;

class PortfolioManager {
private:
    map<string, Asset*> portfolio;  // Raw pointers instead of unique_ptr

public:
    // Destructor to free memory
    ~PortfolioManager();

    // Add a new asset to the portfolio
    void addAsset(Asset* asset);

    // Remove an asset from the portfolio
    void removeAsset(string assetName);

    // Calculate the total value of the portfolio
    double getTotalValue() const;

    // Buy additional units of an asset
    void buyAsset(const std::string& assetName, int quantity, double price);

    // Sell units of an asset
    void sellAsset(const std::string& assetName, int quantity, double price);

    // Display a bar graph representing asset distribution
    void displayPortfolioGraph() const;

    // Display all assets in the portfolio
    void displayPortfolio() const;

    // Overloaded function that writes to a given ostream
    void displayPortfolio(ostream& out) const;
};
