#pragma once

#include <vector>
#include "Transaction.h"

using namespace std;

// TransactionLog class declaration
class TransactionLog {
private:
    // Private member variable to store transactions
    vector<Transaction> transactions;

public:
    // Log a transaction to the log
    void logTransaction(const Transaction& transaction);

    // Display the transaction log
    void displayLog() const;
    void displayLog(ostream& out) const;
};