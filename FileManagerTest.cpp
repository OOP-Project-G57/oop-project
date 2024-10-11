#include <iostream>
#include "FileManager.h"
#include "PortfolioManager.h"
#include "Transaction.h"

using namespace std;

int main() {
    FileManager fileManager;
    PortfolioManager portfolioManager;
    TransactionLog transactionLog;

    // 1. Test saving and loading a portfolio
    cout << "==== Testing Portfolio Save and Load ====" << endl;

    // Add some assets to the portfolio
    portfolioManager.addAsset(new Stock("AAPL", 150.0, 10));
    portfolioManager.addAsset(new Stock("GOOG", 2000.0, 5));

    // Save the portfolio to a file
    fileManager.savePortfolio(portfolioManager, "test_portfolio.txt");

    // Clear portfolio to simulate loading from scratch
    portfolioManager.clearPortfolio();
    cout << "Portfolio cleared, size: " << portfolioManager.getPortfolioSize() << endl;

    // Load the portfolio from the file
    fileManager.loadPortfolio(portfolioManager, "test_portfolio.txt");
    cout << "Loaded portfolio size: " << portfolioManager.getPortfolioSize() << endl;

    // Check that the portfolio was loaded correctly
    const Asset* stock = portfolioManager.getAsset("AAPL");
    if (stock != nullptr) {
        cout << "Loaded asset: " << stock->getName() << ", Price: " << stock->getPrice() << ", Quantity: " << stock->getQuantity() << endl;
    } else {
        cout << "Error: AAPL asset not loaded!" << endl;
    }

    // 2. Test saving and loading a transaction log
    cout << "==== Testing Transaction Log Save and Load ====" << endl;

    // Add transactions
    transactionLog.logTransaction(Transaction("AAPL", "buy", 10, 150, "2024-09-25"));
    transactionLog.logTransaction(Transaction("GOOG", "sell", 5, 2000, "2024-09-26"));

    // Save the transaction log
    fileManager.saveTransactionLog(transactionLog, "test_transactions.txt");

    // Simulate loading transaction log (just prints transactions)
    fileManager.loadTransactionLog(transactionLog, "test_transactions.txt");

    return 0;
}