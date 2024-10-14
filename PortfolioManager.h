#ifndef PORTFOLIOMANAGER_H
#define PORTFOLIOMANAGER_H

#include "Asset.h"
#include <map>
#include <string>
#include <iostream>

class PortfolioManager {
private:
    std::map<std::string, Asset*> portfolio;  // Stores assets using raw pointers

public:
 
    ~PortfolioManager();

    void addAsset(Asset* asset);

    void removeAsset(std::string assetName);

    double getTotalValue() const;

    void buyAsset(const std::string& assetName, int quantity, double price);

    void sellAsset(const std::string& assetName, int quantity);

    void displayPortfolio(std::ostream& out = std::cout) const;

    void calculateProfitLoss(std::ostream& out);
};

#endif // PORTFOLIOMANAGER_H
