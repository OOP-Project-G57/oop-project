#include <iostream>
#include "PortfolioManager.h"
#include "Stock.h"            // Inherits from Asset
#include "Cryptocurrency.h"   // Inherits from Asset
#include "Bond.h"             // Inherits from Asset
#include "GovernmentBond.h"   // Inherits from Bond

using namespace std;

// Helper function to display test results
void test(bool condition, const string& testName) {
    if (condition) {
        cout << testName << " passed." << endl;
    } else {
        cout << testName << " failed!" << endl;
    }
}

int main() {
    // Create PortfolioManager object
    PortfolioManager portfolio;

    // Test 1: Add different types of assets to the portfolio
    portfolio.addAsset(new Stock("Apple", 150.0, 10));  // Add 10 units of Apple stock
    portfolio.addAsset(new Cryptocurrency("Bitcoin", 45000.0, 2));  // Add 2 Bitcoin
    portfolio.addAsset(new Bond("CorporateBond", 1000.0, 20));  // Add Corporate Bond
    portfolio.addAsset(new GovernmentBond("USGovBond", 1050.0, 5, 1.5));  // Add 5 Government Bonds

    test(portfolio.getPortfolioSize() == 4, "Test 1.1: Add various asset types to portfolio");
    test(portfolio.getTotalValue() == (1500.0 + 90000.0 + 20000.0 + 5250.0), "Test 1.2: Total value after adding assets");

    // Test 2: Buy more of an asset
    portfolio.buyAsset("Bitcoin", 1, 46000.0);  // Buy 1 more Bitcoin
    test(portfolio.getPortfolio().at("Bitcoin")->getQuantity() == 3, "Test 2.1: Buy more Bitcoin");
    test(portfolio.getPortfolio().at("Bitcoin")->getPrice() == 46000.0, "Test 2.2: Updated Bitcoin price");

    // Test 3: Sell some stock
    portfolio.sellAsset("Apple", 3, 160.0);  // Sell 3 Apple stocks at $160 each
    test(portfolio.getPortfolio().at("Apple")->getQuantity() == 7, "Test 3.1: Sell Apple stocks");
    test(portfolio.getPortfolio().at("Apple")->getPrice() == 160.0, "Test 3.2: Updated Apple stock price");

    // Test 4: Remove an asset
    portfolio.removeAsset("CorporateBond");  // Remove CorporateBond from portfolio
    test(portfolio.getPortfolioSize() == 3, "Test 4.1: Remove CorporateBond from portfolio");
    test(portfolio.getPortfolio().find("CorporateBond") == portfolio.getPortfolio().end(), "Test 4.2: CorporateBond no longer exists");

    // Test 5: Display the portfolio
    cout << "\nDisplaying portfolio:\n";
    portfolio.displayPortfolio();

    // Test 6: Display profit/loss summary
    // Ensure "historical_prices.txt" exists with proper values for all asset types
    cout << "\nDisplaying profit/loss summary:\n";
    portfolio.displayProfitLossSummary(cout);

    return 0;
}
