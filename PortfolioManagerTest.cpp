#include "PortfolioManager.h"
#include "Stock.h"  // Assuming you have a Stock class that inherits Asset
#include <iostream>

using namespace std;

int main() {
    PortfolioManager manager;

    // Add some assets
    cout << "==== Testing Adding Assets ====" << endl;
    manager.addAsset(new Stock("AAPL", 150, 10));
    manager.addAsset(new Stock("TSLA", 700, 5));
    manager.displayPortfolio();

    // Test buying more of an asset
    cout << "\n==== Testing Buying Asset ====" << endl;
    manager.buyAsset("AAPL", 5, 155);
    manager.displayPortfolio();

    // Test selling an asset
    cout << "\n==== Testing Selling Asset ====" << endl;
    manager.sellAsset("TSLA", 3);
    manager.displayPortfolio();

    // Test removing an asset
    cout << "\n==== Testing Removing Asset ====" << endl;
    manager.removeAsset("AAPL");
    manager.displayPortfolio();

    // Test total value calculation
    cout << "\n==== Testing Total Portfolio Value ====" << endl;
    cout << "Total Value: " << manager.getTotalValue() << endl;

    return 0;
}
