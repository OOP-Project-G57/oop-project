#include "TransactionLog.h"

void TransactionLog::logTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
}

void TransactionLog::displayLog() const {
    displayLog(cout);
}

void TransactionLog::displayLog(ostream& out) const {
    out << "Transaction Log:" << endl;
    for (const auto& transaction : transactions) {
        transaction.displayTransaction(out);
    }
}