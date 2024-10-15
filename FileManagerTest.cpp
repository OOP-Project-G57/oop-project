#include <iostream>
#include "FileManager.h"
#include "PortfolioManager.h"
#include "TransactionLog.h"
#include "Stock.h"
#include "Cryptocurrency.h"
#include "Bond.h"
#include "GovernmentBond.h"

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
    // Create PortfolioManager, TransactionLog, and FileManager objects
    PortfolioManager portfolio;
    TransactionLog transactionLog;
    FileManager fileManager;

    // File names for saving/loading tests
    const string portfolioFile = "test_portfolio.txt";
    const string transactionFile = "test_transactions.txt";

    // Test 1: Save and load portfolio with multiple asset types
    // Add different asset types to the portfolio
    portfolio.addAsset(new Stock("Apple", 150.0, 10));  // 10 units of Apple stock
    portfolio.addAsset(new Cryptocurrency("Bitcoin", 45000.0, 2));  // 2 Bitcoin
    portfolio.addAsset(new Bond("CorporateBond", 1000.0, 20));  // Corporate Bond
    portfolio.addAsset(new GovernmentBond("USGovBond", 1050.0, 5, 1.5));  // 5 Government Bonds

    // Save portfolio to file
    fileManager.savePortfolio(portfolio, portfolioFile);
    
    // Load the portfolio back into a new object
    PortfolioManager loadedPortfolio;
    fileManager.loadPortfolio(loadedPortfolio, portfolioFile);

    // Verify loaded portfolio matches the saved one
    test(loadedPortfolio.getPortfolioSize() == 4, "Test 1.1: Loaded portfolio size matches saved size");
    test(loadedPortfolio.getPortfolio().at("Apple")->getQuantity() == 10, "Test 1.2: Loaded Apple quantity");
    test(loadedPortfolio.getPortfolio().at("Bitcoin")->getPrice() == 45000.0, "Test 1.3: Loaded Bitcoin price");
    test(loadedPortfolio.getPortfolio().at("USGovBond")->getQuantity() == 5, "Test 1.4: Loaded GovernmentBond quantity");

    // Test 2: Save and load transaction log with multiple transactions
    // Add transactions to the log
    transactionLog.logTransaction(Transaction("Apple", "buy", 10, 150.0, "2023-10-10"));
    transactionLog.logTransaction(Transaction("Bitcoin", "buy", 2, 45000.0, "2023-10-15"));
    transactionLog.logTransaction(Transaction("CorporateBond", "buy", 20, 1000.0, "2023-10-12"));
    transactionLog.logTransaction(Transaction("USGovBond", "buy", 5, 1050.0, "2023-10-20"));

    // Save the transaction log to a file
    fileManager.saveTransactionLog(transactionLog, transactionFile);
    
    // Load the transaction log back into a new object
    TransactionLog loadedLog;
    fileManager.loadTransactionLog(loadedLog, transactionFile);

    // Verify the loaded transaction log matches the saved one
    test(loadedLog.getTransactions().size() == 4, "Test 2.1: Loaded transaction log size matches saved size");
    test(loadedLog.getTransactions()[0].getAssetName() == "Apple", "Test 2.2: First transaction asset name");
    test(loadedLog.getTransactions()[1].getQuantity() == 2, "Test 2.3: Second transaction quantity");
    test(loadedLog.getTransactions()[3].getDate() == "2023-10-20", "Test 2.4: Fourth transaction date");

    // Clean up test files (optional)
    // remove(portfolioFile.c_str());
    // remove(transactionFile.c_str());

    cout << "All tests completed." << endl;
    return 0;
}
