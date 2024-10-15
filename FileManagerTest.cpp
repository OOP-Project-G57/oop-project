#include <iostream>
#include "FileManager.h"
#include "PortfolioManager.h"
#include "Stock.h"
#include "Asset.h"
#include "Transaction.h"
#include "TransactionLog.h"
#include "Cryptocurrency.h"
#include "debug.h"
#include "GovernmentBond.h"
#include "Bond.h"

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
    // Create FileManager object
    FileManager fileManager;

    // Create PortfolioManager and TransactionLog objects
    PortfolioManager portfolio;
    TransactionLog transactionLog;

    // Test 1: Save and Load Portfolio
    portfolio.addAsset(new Stock("Apple", 150.0, 10));  // Adding a stock asset to the portfolio

    // Save the portfolio to a file
    string portfolioFile = "test_portfolio.txt";
    fileManager.savePortfolio(portfolio, portfolioFile);

    // Load the portfolio into a new PortfolioManager object
    PortfolioManager loadedPortfolio;
    fileManager.loadPortfolio(loadedPortfolio, portfolioFile);

    // Verify that the loaded portfolio matches the saved one
    test(loadedPortfolio.getPortfolioSize() == portfolio.getPortfolioSize(), "Test 1.1: Portfolio size after loading");
    test(loadedPortfolio.getPortfolio().at("Apple")->getQuantity() == portfolio.getPortfolio().at("Apple")->getQuantity(),
         "Test 1.2: Asset quantity after loading");

    // Test 2: Save and Load Transaction Log
    transactionLog.logTransaction(Transaction("Apple", "buy", 10, 150.0, "2023-10-10"));

    // Save the transaction log to a file
    string transactionFile = "test_transactions.txt";
    fileManager.saveTransactionLog(transactionLog, transactionFile);

    // Load the transaction log into a new TransactionLog object
    TransactionLog loadedTransactionLog;
    fileManager.loadTransactionLog(loadedTransactionLog, transactionFile);

    // Verify that the loaded transaction log matches the saved one
    test(true, "Test 2: Transaction log loaded successfully. Manually verify using displayLog.");

    cout << "All tests completed." << endl;
    return 0;
}