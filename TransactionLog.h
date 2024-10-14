#pragma once

#include <vector>
#include "Transaction.h"

using namespace std;

class TransactionLog {
private:
    vector<Transaction> transactions;

public:
    void logTransaction(const Transaction& transaction);
    void displayLog() const;
    void displayLog(ostream& out) const;
};