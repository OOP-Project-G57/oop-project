#include <iostream>
#include "FileManager.h"
#include "PortfolioManager.h"
#include "TransactionLog.h"
#include "Stock.h"  // Assuming Stock is the asset type used in PortfolioManager

using namespace std;

// Helper function for test evaluation
void test(bool condition, const string& testName) {
    if (condition) {
        cout << testName << " passed." << endl;
    } else {
        cout << testName << " failed!" << endl;
    }
}

int main() {
    // Setup: Create PortfolioManager and TransactionLog objects
    PortfolioManager portfolio;
    TransactionLog transactionLog;
    FileManager fileManager;

    // File names to test saving/loading
    const string portfolioFile = "test_portfolio.txt";
    const string transactionFile = "test_transactions.txt";

    // Test 1: Save and load portfolio
    // Add assets to portfolio
    portfolio.addAsset(new Stock("Apple", 150.0, 10));
    portfolio.addAsset(new Stock("Tesla", 200.0, 5));

    // Save portfolio to file
    fileManager.savePortfolio(portfolio, portfolioFile);
    PortfolioManager loadedPortfolio;
    fileManager.loadPortfolio(loadedPortfolio, portfolioFile);

    // Verify loaded portfolio matches the saved one
    test(loadedPortfolio.getPortfolioSize() == 2, "Test 1.1: Loaded portfolio size");
    test(loadedPortfolio.getPortfolio().at("Apple")->getQuantity() == 10, "Test 1.2: Apple quantity");
    test(loadedPortfolio.getPortfolio().at("Tesla")->getPrice() == 200.0, "Test 1.3: Tesla price");

    // Test 2: Save and load transaction log
    // Add transactions to the log
    transactionLog.logTransaction(Transaction("Apple", "buy", 10, 150.0, "2023-10-10"));
    transactionLog.logTransaction(Transaction("Tesla", "buy", 5, 200.0, "2023-10-15"));

    // Save transaction log to file
    fileManager.saveTransactionLog(transactionLog, transactionFile);
    TransactionLog loadedLog;
    fileManager.loadTransactionLog(loadedLog, transactionFile);

    // Verify loaded transaction log matches the saved one
    test(loadedLog.getTransactions().size() == 2, "Test 2.1: Loaded transaction log size");
    test(loadedLog.getTransactions()[0].getAssetName() == "Apple", "Test 2.2: First transaction asset name");
    test(loadedLog.getTransactions()[1].getQuantity() == 5, "Test 2.3: Second transaction quantity");
    test(loadedLog.getTransactions()[1].getDate() == "2023-10-15", "Test 2.4: Second transaction date");

    cout << "All tests completed." << endl;
    return 0;
}
