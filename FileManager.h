#pragma once

#include "PortfolioManager.h"  // Include PortfolioManager for accessing assets
#include "Transaction.h"       // Include Transaction and TransactionLog
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileManager {
public:
    // Save the portfolio to a file
    void savePortfolio(const PortfolioManager& manager, const string& filename);

    // Load the portfolio from a file (simulated loading)
    void loadPortfolio(PortfolioManager& manager, const string& filename);

    // Save the transaction log to a file
    void saveTransactionLog(const TransactionLog& log, const string& filename);

    // Load the transaction log from a file (simulated loading)
    void loadTransactionLog(TransactionLog& log, const string& filename);
};
