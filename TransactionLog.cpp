#include "TransactionLog.h"

// Log a transaction to the log
void TransactionLog::logTransaction(const Transaction& transaction) {
    // Add the transaction to the vector of transactions
    transactions.push_back(transaction);
}

// Display the transaction log to the console
void TransactionLog::displayLog() const {
    // Call the overloaded displayLog method with standard output stream
    displayLog(cout);
}

// Display the transaction log to a specified output stream
void TransactionLog::displayLog(ostream& out) const {
    // Output the transaction log header
    out << "Transaction Log:" << endl;

    // Iterate over the transactions and display each one
    for (const auto& transaction : transactions) {
        transaction.displayTransaction(out);
    }
}