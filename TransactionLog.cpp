#include "TransactionLog.h"
#include <iomanip>

// returns transactions
const std::vector<Transaction>& TransactionLog::getTransactions() const {
    return transactions;
}

//Logs a new transaction into the log.
void TransactionLog::logTransaction(const Transaction& transaction) {
    // Add the transaction to the vector of transactions
    transactions.push_back(transaction);
}

//Clears the transaction log.
void TransactionLog::clear() {
    transactions.clear();
}

//Displays the transaction log to the console.
void TransactionLog::displayLog() const {
    // Call the overloaded displayLog method with standard output stream
    displayLog(cout, false);
}

//Displays the transaction log to a specified output stream.
void TransactionLog::displayLog(ostream& out, bool useColor) const {
    // Check if color formatting is to be used
    if (useColor) {
        out << "\033[36m" << "╔═══════════════════════════════════════╗\n";
        out << "\033[36m" << "║          Transaction Log              ║\n";
        out << "\033[36m" << "╚═══════════════════════════════════════╝\n" << "\033[0m";
    } else {
        out << "Transaction Log\n";
    }

    // Display headers for the transaction table
    out << std::left << std::setw(10) << "Asset"
        << std::setw(10) << "Type"
        << std::setw(10) << "Quantity"
        << std::setw(10) << "Price"
        << std::setw(15) << "Date" << endl;

    // Iterate over the transactions and display each one
    for (const auto& transaction : transactions) {
        out << std::left << std::setw(10) << transaction.getAssetName()
            << std::setw(10) << transaction.getTransactionType()
            << std::setw(10) << transaction.getQuantity()
            << std::setw(10) << transaction.getPrice()
            << std::setw(15) << transaction.getDate() << endl;
    }
}